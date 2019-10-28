#include<reg51.h>

#define uint unsigned int

#define uchar unsigned char


sbit PWM=P2^0;						// P2.0输出pwm
uchar time; 							// 定义一个时间函数


void main()

{

TMOD=0x01;								//让定时器以1模式打开

TH0=0xff;									//定时器1微秒
TL0=0xf7;

EA=1;											//打开总中断

ET0=1;										//定时器0，打开。
	
TR0=1;										//启动定时器。

while(1)

{

}

}


void tim0() interrupt 1

{

TR0=0;										//关闭定时器，重新赋值。

TH0=0xff;									//定时1微秒。

TL0=0xf7;

TR0=1;										//打开定时器。


time++;

if(time>=100)							//大于100归零。

time=0;

if(time<=30) 							//占空比为N，此时既是30.

PWM=1;

else PWM=0;

}

