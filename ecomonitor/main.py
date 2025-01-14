from utils import connect_wifi
from sensors import read_dht
from mqtt import MQTTClient
from config import NODE_IDENTIFIER, NODE_HUMIDITY_API_KEY, NODE_TEMPERATURE_API_KEY
import time

def main():
    print("Starting DHT sensor reading...")
    connect_wifi()
    time.sleep(5)

    mqtt_client = MQTTClient()
    mqtt_client.connect()

    send_online_status(mqtt_client)
    time.sleep(5)

    send_dht_data(mqtt_client)
    time.sleep(5)

    last_status_time = time.time()

    while True:
        current_time = time.time()
        if current_time - last_status_time >= (60 * 10):  # 600 seconds = 10 minutes
            send_dht_data(mqtt_client)
            last_status_time = current_time

        send_online_status(mqtt_client)
        time.sleep(120) # 2 minutes

def send_online_status(mqtt_client):
    mqtt_client.publish(f"nodes/{NODE_IDENTIFIER}/status", "online")
    print(f"Published online status for {NODE_IDENTIFIER}")

def send_dht_data(mqtt_client):
    temperature, humidity = read_dht()
    if temperature is None or humidity is None:
        print("Failed to read DHT data.")
        return
    
    mqtt_client.publish(f"nodes/{NODE_HUMIDITY_API_KEY}/value", temperature)
    mqtt_client.publish(f"nodes/{NODE_TEMPERATURE_API_KEY}/value", humidity)

    print(f"Published DHT data for {NODE_IDENTIFIER}")

if __name__ == "__main__":
    main()
