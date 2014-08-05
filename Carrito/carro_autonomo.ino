int tiempo = 0 ,distancia = 0;                  
const int controlPin1=2; 
const int controlPin2=3;
const int controlPin3=14;
const int controlPin4=15;
const int ECHOPIN = 5;     
const int TRIGPIN = 4;        
       
void setup() {
  Serial.begin(9600); 
  pinMode(controlPin1,OUTPUT);
  pinMode(controlPin2,OUTPUT);
  pinMode(controlPin3,OUTPUT); 
  pinMode(controlPin4,OUTPUT);
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
}
  
void adelante(){
  digitalWrite(controlPin3,HIGH);
}

void atras(){ 
  digitalWrite(controlPin4,HIGH);
}

void izquierda(){
  digitalWrite(controlPin2,HIGH);
}

void derecha(){
  digitalWrite(controlPin1,HIGH);
}

void detener(){
  digitalWrite(controlPin1,LOW);
  digitalWrite(controlPin2,LOW);
  digitalWrite(controlPin3,LOW);
  digitalWrite(controlPin4,LOW);
}

int lectura(int trig, int echo){
  digitalWrite(trig, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trig, HIGH);  
  delayMicroseconds(10);      
  digitalWrite(trig, LOW); 
  return ((pulseIn(echo, HIGH))/2) / 29;
}
void loop()
{ 
  distancia=lectura(TRIGPIN, ECHOPIN);
  adelante();
  Serial.println(distancia);
  delay(50);
  if(distancia <= 30){
    detener();
    while(distancia<=45){
      derecha();
      atras();
      distancia=lectura(TRIGPIN, ECHOPIN);
      Serial.println(distancia);
      delay(50);
    }
    detener();
    adelante();
    izquierda();
    delay(600);
    detener();
    adelante();
  }
}
