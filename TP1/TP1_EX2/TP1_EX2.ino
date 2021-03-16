//Include ISEN libraries
#include <ISEN.h>
#include <LabIsen-2009.h>
#include <ISL12026.h>
#include <MCP23X08.h>

#define LED_ROUGE  8
#define LED_ORANGE 9
#define LED_VERTE  2

void setup() {
  Serial.begin(9600);
  pinMode(LED_VERTE , OUTPUT);
  pinMode(LED_ORANGE, OUTPUT);
  pinMode(LED_ROUGE, OUTPUT);
}

void loop() {
  allumer(LED_VERTE, 5);
  allumer(LED_ORANGE, 2);
  allumer(LED_ROUGE, 5);
}

void allumer(int pin, int seconds){
  digitalWrite(pin, HIGH);
  delay(seconds*1000);
  digitalWrite(pin, LOW);
}
