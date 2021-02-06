#include <Arduino.h>
#include <time.h>
int Vo, ThermistorPin = 0;
float R1 = 10000;
float logR2, R2, TF, c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

void setup() {
Serial.begin(9600);
}

void loop() {

  Vo = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  TF = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  TF = TF - 273.15;
  TF = (TF * 9.0)/ 5.0 + 32.0; 

  Serial.print("Temperature: "); 
  Serial.print(TF);
  Serial.println(" F"); 

  delay(500);
}