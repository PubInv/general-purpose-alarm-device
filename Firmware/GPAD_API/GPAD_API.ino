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

#define PROG_NAME "******GPAD_API******"     //Descriptive name of this software, 20 characters.
#define VERSION 0.1             //Version of this software
#define BAUDRATE 115200


enum AlarmLevel { silent, informational, problem, warning, critical, panic };
const char *AlarmNames[] = { "OK   ","INFO.","PROB.","WARN ","CRIT.","PANIC" };
const int NUM_LEVELS = 6;

char AlarmMessageBuffer[128];

// here is the abstract "state" of the machine,
// completely independent of hardware.
// This is very simple version of what is probably needed.
// For example, perhaps the abstract machine should know how long
// it has been in a given alarm state. At present, this 
// is a "dumb" machine---the user of it is expected to do
// all alarm management.
AlarmLevel currentLevel = silent;
boolean currentlyMuted = false;


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

const int BUZZER_LVL_FREQ_HZ[]= {0,128,256,512,1024,2048};

// in general, we want tones to last forever, although
// I may implement blinking later.
const unsigned long INF_DURATION = 4294967295;

//For I2C Scan
#include <Wire.h>
//For LCD
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x38, 20, 4); // set the LCD address to 0x27 for a 20 chars and 4 line display in Wokwi, and 0x38 for the physical GPAD board
// To Debounce our standard button
#include <DailyStruggleButton.h>
DailyStruggleButton muteButton;

