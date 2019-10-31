/********************************
���ƣ������ķ��С��
  
	�� �� ��   : main.c
  �� �� ��   : v1.0
  ��    ��   : �̿���  
  ��������   : 2019-10-27
  ����޸�   : 2019-10-27
  ��������   : ѧϰʹ�������ķ��
********************************/

#include "stm32f10x.h"   // �൱��51��Ƭ���е�  #include <reg51.h>
#include "./led/bsp_led.h"
#include "./motor/bsp_motor.h"
#include "./usart/bsp_usart.h"
#include "./systick/bsp_systick.h"
#include "./GeneralTim4/bsp_GeneralTim4.h"

int main(void)
{
	// ���������ʱ��ϵͳ��ʱ���Ѿ������ó�72M��
	
	//��ʼ������
	USART_Config();
	//��ʼ������GPIO��
	wheel_GPIO_Config();
	//��ʼ����ʱ��4
	GENERAL_TIM4_Init();

	while(1)
	{
		//��ǰ��
		go_stright();
		SysTick_Delay_ms(3000);
		SysTick_Delay_ms(3000);
		//�����
		go_back();
		SysTick_Delay_ms(3000);
		SysTick_Delay_ms(3000);
		//����ת
		turn_right();;
		SysTick_Delay_ms(3000);
		SysTick_Delay_ms(3000);		
		//����ת
		turn_left();	
		SysTick_Delay_ms(3000);
		SysTick_Delay_ms(3000);				
		//����ƽ��
		left_parall();
		SysTick_Delay_ms(3000);
		SysTick_Delay_ms(3000);
		//����ƽ��
		right_parall();
		SysTick_Delay_ms(3000);
		SysTick_Delay_ms(3000);
	}
  	
}


