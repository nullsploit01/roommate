from utils.wifi import connect_wifi
from sensors.dht_reader import read_dht

import time

def main():
    connect_wifi()

    while True:
        temperature, humidity = read_dht()
        time.sleep(10)  

if __name__ == "__main__":
    main()