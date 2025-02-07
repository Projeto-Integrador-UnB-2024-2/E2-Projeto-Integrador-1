#include <Ultrasonic.h>

// Define the pins for the ultrasonic sensors 
#define TRIGGER_PIN 8 // Trigger pin for all sensors
#define ECHO_PIN_LEFT 12 // Echo pin for the left sensor
#define ECHO_PIN_CENTER 4 // Echo pin for the center sensor
#define ECHO_PIN_RIGHT 13 // Echo pin for the right sensor

// Create an array of ultrasonic sensors objects
Ultrasonic ultrasonics[] = {
    {TRIGGER_PIN, ECHO_PIN_LEFT},
    {TRIGGER_PIN, ECHO_PIN_CENTER},
    {TRIGGER_PIN, ECHO_PIN_RIGHT}
};

// Array to store echo pin numbers for input configuration
int ultraSonicsPins[] = {ECHO_PIN_LEFT, ECHO_PIN_CENTER, ECHO_PIN_RIGHT};

// Array to store measured distances from each sensor
int distances[3];

void setup() {
   // Configure the echo pins as input
   for (int i = 0; i < 3; i++)
      pinMode(ultraSonicsPins[i], INPUT);

   // Set the trigger pin as output and initialize it as HIGH
   pinMode(TRIGGER_PIN, OUTPUT);
   digitalWrite(TRIGGER_PIN, HIGH);

   Serial.begin(9600);
}

void loop() {
   // Measure the distance from each sensor
   for (int i = 0; i < 3; i++) {
      distances[i] = ultrasonics[i].Ranging(CM); // Get measured distance in cm
      delay(3); // Small delay to avoid interference
      Serial.print("distances ");
      Serial.println(i);
      Serial.println(distances[i]);
      Serial.println("---");
   }
}