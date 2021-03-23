#include<LiquidCrystal.h>
#define led_vert 10
#define led_orange 9
#define led_rouge 6
#define temperature A0

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int sensorValue = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(led_vert, OUTPUT);
  pinMode(led_orange, OUTPUT);
  pinMode(led_rouge, OUTPUT);
  
  pinMode(temperature, INPUT);
  
  lcd.begin(16, 2);
  lcd.clear();
}

void loop(){
  sensorValue = analogRead(temperature);
  sensorValue = map(sensorValue,20,358,0,125);
  Serial.println(sensorValue) ;  
  
  lcd.clear();
  
  lcd.setCursor(0, 0);
  lcd.print("Temp :");
  resetETA();
  if(sensorValue >= 0 && sensorValue <= 20){
    digitalWrite(led_vert, HIGH);
    lcd.setCursor(7, 0);
    lcd.print(sensorValue);
  }
  if(sensorValue > 20 && sensorValue <= 60){
    digitalWrite(led_orange, HIGH);
    lcd.setCursor(7, 0);
    lcd.print(sensorValue);
  }
  if(sensorValue > 60 && sensorValue <= 125){
    digitalWrite(led_rouge, HIGH);
    lcd.setCursor(7, 0);
    lcd.print(sensorValue);
  }
  delay(500);
}

void resetETA(){
  digitalWrite(led_vert, LOW);
  digitalWrite(led_orange, LOW);
  digitalWrite(led_rouge, LOW);
}
