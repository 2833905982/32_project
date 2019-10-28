#include "stm32f10x.h"   // 相当于51单片机中的  #include <reg51.h>
#include "usart.h"
#include "AdvanceTim.h"


#define LED_GPIO_PIN         GPIO_Pin_0 										//宏定义，定义IO口的引脚号。
#define LED_GPIO_PORT        GPIOB													//定义IO口的序号。
#define LED_GPIO_CLK         RCC_APB2Periph_GPIOB						//RCC,时钟函数打开时钟。

uint8_t sh = 0;
uint16_t value(void);
int main(void)
{
	
	USART_Config();
	
	/* 高级定时器初始化 */
	ADVANCE_TIM_Init();
	
	printf("我有一个梦想！\n");
	
	while(1)
	{
		sh = 0;
		printf("sh = %c",sh);
		//uint16_t value();
	}

}
uint16_t value(void)
{
	if(sh=='A')
	{
		return 0;
	}
	if(sh=='B')
	{
	  return 4;
	}
	else
	{
		return 8;
	}
}

