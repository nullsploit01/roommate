import dht
import machine

DHT_PIN = 4  

def read_dht():
    """Reads temperature and humidity from the DHT sensor."""
    try:
        sensor = dht.DHT11(machine.Pin(DHT_PIN))
        sensor.measure()
        temperature = sensor.temperature()
        humidity = sensor.humidity()
        print(f"Temperature: {temperature}°C, Humidity: {humidity}%")
        return temperature, humidity
    except Exception as e:
        print(f"Error reading DHT sensor: {e}")
        return None, None