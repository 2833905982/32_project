#include "stm32f10x.h"   // �൱��51��Ƭ���е�  #include <reg51.h>
#include "usart.h"

#define LED_GPIO_PIN         GPIO_Pin_5 										//�궨�壬����IO�ڵ����źš�
#define LED_GPIO_PORT        GPIOB													//����IO�ڵ���š�
#define LED_GPIO_CLK         RCC_APB2Periph_GPIOB						//RCC,ʱ�Ӻ�����ʱ�ӡ�



int main(void)
{
	char ch;
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
	
	ch=getchar();
	printf("ch=%c\n",ch);

	while(1)
	{
		
	}
}


