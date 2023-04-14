/*MINISUMO UAM MADRID*/
/**
 * Autor Alan Cruz
 * Minisumo hecho con arduino nano y tb6612fng
 * 
 * 
 * 
 */


/*H-bridge*/
int ain1 = 10;
int ain2 = 9;

int bin1 = 3;
int bin2 = 2;

int pwmA = 6;
int pwmB = 5;

//LED
int led = 13;


/*Sensores*/
int der = A0;
int izq = A6;
int cen = A3;
int lin = A1;

unsigned int der_v;
unsigned int izq_v;
bool cen_v;
bool lin_v;


/*Switch*/
int sw1 = A4;

/*Auxiliars*/
bool state = 0;
bool sentido = 0;

/*Directions*/
void adelante (int velocidad) {
  digitalWrite (ain1 , HIGH);
  digitalWrite (ain2 , LOW);
  digitalWrite (bin1 , HIGH);
  digitalWrite (bin2 , LOW);
  analogWrite (pwmA , velocidad);
  analogWrite (pwmB , velocidad);
}
void atras (int velocidad) {
  digitalWrite (ain1 , LOW);
  digitalWrite (ain2 , HIGH);
  digitalWrite (bin1 , LOW);
  digitalWrite (bin2 , HIGH);
  analogWrite (pwmA , velocidad);
  analogWrite (pwmB , velocidad);
}
void derecha (int velocidad) {
  digitalWrite (ain1 , HIGH);
  digitalWrite (ain2 , LOW);
  digitalWrite (bin1 , LOW);
  digitalWrite (bin2 , HIGH);
  analogWrite (pwmA , velocidad);
  analogWrite (pwmB , velocidad);
}
void izquierda (int velocidad) {
  digitalWrite (ain1 , LOW);
  digitalWrite (ain2 , HIGH);
  digitalWrite (bin1 , HIGH);
  digitalWrite (bin2 , LOW);

  analogWrite (pwmA , velocidad);
  analogWrite (pwmB , velocidad);
}

void inicio_led1(){
  for(int i = 0; i < 10;i++){
      digitalWrite(led,!state);
      delay(500);
    }  
}
void inicio_led2(){
  for(int i = 0; i < 5;i++){
      digitalWrite(led,!state);
      delay(1000);
    }  
}

void lecturas(){
  izq_v = 12343.85 * pow(analogRead(izq),-1.15);
  der_v = 12343.85 * pow(analogRead(izq),-1.15);
  lin_v = digitalRead(lin);
  cen_v = digitalRead(cen);
}

void setup() {
  // H bridge
  pinMode(ain1,OUTPUT);
  pinMode(ain2,OUTPUT);
  pinMode(bin1,OUTPUT);
  pinMode(bin2,OUTPUT);
  pinMode(pwmA,OUTPUT);
  pinMode(pwmB,OUTPUT);
  //Sensors
  pinMode(der,INPUT);
  pinMode(izq,INPUT);
  pinMode(cen,INPUT);

  //switch
  pinMode(sw1,INPUT);
}


void loop() {
  
  if(digitalRead(sw1) == 1){ //programacion 1
    inicio_led1(); //retardo 5 s
    while(1){
      lecturas();    
      if(cen_v == 1){
        adelante(255);  
      }
      else if(izq_v <= 50  && der_v <= 50 ){
        adelante(50);
      }
      else if(der_v <= 50  && izq_v > 30 ){
        derecha(120);
        sentido = 0;  
      }
      else if(izq_v <= 50  && der_v > 30 ){
        izquierda(120);
        sentido = 1;
      }
      else{
        if(sentido == 1){
          izquierda(80);  
        }
        else{
          derecha(80);  
        }  
      }
    }
  }
  
  else{ //programacion 2
    inicio_led2(); //retardo 5 s
    while(1){
      lecturas();    
      if(cen_v == 1){
        adelante(255);  
      }
      else if(izq_v <= 50  && der_v <= 50 ){
        adelante(50);
      }
      else if(der_v <= 50  && izq_v > 30 ){
        derecha(120);
        sentido = 0;  
      }
      else if(izq_v <= 50  && der_v > 30 ){
        izquierda(120);
        sentido = 1;
      }
      else{
        if(sentido == 1){
          izquierda(80);  
        }
        else{
          derecha(80);  
        }  
      }
    }
  }

}
