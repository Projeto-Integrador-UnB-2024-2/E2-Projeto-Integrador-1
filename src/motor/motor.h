#ifndef MOTOR_H
#define MOTOR_H

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint8_t rightMotorEnable;
    uint8_t leftMotorEnable;
    uint8_t rightMotorPWM;
    uint8_t leftMotorPWM;
    float tension;
    bool direction;
} ModuleMotor;

void motorInit(ModuleMotor *motor, uint8_t rightMotorEnable, uint8_t leftMotorEnable, 
uint8_t rightMotorPWM, uint8_t leftMotorPWM, float tension, bool direction);
void moveForward(ModuleMotor *motor);
void moveBackward(ModuleMotor *motor);
void turnLeft(ModuleMotor *motor);
void turnRight(ModuleMotor *motor);
void stopMotor(ModuleMotor *motor);
void debugMotorState(ModuleMotor *motor);

#endif