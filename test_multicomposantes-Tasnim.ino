//Dans ce croquis se tient une série de test pour le LCD, le diode multicolor, le buzzer, et un essais avec un détecteur à ultrason et avec la manette que j'utlise dans ce projet.

//importer la bibliothèque pour l'afficheur LCD
#include <LiquidCrystal.h>

//Définir les broches de la diode multicolor
const int redpin = 9;
const int greenpin = 10;
const int bluepin = 11;
//Définir la broche du buzzer passif
const int loud_pin = A0;
//Définir les broches du détecteur à ultrason
const int trig_pin = 7;
const int echo_pin = 8;
//Définir les broches du LCD
const int rs=13,  en=2, d4= 4, d5= 5, d6= 6, d7= 7;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//Définir les broches de la manette
#define VRY A2
 
//Définir les variables pour le détacteur à ultrason
float duration, distance;

void setup() {
  //Définir les broches RGB comme sortie
  pinMode(redpin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  pinMode(bluepin, OUTPUT);  
  //Définir le buzzer comme sortie
  pinMode(loud_pin, OUTPUT);
  //Définir la broche trigger comme sortie et echo comme entrée
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  //Définir la communication Serial
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("HI!");
}

void loop() {
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);

  duration = pulseIn(echo_pin, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance est: ");
  Serial.println(distance);
  Serial.println(duration);
  delay(100);

  lcd.setCursor(0,1);
  lcd.print(millis()/1000);


/*
  analogWrite(redpin, 255);
  analogWrite(greenpin, 0);
  analogWrite(bluepin, 0);

  tone(loud_pin, 262, 500);

  delay(1000);
  
  noTone(loud_pin);

  analogWrite(redpin, 0);
  analogWrite(greenpin, 255);
  analogWrite(bluepin, 0);

  tone(loud_pin, 328, 500);

  delay(1000);

  noTone(loud_pin);

  analogWrite(redpin, 0);
  analogWrite(greenpin, 0);
  analogWrite(bluepin, 255);

  tone(loud_pin, 393, 500);

  delay(1000);


  noTone(loud_pin);
  tone(loud_pin, 262, 500);
  delay(1000);
  noTone(loud_pin);
  tone(loud_pin, 328, 500);
  delay(1000);
  noTone(loud_pin);
  tone(loud_pin, 393, 500);
  delay(1000);
  noTone(loud_pin);
  tone(loud_pin, 393, 500);
  delay(1000);
  noTone(loud_pin);
  tone(loud_pin, 393, 500);
  delay(1000);
  noTone(loud_pin);
  tone(loud_pin, 328, 500);
  delay(1000);
  noTone(loud_pin);
  tone(loud_pin, 262, 500);
  delay(1000);
  noTone(loud_pin);
  tone(loud_pin, 262, 500);
  delay(1000);
  
  */
}
