#ifndef _LED_H
#define _LED_H          //防止重复编译

#include "stm32f10x.h"

//与硬件相关的定义成宏

#define LED_GPIO_PIN                  GPIO_Pin_12
#define LED_GPIO_PORT                 GPIOA
#define LED_GPIO_CLK                  RCC_APB2Periph_GPIOA

  
void led (void);

#endif /*_LED_H*/

