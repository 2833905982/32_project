
// TIM—通用定时器-4路PWM输出应用
#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_GeneralTim.h"  

/**
  * @brief  主函数
  * @param  无  
  * @retval 无
  */
	
void delay_us(uint32_t us);
void delay_ms(uint32_t ms);
int main(void)
{
	/* led 端口配置 */ 
	LED_GPIO_Config();
	
	/* 定时器初始化 */
	GENERAL_TIM_Init();
	
	while (1)
	{
		delay_ms(500);
		TIM_SetCompare1(TIM1,175);//对应180度
		delay_ms(500);
		TIM_SetCompare1(TIM1,180);//对应135度
		delay_ms(500);
		TIM_SetCompare1(TIM1,185);//对应90度
		delay_ms(500);
		TIM_SetCompare1(TIM1,190);//对应45度
		delay_ms(500);
		TIM_SetCompare1(TIM1,195);//对应0度
		delay_ms(500);
		TIM_SetCompare1(TIM1,190);//对应45度
		delay_ms(500);
		TIM_SetCompare1(TIM1,185);//对应90度
		delay_ms(500); 
		TIM_SetCompare1(TIM1,180);//对应135度
		
		//如果配置的是PWM1模式，那么对应的占空比为25,20,15,10,5
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
		while( !((SysTick->CTRL) & (1<<16)) );             //等待置1，若置1 则1ms时间到了
	}
	
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}





