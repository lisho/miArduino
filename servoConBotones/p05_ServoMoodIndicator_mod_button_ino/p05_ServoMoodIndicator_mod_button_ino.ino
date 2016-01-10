/*
  Servomotor movido por botones a posiciones predeterminadas.
  
  Repasar ejemplos:
  https://www.arduino.cc/en/Tutorial/Button

*/

// Añadimos la librera SERVO de Arduino
  #include <Servo.h>

  Servo myServo;  // creamos un objeto de la clase servo

// Declaramos las variables y constantes
  const int red=3; // pin rojo
  const int yellow=4; // pin amarillo
  const int green=5; // pin verde
  
  const int angleRed=0; // angulo del servo si pulsamos el boton rojo
  const int angleYellow=90; // angulo del servo si pulsamos el boton amarillo
  const int angleGreen=180; // angulo del servo si pulsamos el boton verde
  
  int redVal, yellowVal, greenVal; //declaramos variables vacas para almacenar el valor de cada pin

  int angle; // Declaramos la variable que almacenar el angulo en el que se posicionara el servo.
  
  


void setup() {
   
  pinMode(red,INPUT);
  pinMode(yellow,INPUT);
  pinMode(green,INPUT);
  
  myServo.attach(9); // definimos el puerto que va a manejar el servo
  Serial.begin(9600); // abrimos la conexion con el puerto-serie del ordenador
  
}

void loop(){
  
  // asignamos a cada variable la lectura de su pin correspondiente.
  redVal=digitalRead(red);
  yellowVal=digitalRead(yellow);
  greenVal=digitalRead(green);
  
  // Definimos el angulo del servo dependiendo del boton que pulsemos
  
  if (redVal==1){
    angle=angleRed;
  }
  else if(yellowVal==1){
    angle=angleYellow;
  }
  else if(greenVal==1){
    angle=angleGreen;
  }
  
  // Posicionamos el servo
  
     myServo.write(angle);
  
  // Imprimimos en pantalla el valor correspondiente
  
  Serial.print("Rojo: ");
  Serial.print(redVal); 
  Serial.print("  Amarillo: ");
  Serial.print(yellowVal);  
  Serial.print("  Verde: ");
  Serial.print(greenVal); 
  Serial.print(", --> angulo: ");
  Serial.println(angle); 
  
 //Esperamos a que el servo llegue a la nueva posicin antes de mandarle otra para que no se cueza.
 
     delay(25);
  
}
