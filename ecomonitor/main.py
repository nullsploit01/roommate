import dht
import machine
import time


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