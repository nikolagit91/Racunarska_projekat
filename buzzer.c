#include <wiringPi.h>
#include <stdio.h>

#define BUZZER_PIN 0 // Define the GPIO pin number for the buzzer

int main() {
  wiringPiSetup(); // Initialize wiringPi library

  pinMode(BUZZER_PIN, OUTPUT); // Set buzzer pin as output

  while(1) {
    digitalWrite(BUZZER_PIN, HIGH); // Turn on the buzzer
    delay(500); // Wait for 0.5 seconds
    digitalWrite(BUZZER_PIN, LOW); // Turn off the buzzer
    delay(500); // Wait for 0.5 seconds
  }

  return 0;
}
