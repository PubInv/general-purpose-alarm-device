#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<array>
#include<alarmtest.h>

using namespace std;
namespace AlarmWork{
    
    uint16_t timer;  //timer in ms
    uint16_t display;
    bool displayCheck = true;
    array<uint16_t,3> BuzzerFreq = {20,32,45};
    
    void AlarmSystem::setAlarmSystem(Alarmlev alarmlev){
        if (alarmlev == Alarmlev::LOW){
            BuzzerFreq.at(0);
            timer = 3500;
        }
            
        else if(alarmlev == Alarmlev::MEDIUM){
            BuzzerFreq.at(1);
            timer = 6500;
        }
        else 
        {
            BuzzerFreq.at(2);
            timer = 9500;
        }
        setSoundBuzzer(BuzzerFreq.data());
    };
    void AlarmSystem::checkBuzzerStatus (bool BuzzerCheck){
        //TEST_ASSERT_TRUE(BuzzerCheck == true);
        float sound = setSoundBuzzer(BuzzerFreq.data());
    };
    void AlarmSystem::LightDisplayLevel(uint16_t lightDisplay, bool displayCheck){
        //TEST_ASSERT_TRUE(displayCheck, TRUE);
        if (alarmlev == Alarmlev::LOW){
             lightDisplay = 32;
        }
        else if(alarmlev == Alarmlev::MEDIUM){
            lightDisplay = 47;
        }
        else{
            lightDisplay = 56;
        }
    };
    /*float AlarmSystem::setSoundBuzzer(uint16_t* BuzzerFreq){
        //Outputting a PWM signal over here which has the same frequency as the buzzer frequency.
        SoundAlarm = square(BuzzerFreq.data()); 
    };*/
    float AlarmSystem::AlarmManage(Alarmlev alarmlev, bool BuzzerCheck, AlarmMLogic alarmmlogic){
        if (alarmmlogic == AlarmMLogic::SILENCE){
            BuzzerCheck == false;
        }
        else if (alarmmlogic == AlarmMLogic::SUSPEND){
            BuzzerCheck = false;
            displayCheck = false;
        }
        else if(alarmmlogic == AlarmMLogic::REACTIVATE || alarmmlogic == AlarmMLogic::DEACTIVATE){
            displayCheck = false;
        }
        else{
            alarmlev = Alarmlev::HIGH;
        }

    };
    float AlarmSystem::AlarmTextMessage (Alarmlev alarmlev, bool BuzzerCheck){
        //Need to check for printing alarm text message.    
        
    };

}


