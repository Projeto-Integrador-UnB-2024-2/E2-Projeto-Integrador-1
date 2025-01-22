#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <stdint.h>
#include <Ultrasonic.h>

typedef struct {
    Ultrasonic *sensor;
    int distance;
} ModuleUltrasonic;

void ultrasonicInit(ModuleUltrasonic *ultrasonic, uint8_t trigger, uint8_t echo);
int readDistance(ModuleUltrasonic *ultrasonic);

#endif