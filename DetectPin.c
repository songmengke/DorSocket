#include<stdio.h>
#include<wiringPi.h>
#define PIN 4
int main()
{
	wiringPiSetup();
	pinMode(PIN,INPUT);
	while(1)
	{
		if(digitalRead(PIN))
		{
			delay(100);
			printf("door open\n");
		}
		else
		{
			delay(100);
			printf("door close\n");
		}
	}
	return 0;
}
