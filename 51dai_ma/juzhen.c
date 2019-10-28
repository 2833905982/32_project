#include <reg52.h>

sbit KEY_IN_1  = P2^4;
sbit KEY_IN_2  = P2^5;
sbit KEY_IN_3  = P2^6;

sbit KEY_OUT_1 = P2^3;
sbit KEY_OUT_2 = P2^2;
sbit KEY_OUT_3 = P2^1;
sbit A1 = P0^0;
sbit B1 = P0^1;
sbit C1 = P0^2;

sbit B0 = P3^3;

unsigned D[8]={0,1,0,1,0,1,0,1};
unsigned E[8]={0,0,1,1,0,0,1,1};
unsigned F[8]={0,0,0,0,1,1,1,1};


unsigned char KeySta[3][3] = {{1, 1, 1},{1, 1, 1},{1, 1, 1}};
//unsigned HC138[8]={0x00,0x80,0x40,0xC0,0x20,0xA0,0x60,0xE0};
unsigned char cnt = 0;


//void shaomiao();
void delay(void);
main()
{
    unsigned char i, j;
    unsigned char backup[3][3] = {{1, 1, 1},{1, 1, 1},{1, 1, 1}};
	
		KEY_IN_1 = 1;
		KEY_IN_2 = 1;
		KEY_IN_3 = 1;
	
		KEY_OUT_1 =1;
		KEY_OUT_2 =1;
		KEY_OUT_3 =1;
		B0 = 0;
    while (1)
    {
			//shaomiao();
			 KEY_OUT_1 = 0;
			 KEY_OUT_2 = 1;
			 KEY_OUT_3 = 1;
       if(KEY_IN_1 == 0){KeySta[0][0]=0; delay();}
			 else if(KEY_IN_2 == 0){KeySta[0][1]=0; delay();}
			 else if(KEY_IN_3 == 0){KeySta[0][2]=0; delay();}
			 
        for (i=0; i<3; i++)  
        {
            for (j=0; j<3; j++)
            {
							
                if (backup[i][j] != KeySta[i][j])  
                {
								
									//if(cnt%2 == 0)
								//	{
                    if (backup[i][j] != 0)         
                    {
                             A1=D[i*3+j];
														 B1=E[i*3+j];
														 C1=F[i*3+j];
                    }
									//}  
								/*	if(cnt%2 != 0)
									{
										B0 = 1;
									}
										cnt++;	*/
                }
            }
        }
    }
}
		/*
void shaomiao()
{
			 KEY_OUT_1 = 0;
			 KEY_OUT_2 = 1;
			 KEY_OUT_3 = 1;
       if(KEY_IN_1 == 0){KeySta[0][0]=0; delay();}
			 else if(KEY_IN_2 == 0){KeySta[0][1]=0; delay();}
			 else if(KEY_IN_3 == 0){KeySta[0][2]=0; delay();}
			 
			 KEY_OUT_1 = 1;
			 KEY_OUT_2 = 0;
			 KEY_OUT_3 = 1;
			 
			 if(KEY_IN_1 == 0){KeySta[1][0]=0; delay();}
			 else if(KEY_IN_2 == 0){KeySta[1][1]=0; delay();}
			 else if(KEY_IN_3 == 0){KeySta[1][2]=0; delay();}
		
			 KEY_OUT_1 = 1;
			 KEY_OUT_2 = 1;
			 KEY_OUT_3 = 0;
			 if(KEY_IN_1 == 0){KeySta[2][0]=0;delay();}
			 else if(KEY_IN_2 == 0){KeySta[2][1]=0; delay();}
			 else if(KEY_IN_3 == 0){KeySta[2][2]=0; delay();}
}
*/
void delay(void)
{
	int i;
	for(i=0;i<1000;i++);
}