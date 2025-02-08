#include <Arduino.h>

// Define the pins connected to the infrared sensors
#define SENSOR_LEFT_PIN A0 // Left infrared sensor
#define SENSOR_RIGHT_PIN A1  // Right infrared sensor

void setup() {
  // Configure the sensor pins as input
  pinMode(SENSOR_LEFT_PIN, INPUT); 
  pinMode(SENSOR_RIGHT_PIN, INPUT); 
  Serial.begin(9600); 
}

void loop() {
    // Read the state of the infrared sensors (0 = white, 1 = black)
    int sensorLeft = digitalRead(SENSOR_LEFT_PIN); 
    int sensorRight = digitalRead(SENSOR_RIGHT_PIN); 

    Serial.print("LEFT sensor: ");  
    Serial.println(sensorLeft);
    Serial.print("RIGHT sensor: ");
    Serial.println(sensorRight);
  
  Serial.println("---"); 
  delay(100); 
}
