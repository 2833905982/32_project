#include "stm32f10x.h"   // �൱��51��Ƭ���е�  #include <reg51.h>
#include "pid_gpio.h"
#include "pid.h"

uint32_t time = 0; // ms ��ʱ���� 

void PID_Init(void)
{
	pid.Sv=100;						//�û��趨ֵΪ100
	pid.Kp=20;						//����ϵ��
	pid.T=1000;						//PID��������
	pid.Ti=5000;					//����ʱ��
	pid.Td=1200;					//΢��ʱ��
	pid.pwmcycle=1000;		//pwm ������1000΢��
}



int main(void)
{
	// ���������ʱ��ϵͳ��ʱ���Ѿ������ó�72M��
	PID_Init();
	PID_GPIO_Config();
	while(1)
	{
		PID_Calc();
	}
	
}


