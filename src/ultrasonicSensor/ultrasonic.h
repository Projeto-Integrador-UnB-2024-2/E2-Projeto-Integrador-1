#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <stdint.h>

typedef struct {
    uint8_t trigger;
    uint8_t echo;
    uint8_t side;
    int distance;
} ModuleUltrasonic;

int ultrasonicInit(ModuleUltrasonic *ultrasonic, uint8_t trigger, uint8_t echo, uint8_t side);
int readDistance(ModuleUltrasonic *ultrasonic);
void debugUltrasonicState(ModuleUltrasonic *ultrasonic);

#endif