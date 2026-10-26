
#include <LiquidCrystal.h>

// LCD: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Sensor de umidade do solo
const int sensorUmidade = A0;

// Buzzer
const int buzzer = 8;

// Limites de umidade (ajustar conforme o sensor)
const int limiteUmido = 400;
const int limiteSeco = 600;

// Controle dos avisos sonoros
unsigned long tempoAnterior = 0;
bool buzzerLigado = false;

void setup() {
  lcd.begin(16, 2);

  pinMode(buzzer, OUTPUT);
  noTone(buzzer);

  Serial.begin(9600);

  lcd.setCursor(0, 0);
  lcd.print("Jardim");
  lcd.setCursor(0, 1);
  lcd.print("Inteligente!");

  delay(2000);
  lcd.clear();
}

void loop() {
  int umidade = analogRead(sensorUmidade);

  Serial.print("Umidade do solo: ");
  Serial.println(umidade);

  // ESTADO 1: SOLO BEM UMIDO
  if (umidade < limiteUmido) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Estou bem, nao");
    lcd.setCursor(0, 1);
    lcd.print("preciso de agua");

    noTone(buzzer);
    buzzerLigado = false;
    tempoAnterior = millis();
  }

  // ESTADO 2: SOLO EM ATENCAO
  else if (umidade <= limiteSeco) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Preciso atencao");
    lcd.setCursor(0, 1);
    lcd.print("Solo secando!");

    // Bip leve e espaçado
    if (millis() - tempoAnterior >= 3000) {
      tempoAnterior = millis();
      tone(buzzer, 1500, 120);
    }
  }

  // ESTADO 3: SOLO MUITO SECO
  else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Estou com sede");
    lcd.setCursor(0, 1);
    lcd.print("Regue a planta!");

    // Bipes mais frequentes
    if (millis() - tempoAnterior >= 500) {
      tempoAnterior = millis();
      tone(buzzer, 2500, 150);
    }
  }

  delay(200);
}
