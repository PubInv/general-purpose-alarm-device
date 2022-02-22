
#include<alarmtest.h>
#include <buzzer.h>
#include <Arduino.h>
#include <leds.h>
#include <text.h>

using namespace std;
using namespace BuzzerAlarm;
using namespace LEDAlarm;
using namespace TEXTAlarm;

namespace AlarmWork{
    
    uint16_t timer;  //timer in ms
    uint16_t display;
    DisplayCheck displayCheck = DisplayCheck::BLINK;
    int BuzzerFreq[] = {3000,4200,7500,5000,8000,10000};
    int DispFreq[] = {4000, 8000, 16000, 24000, 30000};
    
    BuzzerAlarm::BuzAlm b;
    LEDAlarm::AlLev alm;
    TEXTAlarm::TEXTAl txt;
    void AlarmSystem::SoundTimerBuzzer(Alarmlev alarmlev, Check buz){
        int dur = 0;
        if (buz == AlarmWork::Check::WORKING || buz == AlarmWork::Check::BLANK1){
            dur = BuzzerFreq[int(alarmlev)];
            b.play_buzzeralarm(alarmlev,buz, dur);
            
        }    
        else
            Serial.println("Buzzer Not Working");
    }

    void AlarmSystem::LightDisplayLevel( Alarmlev alarmlev, DisplayCheck displayCheck, Adafruit_LEDBackpack matrix1){
        int blinkfreq = 0;
        if (displayCheck == BLINK || displayCheck == DisplayCheck::BLANK){
            blinkfreq = DispFreq[int(alarmlev)];
            
            alm.play_LEDalarm(alarmlev, displayCheck,blinkfreq, matrix1);
        }
        if (displayCheck == DisplayCheck::DULL)
            Serial.println("There is a problem with the LEDs");
    }
        
    
    void AlarmSystem::AlarmTextMessage (Alarmlev alarmlev, DisplayCheck textcheck, Adafruit_ST7789 tft){
        //Need to check for printing alarm text message.    
        int textfreq = 0;
        if(textcheck == BLINK || textcheck == BLANK){
            textfreq = DispFreq[int(alarmlev)];
            txt.play_TEXT_Alarm( alarmlev, tft, textcheck, textfreq);
        }
        if (textcheck == Check::MALFUNCTION) 
            Serial.println("There is some problem with the TextMonitor");
    };

    void AlarmSystem::AlarmManage(Alarmlev alarmlev, Check buz, AlarmMLogic alarmmlogic, DisplayCheck disp, Adafruit_LEDBackpack matrix1, Adafruit_ST7789 tft){
        if (alarmmlogic == AlarmMLogic::SILENCE){
            buz = Check::BLANK1;
            disp = DisplayCheck::BLINK;
        }
        else if (alarmmlogic == AlarmMLogic::SUSPEND){
            buz = Check::BLANK1;
            disp = DisplayCheck::BLANK;
        }
        else if(alarmmlogic == AlarmMLogic::DEACTIVATE){
            disp = DisplayCheck::BLANK;
            buz = Check::BLANK1;
        }
        else if(alarmmlogic == AlarmMLogic::REACTIVATE){
            disp = DisplayCheck::BLINK;
            buz = Check::WORKING;
        }
        else{
            disp = DisplayCheck::BLINK;
            buz = Check::WORKING;
            alarmlev = Alarmlev::LEVEL5;
        }
        //Serial.println(alarmlev);
        //Serial.println(disp);
        LightDisplayLevel(alarmlev, disp, matrix1);
        SoundTimerBuzzer(alarmlev, buz);
        AlarmTextMessage ( alarmlev, disp, tft);
    };
    

}


