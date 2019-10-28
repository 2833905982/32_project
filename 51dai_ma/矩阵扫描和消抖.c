#include <reg52.h>

sbit LED1 = P0^0;
sbit LED2 = P0^1;
sbit LED3 = P0^2;
sbit KEYOUT = P2^0;
sbit KEYIN1 = P2^1;
sbit KEYIN2 = P2^2;
sbit KEYIN3 = P2^3;

void delay();
int main()
{
	EA = 1;
	TMOD = 0x01;
	TH0 = 0x70;
	TL0 = 0x00;
	ET0 = 1;
	TR0 = 1;
	return 0; 
}
void interrupttime() interrupt 1
{
//	unsigned char i;
	static unsigned char keybuf[3][3]={{1,1,1},{1,1,1},{1,1,1}};
	static unsigned char backup[3][3]={{1,1,1},{1,1,1},{1,1,1}};
	TH0 = 0x70;
	TR0 = 0x00;
	KEYOUT = 0;
	
	keybuf[0][1]=KEYIN1;
	if(keybuf[0][1] != backup[0][1])
	{
		delay();
		if(keybuf[0][1] == KEYIN1)
		{
			if(backup == 0)
			{
				LED1 = ~LED1;
			}
		}
		backup[0][1] = keybuf[0][1];
	}
	
	keybuf[0][2]=KEYIN2;
	if(keybuf[0][2] != backup[0][2])
	{
		delay();
		if(keybuf[0][2] == KEYIN2)
		{
			if(backup == 0)
			{
				LED2 = ~LED2;
			}
		}
		backup[0][2] = keybuf[0][2];
	}
	
	keybuf[0][3]=KEYIN3;
	if(keybuf[0][3] != backup[0][3])
	{
		delay();
		if(keybuf[0][3] == KEYIN3)
		{
			if(backup == 0)
			{
				LED3 = ~LED3;
			}
		}
		backup[0][3] = keybuf[0][3];
	}
}
void delay()
{
	unsigned char i = 1000;
	while(i--);
}