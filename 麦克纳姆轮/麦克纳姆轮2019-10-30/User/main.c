/********************************
���ƣ������ķ��С��
  
	�� �� ��   : main.c
  �� �� ��   : v1.0
  ��    ��   : �̿���  
  ��������   : 2019-10-27
  ����޸�   : 2019-10-30
  ��������   : ѧϰʹ�������ķ��
********************************/

#include "stm32f10x.h"   // �൱��51��Ƭ���е�  #include <reg51.h>
#include "./led/bsp_led.h"
#include "./motor/bsp_motor.h"
#include "./usart2/bsp_usart2.h"
#include "./systick/bsp_systick.h"
#include "./GeneralTim4/bsp_GeneralTim4.h"

char ch = 'a';

int main(void)
{
	// ���������ʱ��ϵͳ��ʱ���Ѿ������ó�72M��
	
	//��ʼ������
	USART2_Config();
	//��ʼ������GPIO��
	wheel_GPIO_Config();
	//��ʼ����ʱ��4
	GENERAL_TIM4_Init();

	while(1)
	{
		ch = getchar();
		printf("ch = %c",ch);
		
		switch(ch)
		{
			/* ǰ�� */
			case '1': go_stright(); break;
			/* ���� */
			case '2': go_back();break;
			/* ��� */
			case '3': turn_left();	break;
			/* �ҹ� */
			case '4': turn_right();break;
			/* ��ƽ�� */
			case '5': left_parall();	break;
			/* ��ƽ�� */
			case '6': right_parall();break;			
			/* ֹͣ */
			case '7': go_stright();break;
			default : break;
		}
		
//		//��ǰ��
//		go_stright();
//		SysTick_Delay_ms(3000);
//		SysTick_Delay_ms(3000);
//		//�����
//		go_back();
//		SysTick_Delay_ms(3000);
//		SysTick_Delay_ms(3000);
//		//����ת
//		turn_right();
//		SysTick_Delay_ms(3000);
//		SysTick_Delay_ms(3000);		
//		//����ת
//		turn_left();	
//		SysTick_Delay_ms(3000);
//		SysTick_Delay_ms(3000);				
//		//����ƽ��
//		left_parall();
//		SysTick_Delay_ms(3000);
//		SysTick_Delay_ms(3000);
//		//����ƽ��
//		right_parall();
//		SysTick_Delay_ms(3000);
//		SysTick_Delay_ms(3000);
	}
  	
}


