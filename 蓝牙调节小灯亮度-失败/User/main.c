#include "stm32f10x.h"   // �൱��51��Ƭ���е�  #include <reg51.h>
#include "usart.h"
#include "AdvanceTim.h"


#define LED_GPIO_PIN         GPIO_Pin_0 										//�궨�壬����IO�ڵ����źš�
#define LED_GPIO_PORT        GPIOB													//����IO�ڵ���š�
#define LED_GPIO_CLK         RCC_APB2Periph_GPIOB						//RCC,ʱ�Ӻ�����ʱ�ӡ�

uint8_t sh = 0;
uint16_t value(void);
int main(void)
{
	
	USART_Config();
	
	/* �߼���ʱ����ʼ�� */
	ADVANCE_TIM_Init();
	
	printf("����һ�����룡\n");
	
	while(1)
	{
		sh = 0;
		printf("sh = %c",sh);
		//uint16_t value();
	}

}
uint16_t value(void)
{
	if(sh=='A')
	{
		return 0;
	}
	if(sh=='B')
	{
	  return 4;
	}
	else
	{
		return 8;
	}
}

