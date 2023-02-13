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
#define T_LED_BUILTIN   0   // LEDs:
#define T_LIGHTS_START  1
#define T_LIGHTS_END    11
#define T_BUZZER_CONT   0   // Buzzer:
#define T_BUZZER_INT    1
#define T_BACKLIGHT     0   // LCD:
#define T_DEAD_PIXELS   1
#define T_GRID_FILL     2   // filled background
#define T_GRID_CLEAR    3   // clear background
#define T_ASCII_CHARS   4

//I2C Scan Target Address
#define ADDRESS_TARGET  0x38u   // primary target
#define NUM_I2C         1       // number of I2C devices

//Allow indexing to LIGHT[] by symbolic name. So LIGHT0 is first and so on.
int LIGHT[] = {LIGHT0, LIGHT1, LIGHT2, LIGHT3, LIGHT4};
const int NUM_LIGHTS = sizeof(LIGHT)/sizeof(LIGHT[0]);

//DailyStruggleButton
unsigned int longPressTime = 1000;
unsigned int multiHitTime = 400;
byte multiHitTarget = 2;
DailyStruggleButton switchMute;   // create instance of DSB

//Hello, Bryan was here.
//Testing
byte ASCII = 33;                // for more info see: https://www.asciitable.com/
byte charCountX = 0;            // for LCD tests
byte charCountY = 0;            
byte testCount = 0;             // for toggling through each test function with single-press
byte testGroupCount = 0;        // for toggling through each group of test functions with multi-press
byte testGroup = 0;             // current test group
const byte testGroups = 5;      // number of test groups to cycle through
bool printStatus = false;       // for printing once during loop()
bool autoToggle = false;        // to enable/disable automated toggling through tests
bool buzzer = false;            // driving buzzer
unsigned long lastToggleTime_ms = 0;  // for autoToggle exclusively
unsigned long lastTestTime_ms = 0;    // generic - ONLY for mutually exclusive events

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
  Serial.print("Target primary address: ");
  Serial.print(ADDRESS_TARGET, DEC);
  Serial.print(" (0x");
  Serial.print(ADDRESS_TARGET, HEX);
  Serial.println (")");
  Serial.print("Target number of I2C devices: ");
  Serial.println(NUM_I2C, DEC);
  Serial.println ("I2C scanner. Scanning ...");

  bool targetFound = false;
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
      Serial.print (")");
      if (i == ADDRESS_TARGET) { 
        Serial.println(" [TARGET ADDRESS]"); 
        targetFound = true; 
      }
      else { 
        Serial.println(" [NON-TARGET ADDRESS]"); 
      }
      delay (1);  // maybe unneeded?
    } // end of good response
  } // end of for loop
  Serial.println ("Done.");
  
  if (!targetFound) {
    Serial.println("Target primary address NOT FOUND.");
  }

  if (endCode[SUCCESS] == NUM_I2C) {   // found expected number of devices.
    Serial.print("Found ");
    Serial.print(endCode[SUCCESS], DEC);
    Serial.print(" device(s).");
    Serial.println(" [TARGET NUMBER]");
  }
  else {   // print error codes regardless...
    if (endCode[SUCCESS]) {       // found something, but not expected number
      Serial.print("Found ");
      Serial.print(endCode[SUCCESS], DEC);
      Serial.print(" device(s).");
      Serial.println(" [NON-TARGET NUMBER]");
    }
    else {                        // found nothing
      Serial.println("NO DEVICE FOUND.");
    }
    // Print error message(s):
    if (endCode[OVERFLOW]) {   
      Serial.println("ERROR: Data too long to fit in transmit buffer. [x");
      Serial.print(endCode[OVERFLOW], DEC);
      Serial.println(" address(es)]");
    }
    if (endCode[NACK_ADDRESS]) {
      Serial.print("ERROR: Received NACK on transmit of address. [x");
      Serial.print(endCode[NACK_ADDRESS], DEC);
      Serial.println(" address(es)]"); 
    }
    if (endCode[NACK_DATA]) {
      Serial.println("ERROR: Received NACK on transmit of data. [x");
      Serial.print(endCode[NACK_DATA], DEC);
      Serial.println(" address(es)]");
    }
    if (endCode[OTHER_ERROR]) {
      Serial.println("ERROR: Other error. [x");
      Serial.print(endCode[OTHER_ERROR], DEC);
      Serial.println(" address(es)]");
    }
    if (endCode[TIMEOUT]) {
      Serial.println("ERROR: Timeout. [x");
      Serial.print(endCode[TIMEOUT], DEC);
      Serial.println(" address(es)]");
    }
  }//end serial prints
  Serial.println();
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
  }// end <switchStatus> switch-case
}// end testSwitchMute

