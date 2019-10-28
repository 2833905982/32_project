#include<reg52.h>

char code high[9]={0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe,0xff};

char KeySta[3] = {0x3b,0x3d,0x3e};

void delay(void)
{
   int i;

   for (i=0 ;i<1000;i++);
}

main()
{
   int i,b;
   char back;
   b=10;
   while(1){
	  for (i=0; i<3; i++)  
        {
		        P2 = KeySta[i];
				back = P2;
                if (back != KeySta[i])  
                {
				    delay();
					back = P2;
                    if(back != KeySta[i])         
                    {
						 if (back == (0x37 & KeySta[i])&& b != i*3){
						 P1 =  high[i*3];
						 b = i*3;
						 }	else
						 if (back == (0x2f & KeySta[i])&& b!= 1+i*3){
						 P1 =  high[1+i*3];
						 b =  1+i*3;
						 } else
						 if (back == (0x1f & KeySta[i])&& b != 2+i*3){
						 P1 =  high[2+i*3];
						 b =  2+i*3;
						 }  else {
						 P1 = high[8];
						 b = 10;
						 }    
                    }  
                }
         }
    }
}
