#include <reg52.h>

sbit LED1 = P0^0;
sbit LED2 = P0^1;
sbit LED3 = P0^2;

void delay(void)
{
	int i;
	for(i=0;i<30000;i++);
}
int main()
{
	while(1)
	{
		LED1=0;LED2=0;LED3=0;delay();
		LED1=1;LED2=0;LED3=0;delay();
		LED1=0;LED2=1;LED3=0;delay();
		LED1=1;LED2=1;LED3=0;delay();
		LED1=0;LED2=0;LED3=1;delay();
		LED1=1;LED2=0;LED3=1;delay();
		LED1=0;LED2=1;LED3=1;delay();
		LED1=1;LED2=1;LED3=1;delay();
	}
}