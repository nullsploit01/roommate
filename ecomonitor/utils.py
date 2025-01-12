import network
import time
import machine

from config import WIFI_SSID, WIFI_PASSWORD

WIFI_LED_LIGHT = machine.Pin(0, machine.Pin.OUT) 

def connect_wifi():
    wlan = network.WLAN(network.STA_IF)
    wlan.active(True)
    wlan.connect(WIFI_SSID, WIFI_PASSWORD)

    print(f"Connecting to Wi-Fi: {WIFI_SSID}...")
    while not wlan.isconnected():
        WIFI_LED_LIGHT.value(1) 
        time.sleep(0.3)
        print(".", end="")
        WIFI_LED_LIGHT.value(0) 
        time.sleep(0.3)

    print("\nConnected to Wi-Fi.")
    print("Network Config:", wlan.ifconfig())
    WIFI_LED_LIGHT.value(1)  
