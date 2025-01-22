#include <Arduino.h>
#include "motor.h"
#include "ultrasonic.h"
#include "infrared.h"

#define THRESHOLD 30// Valor limite para deteccao da borda
#define TRIGGER_PULSE_DURATION 20 // Duracao do pulso de trigger
#define ROBOT_WEIGHT 0.0 

#define SENSOR_LEFT_PIN A0 // Pino do sensor esquerdo
#define SENSOR_RIGHT_PIN A1 // Pino do sensor direito

ModuleMotor motors;
ModuleUltrasonic ultrasonics[3];
ModuleInfrared infraredSensors[2];

void setup() {
    int sensorLeftValue = analogRead(SENSOR_LEFT_PIN); 
    int sensorRightValue = analogRead(SENSOR_RIGHT_PIN); 

    motorInit(&motors, 7, 11, 6, 10, 5, 0.7);
    ultrasonicInit(&ultrasonics[0], 8, 2);
    ultrasonicInit(&ultrasonics[1], 8, 3);
    ultrasonicInit(&ultrasonics[2], 8, 13);
    infraredInit(&infraredSensors[0], sensorLeftValue, THRESHOLD);
    infraredInit(&infraredSensors[1], sensorRightValue, THRESHOLD);

    Serial.begin(9600);
}

int isOnEdge() {
    return verifyEdge(&infraredSensors[0]) || verifyEdge(&infraredSensors[1]);
}

void loop() {
   int distances[3];
    int minimun = 999, index = -1, i;

    for (int i = 0; i < 3; i++) {
        distances[i] = readDistance(&ultrasonics[i]);
        if (distances[i] < minimun) {
            minimun = distances[i];
            index = i;
        }
    }

    
    if (index != -1 && distances[index] < 400) { // Objeto detectado a menos de 50 cm

        // Alinha com o objeto
        if (index == 0) turnLeft(&motors);
        else if (index == 2) turnRight(&motors);
        delay(500);

        // Aproxima-se do objeto
        moveForward(&motors);
        while (readDistance(&ultrasonics[index]) > 10) {
            if (isOnEdge()) {
                stopMotor(&motors);
                break; // Evita sair da arena
            }
        }
        stopMotor(&motors);

        // Empurra o objeto
        moveForward(&motors);
        while (!isOnEdge()) {
            delay(600); // Continua empurrando enquanto não está na borda
        }
        stopMotor(&motors);
    } 
    
    else {
        // Caso nenhum objeto seja detectado, o robô busca girando
        turnLeft(&motors);
        delay(600);
        stopMotor(&motors);
    } 
 delay(100);   
}

// long distancia;

// void loop()
// {

//     digitalWrite(TRIGGER_PIN, HIGH);
//     for (int thisPin = 0; thisPin < ultraPinCount; thisPin++)
//     {
//         distancia = ultrasonics[thisPin].Ranging(CM);

//         Serial.print("Distancia %d: %ld", thisPin, distancia);
//     }
//     digitalWrite(TRIGGER_PIN, LOW);

//     delay(2000);

//     for (int times = 0; times < 5; times++)
//     {
//         Serial.print("Teste %d:\n", times);
//         int sensorLeftValue = analogRead(SENSOR_LEFT_PIN);
//         int sensorRightValue = analogRead(SENSOR_RIGHT_PIN);

//         Serial.print("Sensor Esquerdo: ");
//         Serial.print(sensorLeftValue);
//         Serial.print("\nSensor Direito: ");
//         Serial.println(sensorRightValue);

//         // Verifica o estado do sensor esquerdo
//         if (sensorLeftValue < THRESHOLD)
//             Serial.println("Borda detectada pelo sensor esquerdo");
//         else
//             Serial.println("Superficie clara detectada pelo sensor esquerdo");

//         // Verifica o estado do sensor direito
//         if (sensorRightValue < THRESHOLD)
//             Serial.println("Borda detectada pelo sensor direito");
//         else
//             Serial.println("Superficie clara detectada pelo sensor direito");

//         Serial.println("---");
//         delay(200);
//     }

//     delay(500);
// }








