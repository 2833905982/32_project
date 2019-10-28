#include<reg52.h>
sbit key1 = P0^0;
sbit key2 = P0^1;
sbit led1 = P0^2;
sbit led2 = P0^3;

void delay(unsigned int i)
{
	while(i--);
}

void main()
{
	while(1)
	{
		EA = 1;
    EX0 = 1;
    IT0 = 1;
    EX1 = 1;
    IT1 = 1;
	}
	
}
void ww1() interrupt 0
{
	delay(1000);
	if(key1 == 0)
	led1 = ~led1;
}
void ww2() interrupt 2
{
	delay(1000);
	if(key2 == 0)
	led2 = ~led2;
}
