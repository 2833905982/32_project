#include "gpio.h"


void GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;													//����ṹ�������
	
	RCC_APB2PeriphClockCmd( GPIO2_CLK , ENABLE);							//rcc ��ʱ�ӣ�����APB2���ߡ�
	GPIO_InitStruct.GPIO_Pin = GPIO2_PIN;									//����IO�ڣ�����PB�˿ڡ�
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;							//���������ʽ��Ϊ�������
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;						//�����ٶ�Ϊ50MHZ.
	GPIO_Init(GPIO2_PORT, &GPIO_InitStruct);								//��IO�ڣ��ͽṹ�������ֵ��
//	/*----------------GPIO2 ����----------------------*/
//	
//	GPIO_InitStruct.GPIO_Pin = GPIO2_PIN;
//	GPIO_Init(GPIO2_PORT, &GPIO_InitStruct);

}




