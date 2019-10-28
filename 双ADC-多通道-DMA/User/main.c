#include "stm32f10x.h"   // �൱��51��Ƭ���е�  #include <reg51.h>
#include "usart.h"
#include "adc.h"



extern __IO uint32_t ADC_ConvertedValue[NOFCHANEL];

// �ֲ����������ڱ���ת�������ĵ�ѹֵ 	 
float ADC_ConvertedValueLocal[NOFCHANEL*2];    


void Delay(__IO uint32_t nCount)
{
  for(; nCount != 0; nCount--);
} 


int main(void)
{
	//uint8_t a[10]={1,2,3,4,5,6,7,8,9,10};
	USART_Config();
	//���˴�����ֵ�����͵������ϣ�һ���ֽڡ�
	//Usart_SendByte(DEBUG_USARTx,1);
	
	//���������ֽڵ����ݡ�
	//Usart_SendHalfword(DEBUG_USARTx,0xFF56);
	
	/* ����һ����������� */
  //Usart_SendArray(DEBUG_USARTx ,a, 10);

	/* �����ַ����� */
	Usart_SendStr(DEBUG_USARTx,"STM32,��ã��������ˣ�\n");
	
	printf( "����һ�����룡\n" );
	
	/* ��ʼ��ADC */
	ADCx_Init();
	
	while (1)
	{	
   	uint16_t temp0=0 ,temp1=0;		
    // ȡ��ADC1���ݼĴ����ĸ�16λ�������ADC2��ת������
		temp0 = (ADC_ConvertedValue[0]&0XFFFF0000) >> 16;
		// ȡ��ADC1���ݼĴ����ĵ�16λ�������ADC1��ת������
		temp1 = (ADC_ConvertedValue[0]&0XFFFF);	
		
		ADC_ConvertedValueLocal[0] =(float) temp0/4096*3.3;
		ADC_ConvertedValueLocal[1] =(float) temp1/4096*3.3;
		
		printf("\r\n ADCx_1 value = %f V \r\n",ADC_ConvertedValueLocal[1]);
		printf("\r\n ADCx_2 value = %f V \r\n",ADC_ConvertedValueLocal[0]);
		
		printf("\r\n\r\n");
		Delay(0xffffee); 
		 
	}
}


