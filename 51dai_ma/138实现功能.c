#include <reg52.h>

/*sbit LED1 = P0^0;
sbit LED2 = P0^1;
sbit LED3 = P0^2;
sbit LED4 = P0^3;
sbit LED5 = P0^4;
sbit LED6 = P0^5;
sbit LED7 = P0^6;
sbit LED8 = P0^7;
*/
sbit A00 = P0^0;
sbit A11 = P0^1;
sbit A22 = P0^2;
sbit E1 = P0^3;
//sbit E2 = P0^4;
//sbit E3 = P0^5;

sbit KEYIN1 = P2^4;
sbit KEYIN2 = P2^5;
sbit KEYIN3 = P2^6;

sbit KEYOUT1 = P2^0;
sbit KEYOUT2 = P2^1;
sbit KEYOUT3 = P2^2;
A0[8]={0,1,0,1,0,1,0,1};
A1[8]={0,0,1,1,0,0,1,1};
A2[8]={0,0,0,0,1,1,1,1};

void delay();
int main()
{
	unsigned char keybuf[3][3] = {{1,1,1},{1,1,1},{1,1,1}};
	unsigned char backup[3][3] = {{1,1,1},{1,1,1},{1,1,1}};
	int a=3,b=3,c=3,i=3,d=3,e=3,f=3,g=3,h=3;
//	unsigned char i,j;
//	KEYOUT = 0;
//	LED = 1;
	
	while(1)
	{
			KEYOUT1 = 0;
			KEYOUT2 = 1;
			KEYOUT3 = 1;
			keybuf[0][0] = KEYIN1;
			if(keybuf[0][0] != backup[0][0])
			{
				delay();
				if(keybuf[0][0] == KEYIN1)
				{
					if(backup[0][0] == 0)
					{
						if(a%2!=0)
						{
							E1 = 0;								//138低电有效
							A00=A0[0];
							A11=A1[0];
							A22=A2[0];
						}
						if(a%2==0)
						{
							E1 = 1;
						}
						a++;
					}
				}
					backup[0][0] = keybuf[0][0];	
			}
			
						keybuf[0][1] = KEYIN2;
			if(keybuf[0][1] != backup[0][1])
			{
				delay();
				if(keybuf[0][1] == KEYIN2)
				{
					if(backup[0][1] == 0)
					{
						if(b%2!=0)
						{
							E1 = 0;								//138低电有效
							A00=A0[1];
							A11=A1[1];
							A22=A2[1];
						}
						if(b%2==0)
						{
							E1 = 1;
						}
						b++;
						//LED2 = ~LED2;
					}
				}
					backup[0][1] = keybuf[0][1];	
			}
			
						keybuf[0][2] = KEYIN3;
			if(keybuf[0][2] != backup[0][2])
			{
				delay();
				if(keybuf[0][2] == KEYIN3)
				{
					if(backup[0][2] == 0)
					{
						if(c%2!=0)
						{
							E1 = 0;								//138低电有效
							A00=A0[2];
							A11=A1[2];
							A22=A2[2];
						}
						if(c%2==0)
						{
							E1 = 1;
						}
						c++;
				//		LED3 = ~LED3;
					}
				}
					backup[0][2] = keybuf[0][2];	
			}
			
					KEYOUT1 = 1;
					KEYOUT2 = 0;
					KEYOUT3 = 1;
					keybuf[1][0] = KEYIN1;
			if(keybuf[1][0] != backup[1][0])
			{
				delay();
				if(keybuf[1][0] == KEYIN1)
				{
					if(backup[1][0] == 0)
					{
						if(i%2!=0)
						{
							E1 = 0;								//138低电有效
							A00=A0[3];
							A11=A1[3];
							A22=A2[3];
						}
						if(i%2==0)
						{
							E1 = 1;
						}
						i++;						
					//	LED4 = ~LED4;
					}
				}
					backup[1][0] = keybuf[1][0];	
			}
					
					keybuf[1][1] = KEYIN2;
			if(keybuf[1][1] != backup[1][1])
			{
				delay();
				if(keybuf[1][1] == KEYIN2)
				{
					if(backup[1][1] == 0)
					{
						if(e%2!=0)
						{
							E1 = 0;								//138低电有效
							A00=A0[4];
							A11=A1[4];
							A22=A2[4];
						}
						if(e%2==0)
						{
							E1 = 1;
						}
						e++;						
					//	LED5 = ~LED5;
					}
				}
					backup[1][1] = keybuf[1][1];	
			}
			
						keybuf[1][2] = KEYIN3;
			if(keybuf[1][2] != backup[1][2])
			{
				delay();
				if(keybuf[1][2] == KEYIN3)
				{
					if(backup[1][2] == 0)
					{
						if(f%2!=0)
						{
							E1 = 0;								//138低电有效
							A00=A0[5];
							A11=A1[5];
							A22=A2[5];
						}
						if(f%2==0)
						{
							E1 = 1;
						}
						f++;						
					//	LED6 = ~LED6;
					}
				}
					backup[1][2] = keybuf[1][2];	
			}
					KEYOUT1 = 1;
					KEYOUT2 = 1;
					KEYOUT3 = 0;
						keybuf[2][0] = KEYIN1;
			if(keybuf[2][0] != backup[2][0])
			{
				delay();
				if(keybuf[2][0] == KEYIN1)
				{
					if(backup[2][0] == 0)
					{
						if(g%2!=0)
						{
							E1 = 0;								//138低电有效
							A00=A0[6];
							A11=A1[6];
							A22=A2[6];
						}
						if(g%2==0)
						{
							E1 = 1;
						}
						g++;						
					//	LED7 = ~LED7;
					}
				}
					backup[2][0] = keybuf[2][0];	
			}
					
					keybuf[2][1] = KEYIN2;
			if(keybuf[2][1] != backup[2][1])
			{
				delay();
				if(keybuf[2][1] == KEYIN2)
				{
					if(backup[2][1] == 0)
					{
						if(h%2!=0)
						{
							E1 = 0;								//138低电有效
							A00=A0[7];
							A11=A1[7];
							A22=A2[7];
						}
						if(h%2==0)
						{
							E1 = 1;
						}
						h++;						
					//	LED8 = ~LED8;
					}
				}
					backup[2][1] = keybuf[2][1];	
			}
			
		/*				keybuf[2][2] = KEYIN3;
			if(keybuf[2][2] != backup[2][2])
			{
				delay();
				if(keybuf[2][2] == KEYIN1)
				{
					if(backup[2][2] == 0)
					{
						LED = ~LED;
					}
				}
					backup[2][2] = keybuf[2][2];	
			}
		*/	
	}
}
void delay()
{
	unsigned int i=1000;
	while(i--);
}