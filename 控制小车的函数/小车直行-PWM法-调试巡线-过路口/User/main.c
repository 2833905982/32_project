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
	//uint8_t ch;
	
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
		
	
	while(1)
	{
		
		//检测左灰度
		if(scan (HUI1_GPIO_PORT,HUI1_GPIO_PIN) == ON && scan (HUI2_GPIO_PORT,HUI2_GPIO_PIN) == OFF)
		{
			turn_left(250);
		}
		//检测右灰度
		if(scan (HUI2_GPIO_PORT,HUI2_GPIO_PIN) == ON && scan (HUI1_GPIO_PORT,HUI1_GPIO_PIN) == OFF)
		{
			turn_right(250);
		}
		if(scan (HUI2_GPIO_PORT,HUI2_GPIO_PIN) == OFF && scan (HUI1_GPIO_PORT,HUI1_GPIO_PIN) == OFF)
		{
			qian_jin();		
		}
		if(scan (HUI2_GPIO_PORT,HUI2_GPIO_PIN) == ON && scan (HUI1_GPIO_PORT,HUI1_GPIO_PIN) == ON)
		{
			qian_jin();	
		}

		if(scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON && scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
		{				
			while(1)
			{
				i++;
				SysTick_Dwelay_ms(1000);										//此延时的目的是为了让小车不受到黑线影响，让小车安全过线
				
			}
			if(i==5)
			{
				stop();
				turn_left(250);
				turn_left(250);
			}
			break;
		}
			printf("i=%d",i);
			SysTick_Dwelay_ms(100);
	}

	
}
	



























