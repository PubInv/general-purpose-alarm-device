# Introduction: ExampleR4VoltageRead


    This program exists to demonstrate using the GPAD from a simple
  Arudion R4 via the SPI interface.

  It reads a voltage from an analog input pin, and assumes that
  as the voltage increases, the situation is becoming more dangerous
  and requires more human attention. This is embodied by a simple
  potentiometer, which can be turned by hand to demostrate the GPAD.

  This code is very similar to the GPAD_API_SPI_CONTROLLER code.
  That code, however, is used by this project to test a GPAD by
  using a GPAD itself as a controller. Since most users are not
  going to have two GPADs, showing how to use one from a simple,
  cheap, widely avaialabe micrcontroller, such as an Arduino R4.

  Note: This Arduion project copies some utility files into this
  directory. These are:
1.   GPAD_ALARM_API_SPI.cpp
1.    GPAD_ALARM_API_SPI.h
1.    alarm_api.h
  This is a code duplcation which is bad form; these should probably
  be made into a separate repo so that these can included as a
  separate libary. This is issue #263 in our repo,
  [https://github.com/PubInv/general-purpose-alarm-device/issues/263](https://github.com/PubInv/general-purpose-alarm-device/issues/263)

# How it Works

This is roughly the simplest use of the GPAD that we can imagine.
This prgram is designed to work with a simple rotary potentiometer (10kohm)
(called a "pot").

Turning the pot with your hand changes the voltage.
The voltage is read on pin A0 of an Arduino R4.
We want to demonstrate running the GPAD through all of its alarm
levels, so we break the voltage range into levels.
We read the voltage level, and send an associated alarm level
to the GPAD. We add the voltage to the message sent as well,
to demonstrate the value of the built in LCD.