#include <Ultrasonic.h>
// Leitura de Distância com o Sensor HC-SR04.

// O nome do sensor é ultrassom, o pino do trig está conectado na porta 8 e o pino do echo na porta 7.
Ultrasonic ultrassom(8,7);

long distancia;

// setup roda uma vez quando a placa é ligada ou resetada.
void setup() {
  Serial.begin(9600); // Habilita comunicação Serial a uma taxa de 9600 bauds.
}

// loop se repete infinitamente quando a placa é ligada.
void loop() {
  // ultrassom.Ranging(CM) retorna a distancia em centímetros(CM) ou polegadas(INC).
  distancia = ultrassom.Ranging(CM);

  Serial.print(distancia); // Imprime o valor da variável distancia.
  Serial.println("cm");
  delay(100);
}