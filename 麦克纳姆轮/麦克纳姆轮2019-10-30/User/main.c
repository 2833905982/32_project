/********************************
名称：麦克纳姆轮小车
  
	文 件 名   : main.c
  版 本 号   : v1.0
  作    者   : 商俊辉  
  生成日期   : 2019-10-27
  最近修改   : 2019-10-30
  功能描述   : 学习使用麦克纳姆轮
********************************/

#include "stm32f10x.h"   // 相当于51单片机中的  #include <reg51.h>
#include "./led/bsp_led.h"
#include "./motor/bsp_motor.h"
#include "./usart2/bsp_usart2.h"
#include "./systick/bsp_systick.h"
#include "./GeneralTim4/bsp_GeneralTim4.h"

char ch = 'a';

int main(void)
{
	// 来到这里的时候，系统的时钟已经被配置成72M。
	
	//初始化串口
	USART2_Config();
	//初始化车轮GPIO口
	wheel_GPIO_Config();
	//初始化定时器4
	GENERAL_TIM4_Init();

	while(1)
	{
		ch = getchar();
		printf("ch = %c",ch);
		
		switch(ch)
		{
			/* 前进 */
			case '1': go_stright(); break;
			/* 后退 */
			case '2': go_back();break;
			/* 左拐 */
			case '3': turn_left();	break;
			/* 右拐 */
			case '4': turn_right();break;
			/* 左平移 */
			case '5': left_parall();	break;
			/* 右平移 */
			case '6': right_parall();break;			
			/* 停止 */
			case '7': go_stright();break;
			default : break;
		}
		
//		//向前走
//		go_stright();
//		SysTick_Delay_ms(3000);
//		SysTick_Delay_ms(3000);
//		//向后走
//		go_back();
//		SysTick_Delay_ms(3000);
//		SysTick_Delay_ms(3000);
//		//向右转
//		turn_right();
//		SysTick_Delay_ms(3000);
//		SysTick_Delay_ms(3000);		
//		//向左转
//		turn_left();	
//		SysTick_Delay_ms(3000);
//		SysTick_Delay_ms(3000);				
//		//向左平移
//		left_parall();
//		SysTick_Delay_ms(3000);
//		SysTick_Delay_ms(3000);
//		//向右平移
//		right_parall();
//		SysTick_Delay_ms(3000);
//		SysTick_Delay_ms(3000);
	}
  	
}


