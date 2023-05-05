# Hardware Folders
Folders for the hardware designed as GPAD (or related such as the PolyVent_SPI_Controler)

**Outline**
1. Documentation 
2. Enclosure
3. GeneralPurposeAlarmDevicePCB
4. Manufacturing
5. PolyVent_SPI_Controller

## Documentation
Documentation for the fabrication of the Version 1 GPAD.
Photos of units under assembly and a document [ManufacturingUnitTestTroubleshooting.md](./Documentation/ManufacturingUnitTestTroubleshooting.md)

## Enclosure
The Version 1 enclosure is mostly designed in OPEN SCAD  
Files to fabricate an enclosure are detailed in this document: [LINK](./Enclosure/README.md)

## GeneralPurposeAlarmDevicePCB
Includes the KiCad files for schematic and PCBs.
A PDF of the Rev 2 schematic is: [Schematic-GeneralPurposeAlarmDevicePCB-V1.2pdf.pdf](/Hardware/GeneralPurposeAlarmDevicePCB/PDF/Schematic-GeneralPurposeAlarmDevicePCB-V1.2pdf.pdf)  

Here follows a link that will open a web page views of the schematic pages and PCB files.
[View KiCad files with on line viewer](https://github.com/PubInv/general-alarm-device/tree/main/Hardware/GeneralPurposeAlarmDevicePCB)  

## Manufacturing
Includes the spread sheets for Bill of Materials (BOMs) to fabricate the GeneralPurposeAlarmDevicePCB.  
Note if using the Version #1 PCB which has front silk screen text including "Prototype#1, 20220726", there are reworks required for the D7 and D10 lines and for the /RTS to RESET through a relocated C106 which are captured in a schematic of revision V1.2. 
> There is a tag to these files. I tagged it V1.2 which is what I am thinking of as the version of the schematic reflecting Version 1 PCB but with reworks.  
The schematic reflecting the reworks to bring the 15 GPADs build in September 2022 to revision V1.2 is here: [Schematic-GeneralPurposeAlarmDevicePCB-V120220810.pd](Schematic-GeneralPurposeAlarmDevicePCB-V120220810.pd)

## PolyVent_SPI_Controller
Includes KiCad schematic and PCB files for an adapter PCB to fit into PolyVent Main Controller card cage and provide an SPI (and I2C) interface to other devices. The SPI interface is for the GPAD.
KiCad Schematic, PCB and bom documentation for ordering PCBs and PWAs in found in this folder.


