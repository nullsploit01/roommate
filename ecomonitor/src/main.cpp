
#include "Arduino.h"


void setup()
{
  pinMode(D3, OUTPUT);
  pinMode(D2, INPUT);

  Serial.begin(9600);
}

void loop()
{
  int detection = digitalRead(D2);

  if(detection == HIGH) {
    Serial.println("detected");
    digitalWrite(D3, HIGH);
  }else{
    Serial.println("clear");
    digitalWrite(D3, LOW);
  }

  delay(50);
}