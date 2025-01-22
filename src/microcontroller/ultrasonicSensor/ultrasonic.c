#include <stdio.h>
#include "Ultrasonic.h"
#include "Arduino.h"

void ultrasonicInit(ModuleUltrasonic *ultrasonic, uint8_t trigger, uint8_t echo) {
    ultrasonic.sensor = Ultrasonic(trigger, echo);
    ultrasonic->distance = 0;
}

int readDistance(ModuleUltrasonic *ultrasonic) {
    ultrasonic->distance = ultrasonic.sensor.Ranging(CM);
    return ultrasonic->distance;
}