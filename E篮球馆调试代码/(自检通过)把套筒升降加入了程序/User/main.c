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

/*4_21上午要加的东西：
1.每次过白点加200s延时
2.放置位置校准函数
3.颜色识别阈值*/


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
	
//	S1riseup();//套筒下降
//	S1down();//套筒上升
//	
//	S3updown(449,1499);
//	S3updown(1449,499);
//	
//	S4leftright(449,1499);
//	S4leftright(1499,999);
 
 
//	/* 打开套筒 */
	TIM_SetCompare1(GENERAL_TIM5,1880);
	stop();
	delay_s(1);
	qianjin_xunji();
	
	/* 让小车走到第一个检测区 */
	qianjin_lukou2(2);
	mangzou_guolukou();
	
	zhuaqu_huidu();
	delay_s(1);	
	
	/* 关闭套筒 */
	TIM_SetCompare1(GENERAL_TIM5,900);
	delay_s(1);	

	
	while(1)
	{	
		renwu1();
		stop();
		delay_s(1);//任务一结束后车指向出发区
		
		R_zhuanwan1(1);
		delay_s(1);
		qianjin_lukou2(2);//到达h1
		stop();
		delay_s(1);
		
		renwu2_h();
		renwu2_f();
		
		//（回到出发区）
		qianjin_lukou2(3);
		qianjin();
		delay_ms(300);
		
		stop();
		
		while(1);
	}

}