//// Configuração dos sensores e motores
//#define TRIGGER_PIN 8
//#define TRIGGER_PULSE_DURATION 20
//#define SENSOR_LEFT_PIN 19
//#define SENSOR_RIGHT_PIN 20
//#define THRESHOLD 500 // Valor limite para detecção da borda
//#define ULTRASONIC_COUNT 3
//
////ModuleUltrasonic ultrasonics[3] = {{1, 13}, {1, 14}, {1, 15}};
//int ultraSonicsPins[ULTRASONIC_COUNT] = {13, 14, 15};
//
//// Estrutura para o sensor ultrassônico
//typedef struct {
//    int triggerPin;
//    int echoPin;
//} Ultrasonic;
//
//Ultrasonic ultrasonics[ULTRASONIC_COUNT] = {
//    {TRIGGER_PIN, 13},
//    {TRIGGER_PIN, 14},
//    {TRIGGER_PIN, 15}
//};
//
//ModuleMotor motors;
//long distances[ULTRASONIC_COUNT];
//
//// Função para inicializar o sensor ultrassônico
//void ultrasonicInit(Ultrasonic *sensor) {
//    pinMode(sensor->triggerPin, OUTPUT);
//    pinMode(sensor->echoPin, INPUT);
//}
//
//// Função para medir a distância com o sensor ultrassônico
//long measureDistance(Ultrasonic *sensor) {
//    digitalWrite(sensor->triggerPin, LOW);
//    delayMicroseconds(2);
//    digitalWrite(sensor->triggerPin, HIGH);
//    delayMicroseconds(TRIGGER_PULSE_DURATION);
//    digitalWrite(sensor->triggerPin, LOW);
//
//    long duration = pulseIn(sensor->echoPin, HIGH);
//    long distance = duration * 0.034 / 2; // Conversão para centímetros
//    return distance;
//}
//
//// Função para detectar o objeto mais próximo
//int detectClosestObject() {
//    int closestIndex = -1;
//    long minDistance = 9999;
//
//    for (int i = 0; i < ULTRASONIC_COUNT; i++) {
//        distances[i] = measureDistance(&ultrasonics[i]);
//        if (distances[i] < minDistance) {
//            minDistance = distances[i];
//            closestIndex = i;
//        }
//    }
//
//    return closestIndex;
//}
//
//// Função para verificar se está na borda da arena
//int isOnEdge() {
//    int leftValue = analogRead(SENSOR_LEFT_PIN);
//    int rightValue = analogRead(SENSOR_RIGHT_PIN);
//    return (leftValue < THRESHOLD || rightValue < THRESHOLD);
//}
//
//// Função principal
//void setup() {
//    // Inicialização dos motores
//    motorInit(&motors, 7, 11, 6, 10, 5, 0);
//
//    // Inicialização dos sensores ultrassônicos
//    for (int i = 0; i < ULTRASONIC_COUNT; i++) {
//        ultrasonicInit(&ultrasonics[i]);
//    }
//
//    // Configuração dos sensores infravermelhos
//    pinMode(SENSOR_LEFT_PIN, INPUT);
//    pinMode(SENSOR_RIGHT_PIN, INPUT);
//
//    Serial.begin(9600);
//}
//
//void loop() {
//    int closestObject = detectClosestObject();
//
//    if (closestObject != -1 && distances[closestObject] < 50) { // Objeto detectado a menos de 50 cm
//        Serial.print("Objeto detectado pelo sensor: ");
//        Serial.println(closestObject);
//
//        // Alinha com o objeto
//        if (closestObject == 0) {
//            turnLeft(&motors);
//        } else if (closestObject == 2) {
//            turnRight(&motors);
//        }
//        delay(500);
//
//        // Aproxima-se do objeto
//        moveForward(&motors);
//        while (measureDistance(&ultrasonics[closestObject]) > 10) {
//            if (isOnEdge()) {
//                stopMotor(&motors);
//                return; // Evita sair da arena
//            }
//        }
//        stopMotor(&motors);
//
//        // Empurra o objeto
//        moveForward(&motors);
//        while (!isOnEdge()) {
//            delay(100); // Continua empurrando enquanto não está na borda
//        }
//        stopMotor(&motors);
//    } else {
//        // Caso nenhum objeto seja detectado, o robô busca girando
//        turnLeft(&motors);
//        delay(1000);
//        stopMotor(&motors);
//    }
//
//    delay(500); // Pequena pausa antes de reiniciar o loop
//}