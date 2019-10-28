#include "stm32f10x.h"   // 相当于51单片机中的  #include <reg51.h>
#include "usart.h"

#define LED_GPIO_PIN         GPIO_Pin_0 										//宏定义，定义IO口的引脚号。
#define LED_GPIO_PORT        GPIOB													//定义IO口的序号。
#define LED_GPIO_CLK         RCC_APB2Periph_GPIOB						//RCC,时钟函数打开时钟。


void LED_GPIO_Config(void);
int main(void)
{
	uint8_t ch;
	USART_Config();
	LED_GPIO_Config();
	printf( "我有一个梦想！\n" );
	
	
	while(1)
	{
		ch = getchar();
		printf("ch = %c",ch);
		
		switch(ch)
		{
			case 'A': GPIO_SetBits(LED_GPIO_PORT, LED_GPIO_PIN);	break;
			case 'B': GPIO_ResetBits(LED_GPIO_PORT, LED_GPIO_PIN);break;
			default : break;
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


