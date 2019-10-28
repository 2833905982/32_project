#ifndef _LED_H
#define _LED_H


#include "stm32f10x.h"

#define LED1_GPIO_PIN         GPIO_Pin_0 										//�궨�壬����IO�ڵ����źš�
#define LED1_GPIO_PORT        GPIOB													//����IO�ڵ���š�
#define LED1_GPIO_CLK         RCC_APB2Periph_GPIOB						//RCC,ʱ�Ӻ�����ʱ�ӡ�

#define LED2_GPIO_PIN         GPIO_Pin_1 										//�궨�壬����IO�ڵ����źš�
#define LED2_GPIO_PORT        GPIOB													//����IO�ڵ���š�
#define LED2_GPIO_CLK         RCC_APB2Periph_GPIOB						//RCC,ʱ�Ӻ�����ʱ�ӡ�


/* ���ֿ��Ƶ�GPIO�� */
#define Rwheel1_GPIO_PORT      	GPIOA			             				 /* GPIO�˿� */
#define Rwheel1_GPIO_CLK 	      RCC_APB2Periph_GPIOA		 			/* GPIO�˿�ʱ�� */
#define Rwheel1_GPIO_PIN		    GPIO_Pin_2			       					 /* ���ӵ�SCLʱ���ߵ�GPIO */

/* ���ֿ��Ƶ�GPIO�� */
#define Lwheel2_GPIO_PORT      	GPIOA			              /* GPIO�˿� */
#define Lwheel2_GPIO_CLK 	      RCC_APB2Periph_GPIOA		/* GPIO�˿�ʱ�� */
#define Lwheel2_GPIO_PIN		    GPIO_Pin_4			        /* ���ӵ�SCLʱ���ߵ�GPIO */



void LED1_GPIO_Config(void);


#endif /* _LED_H */


