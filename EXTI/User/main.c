#include "stm32f10x.h"   // �൱��51��Ƭ���е�  #include <reg51.h>
#include "stm32f10x_it.h"
#include "exti.h"


#define LED_GPIO_PIN         GPIO_Pin_13 										//�궨�壬����IO�ڵ����źš�
#define LED_GPIO_PORT        GPIOC													//����IO�ڵ���š�
#define LED_GPIO_CLK         RCC_APB2Periph_GPIOC						//RCC,ʱ�Ӻ�����ʱ�ӡ�


//void Delay(uint32_t count);
void LED_GPIO_Config()
{
	GPIO_InitTypeDef GPIO_InitStruct;													//�������ʱ�����
	
	RCC_APB2PeriphClockCmd(LED_GPIO_CLK, ENABLE);							//rcc ��ʱ�ӣ�����APB2���ߡ�
	GPIO_InitStruct.GPIO_Pin = LED_GPIO_PIN;									//����IO�ڣ�����PB�˿ڡ�
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;							//���������ʽ��Ϊ�������
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;						//�����ٶ�Ϊ50MHZ.
	GPIO_Init(LED_GPIO_PORT, &GPIO_InitStruct);				
}	
int main(void)
{
	 LED_GPIO_Config();
	 EXTI_Key_Config();
	while(1)
	{
		
	}
}
//��IO�ڣ��ͽṹ�������ֵ��

//void Delay(uint32_t count)																	//��ʱ������������ʱ��
//{
//	for(;count!=0;count--);
//}