void testLEDs(void) {
  byte test = testCount % (1 + (2*NUM_LIGHTS + 1));      // total number of tests counter
  byte testEachLight = (test - 1) % NUM_LIGHTS;     // counter for iterating through lights (0 -> NUM_LIGHTS-1)

  // guard clauses
  if (test != T_LED_BUILTIN) {
    digitalWrite(LED_BUILTIN, LOW);
  }
  if (test <= T_LIGHTS_START || test >= T_LIGHTS_END) {
    for (byte i = 0; i < NUM_LIGHTS; ++i) {   // turn off every light if not testing
      digitalWrite(LIGHT[i], LOW);
    }
  }

  // Exclusive testing
  switch (test) {
    case T_LED_BUILTIN:             // wink built-in LED
      updateWink();
      if (!printStatus) {    // print once
        Serial.println("Now winking built-in LED.");   
        printStatus = true;
      }
      break;
    
    case T_LIGHTS_START ... 5:      // Sequentially drive each light individually
      for (byte i = 0; i < NUM_LIGHTS; ++i) {    
        if (i != testEachLight) {
          digitalWrite(LIGHT[i], LOW);    // Turn off every other light
        }
        else {
          digitalWrite(LIGHT[i], HIGH);   // selected
        }
      }

      if (!printStatus) {   // print once
        Serial.print("Now individually driving LIGHT ");
        Serial.println(testEachLight, DEC);  
        printStatus = true;
      }
      break;

    case 6 ... 10:      // Sequentially drive all but one light
      for (byte i = 0; i < NUM_LIGHTS; ++i) {   
        if (i == testEachLight) {     // turn ON all lights apart from selected
          digitalWrite(LIGHT[i], LOW);
        }
        else {
          digitalWrite(LIGHT[i], HIGH); // selected
        }
      }

      if (!printStatus) {   // print once
        Serial.print("Now driving all but LIGHT ");
        Serial.println(testEachLight, DEC);  
        printStatus = true;         
      }
      break;

    case T_LIGHTS_END:   // Drive ALL lights
      for (byte i = 0; i < NUM_LIGHTS; ++i) {
        digitalWrite(LIGHT[i], HIGH);
      }

      if (!printStatus) {   // print once
        Serial.print("Now driving all ");
        Serial.print(NUM_LIGHTS, DEC);
        Serial.println(" Lights.");
        printStatus = true;
      }      
      break;
  }// end test switch-case
}// end testLEDS()

void stopTestLEDs(void) {
  digitalWrite(LED_BUILTIN, LOW);           // Test 1
  for (byte i = 0; i < NUM_LIGHTS; ++i) {   // Test 2++
    digitalWrite(LIGHT[i], LOW);
  }
}// end stopTestLEDs

