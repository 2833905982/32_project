#ifndef _GPIO_H
#define _GPIO_H


#include "stm32f10x.h"

//#define GPIO1_PIN         GPIO_Pin_0 										//宏定义，定义IO口的引脚号。
//#define GPIO1_PORT        GPIOB													//定义IO口的序号。
//#define GPIO1_CLK         RCC_APB2Periph_GPIOB						//RCC,时钟函数打开时钟。

#define GPIO2_PIN         GPIO_Pin_1 										//宏定义，定义IO口的引脚号。
#define GPIO2_PORT        GPIOB													//定义IO口的序号。
#define GPIO2_CLK         RCC_APB2Periph_GPIOB						//RCC,时钟函数打开时钟。




void GPIO_Config(void);


#endif /* _GPIO_H */


