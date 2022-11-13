#include "gpad_utility.h"


void printError(Stream &serialport) {
    serialport.println(F("bad format of command!"));
    printInstructions(serialport);
}
void printInstructions(Stream &serialport) {
  serialport.println(F("PubInv GPAD: enter command in form CDa (C is a char, D is a digit)"));
}
