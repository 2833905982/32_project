
// TIM��ͨ�ö�ʱ��-4·PWM���Ӧ��
#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_GeneralTim.h"  

/**
  * @brief  ������
  * @param  ��  
  * @retval ��
  */
	
void delay_us(uint32_t us);
void delay_ms(uint32_t ms);
int main(void)
{
	/* led �˿����� */ 
	LED_GPIO_Config();
	
	/* ��ʱ����ʼ�� */
	GENERAL_TIM_Init();
	
	while (1)
	{
		delay_ms(500);
		TIM_SetCompare1(TIM1,175);//��Ӧ180��
		delay_ms(500);
		TIM_SetCompare1(TIM1,180);//��Ӧ135��
		delay_ms(500);
		TIM_SetCompare1(TIM1,185);//��Ӧ90��
		delay_ms(500);
		TIM_SetCompare1(TIM1,190);//��Ӧ45��
		delay_ms(500);
		TIM_SetCompare1(TIM1,195);//��Ӧ0��
		delay_ms(500);
		TIM_SetCompare1(TIM1,190);//��Ӧ45��
		delay_ms(500);
		TIM_SetCompare1(TIM1,185);//��Ӧ90��
		delay_ms(500); 
		TIM_SetCompare1(TIM1,180);//��Ӧ135��
		
		//������õ���PWM1ģʽ����ô��Ӧ��ռ�ձ�Ϊ25,20,15,10,5
	}
}
/*********************************************END OF FILE**********************/


//us
void delay_us(uint32_t us)
{
	uint32_t i;
	SysTick_Config(72);
	
	for(i=0;i<us;i++)
	{
		while( !((SysTick->CTRL) & (1<<16)) );
	}
	
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}


//ms
void delay_ms(uint32_t ms)
{
	uint32_t i;
	SysTick_Config(72000);
	
	for(i=0;i<ms;i++)
	{
		while( !((SysTick->CTRL) & (1<<16)) );             //�ȴ���1������1 ��1msʱ�䵽��
	}
	
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}





