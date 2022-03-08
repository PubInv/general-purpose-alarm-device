#ifndef ALARMTEST_H
#define ALARMTEST_H

#include <Arduino.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>

using namespace std;
/*
    Displays the alarm levels, alarm management logics, alarm checks, 
    and alarm text monitor display checks.

*/
namespace AlarmWork{
    enum Alarmlev {
        LEVEL1, 
        LEVEL2, 
        LEVEL3,
        LEVEL4,
        LEVEL5
    };
    enum AlarmMLogic{
        SUSPEND,
        SILENCE,
        HIGHLEVEL,
        REACTIVATE,
        DEACTIVATE
    };
    enum Check {
        WORKING,
        BLANK1,
        MALFUNCTION
    };

    enum DisplayCheck {
        BLINK,
        BLANK,
        DULL
    };


    class AlarmSystem {
        private:
            Alarmlev alarmlev;
            Check buz;
            DisplayCheck dispcheck;
            AlarmMLogic alarmmlogic;

        public: 
            void SoundTimerBuzzer(Alarmlev alarmlev, Check buz);
            void LightDisplayLevel (Alarmlev alarmlev, DisplayCheck dispcheck, Adafruit_LEDBackpack matrix1);
            void AlarmManage(Alarmlev alarmlev, Check buz,AlarmMLogic alarmmlogic, DisplayCheck disp,Adafruit_LEDBackpack matrix1, Adafruit_ST7789 tft );
            void AlarmTextMessage(Alarmlev alarmlev, DisplayCheck text, Adafruit_ST7789 tft);

    };

}
#endif