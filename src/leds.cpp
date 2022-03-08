#include <Arduino.h>
#include <leds.h>
#include <Wire.h>
#ifndef _BV
#define _BV(bit) (1 << (bit))
#endif
uint8_t counter = 0;
using namespace std;

namespace LEDAlarm
{
    void AlLev::play_LEDalarm(Alarmlev al, DisplayCheck disp, int blink, Adafruit_LEDBackpack matrix1)
    {
        /*
            Displays the LED brightness level according to the alarm level and 
            working condition of the LED.
        */
        if (disp == DisplayCheck::BLINK){
            Serial.println("LEDS are going to turn on");    
            // draw a diagonal row of pixels

            matrix1.displaybuffer[1] = _BV(7) | _BV(0) | _BV(1) | _BV(2) | _BV(3) | _BV(4) | _BV(5) | _BV(6) ;
            matrix1.displaybuffer[0] = _BV(7) | _BV(0) | _BV(5) | _BV(6) ;
            matrix1.displaybuffer[2] =  _BV(0) | _BV(1) | _BV(2) | _BV(3) | _BV(4) | _BV(5);
            matrix1.displaybuffer[3] =  _BV(0) | _BV(1)   | _BV(4) | _BV(5) ;
            matrix1.displaybuffer[4] =  _BV(0) | _BV(1) | _BV(4) | _BV(5) ;
            matrix1.displaybuffer[5] =  _BV(0) | _BV(1) | _BV(2) | _BV(3) | _BV(4) | _BV(5);
            matrix1.displaybuffer[6] = _BV(7) | _BV(0) | _BV(1) | _BV(2) | _BV(3) | _BV(4) | _BV(5) | _BV(6);
            matrix1.displaybuffer[7] = _BV(7) | _BV(0) | _BV(5) | _BV(6) ;
            matrix1.setBrightness((blink/4000));        
            // write the changes we just made to the display
            matrix1.blinkRate(blink/1000);
            matrix1.writeDisplay();
            delay(1000);
            
            }
        else 
            {
            for (uint8_t i = 0; i < 8; i++)
                {
                // clear the matrix
                matrix1.displaybuffer[i] = 0;
                }
            matrix1.writeDisplay();
            }
        
    }

}
