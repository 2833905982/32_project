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

int main(void)
{
		
	/*轮子*/
	W_GPIO_Config();
	
	/* PWM */
	GENERAL_TIM_Init();
 
	/* 初始化串口 */
	USART_Config();
	
	/* 初始化灰度 */
	huidu ();
	
	/*颜色*/
	color();
		
	qianjin();
	
	/* 让小车走到第一个检测区 */
	qianjin_lukou(7);
	
//	while(1)
//	{
//		switch(TCS230_Distinguish2())
//		{
//			case 1:green();break;
//			case 2:printf(" 白色 \n");break;
//			case 3:printf(" 红色 \n");break;
//			case 4:printf(" 黑色 \n");break;		
//			case 5:printf(" 蓝色 \n");break;
//			case 0:printf(" 不知 \n");break;										
//		}delay_s(1);
//	}
	while(1)
	{
		if(TCS230_Distinguish2()==1)
		{
			green();
			break;
		}
	}
}
	

