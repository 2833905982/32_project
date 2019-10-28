#include "stm32f10x.h"   // �൱��51��Ƭ���е�  #include <reg51.h>
#include "SysTick.h"

#define LED_GPIO_PIN         GPIO_Pin_0 										//�궨�壬����IO�ڵ����źš�
#define LED_GPIO_PORT        GPIOB													//����IO�ڵ���š�
#define LED_GPIO_CLK         RCC_APB2Periph_GPIOB						//RCC,ʱ�Ӻ�����ʱ�ӡ�


void Delay(uint32_t count);
void LED_GPIO_Config(void);
int main(void)
{
	while(1)
	{
		LED_GPIO_Config();																			//���ú�����װ�������ܿ顣
		
		GPIO_SetBits(LED_GPIO_PORT, LED_GPIO_PIN);							//GPIO_SetBits�������ø�GPIO�õף�ʹС�����������Ŀ��ܡ�
		//Delay(0xFFFFF);
		SysTick_Dwelay_us(100);
		
		GPIO_ResetBits(LED_GPIO_PORT, LED_GPIO_PIN);						//GPIO_ResetBits��������GPIO�øߣ���С�������
		//Delay(0xFFFFF);																					//������ʱ�������������룬����10���Ʋ��С�
		SysTick_Dwelay_us(100);
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
void Delay(uint32_t count)																	//��ʱ������������ʱ��
{
	for(;count!=0;count--);
}


