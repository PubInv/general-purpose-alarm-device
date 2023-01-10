/* GPAD_Alarm_API_SPI.h
  GPAD_Alarm_API_SPI.h - header file to implement an Arduino SPI
  interface the GPAD abastract alarm interface.

  Copyright (C) 2022 Robert Read

  This program includes free software: you can redistribute it and/or modify
  it under the terms of the GNU Affero General Public License as
  published by the Free Software Foundation, either version 3 of the
  License, or (at your option) any later version.

  See the GNU Affero General Public License for more details.
  You should have received a copy of the GNU Affero General Public License
  along with this program.  If not, see <https://www.gnu.org/licenses/>.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

*/

#include <arduino.h>
#include "GPAD_Alarm_API_SPI.h"
#include <assert.h>
#include<SPI.h>

#define DEBUG_GPAD_API_SPI 1

extern int GPAD_CS;

// extern SPITransfer myTransfer;
int alarm_event(AlarmEvent& event,Stream &serialport) {

  if (DEBUG_GPAD_API_SPI > 0) {
    serialport.println(F("send lvl, msg"));
    serialport.print(event.lvl);
  //  serialport.println(event.msg);
  }
  uint8_t v = event.lvl;
  digitalWrite(GPAD_CS, LOW);
  // WARNING...This is test code to just send one byte.
  SPI.transfer(v);
  // now we want to write 128 bytes
  for(int i = 0; i < MAX_MSG_LEN; i++) {
    SPI.transfer(event.msg[i]);
  }
  digitalWrite(GPAD_CS, HIGH);
}
int alarm(AlarmLevel level,char *str,Stream &serialport) {
  AlarmEvent event;
  event.lvl = level;
//  assert(MAX_PACKET_SIZE >= sizeof(AlarmEvent));
  strncpy(event.msg,str,MAX_MSG_LEN);
  alarm_event(event,serialport);
}
