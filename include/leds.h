#ifndef LEDS_H
#define LEDS_H

#include <Arduino.h>
#include <alarmtest.h>
using namespace AlarmWork;

namespace LEDAlarm
{
    /*
        The LED file containing the light display frequency function. 
    */
    class AlLev: public AlarmSystem{
        
        public:    
            void play_LEDalarm(AlarmWork::Alarmlev al, AlarmWork::DisplayCheck disp, int blink, Adafruit_LEDBackpack matrix1);
    };

};

#endif