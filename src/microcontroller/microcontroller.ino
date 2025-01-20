#include <Arduino.h>
#include <stdio.h>
#include "src/motor.h"


typedef struct {
    uint8_t rightMotorEnable;
    uint8_t leftMotorEnable;
    uint8_t rightMotorPWMF;
    uint8_t leftMotorPWMF;
    uint8_t rightMotorPWMB;
    uint8_t leftMotorPWMB;
    float tension;
} ModuleMotor;

void motorInit(ModuleMotor *motor, uint8_t rightMotorEnable, uint8_t leftMotorEnable, 
uint8_t rightMotorPWMF, uint8_t leftMotorPWMF, uint8_t rightMotorPWMB, uint8_t leftMotorPWMB, bool tension) {
    motor->rightMotorEnable = rightMotorEnable;
    motor->leftMotorEnable = leftMotorEnable;
    motor->rightMotorPWMF = rightMotorPWMF;
    motor->leftMotorPWMF = leftMotorPWMF;
    motor->rightMotorPWMB = rightMotorPWMB;
    motor->leftMotorPWMB = leftMotorPWMB;
    motor->tension = tension;

    pinMode(motor->rightMotorEnable, OUTPUT);
    pinMode(motor->leftMotorEnable, OUTPUT);
    pinMode(motor->rightMotorPWMF, OUTPUT);
    pinMode(motor->rightMotorPWMB, OUTPUT);
    pinMode(motor->leftMotorPWMF, OUTPUT);
    pinMode(motor->leftMotorPWMB, OUTPUT);

    stopMotor(motor);
}

void moveForward(ModuleMotor *motor) {
    digitalWrite(motor->rightMotorEnable, HIGH);
    digitalWrite(motor->leftMotorEnable, HIGH);

    analogWrite(motor->rightMotorPWMF, motor->tension * 255);
    analogWrite(motor->leftMotorPWMF, motor->tension * 255);
}

void moveBackward(ModuleMotor *motor) {
    digitalWrite(motor->rightMotorEnable, HIGH);
    digitalWrite(motor->leftMotorEnable, HIGH);

    analogWrite(motor->rightMotorPWMB, motor->tension * 255);
    analogWrite(motor->leftMotorPWMB, motor->tension * 255);
}

void turnLeft(ModuleMotor *motor) {
    digitalWrite(motor->rightMotorEnable, HIGH);
    digitalWrite(motor->leftMotorEnable, HIGH);

    analogWrite(motor->leftMotorPWMF, motor->tension * 255);
    analogWrite(motor->rightMotorPWMB, motor->tension * 255);
}

void turnRight(ModuleMotor *motor) {
    digitalWrite(motor->rightMotorEnable, HIGH);
    digitalWrite(motor->leftMotorEnable, HIGH);

    analogWrite(motor->rightMotorPWMF, motor->tension * 255);
    analogWrite(motor->leftMotorPWMB, motor->tension * 255);
}

void stopMotor(ModuleMotor *motor) {
    digitalWrite(motor->rightMotorEnable, LOW);
    digitalWrite(motor->leftMotorEnable, LOW);

    analogWrite(motor->rightMotorPWMF, 0);
    analogWrite(motor->rightMotorPWMB, 0);
    analogWrite(motor->leftMotorPWMF, 0);
    analogWrite(motor->leftMotorPWMB, 0);
}

void debugMotorState(ModuleMotor *motor) {
    Serial.print("Tension: ");
    Serial.println(motor->tension);
    Serial.print("Right Direction: ");
    Serial.println(motor->rightMotorPWMB ? "Forward" : "Backward");
    Serial.print("Left Direction: ");
    Serial.println(motor->leftMotorPWMB ? "Forward" : "Backward");
}

float robotWeight = 0.0;
ModuleMotor motors;
void setup() {
    // motor,          rEN, leftEn, motor1PWMF, motor2PWMF, motor1PWMB, motor2PWMB, tension
    motorInit(&motors, 7, 7, 11, 6, 10, 5, 0);
    // r
}

void loop() {
    motors.tension = 0.7;
    debugMotorState(&motors);
    moveForward(&motors);
    delay(2000);
    stopMotor(&motors);
    delay(2000);
    moveBackward(&motors);
    delay(2000);
    stopMotor(&motors);
    delay(2000);
    turnLeft(&motors);
    delay(2000);
    stopMotor(&motors);
    delay(2000);
    turnRight(&motors);
    delay(2000);
}

//// Ultrasom
//#define TRIGGER_PIN 1
//#define TRIGGER_PULSE_DURATION 20
//#define ENABLE 7
//
//// Infra
//#define SENSOR_LEFT_PIN 19
//#define SENSOR_RIGHT_PIN 20
//
//int ultraSonicsPins[] = {
//    13, 14, 15} int ultraPinCount = 3;
//
//Ultrasonic ultrasonics[] = {
//    {1, 13},
//    {1, 14},
//    {1, 15}}
//
//long distancia;
//
//void setup()
//{
//    pinMode(SENSOR_LEFT_PIN, INPUT);
//    pinMode(SENSOR_RIGHT_PIN, INPUT);
//
//    for (int thisPin = 0; thisPin < ultraPinCount; thisPin++)
//        pinMode(ultraSonicsPins[thisPin], INPUT);
//
//    pinMode(TRIGGER_PIN, OUTPUT);
//
//    Serial.begin(9600);
//}
//
//void loop()
//{
//
//    digitalWrite(TRIGGER_PIN, HIGH);
//    for (int thisPin = 0; thisPin < ultraPinCount; thisPin++)
//    {
//        distancia = ultrasonics[thisPin].Ranging(CM);
//
//        Serial.print("Distancia %d: %ld", thisPin, distancia);
//    }
//    digitalWrite(TRIGGER_PIN, LOW);
//
//    delay(2000);
//
//    for (int times = 0; times < 5; times++)
//    {
//        Serial.print("Teste %d:\n", times);
//        int sensorLeftValue = analogRead(SENSOR_LEFT_PIN);
//        int sensorRightValue = analogRead(SENSOR_RIGHT_PIN);
//
//        Serial.print("Sensor Esquerdo: ");
//        Serial.print(sensorLeftValue);
//        Serial.print("\nSensor Direito: ");
//        Serial.println(sensorRightValue);
//
//        // Verifica o estado do sensor esquerdo
//        if (sensorLeftValue < THRESHOLD)
//            Serial.println("Borda detectada pelo sensor esquerdo");
//        else
//            Serial.println("Superficie clara detectada pelo sensor esquerdo");
//
//        // Verifica o estado do sensor direito
//        if (sensorRightValue < THRESHOLD)
//            Serial.println("Borda detectada pelo sensor direito");
//        else
//            Serial.println("Superficie clara detectada pelo sensor direito");
//
//        Serial.println("---");
//        delay(200);
//    }
//
//    delay(500);
//}