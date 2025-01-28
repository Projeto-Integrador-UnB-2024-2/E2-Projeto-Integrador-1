#include <stdio.h>
#include "Arduino.h"
#include "infrared.h"

// Initializes the infrared sensor with the specified pin and edge detection threshold
void infraredInit(ModuleInfrared *infrared, uint8_t pin, int edgeDetection) {
    infrared->pin = pin; // Assigns the pin for the infrared sensor
    infrared->edgeDetection = edgeDetection; // Set the edge detection threshold
    pinMode(infrared->pin, INPUT); // Configure the pin as an input
}

// Checks if the edge is detected by the infrared sensor
int verifyEdge(ModuleInfrared *infrared) {
    int total = 0;

    for(int i = 0; i < 5; i++) {
        total += analogRead(infrared->pin); // Reads the analog value from the infrared sensor
        delay(10);
    }

    return (total / 5) > infrared->edgeDetection; 
}