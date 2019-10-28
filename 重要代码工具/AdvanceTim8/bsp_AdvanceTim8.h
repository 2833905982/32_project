#ifndef _BSP_ADVANCETIM8_H
#define _BSP_ADVANCETIM8_H

#include "stm32f10x.h"

/************高级定时器TIM参数定义，只限TIM1和TIM8************/
// 当使用不同的定时器的时候，对应的GPIO是不一样的，这点要注意
// 这里我们使用高级控制定时器TIM1

#define            ADVANCE_TIM8                   TIM8
#define            ADVANCE_TIM8_APBxClock_FUN     RCC_APB2PeriphClockCmd
#define            ADVANCE_TIM8_CLK               RCC_APB2Periph_TIM8
// PWM 信号的频率 F = TIM_CLK/{(ARR+1)*(PSC+1)}
#define            ADVANCE_TIM8_PERIOD            (8-1)					//调整周期
#define            ADVANCE_TIM8_PSC               (9-1)					//调整分频因子
#define            ADVANCE_TIM8_PULSE             4							//调整占空比

#define            ADVANCE_TIM8_IRQ               TIM1_UP_IRQn
#define            ADVANCE_TIM8_IRQHandler        TIM1_UP_IRQHandler

// TIM1 输出比较通道
#define            ADVANCE_TIM8_CH1_GPIO_CLK      RCC_APB2Periph_GPIOC
#define            ADVANCE_TIM8_CH1_PORT          GPIOC
#define            ADVANCE_TIM8_CH1_PIN           GPIO_Pin_6

// TIM1 输出比较通道的互补通道
#define            ADVANCE_TIM8_CH1N_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            ADVANCE_TIM8_CH1N_PORT          GPIOA
#define            ADVANCE_TIM8_CH1N_PIN           GPIO_Pin_7

// TIM1 输出比较通道的刹车通道
#define            ADVANCE_TIM8_BKIN_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            ADVANCE_TIM8_BKIN_PORT          GPIOB
#define            ADVANCE_TIM8_BKIN_PIN           GPIO_Pin_6

void ADVANCE_TIM8_Init(void);


#endif /* _BSP_ADVANCETIM_H */

