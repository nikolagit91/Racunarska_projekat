#include <wiringPi.h>
#include <stdio.h>

#define LASER_PIN 0 // Define the GPIO pin number for the laser diode

int main() {
  wiringPiSetup(); // Initialize wiringPi library

  pinMode(LASER_PIN, OUTPUT); // Set laser pin as output

  while(1) {
    digitalWrite(LASER_PIN, HIGH); // Turn on the laser diode
    delay(1000); // Wait for 1 second
    digitalWrite(LASER_PIN, LOW); // Turn off the laser diode
    delay(1000); // Wait for 1 second
  }

  return 0;
}
