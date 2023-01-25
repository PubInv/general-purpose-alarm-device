# The GPAD_API_SPI_CONTROLLER Code

The GPAD device is designed to be used as an SPI peripheral. It can also accpets commands on the serial port, but that
is primarily for the convenience of testing.

The code in this directory is example code showing how to make a microcontroller programmed within the Arduino
act as an SPI client (controller) of a GPAD SPI server (peripheral).

The code has two very important compile-time switches implemented with the C-preprocessor. The first is
```C++
// #define USE_POLYVENT_ARCH
```
When this is defined, the SPI control lines are specifically set to those implemented by the 
[PolyVent Educational Ventilator Platform](https://www.pubinv.org/polyvent-educational-platform/)
which runs the VentOS software. Unless you are on the PolyVent team or building your own PolyVent, 
you probably want to leave this undefined.

The second is:
```C++
#define USE_LCD 1
```

If you are using a Ardunio UNO or ESP32, for example, as a controller, and are not using a second GPAD itself as 
a controller, you will want to comment out this line. This team, however, uses the GPAD hardware as both
a controller and a peripheral. Because the GPAD has and LCD screen, this allows the controller to print out
an information message. If you do not have a GPAD and run this code on a standard Arduino UNO, you will see
debugging information on the serial port at BAUD RATE 115200. 

The code as written performs a variant of a "walking ones" test; that is, it cycles through all five alarm staters.
