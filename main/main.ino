#include <Arduino.h>
#include "motor.h"
#include "ultrasonic.h"
#include "infrared.h"

#define THRESHOLD 30 // Edge detection threshold for infrared sensors
#define ROBOT_WEIGHT 0.0 

ModuleMotor motors; 
ModuleUltrasonic ultrasonics[3]; 
ModuleInfrared infraredSensors[2];

void setup() {
    // Read initial values of infrared sensors
    int infraredLeft = analogRead(A0), infraredRight = analogRead(A1); 

    // Initialize motor and sensors with specified pins and parameters
    motorInit(&motors, 7, 11, 10, 6, 5, 0.6); 
    ultrasonicInit(&ultrasonics[0], 8, 2); 
    ultrasonicInit(&ultrasonics[1], 8, 3);
    ultrasonicInit(&ultrasonics[2], 8, 13);
    infraredInit(&infraredSensors[0], infraredLeft, THRESHOLD);
    infraredInit(&infraredSensors[1], infraredRight, THRESHOLD);

    Serial.begin(9600);
}

// Check if either infrared sensor is detecting an edge
int isOnEdge() {
    return verifyEdge(&infraredSensors[0]) || verifyEdge(&infraredSensors[1]);
}

void detectObjects() {
    int distances[3];
    for (int i = 0; i < 3; i++)
        distances[i] = readDistance(&ultrasonics[i]);

    // If the middle sensor detects an object closer than 50 cm, move forward
    if (distances[1] < 50) {
        moveForward(&motors);
        delay(100); // Move for a short period of time
    } 
    
    else {
        // Determinate which side has the closest object (left or right)
        int minimum = (distances[0] < distances[2]) ? 0 : 2;
        if (minimum == 0) turnLeft(&motors); // Turn left if the left side is closer
        else turnRight(&motors); // Turn right if the right side is closer
    }
}

// Reset the robot's position by stopping the motors, moving backwards, and turning left
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
    // If the robot is on the edge, reset its position
    if (isOnEdge()) {
        resetPosition();
        return;
    }

    detectObjects(); // Detect objects and move accordingly
    delay(100);
}