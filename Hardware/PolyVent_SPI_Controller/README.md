# PolyVent SPI Controller Card
This project is a printed circuit assembly which fits in to the card rack of the Polyvent  
This assembly brings out an SPI (Serial Peripheral Interface) on an RJ12 connector compatible with the GPAD.  
This assembly brings also out an I2C (Inter Integrated Circuit interface) on a 4 pin JST connector similar to the GPAD.  

This is collaboration of Public Invention with the [Sustainable Progress and Equality Collective (SPEC)](https://www.specollective.org/#:~:text=The%20Sustainable%20Progress%20and%20Equality,be%20catalysts%20for%20positive%20change.)


## Schematic and PCB

<a href="SCH_PolyVent_SPI_Controller.pdf" >
Link to SCH
<img src="SCH_PolyVent_SPI_Controller.gif" width="200">
</a>

<a href="PCB_PolyVent_SPI_Controller.pdf" >Link to PCB 
<img src="PCB_PolyVent_SPI_Controller.gif" width="200"  >
</a>

<a href="PolyVent_SPI_Controller_PCBImage.png" >Link to 3D render screen capture
<img src="PCB_3D.gif" width="200"  > </a>  

<a href="PolyVent_SPI_Controller.step" >Link to 3D step file.</a>



## Theory of Operation
This PCB provides two interface methods for level shifting from the 3.3V ESP32 on the PolyVent to the 5V ATmega328 on the GPAD.
They are options achieved by populating different components in the schematic. As of 20221027 17:00 the schematic does not detail these stuffing options.

* One method of using FETs as described for example here: https://www.eeweb.com/level-shifting-techniques-in-i2c-bus-design/.  This may need some design work for selecting the pull up resistors as there are no pull ups on the GPAD interface.
* The second method is to simply connect the signals from the ESP32 output pins (SCL, COPI, nCS) directly to the ATmega328 inputs and rely on the 3.3 Volt logic high to be sufficient for the Atmega328 CMOS inputs. Full analyses is: The Atmega328 logic low input is specified at 0.3*Vcc and logic input hight is specified at 0.7*Vcc. So we have 1.5 and 3.5 per the specifications. 
![image](https://user-images.githubusercontent.com/5836181/204000965-93931e5e-dbdc-428c-9d71-96e83c09b63b.png)  
So strictly by the specification the ESP output of even the full 3.3V does not guarentee logic high on the input of the ATmega328.  
The output from the ATmega328 is resistively divided through 1K into 2K to produce 5 * 2/3 = 3.3 Volts on the CIPO signal.

There are dip siwtches for choice of five nCS lines of the PolyVent brought out to become the nCS signal. **CAUTION:** Onle one switch should be in the closed position.



## Volunteer Skills and Skills Needed
Project Lead, Product Definition, Robert L. Read, founder of Public Invention.  
Enclosure design, component procurement for rev1, project facilitator, initial board bring-up, board layout design contributor, Lawrence Kincheloe of Speccollective who is a computer scientist by training, and an electrical engineer as well as a hobby inventor by vocation. 
Mentor and coach hardware, firmware, (Forrest) Lee Erickson Physicist who pretends to be electrical engineer and firmware developer and provider of Novel and Diverse Spelling.
Volunteers needed and welcome for review of project documentation and project design.


# License

* Firmware: GLP 3
* Hardware CERN Open Hardware License Version 2 - Strongly Reciprocal


