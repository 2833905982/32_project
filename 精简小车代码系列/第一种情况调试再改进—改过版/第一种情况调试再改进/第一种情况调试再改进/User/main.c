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
	//初始化函数
	W_GPIO_Config();/*轮子方向*/
	GENERAL_TIM_Init();/* PWM */	
	USART_Config();/* 初始化串口 */
	huidu ();/* 初始化灰度 */
	color();/*颜色*/

	//运行函数
	
	chufa();

//	//左拐45
//	turn_left(400);
//	delay_ms(10);
//	qianjin_xunji();
	
	//左拐130
	turn_left(800);
	qianjin(300);
//	qianjin_xunji();

	
}
