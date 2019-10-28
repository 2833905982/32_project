#include <reg52.h>

sbit IN1 = P1^0;
sbit IN2 = P1^1;
sbit IN3 = P1^2;
sbit IN4 = P1^3;
sbit ENA = P1^4;
sbit ENB = P1^5;
sbit lhuidu = P3^2;				//��ߵĻҶȷ���ֵ��
sbit rhuidu = P3^3;				//�ұߵĻҶȷ���ֵ��
sbit flhuidu = P1^6;
sbit frhuidu = P1^7;

unsigned char i = 0;

void fanzhuan();
void main()
{
TMOD=0x01;								//�ö�ʱ����1ģʽ�򿪡�

TH0=0xff;									//��ʱ��1΢�롣
TL0=0xf7;

EA=1;											//�����жϡ�

ET0=1;										//��ʱ��0���򿪡�
	
TR0=1;										//������ʱ����

EX0 = 1;									//���ⲿ�ж�1��
IT0 = 1;					
	
EX1 = 1;									//���ⲿ�ж�2��
IT1 = 1;
	
while(1)
{
	fanzhuan();
	if(i<50)							//��ߵĵ����С��50������ʱ�������ת��
	{
		IN1 = 0;
		IN2 = 1;
	}
	if(i>50)							//��ߵĵ�����ڴ���50������ʱ�����ֹͣ���硣
	{
		IN1 = 0;
		IN2 = 0;
	}
		if(i<50)						//�ұߵĵ����С��50������ʱ�������ת��
	{
		IN3 = 0;
		IN4 = 1;
	}
	if(i>50)							//�ұߵĵ�����ڴ���50������ʱ�����ֹͣ���硣
	{
		IN3 = 0;
		IN4 = 0;
	}
	if(i>100)							//��i��ֵ����100ʱ�����㡣
	{
		i=0;
	}
}
}
void time0() interrupt 1
{
	TH0=0xff;	
	TL0=0xf7;
	i++;
}


void time1() interrupt 0		//�ⲿ�ж�,�ѳ������ּ��١�

{
  ENA = 1;									//��������ת��
	ENB = 1;
	IN1 = 0;
	IN2 = 1;
	IN3 = 1;
	IN4 = 0;
}
void time2() interrupt 2		//������ƫ�ƣ����ּ��١�
{	
  ENA = 1;									//��������ת��
	ENB = 1;
	IN1 = 1;
	IN2 = 0;
	IN3 = 0;
	IN4 = 1;
}

void fanzhuan()
{
	if(flhuidu == 1)
	{
		lhuidu = 0;
	}
		if(flhuidu == 0)
	{
		lhuidu = 1;
	}
	if(fRhuidu == 1)
	{
		Rhuidu = 0;
	}
	if(Rlhuidu == 1)
	{
		Rhuidu = 0;
	}

}