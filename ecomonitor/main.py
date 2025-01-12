from utils import connect_wifi
from sensors import read_dht
from mqtt import MQTTClient
from config import NODE_IDENTIFIER
import time

def main():
    print("Starting DHT sensor reading...")
    connect_wifi()
    time.sleep(2)

    mqtt_client = MQTTClient()
    mqtt_client.connect()
    send_online_status(mqtt_client)
    last_status_time = time.time()

    while True:
        current_time = time.time()
        if current_time - last_status_time >= 120:  # 120 seconds = 2 minutes
            send_online_status(mqtt_client)
            print(f"Published online status for {NODE_IDENTIFIER}")
            last_status_time = current_time


        temperature, humidity = read_dht()
        if temperature is not None and humidity is not None:
            print(f"Published DHT data: Temperature={temperature}°C, Humidity={humidity}%")
        
        time.sleep(30)

def send_online_status(mqtt_client):
    mqtt_client.publish(f"nodes/{NODE_IDENTIFIER}/status", "online")
    print(f"Published online status for {NODE_IDENTIFIER}")

if __name__ == "__main__":
    main()
