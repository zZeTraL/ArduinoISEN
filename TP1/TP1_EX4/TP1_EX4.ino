//Include ISEN libraries
#include <ISEN.h>
#include <LabIsen-2009.h>
#include <ISL12026.h>
#include <MCP23X08.h>


#define LED_ROUGE  8
#define LED_ORANGE 9
#define LED_VERTE  3

int bouton = 2;
int etatbouton;
bool maVariable = false;




void setup() {
  Serial.begin(9600);
  pinMode(LED_VERTE , OUTPUT);
  pinMode(LED_ORANGE, OUTPUT);
  pinMode(LED_ROUGE, OUTPUT);
  pinMode(bouton, INPUT);
  etatbouton = digitalRead(bouton);
}

void loop() {
etatbouton = digitalRead(bouton);
if ( etatbouton == HIGH)
{
  maVariable = true;
}
else
{
  maVariable = false;
}
if ( maVariable == true )  
{
  digitalWrite(LED_VERTE, HIGH);
  delay(500);
  digitalWrite(LED_VERTE, LOW);
  digitalWrite(LED_ORANGE, HIGH);
  delay(500);
  digitalWrite(LED_ORANGE, LOW);
  digitalWrite(LED_ROUGE, HIGH);
  delay(500);
  digitalWrite(LED_ROUGE, LOW);
}
else
{
  digitalWrite(LED_ROUGE, HIGH);
  delay(500);
  digitalWrite(LED_ROUGE, LOW);
  digitalWrite(LED_ORANGE, HIGH);
  delay(500);
  digitalWrite(LED_ORANGE, LOW);
  digitalWrite(LED_VERTE, HIGH);
  delay(500);
  digitalWrite(LED_VERTE, LOW);
}
}
