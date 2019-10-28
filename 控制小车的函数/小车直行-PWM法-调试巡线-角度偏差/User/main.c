#include "stm32f10x.h"   // 相当于51单片机中的  #include <reg51.h>
#include "bsp_GeneralTim.h" 
#include "systick.h"
#include "jiaodu.h"
#include "usart.h"
#include "huidu.h"
#include "exti.h"
#include "led.h"

void qianjin(void);
void houtui(void);
void zuoguai(void);
void youguai(void);
uint16_t i = 0;
int main(void)
{
	// 来到这里的时候，系统的时钟已经被配置成72M。
	//uint8_t ch;
	
	/* 初始化 GPIO口 */
	LED1_GPIO_Config();																			//设置函数封装各个功能块。
	
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
		//GPIO_SetBits(Rwheel1_GPIO_PORT, Rwheel1_GPIO_PIN);											//右轮正转
		GPIO_ResetBits(Rwheel1_GPIO_PORT, Rwheel1_GPIO_PIN);									//右轮反转
		
		/* 操作的A4引脚 */
		GPIO_SetBits(Lwheel2_GPIO_PORT, Lwheel2_GPIO_PIN);					  				//左轮反转
		//GPIO_ResetBits(Lwheel2_GPIO_PORT, Lwheel2_GPIO_PIN);										//左轮正转
		
	
	while(1)
	{
		
		//检测左灰度
		if(scan (HUI1_GPIO_PORT,HUI1_GPIO_PIN) == ON && scan (HUI2_GPIO_PORT,HUI2_GPIO_PIN) == OFF)
		{
			//LED1;
				turn_left(250);
		}

		//检测右灰度
		if(scan (HUI2_GPIO_PORT,HUI2_GPIO_PIN) == ON && scan (HUI1_GPIO_PORT,HUI1_GPIO_PIN) == OFF)
		{
						//LED1;
				turn_right(250);

		}
		if(scan (HUI2_GPIO_PORT,HUI2_GPIO_PIN) == OFF && scan (HUI1_GPIO_PORT,HUI1_GPIO_PIN) == OFF)
		{
			
			TIM_SetCompare3(TIM3,400);																		//调节 BO，即右轮的快慢
			TIM_SetCompare4(TIM3,400);																			//调节 B1，即左轮的快慢
	
		}
		if(scan (HUI2_GPIO_PORT,HUI2_GPIO_PIN) == ON && scan (HUI1_GPIO_PORT,HUI1_GPIO_PIN) == ON)
		{
			TIM_SetCompare3(TIM3,400);																		//调节 BO，即右轮的快慢
			TIM_SetCompare4(TIM3,400);																			//调节 B1，即左轮的快慢		
		}

	}
	
}
	

//void qianjin(void)
//{
//	GPIO_ResetBits(Rwheel1_GPIO_PORT, Rwheel1_GPIO_PIN);
//	GPIO_SetBits(Lwheel2_GPIO_PORT, Lwheel2_GPIO_PIN);	
//}
//void houtui(void)
//{
//	GPIO_SetBits(Rwheel1_GPIO_PORT, Rwheel1_GPIO_PIN);
//	GPIO_ResetBits(Lwheel2_GPIO_PORT, Lwheel2_GPIO_PIN);
//}
//void zuoguai(void)
//{
//	GPIO_SetBits(Lwheel2_GPIO_PORT, Lwheel2_GPIO_PIN);
//	GPIO_SetBits(Rwheel1_GPIO_PORT, Rwheel1_GPIO_PIN);
//}
//void youguai(void)
//{
//	GPIO_ResetBits(Lwheel2_GPIO_PORT, Lwheel2_GPIO_PIN);
//	GPIO_ResetBits(Rwheel1_GPIO_PORT, Rwheel1_GPIO_PIN);
//}


