void testBuzzer(void) {
  byte test = testCount % 2;        // total number of tests counter - modify const int to change number of tests

  switch (test) {
    case T_BUZZER_CONT:  // Continuous buzzing
      tone(TONE_PIN, BUZZER_TEST_FREQ);
      if (!printStatus) {    // print once
        Serial.print("Continuously driving Buzzer at tone frequency: ");
        Serial.print(BUZZER_TEST_FREQ);
        Serial.println(" Hz");   
        printStatus = true;
      }
      break;

    case T_BUZZER_INT:  // Intermittent buzzing
      const unsigned long ms = millis();
      uint16_t buzzTime_ms = 500;
      
      if (ms - lastTestTime_ms > buzzTime_ms) {
          buzzer = !buzzer;
          lastTestTime_ms = ms;
      }
      
      if (buzzer) {
        tone(TONE_PIN, BUZZER_TEST_FREQ);
      }
      else {
        noTone(TONE_PIN);
      }
      
      if (!printStatus) {    // print once
        uint16_t pulseFreq = (uint16_t)(2*buzzTime_ms/1000);
        Serial.print("Intermittently (~");
        Serial.print(pulseFreq, DEC);
        Serial.print(" Hz) driving Buzzer at tone frequency: ");
        Serial.print(BUZZER_TEST_FREQ);
        Serial.println(" Hz");  
        printStatus = true;
      }
      break;
  }//end <test> switch-case
}//end testBuzzer()

void stopTestBuzzer(void) {
  noTone(TONE_PIN);
  buzzer = false;
}//end stopTestBuzzer()

void testI2C(void) {
  if (!printStatus) {      // do once
    Serial.println("Start I2C scan");
    scanI2C();
    Serial.println("End I2C scan");
    printStatus = true;
  }
}// end testI2C()

void testLCD(void) {
  byte fillChar[8] {
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111
  };
  byte voidChar[8] {
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000
  };
  byte indxFill = 0;           // for custom chars
  byte indxVoid = 1;
  byte rows = 4;
  byte cols = 20;
  byte test = testCount % 5;    // total number of tests counter
  const unsigned long ms = millis();
  uint16_t displayTime = 1000;        // in ms
  
  // guard clauses
  if (test != T_ASCII_CHARS) {
    ASCII = 33;
  }
  if (test != T_GRID_FILL && test != T_GRID_CLEAR) {
    charCountX = 0;
    charCountY = 0;
  }
  
  lcd.createChar(indxFill, fillChar);
  lcd.createChar(indxVoid, voidChar);

  // Exclusive Tests
  switch (test) {
    case T_BACKLIGHT:
      if (!printStatus) {    // do once
        lcd.clear();
        Serial.println("Now testing backlight.");
        printStatus = true;
      }
      lcd.backlight();
      break;
    
    case T_DEAD_PIXELS:
      if (!printStatus) {     // do once
        for (byte i = 0; i < rows; ++i) {    // rows
          for (byte j = 0; j < cols; ++j) {   // columns
            lcd.setCursor(j, i);
            lcd.write(indxFill);
          }// end columns
        }// end rows   
        Serial.println("Now testing for dead pixels.");
        printStatus = true;
      }
      break;

    case T_GRID_FILL:
      if (ms - lastTestTime_ms > displayTime) {     // every so often do...
        for (byte i = 0; i < rows; ++i) {     // rows
          for (byte j = 0; j < cols; ++j) {    // columns
            lcd.setCursor(j, i);
            if (j == charCountX && i == charCountY) { lcd.write(indxVoid); }  // fill all but test char
            else { lcd.write(indxFill); }
          }// end columns
        }// end rows
        Serial.print("Now testing grid coordinate (");
        Serial.print(charCountX);
        Serial.print(", ");
        Serial.print(charCountY);
        Serial.println(") against filled background.");
        charCountX = ++charCountX % 20;             // move to next coord..
        if (charCountX == 0) { charCountY = ++charCountY % 4; } 
        lastTestTime_ms = ms;
      }
      break;

    case T_GRID_CLEAR:
      if (ms - lastTestTime_ms > displayTime) {     // every so often do...
        for (byte i = 0; i < rows; ++i) {     // rows
          for (byte j = 0; j < cols; ++j) {    // columns
            lcd.setCursor(j, i);
            if (j == charCountX && i == charCountY) { lcd.write(indxFill); }  // fill only test char
            else { lcd.write(indxVoid); }
          }// end columns
        }// end rows
        Serial.print("Now testing grid coordinate (");
        Serial.print(charCountX);
        Serial.print(", ");
        Serial.print(charCountY);
        Serial.println(") against clear background.");
        charCountX = ++charCountX % 20;             // move to next coord..
        if (charCountX == 0) { charCountY = ++charCountY % 4; } 
        lastTestTime_ms = ms;
      }
      break;

    case T_ASCII_CHARS:
      if (ms - lastTestTime_ms > displayTime) {   // every so often, change...
        const char testChar = (char)ASCII;
        for (byte i = 0; i < rows; ++i) {     // rows
          for (byte j = 0; j < cols; ++j) {     // columns
            lcd.setCursor(j, i);
            lcd.print(testChar);
          }// end columns
        }// end rows
        Serial.print("Now printing character '");
        Serial.print(testChar);
        Serial.println("'");
        ASCII = ++ASCII % 127;              // loop ASCII        
        if (ASCII == 0) { ASCII = 33; }     // between 33->127
        lastTestTime_ms = ms;
      }
      break;
  }
}// end testLCD()

