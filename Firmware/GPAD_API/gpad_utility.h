/* gpad_utility.h
  Header files for low-level utility functions needed by every module (presumably) in the GPAD system

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

#ifndef GPAD_UTILITY
#define GPAD_UTILITY 1
#include <Stream.h>


#define PROG_NAME "******GPAD_API******"     //Descriptive name of this software, 20 characters.

#define VERSION 0.07             //Version of this software

void printError(Stream *serialport);
void printInstructions(Stream *serialport);
void printAlarmState(Stream *serialport);
#endif
