#include "led.h"



void LED1_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;													//����ṹ�������
	
	RCC_APB2PeriphClockCmd(LED1_GPIO_CLK | LED2_GPIO_CLK | Rwheel1_GPIO_CLK | Lwheel2_GPIO_CLK, ENABLE);							//rcc ��ʱ�ӣ�����APB2���ߡ�
	GPIO_InitStruct.GPIO_Pin = LED1_GPIO_PIN;									//����IO�ڣ�����PB�˿ڡ�
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;							//���������ʽ��Ϊ�������
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;						//�����ٶ�Ϊ50MHZ.
	GPIO_Init(LED1_GPIO_PORT, &GPIO_InitStruct);								//��IO�ڣ��ͽṹ�������ֵ��
	/*----------------GPIO2 ����----------------------*/
	
	GPIO_InitStruct.GPIO_Pin = LED2_GPIO_PIN;
	GPIO_Init(LED2_GPIO_PORT, &GPIO_InitStruct);
	
	/*----------------���ֿ��Ƶ�GPIO�� ����----------------------*/
	
	GPIO_InitStruct.GPIO_Pin = Rwheel1_GPIO_PIN;
	GPIO_Init(Rwheel1_GPIO_PORT, &GPIO_InitStruct);
	
	/*----------------���ֿ��Ƶ�GPIO�� ����----------------------*/
	
	GPIO_InitStruct.GPIO_Pin = Lwheel2_GPIO_PIN;
	GPIO_Init(Lwheel2_GPIO_PORT, &GPIO_InitStruct);
	
}




