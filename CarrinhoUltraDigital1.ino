#include <Ultrasonic.h>
 Ultrasonic ultrassom(8,7); 
int IN1 = 2;
int IN2 = 3;
int IN3 = 4;
int IN4 = 5;
long distancia = 0;
 
void setup() {
  pinMode(IN1, HIGH);
  pinMode(IN2, HIGH);
  pinMode(IN3, HIGH);
  pinMode(IN4, HIGH);
  Serial.begin(9600);
}

void loop() {
  
  distancia = ultrassom.Ranging(CM);
  delay(100);
  
  while(distancia < 30){
    parar();
  delay(2000);
  re();
  delay(2000);
  
  virarDir();
  delay(2000);
  distancia = ultrassom.Ranging(CM);
  
  }

  
  frente();
  //Serial.println (distancia);
  //delay(1000);
}


void frente(){
  digitalWrite( IN1, HIGH);
  digitalWrite(IN2, LOW);
  
  digitalWrite( IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void re(){
   digitalWrite( IN1, LOW);
   digitalWrite(IN2, HIGH);
   digitalWrite( IN3, HIGH);
   digitalWrite(IN4, LOW);
}

void virarDir(){
   digitalWrite( IN1, HIGH);
   digitalWrite(IN2, LOW);
   digitalWrite( IN3, HIGH);
   digitalWrite(IN4, LOW);
}

void parar(){
  digitalWrite( IN1, LOW);
   digitalWrite(IN2, LOW);
   digitalWrite( IN3, LOW);
   digitalWrite(IN4, LOW);
}
