#include <reg52.h>


void delay();
int main()
{
	while(1)
	{
	unsigned char cnt; 
	for(cnt=0;cnt<8;cnt++)
	{
		P2 = ~(0x01 << cnt);
		delay();
	}
	}	
}
void delay()
{
	unsigned int i;
	for(i=0;i<30000;i++);
}