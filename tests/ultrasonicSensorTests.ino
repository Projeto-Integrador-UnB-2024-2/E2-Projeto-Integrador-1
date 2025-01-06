#include <Ultrasonic.h>

#define TRIGGER_PIN 8
#define ECHO_PIN 7
#define TRIGGER_PULSE_DURATION 20 

Ultrasonic ultrassom(TRIGGER_PIN, ECHO_PIN);

long distancia;

// setup roda uma vez quando a placa e ligada ou resetada.
void setup() {
	pinMode(TRIGGER_PIN, OUTPUT); // Define o pino TRIGGER como saida.
	pinMode(ECHO_PIN, INPUT);  // Define o pino ECHO como entrada.
	Serial.begin(9600); 
}

// loop se repete infinitamente quando a placa e ligada.
void loop() {
  	// Configuracao manual do trigger
  	digitalWrite(TRIGGER_PIN, LOW);
  	delayMicroseconds(2);
  	digitalWrite(TRIGGER_PIN, HIGH);
  	delayMicroseconds(TRIGGER_PULSE_DURATION);
  	digitalWrite(TRIGGER_PIN, LOW);

  	// ultrassom.Ranging(CM) retorna a distancia em centimetros(CM) ou polegadas(INC).
  	distancia = ultrassom.Ranging(CM);

	if (distancia > 0 && distancia <= 400) {
    	Serial.print("Distancia: ");
    	Serial.print(distancia);
    	Serial.println(" cm");
  	} 
  
	else Serial.println("Fora do alcance");
  	delay(100);
}