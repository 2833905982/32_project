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
 
	/* 初始化串口 */
	USART_Config();
	
	printf("渣子你好！");
	/* 初始化灰度 */
	huidu ();
	
	/* 颜色 */
	color1();
	
	/* 打开套筒 */
	TIM_SetCompare1(ADVANCE_TIM,182);
	delay_s(1);
	qianjin_xunji();
	
	/* 让小车走到第一个检测区 */
	qianjin_lukou2(5);
	zhuaqu_huidu();
	delay_s(1);	
	/* 关闭套筒 */
	TIM_SetCompare1(ADVANCE_TIM,194);
	
	
	while(1)
	{
		renwu1();
		stop();
		while(1);
	}


}