void stopTestLCD(void) {
  clearLCD();
}// end stopTestLCD()

void autoToggleTest(void) {     // to automatically toggle between individual tests
  if (!autoToggle){
    return;
  }

  const unsigned long ms = millis();
  int testTime_ms = 3000;

  if (ms - lastToggleTime_ms > testTime_ms) {
    testCount++;
    printStatus = false;    // to enable indiviual tests to print to monitor
    lastToggleTime_ms = ms;
  }
}// end autoToggleTest()

void testGroupFunctions(void) {
  testGroup = testGroupCount % testGroups;
  autoToggleTest();

  // guard clauses
  if (testGroup != TG_LEDS) {
    stopTestLEDs();
  }
  if (testGroup != TG_BUZZER) {
    stopTestBuzzer();
  }
  if (testGroup != TG_LCD) {
    stopTestLCD();
  }

  // exclusive test groups
  switch (testGroup) {
    case TG_LEDS:
      testLEDs();
      break;

    case TG_BUZZER:
      testBuzzer();
      break;

    case TG_I2C:
      testI2C();
      break;

    case TG_LCD:
      testLCD();
      break;
  }
}// end testGroupFunctions()

void testGroupPrint(void) {   // for displaying to serial monitor
  testGroup = testGroupCount % testGroups;
  switch (testGroup) {
    case TG_SWITCH_MUTE:
      Serial.println();
      Serial.println("*** Now testing Mute Switch functionality. ***");
      break;

    case TG_LEDS:
      Serial.println();
      Serial.println("*** Now testing LED functionality. ***");
      break;

    case TG_BUZZER:
      Serial.println();
      Serial.println("*** Now testing Buzzer functionality. ***");
      break;

    case TG_I2C:
      Serial.println();
      Serial.println("*** Now testing I2C functionality. ***");
      break;

    case TG_LCD:
      Serial.println();
      Serial.println("*** Now testing LCD functionality. ***");
      break;
  }
}// end testGroupPrint()

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
  delay(3000);
  Serial.println("End LCD splash");

  Serial.println("Set up GPIO pins");
  switchMute.set(SWITCH_MUTE, switchMuteEvent, INT_PULL_UP);
  switchMute.enableLongPress(longPressTime);
  switchMute.enableMultiHit(multiHitTime, multiHitTarget);
  for (int i = 0; i < NUM_LIGHTS; i++) {
    Serial.println(LIGHT[i]);
    pinMode(LIGHT[i], OUTPUT);
  }
  Serial.println("End set up GPIO pins");
  
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
      printStatus = false;
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
      break;

    case onMultiHit:
      testSwitchMute(switchStatus);
      testGroupCount++;
      testGroupPrint();
      printStatus = false;
      testCount = 0;          
      break;
  }
}//end switchMuteEvent()
