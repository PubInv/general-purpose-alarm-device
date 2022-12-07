 /* GPAD_API.ino
  The program implements the main API of the General Purpose Alarm Device.

  Copyright (C) 2022 Robert Read

  This program includes free software: you can redistribute it and/or modify
  it under the terms of the GNU Affero General Public License as
  published by the Free Software Foundation, either version 3 of the
  License, or (at your option) any later version.

  See the GNU Affero General Public License for more details.
  You should have received a copy of the GNU Affero General Public License
  along with this program.  If not, see <https://www.gnu.org/licenses/>.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

  Change notes:
  20221024 Creation by Rob.
  20221028 Report Program Name in splash screen. Lee Erickson
*/

/* This is a work-in-progress but it has two purposes.
 * It essentially implements two APIs: An "abstract" API that is
 * intended to be unchanging and possibly implemented on a large
 * variety of hardware devices. That is, as the GPAD hardware
 * changes and evolves, it does not invalidate the use of this API.
 *
 * Secondly, it offers a fully robotic API; that is, it gives
 * complete access to all of the hardware currently on the board.
 * For example, the current hardware, labeled Prototype #1, offers
 * a simple "tone" buzzer. The abstract interface uses this as part
 * of an abstract command like "set alarm level to PANIC".
 * The robotic control allows you to specify the actual tone to be played.
 * The robotic inteface obviously changes as the hardware changes.
 *
 * Both APIs are useful in different situations. The abstract interface
 * is good for a medical device manufacturer that expects the alarming
 * device to change and evolve. The Robotic API is good for testing the
 * actual hardware, and for a hobbyist that wants to use the device for
 * more than simple alarms, such as for implementing a game.
 *
 * It is our intention that the API will be available both through the
 * serial port and through an SPI interface. Again, these two modes
 * serve different purposes. The SPI interface is good for tight
 * intergration with a safey critical devices. The serial port approach
 * is easier for testing and for a hobbyist to develop an approach,
 * whether they eventually intend to use the SPI interface or not.
 * -- rlr, Oct. 24, 2022
 */

#include "alarm_api.h"
#include "robot_api.h"
#include "gpad_utility.h"
#include "gpad_serial.h"

/* SPI_PERIPHERAL
   From: https://circuitdigest.com/microcontroller-projects/arduino-spi-communication-tutorial
   Modified by Forrest Lee Erickson 20220523
   Change to Controller/Peripheral termonology
   Change variable names for start with lowercase. Constants to upper case.
   Peripherial Arduino Code:
   License: Dedicated to the Public Domain
   Warrenty: This program is designed to kill and render the earth uninhabitable,
   however it is not guaranteed to do so.
   20220524 Get working with the SPI_CONTROLER sketch. Made function updateFromSPI().
   20220925 Changes for GPAD Version 1 PCB.  SS on pin 7 and LED_PIN on D3.
   20220927 Change back for GPAD nCS on Pin 10
*/

//SPI PERIPHERAL (ARDUINO UNO)
//SPI COMMUNICATION BETWEEN TWO ARDUINO UNOs
//CIRCUIT DIGEST

/* Hardware Notes Peripheral
   SPI Line Pin in Arduino, IO setup
  MOSI 11 or ICSP-4  Input
  MISO 12 or ICSP-1 Output
  SCK 13 or ICSP-3  Input
  SS 10 Input
*/

#define GPAD_VERSION1

#ifdef GPAD_VERSION1 //The Version 1 PCB.
//#define SS 7                                // nCS aka /SS Input on GPAD Version 1 PCB.
#define LED_PIN PD3                         // for GPAD LIGHT0
#define BUTTON_PIN PD2                      //GPAD Button to GND,  10K Resistor to +5V.

#else //The proof of concept wiring.
#define LED_PIN 7
#define BUTTON_PIN 2                          //Button to GND, 10K Resistor to +5V.


#endif

#define DEBUG_SPI 0


#include<SPI.h>

volatile boolean isReceived_SPI;
volatile byte peripheralReceived ;


#include <SPITransfer.h>

SPITransfer myTransfer;

//const int fileSize = 200;
//char file[fileSize];
//char fileName[10];

volatile bool procNewPacket = false;

