#ifndef __BSP_GENERALTIME_H
#define __BSP_GENERALTIME_H


#include "stm32f10x.h"


/**************通用定时器TIM参数定义，只限TIM2、3、4、5************/
// 当需要哪个定时器的时候，只需要把下面的宏定义改成1即可

//每次进入中断服务程序间隔时间为
//((1+TIM_Prescaler )/72M)*(1+TIM_Period )=((1+7199)/72M)*(1+9999)=1秒

#define            GENERAL2_TIM                   TIM2
#define            GENERAL2_TIM_APBxClock_FUN     RCC_APB1PeriphClockCmd
#define            GENERAL2_TIM_CLK               RCC_APB1Periph_TIM2
#define            GENERAL2_TIM_Period            (1000-1)
#define            GENERAL2_TIM_Prescaler         71
#define            GENERAL2_TIM_IRQ               TIM2_IRQn
#define            GENERAL2_TIM_IRQHandler        TIM2_IRQHandler


#define            GENERAL3_TIM                   TIM3
#define            GENERAL3_TIM_APBxClock_FUN     RCC_APB1PeriphClockCmd
#define            GENERAL3_TIM_CLK               RCC_APB1Periph_TIM3
#define            GENERAL3_TIM_Period            (10000-1)
#define            GENERAL3_TIM_Prescaler         71
#define            GENERAL3_TIM_IRQ               TIM3_IRQn
#define            GENERAL3_TIM_IRQHandler        TIM3_IRQHandler

//#elif   GENERAL_TIM4
//#define            GENERAL_TIM                   TIM4
//#define            GENERAL_TIM_APBxClock_FUN     RCC_APB1PeriphClockCmd
//#define            GENERAL_TIM_CLK               RCC_APB1Periph_TIM4
//#define            GENERAL_TIM_Period            (1000-1)
//#define            GENERAL_TIM_Prescaler         71
//#define            GENERAL_TIM_IRQ               TIM4_IRQn
//#define            GENERAL_TIM_IRQHandler        TIM4_IRQHandler

//#elif   GENERAL_TIM5
//#define            GENERAL_TIM                   TIM5
//#define            GENERAL_TIM_APBxClock_FUN     RCC_APB1PeriphClockCmd
//#define            GENERAL_TIM_CLK               RCC_APB1Periph_TIM5
//#define            GENERAL_TIM_Period            (1000-1)
//#define            GENERAL_TIM_Prescaler         71
//#define            GENERAL_TIM_IRQ               TIM5_IRQn
//#define            GENERAL_TIM_IRQHandler        TIM5_IRQHandler


/**************************函数声明********************************/

void GENERAL_TIM_Init(void);


#endif	/* __BSP_GENERALTIME_H */


