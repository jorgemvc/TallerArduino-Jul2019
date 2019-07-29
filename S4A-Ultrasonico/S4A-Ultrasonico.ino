#include <S4ALib.h>

// ---- Constantes
const int trigPin = 9;  // Puerto de envío
const int echoPin = 12; // Puerto de recepción

// ---- Variables
S4ALib Robot;

void setup() {
  Robot.begin();
  Robot.setSpeed(75, 75);
  
  pinMode(trigPin, OUTPUT);  // Establece el puerto como de salida
  pinMode(echoPin, INPUT);   // Establece el puerto como de entrada
}  // setup

void loop() {
  if (GetDistancia() <= 25) {
    Robot.stop();
    Robot.left(500);  
  } else {
    Robot.forward();
  }
  delay(50);  
}  // loop

float GetDistancia() {
  float duration;
  
  //  Limpia el puerto de envío
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Pone el puerto de envío en HIGH por 5 microsegundos
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Lee la señal de regreso de la onda de sonido en microsegundos
  duration = pulseIn(echoPin, HIGH);
  
  // Calcula la distancia
  return ((duration / 2.0) / 29.4118);  
}  // GetDistancia
