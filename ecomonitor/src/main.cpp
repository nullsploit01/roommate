
#include <Arduino.h>
#include <DHT.h>
#include <ESP8266WiFi.h>

// Include the library code
#include <Configuration.h>
#include <ConnectWifi.h>

#define DHTPIN D2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(115200);
  
  connectWifi();
  pinMode(D3, OUTPUT);

  dht.begin();
}

void loop()
{

  // Read the humidity
  float h = dht.readHumidity();
  // Read temperature as Celsius 
  float t = dht.readTemperature();

  // Check if any reads have failed
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed reading from DHT sensor"));
    return;
  }

  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);
  
  Serial.print(F("\nHumidity: "));
  Serial.print(h);
  Serial.print(F("% "));
  Serial.print(F("Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(F("Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C"));

  delay(5000);
}