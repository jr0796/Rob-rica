#include <Ultrasonic.h>
 Ultrasonic ultrassom(8,7); 
int IN1 = 3;
int IN2 = 5;
int IN3 = 9;
int IN4 = 10;
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
  Serial.println (distancia);
  //delay(1000);
}


void frente(){
  analogWrite( IN1, 150);
  analogWrite(IN2, 0);
  
  analogWrite( IN3, 0);
  analogWrite(IN4, 150);
}

void re(){
   analogWrite( IN1, 0);
   analogWrite(IN2, 150);
   analogWrite( IN3, 150);
   analogWrite(IN4, 0);
}

void virarDir(){
   analogWrite( IN1, 150);
   analogWrite(IN2, 0);
   analogWrite( IN3, 150);
   analogWrite(IN4, 0);
}

void parar(){
  analogWrite( IN1, 0);
   analogWrite(IN2, 0);
   analogWrite( IN3, 0);
   analogWrite(IN4, 0);
}
