/*

  LiquidCrystal Library - Autoscroll

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal

 library works with all LCD displays that are compatible with the

 Hitachi HD44780 driver. There are many of them out there, and you

 can usually tell them by the 16-pin interface.

 This sketch demonstrates the use of the autoscroll()

 and noAutoscroll() functions to make new text scroll or not.

 The circuit:

 * LCD RS pin to digital pin 12

 * LCD Enable pin to digital pin 11

 * LCD D4 pin to digital pin 5

 * LCD D5 pin to digital pin 4

 * LCD D6 pin to digital pin 3

 * LCD D7 pin to digital pin 2

 * LCD R/W pin to ground

 * 10K resistor:

 * ends to +5V and ground

 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008

 by David A. Mellis

 library modified 5 Jul 2009

 by Limor Fried (http://www.ladyada.net)

 example added 9 Jul 2009

 by Tom Igoe

 modified 22 Nov 2010

 by Tom Igoe

 modified 7 Nov 2016

 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalAutoscroll

*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to

const int rs = 13, en = 2, d4 = 4, d5 = 5, d6 = 6, d7 = 7;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void affichemoidonc(int nbr) {
  lcd.clear(); // efface sinon le tete precedent peut rester
  if(nbr < 4) {
    lcd.print("VA MANGER!");
  } else if(nbr < 10){
    lcd.print("Ca va.");
  }
  else{
    lcd.print("ARRETE DE MANGER!");
  }
}

int nbr = 2;

void setup() {

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  
}

void loop() {

  // set the cursor to (0,0):

  lcd.setCursor(0, 0);

  // print from 0 to 9:

  affichemoidonc(nbr);
  lcd.setCursor(0, 0);
  delay(2000);
  nbr = 5;

  affichemoidonc(nbr);
  lcd.setCursor(0, 0);
 delay(2000);
  nbr = 11;

  affichemoidonc(nbr);
  lcd.setCursor(0, 0);
 delay(2000);
  // set the cursor to (16,1):

  //lcd.setCursor(0, 1);

  // set the display to automatically scroll:

  //lcd.autoscroll();

  // print from 0 to 9:

  lcd.clear();

}