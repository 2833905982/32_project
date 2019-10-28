#ifndef _BSP_BASTICTIM6_H
#define _BSP_BASTICTIM6_H


#include "stm32f10x.h"


/********************基本定时器TIM参数定义，只限TIM6、7************/

#define            BASIC_TIM6                   TIM6
#define            BASIC_TIM6_APBxClock_FUN     RCC_APB1PeriphClockCmd
#define            BASIC_TIM6_CLK               RCC_APB1Periph_TIM6
#define            BASIC_TIM6_Period            1000-1					/* 如果想要修改定时周期，修改宏久可以。 */
#define            BASIC_TIM6_Prescaler         71
#define            BASIC_TIM6_IRQ               TIM6_IRQn
#define            BASIC_TIM6_IRQHandler        TIM6_IRQHandler


void BASIC_TIM6_Init(void);

#endif  /* _BAP_BASTICTIM_H */

