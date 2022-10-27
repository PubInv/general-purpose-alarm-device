# PolyVent SPI Controller Card
This project is a printed circuit assembly which fits in to the card rack of the Solvent
This assembly brings out an SPI (Serial Peripheral Interface) on an RJ12 connector compatible with the GPAD.
This assembly brings out an I2C (Inter Integrated Circuit interface) on a 4 pin JST connector similar to the GPAD.

This is collaboration of Public Invention with the [Sustainable Progress and Equality Collective (SPEC)](https://www.specollective.org/#:~:text=The%20Sustainable%20Progress%20and%20Equality,be%20catalysts%20for%20positive%20change.)


## Schematic and PCB

<a href="SCH_PolyVent_SPI_Controller.gif" >
Link to SCH
<img src="SCH_PolyVent_SPI_Controller.gif" width="200">
</a>

<a href="PCB_PolyVent_SPI_Controller.gif" >Link to PCB 
<img src="PCB_PolyVent_SPI_Controller.gif" width="200"  >
</a>

<a href="PCB_3D.gif" >Link to 3D render
<img src="PCB_3D.gif" width="200"  >
</a>

# Theory of Operation
This PCB provides two interface methods for level shifting from the 3.3V ESP32 on the PolyVent to the 5V ATmega328 on the GPAD.
They are options acheived by populating different components in the schematic. As of 20221027 17:00 the schematic does not detail these stuffing options.

* One method of using FETs as described for example here: https://www.eeweb.com/level-shifting-techniques-in-i2c-bus-design/
* The second method is to simply connect the signals from the ESP32 output pins (SCL, COSI, nCS) directly to the ATmega328 inputs and rely on the 3.3 Volt logic high to be sufficient for the Atmega328. Analyses is: TBD
The output from the ATmega328 is resistivly divided through 1K into 2K to product 5 * 2/3 = 3.3 Volts on the CISO signal.

There is a resistor population choice of five different nCS lines of the PolyVent brought out to become the nCS signal. These are CS11-CS15 on the PolyVent connector.



# Volunteer Skills and Skills Needed

Project Lead, Product Definition, Robert L. Read, founder of Public Invention.

Enclosure design, component procurement for rev1, project facilitator, initial board bring-up, board layout design contributor, Lawrence Kincheloe of Speccollective who is a computer scientest by training, and an electrical engineer as well as a hobby inventor by vocation. 

???  Joe Torreggiani of Speccollective

Mentor and coach hardware, firmware, (Forrest) Lee Erickson Physicist who pretends to be electrical engineer and firmware developer and provider of Novel Spelling.


# License

* Firmware: GLP 3
* Hardware CERN Open Hardware License Version 2 - Strongly Reciprocal


