# Replace these with your device details
PORT = /dev/tty.usbserial-0001         # Serial port of your device
BAUD = 115200               # Baud rate for flashing
FIRMWARE = ./firmware/esp8266-micropython.bin    # Path to the MicroPython firmware
PY_FILES = config.py sensors.py utils.py mqtt.py main.py boot.py  # Python files to upload

# Tool definitions
ESPT = esptool.py
AMPY = ampy
CHIP = esp8266

# Default target
.PHONY: all
all: help

# Help target
.PHONY: help
help:
	@echo "Makefile for ESP8266/ESP32 MicroPython Workflow"
	@echo "Usage:"
	@echo "  make erase          - Erase the flash memory"
	@echo "  make flash          - Flash MicroPython firmware"
	@echo "  make upload         - Upload Python files to the board"
	@echo "  make repl           - Open REPL"
	@echo "  make reset          - Soft reset the board"

# Erase the flash memory
.PHONY: erase
erase:
	$(ESPT) --chip $(CHIP) --port $(PORT) erase_flash

# Flash MicroPython firmware
.PHONY: flash
flash:
	$(ESPT) --chip $(CHIP) --port $(PORT) --baud $(BAUD) write_flash --flash_size=detect 0 $(FIRMWARE)

# Upload Python files
.PHONY: upload
upload: erase flash
	@for file in $(PY_FILES); do \
		echo "Uploading $$file..."; \
		$(AMPY) --port $(PORT) put $$file; \
	done
	@echo "Upload complete!"

# Open REPL
.PHONY: repl
repl:
	$(AMPY) --port $(PORT) repl

# Soft reset the board
.PHONY: reset
reset:
	$(ESPT) --port $(PORT) erase_flash

# Open a serial terminal using screen
.PHONY: screen
screen:
	screen $(PORT) $(BAUD)