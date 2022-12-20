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

#include "GPAD_Alarm_API_SPI.h"
#include <assert.h>

#define DEBUG_GPAD_API_SPI 1

extern SPITransfer myTransfer;
int alarm_event(AlarmEvent& event,Stream &serialport) {



 // myTransfer.sendDatum(event);
  if (DEBUG_GPAD_API_SPI > 0) {
    serialport.println(F("send lvl, msg"));
    serialport.print(event.lvl);
  //  serialport.println(event.msg);
  }
  uint8_t v = event.lvl;
  digitalWrite(SS, LOW);
  // WARNING...This is test code to just send one byte.
  SPI.transfer(v);
  digitalWrite(SS, HIGH);
}
int alarm(AlarmLevel level,char *str,Stream &serialport) {
  AlarmEvent event;
  event.lvl = level;
//  assert(MAX_PACKET_SIZE >= sizeof(AlarmEvent));
 // strncpy(event.msg,str,MAX_MSG_LEN);
  alarm_event(event,serialport);
}



void send_file(SPITransfer& myTransfer,int fileSize,char *fileName, char *file) {
  myTransfer.sendDatum(fileName);
  if (DEBUG_GPAD_API_SPI > 0) {
    Serial.print(F("Filename:"));
    Serial.println(fileName);
  }
  uint16_t numPackets = fileSize / (MAX_PACKET_SIZE - 2); // Reserve two bytes for current file index

  if (fileSize % MAX_PACKET_SIZE) // Add an extra transmission if needed
    numPackets++;

  for (uint16_t i=0; i<numPackets; i++) // Send all data within the file across multiple packets
  {
    uint16_t fileIndex = i * MAX_PACKET_SIZE; // Determine the current file index
    uint8_t dataLen = MAX_PACKET_SIZE - 2;

    if ((fileIndex + (MAX_PACKET_SIZE - 2)) > fileSize) // Determine data length for the last packet if file length is not an exact multiple of MAX_PACKET_SIZE-2
      dataLen = fileSize - fileIndex;

    uint8_t sendSize = myTransfer.txObj(fileIndex); // Stuff the current file index
    sendSize = myTransfer.txObj(file[fileIndex], sendSize, dataLen); // Stuff the current file data

    myTransfer.sendData(sendSize, 1); // Send the current file index and data
    // Pretty unsure about this timing!
    delay(500);
  }
  if (DEBUG_GPAD_API_SPI > 0) {
    Serial.println(F("Done with File Send!"));
  }
}
