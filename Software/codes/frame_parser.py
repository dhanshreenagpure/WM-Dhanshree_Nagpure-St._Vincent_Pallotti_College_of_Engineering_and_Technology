# frame_parser.py
# This file decodes the binary data frame received from LoRa

SOF = 0x7E
EOF = 0x0D

def parse_frame(frame_bytes):
    #Parse a 7-byte LoRa data frame.
    #Frame Format:
    #| SOF | NODE_ID(2) | FILL | STATUS | CRC | EOF |
    

    # Check frame length
    if len(frame_bytes) != 7:
        return None

    # Check start and end markers
    if frame_bytes[0] != SOF or frame_bytes[6] != EOF:
        return None

    # Extract data
    node_id = (frame_bytes[1] << 8) | frame_bytes[2]
    fill = frame_bytes[3]
    status = frame_bytes[4]
    received_crc = frame_bytes[5]

    # Calculate CRC (XOR)
    calculated_crc = frame_bytes[1] ^ frame_bytes[2] ^ frame_bytes[3] ^ frame_bytes[4]

    if received_crc != calculated_crc:
        print("CRC error")
        return None

    return {
        "node_id": node_id,
        "fill": fill,
        "status": status
    }
