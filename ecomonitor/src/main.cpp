
#include <Arduino.h>
#include <DHT.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

// Include the library code
#include <Configuration.h>
#include <ConnectWifi.h>
#include <HumidityTemperatureReader.h>
#include <ServerHttpClient.h>

void setup()
{
  Serial.begin(115200);
  pinMode(D3, OUTPUT);

  connectWifi();
  dht.begin();
}

void loop()
{

  if (isConnected())
  {
    readDHTValues();
  }
  else
  {
    Serial.println("WiFi Disconnected");
  }

  delay(5000);
}