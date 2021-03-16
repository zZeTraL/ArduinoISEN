// Include ISEN libraries
#include <ISEN.h>
#include <LabIsen-2009.h>
#include<ISL12026.h>
#include <MCP23X08.h>

// Include Arduinolibraries
#include <LiquidCrystal.h>
ISENLiquidCrystal lcd;
int compteur = 1;       // compteur qui sert d'incrémenteur (increménte de un en un les secondes)
int start = 0;      // bool pour start

int seconds = 0;
int minutes = 0;
int hours = 0;

void setup() {
  lcd.begin(16, 2);
  pinMode(2, INPUT);    // reset
  pinMode(8, INPUT);    // start
  pinMode(9, INPUT);    // pause
  attachInterrupt(digitalPinToInterrupt(2), reset, CHANGE);
  attachInterrupt(digitalPinToInterrupt(9), interrupt, CHANGE);
  attachInterrupt(digitalPinToInterrupt(3), launch, CHANGE);
}

void loop() {
  affichage();  // on affiche à chaque boucle
  while(start == 0){  // tant que start != false donc tant que start == true
    if(compteur == 1){    // si le compteur == 1 on incrémente les secondes de un en un
      seconds += compteur;
      if(seconds > 59){
        lcd.clear();
        seconds = 0;
        minutes += 1;
      }
      if(minutes > 59){
        lcd.clear();
        minutes = 0;
        hours += 1;
      }
    } else if(compteur == 0) {    // si le compteur == 0 cela veut dire que la fonction interrupt() a été utilisé
      seconds += compteur;
    } else {
      reset();
    }
    delay(1000);
  }
  delay(10000);
}

void affichage(){
  lcd.setCursor(0, 0);
  lcd.print(hours);
  lcd.setCursor(2, 0);
  lcd.print(":");
  lcd.setCursor(3, 0);
  lcd.print(minutes);
  lcd.setCursor(5, 0);
  lcd.print(":");
  lcd.setCursor(6, 0);
  lcd.print(seconds); 
}

void reset(){
  seconds = 0;
  minutes = 0;
  hours = 0;
  compteur = 1;
  start = 0;
}

void launch(){
  start = 1;
}

void interrupt() {
  if(compteur == 1){
    compteur = 0;
  } else {
    compteur = 1;
  }
}
