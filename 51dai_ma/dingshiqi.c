#include <reg52.h>

sbit LED = P0^0;

int main()
{
	unsigned cnt = 0;
	TMOD = 0x01;							//设置T0的模式为1；
	TH0  = 0xB8;							//设置T0的初始值是；0xB8。
	TL0  = 0x00;							
	TR0  = 1;									//启动定时器。
	
	while(1)
	{
		if(TF0 == 1)						//判断是否溢出。
		{
			TF0 = 0;							//T0溢出后归零，
			TH0 = 0xB8;						//重新赋值。
			TL0 = 0x00;
			cnt++;								//计数后自增。
			if(cnt >= 50)					//判断溢出的次数是否达到50次。
			{
				cnt = 0;						//达到50次后归零。
				LED = ~LED;					//取反，小灯闪烁。
			}
		}
	}
}
	