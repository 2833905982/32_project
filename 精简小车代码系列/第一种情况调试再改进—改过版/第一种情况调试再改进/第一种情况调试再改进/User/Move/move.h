#ifndef _MOVE_H
#define _MOVE_H


#include "stm32f10x.h"

//++++++++++++++++++���ӷ������Ŷ���+++++++++++++++++++++++++++++++++

#define LUN_GPIO_PORT       		GPIOA		                /* GPIO�˿� */
#define LUN_LEFT_GPIO_CLK 	    RCC_APB2Periph_GPIOA		/* GPIO�˿�ʱ�� *///����
#define LUN_LEFT_GPIO_PIN		  	GPIO_Pin_3              /* ���ӵ�SCLʱ���ߵ�GPIO */
#define LUN_RIGHT_GPIO_CLK 	    RCC_APB2Periph_GPIOA		/* GPIO�˿�ʱ�� *///����
#define LUN_RIGHT_GPIO_PIN		  GPIO_Pin_4              /* ���ӵ�SCLʱ���ߵ�GPIO */



/* ʹ�ñ�׼�Ĺ̼������IO*/
#define LUN_LEFT(a)	if (a)	\
					GPIO_SetBits(LUN_GPIO_PORT,LUN_LEFT_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LUN_GPIO_PORT,LUN_LEFT_GPIO_PIN)
					
/* ʹ�ñ�׼�Ĺ̼������IO*/
#define LUN_RIGHT(a)	if (a)	\
					GPIO_SetBits(LUN_GPIO_PORT,LUN_RIGHT_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LUN_GPIO_PORT,LUN_RIGHT_GPIO_PIN)	
					

/*********************** �������� *****************************/
void W_GPIO_Config(void);					
void Leftsudu(u16 L_speed,u16 L_DIR);//��һ�������ٶ�  �ڶ�����������,1����ת
void Rightsudu(u16 R_speed,u16 R_DIR);//��һ�������ٶ�  �ڶ�����������0����ת
					
					
void qianjin_xunji(void);
//void back_xunji(void);
void qianjin(u16 time);
//void houtui(void);
void turn_left(u16 time);
void turn_right(u16 time);
//void stop(void);
//void qianjin_lukou (uint8_t n);
//void back_lukou(uint8_t m);
//			
//void L_zhuanwan(uint8_t m);

//void R_zhuanwan(uint8_t k);
void chufa(void);
#endif /* _MOVE_H */

