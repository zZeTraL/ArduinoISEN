//Include ISEN libraries
#include <ISEN.h>
#include <LabIsen-2009.h>
#include <ISL12026.h>
#include <MCP23X08.h>

// Include Arduinolibraries
#include <LiquidCrystal.h>
ISENLiquidCrystal lcd;

const int monCapteur = 3;
int tension = 0;
float valeurLue = 0.00;
float tab = 0.00;
float tmp = 0.00;
float tab2 = 0.00;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  lcd.setCursor(0, 0);
  valeurLue = analogRead(monCapteur);
  tension = valeurLue/204,6;
  lcd.print(tension);
  lcd.setCursor(2, 0);
  lcd.print("V");
  lcd.setCursor(0,1);
  jauge();
  delay(50);
  lcd.clear();
  
}

void jauge() {
  if (tension == 1)
  {
    lcd.print("===");
  }
  if (tension == 2)
  {
    lcd.print("======");
  }
  if (tension == 3)
  {
    lcd.print("=========");
  }
  if (tension == 4)
  {
    lcd.print("============");
  }
  if (tension == 5)
  {
    lcd.print("==================");
  }  
}
