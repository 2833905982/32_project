#include "stm32f10x.h"   // �൱��51��Ƭ���е�  #include <reg51.h>
#include "anjian.h"

#define LED_GPIO_PIN         GPIO_Pin_0 										//�궨�壬����IO�ڵ����źš�
#define LED_GPIO_PORT        GPIOB													//����IO�ڵ���š�
#define LED_GPIO_CLK         RCC_APB2Periph_GPIOB						//RCC,ʱ�Ӻ�����ʱ�ӡ�


void Delay(uint32_t count);
void LED_GPIO_Config(void);
int main(void)
{
		LED_GPIO_Config();																			//���ú�����װ�������ܿ顣
		key1_GPIO_Config();
	while(1)
	{
		if(key_Scan(KEY1_GPIO_PORT,KEY1_GPIO_PIN)==1)
		{
			LED_GPIO_PORT->ODR ^= LED_GPIO_PIN;
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


