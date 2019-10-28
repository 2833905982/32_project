#include<reg52.h>

sbit A0=P0^0;
sbit A1=P0^1;
sbit A2=P0^2;
//sbit DIY=P3^2;
//sbit E1=P3^3;
sbit KeyOut1=P2^3;
sbit KeyOut2=P2^2;
sbit KeyOut3=P2^1;
sbit KeyIn1=P2^4;
sbit KeyIn2=P2^5;
sbit KeyIn3=P2^6;
#define uInt16 unsigned int
#define uChar8 unsigned char
#define	KEYPORT	 P2
uChar8 g_ucKeyNum=9;
//unsigned HC138[8]={0x00,0x80,0x40,0xC0,0x20,0xA0,0x60,0xE0};
void DelayMS(uInt16 ValMS)
{
	uInt16 uiVal,ujVal;
	for(uiVal = 0; uiVal < ValMS; uiVal++)
		for(ujVal = 0; ujVal < 11100; ujVal++);
}
void ScanKey(void)
{
	uChar8 ucTemp;
	 unsigned HC138[9]={0x7F,0xBF,0xDF,0xEF,0xF7,0xFB,0xFD,0xFE,0xFF};
	KEYPORT = 0xFE;		  			//?????
	ucTemp = KEYPORT;	  			//????????
	if(ucTemp != 0xFB)		 		//?????0xF0???????
	{
		DelayMS(1000);                 //??
		ucTemp = KEYPORT;			//????
		if(ucTemp != 0xFE)			//????
		{
			ucTemp = KEYPORT;		//???
			switch(ucTemp)			//????????
			{
				case 0xEE: g_ucKeyNum=HC138[0] ; ;break;
				case 0xDE: g_ucKeyNum=HC138[1] ;break;
				case 0xBE: g_ucKeyNum=HC138[2] ;break;
				//case 0x7e:g_ucKeyNum = 3;break;        
			}
			while(KEYPORT != 0xFE);	//??????
		}
	}	
	KEYPORT = 0xFD;
	ucTemp = KEYPORT;
	if(ucTemp != 0xFD)
	{
		DelayMS(1000);
		ucTemp = KEYPORT;
		if(ucTemp != 0xFD)
		{
			ucTemp = KEYPORT;
			switch(ucTemp)
			{
				case 0xED: g_ucKeyNum=HC138[3];break;
				case 0xDD: g_ucKeyNum=HC138[4];break;
				case 0xBD: g_ucKeyNum=HC138[5];break;
				        
			}
			while(KEYPORT != 0xFD);
		}
	}	
	KEYPORT = 0xFB;
	ucTemp = KEYPORT;
	if(ucTemp != 0xFB)
	{
		DelayMS(1000);
		ucTemp = KEYPORT;
		if(ucTemp != 0xFB)
		{
			ucTemp = KEYPORT;
			switch(ucTemp)
			{
				case 0xEB: g_ucKeyNum=HC138[6] ;break;
				case 0xDB: g_ucKeyNum=HC138[7] ;break;
				case 0xBB: g_ucKeyNum=HC138[1] ;break;
			        
			}
			while(KEYPORT != 0xFB);
		}
	}	
}

/*void delay(void)
{
	int i;
	for(i=0;i<10;i++);
}
  */
void main(void)
		//E1=0;
		
{	
		

	while(1)
	{	
	//unsigned HC138[8]={0x00,0x80,0x40,0xC0,0x20,0xA0,0x60,0xE0};
	//	DIY=1;
		ScanKey();
		
		

		
	}

}
