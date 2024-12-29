#define DHTPIN D2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void readDHTValues()
{

    float h = dht.readHumidity();
    float t = dht.readTemperature();

    if (isnan(h) || isnan(t))
    {
        Serial.println(F("Failed reading from DHT sensor"));
        return;
    }

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
}

float readTemperature()
{
    float h = dht.readHumidity();
    if (isnan(h))
    {
        Serial.println(F("Failed reading humidity from DHT sensor"));
        return -1;
    }

    return h;
}

float readHumidity()
{
    float t = dht.readTemperature();
    if (isnan(t))
    {
        Serial.println(F("Failed reading temperature from DHT sensor"));
        return -1;
    }
    return t;
}

float readHeatIndex()
{
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    if (h == -1 || t == -1)
    {
        Serial.println(F("Failed reading temperature or humidity from DHT sensor"));
        return -1;
    }

    return dht.computeHeatIndex(t, h, false);
}