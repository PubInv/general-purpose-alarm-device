/* GPAD_API_SPI_CONTROLLER.ino

  GPAD_API_SPI_CONTROLLER.ino - Controller code for using one GPAD to control another.

  Copyright (C) 2023 Forrest Lee Erickson

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
  
   From: https://circuitdigest.com/microcontroller-projects/arduino-spi-communication-tutorial
   Modified by Forrest Lee Erickson 20220523
   Change to Controller/Peripheral termonology
   Change variable names for start with lowercase. Constants to uper case.
   Controller Arduino Code:
   20220524 Get working with the SPI_PERIPHERAL sketch.
   20220525 The SCK period is about 250nS as set up.
   20220927 Change for button to have internal pull up.  Add Resistor and LED from pins 7 to 6.
*/

//SPI CONTROLLER (ARDUINO UNO)
//SPI COMMUNICATION BETWEEN TWO ARDUINO UNOs
//CIRCUIT DIGEST

#define PROG_NAME "SPI CONTROLLER" 
#define VERSION 0.1
#define BAUDRATE 115200

/* Hardware Notes, Controller
   SPI Line Pin in Arduino
  MOSI 11 or ICSP-4  Output
  MISO 12 or ICSP-1 Input
  SCK 13 or ICSP-3 Output
  SS 10  Output
  330 Ohm resistor and LED from pin 7 to pin 6.
  LED will be high untill the peripheral button is pressed.

*/

#include<SPI.h>                             //Library for SPI
#define LED_PIN 7                           //Add this LED + Resistor
#define LED_CATHODE 6                        //A pin to sink LED current
#define BUTTON_PIN 2                        //Button to GND, 10K Resistor to +5V.

#include "GPAD_Alarm_API_SPI.h"


/*
 * Note: The GPAD has an SPI interface which could be programmmed in any way,
 * But the obvious way to do this is to use a GPAD itself as an SPI Controller.
 * The GPAD is an "Arduion Duemilanove". 
 * However, we (Public Invention) also want to drive a GPAD from the PolyVent,
 * which uses an ESP32-based architecture, which uses a different output pin
 * for the "MOSI" (Master out, server in.) The upshot of all of this (which is 
 * perhaps obvious) is that wherever you run this code on any microcontroller,
 * you may to make sure the GPAD_CS pin is the one you REALLY are connecting to 
 * the GPAD.
 */
// #define USE_POLYVENT_ARCH 1


#ifdef USE_POLYVENT_ARCH
// If you aren't on the PolyVent team, you don't want to do this---we are keeping
// this confusing thing here for to facilitate our testing on mulitple architectures.
#define GPAD_CS_IDX (11-1)
const uint8_t ESP_CS_PINS[11] =  {4, 5, 13, 14, 15, 16, 17, 25, 26, 32, 33};
int GPAD_CS = ESP_CS_PINS[GPAD_CS_IDX];
#else
int GPAD_CS = SS;
#endif

#define USE_LCD 1
#ifdef USE_LCD
//For LCD -- this is useful if you are using a GPAD as a controller, but 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x38, 20, 4); // set the LCD address to 0x27 for a 20 chars and 4 line display in Wokwi, and 0x38 for the physical GPAD board
#endif

/* Assumes LCD has been initilized
 * Turns off Back Light
 * Clears display
 * Turns on back light.
 */
void clearLCD(void) {  
  lcd.noBacklight();
  lcd.clear();
}

//Splash a message so we can tell the LCD is working
void splashLCD(void) {
  lcd.init();                      // initialize the lcd
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print(PROG_NAME);
  lcd.setCursor(3, 1);
  lcd.print("GPAD Starting");
  lcd.setCursor(0, 2);
  lcd.print("by PubInv & SPEC");
  lcd.setCursor(0, 3);
  lcd.print("Version: ");
  lcd.print(VERSION);
}// end splashLCD


