#ifndef _GPIO_H
#define _GPIO_H


#include "stm32f10x.h"

//#define GPIO1_PIN         GPIO_Pin_0 										//�궨�壬����IO�ڵ����źš�
//#define GPIO1_PORT        GPIOB													//����IO�ڵ���š�
//#define GPIO1_CLK         RCC_APB2Periph_GPIOB						//RCC,ʱ�Ӻ�����ʱ�ӡ�

#define GPIO2_PIN         GPIO_Pin_1 										//�궨�壬����IO�ڵ����źš�
#define GPIO2_PORT        GPIOB													//����IO�ڵ���š�
#define GPIO2_CLK         RCC_APB2Periph_GPIOB						//RCC,ʱ�Ӻ�����ʱ�ӡ�




void GPIO_Config(void);


#endif /* _GPIO_H */


