#include <UploadNodeValue.h>

void readAndSendDHTValuesToServer()
{
    float h = readHumidity();
    float t = readTemperature();

    if (h == -1 || t == -1)
    {
        Serial.println(F("Failed reading temperature or humidity from DHT sensor"));
        return;
    }

    float hic = readHeatIndex();

    uploadNodeValue(String(t), NODE_TEMPERATURE_API_KEY);
    uploadNodeValue(String(h), NODE_HUMIDITY_API_KEY);
    uploadNodeValue(String(hic), NODE_HEAT_INDEX_API_KEY);
}