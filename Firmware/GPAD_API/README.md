# GPAD_API
Description of the GPAD API, the Application Programming Interface.
Verion 0.1

This is the description of the API from the point of view of the firmware with in the General Purpose Alarm Device aka the GPAD 

As of 20221031, the interface is through the USB serial port only. (The SPI is not yet implemented)
Serial BAUD rate is fixed at 115200
Serial messages are terminated with a single **Line Feed**, here after LF character (aka '/n' which is ASCII 0x0A or DEC 10).
The GPAD recognizes a limited set of commands which at minimum are two characters followed by the LF
Some commands take messages by concatenating up to 4x20=80 additional ASCII characters.
The LCD is organized as four rows of twenty characters.
Commands are case-insensitive. A0 and a0 are the same.

## Command List
Optional arguments are in []
Commands fall into categories of **Alarm** and **Mute** and a "Help" message.

### Alarm Messages
* A0[message for alarm level 0]
* A1[message for alarm level 1]
* A2[message for alarm level 2]
* A3[message for alarm level 3]
* A4[message for alarm level 4]
* A5[message for alarm level 5]

In addition to Alarm messages writing text to the LCD, the illumination of the five LEDs is also managed.  A0 lights no LEDs, A1 through A5 light successively more LEDS vertically up the GPAD.

### Mute Messages
Mute messages are single character messages terminalted by LF. These messages manage muting the buzzer. There are fixed buzzer tones associated with each alarm level, A0-A5
* S
* U

### Help
* H

## Command Response and Status
After the GPAD receives a command it returns text string with a response indicating status.

## GPAD MUTE BUTTON
The GPAD has a mute button. Pressing the button will toggle the buzzer on and off.

