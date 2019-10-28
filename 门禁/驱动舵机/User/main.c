
// TIM—通用定时器-4路PWM输出应用
#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_usart.h"
#include "bsp_SysTick.h"
#include "bsp_GeneralTim.h"  

/**
  * @brief  主函数
  * @param  无  
  * @retval 无
  */
int main(void)
{
	/* led 端口配置 */ 
	LED_GPIO_Config();
	
	/* 定时器初始化 */
	GENERAL_TIM_Init();
	
	/* 初始化串口 */
	USART_Config();
	uint16_t i=0;
	
		printf("渣子来了\n");
	
  while(1)
  {      
	 TIM_SetCompare3(GENERAL_TIM,2499);			//舵机归中
	 SysTick_Delay_Ms(5000);

	for(i = 499;i <= 2499;i++)
	{	
		TIM_SetCompare3(GENERAL_TIM,i);//对应180度
		SysTick_Delay_Us(2000);
	}
	TIM_SetCompare3(GENERAL_TIM,2499);
	 SysTick_Delay_Ms(500);
	for(i = 2499;i >= 499;i--)
	{	
		TIM_SetCompare3(GENERAL_TIM,i);//对应180度
		SysTick_Delay_Us(2000);
	}
  }
}
/*********************************************END OF FILE**********************/
