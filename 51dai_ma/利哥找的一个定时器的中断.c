#include<reg51.h>

#define uint unsigned int

#define uchar unsigned char


sbit PWM=P2^0;						// P2.0���pwm
uchar time; 							// ����һ��ʱ�亯��


void main()

{

TMOD=0x01;								//�ö�ʱ����1ģʽ��

TH0=0xff;									//��ʱ��1΢��
TL0=0xf7;

EA=1;											//�����ж�

ET0=1;										//��ʱ��0���򿪡�
	
TR0=1;										//������ʱ����

while(1)

{

}

}


void tim0() interrupt 1

{

TR0=0;										//�رն�ʱ�������¸�ֵ��

TH0=0xff;									//��ʱ1΢�롣

TL0=0xf7;

TR0=1;										//�򿪶�ʱ����


time++;

if(time>=100)							//����100���㡣

time=0;

if(time<=30) 							//ռ�ձ�ΪN����ʱ����30.

PWM=1;

else PWM=0;

}

