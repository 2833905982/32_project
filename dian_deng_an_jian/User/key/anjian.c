#include "anjian.h"

int keybuf = 0;
int keyback = 0;																																	 

void key1_GPIO_Config( void )
{
	GPIO_InitTypeDef GPIO_InitStruct;																//����ṹ�������
	
	RCC_APB2PeriphClockCmd(KEY1_GPIO_CLK, ENABLE);									//rcc ��ʱ�ӣ�����APB2���ߡ�
	GPIO_InitStruct.GPIO_Pin = KEY1_GPIO_PIN;												//����IO�ڣ�����PB�˿ڡ�
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;							//�������뷽ʽ��Ϊ�������롣

	GPIO_Init(KEY1_GPIO_PORT, &GPIO_InitStruct);											//��IO�ڣ��ͽṹ�������ֵ��
}
uint8_t key_Scan( GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin )
{
	if( GPIO_ReadInputDataBit(GPIOx, GPIO_Pin)==1 )
	{
		Delay(10000);
		if( GPIO_ReadInputDataBit(GPIOx, GPIO_Pin)==1 )
		{
			while( GPIO_ReadInputDataBit(GPIOx, GPIO_Pin)==1 );
			return 1;
		}
		else
			return 0;
	}
	else 
	{
		return 0;
	}
}
void Delay(uint32_t count)																	//��ʱ������������ʱ��
{
	for(;count!=0;count--);
}

