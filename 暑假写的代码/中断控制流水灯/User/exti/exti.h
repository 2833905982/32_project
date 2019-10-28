#ifndef __EXTI_H
#define __EXTI_H

#include "stm32f10x.h"

#define KEY1_INT_GPIO_PIN           GPIO_Pin_0
#define KEY1_INT_GPIO_PORT          GPIOA
#define KEY1_INT_GPIO_CLK           RCC_APB2Periph_GPIOA

void EXTI_Key_Config(void);

#endif /* __EXTI_H */
