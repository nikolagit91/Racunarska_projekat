#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <unistd.h>

#define TRIGGER_PIN 23
#define ECHO_PIN 24

void setup()
{
    wiringPiSetup();
    pinMode(TRIGGER_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
}

float getDistance()
{
    // Send a 10us pulse to trigger the sensor
    digitalWrite(TRIGGER_PIN, HIGH);
    usleep(10);
    digitalWrite(TRIGGER_PIN, LOW);

    // Measure the duration of the pulse on the echo pin
    long startTime = micros();
    while (digitalRead(ECHO_PIN) == LOW)
    {
        if (micros() - startTime > 10000) // Timeout if no response within 10ms
            return -1;
    }
    long echoStartTime = micros();
    while (digitalRead(ECHO_PIN) == HIGH)
    {
        if (micros() - startTime > 10000) // Timeout if no response within 10ms
            return -1;
    }
    long echoEndTime = micros();

    // Calculate the distance based on the speed of sound (343.2 m/s)
    float duration = (float)(echoEndTime - echoStartTime);
    float distance = duration * 0.03432 / 2.0; // Divide by 2 for round trip

    return distance;
}

int main()
{
    setup();

    while (1)
    {
        float distance = getDistance();
        if (distance == -1)
        {
            printf("Error: Sensor timed out\n");
        }
        else
        {
            printf("Distance: %.2f cm\n", distance);
        }

        usleep(500000); // Delay for 500ms
    }

    return 0;
}

