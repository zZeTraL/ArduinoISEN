// Include ISEN libraries
#include <ISEN.h>
#include <LabIsen-2009.h>
#include<ISL12026.h>
#include <MCP23X08.h>

// Include Arduinolibraries
#include <LiquidCrystal.h>
ISENLiquidCrystal lcd;
int compteur = 1;       // compteur qui sert d'incrémenteur (increménte de un en un les secondes)
bool start = false;      // bool pour start

int seconds = 0;
int minutes = 0;
int hours = 0;

void setup() {
  lcd.begin(16, 2);
  pinMode(2, INPUT);    // interrupt
  pinMode(8, INPUT);    // start
  pinMode(9, INPUT);    // reset
  attachInterrupt(digitalPinToInterrupt(2), interrupt, FALLING);
}

void loop(){
  lireEntree(8);
  lireEntree(9);
  affichage();
  if(start == true){
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
    } else if(compteur == 0) {    // si le compteur == 0 cela veut dire que la fonction interrupt() a été utilisé donc l'affichage restera statique
      seconds += compteur;
    }
  delay(1000);
  }
}

void reset(){
  lcd.clear();
  seconds = 0;
  minutes = 0;
  hours = 0;
  compteur = 1;
  start = false;
}

void launch(){
  start = true;
}

void interrupt(){
  if (compteur == 0){
    compteur = 1;
  } else {
    compteur = 0;
  }
}

void lireEntree(int pin){
  if(pin == 8 && digitalRead(pin) == LOW){
    start = true;
  } else {
    if(digitalRead(pin) == LOW){
      reset();   
    }
  }
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
