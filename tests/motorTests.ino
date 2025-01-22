// --- Mapeamento de Hardware ---
#define R_En1 11  // Enable da Ponte H 1 no pino 11
#define L_En1 10  // Enable da Ponte H 1 no pino 10
#define RPWM1 6  // RPWM1 Pino 6
#define LPWM1 5  // LPWM1 Pino 5

// --- Configurações iniciais ---
void setup() {

  //Definição dos pinos de saída
  pinMode(R_En1, OUTPUT);
  pinMode(L_En1, OUTPUT);
  pinMode(RPWM1, OUTPUT);
  pinMode(LPWM1, OUTPUT);

  //Habilitando os motores
  digitalWrite(R_En1, HIGH);
  digitalWrite(L_En1, HIGH);
}
void loop() {
  //Programa para ficar alternando a tensão, entre 12V e -12V
  digitalWrite(RPWM1, 0);
  analogWrite(LPWM1, 255);
  delay(1000);
  analogWrite(RPWM1, 255);
  digitalWrite(LPWM1, 0);
  delay(1000);
}