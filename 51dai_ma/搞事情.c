#include <reg52.h>
typedef unsigned int uint;
typedef unsigned char uchar;
sbit pwm=P0^3;//??PWM??
uint pwm_value=1500;//???1.5ms

uint value[]={1400,1300,1200,1100,1000,900,800,700,600,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000,
2100,2200,2300,2400,2500,2400,2300,2200,2100,2000,1900,1800,1700,1600,1500};
void delay_ms(uint x)
{
	uint i;
	while(x--)for(i=0;i<125;i++);
}
void InitTimer(void)
{
	TMOD=0x11;//????0,1
	TH0=-20000/256;//??20MS,20MS?????
	TL0=-20000%256;
	TH1=-1500/256;//??1.5MS,??????0?
	TL1=-1500%256;
	EA=1;//???
	TR0=1;//????0
	ET0=1;
	TR1=1;//????1
	ET1=1;
}
void timer0(void) interrupt 1//???0????
{
	pwm=1;
	TH0=-20000/256;
	TL0=-20000%256;
	TR1=1;
}

void timer1(void) interrupt 3//???1????
{
	pwm=0;
	TH1=-pwm_value/256;
	TL1=-pwm_value%256;
	TR1=0;
}
void main(void)//???
{
	uchar i;
	InitTimer();
	pwm_value=1500;
	while(1)
	{
		for(i=0;i<40;i++)
		{
			pwm_value=value[i];//???????????????
			delay_ms(500);
		}
	}
}
