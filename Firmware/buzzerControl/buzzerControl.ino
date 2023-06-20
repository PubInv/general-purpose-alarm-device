/*  buzzerControl

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


  Buzzer Control for GPAD

  circuit:
  - transducer such as Adafrut P1536A or Floyd Bell TXC-86-5150Q buzzer connected on J601.
  - Buzzer control on Arduino digital pin 8
  - Attenuate on Arduino digital pin 4
  - Buzzer on when GPAD Mute button pressed. Perhaps also light Light0

*/

//#include "pitches.h"

#define PROG_NAME "******tobuzzerControl******"     //Descriptive name of this software, 20 characters.
#define VERSION "Version: 0.1"     //Version of this firmware.
#define BUZZER_PIN 8
#define ATTENUATE_PIN 4
#define BUZZER_START_PIN 3  //Same as LIGHT0

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
    digitalWrite(BUZZER_START_PIN, HIGH);  //Set LIGHT0
    freq = slopFreq * (millis() - startTime);
    tone(BUZZER_PIN, int(freq));
    analogWrite(LIGHT1, (float(sweepElapsedTime) / float(sweepTime)) * 255);

  } else if (sweepElapsedTime < (sweepTime + pauseTime)) {
    //We have gone over sweep time so reset frequency
    //Stop the tone and clear LIGHT0 and LIGHT1 to indicate sweep status
    digitalWrite(BUZZER_START_PIN, LOW);  //Clear LIGHT0
    analogWrite(LIGHT1, 0);
    noTone(BUZZER_PIN);
    pinMode(BUZZER_PIN, OUTPUT);  //Lets force the pin
    digitalWrite(BUZZER_PIN, LOW);
  }//end else over sweep time
  else {
    //We are at end of pause so set up for a new sweep.
    freq = startFrequency;
    Serial.println("Starting sweep");
    digitalWrite(BUZZER_START_PIN, HIGH); //Set LIGHT0
    startTime = millis();
  }
}//end updateSweepTone




void setup() {
  //Serial setup
  delay(100);
  Serial.begin(BAUDRATE);
  delay(100);                         //Wait before sending the first data to terminal
  Serial.println(F(PROG_NAME));
  Serial.println(F(VERSION));

  //Print Instructions to Serial Port
  Serial.println("Press the button S601 for buzzerControl On.");

  pinMode( BUTTON_PIN , INPUT_PULLUP); //So we can start and stop the sweep.

  pinMode( BUZZER_PIN , OUTPUT); // Make output
  digitalWrite(BUZZER_PIN, HIGH); // Make Buzzer on setup()

  //Setup pin for trigger of oscilliscope
  pinMode(BUZZER_START_PIN, OUTPUT);

  startTime = millis(); //Set the start time for the frequency sweep
  sweepElapsedTime = (millis() - startTime);
  digitalWrite(BUZZER_START_PIN, HIGH);
  digitalWrite(BUZZER_PIN, LOW);
}//end setup

void loop() {

  /* Play the toneSweep at user command (button)*/
  //Press the GPAD MUTE button S601 to make high buzzerControl
  if (digitalRead(BUTTON_PIN) == LOW) { // check for button pressed
    //Turn on buzzer
    digitalWrite(BUZZER_PIN, HIGH);
    analogWrite(LIGHT1, 255);

  } else {
    //Turn off buzzer
    digitalWrite(BUZZER_PIN, LOW);
    analogWrite(LIGHT1, 0);
  }

}//end loop()
