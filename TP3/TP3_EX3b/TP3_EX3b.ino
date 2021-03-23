#include<LiquidCrystal.h>
#define led_rouge 6
#define temperature A0
#define potentiometre A1

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int potValue = 0;
int tempValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(led_rouge, OUTPUT);
  
  pinMode(temperature, INPUT);
  pinMode(potentiometre, INPUT);
  
  lcd.begin(16, 2);
  lcd.clear();
}

void loop(){
  tempValue = analogRead(temperature);
  tempValue = map(tempValue,20,358,0,50);
  
  potValue = analogRead(potentiometre);
  potValue = map(potValue,0,1023,0,40);
  Serial.println(potValue) ;  
  
  lcd.clear();
  
  lcd.setCursor(0, 0);
  lcd.print("TempAmb :");
  lcd.setCursor(0, 1);
  lcd.print("TempFixe :");
  digitalWrite(led_rouge, LOW);
  if(potValue > tempValue){
    digitalWrite(led_rouge, HIGH);
  }
  lcd.setCursor(10, 0);
  lcd.print(potValue);
  lcd.setCursor(11, 1);
  lcd.print(tempValue);
  delay(1000);
}
