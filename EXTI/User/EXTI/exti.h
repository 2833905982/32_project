#ifndef EXTI_H
#define EXTI_H

#include "stm32f10x.h"

#define KEY1_INT_GPIO_PIN         GPIO_Pin_0 										//宏定义，定义IO口的引脚号。
#define KEY1_INT_GPIO_PORT        GPIOA													//定义IO口的序号。
#define KEY1_INT_GPIO_CLK         RCC_APB2Periph_GPIOA						//RCC,时钟函数打开时钟。

void EXTI_Key_Config(void);
void EXTI_NVIC_Config(void);

#endif /*EXTI_H*/


