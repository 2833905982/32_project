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

	TIM_Init();
//	GENERAL_TIM4_Init();
 
	/* 初始化串口 */
	USART_Config();
	
	printf("渣子你好！");
	/* 初始化灰度 */
	huidu ();
	
	/* 颜色 */
	color_a();
//	TIM_SetCompare1(ADVANCE_TIM,1000);//对应135度
	while(1)
	{
	  TIM_SetCompare1(ADVANCE_TIM,1500);//对应135度
		delay_ms(1500);
		TIM_SetCompare1(ADVANCE_TIM,500);//对应90度
		delay_ms(1500);
		TIM_SetCompare1(ADVANCE_TIM,1500);//对应135度
		delay_ms(1500);
		TIM_SetCompare1(ADVANCE_TIM,2500);//对应90度
		delay_ms(1500);
	}
		
//// while(1)
//// {
//////	 	delay_ms(500);
//////		TIM_SetCompare1(ADVANCE_TIM,1500);//对应180度
////////		delay_ms(500);
////		TIM_SetCompare1(ADVANCE_TIM,15);//对应135度
////		delay_ms(1500);
////		TIM_SetCompare1(ADVANCE_TIM,0);//对应90度
//////		delay_ms(1500);
//////		TIM_SetCompare2(ADVANCE_TIM,190);//对应45度
//////		delay_ms(500);
//////		TIM_SetCompare2(ADVANCE_TIM,195);//对应0度
//////		delay_ms(500);
//////		TIM_SetCompare2(ADVANCE_TIM,190);//对应45度
//////		delay_ms(500);
//////		TIM_SetCompare2(ADVANCE_TIM,185);//对应90度
//////		delay_ms(500);
//////		TIM_SetCompare2(ADVANCE_TIM,180);//对应135度
//////			delay_ms(500);
//////		TIM_SetCompare2(ADVANCE_TIM,175);//对应180度
//////		delay_ms(500);
//////		TIM_SetCompare2(ADVANCE_TIM,180);//对应135度
//////		delay_ms(500);
//////		TIM_SetCompare2(ADVANCE_TIM,185);//对应90度
//////		delay_ms(500);
//////		TIM_SetCompare2(ADVANCE_TIM,190);//对应45度
//////		delay_ms(500);
//////		TIM_SetCompare2(ADVANCE_TIM,195);//对应0度
//////		delay_ms(500);
//////		TIM_SetCompare2(ADVANCE_TIM,190);//对应45度
//////		delay_ms(500);
//////		TIM_SetCompare2(ADVANCE_TIM,185);//对应90度
//////		delay_ms(500);
//////		TIM_SetCompare2(ADVANCE_TIM,180);//对应135度
//// }
//	/* 打开套筒 */
//	while(1)
//	{
//	TIM_SetCompare1(ADVANCE_TIM,175);
//	delay_s(1);
////	qianjin_xunji();
////	
////	/* 让小车走到第一个检测区 */
////	qianjin_lukou2(2);
////	mangzou_guolukou();
//////	qianjin_lukou2(1);
////	zhuaqu_huidu();
////	delay_s(1);	
////	/* 关闭套筒 */
//	TIM_SetCompare1(ADVANCE_TIM,195);
//	
//	}
//	while(1)
//	{
//		TIM_SetCompare1(ADVANCE_TIM,499);
//		TIM_SetCompare1(ADVANCE_TIM,999);
//		renwu1();
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
//		
//		stop();
//		
//		while(1);
//	}

}

