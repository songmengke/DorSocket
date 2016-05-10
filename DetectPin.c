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
			system("/home/songmengke/socket/client dooropen");
		}
		else
		{
			delay(200);
			system("/home/songmengke/socket/client doorclse");
		}
	}
	return 0;
}
