# GPAD API Regression Test Plan

## Scope of this document:
Test plan for the GPAD_API.ino firmware used in the GPAD.
Testing input should be on both the serial interface, the SPI interface and the push button.
Confirmation of correct behavior may require a human to examine the DUT. Where tests can be automated even better.

## Black Box Testing
Design Black Box Testing use the product features documentation.
* Group 1, Display typical messages to the LCD
* Display all characters to the LCD
* Test all conditions of the Lights (LEDs) 
* Check speed of DUT reponse to input. Try to over run the capability both serial and SPI.
* Look for pathelogical situations like long strings or mal formed commands. Try every non printible character.
* Other, further test as...

Tests implimented as of 20221102
Tests using a terminal program on serial port input. Using RealTerminal both with direct user input and by sending files. RealTerm allows for setting intercharacter delay, end of line delay and repeate file delay. 
Endurance testing with RealTerminal. Capture of the bidirectiontal serial traffice may be possible, and if ont try TeraTerm.

### Black Box Test Results 
#### Group 1 with RealTerminal Testing  
Tests labled "RT" are with RealTerminal.  
DUT Firmware Version: **0.1**
Version of test tools: NA
| Test ID            | RT Test 1  | RT Test 2  | RT Test 3  |RT Test 4  | RT Test 5  |
| -----------        | ----------- | ----------- | ----------- |----------- | ----------- |
| Test Name-->       | **GPAD_API_TEST_1**  | **With LF_Only**  |  **Display all alarms** |**All alpha numeric** |**Long Line Test** |
| Test notes-->      | Use file GPAD_API_TEST_1.CRLF.txt  | Use file GPAD_API_TEST_3LF_Only.LF.txt   | Use file GPAD_API_TEST_3LF_Only.LF.txt   |Use file GPAD_API_TEST_ALPHANUM1.LF.txt  | Use file GPAD_API_TEST_LONGLINE.LF.txt  |
| Description and Expected Results-->|This file has CR and LF end terminations.     | Test file has help command and only Alarms with messages and only LF end terminations. | Display all alarm messages sequentialy.  | All alphan numeric, most punctuation|Alarm message with greater than 60 characters|
| Actual Results LCD-->  | The CR chracter produced a goofy graphic symbol      | This displays with no goffey characters. | A2, A4 message missing, DUT resets | As good as the LCD can do.   | Improper display. No status. Text all over line 1, 3 and 4. Line 2 blank.|
| Actual Results LEDs-->  | The LEDs lite sequentaly.  | The LEDs lite sequentaly. | The LEDs lite sequentaly. | The LEDs lite sequentaly.   | Light 1 lite. Pass|
| Actual Results Buzzer-->  | The buzzer sounded.  | The buzzer sounded. | The buzzer sounded. | The buzzer sounded.   |No sound.|
| Pass/ Fail / Other | Fail. Goofy charcter should not display       | Pass        | Fail. DUT Reset        |Pass  | Fail|
| Bug Report         | GPAD With Bad Character #107       | Pass        | GPAD_API ?Reset? During Endurance Testing With Messages #109 |  See video: https://www.youtube.com/watch?v=uIGDPubeWpw There are notes about a few character substitutions at this issue: https://github.com/PubInv/general-alarm-device/issues/120 | Issue at: https://github.com/PubInv/general-alarm-device/issues/125|  

<sub>(copy this table above in full for future verions and ammend as approprate)</sub>

#### Proccessing Testing, pseduPolyVent
Tests labled "sPV" are with the Processing program pseudoPolyVent.  
DUT Firmware Version: **0.1**
Version of test tools: TBD
| Test ID            | sPV Test 1  | sPV Test 2  | sPV Test 3  |
| -----------        | ----------- | ----------- | ----------- |
| Test Name-->       | **???**  | **???**  | foo |
| Test notes-->      | **???**  | **???**  | bar |
| Expected Results-->|The DUT will... | The DUT will... | ???       |
| Actual Results-->  | The cow jumpted over the moon. | The dish ran away with the spoon | ???       |
| Pass/ Fail / Other | Fail. Cows are not space rated | PASS they were a natural match    | ???       |

<sub>(copy this table above in full for future verions and ammend as approprate)</sub>


## White Box Testing
Design White Box Testing with the additional insight of the source code and help from the designer / coder (s).
* Exercies every state veriable in every order
* With the Processing pseudoPolyVent control more respresentative of how a hardware device might work with capture and logging of device response on the serial and eventualy SPI interface is possible.
* Other TBD

## Other
Reports from users.

## Version
This test plan is version 20221102

## License

* Firmware: GLP 3
* Hardware CERN Open Hardware License Version 2 - Strongly Reciprocal
