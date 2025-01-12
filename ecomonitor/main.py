import dht
import machine
import time
import config
import network

SSID = config.WIFI_SSID
PASSWORD = config.WIFI_PASSWORD

WIFI_LED_LIGHT = machine.Pin(0, machine.Pin.OUT) 

def connect_wifi():
	time.sleep(3)
	wlan = network.WLAN(network.STA_IF)  
	wlan.active(True)                  
	wlan.connect(SSID, PASSWORD)        

	print("Connecting to Wi-Fi...")
	while not wlan.isconnected():       
		time.sleep(1)
		print(".", end="")
		

	print("\nConnected to Wi-Fi")
	print("Network Config:", wlan.ifconfig())
	WIFI_LED_LIGHT.value(1)  

connect_wifi()

dht_sensor = dht.DHT11(machine.Pin(4))  

while True:
    try:
        # Trigger the sensor to measure
        dht_sensor.measure()
        
        # Read temperature and humidity
        temperature = dht_sensor.temperature()  # °C
        humidity = dht_sensor.humidity()        # %

        print("Temperature: {}°C".format(temperature))
        print("Humidity: {}%".format(humidity))
        
    except OSError as e:
        print("Failed to read sensor:", e)
    
    # Wait before reading again
    time.sleep(2)