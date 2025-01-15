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
} Motor;

void motorInit(Motor *motor, uint8_t rightMotorEnable, uint8_t leftMotorEnable, 
uint8_t rightMotorPWM, uint8_t leftMotorPWM, float tension, bool direction);
void moveForward(Motor *motor);
void moveBackward(Motor *motor);
void turnLeft(Motor *motor);
void turnRight(Motor *motor);
void stopMotor(Motor *motor);

#endif