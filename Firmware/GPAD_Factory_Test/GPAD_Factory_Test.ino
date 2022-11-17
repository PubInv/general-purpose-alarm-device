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
#define VERSION 1.30                         //Version of this software
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
//For Switch Debouncing
#include <DailyStruggleButton.h>


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

//Test Groups
#define TG_SWITCH_MUTE 0
#define TG_LEDS        1
#define TG_BUZZER      2
#define TG_I2C         3
#define TG_LCD         4

//Indiviual Tests
#define T_LED_BUILTIN   0
#define T_LIGHTS        1
#define T_LIGHT0        0
#define T_LIGHT1        1
#define T_LIGHT2        2
#define T_LIGHT3        3
#define T_LIGHT4        4
#define T_BUZZER_FREQ1  0


//Allow indexing to LIGHT[] by symbolic name. So LIGHT0 is first and so on.
int LIGHT[] = {LIGHT0, LIGHT1, LIGHT2, LIGHT3, LIGHT4};
const int NUM_LIGHTS = sizeof(LIGHT)/sizeof(LIGHT[0]);

//DailyStruggleButton
unsigned int longPressTime = 1000;
unsigned int multiHitTime = 600;
byte multiHitTarget = 2;
DailyStruggleButton switchMute;   // create instance of DSB

//Testing
byte testCount = 0;             // for toggling through each test function with single-press
byte testGroupCount = 0;        // for toggling through each group of test functions with multi-press
const byte testGroups = 5;      // number of test groups to cycle through
byte testGroup = 0;             // current test group
bool oldStatus = false;         // for printing once during loop()
bool autoToggle = false;
unsigned long lastTestTime_ms = 0;

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

// test functions
void testSwitchMute(byte switchStatus) {
  if(testGroup != TG_SWITCH_MUTE) {
    return;
  }

  switch (switchStatus) {
    case onPress:
      Serial.println("Switch pressed.");
      break;

    case onRelease:
      Serial.println("Switch released.");
      break;

    case onLongPress:
      Serial.println("Switch long-pressed.");
      break;

    case onMultiHit:
      Serial.println("Switch multi-pressed.");            
      break;
  }
}

void testLEDs(void) {
  byte test = testCount % (1 + (2*NUM_LIGHTS + 1));      // total number of tests counter
  
  if (test == T_LED_BUILTIN) {    // Test 1 - built-in LED
    updateWink();
    bool winkStatus = true;
    if (winkStatus != oldStatus) {    // print once
      Serial.println("Now winking built-in LED.");   
      oldStatus = winkStatus;
    }
  }
  else {
    digitalWrite(LED_BUILTIN, LOW);
  }

  if (test >= T_LIGHTS) {         // Test 2++ - external LEDs onwards...
    byte testEachLight = (test - 1) % NUM_LIGHTS;   // counter for iterating through lights (0 -> NUM8LIGHTS-1)
    byte subGroupTest = (byte)(test - 1)/5 ;    // counter to iterate through grouped light tests (0 -> 2)
    bool lightStatus = true;

    switch (subGroupTest) {
      case 0:   // Sequentially drive each light individually
        for (byte i = 0; i < NUM_LIGHTS; ++i) {   // Turn off every other light 
          if (i != testEachLight) {
            digitalWrite(LIGHT[i], LOW);
          }
        }

        switch (testEachLight) {   // Turn on selected light
          case T_LIGHT0:  digitalWrite(LIGHT[T_LIGHT0], HIGH);   break;
          case T_LIGHT1:  digitalWrite(LIGHT[T_LIGHT1], HIGH);   break;
          case T_LIGHT2:  digitalWrite(LIGHT[T_LIGHT2], HIGH);   break;
          case T_LIGHT3:  digitalWrite(LIGHT[T_LIGHT3], HIGH);   break;
          case T_LIGHT4:  digitalWrite(LIGHT[T_LIGHT4], HIGH);   break;
        }

        if (lightStatus != oldStatus) {   // print once
          Serial.print("Now individually driving LIGHT ");
          Serial.println(testEachLight, DEC);  
          oldStatus = lightStatus;
        }
        break;
      
      case 1:   // Sequentially drive all but one light
        for (byte i = 0; i < NUM_LIGHTS; ++i) {   
          if (i == testEachLight) {     // turn ON all lights apart from selected
            digitalWrite(LIGHT[i], LOW);
          }
          else {
            digitalWrite(LIGHT[i], HIGH); // selected
          }
        }

        if (lightStatus != oldStatus) {   // print once
          Serial.print("Now driving all but LIGHT ");
          Serial.println(testEachLight, DEC);  
          oldStatus = lightStatus;         
        }
        break;
      
      case 2:   // Drive ALL lights
        for (byte i = 0; i < NUM_LIGHTS; ++i) {
          digitalWrite(LIGHT[i], HIGH);
        }

        if (lightStatus != oldStatus) {   // print once
          Serial.print("Now driving all ");
          Serial.print(NUM_LIGHTS, DEC);
          Serial.println(" Lights.");
          oldStatus = lightStatus;
        }
        break;
    } // end subGroupTest switch-case
  } // end if (test >= T_LIGHTS)
  else {
    for (byte i = 0; i < NUM_LIGHTS; ++i) {   // turn off every light if not testing
      digitalWrite(LIGHT[i], LOW);
    }
  }
} // end testLEDS()

