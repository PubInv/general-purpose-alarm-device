# general-alarm-device
This General-Alarm-Device repository defines a 'general purpose alarm' module, which is an electronic sub-assembly (a device with hardware and firmware) intended for integration into a medical device and other applications.  The medical device will supply power and issue commands to the module.

# Example Use Case, The Ventilator

The [Freespireco Project](https://github.com/PubInv/freespireco) is an attempt to build a modular ecosystem of cooperating respiration devices. One need that devices such as ventilators and oxygen concentrators need to have is to be able to alert someone to dangerous conditions. This can be as simple and gentle as "it is time for scheduled maintenance" to a far more dangerous "the hose connected to the patient is disconnected!"

# The Firmware

Embedded firmware will be developed for the device.
In addition to firmware that runs in a microcontroller to realize the device, this project will define an Application Programming Interface, or API. The API defines commands the medical device can use to control the General-Alarm-Device.
Resource: Dr. Erich Schulz is providing some guidance on this.

# The Hardware

A custom Printed Circuit Board,or PCB will be designed to realize this device.
The PCB will be designed for third party manufacture (such as but not limited to JLCPCB) for both PCB fabrication and Printed Wiring Assembly or PWA.
The development strategy will be to use off the shelf hobbyist hardware to make a proof of concept and platform(s) for firm ware development in parallel with schematic capture and PCB design.

The electrical interface from the medical device to the general-alarm-device shall include, +5V at no more than TBD mA, Ground, 4 wire SPI (nCS, SCK, MOSI, MISO) Mounting features and hardware will be defined.

The end goal is to develop, test, and document the general-alarm-device so that a third party could manufacturer it as an open source GPL3 commercial product.
