#include <NewPing.h>
#define PING 50
NewPing esq(8, 2, PING);
NewPing front(8, 4, PING);
NewPing dir(8, 13, PING);

#define rightPwmA 11 // motor lado direito
#define leftPwmA 10  // motor lado direito
#define rightPwmB 6  // motor lado esquerdo
#define leftPwmB 5   // motor lado esquerdo

#define motorA_Pwm rightPwmA // Motor A PWM Speed
#define motorA_Dir leftPwmA  // Motor A Direction
#define motorB_Pwm rightPwmB // Motor B Direction
#define motorB_Dir leftPwmB  // Motor B PWM Speed

int front_dist = 0;
int esq_dist = 0;
int dir_dist = 0;

int linhaDir;
int linhaEsq;

void setup()
{
  pinMode(motorA_Dir, OUTPUT); //motor A
  pinMode(motorA_Pwm, OUTPUT);
  digitalWrite(motorA_Dir, LOW);
  digitalWrite(motorA_Pwm, LOW);

  pinMode(motorB_Dir, OUTPUT); //motor B
  pinMode(motorB_Pwm, OUTPUT);
  digitalWrite(motorB_Dir, LOW);
  digitalWrite(motorB_Pwm, LOW);

  Serial.begin(9600);

  delay(100);
}

void loop()
{
  esq_dist = pingEsq();
  dir_dist = pingDir();
  front_dist = pingFront();

  linhaDir = linhaDirIR(); //infra direito
  linhaEsq = linhaEsqIR(); //infra esquerdo

  if (front_dist <= 50)
  {
    Serial.print("front --- ");
    Serial.println(front_dist);
    frente(250);
    delay(100);
  }
  else
  {
    if ((esq_dist < front_dist) && (esq_dist < dir_dist))
    {
      esquerda(250);
    }
    if ((dir_dist < front_dist) && (dir_dist < esq_dist)){
      direita(250);
    }
  }

  if ((linhaDir < 40) || (linhaEsq < 40)){
    re(200);
    delay(100);
    esquerda(250);
    // Serial.print("Dir");
    // Serial.println(linhaDir);
    // Serial.print("Esq --- ");
    // Serial.println(linhaEsq);
    delay(100);
  }
}