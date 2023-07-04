/*MINISUMO UAM MADRID*/
/**
 * Autor Alan Cruz
 * Minisumo hecho con arduino nano y tb6612fng
 * 
 * 
 * 
 */


/*H-bridge*/
int ain1 = 8;
int ain2 = 9;

int bin1 = 3;
int bin2 = 2;

int pwmA = 6;
int pwmB = 5;


/*Sensores*/
int cen = A2;
int izq = A1;
int der = A3;
int lin = A1;



float der_v;
float izq_v;
bool cen_v;
bool lin_v;


/*Switch*/
int sw1 = 11;
int sw2 = 4;

/*Auxiliars*/
bool sentido = 0;

/*Directions*/
void atras (int velocidad) {
  digitalWrite (ain1 , HIGH);
  digitalWrite (ain2 , LOW);
  digitalWrite (bin1 , HIGH);
  digitalWrite (bin2 , LOW);
  analogWrite (pwmA , velocidad);
  analogWrite (pwmB , velocidad);
}
void adelante (int velocidad) {
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

void parar () {
  digitalWrite (ain1 , LOW);
  digitalWrite (ain2 , LOW);
  digitalWrite (bin1 , LOW);
  digitalWrite (bin2 , LOW);

  analogWrite (pwmA , 255);
  analogWrite (pwmB , 255);
}

void inicio_led1(){
  for(int i = 0; i < 5;i++){
      digitalWrite(13,1);
      delay(500);
      digitalWrite(13,0);
      delay(500);
    }  
}
void inicio_led2(){
  for(int i = 0; i < 10;i++){
      digitalWrite(13,1);
      delay(250);
      digitalWrite(13,0);
      delay(250);
    }  
}


void lecturas(){
  cen_v = digitalRead(cen);
   izq_v = distancia(izq);
   der_v = distancia(der);
  
}


float distancia(int sensor){
 float dis_a = 15;

 for(int i=0;i<3000;i++){
   float dis = 12343.85 * pow(analogRead(sensor),-1.15);
    if((dis-dis_a) < -.1 || (dis_a-dis) > .1){ 
      dis_a = dis;
      return(dis);
    }
    else{
      return(dis_a);
    }
 }
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
  pinMode(sw2,INPUT);
  
  pinMode(LED_BUILTIN,OUTPUT);
}


void loop() {

  if(digitalRead(sw1)  == 1 && digitalRead(sw2) == 0){
    
     inicio_led1();
    
     while(1){
        lecturas();    
        if(cen_v == 0){
          adelante(255);  
        }
        else if(izq_v < 14.5 && der_v < 14.5){
          parar();
        }
        else if(izq_v < 14.5 && der_v == 15){
          derecha(80);
          sentido = 0;  
        }
        else if(izq_v == 15 && der_v< 14.5){
          izquierda(80);
          sentido = 1;
        }
        else{
          if(sentido == 1){
            izquierda(100);  
          }
          else{
            derecha(100);  
          }  
        }
      }
    }


     else if(digitalRead(sw1) == 0 && digitalRead(sw2 )== 1){
     inicio_led2();
    
     while(1){
        lecturas();    
        if(cen_v == 0){
          adelante(255);  
        }
        else if(izq_v < 14.5 && der_v < 14.5){
          adelante(70);
        }
        else if(izq_v < 14.5 && der_v == 15){
          derecha(80);
          sentido = 0;  
        }
        else if(izq_v == 15 && der_v< 14.5){
          izquierda(80);
          sentido = 1;
        }
        else{
          if(sentido == 1){
            izquierda(100);  
          }
          else{
            derecha(100);  
          }  
        }
      }
    }


    else{
      parar();
    }
    
  }
 
