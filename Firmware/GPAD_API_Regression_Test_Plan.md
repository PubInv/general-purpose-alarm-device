# GPAD API Regression Test Plan

## Scope of this document:
Test plan for the GPAD_API.ino firmware used in the GPAD.
Testing input should be on both the serial interface, the SPI interface and the push button.
Confirmation of correct behavior may require a human to examine the DUT. Where tests can be automated even better.

## Black Box Testing
Design Black Box Testing use the product features documentation.
* Display typical messages
* Display all characters
* Check speed of DUT reponse to input. Try to over run the capability
* Look for pathelogical situations
Further test as...
Tests implimented as of 20221102
Tests using a terminal program on serial port input. Using RealTerminal both with direct user input and by sending files. RealTerm allows for setting intercharacter delay, end of line delay and repeate file delay. 
Endurance testing with RealTerminal. Capture of the bidirectiontal serial traffice may be possible, and if ont try TeraTerm.

## White Box Testing
Design White Box Testing with the additional insight of the source code and help from the designer / coder (s).
* Exercies every state veriable in every order
* With the Processing pseudoPolyVent control more respresentative of how a hardware device might work with capture and logging of device response on the serial and eventualy SPI interface is possible.
* Other TBD

## Other

## Version
This test plan is version 20221102
