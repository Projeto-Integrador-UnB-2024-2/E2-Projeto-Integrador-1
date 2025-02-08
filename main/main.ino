#include <Arduino.h>
#include <Ultrasonic.h>

// Infrared Sensors (Edge Detection)
#define SENSOR_LEFT_PIN 2
#define SENSOR_RIGHT_PIN 3

// Ultrasonics Sensors (Object detection)
#define TRIGGER_PIN 8
#define ECHO_PIN_LEFT 12
#define ECHO_PIN_FRONT 4
#define ECHO_PIN_RIGHT 13

// Motor control pins
#define MOTOR_ENABLE 7
#define MOTOR_1_R 11
#define MOTOR_1_L 10
#define MOTOR_2_R 5
#define MOTOR_2_L 6

// Flag for detecting edge
volatile bool detectedEdge = false;

// Ultrasonic sensor array
int ultraSonicsPins[] = {ECHO_PIN_LEFT, ECHO_PIN_FRONT, ECHO_PIN_RIGHT};
Ultrasonic ultrasonics[] = {
  {TRIGGER_PIN, ECHO_PIN_LEFT},
  {TRIGGER_PIN, ECHO_PIN_FRONT},
  {TRIGGER_PIN, ECHO_PIN_RIGHT}
};

// Stores the distances read by the ultrasonic sensors
int distances[3] = {0, 0, 0}; // distances[0] = left, distances[1] = front, distances[2] = right

void setup() {
  // Configure infrared sensors and set up interrupts for edge detection
  pinMode(SENSOR_LEFT_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(SENSOR_LEFT_PIN), stateChange, RISING);
  pinMode(SENSOR_RIGHT_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(SENSOR_RIGHT_PIN), stateChange, RISING);

  // Configure motor control pins as output
  pinMode(MOTOR_ENABLE, OUTPUT);
  pinMode(MOTOR_1_R, OUTPUT);
  pinMode(MOTOR_1_L, OUTPUT);
  pinMode(MOTOR_2_R, OUTPUT);
  pinMode(MOTOR_2_L, OUTPUT);
  digitalWrite(MOTOR_ENABLE, LOW); 

  // Configure ultrasonic sensors
  for (int i = 0; i < 3; i++)
    pinMode(ultraSonicsPins[i], INPUT);

  pinMode(TRIGGER_PIN, OUTPUT);
  digitalWrite(TRIGGER_PIN, HIGH);

  Serial.begin(9600);
}

void loop() {
  // If the robot detects an edge, execute an escape maneuver
  if (detectedEdge) {
    Serial.print("ENCONTROU BORDA");
    edgeFound();
    detectedEdge = false;
  }

  // Read distances from ultrasonic sensors
  readDistances();

  // Print distances read
  //for (int i = 0; i < 3; i++) {
  //  Serial.print("distances ");
  //  Serial.print(i);
  //  Serial.print(": ");
  //  Serial.println(distances[i]);
  //}

  // Decision making based on the distances read
  if (distances[1] < 130 && distances[1] < distances[0] && distances[1] < distances[2]) {
    //Serial.println("---");
    //Serial.println("FRONT object detected");

    moveForward(0.3);
    //if (distances[1] > 30 && distances[1] <= 100) moveForward(0.4);
    //else if (distances[1] > 10 && distances[1] <= 30) moveForward(0.7);
    //else if (distances[1] <= 10) moveForward(1);
    //else moveForward(0.3);
  }

  else if (distances[0] < 30 && distances[0] < distances[1] && distances[0] < distances[2]) {
    //Serial.println("---");
    //Serial.println("LEFT object detected");
    while (distances[0] < distances[1]) {
      turnLeft(0.3);
      readDistances();
    }
  }

  else if (distances[2] < 30 && distances[2] < distances[1] && distances[2] < distances[0]) {
    //Serial.println("---");
    //Serial.println("RIGHT object detected");
    while (distances[2] < distances[1]) {
      turnRight(0.3);
      readDistances();
    }
  }
  
  else {
    turnRight(0.15); // If no object is detected, keep turning right to search
    //Serial.println("---");
    //Serial.println("Searching...");
  }
}

// Function to read ultrasonic sensors distances
void readDistances() {
  for (int i = 0; i < 3; i++) {
    distances[i] = ultrasonics[i].Ranging(CM);
    delay(10);

    // Assign a default value if the sensor fails
    if(distances[i] == 0) distances[i] = 150;
    Serial.print("distances ");
    Serial.println(i);
    Serial.println(distances[i]);
    Serial.println("---");
  }
}

// Interrupt function triggered when an edge is detected
void stateChange() {
  detectedEdge = true;
}

// Edge avoidance maneuver: move backward and turn
void edgeFound() {
  moveBackward(0.4);
  delay(2000);
  turnRight(0.3);
  delay(500);
  distances[0] = 0;
  distances[1] = 0;
  distances[2] = 0;
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

void turnRight(float tension) {
  digitalWrite(MOTOR_ENABLE, HIGH);
  analogWrite(MOTOR_1_R, tension * 255);
  analogWrite(MOTOR_1_L, 0);
  analogWrite(MOTOR_2_R, 0);
  analogWrite(MOTOR_2_L, tension * 255);
}

void turnLeft(float tension) {
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