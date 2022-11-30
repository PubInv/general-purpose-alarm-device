# Instructions for gpad_ST_cli.py and the GPAD

Use at the command line to command by the serial port the GPAD USB/UART interface

## Requirements
You must have Python 3 installed.
You must know the COM port on which the GPAD is enumerated. Windows example "COM5".

## Example Usage Windows
Open a CMD (Command shell)
Type "python pgad_ST_cli.py  -s com5" (if the COM port was COM5)
The program will respond with a blank line. Press Enter
The program will respond with
> Input
> 
> sending : b'\n'
Type a GPAD command such as "a5RUN IN CIRCLES SCREAM AND SHOUT!"
Type other GPAD commands

Type "q" to exit

Screen shot
> ![image](https://user-images.githubusercontent.com/5836181/204800915-3a8631df-fc7a-4c27-a4f8-ab45b4d662ba.png)


## Example Usage Linux
Open a terminal 
TBD
