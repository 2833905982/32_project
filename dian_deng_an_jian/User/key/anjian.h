#ifndef _KEY_H
#define _KEY_H

#include "stm32f10x.h"


#define KEY1_GPIO_PIN         GPIO_Pin_0 										//�궨�壬����IO�ڵ����źš�
#define KEY1_GPIO_PORT        GPIOA													//����IO�ڵ���š�
#define KEY1_GPIO_CLK         RCC_APB2Periph_GPIOA 					//RCC,ʱ�Ӻ�����ʱ�ӡ�


void key1_GPIO_Config( void );
uint8_t key_Scan( GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin );
void Delay(uint32_t count);

#endif /* _KEY_H */

