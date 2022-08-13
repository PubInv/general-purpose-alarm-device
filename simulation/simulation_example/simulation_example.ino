// simple project using Arduino UNO and 20x4 character display to display smooth gauge, 
// adapted from upir, 2022
// youtube channel: https://www.youtube.com/upir_upir

// Links related to this project:
// Arduino UNO - https://s.click.aliexpress.com/e/_AXDw1h
// Arduino breadboard prototyping shield - https://s.click.aliexpress.com/e/_ApbCwx
// 16x2 displays with IIC - https://s.click.aliexpress.com/e/_9Hl3JV
// 16x2 display with RGB backlight - https://s.click.aliexpress.com/e/_9wgpeb
// original sketch from YWROBOT - https://wokwi.com/arduino/libraries/LiquidCrystal_I2C/HelloWorld
// character creator - https://tusindfryd.github.io/screenduino/
// another character creator - https://maxpromer.github.io/LCD-Character-Creator/
// sprintf explanation - https://www.programmingelectronics.com/sprintf-arduino/
// custom characters simplest project - https://wokwi.com/projects/294395602645549578
// Arduino I2C scanner - https://playground.arduino.cc/Main/I2cScanner/
// 16x2 available characters - https://docs.wokwi.com/parts/wokwi-lcd1602#font
// Bitwise Operators in GIFs - https://blog.wokwi.com/bitwise-operators-in-gifs/
// Bitwise operators Arduino documentation - https://www.arduino.cc/reference/en/language/structure/bitwise-operators/bitshiftleft/



#include <LiquidCrystal_I2C.h>     // if you don´t have I2C version of the display, use LiquidCrystal.h library instead
const int SCL_LED_PIN = 13;        //
const int LIGHT0_PIN = A3;
const int LIGHT1_PIN = 5;
const int LIGHT2_PIN = 6;
const int LIGHT3_PIN = 9;
const int LIGHT4_PIN = 10;
const int ledCount = 5;    // the number of LEDs in the bar graph
int ledPins[] = {
  LIGHT0_PIN, LIGHT1_PIN, LIGHT2_PIN, LIGHT3_PIN, LIGHT4_PIN
};   // an array of pin numbers to which LEDs are attached

const int SPEAKER_PIN = A0;

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
//LiquidCrystal_I2C lcd(0x3f,16,2);    // set the LCD address to 0x3f for a 16 chars and 2 line display
// if you don´t know the I2C address of the display, use I2C scanner first (https://playground.arduino.cc/Main/I2cScanner/)

// define custom characters/arrays - every character is 5x8 "pixels"
byte gauge_empty[8] =  {B11111, B00000, B00000, B00000, B00000, B00000, B00000, B11111};    // empty middle piece
byte gauge_fill_1[8] = {B11111, B10000, B10000, B10000, B10000, B10000, B10000, B11111};    // filled gauge - 1 column
byte gauge_fill_2[8] = {B11111, B11000, B11000, B11000, B11000, B11000, B11000, B11111};    // filled gauge - 2 columns
byte gauge_fill_3[8] = {B11111, B11100, B11100, B11100, B11100, B11100, B11100, B11111};    // filled gauge - 3 columns
byte gauge_fill_4[8] = {B11111, B11110, B11110, B11110, B11110, B11110, B11110, B11111};    // filled gauge - 4 columns
byte gauge_fill_5[8] = {B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111};    // filled gauge - 5 columns
byte gauge_left[8] =   {B11111, B10000, B10000, B10000, B10000, B10000, B10000, B11111};    // left part of gauge - empty
byte gauge_right[8] =  {B11111, B00001, B00001, B00001, B00001, B00001, B00001, B11111};    // right part of gauge - empty

byte gauge_mask_left[8] = {B01111, B11111, B11111, B11111, B11111, B11111, B11111, B01111};  // mask for rounded corners for leftmost character
byte gauge_mask_right[8] = {B11110, B11111, B11111, B11111, B11111, B11111, B11111, B11110}; // mask for rounded corners for rightmost character

byte warning_icon[8] = {B00100, B00100, B01110, B01010, B11011, B11111, B11011, B11111};     // warning icon - just because we still have one custom character left

byte gauge_left_dynamic[8];   // left part of gauge dynamic - will be set in the loop function
byte gauge_right_dynamic[8];  // right part of gauge dynamic - will be set in the loop function

int cpu_gauge = 0;       // value for the CPU gauge
char buffer[10];         // helper buffer to store C-style strings (generated with sprintf function)
int move_offset = 0;     // used to shift bits for the custom characters

const int gauge_size_chars = 16;       // width of the gauge in number of characters
char gauge_string[gauge_size_chars+1]; // string that will include all the gauge character to be printed

