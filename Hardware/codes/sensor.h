#ifndef ULTRASONIC_SENSOR_H
#define ULTRASONIC_SENSOR_H

#include <stdint.h>

#define ULTRASONIC_MAX_PERCENT   100

#ifdef __cplusplus
extern "C" 
{
  #endif

  void ultrasonic_init(uint8_t trig_pin, uint8_t echo_pin);
  uint16_t ultrasonic_get_distance(void);
  uint8_t ultrasonic_fill_level(uint16_t bin_depth);

  #ifdef __cplusplus
}
#endif

#endif
