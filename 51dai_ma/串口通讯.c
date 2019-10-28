//#include <reg52.h>
//#define unchar unsigned char
//#define uint unsigned int

//unchar buf;
//unchar i;
//sbit IN1 = P1^0;
//sbit IN2 = P1^1;
//sbit IN3 = P1^2;
//sbit IN4 = P1^3;
//sbit ENA = P1^4;
//sbit ENB = P1^5;

//void stop();
//void qianjin();
//void turnleft();
//void turnright();

//void main()
//{
//	SCON = 0x50;
//	PCON = 0x00;
//	TMOD = 0x20;
//	EA = 1;


//  TH0=0xff;									//定时器1微秒。
//  TL0=0xf7;

//  ET0=1;										//定时器0，打开。
//	
//  TR0=1;										//启动定时器。

//	ES = 1;
//	TL1 = 0xFD;
//	TH1 = 0xFD;
//	TR1 = 1;
//	while(1);
//}

//void fuzhi() interrupt 4
//{
//	ES = 0;
//	RI = 0;
//	buf = SBUF;
//	switch(buf)
//	{
//		case 0x00: qianjin();break;
//		case 0x01: turnright();break;
//		case 0x02: turnleft();break;
//		case 0x03: stop();break;
//		default :break;
//	}
//	ES = 1;
//}
//void time0() interrupt 1
//{
//	TH0=0xff;	
//	TL0=0xf7;
//	i++;
//}

//void stop()
//{
//	ENA = 0;
//	ENB = 0;
//}
//void qianjin()
//{
//	while(1)
//{
//	if(i<50)							//左边的电机，小于50个毫秒时，电机正转。
//	{
//		IN1 = 0;
//		IN2 = 1;
//	}
//	if(i>50)							//左边的电机，在大于50个毫秒时，电机停止供电。
//	{
//		IN1 = 0;
//		IN2 = 0;
//	}
//		if(i<50)						//右边的电机，小于50个毫秒时，电机正转。
//	{
//		IN3 = 0;
//		IN4 = 1;
//	}
//	if(i>50)							//右边的电机，在大于50个毫秒时，电机停止供电。
//	{
//		IN3 = 0;
//		IN4 = 0;
//	}
//	if(i>100)							//当i的值大于100时，归零。
//	{
//		i=0;
//	}
//}
//}
//void turnleft()
//{
//  ENA = 0;
//	ENB = 1;
//}
//void turnright()
//{
//  ENA = 1;
//	ENB = 0;
//}

#include<reg52.h>

#define uchar unsigned char

#define uint  unsigned int

sbit IN1 = P1^0;
sbit IN2 = P1^1;
sbit IN3 = P1^2;
sbit IN4 = P1^3;
sbit ENA = P1^4;
sbit ENB = P1^5;

void stop();
void qianjin();
void turnleft();
void turnright();


uchar buf;

void main(void)

{

SCON=0x50;

PCON=0x00;

TMOD=0x20;

EA=1;

ES=1;

TL1=0xfd;
TH1=0xfd;

TR1=1;
qianjin();
while(1);

}

 


void serial() interrupt 4

	{

	ES=0;		

	RI=0;

	buf=SBUF;
		
	switch(buf)

	{

	case 0x31: stop();break;  
//	case 0x32: qianjin();break;	

	case 0x33: turnleft();break;

	case 0x34: turnright();break;

	}

	ES=1;	

 

}
void turnleft()
{
  ENA = 0;
	ENB = 1;
}
void turnright()
{
  ENA = 1;
	ENB = 0;
}
void stop()
{
	ENA = 0;
	ENB = 0;
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
