void sendGetRequest(String path)
{
  if (WiFi.status() == WL_CONNECTED)
  {
    HTTPClient http;
    WiFiClient wifiClient;
    String fullURL = String(SERVER_API_URL) + path; // Construct the full URL
    http.begin(wifiClient, fullURL);                // Specify the URL
    int httpCode = http.GET();                      // Send the request

    if (httpCode > 0)
    {
      Serial.printf("GET Response code: %d\n", httpCode);
      String payload = http.getString();
      Serial.println("Response:");
      Serial.println(payload);
    }
    else
    {
      Serial.printf("GET request failed, error: %s\n", http.errorToString(httpCode).c_str());
    }
    http.end();
  }
}

void sendPostRequest(String path, String jsonData)
{
  if (WiFi.status() == WL_CONNECTED)
  {
    HTTPClient http;
    WiFiClient wifiClient;

    String fullURL = String(SERVER_API_URL) + path;     // Construct the full URL
    http.begin(wifiClient, fullURL);                    // Specify the URL
    http.addHeader("Content-Type", "application/json"); // Set content type to JSON

    int httpCode = http.POST(jsonData); // Send the POST request

    if (httpCode > 0)
    {
      Serial.printf("POST Response code: %d\n", httpCode);
      String payload = http.getString();
      Serial.println("Response:");
      Serial.println(payload);
    }
    else
    {
      Serial.printf("POST request failed, error: %s\n", http.errorToString(httpCode).c_str());
    }
    http.end();
  }
}