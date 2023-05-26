#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>


#define BUZZER_PIN 27
int highTime=100;
int lowTime=0;


int main()
{
	if (wiringPiSetup() == -1) 
		exit (1);
        

	pinMode(BUZZER_PIN, OUTPUT);



	while (1) {
   
        digitalWrite(BUZZER_PIN,HIGH);
        delay(highTime);
        digitalWrite(BUZZER_PIN,LOW);
        delay(lowTime);
   
    }
     return 0;
}

