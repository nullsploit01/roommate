
#include "Arduino.h"


void setup()
{
  // initialize LED digital pin as an output.
  pinMode(15, OUTPUT);
}

void loop()
{
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(15, HIGH);

  // wait for a second
  delay(5000);

  // turn the LED off by making the voltage LOW
  digitalWrite(15, LOW);

   // wait for a second
  delay(5000);
}