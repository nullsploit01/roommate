
#include <Arduino.h>
#include <DHT.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <DHTReader.h>

// Include the library code
#include <Configuration.h>
#include <ConnectWifi.h>
#include <DHTReadingUploader.h>

#define WIFI_INDICATOR D3

void setup()
{
  Serial.begin(115200);
  pinMode(WIFI_INDICATOR, OUTPUT);

  connectWifi();
  dht.begin();
}

void loop()
{
  if (isConnected())
  {
    digitalWrite(WIFI_INDICATOR, HIGH);
    readAndSendDHTValuesToServer();
  }
  else
  {
    digitalWrite(WIFI_INDICATOR, LOW);
    Serial.println("WiFi Disconnected");
  }

  delay(105000);

  digitalWrite(WIFI_INDICATOR, LOW);
  delay(1500);
  digitalWrite(WIFI_INDICATOR, HIGH);
}