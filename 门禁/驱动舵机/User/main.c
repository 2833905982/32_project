
// TIM��ͨ�ö�ʱ��-4·PWM���Ӧ��
#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_usart.h"
#include "bsp_SysTick.h"
#include "bsp_GeneralTim.h"  

/**
  * @brief  ������
  * @param  ��  
  * @retval ��
  */
int main(void)
{
	/* led �˿����� */ 
	LED_GPIO_Config();
	
	/* ��ʱ����ʼ�� */
	GENERAL_TIM_Init();
	
	/* ��ʼ������ */
	USART_Config();
	uint16_t i=0;
	
		printf("��������\n");
	
  while(1)
  {      
	 TIM_SetCompare3(GENERAL_TIM,2499);			//�������
	 SysTick_Delay_Ms(5000);

	for(i = 499;i <= 2499;i++)
	{	
		TIM_SetCompare3(GENERAL_TIM,i);//��Ӧ180��
		SysTick_Delay_Us(2000);
	}
	TIM_SetCompare3(GENERAL_TIM,2499);
	 SysTick_Delay_Ms(500);
	for(i = 2499;i >= 499;i--)
	{	
		TIM_SetCompare3(GENERAL_TIM,i);//��Ӧ180��
		SysTick_Delay_Us(2000);
	}
  }
}
/*********************************************END OF FILE**********************/
