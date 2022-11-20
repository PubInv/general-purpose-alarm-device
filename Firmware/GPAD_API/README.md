# GPAD_API
Description of the GPAD API, the Application Programming Interface.
Version 0.1
Updated on Date: 20221104

This is the description of the API from the point of view of the firmware within the General Purpose Alarm Device, aka the GPAD.

As of Version 0.1, the interface is through the USB serial port only. (The SPI Peripheral is not yet implemented.)
Serial BAUD rate is fixed at 115200
Serial messages are terminated with a single **Line Feed**, here after LF character (aka '/n' or New Line, which is ASCII 0x0A or DEC 10).
The GPAD recognizes a limited set of commands.
Some commands are one character only.
Some commands are two characters followed by the LF.
Some commands take messages by concatenating up to _**TBD**_ (?3x20=60?) additional ASCII characters.

## Display Description
The LCD is organized as four rows of twenty characters.
The first row displays the alarm level by number and name { "OK   ","INFO.","PROB.","WARN ","CRIT.","PANIC" }
The remaining rows display the message sent by the controller with commands detailed below.

## Command List
Summary:
Commands fall into categories of **Alarm** and **Mute** and a **Help** message.
Optional arguments are in [].
Commands are case-insensitive. **A0** and **a0** are the same.

### Alarm Messages
These have the form of a letter "A" and a digit 0-5 inclusive followed optionally by text for the message.
* A0[message for alarm level 0]
* A1[message for alarm level 1]
* A2[message for alarm level 2]
* A3[message for alarm level 3]
* A4[message for alarm level 4]
* A5[message for alarm level 5]

In addition to Alarm messages writing text to the LCD, the illumination of the five LEDs is also managed.  A0 lights no LEDs, A1 through A5 light successively more LEDS vertically up the GPAD.
There are fixed buzzer tones associated with each alarm level, A0-A5
The "A0" alarm level turns off the LCD back light.  All other levels turn on the LCD back light.
Some example alarm messages:
> a0 pseudoSerialVent Testing.  All is OK.
> a0Uh, everything's under control. Situation normal.
> a5LUKE, WE'RE GONNA HAVE COMPANY!

### Mute Messages
The GPAD has a buzzer which can be silenced or Muted by the API. (The user can also press a button to manage the mute state).
Mute messages are single character messages terminated by LF.
* S
* U

The S command **Silences** or mutes the buzzer.
The U command **Unmutes** the buzzer.

### Help
* H

The **H** message is single character messages terminated by LF.
The device will return a message out the serial port with help instructions.
Screen shot of the help message.
![image](https://user-images.githubusercontent.com/5836181/200066531-264861f6-eaba-42e5-be05-d8b6f6640e94.png)


## Command Response and Status
After the GPAD receives a command, it returns text string with a response indicating status.
Example of response to the command "a0 pseudoSerialVent Testing.  All is OK."
![image](https://user-images.githubusercontent.com/5836181/200065137-465a2ade-5cc2-4c08-925f-df86810f21c1.png)


## GPAD MUTE BUTTON
The GPAD has a mute button. Pressing the button will toggle the buzzer on and off.
Text is returned out the serial port indicating the MUTE status as OFF or ON.
![image](https://user-images.githubusercontent.com/5836181/200072832-7efc77ac-50da-4c15-8be6-abd9bafb60cb.png)


# Software Organization

The files in the directory are organized to create as much modularity as possible
to make future enhancement easy. At present these are:

> alarm_api.cpp
> alarm_api.h
> gpad_serial.cpp
> gpad_serial.h
> gpad_utility.cpp
> gpad_utility.h
> robot_api.cpp
> robot_api.h

The "alarm_api" module is main application programmers interface; it is a very
high-level abstract alarm module.
The "gpad_serial" module handles serial communication of the alarm commands.
The "gpad_utility" contains mostly debugging routines needed by all other modules.
The "robot_api" is a low-level api concerning the specific API. It is means to
change more rapidly as the hardware evolves than the "alarm_api".
At the time of this writing I will shortly add an "spi" module