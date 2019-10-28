#include "bsp_GeneralTim.h" 
#include "stm32f10x.h"   
#include "bsp-gpio.h"
#include "systick.h"
#include "jiaodu.h"
#include "usart.h"
#include "huidu.h"
#include "exti.h"
#include "move.h"

int main(void)
{
	
	/* ��ʼ�� PWM */
	GENERAL_TIM_Init();
 
	/* ��ʼ������ */
	USART_Config();
	
	/* ��ʼ���Ҷ� */
	huidu();
	
	/* ��ʼ���˶� */
	wheel_configer();
		
	/* ��ʼ��С���ķ�����ٶ� */
	Leftsudu(400,ON);                                //����ߵ�ƽ��ʱ��Ϊ100�� DIR = 0,    ��������ת
	Rightsudu(400,OFF);                               //����ߵ�ƽ��ʱ��Ϊ100��DIR = 1,    ��������ת

	while(1)
	{
		
	}
}
	

