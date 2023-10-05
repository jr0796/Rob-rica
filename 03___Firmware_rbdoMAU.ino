#define p1m1 6
#define p2m1 7
#define pve1m1 8
#define p1m2 4
#define p2m2 5
#define pve1m2 3

int vel;

class Motor{
public:
  int p1,p2,pv;
  Motor(int p1, int p2, int v){
    this->p1=p1;
    this->p2=p2;
    this->pv=v;
    pinMode(p1,OUTPUT);
    pinMode(p2,OUTPUT);
    pinMode(pv,OUTPUT);
    digitalWrite(p1,LOW);
    digitalWrite(p2,LOW);
    analogWrite(pv,0);
    }
    void frente(int v){
      digitalWrite(p1,HIGH);
      digitalWrite(p2,LOW);
      analogWrite(pv,v);
      }
    void tras(int v){
      digitalWrite(p1,LOW);
      digitalWrite(p2,HIGH);
      analogWrite(pv,v);
      }
    void para(){
      digitalWrite(p1,LOW);
      digitalWrite(p2,LOW);
      analogWrite(pv,0);
      }
    void freia(){
      digitalWrite(p1,HIGH);
      digitalWrite(p2,HIGH);
      analogWrite(pv,128);
      }
  };

Motor *md=new Motor(p1m1,p2m1,pve1m1);
Motor *me=new Motor(p1m2,p2m2,pve1m2);

void setup(){
  Serial.begin(9600);
  Serial1.begin(9600);
  vel=150; 
  }

void loop() {
  char c=Serial.read();
  if(c=='T'){
    md->frente(vel);
    me->frente(vel);
    }
  if(c=='F'){
    md->tras(vel);
    me->tras(vel);
    }
  if(c=='E'){
    md->tras(vel*0.9);
    me->frente(vel*0.9);
    }
  if(c=='D'){
    md->frente(vel*0.9);
    me->tras(vel*0.9);
    }
  if(c=='P'){
    md->para();
    me->para();
    }
  
}
