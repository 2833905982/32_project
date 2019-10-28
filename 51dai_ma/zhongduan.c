#include <reg52.h>

sbit LED = P0^0;
unsigned char led[]={
		0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8,
		0x80, 0x90, 0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E
		};
unsigned char ledbug[]={
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
		};
unsigned char i;
unsigned char cnt;
unsigned char flag;
int main()
{
	EA   = 1;
	TMOD = 0x01;
	TH0  = 0xFC;
	TL0  = 0x67;
	ET0  = 1;
	TR0  = 1;
	while(1)
	{
		unsigned char sec = 0;
		if(flag==1)
		{
			flag = 0;
			sec++;
			ledbug[0]=led[sec%10];
			ledbug[1]=led[sec/10%10];
			ledbug[2]=led[sec/100%10];
			ledbug[3]=led[sec/1000%10];
			ledbug[4]=led[sec/10000%10];
			ledbug[5]=led[sec/100000%10];
		}
	}
}
void interruptTimer()  interrupt 1
{
		TH0 = 0xFC;
		TR0 = 0x67;
		cnt++;
		if(cnt>=1000)
		{
			cnt  = 0;
			flag = 1;
		}
			P0 = 0xFF;
			switch(i)
			{
				case 0: P0 = ledbug[0]; i++;  break;
				case 1: P0 = ledbug[1]; i++;  break;
				case 2: P0 = ledbug[2]; i++;  break;
				case 3: P0 = ledbug[3]; i++;  break;
				case 4: P0 = ledbug[4]; i++;  break;
				case 5: P0 = ledbug[5]; i++;  break;
				default : break;
			}
}