import umqtt.simple as umqtt
import json
import machine
from config import MQTT_BROKER, MQTT_PORT, MQTT_CLIENT_ID, MQTT_USERNAME, MQTT_PASSWORD


class MQTTClient:
    def __init__(self):
        self.client = umqtt.MQTTClient(MQTT_CLIENT_ID + machine.unique_id().hex(), MQTT_BROKER, port=MQTT_PORT, user=MQTT_USERNAME, password=MQTT_PASSWORD)

    def connect(self):
        print("Connecting to MQTT broker...")
        self.client.connect()
        print("Connected to MQTT broker.", MQTT_BROKER)

    def publish_json(self, topic, message):
        """Publishes a JSON message to the specified topic."""
        payload = json.dumps(message)
        self.publish(topic, payload)

    def publish(self, topic, message):
        """Publishes a message to the specified topic."""
        try:
            self.client.publish(topic, message)
            print(f"Published to {topic}: {message}")
        except Exception as e:
            print(f"Error publishing to MQTT: {e}")