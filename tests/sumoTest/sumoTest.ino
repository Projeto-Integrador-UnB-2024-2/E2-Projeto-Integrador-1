#include <Arduino.h>
#include <Ultrasonic.h>
#include <stdint.h>

//#define THRESHOLD 35
#define ROBOT_WEIGHT 0.0
// infrared
#define SENSOR_LEFT_PIN A1
#define SENSOR_RIGHT_PIN A0
// motor
#define MOTOR_ENABLE 7
#define MOTOR_1_R 11
#define MOTOR_1_L 10
#define MOTOR_2_R 6
#define MOTOR_2_L 5
// ultrasonics
#define TRIGGER_PIN 8

Ultrasonic ultrasonics[] = {
    {8, 2},
    {8, 4},
    {8, 13}
};

int ultrasonicsPins[] = {2, 4, 13};
int distances[3];
int sensorLeft;
int sensorRight;

void setup() {
    pinMode(SENSOR_LEFT_PIN, INPUT);
    pinMode(SENSOR_RIGHT_PIN, INPUT);

    pinMode(MOTOR_ENABLE, OUTPUT);
    pinMode(MOTOR_1_R, OUTPUT);
    pinMode(MOTOR_1_L, OUTPUT);
    pinMode(MOTOR_2_R, OUTPUT);
    pinMode(MOTOR_2_L, OUTPUT);
    digitalWrite(MOTOR_ENABLE, LOW);

    for (int i = 0; i < 3; i++) 
        pinMode(ultrasonicsPins[i], INPUT);
    pinMode(TRIGGER_PIN, OUTPUT);

    Serial.begin(9600);
}

void loop() {
    sensorLeft = digitalRead(SENSOR_LEFT_PIN);
    sensorRight = digitalRead(SENSOR_RIGHT_PIN);

    if(sensorLeft || sensorRight) edgeFound();

    readDistances();

    while(distances[0] > 50 && distances[1] > 50 && distances[2] > 50) {
      turnRight(0.4); 
      readDistances();
    }

    while((!sensorLeft && !sensorRight) && distances[1] < 50 && distances[1] < distances[0] && distances[1] < distances[2]) {
        //sintaxe: map(valor, deMenor, deMaior, paraMenor, paraMaior);
        //float speed = map(distances[1], 50, 1, 40, 100) / 100.0; 
        //moveForward(speed);
        moveForward(0.7);

        sensorLeft = digitalRead(SENSOR_LEFT_PIN);
        sensorRight = digitalRead(SENSOR_RIGHT_PIN);

        if(sensorLeft || sensorRight) {
          edgeFound();
          return;
        }
        
        readDistances();
    }

    if (distances[0] < distances[2] && distances[2] < distances[1]) 
      turnLeft(0.4);
      
    else if (distances[2] < distances[0] && distances[0] < distances[1]) 
      turnRight(0.4);
}

void edgeFound(){
    stop();
    delay(1000);
    moveBackward(0.4);
    delay(1000);
    turnLeft(0.4);
    delay(100);
}

void readDistances() {
   digitalWrite(TRIGGER_PIN, HIGH);
    for (int i = 0; i < 3; i++) {
        distances[i] = ultrasonics[i].Ranging(CM);
        delay(1);
        Serial.print("Distance ");
        Serial.println(i);
        Serial.println(distances[i]);
        Serial.println("---");
    }
    digitalWrite(TRIGGER_PIN, LOW);
}