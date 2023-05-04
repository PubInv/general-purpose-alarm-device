/* robot_api.cpp
   the "robot" (low-level hardware) api

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

*/

#include <arduino.h>
#include "robot_api.h"
#include "alarm_api.h"
#include "gpad_utility.h"
#include "gpad_serial.h"
#include "dfplayer.h"

#include <DailyStruggleButton.h>
DailyStruggleButton muteButton;

extern const char *AlarmNames[];
extern AlarmLevel currentLevel;
extern bool currentlyMuted;
extern char AlarmMessageBuffer[81];

//For LCD
#include <LiquidCrystal_I2C.h>

//GPAD hardware
//LiquidCrystal_I2C lcd(0x38, 20, 4); // set the LCD address to 0x27 for a 20 chars and 4 line display in Wokwi, and 0x38 for the physical GPAD board

//test LCD
LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 20 chars and 4 line display in Wokwi, and 0x38 for the physical GPAD board

//Setup for buzzer.
//const int BUZZER_TEST_FREQ = 130; // One below middle C3. About 67 db, 3" x 4.875" 8 Ohm speakers no cabinet at 1 Meter.
//const int BUZZER_TEST_FREQ = 260; // Middle C4. About ?? db, 3" x 4.875" 8 Ohm speakers no cabinet at 1 Meter.
//const int BUZZER_TEST_FREQ = 1000; //About 76 db, 3" x 4.875" 8 Ohm speakers no cabinet at 1 Meter.
const int BUZZER_TEST_FREQ = 4000; // Buzzers, 3 V 4kHz 60dB @ 3V, 10 cm.  The specified frequencey for the Version 1 buzzer.

const int BUZZER_LVL_FREQ_HZ[]= {0,128,256,512,1024,2048};


// in general, we want tones to last forever, although
// I may implement blinking later.
const unsigned long INF_DURATION = 4294967295;
long msPlayBegin=0;
const long AUDIO_WAIT_TIME=5000;

//Allow indexing to LIGHT[] by symbolic name. So LIGHT0 is first and so on.
const int LIGHT[] = {2,26,25,14,15,4};
int NUM_LIGHTS = sizeof(LIGHT)/sizeof(LIGHT[0]);

Stream* local_ptr_to_serial;

// Have to get a serialport here
void myCallback(byte buttonEvent){
  switch (buttonEvent){
    case onPress:
      // Do something...
      local_ptr_to_serial->println(F("onPress"));
      currentlyMuted = !currentlyMuted;
      annunciateAlarmLevel();
      printAlarmState(*local_ptr_to_serial);
      break;
  }
}

void checkAlarmIteration(Stream* serialport){
  long msNow= millis();
  long msSincePlay=msNow-msPlayBegin;

  
  
  if(msSincePlay>AUDIO_WAIT_TIME){
    serialport->println(F("Audio wait time up"));
    annunciateAlarmLevel();
    
  }

  }


void robot_api_setup(Stream* serialport) {

  local_ptr_to_serial = serialport;
  Wire.begin();
  lcd.init();
  serialport->println(F("Clear LCD"));
  clearLCD();
  delay(100);
  serialport->println(F("Start LCD splash"));
  splashLCD();
  serialport->println(F("EndLCD splash"));

  serialport->println(F("Set up GPIO pins"));
  pinMode(SWITCH_MUTE, INPUT_PULLUP);
  for (int i = 0; i < NUM_LIGHTS; i++) {
    serialport->println(LIGHT[i]);

    //uncomment later
    //pinMode(LIGHT[i], OUTPUT);
  }

  serialport->println(F("about to set up mute callback"));

  //muteButton.set(SWITCH_MUTE, myCallback);

  serialport->println(F("end set up GPIO pins"));

  printInstructions(*serialport);
  AlarmMessageBuffer[0] = '\0';

  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off at end of setup
}



// This has to be called periodically, at a minimum to handle the mute_button
void robot_api_loop() {
    muteButton.poll();
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
  if (level >= 0) {
    lcd.backlight();
  } else {
    lcd.noBacklight();
  }

  lcd.print("LVL: ");
  lcd.print(level);
  lcd.print(" - ");
  lcd.print(AlarmNames[level]);

  int msgLineStart = 1;
  lcd.setCursor(0,msgLineStart);
  int len = strlen(AlarmMessageBuffer);
  if (len < 9) {
    if (muted) {
      lcd.print("MUTED! MSG:");
    } else {
      lcd.print("MSG:  ");
    }
    msgLineStart = 2;
  }
    if (strlen(AlarmMessageBuffer) == 0) {
      lcd.print("None.");
    } else {

    char buffer[21] = {0}; // note space for terminator

    size_t len = strlen(msg);      // doesn't count terminator
    size_t blen = sizeof(buffer)-1; // doesn't count terminator
    size_t i = 0;
    // the actual loop that enumerates your buffer
    for (i=0; i<(len/blen + 1) && i + msgLineStart < 4; ++i)
    {
      memcpy(buffer, msg + (i*blen), blen);
      local_ptr_to_serial->println(buffer);
      
      lcd.setCursor(0,i+msgLineStart);
      lcd.print(buffer);
    }
   }
}


// This operation is idempotent if there is no change in the abstract state.
void annunciateAlarmLevel() {

for (int i = 0; i < 7; i++) {
  if(currentLevel>0){
  digitalWrite(LIGHT[(int)currentLevel - 1], HIGH);
  }
  if(LIGHT[i] != LIGHT[(int)currentLevel - 1]){
    digitalWrite(LIGHT[i], LOW);
  }

if((int)currentLevel ==5){
  digitalWrite(4, HIGH);
}


  if((int)currentLevel == 0){
    digitalWrite(LIGHT[i], LOW);
    digitalWrite(4, LOW);
    
  }
  
}




  //you will change this
    // tone(TONE_PIN, BUZZER_LVL_FREQ_HZ[currentLevel],INF_DURATION);
      if(!currentlyMuted){
        //msPlayBegin=millis();
        playMessage1(currentLevel);    
      }
      else if (currentlyMuted){
        muting();
      }

  //uncomment later
  showStatusLCD(currentLevel,currentlyMuted,AlarmMessageBuffer);
}
