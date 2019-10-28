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


/*4_21����Ҫ�ӵĶ�����
1.ÿ�ι��׵��200s��ʱ
2.����λ��У׼����
3.��ɫʶ����ֵ*/


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
	TIM_SetCompare1(GENERAL_TIM5,2200);
	stop();
	delay_s(1);
	qianjin_xunji();
	
	/* ��С���ߵ���һ������� */
	qianjin_lukou2(2);
	mangzou_guolukou();
	
	zhuaqu_huidu();
	delay_s(1);	
	
	/* �ر���Ͳ */
	TIM_SetCompare1(GENERAL_TIM5,1200);
	delay_s(1);	


	while(1)
	{	
		renwu1();
		stop();
		delay_s(1);//����һ������ָ�������
		qianjin();
		delay_ms(200);
		qianjin_lukou2(3);
		qianjin();
		delay_ms(300);
		stop();
		delay_s(1);//����1�����ص�������
		
		
		turn_180();
		delay_s(1);
		qianjin_lukou2(2);
		mangzou_guolukou();
		L_zhuanwan(3);
		delay_s(1);
		qianjin();
		delay_ms(200);
		qianjin_lukou2(1);//����h1
		zhuaqu_huidu();
		stop();
		delay_s(1);
		
		renwu2_h();
		renwu2_f();
		
		//���ص���������
		qianjin();
		delay_ms(200);
		qianjin_lukou2(3);
		qianjin();
		delay_ms(300);
		
		stop();
		
		while(1);
	}

}

