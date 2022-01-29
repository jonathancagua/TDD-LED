#ifndef LEDS_DRIVER_H
#define LEDS_DRIVER_H
#include <stdint.h>
#include <stdbool.h>

void LedDriver_Create(uint16_t * address);
void LedDriver_TurnOn(int ledNumber);
#endif // LEDS_DRIVER_H
