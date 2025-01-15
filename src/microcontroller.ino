// #include "motor.h"

// float robotWeight = 0.0;
// Motor motors[2];

// void setup() {
//     motorInit(&motors[0], 2, 3, 4, 5, 5.0, true);
//     motorInit(&motors[1], 6, 7, 8, 9, 5.0, true);

//     stopMotor(&motors[0]);
//     stopMotor(&motors[1]);
// }

// void loop() {
//     moveForward(&motors[0]);
//     moveForward(&motors[1]);
//     delay(1000);

//     stopMotor(&motors[0]);
//     stopMotor(&motors[1]);
//     delay(1000);

//     moveBackward(&motors[0]);
//     moveBackward(&motors[1]);
//     delay(1000);

//     stopMotor(&motors[0]);
//     stopMotor(&motors[1]);
//     delay(1000);

//     turnLeft(&motors[0]);
//     turnRight(&motors[1]);
//     delay(1000);

//     stopMotor(&motors[0]);
//     stopMotor(&motors[1]);
//     delay(1000);
// }

#include <Arduino.h>
#include <Ultrasonic.h>

// Ultrasom
#define TRIGGER_PIN 1
#define TRIGGER_PULSE_DURATION 20
#define ENABLE 7

// Infra
#define SENSOR_LEFT_PIN 19
#define SENSOR_RIGHT_PIN 20

int ultraSonicsPins[] = {
    13, 14, 15} int ultraPinCount = 3;

Ultrasonic ultrasonics[] = {
    {1, 13},
    {1, 14},
    {1, 15}}

long distancia;

void setup()
{
    pinMode(SENSOR_LEFT_PIN, INPUT);
    pinMode(SENSOR_RIGHT_PIN, INPUT);

    for (int thisPin = 0; thisPin < ultraPinCount; thisPin++)
        pinMode(ultraSonicsPins[thisPin], INPUT);

    pinMode(TRIGGER_PIN, OUTPUT);

    Serial.begin(9600);
}

void loop()
{

    digitalWrite(TRIGGER_PIN, HIGH);
    for (int thisPin = 0; thisPin < ultraPinCount; thisPin++)
    {
        distancia = ultrasonics[thisPin].Ranging(CM);

        Serial.print("Distancia %d: %ld", thisPin, distancia);
    }
    digitalWrite(TRIGGER_PIN, LOW);

    delay(2000);

    for (int times = 0; times < 5; times++)
    {
        Serial.print("Teste %d:\n", times);
        int sensorLeftValue = analogRead(SENSOR_LEFT_PIN);
        int sensorRightValue = analogRead(SENSOR_RIGHT_PIN);

        Serial.print("Sensor Esquerdo: ");
        Serial.print(sensorLeftValue);
        Serial.print("\nSensor Direito: ");
        Serial.println(sensorRightValue);

        // Verifica o estado do sensor esquerdo
        if (sensorLeftValue < THRESHOLD)
            Serial.println("Borda detectada pelo sensor esquerdo");
        else
            Serial.println("Superficie clara detectada pelo sensor esquerdo");

        // Verifica o estado do sensor direito
        if (sensorRightValue < THRESHOLD)
            Serial.println("Borda detectada pelo sensor direito");
        else
            Serial.println("Superficie clara detectada pelo sensor direito");

        Serial.println("---");
        delay(200);
    }

    delay(500);
}