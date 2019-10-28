#include "stm32f10x.h"
#include "bsp_led.h"
#include "systick.h"
#include "exti.h"
#include "base.h"
#include "color.h"
#include "weidai.h"
#include "usart.h"


int main (void)
{
	TIM2_Configuration();
	TIM2_NVIC_Configuration();
	Color2_GPIO_Config();
	EXTI2_NVIC_Configuration();
	EXTI_PG2_Config();
	color_Init();
	TCS230_Start2();
	EXTI_PG2_Config_on();
	EXTI_PG2_Config_off();
	USART_Config();
	SysTick_Init();
	
	printf("color");

	while(1)
	{
		
		switch(TCS230_Distinguish2())
		{
			case 1:printf(" 绿色 \n");break;
			case 2:printf(" 白色 \n");break;
			case 3:printf(" 红色 \n");break;
			case 4:printf(" 黑色 \n");break;		
			case 5:printf(" 蓝色 \n");break;
			case 0:printf(" 不知 \n");break;										
		}delay_s(1);
	}
}

