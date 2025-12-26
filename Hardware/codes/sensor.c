#include "sensor.h"
#include <Arduino.h>


uint8_t trig;
uint8_t echo;

void ultrasonic_init(uint8_t trig_pin, uint8_t echo_pin)
{
  //hardware pin setup
    trig = trig_pin;
    echo = echo_pin;

    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);

//force trig pin low as we don't know its initial status 
    digitalWrite(trig, LOW);
}

uint16_t ultrasonic_get_distance(void)
{
    long duration;
    uint16_t distance;

    digitalWrite(trig, LOW);
    delayMicroseconds(2);
//make trig high for 10 ms then make it low , it produce a beam of signal
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);

    duration = pulseIn(echo, HIGH, 30000); // 30ms timeout

    if (duration == 0)
        return 0;

//calculates distance from simple formula speed = distance/time 
    distance = duration * 0.034 / 2;
    return distance;
}

uint8_t ultrasonic_get_fill_level(uint16_t bin_depth)
{
    uint16_t distance = ultrasonic_get_distance();

    if (distance == 0 || distance > bin_depth)
        return 0;

    return (uint8_t)(((bin_depth - distance) * ULTRASONIC_MAX_PERCENT) / bin_depth) ;
}
