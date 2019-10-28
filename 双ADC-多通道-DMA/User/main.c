#include "stm32f10x.h"   // 相当于51单片机中的  #include <reg51.h>
#include "usart.h"
#include "adc.h"



extern __IO uint32_t ADC_ConvertedValue[NOFCHANEL];

// 局部变量，用于保存转换计算后的电压值 	 
float ADC_ConvertedValueLocal[NOFCHANEL*2];    


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
	
	while (1)
	{	
   	uint16_t temp0=0 ,temp1=0;		
    // 取出ADC1数据寄存器的高16位，这个是ADC2的转换数据
		temp0 = (ADC_ConvertedValue[0]&0XFFFF0000) >> 16;
		// 取出ADC1数据寄存器的低16位，这个是ADC1的转换数据
		temp1 = (ADC_ConvertedValue[0]&0XFFFF);	
		
		ADC_ConvertedValueLocal[0] =(float) temp0/4096*3.3;
		ADC_ConvertedValueLocal[1] =(float) temp1/4096*3.3;
		
		printf("\r\n ADCx_1 value = %f V \r\n",ADC_ConvertedValueLocal[1]);
		printf("\r\n ADCx_2 value = %f V \r\n",ADC_ConvertedValueLocal[0]);
		
		printf("\r\n\r\n");
		Delay(0xffffee); 
		 
	}
}


