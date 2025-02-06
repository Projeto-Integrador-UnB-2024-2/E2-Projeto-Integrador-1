// Ultrasom

#include <Ultrasonic.h>
#define TRIGGER_PIN 8
#define ENABLE 7

// Infra
#define SENSOR_LEFT_PIN A0
#define SENSOR_RIGHT_PIN A1

// Motor
#define MOTOR_ENABLE 7
#define MOTOR_1_R 11
#define MOTOR_1_L 10
#define MOTOR_2_R 6
#define MOTOR_2_L 5

int ultraSonicsPins[] = {
   12,4,13};
  int ultraPinCount = 3;

Ultrasonic ultrasonics[] = {
   {8, 12},
   {8, 4},
   {8, 13}};

int distancia[3];

void setup()
{
   pinMode(SENSOR_LEFT_PIN, INPUT);
   pinMode(SENSOR_RIGHT_PIN, INPUT);
   pinMode(MOTOR_ENABLE, OUTPUT);
    pinMode(MOTOR_1_R, OUTPUT);
    pinMode(MOTOR_1_L, OUTPUT);
    pinMode(MOTOR_2_R, OUTPUT);
    pinMode(MOTOR_2_L, OUTPUT);
    digitalWrite(MOTOR_ENABLE, LOW);

   for (int thisPin = 0; thisPin < ultraPinCount; thisPin++)
       pinMode(ultraSonicsPins[thisPin], INPUT);

   pinMode(TRIGGER_PIN, OUTPUT);
   digitalWrite(TRIGGER_PIN, HIGH);

   Serial.begin(9600);
}

void loop() {
   for (int thisPin = 0; thisPin < ultraPinCount; thisPin++)
   {
       distancia[thisPin] = ultrasonics[thisPin].Ranging(CM);
       delay(3);

       Serial.print("Distancia ");
       Serial.println(thisPin);
       Serial.println(distancia[thisPin]);
       Serial.println("---");
   }

  if(distancia[1] < 15 && distancia[1] < distancia[0] && distancia[1] < distancia[2]) {
    moveForward(0.4);
  } else if(distancia[0] < 15 && distancia[0] < distancia[1] && distancia[0] < distancia[2]) {
    turnLeft(0.4);
  } else if(distancia[2] < 15 && distancia[2] < distancia[0] && distancia[2] < distancia[1]) {
    turnRight(0.4);
  } else {
    turnRight(0.4);
  }
}

void moveForward(float tension) {
    digitalWrite(MOTOR_ENABLE, HIGH);
    analogWrite(MOTOR_1_R, tension * 255);
    analogWrite(MOTOR_1_L, 0);
    analogWrite(MOTOR_2_R, tension * 255);
    analogWrite(MOTOR_2_L, 0);
}

void moveBackward(float tension) {
    digitalWrite(MOTOR_ENABLE, HIGH);
    analogWrite(MOTOR_1_R, 0);
    analogWrite(MOTOR_1_L, tension * 255);
    analogWrite(MOTOR_2_R, 0);
    analogWrite(MOTOR_2_L, tension * 255);
}

void turnLeft(float tension) {
    digitalWrite(MOTOR_ENABLE, HIGH);
    analogWrite(MOTOR_1_R, tension * 255);
    analogWrite(MOTOR_1_L, 0);
    analogWrite(MOTOR_2_R, 0);
    analogWrite(MOTOR_2_L, tension * 255);
}

void turnRight(float tension) {
    digitalWrite(MOTOR_ENABLE, HIGH);
    analogWrite(MOTOR_1_R, 0);
    analogWrite(MOTOR_1_L, tension * 255);
    analogWrite(MOTOR_2_R, tension * 255);
    analogWrite(MOTOR_2_L, 0);
}

void stop() {
    digitalWrite(MOTOR_ENABLE, LOW);
    analogWrite(MOTOR_1_R, 0);
    analogWrite(MOTOR_1_L, 0);
    analogWrite(MOTOR_2_R, 0);
    analogWrite(MOTOR_2_L, 0);
}




