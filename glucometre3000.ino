//Dans ce croquis se tient le croquis final de mon projet.

//importer la bibliothèque pour l'afficheur LCD
#include <LiquidCrystal.h>

//Définir les broches du LCD
const int rs=13,  en=2, d4= 4, d5= 5, d6= 6, d7= 7;

//Définir les broches de l'afficheur LCD
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//Définir les broches de la diode multicolor
const int DEL_ROUGE = 9;
const int DEL_VERTE = 10;
const int DEL_BLEUE = 11;

//Définir la broche du buzzer passif
const int brocheBuzzer = A0;

//Définir les broches de la manette
#define MANETTE_Y A2

//Définir les seuils pour les niveaux de glucose
const int BAS = 32;
const int OPT = 350;
const int HAUT = 1023;

//Déclare les variables pour la lecture du niveau de glucose
int glucoseBrut; //La variable glucose, elle tient la valeur d'entrée de la manette
int glucoseMesure; //La variable glucose, mais à une échelle plus réaliste que 0 à 1023

//Cette fonction est paramétrée avec des conditions afin d'afficher le message approprié dépendamment du niveau de glucose.
void affiche_glucose(int glucoseBrut) {
  if(glucoseBrut < 4) {
    lcd.print("GLUCOSE BAS!");
  } else if(glucoseBrut < 14){
    lcd.print("GLUCOSE OPTIMAL");
  } else{
    lcd.print("GLUCOSE HAUT!");
  }
}

void setup() {
  //Définir les broches RGB comme sortie
  pinMode(DEL_ROUGE, OUTPUT);
  pinMode(DEL_VERTE, OUTPUT);
  pinMode(DEL_BLEUE, OUTPUT);  

  //Définir le buzzer comme sortie
  pinMode(brocheBuzzer, OUTPUT);

  //Définir la manette comme entrée
  pinMode(MANETTE_Y, INPUT);

  //Établir la communication Serial afin d'afficher les niveaux de glucose mesurés
  Serial.begin(9600);
  

  lcd.begin(16, 2); //Le texte sur le LCD commence à partir de ce point.
  
}

void loop() {
  //Lecture de la manette Y
  glucoseBrut = analogRead(MANETTE_Y);
  glucoseMesure = map(glucoseBrut, 32, 1023, 2, 22);
  
  //Lecture affiché dans le moniteur et le graphique
  Serial.print("Taux_de_glucose:");
  Serial.print(glucoseMesure);
  Serial.println(" mmol/L");
  delay(500);

  //Mise en position de l'affichage du message sur le LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  affiche_glucose(glucoseMesure);
  //Mise en position de l'affichage du taux de glucose sur le LCD
  lcd.setCursor(0, 1);
  lcd.print(glucoseMesure);
  lcd.print(" mmol/L");

  //Condition si le taux de glucose est bas.
  if (glucoseMesure < 4) {
    analogWrite(DEL_ROUGE, 255); // RGB Rouge
    analogWrite(DEL_VERTE, 0);
    analogWrite(DEL_BLEUE, 0);

    // D minor - BAS
    tone(brocheBuzzer, 349, 500);
    delay(350);
    tone(brocheBuzzer, 294, 500);
    delay(400);
    tone(brocheBuzzer, 349, 500);
    delay(350);
    tone(brocheBuzzer, 294, 500);
    delay(400);
    tone(brocheBuzzer, 349, 500);
    delay(350);
    tone(brocheBuzzer, 250, 500);
    delay(400);
    tone(brocheBuzzer, 349, 500);
    delay(450);
    tone(brocheBuzzer, 440, 600);
    delay(400);
    
  }
  //Condition si le taux de glucose est optimale.
  else if (glucoseMesure < 14) {
    noTone(brocheBuzzer);

    analogWrite(DEL_ROUGE, 0); // RGB Vert
    analogWrite(DEL_VERTE, 255);
    analogWrite(DEL_BLEUE, 0);
  }
  //Conditions si le taux de glucose est haut.
  else{
    analogWrite(DEL_ROUGE, 211); //RGB Jaune
    analogWrite(DEL_VERTE, 84);
    analogWrite(DEL_BLEUE, 0);

    //D minor - HAUT
    tone(brocheBuzzer, 220, 500);
    delay(350);
    tone(brocheBuzzer, 294, 500);
    delay(250);
    tone(brocheBuzzer, 220, 500);
    delay(350);
    tone(brocheBuzzer, 174, 500);
    delay(400);
    tone(brocheBuzzer, 110, 500);
    delay(400);
    tone(brocheBuzzer, 294, 500);
    delay(250);
    tone(brocheBuzzer, 174, 500);
    delay(500);
  }

  delay(300);
}
