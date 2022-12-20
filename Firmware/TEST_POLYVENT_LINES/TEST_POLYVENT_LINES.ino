/* SPI_CONTROLLER
   From: https://circuitdigest.com/microcontroller-projects/arduino-spi-communication-tutorial
   Modified by Forrest Lee Erickson 20220523
   Change to Controller/Peripheral termonology
   Change variable names for start with lowercase. Constants to uper case.
   Controller Arduino Code:
   License: Dedicated to the Public Domain
   Warrenty: This program is designed to kill and render the earth uninhabitable,
   however it is not guaranteed to do so.
   20220524 Get working with the SPI_PERIPHERAL sketch.
   20220525 The SCK period is about 250nS as set up.
   20220927 Change for button to have internal pull up.  Add Resistor and LED from pins 7 to 6.
*/

//SPI CONTROLLER (ARDUINO UNO)
//SPI COMMUNICATION BETWEEN TWO ARDUINO UNOs
//CIRCUIT DIGEST

/* Hardware Notes, Controller
   SPI Line Pin in Arduino
  MOSI 11 or ICSP-4  Output
  MISO 12 or ICSP-1 Input
  SCK 13 or ICSP-3 Output
  SS 10  Output
  330 Ohm resistor and LED from pin 7 to pin 6.
  LED will be high untill the peripheral button is pressed.

*/

#include<SPI.h>                             //Library for SPI
#define LED_PIN 7                           //Add this LED + Resistor
#define LED_CATHODE 6                        //A pin to sink LED current
#define BUTTON_PIN 2                        //Button to GND, 10K Resistor to +5V.


const int fileSize = 21;
char file[fileSize] = "Lorem ipsum dolor si";

char fileName[] = "test.txt";

#define USE_POLYVENT_ARCH 1

#ifdef USE_POLYVENT_ARCH
#define GPAD_CS_IDX (11-1)

const uint8_t ESP_CS_PINS[11] =  {4, 5, 13, 14, 15, 16, 17, 25, 26, 32, 33};

const int GPAD_CS = ESP_CS_PINS[GPAD_CS_IDX];
#else

const int GPAD_CS = SS;

#endif



void local_setup(void) {
   //For SPI clock rates, see https://www.arduino.cc/reference/en/language/functions/communication/spi/setclockdivider/
  //SPI.setClockDivider(SPI_CLOCK_DIV8);    //Sets clock for SPI communication at 8 (16/8=2Mhz)
  //SPI.setClockDivider(SPI_CLOCK_DIV16);    //SPI clock at 16MHz/N (16/16=1Mhz) where N={2,4,8,16,32,64,128}
  //SPI.setClockDivider(SPI_CLOCK_DIV64);    //SPI clock at 16MHz/N (16/64=250Khz) where N={2,4,8,16,32,64,128}
  SPI.setClockDivider(SPI_CLOCK_DIV128);    //SPI clock at 16MHz/N (16/128=125Khz) where N={2,4,8,16,32,64,128}
//  pinMode(SS, OUTPUT);                    // Set nCS for output
  pinMode(MISO, INPUT);                   //Sets MISO as INPUT. Note MOSI must be set automaticaly
  SPI.begin();                            //Begins the SPI commnuication
  
  pinMode(SS, OUTPUT);                    // Set nCS for output
  digitalWrite(SS, HIGH);                 // Setting PeripheralSelect as HIGH (So controller doesnt connnect with peripheral)

//  struct configST config;
//  config.timeout = 200;

//  myTransfer.begin(SPI,config);
  delay(100);
  Serial.println(F("SETUP DONE!"));

#ifdef USE_POLYVENT_ARCH
   for (int i = 0; i < 11; i++) {
    pinMode(ESP_CS_PINS[i], OUTPUT);
    digitalWrite(ESP_CS_PINS[i], HIGH);
  }
#endif 
}
void setup (void)
{
  Serial.begin(115200);                   //Starts Serial Communication at Baud Rate 115200
  delay(500);
  Serial.println(F("Starting SPI Controller."));
 // pinMode(BUTTON_PIN, INPUT_PULLUP);               //Sets pin 2 as input
 // pinMode(LED_PIN, OUTPUT);                   //Sets pin 7 as Output

 // pinMode(LED_CATHODE, OUTPUT);               //Sets pin 6 as Output
 // digitalWrite(LED_CATHODE, LOW);             //Sets pin 6 to sink LED current
  local_setup();
 
}// end setup()

int cnt = 0;
unsigned long timer;
int toggle = 0;
void loop(void)
{
//  AlarmEvent event;
//  event.lvl = cnt++ % 6;
//  strcpy(event.msg,"Be True; You need noBe True; You need noBe True; You need noBe True; You need no");
  
//  alarm_event(event,Serial);
//  Serial.println(F("Done with Datum Send!"));
//  delay(3000);

//  Serial.println("SENDING SPI");
  unsigned long m = millis();
  if (m > (5000 + timer)) {
    timer = m;
    const int USE_TOGGLE = 0;

    if (USE_TOGGLE) {
      if (toggle == 0) {
        Serial.println(F("Writing LOW"));
        Serial.println(GPAD_CS);
        digitalWrite(GPAD_CS, LOW);
      } else {
        Serial.println(F("Writing HIGH"));
        Serial.println(GPAD_CS);
        digitalWrite(GPAD_CS, HIGH);
        
      }
      toggle = (toggle + 1) % 2;

    } else {
         Serial.println(F("Writing SPI LOW"));
        Serial.println(GPAD_CS);
        digitalWrite(GPAD_CS, LOW);
        
        // Send a test byte
        uint8_t v = 5;
        SPI.transfer(v);
        
         Serial.println(F("Done"));
        Serial.println(GPAD_CS);
        digitalWrite(GPAD_CS, HIGH);
    }
  }
}
