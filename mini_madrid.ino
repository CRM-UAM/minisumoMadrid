/*MINISUMO UAM MADRID*/



/*H-bridge*/
int ain1 = 10;
int ain2 = 9;

int bin1 = 3;
int bin2 = 2;

int pwmA = 6;
int pwmB = 5;


/*Switch ports*/
int switch1 = 7;
int switch2 = 11; //original

/*auxiliares*/
int enter, select;
int sensores[7];
int go;
int tiempo = 0;

/*Sensores*/
//int enables = 8;
int led = 1;


/*Directions*/
void adelante (int velocidad) {
  digitalWrite (ain1 , HIGH);
  digitalWrite (ain2 , LOW);
  digitalWrite (bin1 , HIGH);
  digitalWrite (bin2 , LOW);
  analogWrite (pwm1 , velocidad);
  analogWrite (pwm2 , velocidad);
}
void atras (int velocidad) {
  digitalWrite (ain1 , LOW);
  digitalWrite (ain2 , HIGH);
  digitalWrite (bin1 , LOW);
  digitalWrite (bin2 , HIGH);
  analogWrite (pwm1 , velocidad);
  analogWrite (pwm2 , velocidad);
}
void derecha (int velocidad) {
  digitalWrite (ain1 , HIGH);
  digitalWrite (ain2 , LOW);
  digitalWrite (bin1 , LOW);
  digitalWrite (bin2 , HIGH);
  analogWrite (pwm1 , velocidad);
  analogWrite (pwm2 , velocidad);
}
void izquierda (int velocidad) {
  digitalWrite (ain1 , LOW);
  digitalWrite (ain2 , HIGH);
  digitalWrite (bin1 , HIGH);
  digitalWrite (bin2 , LOW);
  analogWrite (pwm1 , velocidad);
  analogWrite (pwm2 , velocidad);
}


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
