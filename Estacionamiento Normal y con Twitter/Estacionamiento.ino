#include <Servo.h> 
 
Servo myservo;  
int pos = 0;
int switch1 = 11, switch2 = 10, contador = 9, switch1State, switch2State;
int pin[]={4,5,8,7,6,2,3};
int cero[10][7] = {{1,1,1,1,1,0,1}, {0,1,1,0,0,0,0}, {1,1,0,1,1,1,0},{1,1,1,1,0,1,0}, {0,1,1,0,0,1,1}, 
                  {1,0,1,1,0,1,1}, {1,0,1,1,1,1,1}, {1,1,1,0,0,0,0}, {1,1,1,1,1,1,1}, {1,1,1,1,0,1,1}};

void setup() 
{
  Serial.begin(9600);
  myservo.attach(9);
  pinMode(switch1, INPUT);
  pinMode(switch2, INPUT);
  for(int i=0; i < 7; i++){
  pinMode(pin[i],OUTPUT);
 } 
 for (int columna = 0; columna < 7; columna++)
 {
   digitalWrite(pin[columna],cero[contador][columna]);
 }
} 
void loop() 
{
  switch1State = digitalRead(switch1);
  switch2State = digitalRead(switch2);
  if(switch1State == HIGH && contador != 0){
   for(pos = 10; pos < 60; pos++)  
    {                                 
      myservo.write(pos);             
      delay(15);                     
     } 
    for(pos = 60; pos>=10; pos--)     
    {                                
      myservo.write(pos);              
      delay(15);                      
    }
    contador--;
    for (int columna = 0; columna < 7; columna++)
    {
      digitalWrite(pin[columna],cero[contador][columna]);
    }
        Serial.println(contador);
    delay(500);
  }
  
 else if(switch2State == HIGH && contador != 9){
  for(pos = 10; pos < 60; pos++)  
    {                                 
      myservo.write(pos);             
      delay(15);                     
     } 
    for(pos = 60; pos>=10; pos--)     
    {                                
      myservo.write(pos);              
      delay(15);                      
    }
    contador++;
    for (int columna = 0; columna < 7; columna++)
    {
      digitalWrite(pin[columna],cero[contador][columna]);
    }
        Serial.println(contador);
delay(500);
  }  
} 
