#include <reg52.h>

sbit pwm = P0^3;
int i = 0;

void main()
{
	TMOD = 0x01;
	TH0 = 0xFF;
	TL0 = 0xFF;
	ET0 = 1;
	TR0 = 1;
	while(1)
	{
	if(i<12)
	{
		pwm = 1;
	}
	if(i>12)
	{
		pwm = 0;
	}
	if(i>15)
	{
		i = 0;
	}
}
}
void time0() interrupt 1
{
	TH0 = 0xFF;
	TL0 = 0xFF;
	i++;
}