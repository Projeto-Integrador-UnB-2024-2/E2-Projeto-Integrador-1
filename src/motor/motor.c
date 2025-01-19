#include <stdio.h>
#include "motor.h"
#include <Arduino.h>

void motorInit(ModuleMotor *motor, uint8_t rightMotorEnable, uint8_t leftMotorEnable, 
uint8_t rightMotorPWM, uint8_t leftMotorPWM, float tension, bool direction) {
    motor->rightMotorEnable = rightMotorEnable;
    motor->leftMotorEnable = leftMotorEnable;
    motor->rightMotorPWM = rightMotorPWM;
    motor->leftMotorPWM = leftMotorPWM;
    motor->tension = tension;
    motor->direction = direction;

    pinMode(motor->rightMotorEnable, OUTPUT);
    pinMode(motor->leftMotorEnable, OUTPUT);
    pinMode(motor->rightMotorPWM, OUTPUT);
    pinMode(motor->leftMotorPWM, OUTPUT);

    digitalWrite(motor->rightMotorEnable, LOW);
    digitalWrite(motor->leftMotorEnable, LOW);

    analogWrite(motor->rightMotorPWM, 0);
    analogWrite(motor->leftMotorPWM, 0);
}

void moveForward(ModuleMotor *motor) {
    motor->direction = true;

    digitalWrite(motor->rightMotorEnable, HIGH);
    digitalWrite(motor->leftMotorEnable, HIGH);

    analogWrite(motor->rightMotorPWM, motor->tension * 255);
    analogWrite(motor->leftMotorPWM, motor->tension * 255);
}

void moveBackward(ModuleMotor *motor) {
    motor->direction = false;

    digitalWrite(motor->rightMotorEnable, HIGH);
    digitalWrite(motor->leftMotorEnable, HIGH);

    analogWrite(motor->rightMotorPWM, motor->tension * 255);
    analogWrite(motor->leftMotorPWM, motor->tension * 255);
}

void turnLeft(ModuleMotor *motor) {
    motor->direction = false;

    digitalWrite(motor->rightMotorEnable, HIGH);
    digitalWrite(motor->leftMotorEnable, HIGH);

    analogWrite(motor->rightMotorPWM, motor->tension * 255);
    analogWrite(motor->leftMotorPWM, 0);
}

void turnRight(ModuleMotor *motor) {
    motor->direction = true;

    digitalWrite(motor->rightMotorEnable, HIGH);
    digitalWrite(motor->leftMotorEnable, HIGH);

    analogWrite(motor->rightMotorPWM, 0);
    analogWrite(motor->leftMotorPWM, motor->tension * 255);
}

void stopMotor(ModuleMotor *motor) {
    digitalWrite(motor->rightMotorEnable, LOW);
    digitalWrite(motor->leftMotorEnable, LOW);

    analogWrite(motor->rightMotorPWM, 0);
    analogWrite(motor->leftMotorPWM, 0);
}

void debugMotorState(ModuleMotor *motor) {
    Serial.print("Right Motor Enable: ");
    Serial.println(motor->rightMotorEnable);
    Serial.print("Left Motor Enable: ");
    Serial.println(motor->leftMotorEnable);
    Serial.print("Tension: ");
    Serial.println(motor->tension);
    Serial.print("Direction: ");
    Serial.println(motor->direction ? "Forward" : "Backward");
}