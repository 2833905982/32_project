#ifndef _LED_H
#define _LED_H          //��ֹ�ظ�����

#include "stm32f10x.h"

//��Ӳ����صĶ���ɺ�

#define LED_GPIO_PIN                  GPIO_Pin_12
#define LED_GPIO_PORT                 GPIOA
#define LED_GPIO_CLK                  RCC_APB2Periph_GPIOA

  
void led (void);

#endif /*_LED_H*/

