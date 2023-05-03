#include "dfplayer.h"
#include <DFRobotDFPlayerMini.h>

DFRobotDFPlayerMini myDFPlayer;

const char *SoundFileNames[] = { "A.wav","B.wav","C.wav","D.wav","E.wav","F.wav" };//audio files to output based on level
const int portbits[] = {2,26,25,14,15};
//const char *AlarmNames[] = { "OK   ","INFO.","PROB.","WARN ","CRIT.","PANIC" };
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

  //if the fileNumber matches the alarm level, play the track. 
    
      myDFPlayer.play((int)currentLevel + 1);
  
      
}




void muting(){
  myDFPlayer.stop();
}