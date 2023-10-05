/*--------- Variáveis e Constantes --------------------------------------------------*/

#define motorEF 6           // Motor ESQUERDO anda para FRENTE
#define motorET 7           // Motor ESQUERDO anda para TRÁS
#define motorDF 4           // Motor DIREITO anda para FRENTE
#define motorDT 5           // Motor DIREITO anda para TRÁS
#define pwmE    10          // PWM motor ESQUERDO
#define pwmD    9           // PWM motor DIREITO

#define SensorEsquerdo A0   // Pino analógico para o sensor do lado ESQUERDO
#define SensorDireito  A1   // Pino analógico para o sensor do lado DIREITO

#define velocidade 85       //Controle de velocidade do PWM

#define branco 80           //Definição da intensidade do branco
#define preto 200           //Definição da intensidade do preto

unsigned int valorSenEsq, valorSenDir; // Variáveis para armazenar o valor dos sensores infravermelhos

void setup(){

  pinMode(SensorEsquerdo,INPUT);  // Configura pino como entrada
  pinMode(SensorDireito,INPUT);   // Configura pino como entrada
  
  pinMode(motorEF,OUTPUT);        // Configura pino como Saída
  pinMode(motorET,OUTPUT);        // Configura pino como Saída
  pinMode(motorDF,OUTPUT);        // Configura pino como Saída    
  pinMode(motorDT,OUTPUT);        // Configura pino como Saída    
  
  pinMode(pwmE,OUTPUT);           // Configura pino como Saída    
  pinMode(pwmD,OUTPUT);           // Configura pino como Saída    
  
}

//********************************************************* PROGRAMA PRINCIPAL ************************************************************

void loop(){
  
  valorSenDir = analogRead(SensorDireito);  
  valorSenEsq = analogRead(SensorEsquerdo); 

  analogWrite(pwmE,velocidade);
  analogWrite(pwmD,velocidade);
   
 // Se os dois sensores estiverem no branco(fora da linha), anda para FRENTE
  if((valorSenEsq < branco ) && (valorSenDir < branco))
  {  
    frente(); 
  }
  
  // Se o sensor esquerdo estiver na linha preta vira para ESQUERDA 
  else if((valorSenEsq > preto ) && (valorSenDir <  branco))
  { 
    esquerda(); 
  }
 
  // Se o sensor direito estiver na linha preta vira para DIREITA 
  else if((valorSenEsq < branco) && (valorSenDir > preto))
  { 
    direita(); 
  }

}

//**************************************************************** F U N Ç Õ E S ****************************************************************

void tras(void)   // Ambos motores são acionados reversamente, o robô anda para TRÁS
{
 
  digitalWrite(motorEF, 1);
  digitalWrite(motorET, 0);
  digitalWrite(motorDF, 1);
  digitalWrite(motorDT, 0);
}

void frente(void)  // Ambos motores são acionados, o robô anda para FRENTE
{

  digitalWrite(motorEF, 0);
  digitalWrite(motorET, 1);
  digitalWrite(motorDF, 0);
  digitalWrite(motorDT, 1);
}


void esquerda(void)  // Apenas o motor direito é acionado, virando para ESQUERDA
{
  
  digitalWrite(motorEF, 0);
  digitalWrite(motorET, 0);
  digitalWrite(motorDF, 0);
  digitalWrite(motorDT, 1);
}

void direita(void)   // Apenas o motor esquerdo é acionado, virando para DIREITA
{
  digitalWrite(motorEF, 0);
  digitalWrite(motorET, 1);
  digitalWrite(motorDF, 0);
  digitalWrite(motorDT, 0);
}


void para(void)       // Todos motores ficam parados
{
  digitalWrite(motorEF, 0);
  digitalWrite(motorET, 0);
  digitalWrite(motorDF, 0);
  digitalWrite(motorDT, 0);
}
