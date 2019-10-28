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
 
	/* ��ʼ������ */
	USART_Config();
	
	printf("������ã�");
	/* ��ʼ���Ҷ� */
	huidu ();
	
	/* ��ɫ */
	color1();
	
	/* ����Ͳ */
	TIM_SetCompare1(ADVANCE_TIM,182);
	delay_s(1);
	qianjin_xunji();
	
	/* ��С���ߵ���һ������� */
	qianjin_lukou2(5);
	zhuaqu_huidu();
	delay_s(1);	
	/* �ر���Ͳ */
	TIM_SetCompare1(ADVANCE_TIM,194);
	
	
	while(1)
	{
		renwu1();
		stop();
		while(1);
	}


}

