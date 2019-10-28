#ifndef __BSP_GENERALTIME_H
#define __BSP_GENERALTIME_H


#include "stm32f10x.h"


/************通用定时器TIM参数定义，只限TIM2、3、4、5************/
// 当使用不同的定时器的时候，对应的GPIO是不一样的，这点要注意
// 我们这里默认使用TIM5

#define            GENERAL_TIM5                   TIM5
#define            GENERAL_TIM5_APBxClock_FUN     RCC_APB1PeriphClockCmd
#define            GENERAL_TIM5_CLK               RCC_APB1Periph_TIM5


// 输入捕获能捕获到的最小的频率为 72M/{ (ARR+1)*(PSC+1) }
#define            GENERAL_TIM5_PERIOD           (1000-1)
#define            GENERAL_TIM5_PSC              (72-1)


// 中断相关宏定义
//#define            GENERAL_TIM5_IT_CCx            TIM_IT_CC1
#define            GENERAL_TIM5_IRQ              	 TIM5_IRQn
#define            GENERAL_TIM5_IRQHandler         TIM5_IRQHandler

// TIM 输入捕获通道GPIO相关宏定义
#define            GENERAL_TIM5_CH1_GPIO_CLK       RCC_APB2Periph_GPIOA
#define            GENERAL_TIM5_CH1_PORT           GPIOA
#define            GENERAL_TIM5_CH1_PIN            GPIO_Pin_0

#define            GENERAL_TIM5_IC1PWM_CHANNEL     TIM_Channel_1
#define            GENERAL_TIM5_IC2PWM_CHANNEL     TIM_Channel_2



/**************************函数声明********************************/

void GENERAL_TIM_Init(void);


#endif	/* __BSP_GENERALTIME_H */


