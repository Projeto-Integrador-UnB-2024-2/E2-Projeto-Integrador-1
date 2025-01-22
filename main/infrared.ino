#include <stdio.h>
#include "Arduino.h"
#include "infrared.h"

void infraredInit(ModuleInfrared *infrared, int pin, int edgeDetection) {
    infrared->pin = pin;
    infrared->edgeDetection = edgeDetection;
    pinMode(infrared->pin, INPUT);
}

int verifyEdge(ModuleInfrared *infrared) {
    return analogRead(infrared->pin) < infrared->edgeDetection;
}