#ifndef _KEY_H
#define _KEY_H

#include "stm32f10x.h"


#define KEY1_GPIO_PIN         GPIO_Pin_0 										//宏定义，定义IO口的引脚号。
#define KEY1_GPIO_PORT        GPIOA													//定义IO口的序号。
#define KEY1_GPIO_CLK         RCC_APB2Periph_GPIOA 					//RCC,时钟函数打开时钟。


void key1_GPIO_Config( void );
uint8_t key_Scan( GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin );
void Delay(uint32_t count);

#endif /* _KEY_H */

