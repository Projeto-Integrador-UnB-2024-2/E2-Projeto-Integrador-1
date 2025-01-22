#include <stdio.h>
#include "motor.h"
#include <Arduino.h>

void stopMotor(ModuleMotor *motor) {
    digitalWrite(motor->motorEnable, LOW);

    analogWrite(motor->rightMotorPWMF, 0);
    analogWrite(motor->rightMotorPWMB, 0);
    analogWrite(motor->leftMotorPWMF, 0);
    analogWrite(motor->leftMotorPWMB, 0);
}

void motorInit(ModuleMotor *motor, uint8_t motorEnable, uint8_t rightMotorPWMF,
 uint8_t leftMotorPWMF, uint8_t rightMotorPWMB, uint8_t leftMotorPWMB, float tension) {
    motor->motorEnable = motorEnable;
    motor->rightMotorPWMF = rightMotorPWMF;
    motor->leftMotorPWMF = leftMotorPWMF;
    motor->rightMotorPWMB = rightMotorPWMB;
    motor->leftMotorPWMB = leftMotorPWMB;
    motor->tension = tension;

    pinMode(motor->motorEnable, OUTPUT);
    pinMode(motor->rightMotorPWMF, OUTPUT);
    pinMode(motor->rightMotorPWMB, OUTPUT);
    pinMode(motor->leftMotorPWMF, OUTPUT);
    pinMode(motor->leftMotorPWMB, OUTPUT);

    stopMotor(motor);
}

void moveForward(ModuleMotor *motor) {
    digitalWrite(motor->motorEnable, HIGH);

    analogWrite(motor->rightMotorPWMF, motor->tension * 255);
    analogWrite(motor->leftMotorPWMF, motor->tension * 255);
}

void moveBackward(ModuleMotor *motor) {
    digitalWrite(motor->motorEnable, HIGH);

    analogWrite(motor->rightMotorPWMB, motor->tension * 255);
    analogWrite(motor->leftMotorPWMB, motor->tension * 255);
}

void turnLeft(ModuleMotor *motor) {
    digitalWrite(motor->motorEnable, HIGH);

    analogWrite(motor->leftMotorPWMF, motor->tension * 255);
    analogWrite(motor->rightMotorPWMB, motor->tension * 255);
}

void turnRight(ModuleMotor *motor) {
    digitalWrite(motor->motorEnable, HIGH);

    analogWrite(motor->rightMotorPWMF, motor->tension * 255);
    analogWrite(motor->leftMotorPWMB, motor->tension * 255);
}