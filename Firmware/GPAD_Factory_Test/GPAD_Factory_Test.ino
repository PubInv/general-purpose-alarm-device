/* GPAD_Factory_Test.ino
  This program for factory test of GPAD hardware

  Copyright (C) 2022 Robert Read, Forrest Erickson.

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
  20220922 Add version report on serial output and LCD.
  Change for BUZZER_TEST_FREQ - 4000 KHz the resonant frequency of the V1 buzzer.
  Was //tone(TONE_PIN, 130) for approximatly note C3 or middle C.
  20220923 Clear the LCD and turn off back light at start up before writing to it. Other test frequencies for speakers.
  20220927 Rewire SPI nCS to D10, Rewire LIGHT4 to D7.
  20221019 Lee and Robert, Code Review changes. 
*/

/* The purpose of this code is to help test the hardware of the GPAD.
 * GPAD was created by Public Invention and Sustainable Progress and Equality Collective
 * See: https://github.com/PubInv/general-alarm-device 
 * And: https://www.specollective.org/
*/

#define PROG_NAME "****FACTORY TEST****"     //Descriptive name of this software, 20 characters.
#define VERSION 1.24                         //Version of this software
#define BAUDRATE 115200

//Set LED wink parameters
const int HIGH_TIME_LED_MS = 800;    //time in milliseconds
const int LOW_TIME_LED_MS = 200;
unsigned long lastLEDtime_ms = 0;
unsigned long nextLEDchangee_ms = 100; //time in ms.

//Setup for buzzer.
//const int BUZZER_TEST_FREQ = 130; // One below middle C3. About 67 db, 3" x 4.875" 8 Ohm speakers no cabinet at 1 Meter.
//const int BUZZER_TEST_FREQ = 260; // Middle C4. About ?? db, 3" x 4.875" 8 Ohm speakers no cabinet at 1 Meter.
//const int BUZZER_TEST_FREQ = 1000; //About 76 db, 3" x 4.875" 8 Ohm speakers no cabinet at 1 Meter.
const int BUZZER_TEST_FREQ = 4000; // Buzzers, 3 V 4kHz 60dB @ 3V, 10 cm.  The specified frequencey for the Version 1 buzzer.

//For I2C Scan
#include <Wire.h>
//For LCD
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x38, 20, 4); // set the LCD address to 0x27 for a 20 chars and 4 line display in Wokwi, and 0x38 for the physical GPAD board

//Pin definitions.  Assign symbolic constant to Arduino pin numbers. 
//For more information see: https://www.arduino.cc/en/Tutorial/Foundations/DigitalPins
#define SWITCH_MUTE 2 
#define TONE_PIN 8
#define LIGHT0 3
#define LIGHT1 5
#define LIGHT2 6
#define LIGHT3 9
#define LIGHT4 7

//I2C endTransmission() return values/error codes
//For more information see: https://www.arduino.cc/reference/en/language/functions/communication/wire/endtransmission/
#define SUCCESS       0
#define OVERFLOW      1
#define NACK_ADDRESS  2
#define NACK_DATA     3
#define OTHER_ERROR   4
#define TIMEOUT       5

//Allow indexing to LIGHT[] by symbolic name. So LIGHT0 is first and so on.
int LIGHT[] = {LIGHT0, LIGHT1, LIGHT2, LIGHT3, LIGHT4};
const int NUM_LIGHTS = sizeof(LIGHT)/sizeof(LIGHT[0]);

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

//Portions of this copied from example i2c_scanner
//Scan I2C
void scanI2C(void) {
  Serial.println ();
  Serial.println ("I2C scanner. Scanning ...");
  const byte scanStart = 8;
  const byte scanEnd = 120;
  const byte scanRange = scanEnd - scanStart;
  byte endCode[6] = { 0 };    // returns no. of addresses per return code (max 6 codes).

  Wire.begin();
  for (byte i = scanStart; i < scanEnd; i++)  // scan fully range of addresses
  {
    Wire.beginTransmission (i);
    endCode[Wire.endTransmission()]++;  // tally up return codes
    if (Wire.endTransmission () == 0)
    {
      Serial.print ("Found address: ");
      Serial.print (i, DEC);
      Serial.print (" (0x");
      Serial.print (i, HEX);
      Serial.println (")");
      delay (1);  // maybe unneeded?
    } // end of good response
  } // end of for loop
  Serial.println ("Done.");
  
  if (endCode[SUCCESS]) {   // At least 1 found
    Serial.print("Found ");
    Serial.print(endCode[SUCCESS], DEC);
    Serial.println(" device(s).");
  }
  else {   // None found
    Serial.println("NO DEVICE FOUND.");
    // Print error message(s):
    if(endCode[OVERFLOW]) {   
      Serial.println("ERROR: Data too long to fit in transmit buffer. [x");
      Serial.print(endCode[OVERFLOW], DEC);
      Serial.println(" address(es)]");
    }
    if(endCode[NACK_ADDRESS]) {
      Serial.print("ERROR: Received NACK on transmit of address. [x");
      Serial.print(endCode[NACK_ADDRESS], DEC);
      Serial.println(" address(es)]"); 
    }
    if(endCode[NACK_DATA]) {
      Serial.println("ERROR: Received NACK on transmit of data. [x");
      Serial.print(endCode[NACK_DATA], DEC);
      Serial.println(" address(es)]");
    }
    if(endCode[OTHER_ERROR]) {
      Serial.println("ERROR: Other error. [x");
      Serial.print(endCode[OTHER_ERROR], DEC);
      Serial.println(" address(es)]");
    }
    if(endCode[TIMEOUT]) {
      Serial.println("ERROR: Timeout. [x");
      Serial.print(endCode[TIMEOUT], DEC);
      Serial.println(" address(es)]");
    }
  }//end serial prints
}//end scanI2C()

void setup() {
  //Lets make the LED high near the start of setup for visual clue
  pinMode(LED_BUILTIN, OUTPUT);      // set the LED pin mode
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)

  //Serial setup
  delay(100);
  Serial.begin(BAUDRATE);
  delay(100);                         //Wait before sending the first data to terminal

  Serial.print("FactoryTest V");
  Serial.println(VERSION);
  Serial.println("Start I2C scan");
  scanI2C();
  Serial.println("End I2C scan");
  
  lcd.init();                      // initialize the lcd
  Serial.println("Clear LCD");
  clearLCD();
  delay(100);
  Serial.println("Start LCD splash");
  splashLCD();
  Serial.println("EndLCD splash");

  Serial.println("Set up GPIO pins");
  pinMode(SWITCH_MUTE, INPUT_PULLUP);
  for (int i = 0; i < NUM_LIGHTS; i++) {
    Serial.println(LIGHT[i]);
    pinMode(LIGHT[i], OUTPUT);
  }
  Serial.println("end set up GPIO pins");

  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off at end of setup
}// end of setup()

void loop() {
  updateWink(); //The builtin LED.

  if (digitalRead(SWITCH_MUTE) != HIGH) {
    tone(TONE_PIN, BUZZER_TEST_FREQ);
    Serial.println("Button pressed.");
    for (int i = 0; i < NUM_LIGHTS; i++) {
      digitalWrite(LIGHT[i], HIGH);
    }
  } else {
    noTone(TONE_PIN);
    for (int i = 0; i < NUM_LIGHTS; i++) {
      digitalWrite(LIGHT[i], LOW);
    }
  }
}//end loop()
