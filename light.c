#include <wiringPi.h>
#include <stdio.h>

#define SENSOR_PIN 0 // Define the GPIO pin number for the sensor

int main() {
  wiringPiSetup(); // Initialize wiringPi library

  pinMode(SENSOR_PIN, INPUT); // Set sensor pin as input

  while(1) {
    if(digitalRead(SENSOR_PIN) == LOW) { // If sensor detects interrupt
      printf("Light interrupt detected\n"); // Print message to console
      delay(500); // Wait for 0.5 seconds to avoid detecting multiple interrupts
    }
  }

  return 0;
}
