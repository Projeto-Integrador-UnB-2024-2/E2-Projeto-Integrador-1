#include <Ultrasonic.h>
#include "Arduino.h"

// Initializes the ultrasonic sensor with the specified pins
void ultrasonicInit(ModuleUltrasonic *ultrasonic, uint8_t trigger, uint8_t echo) {
    ultrasonic->sensor = new Ultrasonic(trigger, echo); // Creates a new Ultrasonic object
    ultrasonic->trigger = trigger; // Assigns the trigger pin
    ultrasonic->distance = 0; // Initializes the distance to zero

    pinMode(echo, INPUT); // Configures the echo pin as input
    pinMode(trigger, OUTPUT); // Configures the trigger pin as output
    digitalWrite(trigger, LOW); // Ensures the trigger pin is low initially
    delay(2); // Short delay to stabilize the sensor
}

// Reads the distance measured by the ultrasonic sensor
int readDistance(ModuleUltrasonic *ultrasonic) {
    digitalWrite(ultrasonic->trigger, HIGH); // Sends a high pulse to the trigger pin
    delayMicroseconds(20); // Pulse duration (20 microseconds)
    ultrasonic->distance = ultrasonic->sensor->Ranging(CM); // Gets the mensured distance in centimeters
    digitalWrite(ultrasonic->trigger, LOW); // Stops the pulse
    return ultrasonic->distance; // Returns the measured distance
}