void setup()
{
  lcd.init();                       // initialize the 20x4 lcd module
  lcd.createChar(7, gauge_empty);   // middle empty gauge
  lcd.createChar(1, gauge_fill_1);  // filled gauge - 1 column
  lcd.createChar(2, gauge_fill_2);  // filled gauge - 2 columns
  lcd.createChar(3, gauge_fill_3);  // filled gauge - 3 columns
  lcd.createChar(4, gauge_fill_4);  // filled gauge - 4 columns  
  lcd.createChar(0, warning_icon); // warning icon - just because we have one more custom character that we could use  
  lcd.backlight();                  // enable backlight for the LCD module



  pinMode(SCL_LED_PIN, OUTPUT);
  pinMode(LIGHT0_PIN, OUTPUT);
  pinMode(LIGHT1_PIN, OUTPUT);
  pinMode(LIGHT2_PIN, OUTPUT);
  pinMode(LIGHT3_PIN, OUTPUT);
  pinMode(LIGHT4_PIN, OUTPUT);

}


void loop()
{
  float units_per_pixel = (gauge_size_chars*5.0)/100.0;        //  every character is 5px wide, we want to count from 0-100
  int value_in_pixels = round(cpu_gauge * units_per_pixel);    // cpu_gauge value converted to pixel width

  int tip_position = 0;      // 0= not set, 1=tip in first char, 2=tip in middle, 3=tip in last char

  if (value_in_pixels < 5) {tip_position = 1;}                            // tip is inside the first character
  else if (value_in_pixels > gauge_size_chars*5.0-5) {tip_position = 3;}  // tip is inside the last character
  else {tip_position = 2;}                                                // tip is somewhere in the middle

  move_offset = 4 - ((value_in_pixels-1) % 5);      // value for offseting the pixels for the smooth filling

  for (int i=0; i<8; i++) {   // dynamically create left part of the gauge
     if (tip_position == 1) {gauge_left_dynamic[i] = (gauge_fill_5[i] << move_offset) | gauge_left[i];}  // tip on the first character
     else {gauge_left_dynamic[i] = gauge_fill_5[i];}                                                     // tip not on the first character
 
     gauge_left_dynamic[i] = gauge_left_dynamic[i] & gauge_mask_left[i];                                 // apply mask for rounded corners
  }

  for (int i=0; i<8; i++) {   // dynamically create right part of the gauge
     if (tip_position == 3) {gauge_right_dynamic[i] = (gauge_fill_5[i] << move_offset) | gauge_right[i];}  // tip on the last character
     else {gauge_right_dynamic[i] = gauge_right[i];}                                                       // tip not on the last character

     gauge_right_dynamic[i] = gauge_right_dynamic[i] & gauge_mask_right[i];                                // apply mask for rounded corners
  }  

  lcd.createChar(5, gauge_left_dynamic);     // create custom character for the left part of the gauge
  lcd.createChar(6, gauge_right_dynamic);    // create custom character for the right part of the gauge

  for (int i=0; i<gauge_size_chars; i++) {  // set all the characters for the gauge
      if (i==0) {gauge_string[i] = byte(5);}                        // first character = custom left piece
      else if (i==gauge_size_chars-1) {gauge_string[i] = byte(6);}  // last character = custom right piece
      else {                                                        // character in the middle, could be empty, tip or fill
         if (value_in_pixels <= i*5) {gauge_string[i] = byte(7);}   // empty character
         else if (value_in_pixels > i*5 && value_in_pixels < (i+1)*5) {gauge_string[i] = byte(5-move_offset);} // tip
         else {gauge_string[i] = byte(255);}                        // filled character
      }
  }

  // gauge drawing
  lcd.setCursor(0,0);                         // move cursor to top left
  sprintf(buffer, "CPU:%3d%% ", cpu_gauge);    // set a string as CPU: XX%, with the number always taking at least 3 character
  lcd.print(buffer);                          // print the string on the display
  lcd.write(byte(0));                         // print warning character  
  
  lcd.setCursor(0,1);              // move the cursor to the next line
  lcd.print(gauge_string);         // display the gauge

 // map the result to a range from 0 to the number of LEDs:
  int ledLevel = map(cpu_gauge, 0, 100, 0, ledCount);

  // loop over the LED array:
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    // if the array element's index is less than ledLevel,
    // turn the pin for this element on:
    if (thisLed < ledLevel) {
      digitalWrite(ledPins[thisLed], HIGH);
    }
    // turn off all pins higher than the ledLevel:
    else {
      digitalWrite(ledPins[thisLed], LOW);
    }
  }

  // increase the CPU value, set between 0-100
  cpu_gauge = cpu_gauge +1;
  if (cpu_gauge > 100) {cpu_gauge = 0;}

  delay(100);  // wait for a while - 100ms = update the screen 10x in a second
}
