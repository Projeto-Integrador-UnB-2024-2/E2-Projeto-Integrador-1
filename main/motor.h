#ifndef MOTOR_H
#define MOTOR_H

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint8_t motorEnable;
    uint8_t rightMotorPWMF;
    uint8_t leftMotorPWMF;
    uint8_t rightMotorPWMB;
    uint8_t leftMotorPWMB;
    float tension;
} ModuleMotor;

void motorInit(ModuleMotor *motor, uint8_t motorEnable, uint8_t rightMotorPWMF,
 uint8_t leftMotorPWMF, uint8_t rightMotorPWMB, uint8_t leftMotorPWMB, float tension);
void moveForward(ModuleMotor *motor);
void moveBackward(ModuleMotor *motor);
void turnLeft(ModuleMotor *motor);
void turnRight(ModuleMotor *motor);
void stopMotor(ModuleMotor *motor);
void debugMotorState(ModuleMotor *motor);

#endif