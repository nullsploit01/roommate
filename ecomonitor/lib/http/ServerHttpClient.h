String sendGetRequest(String path)
{
  String response = "";
  HTTPClient http;
  WiFiClient wifiClient;
  String fullURL = String(SERVER_API_URL) + path;

  http.begin(wifiClient, fullURL);
  int httpCode = http.GET();

  if (httpCode > 0)
  {
    Serial.printf("GET Response code: %d\n", httpCode);
    response = http.getString();
  }
  else
  {
    Serial.printf("GET request failed, error: %s\n", http.errorToString(httpCode).c_str());
  }
  http.end();

  return response;
}

String sendPostRequest(String path, String jsonData)
{
  String response = "";
  HTTPClient http;
  WiFiClient wifiClient;

  String fullURL = String(SERVER_API_URL) + path;
  http.begin(wifiClient, fullURL);
  http.addHeader("Content-Type", "application/json");

  int httpCode = http.POST(jsonData);

  if (httpCode > 0)
  {
    Serial.printf("POST Response code: %d\n", httpCode);
    response = http.getString();
  }
  else
  {
    Serial.printf("POST request failed, error: %s\n", http.errorToString(httpCode).c_str());
  }
  http.end();
  return response;
}