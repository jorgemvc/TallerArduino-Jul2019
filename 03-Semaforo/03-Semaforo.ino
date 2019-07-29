/** @file    03-Semaforo.ino
 *  @author  Jorge Villalobos Carvajal (jorgemvc@gmail.com)
 *  @date    29.Jul.2019
 *  @version 1.0 
 *  
 *  @brief   Semáforo de dos vías
 *
 *  @licence  MIT License
 */
byte sem1 = 2,  // Puerto de inicio del semáforo 1
     sem2 = 5,  // Puerto de inicio del semáforo 2
     i;         // Contador

void semaforo (
  byte semaforo,    // Puerto inicial del semáforo
  byte luzRoja,     // Estado de la luz roja
  byte luzAmarilla, // Estado de la luz amarilla
  byte luzVerde     // Estado de la luz verde
) {
  digitalWrite(semaforo+0, luzRoja    );
  digitalWrite(semaforo+1, luzAmarilla);
  digitalWrite(semaforo+2, luzVerde   );
}  // semaforo

void pruebaLuces() {
  semaforo(sem1, HIGH, LOW, LOW);
  semaforo(sem2, HIGH, LOW, LOW);
  delay(500);

  semaforo(sem1, LOW, HIGH, LOW);
  semaforo(sem2, LOW, HIGH, LOW);
  delay(500);
  
  semaforo(sem1, LOW, LOW, HIGH);
  semaforo(sem2, LOW, LOW, HIGH);
  delay(500);
}  // pruebaLuces

void setup() {
  // Se inicializan los 6 puertos, como de salida
  for (i = 2 ; i <= 7 ; i++) {
    pinMode(i, OUTPUT);
  }
  
  pruebaLuces();
  
  i = 1;
}  // void setup

void loop() {
  switch (i) {
    case 1:
      semaforo(sem1, HIGH, LOW, LOW );
      semaforo(sem2, LOW , LOW, HIGH);
      break;
    case 6:
      semaforo(sem2, LOW, HIGH, LOW);
      break;
    case 8:
      semaforo(sem1, LOW , LOW, HIGH);
      semaforo(sem2, HIGH, LOW, LOW );
      break;
    case 13:
      semaforo(sem1,LOW, HIGH, LOW);
      break;
  }  // switch
  
  i++;
  delay(1000); // Espera de 1 segundo (1000 milisegundos)
  if (i == 14) i = 1;
}  // void loop
