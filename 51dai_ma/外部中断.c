#include <reg52.h>

sbit KEY1 = P3^2;
sbit KEY2 = P3^3;
sbit LED1 = P0^0;
sbit LED2 = P0^1;
bit backup1 = 1;
bit backup2 = 1;

unsigned char keybuf1 = 1;
unsigned char keybuf2 = 1;

void delay();
void main()
{
	EA = 1;
	IT0 = 1;
	EX0 = 1;
	IT1 = 1;
	EX1 = 1;
	while(1);
}
void zhongduang1() interrupt 0
{
	keybuf1 = KEY1;
	if(keybuf1!=backup1)
	{
		delay();
		if(keybuf1==KEY1)
		{
			if(backup1==0)
			{
				LED1 = ~LED1;
			}
		}
		backup1 = keybuf1;
	}
}
void zhongduan2() interrupt 2
{
	keybuf2 = KEY2;
	if(keybuf2!=backup2)
	{
		delay();
		if(keybuf2==KEY2)
		{
			if(backup2==0)
			{
				LED2 = ~LED2;
			}
		}
		backup2 = keybuf2;
	}
}
void delay()
{
	unsigned char i = 1000;
	while(i--);
}