void setup_spi()
{
  Serial.println(F("Starting SPI Peripheral."));
  Serial.print(F("Pin for SS: "));
  Serial.println(SS);

  pinMode(BUTTON_PIN, INPUT);              // Setting pin 2 as INPUT
  pinMode(LED_PIN, OUTPUT);                // Setting pin 7 as OUTPUT

  //  SPI.begin();    // IMPORTANT. Do not set SPI.begin for a peripherial device.
  pinMode(SS, INPUT_PULLUP); //Sets SS as input for peripherial
  pinMode(MOSI, OUTPUT);    //This works for Peripheral
  pinMode(MISO, OUTPUT);    //try this.
  pinMode(SCK, INPUT);                  //Sets clock as input
  SPCR |= _BV(SPE);                       //Turn on SPI in Peripheral Mode
  isReceived_SPI = false;
  SPI.attachInterrupt();                  //Interuupt ON is set for SPI commnucation

//  struct configST
//  {
//    Stream*            debugPort    = &Serial;
//    bool               debug        = true;
//    const functionPtr* callbacks    = NULL;
//    uint8_t            callbacksLen = 0;
//    uint32_t           timeout      = __UINT32_MAX__;
//  };

struct configST config;
config.timeout = 200;

  myTransfer.begin(SPI,config);
}//end setup()

//ISRs
// This is the original...
// ISR (SPI_STC_vect)                        //Inerrrput routine function
// {
//   peripheralReceived = SPDR;         // Value received from controller if store in variable peripheralReceived
//   isReceived_SPI = true;                        //Sets isReceived_SPI as True
// }//end ISR

ISR (SPI_STC_vect)
{
  if(myTransfer.available())
    procNewPacket = true;
}

//Functions
// This reads a message of time AlarmEvent;
void updateFromSPI_SerialTransfer()
{
  if(procNewPacket)
  {
    procNewPacket = false;

    AlarmEvent event;
    myTransfer.rxObj(event);
    Serial.print(F("LVL: "));
    Serial.println(event.lvl);
    
    Serial.println(event.msg);
    Serial.println();
  }
}

//void updateFromSPI_SerialTransfer()
//{
//  if(procNewPacket)
//  {
//    procNewPacket = false;
//    
//    if (!myTransfer.currentPacketID())
//    {
//      myTransfer.rxObj(fileName);
//      Serial.println("filename: ");
//      Serial.println(fileName);
//    }
//    else if (myTransfer.currentPacketID() == 1)
//      for(uint8_t i=2; i<myTransfer.bytesRead; i++)
//        Serial.print((char)myTransfer.packet.rxBuff[i]);
//    Serial.println();
//  }
//}

// #define VERSION 0.02             //Version of this software
#define BAUDRATE 115200
// #define BAUDRATE 57600
// Let's have a 10 minute time out to allow people to compose strings by hand, but not
// to leave data our there forever
// #define SERIAL_TIMEOUT_MS 600000
#define SERIAL_TIMEOUT_MS 1000

//Set LED wink parameters
const int HIGH_TIME_LED_MS = 800;    //time in milliseconds
const int LOW_TIME_LED_MS = 200;
unsigned long lastLEDtime_ms = 0;
unsigned long nextLEDchangee_ms = 100; //time in ms.

// extern int LIGHT[];
// extern int NUM_LIGHTS;

// Functions

void updateWink(void) {
  //Wink the built in LED
  const unsigned long m = millis();
  if (((m - lastLEDtime_ms) > nextLEDchangee_ms) || (m < lastLEDtime_ms)) {
    if (digitalRead(LED_BUILTIN) == LOW) {
      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      nextLEDchangee_ms = HIGH_TIME_LED_MS;
    } else {
      digitalWrite(LED_BUILTIN, LOW);   // turn the LED on (HIGH is the voltage level)
      nextLEDchangee_ms = LOW_TIME_LED_MS;
    }
    lastLEDtime_ms = m;
  }//end of Wink
}


void setup() {
  //Lets make the LED high near the start of setup for visual clue
  pinMode(LED_BUILTIN, OUTPUT);      // set the LED pin mode
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)

  //Serial setup
  delay(100);
  Serial.begin(BAUDRATE);
  delay(100);                         //Wait before sending the first data to terminal
  Serial.setTimeout(SERIAL_TIMEOUT_MS);
  Serial.println(VERSION);
  robot_api_setup(&Serial);

  setup_spi();

  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off at end of setup

  Serial.println(F("Done With Setup!"));
}// end of setup()

void loop() {
  updateWink(); //The builtin LED
  robot_api_loop();

  // This is causing a hang!
  processSerial(Serial);

  // Now try to read from the SPI Port!
  //   updateFromSPI();
  updateFromSPI_SerialTransfer();

}
