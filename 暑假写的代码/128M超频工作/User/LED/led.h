#ifndef __LED_H
#define __LED_H

#include "stm32f10x.h"



#define LED_GPIO_PIN         GPIO_Pin_12  										//�궨�壬����IO�ڵ����źš�
#define LED_GPIO_PORT        GPIOA													//����IO�ڵ���š�
#define LED_GPIO_CLK         RCC_APB2Periph_GPIOA						//RCC,ʱ�Ӻ�����ʱ�ӡ�


void LED_GPIO_Config(void);


#endif /* __LED_H */

