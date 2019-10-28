#include <reg52.h>														//??????90???

typedef unsigned int uint;
typedef unsigned char uchar;

sbit pwm=P0^3;																//??IO?

uint pwm_value=1500;													//???????

uint value[]={500,1500,2500,1500};
//500(-90),1000,1500,2000,2500
void delay_ms(uint x)
{
	uint i;
	while(x--)for(i=0;i<125;i++);
}
void InitTimer(void)
{
	TMOD=0x11;																	//??????????
	TH0=-20000/256;															//???0,????20???
	TL0=-20000%256;
	TH1=-1500/256;															//???1?
	TL1=-1500%256;
	EA=1;																				//?????
	TR0=1;																			//?????0
	ET0=1;
	TR1=1;																			//?????1
	ET1=1;
}
void timer0(void) interrupt 1									//???0,?20??,?????
{
	pwm=1;
	TH0=-20000/256;
	TL0=-20000%256;
	TR1=1;
}

void timer1(void) interrupt 3									//???1,????
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
		for(i=0;i<4;i++)
		{
			pwm_value=value[i];											//??,??????
			delay_ms(500);	
		}
	}
}
