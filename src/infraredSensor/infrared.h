#ifndef INFRARED_H
#define INFRARED_H

#include <stdint.h>

typedef struct {
    uint8_t pin;
    uint8_t side;
    int edgeDetection;
} ModuleInfrared;

void infraredInit(ModuleInfrared *infrared, uint8_t pin, int edgeDetection, uint8_t side);
int verifyEdge(ModuleInfrared *infrared);
void debugInfraredState(ModuleInfrared *infrared);

#endif