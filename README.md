# general-alarm-device
This repository defines a 'general purpose alarm' module, which is an electronic sub-assembly (a device with hardware and software) intended for integration into a medical devices and other applications.  The medical device will supply power and commands to the 'general purpose alarm' module.

# The Ventilator Use Case

The [Freespireco Project](https://github.com/PubInv/freespireco) is an attempt to build a modular ecosystem of cooperating respiration devices. One need that devices such as ventilators and oxygen concentrators need to have is to be able to alert someone to dangerous conditions. This can be as simple and gentle as "it is time for scheduled maintenance" to a far more dangerous "the hose connected to the patient is disconnected!"

# The Software

This project needs to define an Application Programming Interface, or API. Dr. Erich Schulz is providing some guidance on this.

# The Hardware

Although eventually we hope a firm will use our design to make a commercial product,
our initial design will use simple hobbyist hardware. My first idea is to 
to use a simple Arduino UNO programmable with either SPI or the serial port.
