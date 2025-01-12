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

    mqtt_client.publish(f"nodes/{NODE_IDENTIFIER}/status", "online")

    time.sleep(2)

    while True:
        temperature, humidity = read_dht()
        time.sleep(2)

if __name__ == "__main__":
    main()
