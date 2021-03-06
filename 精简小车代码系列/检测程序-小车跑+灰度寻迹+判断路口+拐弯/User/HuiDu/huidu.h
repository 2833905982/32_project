#ifndef _HUIDU_H
#define _HUIDU_H

#include "stm32f10x.h"

#define ON     1
#define OFF    0

#define HUI1_GPIO_PIN          GPIO_Pin_0
#define HUI1_GPIO_PORT         GPIOF
#define HUI1_GPIO_CLK          RCC_APB2Periph_GPIOF


#define HUI2_GPIO_PIN          GPIO_Pin_1
#define HUI2_GPIO_PORT         GPIOF
#define HUI2_GPIO_CLK          RCC_APB2Periph_GPIOF


#define HUI3_GPIO_PIN          GPIO_Pin_2
#define HUI3_GPIO_PORT         GPIOF
#define HUI3_GPIO_CLK          RCC_APB2Periph_GPIOF


#define HUI4_GPIO_PIN          GPIO_Pin_1
#define HUI4_GPIO_PORT         GPIOA
#define HUI4_GPIO_CLK          RCC_APB2Periph_GPIOA


#define HUI5_GPIO_PIN          GPIO_Pin_4
#define HUI5_GPIO_PORT         GPIOF
#define HUI5_GPIO_CLK          RCC_APB2Periph_GPIOF


#define HUI6_GPIO_PIN          GPIO_Pin_5
#define HUI6_GPIO_PORT         GPIOF
#define HUI6_GPIO_CLK          RCC_APB2Periph_GPIOF


#define HUI7_GPIO_PIN          GPIO_Pin_6
#define HUI7_GPIO_PORT         GPIOF
#define HUI7_GPIO_CLK          RCC_APB2Periph_GPIOF


#define HUI8_GPIO_PIN          GPIO_Pin_7
#define HUI8_GPIO_PORT         GPIOF
#define HUI8_GPIO_CLK          RCC_APB2Periph_GPIOF


#define HUI9_GPIO_PIN          GPIO_Pin_8
#define HUI9_GPIO_PORT         GPIOF
#define HUI9_GPIO_CLK          RCC_APB2Periph_GPIOF


#define HUI10_GPIO_PIN         GPIO_Pin_9
#define HUI10_GPIO_PORT        GPIOF
#define HUI10_GPIO_CLK         RCC_APB2Periph_GPIOF



void huidu (void);
int scan (GPIO_TypeDef *GPIOx,int GPIO_Pin); 

#endif /* _HUIDU_H */

