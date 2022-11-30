# Notes on Troubshooting SN00005 GPAD

* Board type is Prototype#1 
* DUT is powered by an external supply.


## Board SN5 gives error verifying upload, even though upload works.... #127
This issue is found at: #127

On Lee's Window's 10 machine to get avrdude to run I had to navigate to the folder path with the exicutible in it it:
C:\Program Files (x86)\Arduino\hardware\tools\avr\bin>
Then I could run "avrdude" and get help and begin to experiment.

The AVRdude command from the error report.
avrdude -CC:\Program Files (x86)\Arduino\hardware\tools\avr/etc/avrdude.conf -v -patmega328p -carduino -PCOM15 -b57600 -D -Uflash:w:C:\Users\Admin\AppData\Local\Temp\arduino_build_502233/GPAD_API.ino.hex:i

This command with the "-U" options of "w" means to write a file.

Lets try to change to verify only.
avrdude -CC:\Program Files (x86)\Arduino\hardware\tools\avr/etc/avrdude.conf -v -patmega328p -carduino -PCOM15 -b57600 -D -Uflash:v:C:\Users\Admin\AppData\Local\Temp\arduino_build_502233/GPAD_API.ino.hex:i
This syntax produced an error.


This syntax worked. 
"avrdude -C../etc/avrdude.conf -v -patmega328p -carduino -PCOM15 -b57600 -D -Uflash:v:C:\Users\Admin\AppData\Local\Temp\arduino_build_502233/GPAD_API.ino.hex:i"

"avrdude -C../etc/avrdude.conf -v -patmega328p -carduino -PCOM16 -b57600 -D -Uflash:v:C:\Users\Admin\AppData\Local\Temp\arduino_build_502233/GPAD_API.ino.hex:i"

This produced the following output:

> avrdude: Version 6.3-20190619
         Copyright (c) 2000-2005 Brian Dean, http://www.bdmicro.com/
         Copyright (c) 2007-2014 Joerg Wunsch

         System wide configuration file is "../etc/avrdude.conf"

         Using Port                    : COM16
         Using Programmer              : arduino
         Overriding Baud Rate          : 57600
         AVR Part                      : ATmega328P
         Chip Erase delay              : 9000 us
         PAGEL                         : PD7
         BS2                           : PC2
         RESET disposition             : dedicated
         RETRY pulse                   : SCK
         serial program mode           : yes
         parallel program mode         : yes
         Timeout                       : 200
         StabDelay                     : 100
         CmdexeDelay                   : 25
         SyncLoops                     : 32
         ByteDelay                     : 0
         PollIndex                     : 3
         PollValue                     : 0x53
         Memory Detail                 :

                                  Block Poll               Page                       Polled
           Memory Type Mode Delay Size  Indx Paged  Size   Size #Pages MinW  MaxW   ReadBack
           ----------- ---- ----- ----- ---- ------ ------ ---- ------ ----- ----- ---------
           eeprom        65    20     4    0 no       1024    4      0  3600  3600 0xff 0xff
           flash         65     6   128    0 yes     32768  128    256  4500  4500 0xff 0xff
           lfuse          0     0     0    0 no          1    0      0  4500  4500 0x00 0x00
           hfuse          0     0     0    0 no          1    0      0  4500  4500 0x00 0x00
           efuse          0     0     0    0 no          1    0      0  4500  4500 0x00 0x00
           lock           0     0     0    0 no          1    0      0  4500  4500 0x00 0x00
           calibration    0     0     0    0 no          1    0      0     0     0 0x00 0x00
           signature      0     0     0    0 no          3    0      0     0     0 0x00 0x00

         Programmer Type : Arduino
         Description     : Arduino
         Hardware Version: 2
         Firmware Version: 1.16
         Vtarget         : 0.0 V
         Varef           : 0.0 V
         Oscillator      : Off
         SCK period      : 0.1 us
         
         avrdude: AVR device initialized and ready to accept instructions
         Reading | ################################################## | 100% 0.01s
         avrdude: Device signature = 0x1e950f (probably m328p)
         avrdude: safemode: lfuse reads as 0
         avrdude: safemode: hfuse reads as 0
         avrdude: safemode: efuse reads as 0
         avrdude: verifying flash memory against C:\Users\Admin\AppData\Local\Temp\arduino_build_502233/GPAD_API.ino.hex:
         avrdude: load data flash data from input file C:\Users\Admin\AppData\Local\Temp\arduino_build_502233/GPAD_API.ino.hex:
         avrdude: input file C:\Users\Admin\AppData\Local\Temp\arduino_build_502233/GPAD_API.ino.hex contains 9500 bytes
         avrdude: reading on-chip flash data:
         
         Reading | ################################################## | 100% 2.49s
         
         avrdude: verifying ...
         avrdude: 9500 bytes of flash verified
         avrdude: safemode: lfuse reads as 0
         avrdude: safemode: hfuse reads as 0
         avrdude: safemode: efuse reads as 0
         avrdude: safemode: Fuses OK (E:00, H:00, L:00)
         
         avrdude done.  Thank you.
         
         C:\Program Files (x86)\Arduino\hardware\tools\avr\bin>

So testing SN5 with the command: avrdude -C../etc/avrdude.conf -v -patmega328p -carduino -PCOM15 -b57600 -D -Uflash:v:C:\Users\Admin\AppData\Local\Temp\arduino_build_502233/GPAD_API.ino.hex:i from the approprate folder might be of interest.

## Reference
https://www.ladyada.net/learn/avr/avrdude.html

