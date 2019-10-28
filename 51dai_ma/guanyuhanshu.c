#include <reg52.h>

unsigned char code ledchar[]=															//定义一系列的数字，让数码管显示这些数字。
{				0xC0,0xF9,0xA4,0xB0,0x99,
				0x92,0x82,0xF8,0x80,0x90,
				0x88,0x83,0xC6,0xA1,0x86,0x8E
};
unsigned char ledbuf[6]=																	//定义所有的数码管，让六个数码管循环显示。
{
				0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
};
unsigned char flag = 0;
unsigned char i = 0;

void xianshi();

int main()																								//主函数运行主要的程序。
{
	TMOD =0x01;																							//定义使用T0的模式为第一种。
	TH0  = 0xFC;																						//为T0赋初值为FC67,定时为1毫秒。
	TL0  = 0x67;
	EA   = 1;																								//打开中断的总开关。
	ET0  = 1;																								//使能总中断。
	TR0  = 1;																								//启动总中断T0。

	while(1)																								//让数码管从零开始显示数字，使它成为一个计数器。
	{
	xianshi();
	}
}
void xianshi()
{
	unsigned long sec = 0;
		if(flag==1)
		{
			flag=0;
			sec++;
			ledbuf[0]=ledchar[sec%10];													//相除取余，让数码管显示各个数字。
			ledbuf[1]=ledchar[sec/10%10];
			ledbuf[2]=ledchar[sec/100%10];
			ledbuf[3]=ledchar[sec/1000%10];
			ledbuf[4]=ledchar[sec/10000%10];
			ledbuf[5]=ledchar[sec/100000%10];
		}
}
void interruptTimer() interrupt 1													//设置中断。
{
	unsigned cnt = 0;
	TH0 = 0xFC;																							//重新赋值。
	TR0 = 0x67;
	cnt++;
	if(cnt>=1000)
	{
		cnt=0;
		flag=1;
	}
	P0 = 0xFF;
	switch(i)																									//刷新数码管，刷新时间1毫秒。
	{
		case 0: i++;P0=ledbuf[0];break;
		case 1: i++;P0=ledbuf[1];break;
		case 2: i++;P0=ledbuf[2];break;
		case 3: i++;P0=ledbuf[3];break;
		case 4: i++;P0=ledbuf[4];break;
		case 5: i=0;P0=ledbuf[5];break;
		default : break;
	}
}