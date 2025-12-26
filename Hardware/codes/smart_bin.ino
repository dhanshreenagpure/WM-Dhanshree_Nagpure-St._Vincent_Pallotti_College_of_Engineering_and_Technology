#include "sensor.h"
#include "lora_uart.h"

#define TRIG_PIN  5
#define ECHO_PIN  18
#define BIN_DEPTH_CM 60

#define SOF  0x7E
#define EOF  0x0D
#define NODE_ID 0x0101

uint8_t frame[15];

uint8_t calculate_crc(uint8_t *data, uint8_t len)
{
    uint8_t crc = 0;
    for (uint8_t i = 0; i < len; i++)
        crc ^= data[i];
    return crc;
}

void setup()
{
    Serial.begin(9600);

    ultrasonic_init(TRIG_PIN, ECHO_PIN);
    lora_uart_init(9600);   // LoRa UART baudrate
}

void loop()
{
    uint8_t fill = ultrasonic_get_fill(BIN_DEPTH_CM);

    Serial.print("Fill Level: ");
    Serial.print(fill);
    Serial.println("%");


//data frame : | SOF | NODE_ID | FILL | STATUS | CRC | EOF |

    if (fill >= FILL_THRESHOLD)
    {
        tx_frame[0] = SOF;
        tx_frame[1] = (NODE_ID >> 8) & 0xFF;
        tx_frame[2] = NODE_ID & 0xFF;
        tx_frame[3] = fill;
        tx_frame[4] = calc_crc(&tx_frame[1], 3);
        tx_frame[5] = EOF;

        lora_uart_send(tx_frame, 6);
        Serial.println("Threshold crossed : Frame sent");
    }

    delay(5000);
}
