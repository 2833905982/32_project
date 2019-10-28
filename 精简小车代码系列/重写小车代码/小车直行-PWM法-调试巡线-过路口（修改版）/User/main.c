#include "stm32f10x.h"   // 相当于51单片机中的  #include <reg51.h>
#include "bsp_GeneralTim.h" 
#include "systick.h"
#include "jiaodu.h"
#include "usart.h"
#include "huidu.h"
#include "bsp-gpio.h"
#include "exti.h"


uint16_t i = 0;
int main(void)
{
	/* 初始化 GPIO口 */
	LUN_GPIO_Config();
	
	/* 初始化按键 */
	EXTI_Key_Config();
	
	/* 初始化 PWM */
	GENERAL_TIM_Init();
	 
 
	/* 初始化串口 */
	USART_Config();
	
	/* 初始化灰度 */
	huidu ();
		
	printf("你好，我来了！");

	
	/*---------------------初始化小车，即前进方向的固定----------------------------*/

		/* 操作A2引脚 */
		GPIO_SetBits(Rwheel1_GPIO_PORT, Rwheel1_GPIO_PIN);											//右轮正转
		//GPIO_ResetBits(Rwheel1_GPIO_PORT, Rwheel1_GPIO_PIN);									//右轮反转
		
		/* 操作的A4引脚 */
		//GPIO_SetBits(Lwheel2_GPIO_PORT, Lwheel2_GPIO_PIN);					  				//左轮反转
		GPIO_ResetBits(Lwheel2_GPIO_PORT, Lwheel2_GPIO_PIN);										//左轮正转
		
	

}
	

