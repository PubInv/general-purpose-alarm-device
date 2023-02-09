/* SPI_PERIPHERAL

Copyright (C) 2022 Robert Read
This program includes free software: you can redistribute it and/or modif
it under the terms of the GNU Affero General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.
See the GNU Affero General Public License for more details.
You should have received a copy of the GNU Affero General Public License
along with this program. If not, see https://www.gnu.org/licenses/.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
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

#include<SPI.h>

volatile boolean isReceived_SPI;
volatile byte peripheralReceived ;

void setup()
{
  Serial.begin(115200);
  delay(500);
  Serial.println("Starting SPI Peripheral.");
  Serial.print("Pin for SS: ");
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
}//end setup()

//ISRs
ISR (SPI_STC_vect)                        //Inerrrput routine function
{
  peripheralReceived = SPDR;         // Value received from controller if store in variable peripheralReceived
  isReceived_SPI = true;                        //Sets isReceived_SPI as True
}//end ISR

//Functions
void updateFromSPI() {
  volatile byte peripheralSend;

  if (isReceived_SPI)                           //Logic to SET LED ON OR OFF depending upon the value recerived from controller
  { // Act on the received data.
    if (peripheralReceived == 1)
    {
      digitalWrite(LED_PIN, HIGH);        //Sets pin 7 as HIGH LED ON
      //          Serial.println("Peripheral LED ON");
    } else
    {
      digitalWrite(LED_PIN, LOW);         //Sets pin 7 as LOW LED OFF
      //          Serial.println("Peripheral LED OFF");
    }

    // Send return SPI data. Lets use a button for this example.
    peripheralSend = digitalRead(BUTTON_PIN);
    SPDR = peripheralSend;    //SPDR register of data to be shiffted out.

    Serial.print("SPI_PERIPHERAL, isReceived_SPI: ");
    Serial.println(peripheralReceived);
  }// end received
}//end function updateFromSPI

void loop()
{
  updateFromSPI();

//Check mute button for press.
    if (digitalRead(BUTTON_PIN) != HIGH) {
  //  tone(TONE_PIN, BUZZER_TEST_FREQ);
    Serial.println("Button pressed.");
//    for (int i = 0; i < 5; i++) {
//      digitalWrite(LIGHT[i], HIGH);
//    }
  } else {
//    noTone(TONE_PIN);
//    for (int i = 0; i < 5; i++) {
//      digitalWrite(LIGHT[i], LOW);
//    }
  }
  
}//end loop()
