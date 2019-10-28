#include "reg52.h"			 

//sbit k3=P3^2;  
sbit led1=P1^4;	
//sbit k4=P3^3;
sbit led2=P1^5;

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
		led1=~led1;
}
void Int1()	interrupt 2	
{
		led2=~led2;
}
