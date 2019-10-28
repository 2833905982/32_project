#include <reg52.h>

sbit IN1 = P0^0;
sbit IN2 = P0^1;
sbit IN3 = P0^2;
sbit IN4 = P0^3;

unsigned char i=0;

int main()
{
	
	EA = 1;
	TMOD = 0x01;
	TH0 = 0xFC;						//定时1毫秒。
	TL0 = 0x67;
	ET0 = 1;
	TR0 = 1;
	while(1)
	{
	if(i<1)							//左边的电机，小于50个毫秒时，电机正转。
	{
		IN1 = 0;
		IN2 = 1;
	}
	if(i>99)							//左边的电机，在大于50个毫秒时，电机停止供电。
	{
		IN1 = 0;
		IN2 = 0;
	}
		if(i<1)						//右边的电机，小于50个毫秒时，电机正转。
	{
		IN3 = 0;
		IN4 = 1;
	}
	if(i>99)							//右边的电机，在大于50个毫秒时，电机停止供电。
	{
		IN3 = 0;
		IN4 = 0;
	}
	if(i>100)							//当i的值大于100时，归零。
	{
		i=0;
	}
	return 0;
}
}
void interrupttime() interrupt 1					//定时器，中断函数，每一毫秒，数字加一。
{
	TH0 = 0xFC;
	TL0 = 0x67;
	i++;
}