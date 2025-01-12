from utils import connect_wifi
from sensors import read_dht

import time

def main():
    print("Starting DHT sensor reading...")
    connect_wifi()
    time.sleep(5)
    while True:
        temperature, humidity = read_dht()
        time.sleep(2)

if __name__ == "__main__":
    main()
