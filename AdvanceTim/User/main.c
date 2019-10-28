#include "stm32f10x.h"   // 相当于51单片机中的  #include <reg51.h>
#include "usart.h"
#include "AdvanceTim.h"


#define LED_GPIO_PIN         GPIO_Pin_0 										//宏定义，定义IO口的引脚号。
#define LED_GPIO_PORT        GPIOB													//定义IO口的序号。
#define LED_GPIO_CLK         RCC_APB2Periph_GPIOB						//RCC,时钟函数打开时钟。



int main(void)
{

	USART_Config();
	
	/* 高级定时器初始化 */
	ADVANCE_TIM_Init();
	
	
	while(1)
	{
		
	}
}


