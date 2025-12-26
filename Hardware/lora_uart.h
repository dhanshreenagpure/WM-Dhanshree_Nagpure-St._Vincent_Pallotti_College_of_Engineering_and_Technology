#ifndef LORA_UART_H
#define LORA_UART_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" 
{
  #endif

  void lora_uart_init(uint32_t baudrate);
  void lora_uart_send(uint8_t *data, uint16_t length);

  #ifdef __cplusplus
}
#endif

#endif
