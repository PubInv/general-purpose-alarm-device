/* GPAD_Factory_Test.ino
  This program for factory test of PGPAD hardware

  Copyright (C) 2021 Robert Read, Forrest Erickson.

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
  
*/

#define VERSION 1.21             //Version of this software
#define BAUDRATE 115200

//Set LED for Uno or ESP32 Dev Kit on board blue LED.
//const int LED_BUILTIN = 2;    // ESP32 Kit
//const int LED_BUILTIN = 13;    //Not really needed for Arduino UNO it is defined in library
const int HIGH_TIME_LED = 800;
const int LOW_TIME_LED = 200;
unsigned long lastLEDtime = 0;
unsigned long nextLEDchange = 100; //time in ms.
//const int BUZZER_TEST_FREQ = 130; // Middle C. About 67 db, 3" x 4.875" 8 Ohm speakers no cabinet at 1 Meter.
const int BUZZER_TEST_FREQ = 4000; // Buzzers, 3 V 4kHz 60dB @ 3V, 10 cm
//const int BUZZER_TEST_FREQ = 1000; //About 76 db, 3" x 4.875" 8 Ohm speakers no cabinet at 1 Meter.

//For I2C Scan
#include <Wire.h>
//For LCD
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x38, 20, 4); // set the LCD address to 0x27 for a 20 chars and 4 line display in Wokwi, and 0x38 for the physical GPAD board

//Pin definitions
#define SWITCH_MUTE 2
#define TONE_PIN 8
#define LIGHT0 3
#define LIGHT1 5
#define LIGHT2 6
#define LIGHT3 9
#define LIGHT4 10

//int LIGHT[] = {3, 5, 6, 9, 10};
int LIGHT[] = {LIGHT0, LIGHT1, LIGHT2, LIGHT3, LIGHT4};

//Functions

void updateWink(void) {
  //Wink the built in LED
  if (((millis() - lastLEDtime) > nextLEDchange) || (millis() < lastLEDtime)) {
    if (digitalRead(LED_BUILTIN) == LOW) {
      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      nextLEDchange = HIGH_TIME_LED;
    } else {
      digitalWrite(LED_BUILTIN, LOW);   // turn the LED on (HIGH is the voltage level)
      nextLEDchange = LOW_TIME_LED;
    }
    lastLEDtime = millis();
  }//end of Wink
}

/*Assumes LCD has been initilized
 * Turns off Back Light
 * Clears display
 * Turns on back light.
 */
void clearLCD(void) {  
  lcd.noBacklight();
  lcd.clear();
}// end clearLCD

void splashLCD(void) {
  //LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27 for a 16 chars and 2 line display
  lcd.init();                      // initialize the lcd
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("********************");
  lcd.setCursor(3, 1);
  lcd.print("GPAD Starting");
  lcd.setCursor(0, 2);
  lcd.print("by Public Invention");
  lcd.setCursor(0, 3);
  lcd.print("Version: ");
  lcd.print(VERSION);
}// end splashLCD

//Scan I2C
void scanI2C(void) {
  Serial.println ();
  Serial.println ("I2C scanner. Scanning ...");
  byte count = 0;

  Wire.begin();
  for (byte i = 8; i < 120; i++)
  {
    Wire.beginTransmission (i);
    if (Wire.endTransmission () == 0)
    {
      Serial.print ("Found address: ");
      Serial.print (i, DEC);
      Serial.print (" (0x");
      Serial.print (i, HEX);
      Serial.println (")");
      count++;
      delay (1);  // maybe unneeded?
    } // end of good response
  } // end of for loop
  Serial.println ("Done.");
  Serial.print ("Found ");
  Serial.print (count, DEC);
  Serial.println (" device(s).");
}//end scanI2C()

void setup() {
  // put your setup code here, to run once:
  delay(100);
  Serial.begin(BAUDRATE);
  delay(100);
  pinMode(LED_BUILTIN, OUTPUT);      // set the LED pin mode
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  //  Serial.println("FactoryTest V1.2");
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
  //pinMode(TONE_PIN, OUTPUT); //Not necessary

  for (int i = 0; i < 5; i++) {
    Serial.println(LIGHT[i]);
    pinMode(LIGHT[i], OUTPUT);
    //   digitalWrite(LIGHT[i], HIGH);
  }
  //#define TONE_PIN 8
  //#define LIGHT0 3
  //#define LIGHT1 5
  //#define LIGHT2 6
  //#define LIGHT3 9
  //#define LIGHT4 10
  Serial.println("end set up GPIO pins");


  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off at end of setup
}// end of setup()

void loop() {
  // put your main code here, to run repeatedly:

  updateWink(); //The builtin LED.

  if (digitalRead(SWITCH_MUTE) != HIGH) {
    tone(TONE_PIN, BUZZER_TEST_FREQ);
    Serial.println("Button pressed.");
    for (int i = 0; i < 5; i++) {
      digitalWrite(LIGHT[i], HIGH);
    }
  } else {
    noTone(TONE_PIN);
    for (int i = 0; i < 5; i++) {
      digitalWrite(LIGHT[i], LOW);
    }
  }

}//end loop()
