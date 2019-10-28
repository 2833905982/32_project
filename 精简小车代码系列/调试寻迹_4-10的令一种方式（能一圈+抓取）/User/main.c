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

int main(void)
{
		
	/*����*/
	W_GPIO_Config();
	
	/* PWM */
	GENERAL_TIM_Init();
	
	TIM_Init();
 
	/* ��ʼ������ */
	USART_Config();
	
	/* ��ʼ���Ҷ� */
	huidu ();
	
	/*��ɫ*/
	color();
	
	TIM_SetCompare1(TIM4,0);
	TIM_SetCompare1(ADVANCE_TIM,182);
	delay_s(1);
		
	qianjin();
	
	/* ��С���ߵ���һ������� */
	qianjin_lukou2(6);
	delay_s(1);
	TIM_SetCompare1(ADVANCE_TIM,194);
	
//	while(1)
//	{
//		switch(TCS230_Distinguish2())
//		{
//			case 1:green();break;
//			case 2:printf(" ��ɫ \n");break;
//			case 3:printf(" ��ɫ \n");break;
//			case 4:printf(" ��ɫ \n");break;		
//			case 5:printf(" ��ɫ \n");break;
//			case 0:printf(" ��֪ \n");break;										
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
	

