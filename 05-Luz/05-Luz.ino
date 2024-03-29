/** @file    05-Luz.ino
 *  @author  Jorge Villalobos Carvajal (jorgemvc@gmail.com)
 *  @date    29.Jul.2019  
 *  @version 1.0 
 *  
 *  @brief   Lectura de un sensor de luminosidad
 *
 *  @licence  MIT License
 */
int
  luzPin = A2,
  sensorValue;

void setup() {
  Serial.begin(9600);
}  // void setup

void loop() {
  // Realiza la lectura del sensor
  sensorValue = analogRead(luzPin);

  int luz = map(sensorValue, 0, 1023, 0, 100);

  Serial.print("Valor medido: ");
  Serial.print(sensorValue);
  Serial.print(" - Porc: ");
  Serial.println(luz);

  delay(100);
} // void loop
