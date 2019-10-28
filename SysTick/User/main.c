#include "stm32f10x.h"   // 相当于51单片机中的  #include <reg51.h>
#include "SysTick.h"

#define LED_GPIO_PIN         GPIO_Pin_0 										//宏定义，定义IO口的引脚号。
#define LED_GPIO_PORT        GPIOB													//定义IO口的序号。
#define LED_GPIO_CLK         RCC_APB2Periph_GPIOB						//RCC,时钟函数打开时钟。


void Delay(uint32_t count);
void LED_GPIO_Config(void);
int main(void)
{
	while(1)
	{
		LED_GPIO_Config();																			//设置函数封装各个功能块。
		
		GPIO_SetBits(LED_GPIO_PORT, LED_GPIO_PIN);							//GPIO_SetBits函数，让改GPIO置底，使小灯有亮起来的可能。
		//Delay(0xFFFFF);
		SysTick_Dwelay_us(100);
		
		GPIO_ResetBits(LED_GPIO_PORT, LED_GPIO_PIN);						//GPIO_ResetBits函数，让GPIO置高，是小灯灭掉。
		//Delay(0xFFFFF);																					//关于延时函数的数字输入，好像10进制不行。
		SysTick_Dwelay_us(100);
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
void Delay(uint32_t count)																	//延时函数，用于延时。
{
	for(;count!=0;count--);
}


