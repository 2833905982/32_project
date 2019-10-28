#include <reg52.h>

sbit KEY_IN_1  = P2^4;
sbit KEY_IN_2  = P2^5;
sbit KEY_IN_3  = P2^6;

sbit KEY_OUT_1 = P2^3;
sbit KEY_OUT_2 = P2^2;
sbit KEY_OUT_3 = P2^1;

unsigned char KeySta[3][3] = {{1, 1, 1},{1, 1, 1},{1, 1, 1}};
unsigned led[9]={0x7F,0xBF,0xDF,0xEF,0xF7,0xFB,0xFD,0xFE,0xFF};
unsigned char cnt = 0;

void shaomiao();
//void xiaodou();
void delay();
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
    while (1)
    {
				shaomiao();			 
        for (i=0; i<3; i++)  
        {
            for (j=0; j<3; j++)
            {
									if(cnt%2==0)
									{
                   // if (backup[i][j] != 0)         
                    //{
                            /* A1=D[i*3+j];
														 B1=E[i*3+j];
														 C1=F[i*3+j];*/
											P0 = led[i*3+j];
											
                    //}
									}  
								else if(cnt%2!=0)
									{
										P0=0xFF;
										
									}
								cnt++;
                }
							}
            }
        }
    

void shaomiao()
{
			 KEY_OUT_1 = 0;
			 KEY_OUT_2 = 1;
			 KEY_OUT_3 = 1;
       if(KEY_IN_1 == 0)
			{delay();
				if(KEY_IN_1 ==0)
			{
				while(KEY_IN_1 != 0);
					delay();
				while(KEY_IN_1 != 0);
				
					KeySta[0][0]=0;
			}	
			}
			 else
				if(KEY_IN_2 == 0)
			{delay();
				if(KEY_IN_2 ==0)
			{
				while(KEY_IN_2 != 0);
					delay();
				while(KEY_IN_2 != 0);
			} 
KeySta[0][1]=0; }
			 else if(KEY_IN_3 == 0){
					delay();
				if(KEY_IN_3 ==0)
			{
				while(KEY_IN_3 != 0);
					delay();
				while(KEY_IN_3 != 0);
			} 
KeySta[0][2]=0; }
			 
			 KEY_OUT_1 = 1;
			 KEY_OUT_2 = 0;
			 KEY_OUT_3 = 1;

			        if(KEY_IN_1 == 0)
			{delay();
				if(KEY_IN_1 ==0)
			{
				while(KEY_IN_1 != 0);
					delay();
				while(KEY_IN_1 != 0);
				
					KeySta[1][0]=0;
			}	
			}
			 else
				if(KEY_IN_2 == 0)
			{delay();
				if(KEY_IN_2 ==0)
			{
				while(KEY_IN_2 != 0);
					delay();
				while(KEY_IN_2 != 0);
			} 
KeySta[1][1]=0; }
			 else if(KEY_IN_3 == 0){
					delay();
				if(KEY_IN_3 ==0)
			{
				while(KEY_IN_3 != 0);
					delay();
				while(KEY_IN_3 != 0);
			} 
KeySta[1][2]=0; }
			
		
			 KEY_OUT_1 = 1;
			 KEY_OUT_2 = 1;
			 KEY_OUT_3 = 0;
			        if(KEY_IN_1 == 0)
			{delay();
				if(KEY_IN_1 ==0)
			{
				while(KEY_IN_1 != 0);
					delay();
				while(KEY_IN_1 != 0);
				
					KeySta[2][0]=0;
			}	
			}
			 else
				if(KEY_IN_2 == 0)
			{delay();
				if(KEY_IN_2 ==0)
			{
				while(KEY_IN_2 != 0);
					delay();
				while(KEY_IN_2 != 0);
			} 
KeySta[2][1]=0; }
			 else if(KEY_IN_3 == 0){
					delay();
				if(KEY_IN_3 ==0)
			{
				while(KEY_IN_3 != 0);
					delay();
				while(KEY_IN_3 != 0);
			} 
KeySta[2][2]=0; }
}
void delay()
{
	int i;
	for(i=0;i<1000;i++);
}
/*int xiaodou(int key4)
{
bit keybuf = 1; //?????,??????????
bit backup = 1;
	
	keybuf = KEY4; //????????
if (keybuf != backup) //???????????????????
{
delay(); //???? 10ms
?????? 51 ???-C ??? (??:2014-10-24) http://www.kingst.org
111
if (keybuf == KEY4) //????????????,?????
{
if (backup == 0) //?????? 0,??????????
{

	
	
	
	
	
	
}
backup = keybuf; //????????,????????
}*/