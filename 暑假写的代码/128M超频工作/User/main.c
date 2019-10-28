#include "stm32f10x.h"   // 相当于51单片机中的  #include <reg51.h>
#include "rccclkconfig.h"
#include "bsp_SysTick.h"
#include "led.h"



int main(void)
{
	//来到这里的时候系统时钟已经被设置为72M.
	  LED_GPIO_Config();																			//设置函数封装各个功能块。

	  HSE_SetSysCLK( RCC_PLLMul_9 );
	while(1)
	{
		
		GPIO_SetBits(LED_GPIO_PORT, LED_GPIO_PIN);							//GPIO_SetBits函数，让改GPIO置底，使小灯有亮起来的可能。
		SysTick_Delay_Ms(50);
		
		GPIO_ResetBits(LED_GPIO_PORT, LED_GPIO_PIN);						//GPIO_ResetBits函数，让GPIO置高，是小灯灭掉。
		SysTick_Delay_Ms(50);
	}
}


