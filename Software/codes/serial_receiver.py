# serial_reader.py
# Reads data from LoRa gateway using serial port

import serial
from frame_parser import parse_frame

# Open serial port (change COM port if needed)
ser = serial.Serial('COM3', 9600, timeout=1)

print("Listening for LoRa data...")

buffer = bytearray()

while True:
    byte = ser.read()

    if not byte:
        continue

    buffer += byte

    # Frame length is fixed (7 bytes)
    if len(buffer) >= 7:
        frame = buffer[:7]
        buffer = buffer[7:]

        parsed_data = parse_frame(frame)

        if parsed_data:
            print("Received Data:", parsed_data)
