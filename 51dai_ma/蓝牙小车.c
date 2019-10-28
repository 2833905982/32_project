#include<reg52.h>

#define uchar unsigned char

#define uint  unsigned int

sbit IN1 = P1^0;
sbit IN2 = P1^1;
sbit IN3 = P1^2;
sbit IN4 = P1^3;
sbit ENA = P1^4;
sbit ENB = P1^5;

void back();
void qianjin();
void turnleft();
void turnright();
void stop();

char buf;

void main(void)

{

SCON=0x50;						//设置串口工作方式01010000

PCON=0x00;

TMOD=0x20;						//定时器模式
  
EA=1;									//打开总中断

ES=1;									//打开串口中断

TL1=0xfd;							//波特率为9600
TH1=0xfd;

TR1=1;


while(1);

}

 
//传行服务函数

void serial() interrupt 4

	{

	ES=0;								//暂时关闭串口中断

	RI=0;

	buf=SBUF;						//把收到的信息从SBUF存到buf
		
	switch(buf)

	{

	case 1: back();break;  
	case 2: qianjin();break;	

	case 3: turnleft();break;

	case 4: turnright();break;
	case 5: stop();break;

	}

	ES=1;	

 

}
void turnleft()
{
  ENA = 1;
	ENB = 1;
	IN1 = 0;
	IN2 = 1;
	IN3 = 1;
	IN4 = 0;
}
void turnright()
{
  ENA = 1;
	ENB = 1;
	IN1 = 1;
	IN2 = 0;
	IN3 = 0;
	IN4 = 1;
}
void back()
{
	ENA = 1;
	ENB = 1;
	IN1 = 1;
	IN2 = 0;
	IN3 = 1;
	IN4 = 0;
}
void qianjin()
{
	ENA = 1;
	ENB = 1;
		IN1 = 0;
	IN2 = 1;
	IN3 = 0;
	IN4 = 1;
	
}
void stop()
{
	ENA = 0;
	ENB = 0;
}
