#include "reg52.h"			 

typedef unsigned int u16;	 
typedef unsigned char u8;

sbit k3=P3^2;  
sbit led1=P0^0;	
sbit k4=P3^3;
sbit led2=P0^1;

void delay(u16 i)
{
	while(i--);	
}
void main()
{	
	EA=1;
	IT0=1;
	EX0=1;
	IT1=1;
	EX1=1;
	while(1);		
}

void Int0()	interrupt 0		
{
	delay(1000);	
	if(k3==0)
	{
		led1=~led1;
	}
}
void Int1()	interrupt 2	
{
	delay(1000);	
	if(k4==0)
	{
		led2=~led2;
	}
}
