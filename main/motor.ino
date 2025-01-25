#include <stdio.h>
#include "motor.h"
#include <Arduino.h>

// Stops all motors, disabling movement
void stopMotor(ModuleMotor *motor) {
    digitalWrite(motor->motorEnable, LOW); // Disables the motors

    // Set all PWM pins to zero
    analogWrite(motor->rightMotorPWMF, 0);
    analogWrite(motor->rightMotorPWMB, 0);
    analogWrite(motor->leftMotorPWMF, 0);
    analogWrite(motor->leftMotorPWMB, 0);
}

// Initializes the the motors pins and sets the motors to a idle state
void motorInit(ModuleMotor *motor, uint8_t motorEnable, uint8_t rightMotorPWMF,
 uint8_t leftMotorPWMF, uint8_t rightMotorPWMB, uint8_t leftMotorPWMB, float tension) {
    // Assign pin numbers and motor parameters
    motor->motorEnable = motorEnable;
    motor->rightMotorPWMF = rightMotorPWMF;
    motor->leftMotorPWMF = leftMotorPWMF;
    motor->rightMotorPWMB = rightMotorPWMB;
    motor->leftMotorPWMB = leftMotorPWMB;
    motor->tension = tension;

    // Set the pins as outputs
    pinMode(motor->motorEnable, OUTPUT);
    pinMode(motor->rightMotorPWMF, OUTPUT);
    pinMode(motor->rightMotorPWMB, OUTPUT);
    pinMode(motor->leftMotorPWMF, OUTPUT);
    pinMode(motor->leftMotorPWMB, OUTPUT);

    stopMotor(motor); // Ensure motors are stopped upon initialization
}

// Moves the robot forward by setting the PWM pins to the forward direction
void moveForward(ModuleMotor *motor) {
    digitalWrite(motor->motorEnable, HIGH); // Enables the motors

    // Set forward PWM values for both motors
    analogWrite(motor->rightMotorPWMF, motor->tension * 255);
    analogWrite(motor->rightMotorPWMB, 0);
    analogWrite(motor->leftMotorPWMF, motor->tension * 255);
    analogWrite(motor->leftMotorPWMB, 0);
}

// Moves the robot backward by setting the PWM pins to the backward direction
void moveBackward(ModuleMotor *motor) {
    digitalWrite(motor->motorEnable, HIGH); // Enables the motors

    // Set backward PWM values for both motors
    analogWrite(motor->rightMotorPWMF, 0);
    analogWrite(motor->rightMotorPWMB, motor->tension * 255);
    analogWrite(motor->leftMotorPWMF, 0);
    analogWrite(motor->leftMotorPWMB, motor->tension * 255);
}

// Turns the robot to the left by making the right motor move forward and the left motor move backward
void turnLeft(ModuleMotor *motor) {
    digitalWrite(motor->motorEnable, HIGH); // Enables the motors

    // Set the right motor to move forward and the left motor to move backward
    analogWrite(motor->rightMotorPWMF, motor->tension * 255);
    analogWrite(motor->rightMotorPWMB, 0);
    analogWrite(motor->leftMotorPWMF, 0);
    analogWrite(motor->leftMotorPWMB, motor->tension * 255);
}

// Turns the robot to the right by making the left motor move forward and the right motor move backward
void turnRight(ModuleMotor *motor) { 
    digitalWrite(motor->motorEnable, HIGH); // Enables the motors

    // Set the left motor to move forward and the right motor to move backward
    analogWrite(motor->rightMotorPWMF, 0);
    analogWrite(motor->rightMotorPWMB, motor->tension * 255);
    analogWrite(motor->leftMotorPWMF, motor->tension * 255);
    analogWrite(motor->leftMotorPWMB, 0);
}
