#ifndef _BSP_GPIO_H
#define _BSP_GPIO_H

#include "stm32f10x.h"


/* ���ֿ��Ƶ�GPIO�� */
#define Rwheel1_GPIO_PORT      	GPIOA			             					 /* GPIO�˿� */
#define Rwheel1_GPIO_CLK 	      RCC_APB2Periph_GPIOA		 					/* GPIO�˿�ʱ�� */
#define Rwheel1_GPIO_PIN		    GPIO_Pin_2			       					 /* ���ӵ�SCLʱ���ߵ�GPIO */

/* ���ֿ��Ƶ�GPIO�� */
#define Lwheel2_GPIO_PORT      	GPIOA			            					  /* GPIO�˿� */
#define Lwheel2_GPIO_CLK 	      RCC_APB2Periph_GPIOA							/* GPIO�˿�ʱ�� */
#define Lwheel2_GPIO_PIN		    GPIO_Pin_4			        					/* ���ӵ�SCLʱ���ߵ�GPIO */


void LUN_GPIO_Config(void);

#endif /* _BSP_GPIO_H */



