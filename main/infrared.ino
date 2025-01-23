#include <stdio.h>
#include "Arduino.h"
#include "infrared.h"

void infraredInit(ModuleInfrared *infrared, int pin, int edgeDetection) {
    infrared->pin = pin;
    infrared->edgeDetection = edgeDetection;
    pinMode(infrared->pin, INPUT);
}

int verifyEdge(ModuleInfrared *infrared) {
     int totalReading = 0;

    for (int i = 0; i < 5; i++) {
        totalReading += analogRead(infrared->pin);
        delay(10); 
    }

    return (totalReading/5) < infrared->edgeDetection; 
}