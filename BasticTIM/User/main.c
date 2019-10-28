#include "stm32f10x.h"   // �൱��51��Ƭ���е�  #include <reg51.h>
#include "BasticTIM.h"


#define LED_GPIO_PIN         GPIO_Pin_0 										//�궨�壬����IO�ڵ����źš�
#define LED_GPIO_PORT        GPIOB													//����IO�ڵ���š�
#define LED_GPIO_CLK         RCC_APB2Periph_GPIOB						//RCC,ʱ�Ӻ�����ʱ�ӡ�

uint16_t time = 0;


void LED_GPIO_Config(void);
int main(void)
{
	LED_GPIO_Config();
	BASIC_TIM_Init();
	while(1)
	{
		/* 500���룬��˸һ�Ρ� */
		if(time == 500)		
		{
			LED_GPIO_PORT->ODR ^= GPIO_Pin_0;
			time = 0;
		}

	}
}
void LED_GPIO_Config()
{
	GPIO_InitTypeDef GPIO_InitStruct;													//�������ʱ�����
	
	RCC_APB2PeriphClockCmd(LED_GPIO_CLK, ENABLE);							//rcc ��ʱ�ӣ�����APB2���ߡ�
	GPIO_InitStruct.GPIO_Pin = LED_GPIO_PIN;									//����IO�ڣ�����PB�˿ڡ�
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;							//���������ʽ��Ϊ�������
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;						//�����ٶ�Ϊ50MHZ.
	GPIO_Init(LED_GPIO_PORT, &GPIO_InitStruct);								//��IO�ڣ��ͽṹ�������ֵ��
}

