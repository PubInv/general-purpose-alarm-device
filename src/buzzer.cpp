#include <Arduino.h>
#include <buzzer.h>
#include <alarmtest.h>

#include "pitches.h"
using namespace std;
using namespace AlarmWork;
namespace BuzzerAlarm
{
  int melody[] = {

      NOTE_F6, NOTE_G3, NOTE_B3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};

  // note durations: 4 = quarter note, 8 = eighth note, etc.:
  int noteDurations[] = {

      4, 8, 8, 4, 4, 4, 4, 4};
  void BuzAlm::play_buzzeralarm(AlarmWork::Alarmlev j, AlarmWork::Check buz, int dur)
  {
    if (buz == Check::WORKING)
    {
      /*
        Plays the buzzer for a few seconds according to every note. 
        For each alarm level the notes are higher. 

        Every note is played for around 1/4th of a second. 

        If the buzzer is working, the buzzer plays the notes according to the alarm level
        and the duration of the note. 
      */
      Serial.println("Buzzer is going on");
      Alarmlev lev = j;
      int c;
      int b[4] = {23, 32, 56, 76};
      int i = 0;
      int timer = 1000/4.5;
      int takebrk = timer*1.120;
      while (i <= 3){
        c = b[i] + int(lev*40);
        tone(7,c,timer);
        delay(takebrk);
        noTone(7);
        i+= 1;
      }

      /*for (int thisNote = 0; thisNote < 8; thisNote++)
      {

        // to calculate the note duration, take one second divided by the note type.

        // e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.

        int noteDuration = 1000 / noteDurations[thisNote];

        tone(8, melody[thisNote], noteDuration);

        // to distinguish the notes, set a minimum time between them.

        // the note's duration + 30% seems to work well:

        int pauseBetweenNotes = noteDuration * 1.120;

        delay(pauseBetweenNotes);

        // stop the tone playing:

        noTone(8);
      }*/
    }
    else
    {
      noTone(8);
    }
  }
}