//Pin definitions.  Assign symbolic constant to Arduino pin numbers. 
//For more information see: https://www.arduino.cc/en/Tutorial/Foundations/DigitalPins
#define SWITCH_MUTE 2 
#define TONE_PIN 8
#define LIGHT0 3
#define LIGHT1 5
#define LIGHT2 6
#define LIGHT3 9
#define LIGHT4 7

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
}
// TODO: We need to break the message up into strings to render properly
// on the display
void showStatusLCD(AlarmLevel level,bool muted,char *msg) {
  lcd.init(); 
  lcd.clear();
  // Possibly we don't need the backlight if the level is zero!
  if (level != 0) {
    lcd.backlight();
  } else {
    lcd.noBacklight(); 
  }

  lcd.print("LVL: ");
  lcd.print(level);
  lcd.print(" - ");
  lcd.print(AlarmNames[level]);


  lcd.setCursor(0, 1);

  if (muted) {
    lcd.print("MUTED! MSG:");
  } else {
    lcd.print("MSG:  ");
  }
  if (strlen(AlarmMessageBuffer) == 0) {
    lcd.print("None.");
  } else {


    char buffer[21] = {0}; // note space for terminator

    size_t len = strlen(msg);      // doesn't count terminator
    size_t blen = sizeof(buffer)-1; // doesn't count terminator
    size_t i = 0;
    // the actual loop that enumerates your buffer
    for (i=0; i<(len/blen + 1) && i < 3; ++i)
    {
      memcpy(buffer, msg + (i*blen), blen);
      Serial.println(buffer);
      lcd.setCursor(0,i+1);
      lcd.print(buffer);
    }
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
  
  Wire.begin();

 
  lcd.init();              
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

  muteButton.set(SWITCH_MUTE, myCallback);
  Serial.println("end set up GPIO pins");

  printInstructions(); 
  AlarmMessageBuffer[0] = '\0';
  
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off at end of setup
}// end of setup()

// We accept maessages up to 128 characters, with 2 characters in front,
// and an end-of-string delimiter makes 131 characters!
const int COMMAND_BUFFER_SIZE = 131;
char buf[COMMAND_BUFFER_SIZE];

const int NUM_PREFICES = 4;
char legal_prefices[NUM_PREFICES] = {'h','s','a','u'};


// This is the abstract alarm function. It CANNOT
// assume the msg buffer will exist after this call.
// str must be null-terminated string!
int alarm(int level,char *str) {
  if (!(level >= 0 && level < NUM_LEVELS)) {
    Serial.println("Bad Level!");
    printError();
    return;
  }
  currentLevel = level;
  // This makes sure we erase the buffer even if msg is an empty string
  AlarmMessageBuffer[0] = '\0'; 
  strcpy(AlarmMessageBuffer,str);
  return currentLevel;
}


void printInstructions() {
  Serial.println(F("PubInv GPAD: enter command in form CDa (C is a char, D is a digit)"));
}

void printAlarmState() {
  Serial.print("Muted: ");
  Serial.println(currentlyMuted ? "YES" : "NO");
  Serial.print("LVL: ");
  Serial.println(currentLevel);
  if (strlen(AlarmMessageBuffer) == 0) {
    Serial.println("No Message.");
  } else {
    Serial.print("Msg: ");
    Serial.println(AlarmMessageBuffer);
  }
}

void printError() {
    Serial.println(F("bad format of command!"));
    printInstructions();
}

// This is a trivial "parser". This should probably be moved
// into a separate .cpp file.
/*
This is a simple protocol:
CD\n
where C is an character, and D is a single digit.
*/
void interpretBuffer(char *buf,int rlen) {
  if (rlen < 1) {
    printError();
    return; // no action
  }

  boolean found = false;
  for(int i = 0; i < NUM_PREFICES; i++) {
    if (buf[0] == legal_prefices[i]) found = true;
  }
  if (!found) {
    printError();
    return;
  }
  char C = buf[0];

  Serial.print(F("Command: "));
  Serial.println(C);
  switch (C) {
    case 's':
      Serial.println("Muting Case!");
      currentlyMuted = true;
      break;
    case 'u':
      Serial.println("UnMuting Case!");
      currentlyMuted = false;
      break;
    case 'h': // help
      printInstructions();
      break;
    case 'a': {
    // In the case of an alarm state, the rest of the buffer is a message.
    // we will read up to 60 characters from this buffer for display on our
    // Arguably when we support mulitple states this will become more complicated.
      char D = buf[1];
      int N = D - '0';
      Serial.println(N);
      char msg[61];
      msg[0] = '\0';
      strcpy(msg, buf+2);
      // This copy loooks uncessary, but is not...we want "alarm" 
      // to be a completely independent and abstract function.
      // it should copy the msg buffer
      alarm(N,msg);
      break;
    }
    default:
      Serial.println(F("Unknown Command"));
      break;
  }
  Serial.println("currentlyMuted : ");
  Serial.println(currentlyMuted);
  Serial.println(F("interpret Done"));
}


// This operation is idempotent if there is no change in the abstract state.
void annunciateAlarmLevel() {
  for(int i = 0; i < currentLevel; i++) {
    digitalWrite(LIGHT[i],HIGH);
  }
  for(int i = currentLevel; i < NUM_LIGHTS; i++) {
    digitalWrite(LIGHT[i],LOW);
  }
  if (!currentlyMuted) {
    tone(TONE_PIN, BUZZER_LVL_FREQ_HZ[currentLevel],INF_DURATION);
  } else {
    noTone(TONE_PIN);
  }
  showStatusLCD(currentLevel,currentlyMuted,AlarmMessageBuffer);
}

void myCallback(byte buttonEvent){
  switch (buttonEvent){
    case onPress:
      // Do something...
      Serial.println("onPress");
      currentlyMuted = !currentlyMuted;
      annunciateAlarmLevel();
      printAlarmState();
      break;
  }
}

void processSerial() {
   // Now see if we have a serial command
    int rlen;
    // TODO: This code can probably hang; it needs to have 
    // timeouts added!
    if (Serial.available() > 0) {
      // read the incoming bytes:
      int rlen = Serial.readBytesUntil('\n', buf, COMMAND_BUFFER_SIZE); 
      // readBytesUntil does not terminate the string!
      buf[rlen] = '\0';
      // prints the received data
      Serial.print("I received: ");
      Serial.print(rlen);
      for(int i = 0; i < rlen; i++)
        Serial.print(buf[i]);
      Serial.println();
      interpretBuffer(buf,rlen);
      // Now "light and scream"appropriately...
      annunciateAlarmLevel();
      printAlarmState();
     } 
}

void loop() {
  updateWink(); //The builtin LED 
  
  muteButton.poll();
  
  processSerial();
}
