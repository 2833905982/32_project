#ifndef __BSP_MOTOR_H
#define __BSP_MOTOR_H


#include "stm32f10x.h"


//++++++++++++++++++轮子方向引脚定义+++++++++++++++++++++++++++++++++

#define LUN_GPIO_PORT       	GPIOB		                /* GPIO端口 */
#define LUN_ZUO_GPIO_CLK 	    RCC_APB2Periph_GPIOB		/* GPIO端口时钟 *///左轮
#define LUN_ZUO1_GPIO_PIN		  GPIO_Pin_12	            /* 连接到SCL时钟线的GPIO */
#define LUN_ZUO2_GPIO_PIN		  GPIO_Pin_13	            /* 连接到SCL时钟线的GPIO */

#define LUN_YOU_GPIO_CLK 	    RCC_APB2Periph_GPIOB		/* GPIO端口时钟 *///右轮
#define LUN_YOU1_GPIO_PIN		  GPIO_Pin_14              /* 连接到SCL时钟线的GPIO */
#define LUN_YOU2_GPIO_PIN		  GPIO_Pin_15              /* 连接到SCL时钟线的GPIO */


/* 使用标准的固件库控制IO*/
#define LUN_ZUO1(a)	if (a)	\
					GPIO_SetBits(LUN_GPIO_PORT,LUN_ZUO1_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LUN_GPIO_PORT,LUN_ZUO1_GPIO_PIN)
/* 使用标准的固件库控制IO*/
#define LUN_ZUO2(a)	if (a)	\
					GPIO_SetBits(LUN_GPIO_PORT,LUN_ZUO2_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LUN_GPIO_PORT,LUN_ZUO2_GPIO_PIN)					
					
/* 使用标准的固件库控制IO*/
#define LUN_YOU1(a)	if (a)	\
					GPIO_SetBits(LUN_GPIO_PORT,LUN_YOU1_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LUN_GPIO_PORT,LUN_YOU1_GPIO_PIN)					
/* 使用标准的固件库控制IO*/
#define LUN_YOU2(a)	if (a)	\
					GPIO_SetBits(LUN_GPIO_PORT,LUN_YOU2_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LUN_GPIO_PORT,LUN_YOU2_GPIO_PIN)									
					
/**************************函数声明********************************/

void wheel_GPIO_Config(void);
void motor_qudong(u16 left,u16 right,u16 Fangxiang1,u16 Fangxiang2,u16 Fangxiang3,u16 Fangxiang4);					
void go_stright(void);
void go_back(void);
void turn_right(void);
void turn_left(void);
void left_parall(void);
void right_parall(void);
	
#endif /* __BSP_MOTOR_H */

