#include <reg52.h>

sbit IN1 = P0^0;
sbit IN2 = P0^1;
sbit IN3 = P0^2;
sbit IN4 = P0^3;

unsigned char i=0;

int main()
{
	
	EA = 1;
	TMOD = 0x01;
	TH0 = 0xFC;						//��ʱ1���롣
	TL0 = 0x67;
	ET0 = 1;
	TR0 = 1;
	while(1)
	{
	if(i<1)							//��ߵĵ����С��50������ʱ�������ת��
	{
		IN1 = 0;
		IN2 = 1;
	}
	if(i>99)							//��ߵĵ�����ڴ���50������ʱ�����ֹͣ���硣
	{
		IN1 = 0;
		IN2 = 0;
	}
		if(i<1)						//�ұߵĵ����С��50������ʱ�������ת��
	{
		IN3 = 0;
		IN4 = 1;
	}
	if(i>99)							//�ұߵĵ�����ڴ���50������ʱ�����ֹͣ���硣
	{
		IN3 = 0;
		IN4 = 0;
	}
	if(i>100)							//��i��ֵ����100ʱ�����㡣
	{
		i=0;
	}
	return 0;
}
}
void interrupttime() interrupt 1					//��ʱ�����жϺ�����ÿһ���룬���ּ�һ��
{
	TH0 = 0xFC;
	TL0 = 0x67;
	i++;
}