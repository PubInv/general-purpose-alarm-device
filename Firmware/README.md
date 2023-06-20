# Firmware Folder

## These folders contain files as follows:

* __GPAD_API__ is the firmware which goes into the GPAD microcontroller.  The GPAD running this firmware is a Peripheral.  This firmware was developed in the Arduino IED.
* **GPAD_API_SPI_CONTROLLER** is the firmware which goes into an ESP32 or UNO to be a Controller to a GPAD. This firmware was developed in the Arduino IED.
* __GPAD_API_TEST__ is a test file and instructions for using RealTerm to be an endurance test of the GPAD serial port interface. It endlessly sends a simple set of commands to the GPAD which are in a simple text file.
* __GPAD_Factory_Test__ is .ino file to be loaded into the GPAD for factory testing and or troubleshooting. Was developed to test Version 1 PCBs and was developed on Wokwi. (Was fun to do!)
* __SPI_Controller_And_Peripherial__... is a ?link? to an external GitHub repository for some SPI communications proof of concept files 
* **Python_Serial**  is a program to facilitate testing from a command line.
* **pseudoSerialVent** is a simulated ventilator made in the Processing IDE with which to test the GPAD when loaded with firmware GPAD_API
* **toneSweep** a simple standalone program (Arduino sketch) developed for evaluation of piezo buzzers and speakers on the GPAD Peripherial. 

## Regression Test Documentation. 
* __GPAD_API_Regression_Test_Plan.md__ is an overall test plan, which describes how to use some of the folder and the files inside to regression test the GPAD_API https://github.com/PubInv/general-alarm-device/blob/main/Firmware/GPAD_API_Regression_Test_Plan.md
* The many test folder may contain specific instructions within their own README.md.

