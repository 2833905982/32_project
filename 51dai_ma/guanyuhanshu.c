#include <reg52.h>

unsigned char code ledchar[]=															//����һϵ�е����֣����������ʾ��Щ���֡�
{				0xC0,0xF9,0xA4,0xB0,0x99,
				0x92,0x82,0xF8,0x80,0x90,
				0x88,0x83,0xC6,0xA1,0x86,0x8E
};
unsigned char ledbuf[6]=																	//�������е�����ܣ������������ѭ����ʾ��
{
				0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
};
unsigned char flag = 0;
unsigned char i = 0;

void xianshi();

int main()																								//������������Ҫ�ĳ���
{
	TMOD =0x01;																							//����ʹ��T0��ģʽΪ��һ�֡�
	TH0  = 0xFC;																						//ΪT0����ֵΪFC67,��ʱΪ1���롣
	TL0  = 0x67;
	EA   = 1;																								//���жϵ��ܿ��ء�
	ET0  = 1;																								//ʹ�����жϡ�
	TR0  = 1;																								//�������ж�T0��

	while(1)																								//������ܴ��㿪ʼ��ʾ���֣�ʹ����Ϊһ����������
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
			ledbuf[0]=ledchar[sec%10];													//���ȡ�࣬���������ʾ�������֡�
			ledbuf[1]=ledchar[sec/10%10];
			ledbuf[2]=ledchar[sec/100%10];
			ledbuf[3]=ledchar[sec/1000%10];
			ledbuf[4]=ledchar[sec/10000%10];
			ledbuf[5]=ledchar[sec/100000%10];
		}
}
void interruptTimer() interrupt 1													//�����жϡ�
{
	unsigned cnt = 0;
	TH0 = 0xFC;																							//���¸�ֵ��
	TR0 = 0x67;
	cnt++;
	if(cnt>=1000)
	{
		cnt=0;
		flag=1;
	}
	P0 = 0xFF;
	switch(i)																									//ˢ������ܣ�ˢ��ʱ��1���롣
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