# GPAD API TEST 1

## Summary
This is folder contains files to test the GPAD_API through the serial port using a terminal program.
Example, the text file, GPAD_API_TEST_1.txt is sent by RealTerm to the device under test, DUT.
RealTerm is set up for a 4000 mSecond end of line delay.
RealTerm is set up for to repeat endlesly by setting the number of repeats to zero.

Screen shot showing the setup and typical serial traffic.
![ScreenShotTest1.gif](ScreenShotTest1.gif)

## Test Files:
* GPAD_API_TEST_1.txt  This file has CR and LF end terminations.
* GPAD_API_TEST_2.txt Similar to GPAD_API_TEST_1 but with messages added. This file has CR and LF end terminations.
* GPAD_API_TEST_2LFOnly.txt Similar to GPAD_API_TEST_1 but with messages added. This file has LF end terminations.
* GPAD_API_TEST_3LF_Only.txt This file has help command and only Alarms with messages and only LF end terminations.

## References
Note Lee used the very helpful program **XVI32** to create the files with the desired line terminations.
XVI32 can be downloaded from what appears to be the author here: http://www.chmaas.handshake.de/delphi/freeware/xvi32/xvi32.htm#download
Example of file in **XVI32** in action.
![XVI32Example.gif](XVI32Example.gif)

The program **RealTerm** can be downloded from: https://sourceforge.net/projects/realterm/

## License

* Firmware: GLP 3
* Hardware CERN Open Hardware License Version 2 - Strongly Reciprocal
