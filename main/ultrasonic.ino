#include <Ultrasonic.h>
#include "Arduino.h"

void ultrasonicInit(ModuleUltrasonic *ultrasonic, uint8_t trigger, uint8_t echo) {
    ultrasonic->sensor = new Ultrasonic(trigger, echo);

    pinMode(trigger, OUTPUT);
    pinMode(echo, INPUT);

    ultrasonic->distance = 0;
    
    digitalWrite(ultrasonic->trigger, HIGH);
}

void stopSensors(ModuleUltrasonic *ultrasonic) {
    digitalWrite(ultrasonic->trigger, LOW);
}

int readDistance(ModuleUltrasonic *ultrasonic) {
    ultrasonic->distance = ultrasonic->sensor->Ranging(CM);
    return ultrasonic->distance;
}