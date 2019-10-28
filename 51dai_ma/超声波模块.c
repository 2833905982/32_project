#include <reg52.h>

sbit pwm = P0^3;
sbit led = P0^4;
sbit ECHO = P0^5;
int i = 0,sum = 0,l = 0;

void cheju();
void chaoshengbo();
void main()
{
	TMOD = 0x11;
	TH0 = 0xFF;
	TL0 = 0xFF;
	TH1 = 0;
	TL1 = 0;
	ET0 = 1;
	ET1 = 1;
	TR0 = 1;
	TR1 = 1;
	while(1)
	{
		chaoshengbo();
		cheju();
}
}
void cheju()
{
	while(!ECHO)
	{
		TR1 = 1;
	}
	while(ECHO)
	{
		TR1 = 0;
	}
	sum = TH1 * 256 + TL1;
	l = (sum * 1.78) / 100;
	TH1 = 0;
	TL1 = 0;
	if(l<15)
	{
		led = 0;
	}
	if(l>4)
	{
		led = 1;
	}

}
void chaoshengbo()
{
	if(i<13)
	{
		pwm = 1;
	}
	if(i>13)
	{
		pwm = 0;
	}
	if(i>50)
	{
		i = 0;
	}
}
void time0() interrupt 1
{
	TH0 = 0xFF;
	TL0 = 0xFF;
	i++;
}