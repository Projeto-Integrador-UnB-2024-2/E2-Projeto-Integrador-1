#ifndef LEDRGB_H
#define LEDRGB_H

#include <stdint.h>

typedef struct {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} ModuleLedRGB;

void ledRGBInit(ModuleLedRGB *ledRGB, uint8_t red, uint8_t green, uint8_t blue);
void turnOnLedRGB(ModuleLedRGB *ledRGB);
void turnOffLedRGB(ModuleLedRGB *ledRGB);
void blinkLedRGB(ModuleLedRGB *ledRGB, int times, int delayTime);

#endif