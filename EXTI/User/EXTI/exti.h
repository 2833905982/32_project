#ifndef EXTI_H
#define EXTI_H

#include "stm32f10x.h"

#define KEY1_INT_GPIO_PIN         GPIO_Pin_0 										//�궨�壬����IO�ڵ����źš�
#define KEY1_INT_GPIO_PORT        GPIOA													//����IO�ڵ���š�
#define KEY1_INT_GPIO_CLK         RCC_APB2Periph_GPIOA						//RCC,ʱ�Ӻ�����ʱ�ӡ�

void EXTI_Key_Config(void);
void EXTI_NVIC_Config(void);

#endif /*EXTI_H*/

