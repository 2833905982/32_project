#include "stm32f10x.h"   // �൱��51��Ƭ���е�  #include <reg51.h>
#include "usart.h"
#include "adc.h"


#define LED_GPIO_PIN         GPIO_Pin_5 										//�궨�壬����IO�ڵ����źš�
#define LED_GPIO_PORT        GPIOB													//����IO�ڵ���š�
#define LED_GPIO_CLK         RCC_APB2Periph_GPIOB						//RCC,ʱ�Ӻ�����ʱ�ӡ�

extern __IO uint16_t ADC_ConvertedValue;

// �ֲ����������ڱ���ת�������ĵ�ѹֵ 	 
float ADC_ConvertedValueLocal;    


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
	
	while(1)
	{
		ADC_ConvertedValueLocal =(float) ADC_ConvertedValue/4096*3.3; 
	
		/* ��ӡ16������ */
		printf("\r\n The current AD value = 0x%04X \r\n", ADC_ConvertedValue); 
		
		/* ��ӡ�������� */
		printf("\r\n The current AD value = %f V \r\n", ADC_ConvertedValueLocal); 
		//����
		printf("\r\n\r\n");

		Delay(0xffff); 
	}
}


