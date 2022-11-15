/* SPI_CONTROLLER
   From: https://circuitdigest.com/microcontroller-projects/arduino-spi-communication-tutorial
   Modified by Forrest Lee Erickson 20220523
   Change to Controller/Peripheral termonology
   Change variable names for start with lowercase. Constants to uper case.
   Controller Arduino Code:
   License: Dedicated to the Public Domain
   Warrenty: This program is designed to kill and render the earth uninhabitable,
   however it is not guaranteed to do so.
   20220524 Get working with the SPI_PERIPHERAL sketch.
   20220525 The SCK period is about 250nS as set up.
   20220927 Change for button to have internal pull up.  Add Resistor and LED from pins 7 to 6.
*/

//SPI CONTROLLER (ARDUINO UNO)
//SPI COMMUNICATION BETWEEN TWO ARDUINO UNOs
//CIRCUIT DIGEST

/* Hardware Notes, Controller
   SPI Line Pin in Arduino
  MOSI 11 or ICSP-4  Output
  MISO 12 or ICSP-1 Input
  SCK 13 or ICSP-3 Output
  SS 10  Output
  330 Ohm resistor and LED from pin 7 to pin 6. 
  LED will be high untill the peripheral button is pressed.
  
*/

#include<SPI.h>                             //Library for SPI 
#define LED_PIN 7                           //Add this LED + Resistor
#define LED_CATHODE 6                        //A pin to sink LED current
#define BUTTON_PIN 2                        //Button to GND, 10K Resistor to +5V.


void setup (void)
{
  Serial.begin(115200);                   //Starts Serial Communication at Baud Rate 115200
  delay(500);
  Serial.println("Starting SPI Controller.");
  pinMode(BUTTON_PIN, INPUT_PULLUP);               //Sets pin 2 as input
  pinMode(LED_PIN, OUTPUT);                   //Sets pin 7 as Output

  pinMode(LED_CATHODE, OUTPUT);               //Sets pin 6 as Output
  digitalWrite(LED_CATHODE, LOW);             //Sets pin 6 to sink LED current

  //For SPI clock rates, see https://www.arduino.cc/reference/en/language/functions/communication/spi/setclockdivider/
  //SPI.setClockDivider(SPI_CLOCK_DIV8);    //Sets clock for SPI communication at 8 (16/8=2Mhz)
  //SPI.setClockDivider(SPI_CLOCK_DIV16);    //SPI clock at 16MHz/N (16/16=1Mhz) where N={2,4,8,16,32,64,128}
  //SPI.setClockDivider(SPI_CLOCK_DIV64);    //SPI clock at 16MHz/N (16/64=250Khz) where N={2,4,8,16,32,64,128}
  SPI.setClockDivider(SPI_CLOCK_DIV128);    //SPI clock at 16MHz/N (16/128=125Khz) where N={2,4,8,16,32,64,128}
  pinMode(SS, OUTPUT);                    // Set nCS for output
  pinMode(MISO, INPUT);                   //Sets MISO as INPUT. Note MOSI must be set automaticaly
  SPI.begin();                            //Begins the SPI commnuication

  digitalWrite(SS, HIGH);                 // Setting PeripheralSelect as HIGH (So controller doesnt connnect with peripheral)
  delay(100);
}// end setup()

void loop(void)
{
  //Local variables
  byte controllerSend, controlleReceive;

  controllerSend = digitalRead(BUTTON_PIN);
  Serial.print("SPI Controler: Button Status: ");
  Serial.print(controllerSend);

  digitalWrite(SS, LOW);                  //Starts communication with Peripheral connected to controller
  controlleReceive = SPI.transfer(controllerSend); //Send the controllersend value to peripheral also receives value from peripheral
  digitalWrite(SS, HIGH);                  //End communication with Peripheral connected to controller

  Serial.print(", Peripherial: ");
  Serial.println(controlleReceive);

  //  Serial.print("Peripherial LED: ");
  if (controlleReceive == 1)                  //Logic for setting the LED output depending upon value received from peripheral
  {
    digitalWrite(LED_PIN, HIGH);             //Sets pin 7 HIGH
    //  Serial.println(" ON");
  }
  else
  {
    digitalWrite(LED_PIN, LOW);              //Sets pin 7 LOW
    //Serial.println(" OFF");
  }

  delay(100);
}// end loop()
