#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <stdint.h>
#include <Ultrasonic.h>

// Structure representing a ultrasonic sensor module
typedef struct {
    Ultrasonic *sensor; // Pointer to the sensor object
    uint8_t trigger; // Trigger pin of the ultrasonic sensor
    int distance; // Last measured distance
} ModuleUltrasonic;

// Initializes the ultrasonic sensor with the specified pins
void ultrasonicInit(ModuleUltrasonic *ultrasonic, uint8_t trigger, uint8_t echo);

// Reads the distance from the ultrasonic sensor and updates the structure
int readDistance(ModuleUltrasonic *ultrasonic);

#endif