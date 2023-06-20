# LCD Troubleshooting
Ideas for troubleshooting the LCD on the GPAD. These notes were made when only version 1 PCB marked Prototype#1 20220726 existed.

## FIRST THING 
Maybe it is a user error. Check that the contrast potentiometer has not been changed. 
The "Vo" voltage at the LCD should be about 2.7 Volts with respect to ground.  

**Screen shot showing the net (PCB tracd) with the contrast voltage Vo.**
![image](https://user-images.githubusercontent.com/5836181/217345582-eb220354-b6e4-40ee-a83b-4dc1a8f60a64.png)  
If that does not fix it, then it is time for more elaborate troubleshooting.

## Capture The Failure In An Issue
If you have a failed or suspected failed display of characters or back light on the GPAD LCD please make an issue describing the failure. See Issue #196 for an example of how to capture information about the LCD failure.


## Testing With **Factory Test** Firmware
Check for the factory test firmware (https://github.com/PubInv/general-alarm-device/blob/main/Firmware/GPAD_Factory_Test/GPAD_Factory_Test.ino

Load the firmware into the DUT (Device Under Test)
Open the Arduino IDE serial monitor at 115200 baud.

The factory test firmware should report success finding the LCD on the assigned address (For Version 1 assemblies that address is 0x38)
Screen show showing normal test for LCD on I2C address
![image](https://user-images.githubusercontent.com/5836181/217339329-16000ecd-7ad5-4a63-8d00-08f2f09a9aa1.png)


Here is a screen show where the I2C communication was blocked by holding the SCL line to ground at J105 simulating a hardware failure on SCL.
![image](https://user-images.githubusercontent.com/5836181/217340353-d2d97ac5-b810-4b65-899c-aaf4b7c95386.png)

Note the Factory test firmware (Version 1.30) does not return a message saying it found 0x38 and it does not go on to the rest of the test.
The same failure and behavior of the firmware occurs if SDA is shorted to ground.


If the short is cleared then the factory test firmware continues the normal bootup.


## Testing With Multimeter
The Version Prototype#1 20220726 PCB has an incorrect footprint on U301 making soldering difficult and perhaps prone to failure. 
Use a multimeter to test from the U301 pins right at the package out to traces so that you are measuring through the solder connections to each pin.
Note that many pins go to the 16 pins inline connecting to the LCD. Other pins go to the SCL and SDA lines which are easy to access on the Arduino UNO like shield connector at the pins near U301.  
Pins 1, 2 and 3 are set high or low with resistors and when power is applied these pins should still measure at ground or very close. This is for the GPAD set for LCD at address 0x38 all three should be low. 

**Schematic of the connections at U301.**
![image](https://user-images.githubusercontent.com/5836181/217344870-7c4580b1-2ba2-4cce-bc52-343cc7d0e45c.png)


**Screen shot of U301 for traces for Version Prototype#1 20220726 PCB**
![image](https://user-images.githubusercontent.com/5836181/217344272-ec83a132-cda9-44c5-8112-1d045fb252ac.png)

Version 2 PCB will fix the footprint to wider. Here are the traces on the proposed Version 2 PCB
**Screen shot of the U301 traces for Version 2 PCB.**
![image](https://user-images.githubusercontent.com/5836181/217342029-6e326023-da23-47bc-adda-d1e7f7c62780.png)

## Other Failures.
The back light should light by default. Remove all power (all connections) to the DUT.  Press and hold the reset button and apply power while continuing to hold the reset button.  The back light should come on.
If not trouble shoot the circuit around Q301.  If the uController is held in reset there is no command sent to U301 and so its pins are high impedance and R311 will pull the gate of Q301 high turnning it on. When on, Q301 drain will go to low voltage which will turn on the back light.

![image](https://user-images.githubusercontent.com/5836181/217346811-8631a985-5019-420d-ab63-5b0d7ffe971c.png)


## Record Results
When you find and clear a problem make sure to document the problem found and the fix on the issue for the device serial number.





