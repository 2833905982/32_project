#ifndef __BSP_TIMEBASE_H
#define __BSP_TIMEBASE_H


#include "stm32f10x.h"


/********************基本定时器TIM参数定义，只限TIM6、7************/

#define            BASIC_TIM6                   TIM6
#define            BASIC_TIM6_APBxClock_FUN     RCC_APB1PeriphClockCmd
#define            BASIC_TIM6_CLK               RCC_APB1Periph_TIM6
#define            BASIC_TIM6_Period            1000-1
#define            BASIC_TIM6_Prescaler         71
#define            BASIC_TIM6_IRQ               TIM6_IRQn
#define            BASIC_TIM6_IRQHandler        TIM6_IRQHandler


#define            BASIC_TIM7                  TIM7
#define            BASIC_TIM7_APBxClock_FUN     RCC_APB1PeriphClockCmd
#define            BASIC_TIM7_CLK               RCC_APB1Periph_TIM7
#define            BASIC_TIM7_Period            1000-1
#define            BASIC_TIM7_Prescaler         71
#define            BASIC_TIM7_IRQ               TIM7_IRQn
#define            BASIC_TIM7_IRQHandler        TIM7_IRQHandler

/**************************函数声明********************************/

void BASIC_TIM_Init(void);


#endif	/* __BSP_TIMEBASE_H */


