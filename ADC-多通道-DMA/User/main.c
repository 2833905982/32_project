#include "stm32f10x.h"   // 相当于51单片机中的  #include <reg51.h>
#include "usart.h"
#include "adc.h"


#define LED_GPIO_PIN         GPIO_Pin_5 										//宏定义，定义IO口的引脚号。
#define LED_GPIO_PORT        GPIOB													//定义IO口的序号。
#define LED_GPIO_CLK         RCC_APB2Periph_GPIOB						//RCC,时钟函数打开时钟。

extern __IO uint16_t ADC_ConvertedValue[NOFCHANEL];

// 局部变量，用于保存转换计算后的电压值 	 
float ADC_ConvertedValueLocal[NOFCHANEL];    


void Delay(__IO uint32_t nCount)
{
  for(; nCount != 0; nCount--);
} 


int main(void)
{
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
	
	/* 初始化ADC */
	ADCx_Init();
	
	while(1)
	{
			ADC_ConvertedValueLocal[0] =(float) ADC_ConvertedValue[0]/4096*3.3;
			ADC_ConvertedValueLocal[1] =(float) ADC_ConvertedValue[1]/4096*3.3;
			ADC_ConvertedValueLocal[2] =(float) ADC_ConvertedValue[2]/4096*3.3;
			ADC_ConvertedValueLocal[3] =(float) ADC_ConvertedValue[3]/4096*3.3;
			ADC_ConvertedValueLocal[4] =(float) ADC_ConvertedValue[4]/4096*3.3;
			ADC_ConvertedValueLocal[5] =(float) ADC_ConvertedValue[5]/4096*3.3;
		
			printf("\r\n CH0 value = %f V \r\n",ADC_ConvertedValueLocal[0]);
			printf("\r\n CH1 value = %f V \r\n",ADC_ConvertedValueLocal[1]);
			printf("\r\n CH2 value = %f V \r\n",ADC_ConvertedValueLocal[2]);
			printf("\r\n CH3 value = %f V \r\n",ADC_ConvertedValueLocal[3]);
			printf("\r\n CH4 value = %f V \r\n",ADC_ConvertedValueLocal[4]);
			printf("\r\n CH5 value = %f V \r\n",ADC_ConvertedValueLocal[5]);
		
			printf("\r\n\r\n");
			Delay(0xffffe);		
	}
}


