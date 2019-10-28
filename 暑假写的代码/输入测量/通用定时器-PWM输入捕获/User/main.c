// TIM—通用-捕获-测量脉宽 应用
#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_usart.h"
#include "bsp_GeneralTim.h"  

/**
  * @brief  主函数
  * @param  无  
  * @retval 无
  */
int main(void)
{
	
	/* 串口初始化 */
	USART_Config();
	
	/* 定时器初始化 */
	GENERAL_TIM_Init();
	
	printf ( "\r\n野火 STM32 输入捕获实验\r\n" );
	printf ( "\r\n按下K1，测试K1按下的时间\r\n" );
	
	while ( 1 )
	{
		
	}
}
/*********************************************END OF FILE**********************/


