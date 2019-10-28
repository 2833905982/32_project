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

	GENERAL_TIM4_Init();
 
	/* ��ʼ������ */
	USART_Config();
	
	printf("������ã�");
	/* ��ʼ���Ҷ� */
	huidu ();
	
	/* ��ɫ */
	color_a();
 
	
	/* ����Ͳ */
	TIM_SetCompare1(GENERAL_TIM5,900);
	stop();
	delay_s(1);
	qianjin_xunji();
	
	/* ��С���ߵ���һ������� */
	qianjin_lukou2(2);
	mangzou_guolukou();
	
	zhuaqu_huidu();
	delay_s(1);	
	
	/* �ر���Ͳ */
	TIM_SetCompare1(GENERAL_TIM5,1900);
	
	
	while(1)
	{	
		renwu1();
		stop();
		delay_s(1);//����һ������ָ�������
		
		R_zhuanwan1(1);
		delay_s(1);
		qianjin_lukou2(2);//����h1
		stop();
		delay_s(1);
		
		renwu2_h();
		renwu2_f();
		
		//���ص���������
		qianjin_lukou2(3);
		qianjin();
		delay_ms(300);
		
		stop();
		
		while(1);
	}

}

