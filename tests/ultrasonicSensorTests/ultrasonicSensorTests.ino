// Ultrasom

#include <Ultrasonic.h>
#define TRIGGER_PIN 1
#define TRIGGER_PULSE_DURATION 20
#define ENABLE 7
#define THRESHOLD 30

// Infra
#define SENSOR_LEFT_PIN A0
#define SENSOR_RIGHT_PIN A1

int ultraSonicsPins[] = {
   2,3,13};
  int ultraPinCount = 3;

Ultrasonic ultrasonics[] = {
   {8, 2},
   {8, 3},
   {8, 13}};

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

       Serial.print("Distancia ");
       Serial.println(thisPin);
       Serial.println(distancia);
       Serial.println("---");
   }
   digitalWrite(TRIGGER_PIN, LOW);
//
   //for (int times = 0; times < 5; times++)
   //{
   //   //  Serial.print("Teste ");
   //   //  Serial.print(times);
   //    int sensorLeftValue = analogRead(SENSOR_LEFT_PIN);
   //    int sensorRightValue = analogRead(SENSOR_RIGHT_PIN);
//
   //    //Serial.print("Sensor Esquerdo: ");
   //   //  Serial.print(sensorLeftValue);
   //   //  Serial.print("\nSensor Direito: ");
   //   //  Serial.println(sensorRightValue);
//
   //   //  // Verifica o estado do sensor esquerdo
   //   //  if (sensorLeftValue < THRESHOLD)
   //   //      Serial.println("Borda detectada pelo sensor esquerdo");
   //   //  else
   //   //      Serial.println("Superficie clara detectada pelo sensor esquerdo");
//
   //   //  // Verifica o estado do sensor direito
   //   //  if (sensorRightValue < THRESHOLD)
   //   //      Serial.println("Borda detectada pelo sensor direito");
   //   //  else
   //   //      Serial.println("Superficie clara detectada pelo sensor direito");
//
   //   //Serial.println("---");
   //   delay(200);
   //}

   delay(600);
}