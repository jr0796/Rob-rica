#include<Ultrasonic.h>
#include<Servo.h>

Servo meuServo;
Ultrasonic sensor(2,3);
long distancia;



void setup() {
  Serial.begin(9600);
  meuServo.attach(4);
  meuServo.write(0);
}

void loop() {
  distancia = sensor.Ranging(CM);
  Serial.println(distancia);

  if(distancia <20){
    meuServo.write(90);
    delay(4000);
  }
  meuServo.write(0);
}
