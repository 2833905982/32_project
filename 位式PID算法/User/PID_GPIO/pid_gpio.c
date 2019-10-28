#include "pid_gpio.h"
#include "pid.h"


void PID_GPIO_Config(void)																	//PID����ܽ�����
{
	GPIO_InitTypeDef GPIO_InitStruct;													//����ṹ�������
	
	RCC_APB2PeriphClockCmd(PID_GPIO_CLK, ENABLE);							//rcc ��ʱ�ӣ�����APB2���ߡ�
	GPIO_InitStruct.GPIO_Pin = PID_GPIO_PIN;									//����IO�ڣ�����PB�˿ڡ�
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;							//���������ʽ��Ϊ�������
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;						//�����ٶ�Ϊ50MHZ.
	GPIO_Init(PID_GPIO_PORT, &GPIO_InitStruct);								//��IO�ڣ��ͽṹ�������ֵ��
}

void PID_out(void)			//��� PID ��������������-----ÿһ���뱻����һ�� 																			
{
	static u16 pw;
	
	pw++;
	
	if(pw>=pid.pwmcycle)							
	{
		pw=0;
	}
	
	//0   ��    pid.pwmcycle-1
	if(pw<pid.OUT)
	{
		pwmout_0;				 //����
	}
	else
	{
		pwmout_1;			  //ֹͣ����
	}
}



