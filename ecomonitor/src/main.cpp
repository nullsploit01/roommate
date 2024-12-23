
#include "Arduino.h"


void setup()
{
  // initialize LED digital pin as an output.
  pinMode(D3, OUTPUT);
}

void loop()
{
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(D3, HIGH);

  // wait for a second
  delay(1000);

  // turn the LED off by making the voltage LOW
  digitalWrite(D3, LOW);

   // wait for a second
  delay(500);
}