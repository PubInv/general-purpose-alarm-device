# OU Capstone 2023 Wifi and Battery Group
	Maxwell Walsh
	Prince Oburoni-Ayeh
	Alex Adkisson
	Trinity Famuliner

**Outline**
1. Overview
2. Implementation
3. Concerns and Moving Foward

## Overview
The goal for our project was to implement an internal battery and Wifi capabilities into the GPAD
in order to make the device wireless capable.

## Implementation
The battery implementation uses a 3.7V Lithium ion battery connected to a MCP73833 charging circuit that when provided with
5V from the GPAD, charges the battery. The output of the battery is then passed through a low Vf shottky diode to prevent back
current from the 5V rail when it is plugged in. Once the GPAD is removed from external power the battery outputs is voltage to
power the device at its native lower voltage to reduce conversion inefficiencies. Additionally, a MOSFET was added to control
the power to the LCD so that it can be switched off between alarms on battery mode to conserve power.

The Wifi is implemented via the onboard wifi module on the esp32. The conversion of the device to use and esp32 was handled by
the other OU 2023 Capstone team.

## Concerns and Moving Foward
One concern arises from the idea to switch off the LCD on battery mode and that is that currently, there is no system in place
for the esp-32 to be able to detect that the device is on battery mode, a potential method could be for the esp-32 to read an
analog input from a voltage divider that should decrease when on the lower voltage battery power.

Another concern is that of the device running properly at the lower voltage. Several tests were conducted, and while not ideal,
the LCD would operate at the lower voltage. Another concern is that of the LED resistors values being set for a 5V source meaning
that the LEDs won't operate the same on the battery voltage. The idea of using a boost converter on the output of the battery to
boost it to 5V was discussed but dropped due to inefficiency from the conversion. However it still might be a viable option
if the current mode of operation proves to be too unstable. If this is done, one concern is that of the battery trying to charge
itself off of the boosted voltage which would lead to a bad loop of sucking current.

One other concern is that of battery shut off. The current implementation has nothing to deal with when the battery voltage gets
too low, so as it is now, certain parts of the device might turn off at different rates as the battery decreases in voltage.
Going forward it could be beneficial to find a battery charging IC that has a function built in the shut off the battery when
the voltage gets too low.