#include "led.h"


void LED_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;													//定义结果剖变量。
	
	RCC_APB2PeriphClockCmd(LED_GPIO_CLK, ENABLE);							//rcc 打开时钟，设置APB2总线。
	GPIO_InitStruct.GPIO_Pin = LED_GPIO_PIN;									//定义IO口，设置PB端口。
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;							//设置输出方式，为推挽输出
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;						//设置速度为50MHZ.
	GPIO_Init(LED_GPIO_PORT, &GPIO_InitStruct);								//传IO口，和结构体变量的值。
}



