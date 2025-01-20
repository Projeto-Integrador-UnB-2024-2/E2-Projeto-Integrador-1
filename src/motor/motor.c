#include <stdio.h>
#include "motor.h"
#include <Arduino.h>

void motorInit(ModuleMotor *motor, uint8_t rightMotorEnable, uint8_t leftMotorEnable, 
uint8_t rightMotorPWMF, uint8_t leftMotorPWMF, uint8_t rightMotorPWMB, uint8_t leftMotorPWMB, bool tension) {
    motor->rightMotorEnable = rightMotorEnable;
    motor->leftMotorEnable = leftMotorEnable;
    motor->rightMotorPWMF = rightMotorPWMF;
    motor->leftMotorPWMF = leftMotorPWMF;
    motor->rightMotorPWMB = rightMotorPWMB;
    motor->leftMotorPWMB = leftMotorPWMB;
    motor->tension = tension;

    pinMode(motor->rightMotorEnable, OUTPUT);
    pinMode(motor->leftMotorEnable, OUTPUT);
    pinMode(motor->rightMotorPWMF, OUTPUT);
    pinMode(motor->rightMotorPWMB, OUTPUT);
    pinMode(motor->leftMotorPWMF, OUTPUT);
    pinMode(motor->leftMotorPWMB, OUTPUT);

    stopMotor(&motor);
}

void moveForward(ModuleMotor *motor) {
    digitalWrite(motor->rightMotorEnable, HIGH);
    digitalWrite(motor->leftMotorEnable, HIGH);

    analogWrite(motor->rightMotorPWMF, motor->tension * 255);
    analogWrite(motor->leftMotorPWMF, motor->tension * 255);
}

void moveBackward(ModuleMotor *motor) {
    digitalWrite(motor->rightMotorEnable, HIGH);
    digitalWrite(motor->leftMotorEnable, HIGH);

    analogWrite(motor->rightMotorPWMB, motor->tension * 255);
    analogWrite(motor->leftMotorPWMB, motor->tension * 255);
}

void turnLeft(ModuleMotor *motor) {
    digitalWrite(motor->rightMotorEnable, HIGH);
    digitalWrite(motor->leftMotorEnable, HIGH);

    analogWrite(motor->leftMotorPWMF, motor->tension * 255);
    analogWrite(motor->rightMotorPWMB, motor->tension * 255);
}

void turnRight(ModuleMotor *motor) {
    digitalWrite(motor->rightMotorEnable, HIGH);
    digitalWrite(motor->leftMotorEnable, HIGH);

    analogWrite(motor->rightMotorPWMF, motor->tension * 255);
    analogWrite(motor->leftMotorPWMB, motor->tension * 255);
}

void stopMotor(ModuleMotor *motor) {
    digitalWrite(motor->rightMotorEnable, LOW);
    digitalWrite(motor->leftMotorEnable, LOW);

    analogWrite(motor->rightMotorPWMF, 0);
    analogWrite(motor->rightMotorPWMB, 0);
    analogWrite(motor->leftMotorPWMF, 0);
    analogWrite(motor->leftMotorPWMB, 0);
}

void debugMotorState(ModuleMotor *motor) {
    Serial.print("Tension: ");
    Serial.println(motor->tension);
    Serial.print("Right Direction: ");
    Serial.println(motor->rightMotorPWMB ? "Forward" : "Backward");
    Serial.print("Left Direction: ");
    Serial.println(motor->leftMotorPWMB ? "Forward" : "Backward");
}