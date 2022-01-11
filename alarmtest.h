#include <stdio.h>
#include <string.h>
#include<vector>
#include<array>
#include<iostream>
using namespace std;

namespace AlarmWork{
    enum Alarmlev {
        LOW, 
        MEDIUM, 
        HIGH
    };
    enum AlarmMLogic{
        SUSPEND,
        SILENCE,
        HIGHLEVEL,
        REACTIVATE,
        DEACTIVATE
    };
    class AlarmSystem {
        private:
            Alarmlev alarmlev;
            bool BuzzerCheck;
            uint16_t LightDisplayLevel;
            array<uint16_t,3> BuzzerFreq;
            
        public: 
            void setAlarmSystem(Alarmlev alarmlev);
            void checkBuzzerStatus (bool BuzzerCheck);
            void LightDisplayLevel (uint16_t lightDisplay, bool DisplayCheck);
            float setSoundBuzzer(uint16_t* BuzzerFreq);
            float AlarmManage(Alarmlev alarmlev, bool BuzzerCheck,AlarmMLogic alarmmlogic);
            float AlarmTextMessage(Alarmlev alarmlev, bool BuzzerCheck);

    };

}