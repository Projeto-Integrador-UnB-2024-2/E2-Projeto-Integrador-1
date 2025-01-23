#include <Ultrasonic.h>
#include "Arduino.h"

void ultrasonicInit(ModuleUltrasonic *ultrasonic, uint8_t trigger, uint8_t echo) {
    ultrasonic->sensor = new Ultrasonic(trigger, echo);
    ultrasonic->trigger = trigger;
    ultrasonic->distance = 0;

    pinMode(trigger, OUTPUT);
    pinMode(echo, INPUT);
    digitalWrite(trigger, LOW);
    delay(2);
}

int readDistance(ModuleUltrasonic *ultrasonic) {
    digitalWrite(ultrasonic->trigger, HIGH);
    delayMicroseconds(20);
    digitalWrite(ultrasonic->trigger, LOW);
    ultrasonic->distance = ultrasonic->sensor->Ranging(CM);
    return ultrasonic->distance;
}