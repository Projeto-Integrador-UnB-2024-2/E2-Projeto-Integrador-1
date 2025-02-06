// Ultrasom

#include <Ultrasonic.h>
#define TRIGGER_PIN 8
#define ENABLE 7

// Infra
#define SENSOR_LEFT_PIN A0
#define SENSOR_RIGHT_PIN A1

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
}




