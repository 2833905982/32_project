#ifndef _LED_H
#define _LED_H          


#include "stm32f10x.h"


#define LED1_GPIO_PIN                  GPIO_Pin_1
#define LED1_GPIO_PORT                 GPIOA
#define LED1_GPIO_CLK                  RCC_APB2Periph_GPIOA

#define LED2_GPIO_PIN                  GPIO_Pin_2
#define LED2_GPIO_PORT                 GPIOA
#define LED2_GPIO_CLK                  RCC_APB2Periph_GPIOA

#define LED3_GPIO_PIN                  GPIO_Pin_3
#define LED3_GPIO_PORT                 GPIOA
#define LED3_GPIO_CLK                  RCC_APB2Periph_GPIOA

#define LED4_GPIO_PIN                  GPIO_Pin_4
#define LED4_GPIO_PORT                 GPIOA
#define LED4_GPIO_CLK                  RCC_APB2Periph_GPIOA

#define LED5_GPIO_PIN                  GPIO_Pin_5
#define LED5_GPIO_PORT                 GPIOA
#define LED5_GPIO_CLK                  RCC_APB2Periph_GPIOA



void led (void);

#endif /*_LED_H*/





