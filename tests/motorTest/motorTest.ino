// Define motor control pins
#define MOTOR_1_R 11 // Right direction for motor 1 (forward)
#define MOTOR_1_L 10  // Left direction for motor 1 (backward)
#define MOTOR_2_R 5 // Right direction for motor 2 (forward)
#define MOTOR_2_L 6 // Left direction for motor 2 (backward)
#define MOTOR_ENABLE 7 // Enable motor control  

void setup() {
  // Set motor control pins as output
  pinMode(MOTOR_ENABLE, OUTPUT);
  //pinMode(MOTOR_1_L, OUTPUT);s
  pinMode(MOTOR_1_R, OUTPUT);
  //pinMode(MOTOR_2_L, OUTPUT);
  pinMode(MOTOR_2_R, OUTPUT);
  digitalWrite(MOTOR_ENABLE, HIGH);
}
void loop() {
  // Move forward: both motors forward
  moveForward(1);
  
  //analogWrite(MOTOR_2_R, 255);
  //analogWrite(MOTOR_2_L, 0);
  //delay(1000);
//
  //// Move backward: both motors backward
  //analogWrite(MOTOR_1_R, 0);
  //analogWrite(MOTOR_1_L, 255);
  //analogWrite(MOTOR_2_R, 0);
  //analogWrite(MOTOR_2_L, 255);
  //delay(1000);
//
  //// Turn right: motor 1 forward, motor 2 backward
  //analogWrite(MOTOR_1_R, 255);
  //analogWrite(MOTOR_1_L, 0);
  //analogWrite(MOTOR_2_R, 0);
  //analogWrite(MOTOR_2_L, 255);
  //delay(1000);
//
  //// Turn left: motor 1 backward, motor 2 forward
  //analogWrite(MOTOR_1_R, 0);
  //analogWrite(MOTOR_1_L, 255);
  //analogWrite(MOTOR_2_R, 255);
  //analogWrite(MOTOR_2_L, 0);
  //delay(1000);
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