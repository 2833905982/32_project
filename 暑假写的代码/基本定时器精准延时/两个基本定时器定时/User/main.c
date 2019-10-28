// 基本定时器TIMx,x[6,7]定时应用
#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_TiMbase.h"
#include "bsp_usart.h"

volatile uint32_t time1 = 0; // ms 计时变量 
volatile uint32_t time2 = 0; // ms 计时变量 
/**
  * @brief  主函数
  * @param  无  
  * @retval 无
  */
int main(void)
{
	/* led 端口配置 */ 
	LED_GPIO_Config();
	
	BASIC_TIM_Init();
	
	/* 初始化串口 */
	USART_Config();
	
	printf("渣子你好\n");
	
  while(1)
  {
    if ( time1 == 1000 ) /* 1000 * 1 ms = 1s 时间到 */
    {
      time1 = 0;
			
			/* LED1 取反 */      
			printf("一秒爱你一次\n");
    }   
    if ( time2 == 500 ) /* 1000 * 1 ms = 1s 时间到 */
    {
      time2 = 0;
			
			/* LED1 取反 */      
			printf("半秒爱你一次\n");
    }		
  }
}
/*********************************************END OF FILE**********************/

