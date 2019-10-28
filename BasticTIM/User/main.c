#include "stm32f10x.h"   // 相当于51单片机中的  #include <reg51.h>
#include "BasticTIM.h"


#define LED_GPIO_PIN         GPIO_Pin_0 										//宏定义，定义IO口的引脚号。
#define LED_GPIO_PORT        GPIOB													//定义IO口的序号。
#define LED_GPIO_CLK         RCC_APB2Periph_GPIOB						//RCC,时钟函数打开时钟。

uint16_t time = 0;


void LED_GPIO_Config(void);
int main(void)
{
	LED_GPIO_Config();
	BASIC_TIM_Init();
	while(1)
	{
		/* 500毫秒，闪烁一次。 */
		if(time == 500)		
		{
			LED_GPIO_PORT->ODR ^= GPIO_Pin_0;
			time = 0;
		}

	}
}
void LED_GPIO_Config()
{
	GPIO_InitTypeDef GPIO_InitStruct;													//定义结果剖变量。
	
	RCC_APB2PeriphClockCmd(LED_GPIO_CLK, ENABLE);							//rcc 打开时钟，设置APB2总线。
	GPIO_InitStruct.GPIO_Pin = LED_GPIO_PIN;									//定义IO口，设置PB端口。
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;							//设置输出方式，为推挽输出
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;						//设置速度为50MHZ.
	GPIO_Init(LED_GPIO_PORT, &GPIO_InitStruct);								//传IO口，和结构体变量的值。
}

