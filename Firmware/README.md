# Firmware Folder

## These folders contain files as follows:

* __GPAD_API__ is the firmware which goes into the GPAD microcontroller.
* __GPAD_API_TEST__ is a test file and instructions for usering Realrerm to be an endurance test of the GPAD serial port interface. It endlessly sends a simple set of commands to the GPAD which are in a simple text file.
* __GPAD_Factory_Test__ is .ino file to be loaded into the GPAD for factory testing and or troubleshooting. Was developed to test Version 1 PCBs and was developed on Wokwi. (Was fun to do!)
* __SPI_Controller_And_Peripherial__... is a ?link? to an external github repository for some SPI communications proof of concept files 
* pseudoSerialVent is a simulated ventelator made in the Proccessing IDE with which to test the GPAD when loaded with formware GPAD_API

## Regression Test Documentation. 
* __GPAD_API_Regression_Test_Plan.md__ is an over all test plan, which describes how to use some of the folder and the files inside to reqression test the GPAD_API https://github.com/PubInv/general-alarm-device/blob/main/Firmware/GPAD_API_Regression_Test_Plan.md
* The many test folder may containe specific instructions with in their own README.md.
