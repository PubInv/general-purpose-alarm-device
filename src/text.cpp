/**************************************************************************
  This is a library for several Adafruit displays based on ST77* drivers.

  Works with the Adafruit 1.8" TFT Breakout w/SD card
    ----> http://www.adafruit.com/products/358
  The 1.8" TFT shield
    ----> https://www.adafruit.com/product/802
  The 1.44" TFT breakout
    ----> https://www.adafruit.com/product/2088
  The 1.14" TFT breakout
  ----> https://www.adafruit.com/product/4383
  The 1.3" TFT breakout
  ----> https://www.adafruit.com/product/4313
  The 1.54" TFT breakout
    ----> https://www.adafruit.com/product/3787
  The 1.69" TFT breakout
    ----> https://www.adafruit.com/product/5206
  The 2.0" TFT breakout
    ----> https://www.adafruit.com/product/4311
  as well as Adafruit raw 1.8" TFT display
    ----> http://www.adafruit.com/products/618

  Check out the links above for our tutorials and wiring diagrams.
  These displays use SPI to communicate, 4 or 5 pins are required to
  interface (RST is optional).

  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  MIT license, all text above must be included in any redistribution
 **************************************************************************/

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>
#include <text.h>

#if defined(ARDUINO_FEATHER_ESP32) // Feather Huzzah32
#define TFT_CS 14
#define TFT_RST 15
#define TFT_DC 32

#elif defined(ESP8266)
#define TFT_CS 4
#define TFT_RST 16
#define TFT_DC 5

#else
// For the breakout board, you can use any 2 or 3 pins.
// These pins will also work for the 1.8" TFT shield.
#define TFT_CS 10
#define TFT_RST 9 // Or set to -1 and connect to Arduino RESET pin
#define TFT_DC 8
#endif

// OPTION 1 (recommended) is to use the HARDWARE SPI pins, which are unique
// to each board and not reassignable. For Arduino Uno: MOSI = pin 11 and
// SCLK = pin 13. This is the fastest mode of operation and is required if
// using the breakout board's microSD card.

// For 1.44" and 1.8" TFT with ST7735 use:
// Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

// For 1.14", 1.3", 1.54", 1.69", and 2.0" TFT with ST7789:
// Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

// OPTION 2 lets you interface the display using ANY TWO or THREE PINS,
// tradeoff being that performance is not as fast as hardware SPI above.
//#define TFT_MOSI 11  // Data out
//#define TFT_SCLK 13  // Clock out

// For ST7735-based displays, we will use this call
// Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

// OR for the ST7789-based displays, we will use this call
// Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);
namespace TEXTAlarm
{
    void TEXTAl::play_TEXT_Alarm(Alarmlev allev, Adafruit_ST7789 tft, DisplayCheck text, int freq)
    {
        /*
          Checks alarm state and prints text as 
          'ALARMMM
           ALARMMMM
           ALARMMMM' 
           in three subsequent lines. The text message can be modified appropriately.
           Depending on the alarm level, the text monitor also prints 
           LEVEL 1, LEVEL 2 according to the alarm level input. 
        */
        if (text == Check::WORKING)
        {
            Serial.println("We are getting some text on the monitor");
            uint16_t time = millis();
            tft.fillScreen(ST77XX_BLACK);
            time = millis() - time;

            delay(500);

            // large block of text
            tft.fillScreen(ST77XX_BLACK);
            delay(1000);

            // tft print function!
            tftPrintTest(tft);
            tft.setTextColor(ST77XX_RED);
            tft.setTextSize(4.25);
            tft.print("LEVEL");
            tft.print(allev + 1);
            flicker(tft, freq);
        }
        else{
            tft.fillScreen(ST77XX_BLACK);
            tft.setTextSize(0);
            tft.setTextColor(ST77XX_BLACK);
        }
    }
    void TEXTAl::flicker(Adafruit_ST7789 tft, int freq)
    {
        //Blinks the text monitor for a set frequency depending on the alarm level.

        delay(freq/100);
        tft.invertDisplay(false);
        delay(freq/100);
    }

    void TEXTAl::tftPrintTest(Adafruit_ST7789 tft)
    {
        /*
          Prints the text on the monitor in different colors 
          to make it appealing as an alarm device.
        */

        tft.setTextWrap(false);
        tft.fillScreen(ST77XX_BLACK);
        tft.setCursor(0, 30);
        tft.setTextColor(ST77XX_RED);
        tft.setTextSize(3);
        tft.println("ALARRMMM");
        tft.setTextColor(ST77XX_YELLOW);
        tft.setTextSize(3.5);
        tft.println("ALARMMM");
        tft.setTextColor(ST77XX_GREEN);
        tft.setTextSize(4);
        tft.println("ALARRMMM");
        tft.setTextColor(ST77XX_BLUE);
        tft.setTextSize(4.25);
        tft.print("ALAARRM");
        
        delay(1500);
        tft.setCursor(0, 0);
    }

}
