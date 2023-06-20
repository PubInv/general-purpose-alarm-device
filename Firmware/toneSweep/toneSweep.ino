/*  toneSweep

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


  Audio Sweep for GPAD

  circuit:
  - transducer such as Piezo at BZ601 or or 8 ohm speaker on J601
  - Tone on Arduino digital pin 8
  - Attenuate on Arduino digital pin 4
  - sweepStart on Arduino digital pin TBD. Perhaps use Light0

*/

#include "pitches.h"

#define PROG_NAME "******toneSweep******"     //Descriptive name of this software, 20 characters.
#define VERSION "Version: 0.1"     //Version of this firmware.
#define TONE_PIN 8
#define ATTENUATE_PIN 4
#define SWEEP_START_PIN 3  //Same as LIGHT0

#define BAUDRATE 115200

#define LIGHT1 5                                // on D5
#define  BUTTON_PIN 2                          //Button to GND, 10K Resistor to +5V.
bool isMuted = false;   //State Variable

/*linear frequency sweep
   from startTone to stopTone at sweepTime
   This funcation is non blocking.
*/
int startFrequency = 400; //Hz
int stopFrequency = 4000; //Hz
//int sweepTime = 1000; //mS
//int sweepTime = 860; //mS   This makes each 4.6 division on oscilliscope for sweep.
int sweepTime = 660; //mS   This makes each division on oscilliscope to be 500Hz @ 100mS/div.
int pauseTime = 500; //mS
float slopFreq = float(stopFrequency - startFrequency) / float(sweepTime);

unsigned long startTime;
unsigned long sweepElapsedTime;

void updateSweepTone() {
  int freq = startFrequency;
  sweepElapsedTime = (millis() - startTime);

  if (sweepElapsedTime < sweepTime) {
    //Sweeping sso set to new new frequency
    digitalWrite(SWEEP_START_PIN, HIGH);  //Set LIGHT0
    freq = slopFreq * (millis() - startTime);
    tone(TONE_PIN, int(freq));
    analogWrite(LIGHT1, (float(sweepElapsedTime) / float(sweepTime)) * 255);

  } else if (sweepElapsedTime < (sweepTime + pauseTime)) {
    //We have gone over sweep time so reset frequency
    //Stop the tone and clear LIGHT0 and LIGHT1 to indicate sweep status
    digitalWrite(SWEEP_START_PIN, LOW);  //Clear LIGHT0
    analogWrite(LIGHT1, 0);
    noTone(TONE_PIN);
    pinMode(TONE_PIN, OUTPUT);  //Lets force the pin
    digitalWrite(TONE_PIN, LOW);
  }//end else over sweep time
  else {
    //We are at end of pause so set up for a new sweep.
    freq = startFrequency;
    Serial.println("Starting sweep");
    digitalWrite(SWEEP_START_PIN, HIGH); //Set LIGHT0
    startTime = millis();
  }
}//end updateSweepTone



void playMelodyArray() {
  // notes in the melody:
  int melody[6][8] = {
    {NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4}, //Shave and a hair cut
    {NOTE_C5, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, 0, NOTE_B4, NOTE_C5},
    {NOTE_C6, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_G5, 0, NOTE_B5, NOTE_C6},
    {NOTE_C7, NOTE_G6, NOTE_G6, NOTE_A6, NOTE_G6, 0, NOTE_B6, NOTE_C7},
    {NOTE_C8, NOTE_G7, NOTE_G7, NOTE_A7, NOTE_G7, 0, NOTE_B7, NOTE_C8},
    {NOTE_C6, NOTE_F7, NOTE_G7, NOTE_C6, NOTE_F7, NOTE_G7, NOTE_C6, NOTE_C6}  //C major cord notes
  };

  // note durations: 4 = quarter note, 8 = eighth note, etc.:
  int noteDurations[] = {
    4, 8, 8, 4, 4, 4, 4, 4
  };

  //Itterate over melodys
  for (int thisMelody = 0; thisMelody < 6; thisMelody++) {
    Serial.print("Playing melody number: ");
    Serial.println(thisMelody);

    // iterate over the notes of the melody:
    //Play a melody
    for (int thisNote = 0; thisNote < 8; thisNote++) {
      // to calculate the note duration, take one second divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / noteDurations[thisNote];
      tone(TONE_PIN, melody[thisMelody][thisNote], noteDuration);

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(TONE_PIN);
    }// end play a melody
    int pauseBetweenMelody = 1000 / noteDurations[5] * 5;
    delay(pauseBetweenMelody);
  }//end thisMelody
}//playMelodyArray

void setup() {
  //Serial setup
  delay(100);
  Serial.begin(BAUDRATE);
  delay(100);                         //Wait before sending the first data to terminal
  Serial.println(F(PROG_NAME));
  Serial.println(F(VERSION));
  //  Serial.print("slopFreq= ");
  //  Serial.println(slopFreq);

  //Print Instructions to Serial Port
  Serial.println("Press the button S601 for toneSweep.");

  pinMode( BUTTON_PIN , INPUT_PULLUP); //So we can start and stop the sweep.

  /* Play the mellody array once using setup()*/
  //  playMelodyArray();
  //  delay(1000);

  //Setup pin for trigger of oscilliscope
  pinMode(SWEEP_START_PIN, OUTPUT);
  digitalWrite(SWEEP_START_PIN, LOW);

  startTime = millis(); //Set the start time for the frequency sweep
  sweepElapsedTime = (millis() - startTime);
  digitalWrite(SWEEP_START_PIN, HIGH);
}//end setup

void loop() {

  /* Play the mellody array looping endlesly*/
  //  playMelodyArray();
  //  delay(1000); // Delay between melody arrays.

  /* Play the toneSweep at user command (button)*/
  //Press the GPAD MUTE button S601 to play toneSweep
  if (digitalRead(BUTTON_PIN) == LOW) { // check for button pressed
    //    isMuted = false;
    updateSweepTone();
  } else {
    noTone(TONE_PIN);
    digitalWrite(SWEEP_START_PIN, LOW);  //Clear LIGHT0
    analogWrite(LIGHT1, 0);              //Clear LIGHT1
    startTime = millis();
  }

}//end loop()