void local_setup(void) {

  // if you need it for debugging, you can slow the SPI clock down
  //For SPI clock rates, see https://www.arduino.cc/reference/en/language/functions/communication/spi/setclockdivider/
  // At this speed (2MHZ), we were missing bytes with a 12" cable.
  //SPI.setClockDivider(SPI_CLOCK_DIV8);    //Sets clock for SPI communication at 8 (16/8=2Mhz)
  // At this speed, with a 12" cable, I noticed no dropped bytes.
  SPI.setClockDivider(SPI_CLOCK_DIV16);    //SPI clock at 16MHz/N (16/16=1Mhz) where N={2,4,8,16,32,64,128}
  //SPI.setClockDivider(SPI_CLOCK_DIV64);    //SPI clock at 16MHz/N (16/64=250Khz) where N={2,4,8,16,32,64,128}
  //SPI.setClockDivider(SPI_CLOCK_DIV128);    //SPI clock at 16MHz/N (16/128=125Khz) where N={2,4,8,16,32,64,128}
  pinMode(GPAD_CS, OUTPUT);                    // Set nCS for output
  pinMode(MISO, INPUT);                   //Sets MISO as INPUT. Note MOSI must be set automaticaly
  SPI.begin();                            //Begins the SPI commnuication


#ifdef USE_LCD
  Wire.begin();
  lcd.init();
  Serial.println(F("Clear LCD"));
  clearLCD();
  delay(100);
  Serial.println(F("Start LCD splash"));
  splashLCD();
  Serial.println(F("EndLCD splash"));
#endif

  digitalWrite(GPAD_CS, HIGH);                 // Setting PeripheralSelect as HIGH (So controller doesnt connnect with peripheral)
  delay(100);
  Serial.println(F("SETUP DONE!"));

}
void setup (void)
{
  Serial.begin(BAUDRATE);                   //Starts Serial Communication at Baud Rate 115200
  delay(500);
  Serial.println(F("Starting SPI Controller."));

#ifndef USE_POLYVENT_ARCH
  pinMode(BUTTON_PIN, INPUT_PULLUP);               //Sets pin 2 as input
  pinMode(LED_PIN, OUTPUT);                   //Sets pin 7 as Output

  pinMode(LED_CATHODE, OUTPUT);               //Sets pin 6 as Output
  digitalWrite(LED_CATHODE, LOW);             //Sets pin 6 to sink LED current
#endif
  local_setup();
 
}// end setup()

int cnt = 2;
void desire_loop(void)
{
  AlarmEvent event;
  event.lvl = cnt++ % 6;
  strcpy(event.msg,"Be True; You need noBe True; You need noBe True; You need noBe True; You need no");
  
  alarm_event(event,Serial);
  Serial.println(F("Done with Datum Send!"));
  delay(3000);
}

// int cnt = 0;
unsigned long timer;
int toggle = 0;
void loop(void)
{

  delay(3000);
  Serial.println("SENDING SPI");
  unsigned long m = millis();
  if (m > (5000 + timer)) {
    timer = m;
    const int USE_TOGGLE = 0;

    if (USE_TOGGLE) {
      if (toggle == 0) {
        Serial.println(F("Writing LOW"));
        Serial.println(GPAD_CS);
        digitalWrite(GPAD_CS, LOW);
      } else {
        Serial.println(F("Writing HIGH"));
        Serial.println(GPAD_CS);
        digitalWrite(GPAD_CS, HIGH);
        
      }
      toggle = (toggle + 1) % 2;

    } else {
         Serial.println(F("Writing SPI LOW"));    
        uint8_t v = cnt++ % 6;
        AlarmEvent event;
        event.lvl = v;
        strcpy(event.msg,"abcdefghijklmnopqrstuvwxy\0");
        event.msg[26] = 0;
        alarm_event(event,Serial);
        Serial.println(F("Done"));
        Serial.println(GPAD_CS);
        Serial.println(F("LEVEL: "));
        Serial.println(event.lvl);
#ifdef USE_LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print(F("LEVEL: "));
  lcd.setCursor(0,1);
  lcd.print(event.lvl);  
#endif     
    }
  }
}
