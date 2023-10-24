# Hardware Folders
Folders for the hardware designed as GPAD (or related such as the PolyVent_SPI_Controler)

**Outline**
1. Documentation 
2. Enclosure
3. GeneralPurposeAlarmDevicePCB
4. Manufacturing
5. PolyVent_SPI_Controller

## Documentation

[Manufacturing Documentation for Version 2 PCB](./Documentation/ManufacturingUnitTestTroubleshootingRev2.md)
Details how to assemble the Printed Wiring Assemblies as received from JLCPCB version 2 PCBs of March 2023. Includes testing and troubleshooting notes.

## Enclosure
The Version 1 enclosure is mostly designed in OPEN SCAD  
Files to fabricate an enclosure are detailed in this document: [LINK](./Enclosure/README.md)

## GeneralPurposeAlarmDevicePCB
Kicanvas live view of current schematic and PCB is found at: [./GeneralPurposeAlarmDevicePCB](./GeneralPurposeAlarmDevicePCB)  

PDF, and therefore stale, schematic for Rev 2 PCB Assemblies is: [Schematic-GeneralPurposeAlarmDevicePCB-V2.2.pdf](/Hardware/GeneralPurposeAlarmDevicePCB/PDF/Schematic-GeneralPurposeAlarmDevicePCB-V2.2.pdf)


## Manufacturing
Includes the spread sheets for Bill of Materials (BOMs) to fabricate the GeneralPurposeAlarmDevicePCB.  
See the [Manufacturing README.md](./Manufacturing) for more information on the files there.

## PolyVent_SPI_Controller
Includes KiCad schematic and PCB files for an adapter PCB to fit into PolyVent Main Controller card cage and provide an SPI (and I2C) interface to other devices. The SPI interface is for the GPAD.
KiCad Schematic, PCB and bom documentation for ordering PCBs and PWAs in found in this folder.


