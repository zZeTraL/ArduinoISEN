#include <math.h>

#define led_vert 9
#define led_orange 10
#define led_rouge 11

#define bouton 7
#define potentiometre A0

int sensorValue;
int randomValue = 0;
int result = 0;

void setup() {
  Serial.begin(9600);
  pinMode(led_rouge, OUTPUT);
  pinMode(led_orange, OUTPUT);
  pinMode(led_vert, OUTPUT);
  
  pinMode(bouton, INPUT);
  pinMode(potentiometre, INPUT);
  
  randomSeed(analogRead(0));
  randomValue = random(0, 1024);
  Serial.println(randomValue);
}

void loop(){
  reset();
  sensorValue = analogRead(potentiometre);
  if(digitalRead(bouton) == HIGH){
    randomValue = random(0, 1024);
    Serial.println(randomValue);
    Serial.println(result);
  }

  result = sensorValue - randomValue;
  if(abs(result) < 50){
    digitalWrite(led_vert, HIGH);
  }
  if(abs(result) < 15){
    digitalWrite(led_orange, HIGH);
  }
  if(abs(result) < 3){
    digitalWrite(led_rouge, HIGH);
  }

  Serial.println(sensorValue);      //debug
  delay(500);
}

void reset(){
  digitalWrite(led_vert, LOW);
  digitalWrite(led_orange, LOW);
  digitalWrite(led_rouge, LOW);

}
