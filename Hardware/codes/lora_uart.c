#include "lora_uart.h"
#include <Arduino.h>

// UART2 Pins (Change if required) 
#define LORA_TX_PIN 17
#define LORA_RX_PIN 16

void lora_uart_init(uint32_t baudrate)
{
  //initialize and setup uart 2 of esp32 
    Serial2.begin(baudrate, SERIAL, LORA_RX_PIN, LORA_TX_PIN);
}

void lora_uart_send(uint8_t *data, uint16_t length)
{
    Serial2.write(data, length);
    Serial2.flush();
}
