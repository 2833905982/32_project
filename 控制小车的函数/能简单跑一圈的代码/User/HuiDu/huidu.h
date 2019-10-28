#ifndef _HUIDU_H
#define _HUIDU_H

#include "stm32f10x.h"

#define ON     1
#define OFF    0

#define HUI1_GPIO_PIN          GPIO_Pin_0
#define HUI1_GPIO_PORT         GPIOE
#define HUI1_GPIO_CLK          RCC_APB2Periph_GPIOE


#define HUI2_GPIO_PIN          GPIO_Pin_1
#define HUI2_GPIO_PORT         GPIOE
#define HUI2_GPIO_CLK          RCC_APB2Periph_GPIOE


#define HUI3_GPIO_PIN          GPIO_Pin_2
#define HUI3_GPIO_PORT         GPIOE
#define HUI3_GPIO_CLK          RCC_APB2Periph_GPIOE


#define HUI4_GPIO_PIN          GPIO_Pin_3
#define HUI4_GPIO_PORT         GPIOE
#define HUI4_GPIO_CLK          RCC_APB2Periph_GPIOE


#define HUI5_GPIO_PIN          GPIO_Pin_4
#define HUI5_GPIO_PORT         GPIOE
#define HUI5_GPIO_CLK          RCC_APB2Periph_GPIOE

#define HUI6_GPIO_PIN          GPIO_Pin_5
#define HUI6_GPIO_PORT         GPIOE
#define HUI6_GPIO_CLK          RCC_APB2Periph_GPIOE

#define HUI7_GPIO_PIN          GPIO_Pin_6
#define HUI7_GPIO_PORT         GPIOE
#define HUI7_GPIO_CLK          RCC_APB2Periph_GPIOE


void huidu (void);
int scan (GPIO_TypeDef *GPIOx,int GPIO_Pin); 

#endif /* _HUIDU_H */

