#ifndef __LED_H
#define __LED_H


#include "stm32f10x.h"


#define LED1_GPIO_PIN              GPIO_Pin_2
#define LED1_GPIO_PORT             GPIOA
#define LED1_GPIO_CLK              RCC_APB2Periph_GPIOA

#define LED2_GPIO_PIN              GPIO_Pin_1
#define LED2_GPIO_PORT             GPIOB
#define LED2_GPIO_CLK              RCC_APB2Periph_GPIOB

#define LED3_GPIO_PIN              GPIO_Pin_2
#define LED3_GPIO_PORT             GPIOB
#define LED3_GPIO_CLK              RCC_APB2Periph_GPIOB

#define LED4_GPIO_PIN              GPIO_Pin_8
#define LED4_GPIO_PORT             GPIOB
#define LED4_GPIO_CLK              RCC_APB2Periph_GPIOB

#define LED5_GPIO_PIN              GPIO_Pin_9
#define LED5_GPIO_PORT             GPIOB
#define LED5_GPIO_CLK              RCC_APB2Periph_GPIOB

#define LED6_GPIO_PIN              GPIO_Pin_5
#define LED6_GPIO_PORT             GPIOB
#define LED6_GPIO_CLK              RCC_APB2Periph_GPIOB

#define LED7_GPIO_PIN              GPIO_Pin_6
#define LED7_GPIO_PORT             GPIOB
#define LED7_GPIO_CLK              RCC_APB2Periph_GPIOB

#define LED8_GPIO_PIN              GPIO_Pin_7
#define LED8_GPIO_PORT             GPIOB
#define LED8_GPIO_CLK              RCC_APB2Periph_GPIOB

void LED_GPIO_Config(void);

#endif /* __LED_H */


