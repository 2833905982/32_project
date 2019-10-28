#include "anjian.h"

int keybuf = 0;
int keyback = 0;																																	 

void key1_GPIO_Config( void )
{
	GPIO_InitTypeDef GPIO_InitStruct;																//定义结构体变量。
	
	RCC_APB2PeriphClockCmd(KEY1_GPIO_CLK, ENABLE);									//rcc 打开时钟，设置APB2总线。
	GPIO_InitStruct.GPIO_Pin = KEY1_GPIO_PIN;												//定义IO口，设置PB端口。
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;							//设置输入方式，为浮空输入。

	GPIO_Init(KEY1_GPIO_PORT, &GPIO_InitStruct);											//传IO口，和结构体变量的值。
}
uint8_t key_Scan( GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin )
{
	if( GPIO_ReadInputDataBit(GPIOx, GPIO_Pin)==1 )
	{
		Delay(10000);
		if( GPIO_ReadInputDataBit(GPIOx, GPIO_Pin)==1 )
		{
			while( GPIO_ReadInputDataBit(GPIOx, GPIO_Pin)==1 );
			return 1;
		}
		else
			return 0;
	}
	else 
	{
		return 0;
	}
}
void Delay(uint32_t count)																	//延时函数，用于延时。
{
	for(;count!=0;count--);
}

