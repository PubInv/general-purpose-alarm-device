//  GPAD server code v0.1
//  Copyright (C) 2022 Robert L. Read
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <https://www.gnu.org/licenses/>.


#define BAUD_RATE 9600

const int BUFFER_SIZE = 100;
char buf[BUFFER_SIZE];

const int NUM_PREFICES = 4;
char legal_prefices[NUM_PREFICES] = {'h','s','a','u'};

enum AlarmLevel { silent, informational, problem, warning, critical, panic };

// here is the abstract "state" of the machine,
// completely independent of hardware.
// This is very simple version of what is probably needed.
// For example, perhaps the abstract machine should know how long
// it has been in a given alarm state. At present, this 
// is a "dumb" machine---the user of it is expected to do
// all alarm management.
AlarmLevel currentLevel = silent;
boolean currentlyMuted = false;

int alarm(int level) {
  if (!(level > 0 && level < 6)) {
    Serial.println("Bad Level!");
    printError();
    return;
  }
  currentLevel = level;
}


void printInstructions() {
  Serial.println(F("PubInv GPAD: enter command in form CD (C is a char, D is a digit)"));
}

void printAlarmState() {
  Serial.println(currentLevel);

}
/*
This is a simple protocol:
CD\n
where C is an character, and D is a single digit.
*/
void printError() {
    Serial.println(F("bad format of command!"));
    printInstructions();
}

// This is a trivial "parser"
void interpretBuffer(char *buf,int rlen) {
  if (rlen != 2) {
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
  char D = buf[1];
  int N = D - '0';
  Serial.print(F("Command: "));
  Serial.print(C);
  Serial.println(N);
  delay(100); // WARNING: this is only for the simulation
  // Now we do a switch on C to decide what we received,
  // and convert that into an abstract command..
  switch (C) {
    case 'h': // help
      printInstructions();
      break;
    case 'a':
      alarm(N);
      printAlarmState();
      break;
    case 's':
      mute();
      break;
    case 'u':
      unmute();
      break;
    default:
      Serial.println(F("Unknown Command"));
      break;
  }
  Serial.println(F("interpret Done"));
}


// SPECIFIC TO THE GPAD HARDWARE
const int LED_PINS[5] = { A3, 5, 6, 9, 10 };
const int POWER_PIN = 13;
const int BUZZER_PIN = 8;
const int MUTE_BUTTON_PIN = A0;

const int BUZZER_LVLS[5] = { 0, 50, 100, 150, 255};

void annunciateAlarmLevel(int level) {
  digitalWrite(POWER_PIN,HIGH); // this is the silence pin!!!
  for(int i = 0; i < level; i++) {
    digitalWrite(LED_PINS[i],HIGH);
  }
  for(int i = level; i < 5; i++) {
    digitalWrite(LED_PINS[i],LOW);
  }
  if (!currentlyMuted) {
   analogWrite(BUZZER_PIN,BUZZER_LVLS[level]);
  } else {
    analogWrite(BUZZER_PIN,0);
  }
}
void mute() {
  Serial.println("Muting!");
  currentlyMuted = true;
}

void unmute() {
  Serial.println("Unmuting!");
  currentlyMuted = false;
}

// TODO: Setup SPI interrupt routines here analogous to the 
// serial port read

void setup() {
  // put your setup code here, to run once:
  // put your setup code here, to run once:
  Serial.begin(BAUD_RATE); //Start the Serial Port at 9600 baud (default)
  delay(500);
  pinMode(POWER_PIN, OUTPUT);
  for(int i = 0; i < 5; i++) {
    pinMode(LED_PINS[i], OUTPUT);
  }

  pinMode(MUTE_BUTTON_PIN,INPUT_PULLUP);

  digitalWrite(POWER_PIN,HIGH); // Let 'em know we're on.
  printInstructions();
}
void processMuteButton() {
  int mute_button = analogRead(MUTE_BUTTON_PIN);
  if (mute_button == 0) {
    if (currentlyMuted) {
      unmute();
    } else {
      mute();
    }
  }
}
void loop() {
  // Warning---this is not "debounced"!
  processMuteButton();

  // Now "light and scream"appropriately...
  annunciateAlarmLevel(currentLevel);

  // Now see if we have a serial command
    char C;
    char D;
    int rlen;
    // TODO: This code can probably hang; it needs to have 
    // timeouts added!
    if (Serial.available() > 0) {
      // read the incoming bytes:
      int rlen = Serial.readBytesUntil('\n', buf, BUFFER_SIZE); 
      // prints the received data
      Serial.print("I received: ");
      Serial.print(rlen);
      for(int i = 0; i < rlen; i++)
        Serial.print(buf[i]);
      Serial.println();
      interpretBuffer(buf,rlen);
     }

    
  delay(1000);
}
