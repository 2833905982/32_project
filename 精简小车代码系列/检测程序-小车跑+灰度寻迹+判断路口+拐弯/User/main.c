#include "stm32f10x.h"   
#include "bsp_GeneralTim.h" 
#include "systick.h"
#include "usart.h"
#include "huidu.h"
#include "bsp-gpio.h"
#include "exti.h"
#include "move.h"
#include "weidai.h"
#include "color.h"

int main(void)
{
		
	/*����*/
	W_GPIO_Config();
	
	/* PWM */
	GENERAL_TIM_Init();
 
	/* ��ʼ������ */
	USART_Config();
	
	/* ��ʼ���Ҷ� */
	huidu ();
	
	/*��ɫ*/
	color();
		
	qianjin();
	
	lukou(6);

	/*  ��ɫʶ�� 
			switch()
	*/

}
	

