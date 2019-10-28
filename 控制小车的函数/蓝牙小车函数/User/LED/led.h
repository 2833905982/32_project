#ifndef _LED_H
#define _LED_H


#include "stm32f10x.h"

#define LED1_GPIO_PIN         GPIO_Pin_0 										//宏定义，定义IO口的引脚号。
#define LED1_GPIO_PORT        GPIOB													//定义IO口的序号。
#define LED1_GPIO_CLK         RCC_APB2Periph_GPIOB						//RCC,时钟函数打开时钟。

#define LED2_GPIO_PIN         GPIO_Pin_1 										//宏定义，定义IO口的引脚号。
#define LED2_GPIO_PORT        GPIOB													//定义IO口的序号。
#define LED2_GPIO_CLK         RCC_APB2Periph_GPIOB						//RCC,时钟函数打开时钟。


/* 右轮控制的GPIO口 */
#define Rwheel1_GPIO_PORT      	GPIOA			             				 /* GPIO端口 */
#define Rwheel1_GPIO_CLK 	      RCC_APB2Periph_GPIOA		 			/* GPIO端口时钟 */
#define Rwheel1_GPIO_PIN		    GPIO_Pin_2			       					 /* 连接到SCL时钟线的GPIO */

/* 左轮控制的GPIO口 */
#define Lwheel2_GPIO_PORT      	GPIOA			              /* GPIO端口 */
#define Lwheel2_GPIO_CLK 	      RCC_APB2Periph_GPIOA		/* GPIO端口时钟 */
#define Lwheel2_GPIO_PIN		    GPIO_Pin_4			        /* 连接到SCL时钟线的GPIO */



void LED1_GPIO_Config(void);


#endif /* _LED_H */


