// https://www.youtube.com/watch?v=2rnczyBd3WU
/*
PIN 2 -> D7 afficheur
PIN 3 -> D6 afficheur
PIN 4 -> D5 afficheur
PIN 5 -> D4 afficheur
PIN 6 -> DT (ampli)
PIN 9 -> SCK (ampli)
PIN 11 -> E (afficheur)
PI 12 -> RS (afficheur)
*/

#include "Hx711.h"
#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);
HX711 scale (6, 9);

float calibration_factor = 103;
float units;
int A;

void setup() {
  Serial.begin(9600);
  scale.set_scale(1);
  scale.tare();
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
}

void loop() {
  scale.set_scale(calibration_factor);
  Serial.print("Lecture : ");
  units = scale.get_units(), 10;

  A = 1.0107*units - 7.466;
  if (A<0) {
  A = 0.00;
  }

  Serial.print(A);
  Serial.print("grammes");
  Serial.println();

  lcd.print(A);
  lcd.print(" g");
  delay(1000);
  lcd.clear();
  }
