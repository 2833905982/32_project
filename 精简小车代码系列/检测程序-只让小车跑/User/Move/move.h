#ifndef _MOVE_H
#define _MOVE_H


#include "stm32f10x.h"


//++++++++++++++++++���ӷ������Ŷ���+++++++++++++++++++++++++++++++++

#define LUN_GPIO_PORT       	GPIOA		                /* GPIO�˿� */
#define LUN_ZUO_GPIO_CLK 	    RCC_APB2Periph_GPIOA		/* GPIO�˿�ʱ�� *///����
#define LUN_ZUO_GPIO_PIN		  GPIO_Pin_2	            /* ���ӵ�SCLʱ���ߵ�GPIO */
#define LUN_YOU_GPIO_CLK 	    RCC_APB2Periph_GPIOA		/* GPIO�˿�ʱ�� *///����
#define LUN_YOU_GPIO_PIN		  GPIO_Pin_4              /* ���ӵ�SCLʱ���ߵ�GPIO */



/* ʹ�ñ�׼�Ĺ̼������IO*/
#define LUN_ZUO(a)	if (a)	\
					GPIO_SetBits(LUN_GPIO_PORT,LUN_ZUO_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LUN_GPIO_PORT,LUN_ZUO_GPIO_PIN)
					
/* ʹ�ñ�׼�Ĺ̼������IO*/
#define LUN_YOU(a)	if (a)	\
					GPIO_SetBits(LUN_GPIO_PORT,LUN_YOU_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LUN_GPIO_PORT,LUN_YOU_GPIO_PIN)					
					
					
					
void wheel_configer(void);														/* ���� GPIO �� */
void Leftsudu(u16 left,u16 fangxiang);								/* ��һ�������ٶ�  �ڶ�����������,0����ת */
void Rightsudu(u16 right,u16 fangxiang);							/* ��һ�������ٶ�  �ڶ�����������1����ת */
//void sudu(u16 left,u16 right,u16 Fangxiang1,u16 Fangxiang2);//ǰ�����������ҵ���ٶ�  ��������������					
void move_Init(void);

#endif /* _MOVE_H */
/*------------------------------END OF FILE-----------------------------------*/		

					