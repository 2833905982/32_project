#include "bsp-gpio.h"



void LUN_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;													//����ṹ�������
	
	RCC_APB2PeriphClockCmd( Rwheel1_GPIO_CLK | Lwheel2_GPIO_CLK, ENABLE);							//rcc ��ʱ�ӣ�����APB2���ߡ�
	GPIO_InitStruct.GPIO_Pin = Lwheel2_GPIO_PIN;									//����IO�ڣ�����PB�˿ڡ�
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;							//���������ʽ��Ϊ�������
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;						//�����ٶ�Ϊ50MHZ.
	GPIO_Init(Lwheel2_GPIO_PORT, &GPIO_InitStruct);								//��IO�ڣ��ͽṹ�������ֵ��

	/*----------------���ֿ��Ƶ�GPIO�� ����----------------------*/
	
	GPIO_InitStruct.GPIO_Pin = Rwheel1_GPIO_PIN;
	GPIO_Init(Rwheel1_GPIO_PORT, &GPIO_InitStruct);
}



