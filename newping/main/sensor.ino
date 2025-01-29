int pingEsq() // This function takes the value of the distance from the library of the ultrasonic sensors
{
  int cmi = esq.ping_cm(); // Left Ping Sensor
  if (cmi <= 0)
  {
    cmi = PING;
  }
  return cmi;
}

int pingDir() // Right Ping Sensor
{
  int cmd = dir.ping_cm();
  if (cmd <= 0)
  {
    cmd = PING;
  }
  return cmd;
}

int pingFront() // Center Ping Sensor
{
  int cmc = front.ping_cm();
  if (cmc <= 0)
  {
    cmc = PING;
  }
  return cmc;
} 

int linhaDirIR() // Line Sensor Right
{
  int sensorValue = analogRead(A1);
  return sensorValue;
}

int linhaEsqIR() // Line Sensor Left
{
  int sensorValue = analogRead(A0);
  return sensorValue;
}

// movimentação do robo

void frente(int motor)
{
  digitalWrite(motorB_Dir, HIGH);             // Direction : Forward
  analogWrite(motorB_Pwm, 255 - motor); // motor : PWM
  digitalWrite(motorA_Dir, HIGH);             // Direction : Forward
  analogWrite(motorA_Pwm, 255 - motor); // motor : PWM
}

void direita(int motor)
{
  digitalWrite(motorB_Dir, HIGH);             // Direction : Forward
  analogWrite(motorB_Pwm, 255 - motor); // motor : PWM
  digitalWrite(motorA_Dir, LOW);              // Direction : Backward
  analogWrite(motorA_Pwm, motor);       // motor : PWM
}

void esquerda(int motor)
{
  digitalWrite(motorB_Dir, LOW);              // Direction : Backward
  analogWrite(motorB_Pwm, motor);       // motor : PWM
  digitalWrite(motorA_Dir, HIGH);             // Direction : Forward
  analogWrite(motorA_Pwm, 255 - motor); // motor : PWM
}

void re(int motor)
{
  digitalWrite(motorB_Dir, LOW);        // Direction : Backward
  analogWrite(motorB_Pwm, motor); // motor : PWM
  digitalWrite(motorA_Dir, LOW);        // Direction : Backward
  analogWrite(motorA_Pwm, motor); // motor : PWM
}

void parar()
{
  digitalWrite(motorB_Dir, LOW);
  digitalWrite(motorB_Pwm, LOW);
  digitalWrite(motorA_Dir, LOW);
  digitalWrite(motorA_Pwm, LOW);
}