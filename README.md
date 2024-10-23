Reaction time measurement using Arduino uno

Components :
Arduino Uno
16x2 LCD display
Push button
LED
10kΩ potentiometer (for LCD contrast)
220Ω resistor (for LCD backlight)
Breadboard and jumper wires

Connection :
LCD 16x2 connections
VSS → GND
VDD → 5V
V0 → Middle pin of the potentiometer
RS → Pin 12
RW → GND
E → Pin 11
D4 → Pin 5
D5 → Pin 4
D6 → Pin 3
D7 → Pin 2
A→ 5V
K→ GND
LED to pin 7
Push button to pin 8

The code in C program:

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int buttonPin = 8;
const int ledPin = 7;
int buttonState = 0;
unsigned long startTime;
unsigned long reactionTime;

void setup() {
lcd.begin(16, 2);
pinMode(buttonPin, INPUT_PULLUP);
pinMode(ledPin, OUTPUT);
lcd.print("Reaction Test");
delay(2000);
}

void loop() {
lcd.clear();
lcd.print("Wait for it...");
delay(random(2000, 5000));

digitalWrite(ledPin, HIGH);
startTime = millis();

while (digitalRead(buttonPin) == HIGH) {

}

reactionTime = millis() - startTime;
digitalWrite(ledPin, LOW);

lcd.clear();
lcd.print("Time: ");
lcd.print(reactionTime);
lcd.print(" ms");

delay(3000);
}
