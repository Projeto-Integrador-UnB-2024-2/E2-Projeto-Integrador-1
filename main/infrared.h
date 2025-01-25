#ifndef INFRARED_H
#define INFRARED_H

#include <stdint.h>

// Structure representing an infrared sensor module
typedef struct {
    int pin; // Pin connected to the infrared sensor
    int edgeDetection; // Threshold value to detect the edge
} ModuleInfrared;

// Initializes the infrared sensor with the specified pin and edge detection value
void infraredInit(ModuleInfrared *infrared, uint8_t pin, int edgeDetection);

// Checks if the edge is detected by the infrared sensor
int verifyEdge(ModuleInfrared *infrared);

#endif