void connectWifi()
{
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("Connected to WiFi!");
}

bool isConnected()
{
    return WiFi.status() == WL_CONNECTED;
}