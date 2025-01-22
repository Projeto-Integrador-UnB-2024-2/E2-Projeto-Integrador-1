#include <Arduino.h>

#define SENSOR_LEFT_PIN A0 // Pino do sensor esquerdo
#define SENSOR_RIGHT_PIN A1 // Pino do sensor direito
#define THRESHOLD 500 

void setup() {
    pinMode(SENSOR_LEFT_PIN, INPUT); 
    pinMode(SENSOR_RIGHT_PIN, INPUT); 
    Serial.begin(9600); 
}

void loop() {
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
