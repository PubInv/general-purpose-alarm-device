#include <Arduino.h>
#include <alarmtest.h>
#include <Wire.h>
#include <leds.h>
#include <buzzer.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>
#include <text.h>

#if defined(ARDUINO_FEATHER_ESP32) // Feather Huzzah32
  #define TFT_CS         14
  #define TFT_RST        15
  #define TFT_DC         32

#elif defined(ESP8266)
  #define TFT_CS         4
  #define TFT_RST        16                                            
  #define TFT_DC         5

#else
  // For the breakout board, you can use any 2 or 3 pins.
  // These pins will also work for the 1.8" TFT shield.
  #define TFT_CS        10
  #define TFT_RST        9 // Or set to -1 and connect to Arduino RESET pin
  #define TFT_DC         8
#endif

#ifndef _BV
#define _BV(bit) (1 << (bit))
#endif
Adafruit_LEDBackpack matrix1 = Adafruit_LEDBackpack();
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);
using namespace AlarmWork;

AlarmWork::AlarmSystem al;
AlarmWork::Alarmlev alarmlev;
AlarmWork::Check buz = WORKING;
AlarmWork::DisplayCheck disp = BLINK;
AlarmWork::AlarmMLogic alm;
String readString;
char c;
String e;

void calling_alarm_level(char c){
    if (c == '1')
      alarmlev = AlarmWork::Alarmlev::LEVEL1;
    else if(c == '2')
      alarmlev = AlarmWork::Alarmlev::LEVEL2;
    else if(c == '3')
      alarmlev = AlarmWork::Alarmlev::LEVEL3;
    else if(c == '4')
      alarmlev = AlarmWork::Alarmlev::LEVEL4;
    else if(c == '5')
      alarmlev = AlarmWork::Alarmlev::LEVEL5;
    else  
      Serial.println("Only 5 alarm levels have been defined");
}

void loop_check( char c) {
 
  /*
    There is some function for directly converting from string to enum.
    I just need to find that. Removes the need of multiple if statements. 
  */  
  if (c ==  'S'){
    alm = AlarmMLogic::SUSPEND;
    Serial.println("The LEDs and Buzzer are going to be turned off");
    buz = Check::BLANK1;
    disp = DisplayCheck::BLANK;
  }
    
  else if(c == 'I'){
    alm = AlarmMLogic::SILENCE;
    Serial.println("The Buzzer is going to be turned off");
    buz = Check::BLANK1;
  }
  else if(c == 'R'){
    alm = AlarmMLogic::REACTIVATE;
    Serial.println("The LEDs and text are going to be turned off for some time");
    disp = DisplayCheck::BLANK;
  }
    
  else if(c == 'H'){
    alm = AlarmMLogic::HIGHLEVEL;
  }
  else if (c == 'D'){
    alm = AlarmMLogic::DEACTIVATE;
    Serial.println("The LEDs and text are going to be turned off for some time");
    disp = DisplayCheck::BLANK;
  }  
  else 
    Serial.println ("Invalid alarm management");
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //Serial.println("HT16K33 test");
  matrix1.begin(0x70); // pass in the address
  tft.init(240, 240);           // Init ST7789 240x240

}

void loop() {
  // put your main code here, to run repeatedly:


  /*
    Takes in the alarm management logic as serial input and appropriately 
    switches the state of the buzzer, LED and the display.

    Keeps the buzzer, LED and text monitor at the highest level when the serial port reads 'H'.
  */
    if (Serial.available()){
        while (Serial.available()) {
    /*
      Pseudo Code:' S is for SUSPEND'
                  ' I is for SILENCE'
                  ' R is for REACTIVATE'
                  ' H is for HIGHLEVEL '
                  ' D is for DEACTIVATE '
    */
          readString = Serial.readStringUntil('\n');
          readString.toUpperCase();
          Serial.println(readString);
          if (readString.length() >= 1){
            bool a = isDigit(readString.charAt(1));
            bool b = isAlpha(readString.charAt(0));
            if (readString.length() == 2){
              delay(1);
              if(b == 1){
                loop_check(readString.charAt(0));
                if (a == 1)
                  calling_alarm_level(readString.charAt(1));
              }    
              //Does not return ASCII. 
              if (a == 0 || b == 0)
                Serial.println( "Invalid alarm check called");
            }
            else if ( b == 1 && readString.charAt(0) == 'H'){
              loop_check(readString.charAt(0));
              alarmlev = LEVEL5;
              Serial.println("Alarm set at level 5");
            }
            else 
              Serial.println("Invalid alarm call");
          }
        }
      al.AlarmManage(alarmlev,buz,alm,disp, matrix1, tft);
    }
}