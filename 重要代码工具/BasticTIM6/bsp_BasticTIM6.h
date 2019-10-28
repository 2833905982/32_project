#ifndef _BSP_BASTICTIM6_H
#define _BSP_BASTICTIM6_H


#include "stm32f10x.h"


/********************������ʱ��TIM�������壬ֻ��TIM6��7************/

#define            BASIC_TIM6                   TIM6
#define            BASIC_TIM6_APBxClock_FUN     RCC_APB1PeriphClockCmd
#define            BASIC_TIM6_CLK               RCC_APB1Periph_TIM6
#define            BASIC_TIM6_Period            1000-1					/* �����Ҫ�޸Ķ�ʱ���ڣ��޸ĺ�ÿ��ԡ� */
#define            BASIC_TIM6_Prescaler         71
#define            BASIC_TIM6_IRQ               TIM6_IRQn
#define            BASIC_TIM6_IRQHandler        TIM6_IRQHandler


void BASIC_TIM6_Init(void);

#endif  /* _BAP_BASTICTIM_H */

