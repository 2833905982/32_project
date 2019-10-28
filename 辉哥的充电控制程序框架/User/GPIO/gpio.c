#include "gpio.h"


void GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;													//定义结构体变量。
	
	RCC_APB2PeriphClockCmd( GPIO2_CLK , ENABLE);							//rcc 打开时钟，设置APB2总线。
	GPIO_InitStruct.GPIO_Pin = GPIO2_PIN;									//定义IO口，设置PB端口。
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;							//设置输出方式，为推挽输出
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;						//设置速度为50MHZ.
	GPIO_Init(GPIO2_PORT, &GPIO_InitStruct);								//传IO口，和结构体变量的值。
//	/*----------------GPIO2 定义----------------------*/
//	
//	GPIO_InitStruct.GPIO_Pin = GPIO2_PIN;
//	GPIO_Init(GPIO2_PORT, &GPIO_InitStruct);

}




