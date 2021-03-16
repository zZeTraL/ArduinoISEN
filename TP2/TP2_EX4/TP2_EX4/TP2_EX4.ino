// Include ISEN libraries
#include <ISEN.h>
#include <LabIsen-2009.h>
#include <ISL12026.h>
#include <MCP23X08.h>

// Include Arduino libraries
#include <Wire.h>
IOstd io;

void setup() {
  io.begin();
  io.clear();
}

void loop() {
  for(int i=5;i <= 12 ;i++) { // boucle qui va parcourir tous les pins des boutons
    io.digitalWrite(i,io.digitalRead(i)); // on allume la led si le bouton est activé donc si le read égale HIGH
  }
  delay(50); // delay
}
