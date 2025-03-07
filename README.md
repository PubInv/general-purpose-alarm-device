# General Purpose Alarm Device v2.0
We often acronymize this as  "GPAD" (prounced gee-pad).

DOI: [https://zenodo.org/records/10065096](https://zenodo.org/records/10065096)

## Abstract 
The General Purpose Alarm Device (GPAD) shines lights and makes loud noises to draw attention to a problem. It has a programmable 80 character display to provide textual info. A mute button toggles the sound on and off. Fundamentally, it is designed to act as a peripheral to a controlling computer or microcontroller. The controller may communicate over a USB (COM) connection or through a 5V SPI connection via an RJ12 cable. The GPAD is intended to be as general as possible, so that it can be used as an alarm for many engineering, scientific, and hobby machines or instruments. The device's original goal was to provide medical alarm capability to the PolyVent [5]open-source mechanical medical ventilator. The GPAD supports 5 alarm levels above “silent” of increasing urgency in terms of light, rhythm, and frequency. It is based on the Arduino Uno Atmega328 design and may similarly become extensible through headers and shields. It includes a printed wiring assembly, firmware for the GPAD peripheral, a simple documented API, and a 3D printable enclosure. The repo includes instructions for using a second GPAD as a controller.

The GPAD does not detect the conditions that need to be alarmed. It is a peripheral to a controlling host device, probably another microcontroller.
The controlling host will assert status through the GPAD to an end user.

## Demonstration Video
A demonstration of one use of the GPAD can be [seen here](https://youtu.be/F5cf5-Cmwu0).

# The Colaborative Open Development

Development of the GPAD is in collaboration with the [Sustainable Progress and Equality Collective
(SPEC)](https://www.specollective.org/#:~:text=The%20Sustainable%20Progress%20and%20Equality,be%20catalysts%20for%20positive%20change.) and other individual volunteers.

The GPAD is Certified Open Source Hardware by OSHWA. Our OSHWA UID is [US002352](https://certification.oshwa.org/us002352.html).

![GPAD_OSHWA](https://github.com/PubInv/general-purpose-alarm-device/assets/5296671/29422091-91a7-4646-a39d-9bfc92c0540c)

GPAD in an Enclosure of Summer 2022
![https://user-images.githubusercontent.com/5296671/203407648-e5b4894c-6909-4530-9af4-f5937bfeb0b8.JPG](https://user-images.githubusercontent.com/5296671/203407648-e5b4894c-6909-4530-9af4-f5937bfeb0b8.JPG)

KiCad Simulated GPAD Printed Circuit Assembly (Version 2)
![image](https://github.com/PubInv/general-purpose-alarm-device/assets/5836181/b7f9a16a-94d4-4ccd-a86f-526d37d9a09f)
**Top View**
![image](https://github.com/PubInv/general-purpose-alarm-device/assets/5836181/ea4155c0-4b1c-4f06-83ff-e278fcaf673b)
**Bottom View.** 

The top view image shows some Artuino UNO connectors peeking out, but on the bottom view the connectors are not actually used.  The GPAD was designed so that it MIGHT become a shield to an UNO, but it can stand alone.


# Versions History
During the summer of 2022, Version 1 of the GPAD PCB was designed and several units were fabricated.
Some of these units were used as electrical engineering senior capstone projects of students at the
University of Oklahoma, located in Nornam Oklahoma, during the spring semester.
Two groups participated: one group developed a wireless interface and battery features, and
the other groups developed a voice playback feature.
These features are on the ESP32 branch, which as of August 2023, is not yet integrated.

## Version 2 PCB Features
As of March 2023, we have developed and built a version 2 PCB.  Fifteen printed wiring assemblies and five enclosures were fabricated largely by JLCPCB.
Some PCB components not available through JLCPCB were assembled by hand in Maryville, TN.
Details of the assembly and test procedure can be found through links in the README.md at:  [https://github.com/PubInv/general-purpose-alarm-device/tree/main/Hardware](https://github.com/PubInv/general-purpose-alarm-device/tree/main/Hardware)
**FIXES in Version 2**
Changes were made in version 2 to fix a few reworks to version 1 PCBs, which involved cutting traces and soldering wires.
The most noticable change was properly connecting the USB-UART chip to the micocontroller nRESET line
so that the devices can program themselves without the user having to press the reset button.
Another change was making the audio output a switch rather than a push-pull, which allows for an internally driven buzzer and greater volume.
We built buzzers with Digi-key part numbers 433-WST-1210T-ND and 102-CMI-1295-0585T-ND. Both are rated at 85 dB and 10cm.
The Rev2 can also drive the **VERY **loud Floyd Bell Inc buzzer 2339-TXC-86-515-Q-ND, rated at 103dB. However, we have not designed an enclosure for the "off board" mounting requirements of this device.
An additional Rev 2 feature is a silk screen on all of the "Arduino UNO" connectors, which look like pins for easy signal indentification.

## GPAD V2 Build Information
Below are files we used to build the V2 assemblies. The PCB with some SMT Assembly was from JCLPCB in China. Additional parts were ordered and hand soldered in the USA.

[Linkes to the schematic and PCB design found here](./Hardware/GeneralPurposeAlarmDevicePCB)
[Links to the exact Gerber files GerbersV120220804.zip](./Hardware/Manufacturing/GerbersV120220804.zip)
[Information on the V2 build of April 2023](/Hardware/Manufacturing)
[Manufacturing and Unit Test Documentation, PCB Version 2.0, 20230228](./Hardware/Documentation/ManufacturingUnitTestTroubleshootingRev2.md)
Details on how to assemble the Printed Wiring Assemblies as received from the JLCPCB version 2 PCBs of March 2023. Includes testing and troubleshooting notes.

## GPAD V1 Repository Tag
Tag to last commit before removing information of Version 1 PCB and PCBA
https://github.com/PubInv/general-purpose-alarm-device/releases/tag/BeforeRemovingV1Files

# Example Use Case, The Ventilator

The [Freespireco Project](https://github.com/PubInv/freespireco) is an attempt to build a
modular ecosystem of cooperating respiration devices.
Devices such as ventilators and oxygen concentrators need to have the ability to alert someone to dangerous conditions.
These alerts can be as simple and gentle as, "It is time for scheduled maintenance,"
to the far more agressive, "The hose connected to the patient is disconnected!"
The purpose of the alarm is to get the attention of nurses or doctors who can fix the problem.

See the PolyVent project on Gitlabs at: [https://gitlab.com/polyvent](https://gitlab.com/polyvent)
See the PolyVent controller at: [https://gitlab.com/polyvent/polyvent_control_module](https://gitlab.com/polyvent/polyvent_control_module)

# The Abstract Application Programmers Interface

GPAD offers a simple API for commanding the device to alarm.
We can imagine a system that supports five levels of alarm severity.
Additionally, an alarm condition normally has a short
message associated with it, such as "Hose disconnect", which
might be displayed on a small screen.

The initial version of this API is extraordinarily simple:
alarm at a level between zero and five, where zero means no alarm.
However, it is clear this API will have to evolve over time.
Issues such as when one alarm level supersedes another, when it is
acceptable to silence an alarm and for how long, etc., quickly complicate this function.

We hope that by clearly defining this version of API, we can make an evolving device of great
utility for a wide variety of purposes.

# Stand-alone or Sub-assembly

Our fully finished design includes a printed wiring assembly and an enclosure.
We freely provide all open source KiCad schematic printed circuit assembly files, so
that users can fabricate just the PCB while using an enclosure of their own design.
The enclosure is designed in the free open source program SCAD,
and we provide these files as well.
Users could fabricate this enclosure as is, or
develop a modified enclosure with their own features from the files provided.

# The Arduino UNO-Like Platform

The implementation is Arduino UNO-like.
We provide a USB interface to an ATmega328 controller for Arduino IDE compatibility, which supports a typical Arduino serial port interface for development and debugging.
Additionally, although the enclosure is not designed for them, we also provide an UNO footprint for shields. There are holes on the PCB where users can solder female Dupont headers and add UNO shields for feature enhancement and evaluation.
The enclosure design is open source so that interested persons
can add these applications according to their requirements.

# How is the alarm signal received?

The SPI Peripherial is a wired RJ12(6P6C) data connection from a host in an SPI controller, and the GPAD is an SPI Peripheral.  A data cable is wired pin 1 to pin 1 on the RJ12(6P6C) connectors. CAUTION: Telephone cables wire pin 1 to pin 6 and are not compatible.


# Summer 2023 Project Status

### Firmware
Demonstration of SPI controller and Peripheral for single byte transmission.

### Hardware
* PCB designed for a predominantly surface mount production. We used JLCPCB. Some had assembly parts not available through JLCPCB.
* An enclosure for the electronics which is designed for easy mounting (for example, with flanges for zip ties.)
* RJ12 Data Cable connection for signal (and optional power) between host and GPAD.
* Light alert by five, 5 mm white LEDs driven at about 20 mA.
* Acoustic alert by 5V buzzer, 85 dB at 10 cm. On board Piezo self-excited buzzer, or through a 0.1" two pin header for off board buzzer (103 dB).
* Text display with back lit, 20x4 character LCD.
* Single User Button labeled "MUTE" on enclosure.
* Recessed reset button.
* Power on status LED.
* USB port for Firmware development and low power operation.
* An I2C output for controller of devices TBD. Connection by locking JST connector: S04B-XASK-1(LF)(SN).
* Power from wall supply on barrel jack 2. 1mm at 9-12V <= 1000mA (or from host controlling device at 5V or 12V on the SPI interface).

### A Simulation with WokWi
Our project development benefited greatly from Wokwi.  Visit: [https://wokwi.com/](https://wokwi.com/)
In parallel with schematic capture, PCB design, and fabrication,
we have written both the diagram and two sketches that simulate our hardware in the "simulation" directory.
One of them,
which Rob wrote on Saturday, August 13th, implements [this rudimentary api](https://github.com/PubInv/general-alarm-device/tree/main/simulation/robSimulatinSat13), without supporting messages.
The other shows the use of the LCD.
These should be integrated together to create the initial firmware for the project.
Meanwhile, we can simulate the device successfully in WokWi.
While the Version 1 PCBs and PCAs were on order, Lee wrote and simulated factory test software on WokWi.
See project at: https://wokwi.com/projects/345960281987351124
![Factory Test Simulation on Wokwi](https://user-images.githubusercontent.com/5836181/206513709-647a1ac0-0031-4747-92a4-0e64b3a6de9e.png)

Factory Test Simulation files can be found at: [./simulation/FactoryTest](./simulation/FactoryTest)
Although we eventually sent a Rev 1 GPAD to Oluseyi 'Seyi' Adeniyi (@NULLbodyHERE) made enhancements
to our factory test without even having hardware (we later sent him one), which he used to enhance
the sonic and light signalling.

# Possible Evolution Stages of the Project
Ideas from the cap stone projects:
1. Wifi interface and batter power
2. Audio voice playback for messages.

In each of these phases, we imagine extensions of the API.

# Volunteer Skills (and Skills Needed)

## Current Volunteers:

Project Lead, Product Definition:  Robert L. Read (@RobertLRead), founder of Public Invention.

Enclosure design, component procurement for rev1, project facilitator, initial board bring-up, board layout design contributor: Lawrence Kincheloe (@LokeMetaSmith) of Speccollective who is a computer scientist by training, and an electrical engineer as well as a hobby inventor by vocation.

Mentor and coach hardware, firmware: (Forrest) Lee Erickson @ForrestErickson, Physicist who pretends to be an electrical engineer, with experience in firmware development, Design for Manufacture, Design for Test and developer of Novel and Diverse Spelling.

Factory Test and API Firmware Contributor: Oluseyi 'Seyi' Adeniyi @NULLbodyHERE, Software Engineer, committed to pursuing diverse creative endeavors.

## Needed Volunteers

We need volunteer:
1. Arduino engineers who can both code and make very simple circuits.
2. Schematic capture and PCB layout designers.  We are using KICAD.
3. Mechanical engineers who can design sturdy enclosures that keep the system bright and loud.
4. Embedded firmware engineers who can design an effective, evolving API and the transport bindings that they require.
5. GUI experts who can address issues such as how to effectively alarm and silence device.
6. Marketers who can promote and evangelize the project.
7. A possible project manager who can organize volunteers and keep them enthused and motivated to move forward.

# The Potential for a Product

Like everything done by Public Invention, this is a fully open project that is
released under fully open hardware and software licenses.
However, unlike many of our projects, which are very "researchy", this project could
become a scalable product pretty easily.
One can imagine it being sold at Sparkfun, Adafruit, or DigiKey, if we do a good job.
Because it could be used for a wide variety of purposes by makers and could be sold with an enclosure at a price of perhaps <=$100USD
As an embedded sub assembly, the printed wiring assembly must be low cost with a material price of < $30USD

Potential uses as a product (by hobbyists) include:
1. Alarming a cat door, bird, or squirrel at feeder
2. Alarming when a visual signal, such as an animal moving in a game camera, is detected
3. Announcement of life-threatening conditions in medical devices
4. Overheating conditions in almost any device
...but the reader can probably imagine a great many more.

Public Invention does not wish to become a manufacturer; but we will impartially
support anyone who wants to take these designs and manufacture them, so long as they abide by the licenses.

# Modular Software Architecture

This is intended to be a long-term project that will evolve and potentially have many volunteers.
The basic software architecture is captured in this diagram:
![GPAD Architecture (3)](https://github.com/PubInv/general-alarm-device/assets/5296671/7f6ec16f-2bee-4acb-a10e-cb6991504d04)


# Our Simple API (Implemented!)

The simplest API is:
```
enum AlarmLevel { silent, informational, problem, warning, critical, panic };
int Alarm(AlarmLevel al);
```

The simplest binding for this, which could be used with SPI or a serial port, would simply be the character A followed by the character 0, 1, 2, 3, 4, or 5.
To test the alarm system of the serial port, you could simply type "A3" into the Arduino IDE serial monitor and send this to the GPAD, which you would expect to set off a moderate noise and flashing light.

A slight improvement on this is to specify a message. We have decided that messages should have 80 character, 32 character, and 16 character
versions, and the hardware device will do its best job rendering them in with available hardware:
```
enum AlarmLevel { silent, informational, problem, warning, critical, panic };
int Alarm(AlarmLevel al);
int Alarm80(AlarmLevel al,char* msg);
int Alarm32(AlarmLevel al,char* msg);
int Alarm16(AlarmLevel al,char* msg);
```
Additionally, it would be nice to have a way to interrogate the current alarm level:
```
AlarmLevel getAlarm(AlarmLevel al);
boolean isMuted();
```

## The Abstract API
The Abstract API is meant to work independent of specific hardware on
the GPAD. That is, it should be useful for hardware built by other teams
with significantly different decisions.

In this API, the message strings support only the most limited
sort of formatting: a linefeed character represents a line break.
Nonetheless, if linefeed characters are used, this will break lines
and of course limit the number of ACTUAL characters
that can be rendered, rather than the 60 that we can render if no
line breaks are used.

## The Hardware API

The Hardware API gives a caller complete access to all of the GPAD
hardware. For example, they could address each LED separately.
This is a lower priority. This API is not intended to be used by
medical devices because it is fragile with respect to improvements in
the hardware. Nonetheless, its availability makes the GPAD more useful
for a wider variety of purposes. For example, someone could program a
simple game with the GPAD.

## Separate transport protocols

In practice, the device needs three ways of invoking the API:
1. Through a human-typable string at the serial port,
1. Through a remote procedure call via the serial port, and
1. Through the SPI interface.

It is our intention to keep all of these mechanisms distinct from the
two APIs. There might even be additional transport protocols in the future,
such as a library that uses I2C ("I-squared C").

# Project Glossary
Some terms we use and how we have defined issues for Github.
[Glossary.md](Glossary.md)

# Building the Firmware

The firmware can be built with the standard Arduino IDE.  (Using 1.8.19 as of 20221208)
It requires libraries:
1. Wire.h
1. LiquidCrystal_I2C.h
1. DailyStruggleButton.h  (Installed with library manager and found at: https://github.com/cygig/DailyStruggleButton)

# Credits
The GPAD team was enabled by, and wishes to thank, the developers and maintainees of:
**GitHub** the project management features, issues, and project board were always useful when we used them.
**KiCAD** for the tools of schematic capture and PCB design
**OpenSCAD** for the tools in which the enclosure was designed.
**FreeCAD** for additional design of the hanging feature on the enclosure
**Wokwi** for the simulation tools for hardware and firmware.
Also, the inventors and developers of the **Arduino** ecology of tools and hardware, who have sparked so much good for so many.
**"The Ultimate Box Maker"** from http://heartygfx.blogspot.com/2016/01/the-ultimate-box-maker.html

# License

* [Firmware: Affero GPL 3.0](https://www.gnu.org/licenses/agpl-3.0.en.html#license-text)
* [CERN Open Hardware Licence Version 2 - Strongly Reciprocal](https://ohwr.org/cern_ohl_s_v2.txt)
