#ifndef MOTOR_H
#define MOTOR_H

#include <stdint.h>
#include <stdbool.h>

// Structure representing a motor control parameters
typedef struct {
    uint8_t motorEnable; // Pin to enable the motors
    uint8_t rightMotorPWMF; // PWM pin for the foward direction of the right motor
    uint8_t rightMotorPWMB; // PWM pin for the backward direction of the right motor
    uint8_t leftMotorPWMF; // PWM pin for the foward direction of the left motor
    uint8_t leftMotorPWMB; // PWM pin for the backward direction of the left motor
    float tension; // Tension applied to the motors (0.0 to 1.0)
} ModuleMotor;

// Initializes the motors with the specified pins and parameters
void motorInit(ModuleMotor *motor, uint8_t motorEnable, uint8_t rightMotorPWMF, 
uint8_t rightMotorPWMB, uint8_t leftMotorPWMF, uint8_t leftMotorPWMB, float tension);
void moveForward(ModuleMotor *motor);
void moveBackward(ModuleMotor *motor);
void turnLeft(ModuleMotor *motor);
void turnRight(ModuleMotor *motor);
void stopMotor(ModuleMotor *motor);

#endif