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
  clignoter(LED_ORANGE, 500, 500, 5);
  digitalWrite(LED_ORANGE, HIGH);
  delay(2000);
  digitalWrite(LED_ORANGE, LOW);
  digitalWrite(LED_ROUGE, HIGH);
  delay(2000);
  digitalWrite(LED_ROUGE, LOW);
}

void clignoter(int pin, int onDelay, int offDelay, int cycle){
  if(pin < 0 || onDelay < 0 || offDelay < 0 || cycle < 0) { // si les paramètres sont erronés on allume la led rouge pour indiquer une erreur
    digitalWrite(LED_ROUGE, HIGH);
  } else {
    for(int i = 0; i < cycle ; i++){
      digitalWrite(pin, HIGH);
      delay(onDelay);
      digitalWrite(pin, LOW);
      delay(offDelay);
    }
  }
}
