#include<reg52.h>
	sbit hu1=P3^2; 
	sbit hu2=P3^3; 
	sbit IN1=P0^0;
	sbit IN2=P0^1;
	sbit IN3=P0^2;
	sbit IN4=P0^3;
	sbit ENA=P2^4;
	sbit ENB=P2^5;
	sbit led1=P1^1;
	sbit led2=P1^2;
	int i=0;
	int j=0;
	 void time(void)
  {
    TMOD = 0x11;
	TL0 = 0x18;
	TH0 = 0xFC;
    TR0=1;
	EA=1;
	ET0=1;
  }
  void main(void)
  {
      time();
	  IN1=1;
	  IN3=0;
	  IN2=0;
	  IN4=1;
	  led1=1;
	  led2=1;
	  EA=1;
	  EX0=1;
	  EX1=1;
	  IT0=0;
	  IT1=0; 
     while(1);
  }
   void time1(void) interrupt 1
  {
	TL0 = 0x18;	
   	TH0 = 0xFC;
	i++;
	j++;
	   
	if(i>=50)
	 i=0;
	if(i<1) 
	 ENA=1;
	else
	 ENA=0;

	if(j>=50)
     j=0;
    if(j<1)
	 ENB=1;
	else
	 ENB=0;
  }
  void time0(void)interrupt 0
  {
       
	   ENA=1;
	   ENB=0;
  }
  void time2(void) interrupt 2
  {
      
	   ENA=0;
	   ENB=1;
  }
