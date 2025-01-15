#include "motor.h"

float robotWeight = 0.0;
Motor motors[2];

void setup() {
    motorInit(&motors[0], 2, 3, 4, 5, 5.0, true);
    motorInit(&motors[1], 6, 7, 8, 9, 5.0, true);

    stopMotor(&motors[0]);
    stopMotor(&motors[1]);
}

void loop() {
    moveForward(&motors[0]);
    moveForward(&motors[1]);
    delay(1000);

    stopMotor(&motors[0]);
    stopMotor(&motors[1]);
    delay(1000);

    moveBackward(&motors[0]);
    moveBackward(&motors[1]);
    delay(1000);

    stopMotor(&motors[0]);
    stopMotor(&motors[1]);
    delay(1000);

    turnLeft(&motors[0]);
    turnRight(&motors[1]);
    delay(1000);

    stopMotor(&motors[0]);
    stopMotor(&motors[1]);
    delay(1000);
}