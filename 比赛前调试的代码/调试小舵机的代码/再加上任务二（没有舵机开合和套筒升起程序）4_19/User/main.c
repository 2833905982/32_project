#include "stm32f10x.h"   
#include "bsp_GeneralTim.h" 
#include "systick.h"
#include "usart.h"
#include "huidu.h"
#include "bsp-gpio.h"
#include "exti.h"
#include "move.h"
#include "weidai.h"
#include "color.h"
#include "TIM.h"
#include "zhuazi.h"
uint16_t c=0;

int main(void)
{
		
	/*轮子*/
	W_GPIO_Config();
	
	/* PWM */
	GENERAL_TIM_Init();

	GENERAL_TIM4_Init();
 
	/* 初始化串口 */
	USART_Config();
	
	printf("渣子你好！");
	/* 初始化灰度 */
	huidu ();
	
	/* 颜色 */
	color_a();
 
	
	/* 打开套筒 */
	TIM_SetCompare1(GENERAL_TIM5,499);
			delay_ms(500);
////	stop();
//	delay_s(1);
//	qianjin_xunji();
//	
////	/* 让小车走到第一个检测区 */
////	qianjin_lukou2(2);
////	mangzou_guolukou();
////	
////	zhuaqu_huidu();
////	delay_s(1);	
////	
//	/* 关闭套筒 */
//		TIM_SetCompare1(GENERAL_TIM5,1999);
//	
//	
//	while(1)
//	{	
//			TIM_SetCompare1(GENERAL_TIM5,499);
//		delay_ms(500);
//			TIM_SetCompare1(GENERAL_TIM5,999);
//				delay_ms(500);
//			TIM_SetCompare1(GENERAL_TIM5,1499);
//				delay_ms(500);
//			TIM_SetCompare1(GENERAL_TIM5,1999);
//				delay_ms(500);
//			TIM_SetCompare1(GENERAL_TIM5,2499);
//				delay_ms(500);
//			TIM_SetCompare1(GENERAL_TIM5,1999);
//				delay_ms(500);
//			TIM_SetCompare1(GENERAL_TIM5,999);
//				delay_ms(500);
//		
////		
////		renwu1();
//		stop();
//		delay_s(1);//任务一结束后车指向出发区
//		
//		R_zhuanwan1(1);
//		delay_s(1);
//		qianjin_lukou2(2);//到达h1
//		stop();
//		delay_s(1);
//		
//		renwu2_h();
//		renwu2_f();
//		
//		//（回到出发区）
//		qianjin_lukou2(3);
//		qianjin();
//		delay_ms(300);
////		
////		stop();
////		
////		while(1);
//	}

}

