#ifndef _MOVE_H
#define _MOVE_H


#include "stm32f10x.h"

//++++++++++++++++++轮子方向引脚定义+++++++++++++++++++++++++++++++++

#define LUN_GPIO_PORT       		GPIOA		                /* GPIO端口 */
#define LUN_LEFT_GPIO_CLK 	    RCC_APB2Periph_GPIOA		/* GPIO端口时钟 *///左轮
#define LUN_LEFT_GPIO_PIN		  	GPIO_Pin_2              /* 连接到SCL时钟线的GPIO */
#define LUN_RIGHT_GPIO_CLK 	    RCC_APB2Periph_GPIOA		/* GPIO端口时钟 *///右轮
#define LUN_RIGHT_GPIO_PIN		  GPIO_Pin_4              /* 连接到SCL时钟线的GPIO */



/* 使用标准的固件库控制IO*/
#define LUN_LEFT(a)	if (a)	\
					GPIO_SetBits(LUN_GPIO_PORT,LUN_LEFT_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LUN_GPIO_PORT,LUN_LEFT_GPIO_PIN)
					
/* 使用标准的固件库控制IO*/
#define LUN_RIGHT(a)	if (a)	\
					GPIO_SetBits(LUN_GPIO_PORT,LUN_RIGHT_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LUN_GPIO_PORT,LUN_RIGHT_GPIO_PIN)	
					

/*********************** 函数声明 *****************************/
void W_GPIO_Config(void);					
void Leftsudu(u16 L_speed,u16 L_DIR);//第一个参数速度  第二个参数方向,1是正转
void Rightsudu(u16 R_speed,u16 R_DIR);//第一个参数速度  第二个参数方向，0是正转
void qianjin_xunji(void);
void back_xunji(void);
void qianjin(void);
void houtui(void);
void turn_left(void);
void turn_right(void);
void stop(void);
void qianjin_lukou1 (uint8_t n);
void qianjin_lukou2(uint8_t n);
void back_lukou1(uint8_t m);
void back_lukou2(uint8_t m);
void L_zhuanwan(uint8_t m);
void R_zhuanwan1(uint8_t k);
void R_zhuanwan2(uint8_t k);
void lukou_3(uint8_t m);

					
#endif /* _MOVE_H */

