#include <Arduino.h>
#include <Ultrasonic.h>

#define THRESHOLD 35 
#define ROBOT_WEIGHT 0.0
// infrared
#define SENSOR_LEFT_PIN A0
#define SENSOR_RIGHT_PIN A1
// motor
#define MOTOR_ENABLE 7
#define MOTOR_1_R 11
#define MOTOR_1_L 10
#define MOTOR_2_R 6
#define MOTOR_2_L 5
#define TENSION 0.65
// ultrasonics
#define TRIGGER_PIN 8

Ultrasonic ultrasonics[] = {
    {8, 2},
    {8, 3},
    {8, 13}
};

int ultrasonicsPins[] = {2, 3, 13};
int distances[3] = {0};

void setup() {
    pinMode(SENSOR_LEFT_PIN, INPUT);
    pinMode(SENSOR_RIGHT_PIN, INPUT);

    pinMode(MOTOR_ENABLE, OUTPUT);
    pinMode(MOTOR_1_R, OUTPUT);
    pinMode(MOTOR_1_L, OUTPUT);
    pinMode(MOTOR_2_R, OUTPUT);
    pinMode(MOTOR_2_L, OUTPUT);
    digitalWrite(MOTOR_ENABLE, LOW);

    for (   int i = 0; i < 3; i++) 
        pinMode(ultrasonicsPins[i], INPUT);
    pinMode(TRIGGER_PIN, OUTPUT);

    Serial.begin(9600);
}

void loop() {
    digitalWrite(TRIGGER_PIN, HIGH);
    for (int i = 0; i < 3; i++) {
        distances[i] = ultrasonics[i].Ranging(CM);

        Serial.print("Distance ");
        Serial.println(i);
        Serial.println(distances[i]);
        Serial.println("---");
    }
    digitalWrite(TRIGGER_PIN, LOW);

    int sensorLeftValue = analogRead(SENSOR_LEFT_PIN);
    int sensorRightValue = analogRead(SENSOR_RIGHT_PIN);    

    Serial.print("Sensor Esquerdo: ");
    Serial.println(sensorLeftValue);
    Serial.print("Sensor Direito: ");
    Serial.println(sensorRightValue);

    if(sensorLeftValue > THRESHOLD || sensorRightValue > THRESHOLD) {
        stop();
        delay(50);
        moveBackward();
        delay(100);
        turnLeft();
        delay(100);
    }
    
    else if(distances[0] > 50 && distances[1] > 50 && distances[2] > 50)
        turnRight();
    
    else if(distances[1] <= 50) {
        moveForward();
        delay(30);
    }

    else (distances[0] < distances[2]) ? turnLeft() : turnRight();
    delay(100);
}

void moveForward() {
    digitalWrite(MOTOR_ENABLE, HIGH);
    analogWrite(MOTOR_1_R, TENSION * 255);
    analogWrite(MOTOR_1_L, 0);
    analogWrite(MOTOR_2_R, TENSION * 255);
    analogWrite(MOTOR_2_L, 0);
}

void moveBackward() {
    digitalWrite(MOTOR_ENABLE, HIGH);
    analogWrite(MOTOR_1_R, 0);
    analogWrite(MOTOR_1_L, TENSION * 255);
    analogWrite(MOTOR_2_R, 0);
    analogWrite(MOTOR_2_L, TENSION * 255);
}

void turnLeft() {
    digitalWrite(MOTOR_ENABLE, HIGH);
    analogWrite(MOTOR_1_R, TENSION * 255);
    analogWrite(MOTOR_1_L, 0);
    analogWrite(MOTOR_2_R, 0);
    analogWrite(MOTOR_2_L, TENSION * 255);
}

void turnRight() {
    digitalWrite(MOTOR_ENABLE, HIGH);
    analogWrite(MOTOR_1_R, 0);
    analogWrite(MOTOR_1_L, TENSION * 255);
    analogWrite(MOTOR_2_R, TENSION * 255);
    analogWrite(MOTOR_2_L, 0);
}

void stop() {
    digitalWrite(MOTOR_ENABLE, LOW);
    analogWrite(MOTOR_1_R, 0);
    analogWrite(MOTOR_1_L, 0);
    analogWrite(MOTOR_2_R, 0);
    analogWrite(MOTOR_2_L, 0);
}