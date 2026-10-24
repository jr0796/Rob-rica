
#include <Servo.h>

Servo esquerda;
Servo direita;
Servo base;
Servo garra;

// Joystick 1
const int eixoX1 = A0;
const int eixoY1 = A1;

// Joystick 2
const int eixoX2 = A2;
const int eixoY2 = A3;

// Pinos dos servos
const int pinoEsquerda = 2;
const int pinoDireita = 3;
const int pinoGarra = 4;
const int pinoBase = 5;

// Calibragem
const int centro = 512;
const int zonaMorta = 250;
const int pontoParada = 90;

// Converte o joystick em comando de rotação
int calcularComando(int leitura) {
  if (abs(leitura - centro) <= zonaMorta) {
    return pontoParada;
  }

  if (leitura < centro - zonaMorta) {
    return map(leitura, 0, centro - zonaMorta,
               0, pontoParada - 1);
  }

  return map(leitura, centro + zonaMorta, 1023,
             pontoParada + 1, 180);
}

void setup() {
  Serial.begin(9600);

  esquerda.attach(pinoEsquerda);
  direita.attach(pinoDireita);
  base.attach(pinoBase);
  garra.attach(pinoGarra);

  // Comandos iniciais de parada
  esquerda.write(pontoParada);
  direita.write(pontoParada);
  base.write(pontoParada);
  garra.write(pontoParada);

  delay(1000);
}

void loop() {
  // Leituras dos dois joysticks
  int x1 = analogRead(eixoX1);
  int y1 = analogRead(eixoY1);

  int x2 = analogRead(eixoX2);
  int y2 = analogRead(eixoY2);

  // Joystick 1: esquerda e direita
  esquerda.write(calcularComando(x1));
  direita.write(calcularComando(y1));

  // Joystick 2: base e garra
  base.write(calcularComando(x2));
  garra.write(calcularComando(y2));

  // Monitor Serial
  Serial.print("Esquerda: ");
  Serial.print(x1);
  Serial.print(" | Direita: ");
  Serial.print(y1);

  Serial.print(" || Base: ");
  Serial.print(x2);
  Serial.print(" | Garra: ");
  Serial.println(y2);

  delay(20);
}
