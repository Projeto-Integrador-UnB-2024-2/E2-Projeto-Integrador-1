#ifndef INFRARED_H
#define INFRARED_H

#include <stdint.h>

typedef struct {
    uint8_t pin;
    int edgeDetection;
} ModuleInfrared;

void infraredInit(ModuleInfrared *infrared, uint8_t pin, int edgeDetection);
int verifyEdge(ModuleInfrared *infrared);

#endif