#include <stdio.h>
#include "Arduino.h"
#include "infrared.h"

// Initializes the infrared sensor with the specified pin and edge detection threshold
void infraredInit(ModuleInfrared *infrared, int pin, int edgeDetection) {
    infrared->pin = pin; // Assigns the pin for the infrared sensor
    infrared->edgeDetection = edgeDetection; // Set the edge detection threshold
    pinMode(infrared->pin, INPUT); // Configure the pin as an input
}

// Checks if the edge is detected by averaging multiple sensor readings
int verifyEdge(ModuleInfrared *infrared) {
     int totalReading = 0;

    // Take 5 readings and sum them up
    for (int i = 0; i < 5; i++) {
        totalReading += analogRead(infrared->pin); // Read the analog value from the sensor
        delay(10); // Ad a small delay between readings
    }

    // Return true if the average reading is below the edge detection threshold
    return (totalReading/5) < infrared->edgeDetection; 
}