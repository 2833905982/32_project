#include <reg52.h>

sbit IN1 = P0^0;
sbit IN2 = P0^1;
sbit IN3 = P0^2;
sbit IN4 = P0^3;
sbit lhuidu = P3^2;				//左边的灰度返回值。
sbit rhuidu = P3^3;				//右边的灰度返回值。

unsigned char i;

void main()

{

TMOD=0x01;								//让定时器以1模式打开。

TH0=0xff;									//定时器1微秒。
TL0=0xf7;

EA=1;											//打开总中断。

ET0=1;										//定时器0，打开。
	
TR0=1;										//启动定时器。

while(1)

{
	if(i<10)							//左边的电机，小于50个毫秒时，电机正转。
	{
		IN1 = 0;
		IN2 = 1;
	}
	if(i>90)							//左边的电机，在大于50个毫秒时，电机停止供电。
	{
		IN1 = 0;
		IN2 = 0;
	}
		if(i<10)						//右边的电机，小于50个毫秒时，电机正转。
	{
		IN3 = 0;
		IN4 = 1;
	}
	if(i>90)							//右边的电机，在大于50个毫秒时，电机停止供电。
	{
		IN3 = 0;
		IN4 = 0;
	}
	if(i>100)							//当i的值大于100时，归零。
	{
		i=0;
	}
}

}
void time0()
{
	TH0=0xff;	
	TL0=0xf7;
	i++;
}


void time1() interrupt 0		//外部中断

{
	if(lhuidu==1)						//已出界右轮加速。
	{
	if(i<10)							//左边的电机，小于50个毫秒时，电机正转。
	{
		IN1 = 0;
		IN2 = 1;
	}
	if(i>90)							//左边的电机，在大于50个毫秒时，电机停止供电。
	{
		IN1 = 0;
		IN2 = 0;
	}
		if(i<50)						//右边的电机，小于50个毫秒时，电机正转。
	{
		IN3 = 0;
		IN4 = 1;
	}
	if(i>50)							//右边的电机，在大于50个毫秒时，电机停止供电。
	{
		IN3 = 0;
		IN4 = 0;
	}
	if(i>100)							//当i的值大于100时，归零。
	{
		i=0;
	}
	}
	if(rhuidu==1)						//已向内偏移，左轮加速。
	{
	if(i<50)							//左边的电机，小于50个毫秒时，电机正转。
	{
		IN1 = 0;
		IN2 = 1;
	}
	if(i>50)							//左边的电机，在大于50个毫秒时，电机停止供电。
	{
		IN1 = 0;
		IN2 = 0;
	}
		if(i<50)						//右边的电机，小于50个毫秒时，电机正转。
	{
		IN3 = 0;
		IN4 = 1;
	}
	if(i>90)							//右边的电机，在大于50个毫秒时，电机停止供电。
	{
		IN3 = 0;
		IN4 = 0;
	}
	if(i>100)							//当i的值大于100时，归零。
	{
		i=0;
	}
	}
	

}

