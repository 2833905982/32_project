#include "stm32f10x.h"   // 相当于51单片机中的  #include <reg51.h>
#include "usart.h"

#define LED_GPIO_PIN         GPIO_Pin_5 										//宏定义，定义IO口的引脚号。
#define LED_GPIO_PORT        GPIOB													//定义IO口的序号。
#define LED_GPIO_CLK         RCC_APB2Periph_GPIOB						//RCC,时钟函数打开时钟。



int main(void)
{
	char ch;
	//uint8_t a[10]={1,2,3,4,5,6,7,8,9,10};
	USART_Config();
	//往此处输入值，则发送到电脑上，一个字节。
	//Usart_SendByte(DEBUG_USARTx,1);
	
	//发送两个字节的数据。
	//Usart_SendHalfword(DEBUG_USARTx,0xFF56);
	
	/* 发送一个数组的数据 */
  //Usart_SendArray(DEBUG_USARTx ,a, 10);

	/* 发送字符数据 */

	Usart_SendStr(DEBUG_USARTx,"STM32,你好，渣子来了！\n");
	
	printf( "我有一个梦想！\n" );
	
	ch=getchar();
	printf("ch=%c\n",ch);

	while(1)
	{
		
	}
}


