/*
  
  ExampleR4VoltageRead.ino - Controller code for using one GPAD to control another.

  Copyright (C) 2024 Robert L. Read

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
  ReadAnalogVoltage


  This code is based on example from here:

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/ReadAnalogVoltage

  This program exists to demonstrate using the GPAD from a simple 
  Arudion R4 via the SPI interface.

  It reads a voltage from an analog input pin, and assumes that
  as the voltage increases, the situation is becoming more dangerous
  and requires more human attention. This is embodied by a simple
  potentiometer, which can be turned by hand to demostrate the GPAD.

  This code is very similar to the GPAD_API_SPI_CONTROLLER code.
  That code, however, is used by this project to test a GPAD by
  using a GPAD itself as a controller. Since most users are not 
  going to have two GPADs, showing how to use one from a simple,
  cheap, widely avaialabe micrcontroller, such as an Arduino R4.

  Note: This Arduion project copies some utility files into this 
  directory. These are:
    GPAD_ALARM_API_SPI.cpp
    GPAD_ALARM_API_SPI.h
    alarm_api.h
  This is a code duplcation which is bad form; these should probably
  be made into a separate repo so that these can included as a 
  separate libary. This is issue #263 in our repo,
  https://github.com/PubInv/general-purpose-alarm-device/issues/263

*/

#include<SPI.h> 
#include "GPAD_Alarm_API_SPI.h"


#define PROG_NAME "Example R4 Voltage Read" 
#define VERSION 0.1
#define BAUDRATE 115200

int GPAD_CS = SS;

void local_setup(void) {
   pinMode(GPAD_CS, OUTPUT);                    // Set nCS for output
  pinMode(MISO, INPUT);                   //Sets MISO as INPUT. Note MOSI must be set automaticaly
  SPI.begin();

  Serial.println(PROG_NAME);
  Serial.println("GPAD Example R4 Voltage Read");
  Serial.println("by PubInv & SPEC");
  Serial.print("Version: ");
  Serial.println(VERSION);
  Serial.println("MISO,MOSI,GPAD_CS,SCK");
  Serial.println(MISO);
  Serial.println(MOSI);
  Serial.println(GPAD_CS);
  Serial.println(SCK); 
}

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(BAUDRATE);

  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }
  local_setup();
}

// These will be a function of the specific potentiometer you use
const float MAX_VOLTAGE = 3.11;
const float MIN_VOLTAGE = 0.33;
const float RANGE_V = MAX_VOLTAGE - MIN_VOLTAGE;
const float STEP = RANGE_V / 6.0;

const char *msg[6] = { "very low voltage, all well",
"low voltage, you may want to look into this",
"medium-low voltage, time to take action",
"medium voltage, take action now!",
"medium-high voltage, disaster imminent!",
"high voltage, catastrophe"
};

int alarm_level_from_voltage(float v) {
  float dv = v - MIN_VOLTAGE;
  for(int i = 0; i < 6; i++) {
    if (dv < i*STEP) 
      return i;
  }
  return 5;
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (3.3 / 1023.0);
  int al = alarm_level_from_voltage(voltage);

  AlarmEvent event;
  event.lvl = al;

  sprintf(event.msg, "v=%.2f %s", voltage,msg[al]);
  int n = strlen(event.msg);
  event.msg[n] = 0;

  alarm_event(event,Serial);
  Serial.println(event.msg);
  Serial.println(F("LEVEL: "));
  Serial.println(event.lvl);

  delay(500);
}

