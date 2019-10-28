#ifndef __LED_H
#define __LED_H

#include "stm32f10x.h"



#define LED_GPIO_PIN         GPIO_Pin_12  										//宏定义，定义IO口的引脚号。
#define LED_GPIO_PORT        GPIOA													//定义IO口的序号。
#define LED_GPIO_CLK         RCC_APB2Periph_GPIOA						//RCC,时钟函数打开时钟。


void LED_GPIO_Config(void);


#endif /* __LED_H */

