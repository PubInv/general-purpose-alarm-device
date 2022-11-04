# GPAD_API
Description of the GPAD API, the Application Programming Interface.
Verion 0.1
Updated on Date: 20221104

This is the description of the API from the point of view of the firmware with in the General Purpose Alarm Device aka the GPAD. 

As of 20221031, the interface is through the USB serial port only. (The SPI is not yet implemented)
Serial BAUD rate is fixed at 115200
Serial messages are terminated with a single **Line Feed**, here after LF character (aka '/n' which is ASCII 0x0A or DEC 10).
The GPAD recognizes a limited set of commands
Some commands are one character only.
Some commands are two characters followed by the LF (Line Feed) character also known as New Line.
Some commands take messages by concatenating up to _**TBD**_ (?3x20=60?) additional ASCII characters.
The LCD is organized as four rows of twenty characters.
Commands are case-insensitive. A0 and a0 are the same.

## Command List
Summary:  
Commands fall into categories of **Alarm** and **Mute** and a **Help** message.
Optional arguments are in []


### Alarm Messages
These have the from of a letter "A" and a digit 0-5 inclusive followed optionaly by text for the message.
* A0[message for alarm level 0]
* A1[message for alarm level 1]
* A2[message for alarm level 2]
* A3[message for alarm level 3]
* A4[message for alarm level 4]
* A5[message for alarm level 5]

In addition to Alarm messages writing text to the LCD, the illumination of the five LEDs is also managed.  A0 lights no LEDs, A1 through A5 light successively more LEDS vertically up the GPAD.
There are fixed buzzer tones associated with each alarm level, A0-A5
The "A0" alarm level turns off the LCD back light.  All other levels turn on the LCD back light.
An example alarm message
> a0 pseudoSerialVent Testing.  All is OK.

### Mute Messages
The GPAD has a buzzer which can be scielenced or Muted by the API. (The user can also press a button to manage the mute state).
Mute messages are single character messages terminalted by LF. 
* S
* U  

The S command **Silences** or mutes the buzzer.  
The U command **Unmutes** the buzzer.  

### Help
* H

The **H** message is single character messages terminalted by LF.   
The device will return a message out the serial port with help instructions.
Screen shot of the help message.  
![image](https://user-images.githubusercontent.com/5836181/200066531-264861f6-eaba-42e5-be05-d8b6f6640e94.png)


## Command Response and Status
After the GPAD receives a command it returns text string with a response indicating status.
Example of response to the command "a0 pseudoSerialVent Testing.  All is OK."  
![image](https://user-images.githubusercontent.com/5836181/200065137-465a2ade-5cc2-4c08-925f-df86810f21c1.png)  


## GPAD MUTE BUTTON
The GPAD has a mute button. Pressing the button will toggle the buzzer on and off.
Text is returned out the serial port indicating the MUTE status as OFF or ON.  
![image](https://user-images.githubusercontent.com/5836181/200066839-2ad4e93d-ec72-4ade-8606-ffd01521a100.png)



