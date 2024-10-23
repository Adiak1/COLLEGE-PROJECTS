
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

const int buttonPin = 8;
const int ledPin = 7;
int buttonState = 0;
unsigned long startTime;
unsigned long reactionTime;

// Simulate LCD screen functions
void lcd_print(const char* message) {
    printf("%s\n", message);
}

void lcd_clear() {
    printf("\033[H\033[J");  // ANSI escape code to clear the terminal (simulating LCD clearing)
}

unsigned long millis() {
    return (unsigned long)(clock() / (CLOCKS_PER_SEC / 1000));
}

int digitalRead(int pin) {
    // Simulate button press; you can replace it with actual GPIO read function
    int input;
    printf("Press 0 to stop: ");
    scanf("%d", &input);
    return input;
}

void digitalWrite(int pin, int state) {
    if (state == 1) {
        printf("LED ON\n");
    } else {
        printf("LED OFF\n");
    }
}

int random(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void delay(int ms) {
    clock_t start_time = clock();
    while (clock() < start_time + ms * CLOCKS_PER_SEC / 1000);
}

void setup() {
    lcd_print("Reaction Test");
    delay(2000);
}

void loop() {
    lcd_clear();
    lcd_print("Wait for it...");
    delay(random(2000, 5000));

    digitalWrite(ledPin, 1);
    startTime = millis();

    while (digitalRead(buttonPin) == 1) {
        // wait for button press
    }

    reactionTime = millis() - startTime;
    digitalWrite(ledPin, 0);

    lcd_clear();
    lcd_print("Time: ");
    printf("%lu ms\n", reactionTime);

    delay(3000);
}

int main() {
    setup();
    while (1) {
        loop();
    }
}
