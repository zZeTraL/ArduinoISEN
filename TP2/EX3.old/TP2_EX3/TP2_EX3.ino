// Include ISEN libraries
#include <ISEN.h>
#include <LabIsen-2009.h>
#include<ISL12026.h>
#include <MCP23X08.h>

// Include Arduinolibraries
#include <LiquidCrystal.h>
ISENLiquidCrystal lcd;
int seconds = 0;
int minutes = 0;
int hours = 0;
bool pause = false;

void setup() {
  lcd.begin(16, 2);
  pinMode(2, INPUT); // reset
  pinMode(8, INPUT); // start
  pinMode(9, INPUT); // pause
  attachInterrupt(digitalPinToInterrupt(2), reset, CHANGE);
  attachInterrupt(digitalPinToInterrupt(9), interrupt, CHANGE);
  attachInterrupt(digitalPinToInterrupt(8), start, CHANGE);
}

void loop() {
  seconds+= 1;
  affichage();
  if(seconds > 59){
     seconds = 0;
     minutes += 1;
  }
  if(minutes > 59){
    lcd.clear();
    minutes = 0;
    seconds = 0;
    hours += 1;
  }
  delay(20);
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
}

void start(){
}

bool interrupt() {
  seconds = 0;
}
