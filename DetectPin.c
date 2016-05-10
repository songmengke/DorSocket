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
			delay(200);
			system("/home/songmengke/socket/client 010111");
		}
		else
		{
			delay(200);
			printf("door close\n");
		}
	}
	return 0;
}
