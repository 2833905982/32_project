#include <reg52.h>														//舵机每次旋转90度代码

typedef unsigned int uint;
typedef unsigned char uchar;

sbit pwm=P0^3;																//定义IO口

uint pwm_value=1500;													//定义一个占空比

uint value[]={500,1500,2500,1500};
//500(-90),1000,1500,2000,2500
void delay_ms(uint x)
{
	uint i;
	while(x--)for(i=0;i<125;i++);
}
void InitTimer(void)
{
	TMOD=0x11;																	//定义定时器的使用模式
	TH0=-20000/256;															//定时器0，的时间。20毫秒。
	TL0=-20000%256;
	TH1=-1500/256;															//定时器1。
	TL1=-1500%256;
	EA=1;																				//打开总中断
	TR0=1;																			//打开定时器0
	ET0=1;
	TR1=1;																			//打开定时器1
	ET1=1;
}
void timer0(void) interrupt 1									//定时器0，为20毫秒，为定时周期
{
	pwm=1;
	TH0=-20000/256;
	TL0=-20000%256;
	TR1=1;
}

void timer1(void) interrupt 3									//定时器1，打开传值
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
			pwm_value=value[i];											//数组，调节占空比。
			delay_ms(500);	
		}
	}
}
