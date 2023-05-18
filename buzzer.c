#include <stdio.h>
#include <wiringPi.h>

#define BUZZER_PIN 17

void setup()
{
    wiringPiSetup();
    pinMode(BUZZER_PIN, OUTPUT);
}

void buzz(int duration_ms)
{
    digitalWrite(BUZZER_PIN, HIGH);
    delay(duration_ms);
    digitalWrite(BUZZER_PIN, LOW);
    delay(duration_ms);
}

int main()
{
    setup();

    // Make the buzzer beep 3 times with a 500ms duration
    int i;
    for (i = 0; i < 3; i++)
    {
        buzz(500);
        delay(500);
    }

    return 0;
}

