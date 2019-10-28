#ifndef _BSP_GPIO_H
#define _BSP_GPIO_H

#include "stm32f10x.h"


/* 右轮控制的GPIO口 */
#define Rwheel1_GPIO_PORT      	GPIOA			             					 /* GPIO端口 */
#define Rwheel1_GPIO_CLK 	      RCC_APB2Periph_GPIOA		 					/* GPIO端口时钟 */
#define Rwheel1_GPIO_PIN		    GPIO_Pin_2			       					 /* 连接到SCL时钟线的GPIO */

/* 左轮控制的GPIO口 */
#define Lwheel2_GPIO_PORT      	GPIOA			            					  /* GPIO端口 */
#define Lwheel2_GPIO_CLK 	      RCC_APB2Periph_GPIOA							/* GPIO端口时钟 */
#define Lwheel2_GPIO_PIN		    GPIO_Pin_4			        					/* 连接到SCL时钟线的GPIO */


void LUN_GPIO_Config(void);

#endif /* _BSP_GPIO_H */



