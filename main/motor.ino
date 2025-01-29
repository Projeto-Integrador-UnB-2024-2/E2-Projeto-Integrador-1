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