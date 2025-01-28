#include <Arduino.h>
#include "motor.h"
#include "ultrasonic.h"
#include "infrared.h"

#define THRESHOLD 35 // Edge detection threshold for infrared sensors
#define ROBOT_WEIGHT 0.0 
#define SENSOR_LEFT_PIN A0 // Pin connected to the left infrared sensor
#define SENSOR_RIGHT_PIN A1 // Pin connected to the right infrared sensor

ModuleMotor motors; 
ModuleUltrasonic ultrasonics[3]; 
ModuleInfrared infraredSensors[2];

void setup() {
    // Initialize motor and sensors with specified pins and parameters
    motorInit(&motors, 7, 11, 10, 6, 5, 0.6); 
    ultrasonicInit(&ultrasonics[0], 8, 2); 
    ultrasonicInit(&ultrasonics[1], 8, 3);
    ultrasonicInit(&ultrasonics[2], 8, 13);
    infraredInit(&infraredSensors[0], SENSOR_LEFT_PIN, THRESHOLD);
    infraredInit(&infraredSensors[1], SENSOR_RIGHT_PIN, THRESHOLD);

    Serial.begin(9600);
}

void loop() {
    int edgeDetectedRight = verifyEdge(&infraredSensors[0]);
    int edgeDetectedLeft = verifyEdge(&infraredSensors[1]);
    Serial.print("Edge detected right: ");
    Serial.println(edgeDetectedRight);
    Serial.print("Edge detected left: ");
    Serial.println(edgeDetectedLeft);

    int distances[3] = {0};

    for (int i = 0; i < 3; i++) {
        distances[i] = readDistance(&ultrasonics[i]);
        Serial.print("Distance ultrasonic ");
        Serial.print(i);
        Serial.print(": ");
        Serial.println(distances[i]);
    }

    if (edgeDetectedLeft || edgeDetectedRight) {
        stopMotor(&motors);
        delay(50);
        moveBackward(&motors);
        delay(100);
        turnLeft(&motors);
        delay(100);
    } 
    
    else if (distances[0] > 50 && distances[1] > 50 && distances[2] > 50) 
        turnRight(&motors); 

    else if (distances[1] <= 50) {
        moveForward(&motors);
        delay(30);
    } 

    else (distances[0] < distances[2]) ? turnLeft(&motors) : turnRight(&motors);
    delay(100);
}