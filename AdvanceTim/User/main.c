#include "stm32f10x.h"   // �൱��51��Ƭ���е�  #include <reg51.h>
#include "usart.h"
#include "AdvanceTim.h"


#define LED_GPIO_PIN         GPIO_Pin_0 										//�궨�壬����IO�ڵ����źš�
#define LED_GPIO_PORT        GPIOB													//����IO�ڵ���š�
#define LED_GPIO_CLK         RCC_APB2Periph_GPIOB						//RCC,ʱ�Ӻ�����ʱ�ӡ�



int main(void)
{

	USART_Config();
	
	/* �߼���ʱ����ʼ�� */
	ADVANCE_TIM_Init();
	
	
	while(1)
	{
		
	}
}


