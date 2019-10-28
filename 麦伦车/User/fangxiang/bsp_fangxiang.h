#ifndef __FANGXIANG_H
#define	__FANGXIANG_H


#include "stm32f10x.h"


//��ǰ
#define LUN1_GPIO_PORT    	GPIOD			              /* GPIO�˿� */
#define LUN1_GPIO_CLK 	    RCC_APB2Periph_GPIOD		/* GPIO�˿�ʱ�� */
#define LUN1_GPIO_PIN		    GPIO_Pin_0		        /* ���ӵ�SCLʱ���ߵ�GPIO */


#define LUN2_GPIO_PORT    	GPIOD			              /* GPIO�˿� */
#define LUN2_GPIO_CLK 	    RCC_APB2Periph_GPIOD		/* GPIO�˿�ʱ�� */
#define LUN2_GPIO_PIN		    GPIO_Pin_1			        /* ���ӵ�SCLʱ���ߵ�GPIO */

//��ǰ
#define LUN3_GPIO_PORT    	GPIOD			              /* GPIO�˿� */
#define LUN3_GPIO_CLK 	    RCC_APB2Periph_GPIOD		/* GPIO�˿�ʱ�� */
#define LUN3_GPIO_PIN		    GPIO_Pin_2			        /* ���ӵ�SCLʱ���ߵ�GPIO */


#define LUN4_GPIO_PORT    	GPIOD			              /* GPIO�˿� */
#define LUN4_GPIO_CLK 	    RCC_APB2Periph_GPIOD		/* GPIO�˿�ʱ�� */
#define LUN4_GPIO_PIN		    GPIO_Pin_3			        /* ���ӵ�SCLʱ���ߵ�GPIO */

//���
#define LUN5_GPIO_PORT    	GPIOD			              /* GPIO�˿� */
#define LUN5_GPIO_CLK 	    RCC_APB2Periph_GPIOD		/* GPIO�˿�ʱ�� */
#define LUN5_GPIO_PIN		    GPIO_Pin_4		        /* ���ӵ�SCLʱ���ߵ�GPIO */


#define LUN6_GPIO_PORT    	GPIOD			              /* GPIO�˿� */
#define LUN6_GPIO_CLK 	    RCC_APB2Periph_GPIOD		/* GPIO�˿�ʱ�� */
#define LUN6_GPIO_PIN		    GPIO_Pin_5			        /* ���ӵ�SCLʱ���ߵ�GPIO */

//�Һ�
#define LUN7_GPIO_PORT    	GPIOD			              /* GPIO�˿� */
#define LUN7_GPIO_CLK 	    RCC_APB2Periph_GPIOD		/* GPIO�˿�ʱ�� */
#define LUN7_GPIO_PIN		    GPIO_Pin_6			        /* ���ӵ�SCLʱ���ߵ�GPIO */


#define LUN8_GPIO_PORT    	GPIOD			              /* GPIO�˿� */
#define LUN8_GPIO_CLK 	    RCC_APB2Periph_GPIOD		/* GPIO�˿�ʱ�� */
#define LUN8_GPIO_PIN		    GPIO_Pin_7			        /* ���ӵ�SCLʱ���ߵ�GPIO */




#define ON  1
#define OFF 0

/* ʹ�ñ�׼�Ĺ̼������IO*/
#define LUN1(a)	if (a)	\
					GPIO_SetBits(LUN1_GPIO_PORT,LUN1_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LUN1_GPIO_PORT,LUN1_GPIO_PIN)

#define LUN2(a)	if (a)	\
					GPIO_SetBits(LUN2_GPIO_PORT,LUN2_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LUN2_GPIO_PORT,LUN2_GPIO_PIN)

#define LUN3(a)	if (a)	\
					GPIO_SetBits(LUN3_GPIO_PORT,LUN3_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LUN3_GPIO_PORT,LUN3_GPIO_PIN)
					
#define LUN4(a)	if (a)	\
					GPIO_SetBits(LUN4_GPIO_PORT,LUN4_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LUN4_GPIO_PORT,LUN4_GPIO_PIN)	

#define LUN5(a)	if (a)	\
					GPIO_SetBits(LUN5_GPIO_PORT,LUN5_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LUN5_GPIO_PORT,LUN5_GPIO_PIN)

#define LUN6(a)	if (a)	\
					GPIO_SetBits(LUN6_GPIO_PORT,LUN6_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LUN6_GPIO_PORT,LUN6_GPIO_PIN)
					
#define LUN7(a)	if (a)	\
					GPIO_SetBits(LUN7_GPIO_PORT,LUN7_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LUN7_GPIO_PORT,LUN7_GPIO_PIN)	
									
#define LUN8(a)	if (a)	\
					GPIO_SetBits(LUN8_GPIO_PORT,LUN8_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LUN8_GPIO_PORT,LUN8_GPIO_PIN)






void LUN_GPIO_Config(void);

#endif /* __FANGXIANG_H */






