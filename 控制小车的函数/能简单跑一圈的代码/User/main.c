#include "stm32f10x.h"
#include "bsp_led.h"
#include "systick.h"
#include "exti.h"
#include "base.h"
#include "color.h"
#include "weidai.h"
#include "usart.h"
#include "bsp_GeneralTim.h"
#include "bsp-gpio.h"
#include "huidu.h"
#include "jiaodu.h"
#include "xunji.h"


uint16_t i = 0;

void green(void)
{
	/*如果检测到物块的颜色是绿色*/
		printf("绿色！\n");
		qian_jin();
	qian_jin();
	qian_jin();
	qian_jin();
	
//		SysTick_Dwelay_ms(1000);//前进一会为了使其走过黑线
		delay_ms(1000);	
		while(1)
		{
			xunji();
			
			//到达下一条条黑线的地区，小车停下一会,并且此阶段寻迹结束
			if(/*scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == OFF &&*/ scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
			{
				stop();
				delay_ms(1000);
				delay_ms(1000);
				
				delay_ms(1000);
				
				break;
			}
		}
		turn_left(1000);//向左转向90度,继续绕着弧形巡线巡线
		//SysTick_Dwelay_ms(10);
		delay_ms(1000);
		while(1)
		{
			xunji();
			
			/*此时只有一个灰度可以检测路口，需要过两个路口可以到达绿色放置区*/
			if(scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
			{
					i++;
					delay_ms(200);
					while(1)
					{
						qian_jin();
						if(scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == OFF)//出了黑线
							break;
					}
			}
			if(i>=2)//即此时到达绿色放置区,这一阶段寻迹结束
			{
				i=0;
				stop();
				delay_ms(1000);
				delay_ms(1000);
				delay_ms(1000);
				delay_ms(1000);
				delay_ms(1000);
				break;
			}
		}	
			turn_left(1000);//向左转向90度,继续绕着弧形巡线巡线
			//SysTick_Dwelay_ms(10);
			delay_ms(1200);
		
			/*再向前走一个路口到达A处，并且识别A的颜色，放好它*/
		while(1)
		{
			xunji();
			//到达放置A物块的区域
			if(/* scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON &&  */ scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
			{
					stop();
					delay_ms(1000);
					delay_ms(1000);
					delay_ms(1000);
					break;//这一阶段结束，
			}
		}
		
		
		
				/*开始识别颜色，如果A物块是红色,
				继续向前走，过两个路口，到达米字型位置，左转90度
		 		之后向前走，到达红色位置，之后退回来*/
		i=0;
		while(1)
		{
			/* 如果为红色，则执行此函数 */
			if(TCS230_Distinguish2()==3)
				{
					qian_jin();
					qian_jin();
					qian_jin();
					qian_jin();													
					delay_ms(1000);				//延时50ms让灰度过A所在黑线
					while(1)
					{
						xunji();
						delay_ms(100);
						if(/*scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON && */scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
						{
							i++;
							delay_ms(200);
							while(1)
							{
								qian_jin();
								if(/*scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON && */scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == OFF)
								break;
							}
						}
							if(i>=2)
							{
								i=0;
								stop();
								delay_ms(1000);
								delay_ms(1000);
								delay_ms(1000);
								delay_ms(1000);
								delay_ms(1000);	
							break;//到达米字型路口								
							}
					}
					/*到这里小车已经回到了米字路口
					下一步向红色物块放置区出发*/
					
					turn_left(1000);//向左转向90度
					delay_ms(1000);
					
					/*小车从米字型中心走到红色放置区*/
					while(1)
					{
						xunji();
						
						//这里延时的目的是使小车可以安全过去米字型交叉而不受影响
						delay_ms(100);
						
						if(/*scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON && */scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
						{
							i++;
							while(1)
							{
								qian_jin();
								if(/*scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == OFF &&*/ scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == OFF)//出了黑线
									break;
							}
						}
						if(i>=2)
						{
							i=0;
							stop();
							delay_ms(1000);
							delay_ms(1000);						
							delay_ms(1000);
							delay_ms(1000);
							delay_ms(1000);
							break;
						}
					}
					/*这个后退需要在后面加灰度，使其后退时也可以寻迹，
					并且寻迹到米字型中心的位置停下来*/

						back();
						back();
						back();
						back();
						delay_ms(1000);	
					while(1)
					{
						back_xunji();
						if(/*scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON && */scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
						{
							i++;
							delay_ms(200);	
							while(1)
							{
								back();
								back_xunji();
								if(/*scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON && */scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == OFF)
								break;
							}
						}
						if(i>=3)
						{
								i=0;
								stop();
								delay_ms(1000);
								delay_ms(1000);
								delay_ms(1000);
								delay_ms(1000);
								delay_ms(1000);	
							break;//到达米字型路口		
						}
					}
					/*之后向右拐90度,开始巡线，过两个路口，把E点推到蓝色区域*/
					turn_right(1000);
					delay_ms(600);
					while(1)
					{
						xunji();
						delay_ms(100);					//这里延时的目的是使小车可以安全过去米字型交叉而不受影响					
						if(/*scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON && */scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
						{
							i++;
							delay_ms(200);
							while(1)
							{
								qian_jin();
								if(/*scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == OFF && */scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == OFF)//出了黑线
									break;
							}
						}
						if(i>=2)
						{
							i=0;
							stop();
              delay_ms(1000);
							delay_ms(1000);
							delay_ms(1000);
							delay_ms(1000);
							delay_ms(1000);
							delay_ms(1000);
							
							break;
						}
					}//到这一步之后物块已经被推到了蓝色区域

					
					/*然后后退回到中心点，向左旋转九十度，
					后退回到初始位置，此次完毕*/
					
					back();//这里也要用灰度寻迹，判断路口，使其可以到达中心点
					back();
					back();
					back();
					while(1)
					{
						back_xunji();
						if(/*scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON && */scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
						{
							i++;
							delay_ms(500);	
							while(1)
							{
								back();
								if(/*scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON && */scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == OFF)
								break;
							}
						}
					if(i>=3)
					{
						i=0;
						stop();
						delay_ms(1000);
						delay_ms(1000);
						delay_ms(1000);
						delay_ms(1000);
						delay_ms(1000);
						delay_ms(1000);
						break;						
					}
				}
					turn_right(1000);
					delay_ms(850);
					
					qian_jin();
					qian_jin();
					qian_jin();
					qian_jin();													
					delay_ms(1000);				
					
					while(1)
					{
						xunji();
						delay_ms(100);
						if(/*scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON && */scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
						{
							i++;
							delay_ms(200);
							while(1)
							{
								qian_jin();
								if(/*scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON && */scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == OFF)
								break;
							}
						}
							if(i>=4)
							{
								i=0;
								stop();
								delay_ms(1000);
								delay_ms(1000);
								delay_ms(1000);
								delay_ms(1000);
								delay_ms(1000);	
							break;//到达米字型路口								
							}
					}
					//回到初始位置	
					break;
					
				}
		}//大while
	}//函数
//				/*识别颜色，如果A为蓝色*/
//				if(TCS230_Distinguish2()==5)
//				{
//					qian_jin();
//					qian_jin();
//					qian_jin();
//					qian_jin();													
//					delay_ms(1000);				//延时1000ms让灰度过A所在黑线								
//					while(1)
//					{
//						xunji();
//						delay_ms(1000);    //这里延时的目的是使小车安全过去A点处的交线						
//						//如果到了中点
//						if(scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
//						{
//							stop();
//							delay_ms(50);
//							break;
//						}
//					}
//					turn_left(1000);//左转90度
//					delay_ms(1000);
//					qian_jin();
//					//SysTick_Dwelay_ms(50);//前进一会防止黑线影响
//					delay_ms(50);
//					
//					while(1)
//					{
//						xunji();
//						if(/* scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON && */ scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
//						{
//							i++;
//							while(1)
//							{
//								qian_jin();
//								if(/* scan ( HUI3_GPIO_PORT,HUI3_GPIO_PIN) == OFF && */ scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == OFF)//出了黑线
//									break;
//							}
//						}
//						if(i>=2)
//						{
//							i=0;
//							stop();
//							//SysTick_Dwelay_ms(10);
//							delay_ms(50);
//							break;
//						}
//					}//这一步结束后小车走到了红色的放置区
//					
//					/*下一步让小车从红色区走到蓝色区*/
//					turn_right(250);//右转90度
//					while(1)
//					{
//						xunji();
//						if(scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
//						{
//							i++;
//							while(1)
//							{
//								if(scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == OFF)
//									break;
//							}
//						}
//						if(i==2)
//							{
//								i=0;
//								stop();
//								//SysTick_Dwelay_ms(10);
//								delay_ms(50);
//								break;
//							}
//					}//此时小车已经到达蓝色放置区
//				//	SysTick_Dwelay_ms(50);
//					delay_ms(50);
//					
//					
//					
//					
//					
//					/*这一步是为了让小车从蓝色放置区到达E点*/
//					while(1)
//					{
//						xunji();
//						if(/*scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON &&  */ scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
//						{
//							stop();
//							//SysTick_Dwelay_ms(10);//到达E点
//							delay_ms(50);
//							break;
//						}
//					}
//					/*,然后把E送到红色放置区*/
//					while(1)
//					{
//						qian_jin();
//						delay_ms(50);
//						//SysTick_Dwelay_ms(50);//这里的目的是使小车安全度过黑线E，不受影响
//						if(/* scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON &&  */ scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
//						{
//							stop();
//							delay_ms(50);
//							//SysTick_Dwelay_ms(50);//到达米字中心点
//							break;//这一阶段的寻迹结束了
//						}
//					}
//					/*这里是使小车可以从米字型中心点到达红色放置区*/
//					turn_right(250);
//					delay_ms(50);
//				//	SysTick_Dwelay_ms(10);
//					
//					qian_jin();
//					delay_ms(50);
//					//SysTick_Dwelay_ms(50);//使小车过了受影响的黑线
//					while(1)
//					{
//						xunji();
//						if(/* scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON &&  */scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
//						{
//							i++;
//							while(1)
//							{
//								qian_jin();
//								if(/* scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == OFF &&  */ scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == OFF)
//									break;
//							}
//						}
//						if(i==2)
//						{
//							i=0;
//							stop();
//							delay_ms(50);
//							//SysTick_Dwelay_ms(50);
//							break;
//						}
//					}//到这里小车已经到达了红色放置区，
//					
//					/*小车退回到出发区*/
//					back();
//					//此次搬运结束
//					break;
//				}
//		}
//	}		
//	

int main (void)
{
	//uint8_t ch;
	
	/* 初始化 GPIO口 */
	LUN_GPIO_Config();
	
	/* 初始化按键 */
//	EXTI_Key_Config();
	
	/* 初始化 PWM */
	GENERAL_TIM_Init();
	 
 
	/* 初始化串口 */
	USART_Config();
	
	/* 初始化灰度 */
	huidu ();
	
	
	/*颜色*/
	TIM2_Configuration();
	TIM2_NVIC_Configuration();
	Color2_GPIO_Config();
	EXTI2_NVIC_Configuration();
	EXTI_PG2_Config();
	color_Init();
	TCS230_Start2();
	EXTI_PG2_Config_on();
	EXTI_PG2_Config_off();
	USART_Config();
	SysTick_Init();
	
	
	printf("color");
	
	//	/*---------------------初始化小车，即前进方向的固定----------------------------*/

//	/* 操作A2引脚 */
	GPIO_SetBits(Rwheel1_GPIO_PORT, Rwheel1_GPIO_PIN);											//右轮正转
//	//GPIO_ResetBits(Rwheel1_GPIO_PORT, Rwheel1_GPIO_PIN);									//右轮反转
//		
//	/* 操作的A4引脚 */
//	//GPIO_SetBits(Lwheel2_GPIO_PORT, Lwheel2_GPIO_PIN);					  				//左轮反转
	GPIO_ResetBits(Lwheel2_GPIO_PORT, Lwheel2_GPIO_PIN);										//左轮正转
//

/*到达米字型前的寻迹和判断路口*/
	while(1)
	{
		xunji();
		if( scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON )
		{
			i++;
			delay_ms(200);
			while(1)
			{
				qian_jin();				
				if(scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == OFF)
				{

					printf("i=%d \n",i);
					break;
				}
			}
		}
		if(i>=5)
			{
				i=0;
				stop();
				delay_ms(1000);
				delay_ms(1000);
				delay_ms(1000);
				delay_ms(1000);				
				break;
			}
	}
	/*到达物块所在位置*/
	while(1)
	{		
		xunji();
		if(scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
		{
			stop();
			delay_ms(1000);
			delay_ms(1000);
			delay_ms(1000);
			break;
		}
	}
	
	
	
	while(1)
	{		
		switch(TCS230_Distinguish2())
		{
			case 1:green();break;
			case 2:printf(" 白色 \n");break;
			case 3:printf(" 红色 \n");break;
			case 4:printf(" 黑色 \n");break;		
			case 5:printf(" 蓝色 \n");break;
			case 0:printf(" 不知 \n");break;										
		}delay_s(1);
	}
}

	
