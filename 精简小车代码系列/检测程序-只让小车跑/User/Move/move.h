#ifndef _MOVE_H
#define _MOVE_H


#include "stm32f10x.h"


//++++++++++++++++++轮子方向引脚定义+++++++++++++++++++++++++++++++++

#define LUN_GPIO_PORT       	GPIOA		                /* GPIO端口 */
#define LUN_ZUO_GPIO_CLK 	    RCC_APB2Periph_GPIOA		/* GPIO端口时钟 *///左轮
#define LUN_ZUO_GPIO_PIN		  GPIO_Pin_2	            /* 连接到SCL时钟线的GPIO */
#define LUN_YOU_GPIO_CLK 	    RCC_APB2Periph_GPIOA		/* GPIO端口时钟 *///右轮
#define LUN_YOU_GPIO_PIN		  GPIO_Pin_4              /* 连接到SCL时钟线的GPIO */



/* 使用标准的固件库控制IO*/
#define LUN_ZUO(a)	if (a)	\
					GPIO_SetBits(LUN_GPIO_PORT,LUN_ZUO_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LUN_GPIO_PORT,LUN_ZUO_GPIO_PIN)
					
/* 使用标准的固件库控制IO*/
#define LUN_YOU(a)	if (a)	\
					GPIO_SetBits(LUN_GPIO_PORT,LUN_YOU_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LUN_GPIO_PORT,LUN_YOU_GPIO_PIN)					
					
					
					
void wheel_configer(void);														/* 配置 GPIO 口 */
void Leftsudu(u16 left,u16 fangxiang);								/* 第一个参数速度  第二个参数方向,0是正转 */
void Rightsudu(u16 right,u16 fangxiang);							/* 第一个参数速度  第二个参数方向，1是正转 */
//void sudu(u16 left,u16 right,u16 Fangxiang1,u16 Fangxiang2);//前两个参数左右电机速度  后两个参数方向					
void move_Init(void);

#endif /* _MOVE_H */
/*------------------------------END OF FILE-----------------------------------*/		

					