#ifndef _HUIDU_H
#define _HUIDU_H

#include "stm32f10x.h"

#define ON     1
#define OFF    0

/**********************更新后的**********************/
#define HUI1_GPIO_PIN          GPIO_Pin_5
#define HUI1_GPIO_PORT         GPIOF
#define HUI1_GPIO_CLK          RCC_APB2Periph_GPIOF


#define HUI2_GPIO_PIN          GPIO_Pin_4
#define HUI2_GPIO_PORT         GPIOF
#define HUI2_GPIO_CLK          RCC_APB2Periph_GPIOF


#define HUI3_GPIO_PIN          GPIO_Pin_3
#define HUI3_GPIO_PORT         GPIOF
#define HUI3_GPIO_CLK          RCC_APB2Periph_GPIOF


#define HUI4_GPIO_PIN          GPIO_Pin_2
#define HUI4_GPIO_PORT         GPIOF
#define HUI4_GPIO_CLK          RCC_APB2Periph_GPIOF


#define HUI5_GPIO_PIN          GPIO_Pin_1
#define HUI5_GPIO_PORT         GPIOF
#define HUI5_GPIO_CLK          RCC_APB2Periph_GPIOF


#define HUI6_GPIO_PIN          GPIO_Pin_0
#define HUI6_GPIO_PORT         GPIOF
#define HUI6_GPIO_CLK          RCC_APB2Periph_GPIOF


#define HUI7_GPIO_PIN          GPIO_Pin_11
#define HUI7_GPIO_PORT         GPIOF
#define HUI7_GPIO_CLK          RCC_APB2Periph_GPIOF


#define HUI8_GPIO_PIN          GPIO_Pin_7
#define HUI8_GPIO_PORT         GPIOB
#define HUI8_GPIO_CLK          RCC_APB2Periph_GPIOB

///*************************** END **************************/

///*********************下面这些是未更新的**********************/
#define HUI9_GPIO_PIN          GPIO_Pin_8
#define HUI9_GPIO_PORT         GPIOF
#define HUI9_GPIO_CLK          RCC_APB2Periph_GPIOF


#define HUI10_GPIO_PIN         GPIO_Pin_9
#define HUI10_GPIO_PORT        GPIOF
#define HUI10_GPIO_CLK         RCC_APB2Periph_GPIOF


#define HUI11_GPIO_PIN         GPIO_Pin_10
#define HUI11_GPIO_PORT        GPIOF
#define HUI11_GPIO_CLK         RCC_APB2Periph_GPIOF


#define HUI12_GPIO_PIN         GPIO_Pin_11
#define HUI12_GPIO_PORT        GPIOF
#define HUI12_GPIO_CLK         RCC_APB2Periph_GPIOF


#define HUI13_GPIO_PIN         GPIO_Pin_12
#define HUI13_GPIO_PORT        GPIOF
#define HUI13_GPIO_CLK         RCC_APB2Periph_GPIOF


#define HUI14_GPIO_PIN         GPIO_Pin_13
#define HUI14_GPIO_PORT        GPIOF
#define HUI14_GPIO_CLK         RCC_APB2Periph_GPIOF


void huidu (void);
int scan (GPIO_TypeDef *GPIOx,int GPIO_Pin); 

#endif /* _HUIDU_H */

