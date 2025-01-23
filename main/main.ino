#include <Arduino.h>
#include "motor.h"
#include "ultrasonic.h"
#include "infrared.h"

#define THRESHOLD 30
#define ROBOT_WEIGHT 0.0 

ModuleMotor motors;
ModuleUltrasonic ultrasonics[3];
ModuleInfrared infraredSensors[2];

void setup() {
    int infraredLeft = analogRead(A0), infraredRight = analogRead(A1); 

    motorInit(&motors, 7, 11, 10, 6, 5, 0.6);
    ultrasonicInit(&ultrasonics[0], 8, 2);
    ultrasonicInit(&ultrasonics[1], 8, 3);
    ultrasonicInit(&ultrasonics[2], 8, 13);
    infraredInit(&infraredSensors[0], infraredLeft, THRESHOLD);
    infraredInit(&infraredSensors[1], infraredRight, THRESHOLD);

    Serial.begin(9600);
}

int isOnEdge() {
    return verifyEdge(&infraredSensors[0]) || verifyEdge(&infraredSensors[1]);
}

void detectObjects() {
    int distances[3];
    for (int i = 0; i < 3; i++) {
        distances[i] = readDistance(&ultrasonics[i]);
    }

    if (distances[1] < 50) {
        moveForward(&motors);
        delay(100);
    } 
    
    else {
        int minimum = (distances[0] < distances[2]) ? 0 : 2;
        if (minimum == 0) turnLeft(&motors);
        else turnRight(&motors);
    }
}

void resetPosition() {
    stopMotor(&motors);
    delay(50);
    moveBackward(&motors);
    delay(100);
    turnLeft(&motors);
    delay(100);
}

//float calculateTractionForce() {
//    
//}

void loop() {
    if (isOnEdge()) {
        resetPosition();
        return;
    }

    detectObjects();
    delay(100);
}