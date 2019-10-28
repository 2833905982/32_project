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
		//stop();
	
	while(1)
	{
		
		//检测左灰度
		if(scan (HUI1_GPIO_PORT,HUI1_GPIO_PIN) == ON && scan (HUI2_GPIO_PORT,HUI2_GPIO_PIN) == OFF)
		{
			turn_left(25);
		}
		//检测右灰度
		if(scan (HUI2_GPIO_PORT,HUI2_GPIO_PIN) == ON && scan (HUI1_GPIO_PORT,HUI1_GPIO_PIN) == OFF)
		{
			turn_right(25);
		}
		if(scan (HUI2_GPIO_PORT,HUI2_GPIO_PIN) == OFF && scan (HUI1_GPIO_PORT,HUI1_GPIO_PIN) == OFF)
		{
			qian_jin();		
		}
		if(scan (HUI2_GPIO_PORT,HUI2_GPIO_PIN) == ON && scan (HUI1_GPIO_PORT,HUI1_GPIO_PIN) == ON)
		{
			qian_jin();	
		}
//   if(/*scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON  &&*/ scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
//		{
//			i++;
//			
//			if(i>=5) 
//			{
//			//	break;
//				while(1)
//				{
//					stop();
//				}
//			}
//			while(1)
//			{
//				qian_jin();
//				if(/*scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == OFF  &&*/ scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == OFF )
//				{
//					break;
//				}
//			}
//		}
							if(/* scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON  && */ scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON )
						{
							i++;

							while(1)
							{
								if(/* scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == OFF && */scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == OFF)
								{
									qian_jin();
									printf("i=%d \n",i);
									SysTick_Dwelay_ms(1000);					
									break;
								}
							}
						}
								if(i>=5)
							{
								i=0;
								stop();
								printf("xiaozhazha");
								SysTick_Dwelay_ms(1000);
								SysTick_Dwelay_ms(1000);
								SysTick_Dwelay_ms(1000);
								SysTick_Dwelay_ms(1000);
								SysTick_Dwelay_ms(1000);
								SysTick_Dwelay_ms(1000);
								SysTick_Dwelay_ms(1000);
								break;
							}

			
			printf("i=%d",i);
			SysTick_Dwelay_ms(100);
	}
}
	





//if(/* scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON  && */ scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON )
//		{
//			i++;

//			while(1)
//			{
//				if(/* scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == OFF && */scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == OFF)
//				{
//					qian_jin();
//					printf("i=%d \n",i);
//					SysTick_Dwelay_ms(1000);					
//					break;
//				}
//			}
//		}
//		if(i>=5)
//			{
//				i=0;
//				stop();
//				printf("xiaozhazha");
//				SysTick_Dwelay_ms(1000);
//				SysTick_Dwelay_ms(1000);
//				SysTick_Dwelay_ms(1000);
//				SysTick_Dwelay_ms(1000);
//				SysTick_Dwelay_ms(1000);
//				SysTick_Dwelay_ms(1000);
//				SysTick_Dwelay_ms(1000);
//				break;
//			}
//	}
//	/*到达物块所在位置*/
//	while(1)
//	{		
//		xunji();
//		if(/*scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON && */scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
//		{
//			stop();
//			SysTick_Dwelay_ms(1000);
//			SysTick_Dwelay_ms(1000);
//			SysTick_Dwelay_ms(1000);
//			SysTick_Dwelay_ms(1000);
//			SysTick_Dwelay_ms(1000);
//			SysTick_Dwelay_ms(1000);
//			SysTick_Dwelay_ms(1000);
//			break;
//		}
//	}
//	

///*颜色识别，即到达物块所在区域后开启颜色识别模块，识别面前的是什么颜色
//并且把相应的物块放到指定位置*/
//	
//	
//	/*如果检测到物块的颜色是绿色*/
//	if(TCS230_Distinguish2()==1)
//	{
//		qian_jin();
//		SysTick_Dwelay_ms(1000);//前进一会为了使其走过黑线
//			
//		while(1)
//		{
//			xunji();
//			
//			//到达下一条条黑线的地区，小车停下一会,并且此阶段寻迹结束
//			if(/*scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == OFF &&*/ scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == OFF)
//			{
//				stop();
//				SysTick_Dwelay_ms(1000);
//				SysTick_Dwelay_ms(1000);
//				SysTick_Dwelay_ms(1000);
//				SysTick_Dwelay_ms(1000);
//				SysTick_Dwelay_ms(1000);
//				
//				break;
//			}
//		}
