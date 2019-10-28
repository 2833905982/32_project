#include <reg52.h>
sbit IN1 = P0^0;
sbit IN3 = P0^2;
sbit ENA = P0^4;
sbit ENB = P0^5;


unsigned char i;

void main()
{
	TMOD = 0x01;
	TH0 = 0xFC;
	TL0 = 0X67;
	EA = 1;
	ET0 = 1;
	TR0 = 1;
	while(1)
	{
	if(i<20)
	{
		IN1 = 1;
		IN3 = 1;
		ENA = 1;
		ENB = 1;
	}
	 if(i>=80)
	{
		IN1 = 0;
		IN3 = 0;
		ENA = 1;
		ENB = 1;
	}
	if(i>100)
	{
		i = 0;
	}
}
}
void time() interrupt 1
{
	TH0 = 0xFC;
	TL0 = 0x67;
	i++;
}
