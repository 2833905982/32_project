#include "bsp_GeneralTim.h" 
#include "stm32f10x.h"   
#include "bsp-gpio.h"
#include "systick.h"
#include "weidai.h"
#include "color.h"
#include "usart.h"
#include "huidu.h"
#include "exti.h"
#include "move.h"


int main(void)
{
	uint8_t a=0;
		
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
	
	lukou(4);
	
		while(1)
		{
			turn_left();
			if(scan (HUI1_GPIO_PORT,HUI1_GPIO_PIN) == ON)
			{
				a++;
				delay_ms(100);
				while(1)
				{
					if(scan (HUI1_GPIO_PORT,HUI1_GPIO_PIN) == OFF)
					{
						break;
					}
				}
			}
				if(a>=2)
				{
					stop();
					break;
				}		

		}
}
	

