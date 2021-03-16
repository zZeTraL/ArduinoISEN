// Include ISEN libraries
#include <ISEN.h>
#include <LabIsen-2009.h>
#include <ISL12026.h>
#include <MCP23X08.h>

// Include Arduino libraries
#include <Wire.h>
#include <math.h>
#include <LiquidCrystal.h>
IOstd io;
ISENLiquidCrystal lcd;

int decimal = 0;
int tab[8];

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
  io.begin();
  io.clear();
  initTab(tab);
  tab[0] = 1;
  tab[1] = 1;
  tab[2] = 1;
  tab[3] = 1;
  convertToDecimal(tab);
}

void loop() {

}

void convertToDecimal (int tab[]){
  lcd.clear();
  if(tab == NULL){
    lcd.setCursor(0, 0);
    lcd.print("ConvertDecimal function error");
  } else {
    float result = 0;
    for(int i = 0; i <= 8; i++) {
        if(tab[i] == 1){
          result += pow(2, i);
          Serial.println(i);
        } else {
          continue;
        }
    }
    affichage(tab, result);
  }
}

void initTab(int tab[]){
  for(int i = 0; i <= 8; i++){
    tab[i] = 0;
  }
}

void affichage(int tab[], float result){
  for(int i = 0; i <= 8; i++){
      lcd.setCursor(i, 0);
      lcd.print(tab[i]);
  }
  lcd.setCursor(10,0);
  lcd.print("=");
  lcd.setCursor(12, 0);
  lcd.print(result);
}
