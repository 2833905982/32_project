#ifndef _HUIDU_H
#define _HUIDU_H

#include "stm32f10x.h"

#define ON     1
#define OFF    0

#define HUI1_GPIO_PIN          GPIO_Pin_4
#define HUI1_GPIO_PORT         GPIOE
#define HUI1_GPIO_CLK          RCC_APB2Periph_GPIOE


#define HUI2_GPIO_PIN          GPIO_Pin_11
#define HUI2_GPIO_PORT         GPIOE
#define HUI2_GPIO_CLK          RCC_APB2Periph_GPIOE

void huidu (void);
int scan (GPIO_TypeDef *GPIOx,int GPIO_Pin); 

#endif /* _HUIDU_H */

