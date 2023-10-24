#include <Ultrasonic.h>
Ultrasonic ultra(4,3);
long distancia;
int buzzer = 5;

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  distancia = ultra.Ranging(CM);
  if (distancia <50){
    delay(10);
    tone(buzzer,100,70);
  }else{
    delay(500);
    tone(buzzer,80,10);
  }

  //Serial.println(distancia);
  //Serial.print(" cm");
  //delay(100);  
}
