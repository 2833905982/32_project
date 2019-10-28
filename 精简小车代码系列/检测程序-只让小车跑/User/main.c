#include "bsp_GeneralTim.h" 
#include "stm32f10x.h"   
#include "bsp-gpio.h"
#include "systick.h"
#include "jiaodu.h"
#include "usart.h"
#include "huidu.h"
#include "exti.h"
#include "move.h"

int main(void)
{
	
	/* 初始化 PWM */
	GENERAL_TIM_Init();
 
	/* 初始化串口 */
	USART_Config();
	
	/* 初始化灰度 */
	huidu();
	
	/* 初始化运动 */
	wheel_configer();
		
	/* 初始化小车的方向和速度 */
	Leftsudu(400,ON);                                //输出高电平的时间为100， DIR = 0,    则左轮正转
	Rightsudu(400,OFF);                               //输出高电平的时间为100，DIR = 1,    则右轮正转

	while(1)
	{
		
	}
}
	

