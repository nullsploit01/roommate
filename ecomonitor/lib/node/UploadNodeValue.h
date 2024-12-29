#include <ServerHttpClient.h>

void uploadNodeValue(String value, String API_KEY)
{
    String jsonData = "{\"value\": \"" + value + "\", \"api_key\": \"" + API_KEY + "\"}";
    String response = sendPostRequest("/nodes/value", jsonData);
    Serial.println(response);
}