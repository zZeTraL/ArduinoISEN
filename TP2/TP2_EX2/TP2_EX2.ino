// Include ISEN libraries
#include <ISEN.h>
#include <LabIsen-2009.h>
#include<ISL12026.h>
#include <MCP23X08.h>

// Include Arduinolibraries
#include <LiquidCrystal.h>
ISENLiquidCrystal lcd;

int compteur = 0;

void setup() {
  lcd.begin(16, 2);
  pinMode(2, INPUT);
  attachInterrupt(digitalPinToInterrupt(2), interrupt, FALLING);
}

void loop() {
   lcd.setCursor(0, 0);
   lcd.print(compteur);
}

void interrupt() {
  compteur +=1 ;
}
