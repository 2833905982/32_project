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
		
	/*����*/
	W_GPIO_Config();
	
	/* PWM */
	GENERAL_TIM_Init();

	TIM_Init();
//	GENERAL_TIM4_Init();
 
	/* ��ʼ������ */
	USART_Config();
	
	printf("������ã�");
	/* ��ʼ���Ҷ� */
	huidu ();
	
	/* ��ɫ */
	color_a();
//	TIM_SetCompare1(ADVANCE_TIM,1000);//��Ӧ135��
	while(1)
	{
	  TIM_SetCompare1(ADVANCE_TIM,1500);//��Ӧ135��
		delay_ms(1500);
		TIM_SetCompare1(ADVANCE_TIM,500);//��Ӧ90��
		delay_ms(1500);
		TIM_SetCompare1(ADVANCE_TIM,1500);//��Ӧ135��
		delay_ms(1500);
		TIM_SetCompare1(ADVANCE_TIM,2500);//��Ӧ90��
		delay_ms(1500);
	}
		
//// while(1)
//// {
//////	 	delay_ms(500);
//////		TIM_SetCompare1(ADVANCE_TIM,1500);//��Ӧ180��
////////		delay_ms(500);
////		TIM_SetCompare1(ADVANCE_TIM,15);//��Ӧ135��
////		delay_ms(1500);
////		TIM_SetCompare1(ADVANCE_TIM,0);//��Ӧ90��
//////		delay_ms(1500);
//////		TIM_SetCompare2(ADVANCE_TIM,190);//��Ӧ45��
//////		delay_ms(500);
//////		TIM_SetCompare2(ADVANCE_TIM,195);//��Ӧ0��
//////		delay_ms(500);
//////		TIM_SetCompare2(ADVANCE_TIM,190);//��Ӧ45��
//////		delay_ms(500);
//////		TIM_SetCompare2(ADVANCE_TIM,185);//��Ӧ90��
//////		delay_ms(500);
//////		TIM_SetCompare2(ADVANCE_TIM,180);//��Ӧ135��
//////			delay_ms(500);
//////		TIM_SetCompare2(ADVANCE_TIM,175);//��Ӧ180��
//////		delay_ms(500);
//////		TIM_SetCompare2(ADVANCE_TIM,180);//��Ӧ135��
//////		delay_ms(500);
//////		TIM_SetCompare2(ADVANCE_TIM,185);//��Ӧ90��
//////		delay_ms(500);
//////		TIM_SetCompare2(ADVANCE_TIM,190);//��Ӧ45��
//////		delay_ms(500);
//////		TIM_SetCompare2(ADVANCE_TIM,195);//��Ӧ0��
//////		delay_ms(500);
//////		TIM_SetCompare2(ADVANCE_TIM,190);//��Ӧ45��
//////		delay_ms(500);
//////		TIM_SetCompare2(ADVANCE_TIM,185);//��Ӧ90��
//////		delay_ms(500);
//////		TIM_SetCompare2(ADVANCE_TIM,180);//��Ӧ135��
//// }
//	/* ����Ͳ */
//	while(1)
//	{
//	TIM_SetCompare1(ADVANCE_TIM,175);
//	delay_s(1);
////	qianjin_xunji();
////	
////	/* ��С���ߵ���һ������� */
////	qianjin_lukou2(2);
////	mangzou_guolukou();
//////	qianjin_lukou2(1);
////	zhuaqu_huidu();
////	delay_s(1);	
////	/* �ر���Ͳ */
//	TIM_SetCompare1(ADVANCE_TIM,195);
//	
//	}
//	while(1)
//	{
//		TIM_SetCompare1(ADVANCE_TIM,499);
//		TIM_SetCompare1(ADVANCE_TIM,999);
//		renwu1();
//		stop();
//		delay_s(1);//����һ������ָ�������
//		
//		R_zhuanwan1(1);
//		delay_s(1);
//		qianjin_lukou2(2);//����h1
//		stop();
//		delay_s(1);
//		
//		renwu2_h();
//		renwu2_f();
//		
//		//���ص���������
//		
//		stop();
//		
//		while(1);
//	}

}

