#include <reg52.h>

void delay(void)
{
	int i;
	for(i=0;i<30000;i++);
}
int main()
{
	int cnt=0;								
	while(1)
	{
		for(cnt=0;cnt<8;cnt++)
		{
			P0 = ~(0x01 << cnt);	
			delay();
		}
		for(cnt=0;cnt<7;cnt++)
		{
			P0 = ~(0x40 >> cnt);
			delay();
		}
	}
}	