//Importando a biblioteca nativa SoftSerial
#include "SoftwareSerial.h"

//EStânciando uma variável do tipo SoftwareSerial
SoftwareSerial meuModulo(2, 3); // Onde TX, RX (meuModulo)

void setup() {
  //Inicializando a portal serial nativa do Arduino IDE.
  Serial.begin(9600);
  Serial.println(F("Tipos de Entradas ou Comandos:"));

  //Inicializando a portal Serial virtual da variável.
  meuModulo.begin(9600); //Com ela posso acompanhar os dados que trafegam na porta.
}

void loop() {
  //Checando se a portal Serial recebeu algum valor.
  if (Serial.available()) { //Se sim
    char r = Serial.read(); //Faça a leitura dessa entrada, nesse caso salvando um byte(ou uma String)
    meuModulo.print(r);  //Imprimindo o que foi transferido via SoftwareSerial
    Serial.print(r);  
  }
  //Checando se a porta serial virtual recebeu algum valor. 
  if (meuModulo.available()) {//Se sim 
    char r = meuModulo.read(); //Leia os dados de entrada nessa caso  salvando um byte.
    Serial.print(r); 
  }
}