void stopTestLEDs(void) {
  digitalWrite(LED_BUILTIN, LOW);           // Test 1
  for (byte i = 0; i < NUM_LIGHTS; ++i) {   // Test 2++
    digitalWrite(LIGHT[i], LOW);
  }
}

void testBuzzer(void) {
  byte test = testCount % 1;        // modify const int to change number of tests

  switch (test) {           // Note: switch-case for potential further expansion of tests...
    case T_BUZZER_FREQ1:
      tone(TONE_PIN, BUZZER_TEST_FREQ);
      bool buzzerStatus = true;
      if (buzzerStatus != oldStatus) {    // print once
        Serial.print("Driving Buzzer at frequency: ");
        Serial.print(BUZZER_TEST_FREQ);
        Serial.println(" Hz");   
        oldStatus = buzzerStatus;
      }
      break;
  }
}

void stopTestBuzzer(void) {
  noTone(TONE_PIN);
}

void testI2C(void) {

}

void stopTestI2C(void) {

}

void testLCD(void) {

}

void stopTestLCD(void) {

}

void autoToggleTest(void) {
  if (!autoToggle){
    return;
  }

  const unsigned long ms = millis();
  int testTime_ms = 3000;

  if (ms - lastTestTime_ms > testTime_ms) {
    testCount++;
    oldStatus = false;    // to enable indiviual tests to print to monitor
    lastTestTime_ms = ms;
  }
}

void testGroupFunctions(void) {
  testGroup = testGroupCount % testGroups;
  autoToggleTest();

  if (testGroup == TG_LEDS) {
    testLEDs();
  }
  else {
    stopTestLEDs();
  }

  if (testGroup == TG_BUZZER) {
    testBuzzer();
  }
  else {
    stopTestBuzzer();
  }

  if (testGroup == TG_I2C) {
    testI2C();
  }
  else {
    stopTestI2C();
  }

  if (testGroup == TG_LCD) {
    testLCD();
  }
  else {
    stopTestLCD();
  }
}

void testGroupPrint(void) {   // for displaying to serial monitor
  testGroup = testGroupCount % testGroups;
  switch (testGroup) {
    case TG_SWITCH_MUTE:
      Serial.println("*** Now testing Mute Switch functionality. ***");
      break;

    case TG_LEDS:
      Serial.println("*** Now testing LED functionality. ***");
      break;

    case TG_BUZZER:
      Serial.println("*** Now testing Buzzer functionality. ***");
      break;

    case TG_I2C:
      Serial.println("*** Now testing I2C functionality. ***");
      break;

    case TG_LCD:
      Serial.println("*** Now testing LCD functionality. ***");
      break;
  }
}

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
  Serial.println("End LCD splash");

  Serial.println("Set up GPIO pins");
  switchMute.set(SWITCH_MUTE, switchMuteEvent, INT_PULL_UP);
  switchMute.enableLongPress(longPressTime);
  switchMute.enableMultiHit(multiHitTime, multiHitTarget);
  for (int i = 0; i < NUM_LIGHTS; i++) {
    Serial.println(LIGHT[i]);
    pinMode(LIGHT[i], OUTPUT);
  }
  Serial.println("end set up GPIO pins");
  
  testGroupPrint();   // print first, default test message
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off at end of setup
}// end of setup()

void loop() {
  switchMute.poll();
  testGroupFunctions();
}//end loop()

void switchMuteEvent(byte switchStatus) {
  switch (switchStatus) {
    case onPress:
      testSwitchMute(switchStatus);
      oldStatus = false;
      testCount++;
      break;

    case onRelease:
      testSwitchMute(switchStatus);
      break;

    case onLongPress:
      testSwitchMute(switchStatus);
      autoToggle ^= true;
      if (autoToggle) { Serial.println("-- Auto-toggle mode enabled. --"); }
      else { Serial.println("-- Auto-toggle mode disabled. --"); }
      testCount = 0;  
      break;

    case onMultiHit:
      testSwitchMute(switchStatus);
      testGroupCount++;
      testGroupPrint();
      oldStatus = false;
      testCount = 0;          
      break;
  }
}//end switchMuteEvent()
