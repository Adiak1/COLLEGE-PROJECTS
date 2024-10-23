#include <Wire.h>
#include "Adafruit_TCS34725.h"

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_1X)

int in1 = 7;
int in2 = 6;
int ena = 9;

uint16_t r, g, b, c;

void setup() {

  Serial.begin(9600);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(ena, OUTPUT);

  if (tcs.begin()) {
    Serial.println("Color sensor found.");
  } else {
    Serial.println("No color sensor found.");
    while (1);
  }
}

void loop() {

  tcs.getRawData(&r, &g, &b, &c);
  
  Serial.print("R: "); Serial.print(r);
  Serial.print(" G: "); Serial.print(g);
  Serial.print(" B: "); Serial.print(b);
  Serial.print(" C: "); Serial.println(c);
  
  controlMotorBasedOnColor(r, g, b);

  delay(500);
}

void controlMotorBasedOnColor(uint16_t r, uint16_t g, uint16_t b) {
 
  if (r > g && r > b) {
   
    Serial.println("Red detected: Motor off.");
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    analogWrite(ena, 0);
  } else if (g > r && g > b) {
    
    Serial.println("Green detected: Motor at full speed forward.");
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(ena, 255);
  } else if (b > r && b > g) {
   
    Serial.println("Blue detected: Motor reversed at 75% speed.");
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(ena, 192);
  } else {
    
    Serial.println("No specific color detected: Motor at 50% speed forward.");
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(ena, 128);
  }
}
