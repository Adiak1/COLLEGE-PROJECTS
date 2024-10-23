
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
        // Waiting for button press
    }

    reactionTime = millis() - startTime;
    digitalWrite(ledPin, LOW);

    lcd.clear();
    lcd.print("Time: ");
    lcd.print(reactionTime);
    lcd.print(" ms");

    delay(3000);
}
