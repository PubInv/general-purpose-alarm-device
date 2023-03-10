#include "dfplayer.h"
#include <DFRobotDFPlayerMini.h>
DFRobotDFPlayerMini myDFPlayer;
const char *SoundFileNames[] = { "A.wav","B.wav","C.wav","D.wav","E.wav","F.wav" };//audio files to output based on level

void dfPlayer_setup(){

    Serial2.begin(9600);

    if (!myDFPlayer.begin(Serial2)) {
        Serial.println("Unable to begin");
        Serial.println("1. Please recheck the connection!");
        Serial.println("2. Please insert the SD Card!");
        while(true);
    }

    // Set serial communication time out 500ms
    myDFPlayer.setTimeOut(500);

    // Set volume value (0~30)
    myDFPlayer.volume(30);

    // ----Set different EQ
    myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);

    // ----Set device we use SD as default----
    myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);

    // ----Mp3 Play Testing ----
   // myDFPlayer.randomAll();
    
    
}


void playMessage1(AlarmLevel currentLevel){
  myDFPlayer.previous();
  Serial.println(SoundFileNames[currentLevel]);
}