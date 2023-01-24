# toneSweep  
An Arduino UNO sketch for GPAD to test the build in buzzer for response.
Measurements and Novel Spelling by Forrest Lee Erickson (Amused Scientist). 
Date: 20230110

**Analysis Summary**
The swept response of the piezo is easier to hear than the steady tones used in the GPAD API as of 202301 Version ?0.3?
The buzzer horn improves the response some what by perhaps 6 or more db when measuring SPL.
The buzzer horn may be improving Lee's hearing of the sweepTone by lowering the frequency of resonance some what and perhaps making more resonant.
The 4"x5.5" moving coil speaker is SIGNIFICANTLY LOUDER at over 80dB.  This is probably do to the significant response at lower frequency the speaker has.

## Setup and test description  
Firmware: toneSweep.ino 
Sweeps from a hard coded start frequency to a hard coded stop frequency in a set time.  
<img src="IDE_ScreenShot.png" > 
The cell phone was hand held about one hand span (<9") above the piezo and about the same from the moving coil speaker. The moving coil speaker has no enclosure. It is a driver setting magnet down on the work bench.
<img src="WorkBench20230110_185013.jpg" width="300">    
[Work bench big image LINK ](WorkBench20230110_185013.jpg)


## Oscilloscope Results 
Observe the response on an oscilloscope and notice there is a perturbation in the envelope of the drive voltage.
The blue signal goes low when sweep starts at 400 Hz and goes high at 4000Hz.
Test made without and with the buzzer horn.

<img src="CH1toneSweepCH2nTrigger.png" width="600">    
  
*Without horn.*   

<img src="CH1toneSweepCH2nTrigger_WithHorn.png" width="600">     

*With horn.*  

<img src="CH1toneSweepCH2nTrigger_With4inch_Speaker.png" width="600">     

*4x5.5 inch moving coil speaker.* 

**Speculative Analysis Oscilloscope Results** 
Resonance possible at about 2.6 to 2.75 KHz.  Another at 3.6 to 3.7 Hz.
This is just a guess at resonance. A better test might be to measure with a microphone but of course a microphone's response will then become a factor in the results.

## Cell Phone Sound Meter and Analyzer 
On each image the left "half" of the data is without buzzer horn and to the right is with buzzer horn. 
<img src="Screenshot_20230110-173854_Sound_Meter.jpg" width="300"> 
<img src="Screenshot_20230110_174257_Sound_Analyser.jpg" width="300">  

Additional and restarted tests with the 4x5.5 Inch moving coil speaker. 
The Sound Analyser right most ?25%? or so of the display is with the speaker.  

<img src="Screenshot_20230110-183558_Sound-Meter.jpg" width="300">  
<img src="Screenshot_20230110-183438_Sound_Analyser.jpg" width="300">  


**Speculative Analysis Sound Meter & Analyser Results**  
There is somewhat higher peaks seen on the Sound Meter with the Horn.
The Sound Analyser shows the odd harmonics are present as to be expected with the square wave drive into the piezo transducer from the Arduino Tone function.

## Notes on Instruments.
1. Oscilloscope is GWInstek GDS-1054 using Open Wave software on Windows 10 PC for waveform capture.
2. Android application: SoundAnalyser V4.2 by Droid Dev February 2017
3. Android application: Sound Meter by Abc Apps.
 
