#ifndef __BSP_GENERALTIME_H
#define __BSP_GENERALTIME_H


#include "stm32f10x.h"


/************通用定时器TIM参数定义，只限TIM2、3、4、5************/
// 当使用不同的定时器的时候，对应的GPIO是不一样的，这点要注意
// 我们这里默认使用TIM3



#define            GENERAL_TIM3                   TIM3
#define            GENERAL_TIM_APBxClock_FUN      RCC_APB1PeriphClockCmd
#define            GENERAL_TIM3_CLK               RCC_APB1Periph_TIM3
#define            GENERAL_TIM_Period            (20000-1)
#define            GENERAL_TIM_Prescaler         (72-1)
// TIM3 输出比较通道1
#define            GENERAL_TIM3_CH1_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM3_CH1_PORT          GPIOA
#define            GENERAL_TIM3_CH1_PIN           GPIO_Pin_6

// TIM3 输出比较通道2
#define            GENERAL_TIM3_CH2_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM3_CH2_PORT          GPIOA
#define            GENERAL_TIM3_CH2_PIN           GPIO_Pin_7

// TIM3 输出比较通道3
#define            GENERAL_TIM3_CH3_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            GENERAL_TIM3_CH3_PORT          GPIOB
#define            GENERAL_TIM3_CH3_PIN           GPIO_Pin_0

// TIM3 输出比较通道4
#define            GENERAL_TIM3_CH4_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            GENERAL_TIM3_CH4_PORT          GPIOB
#define            GENERAL_TIM3_CH4_PIN           GPIO_Pin_1



/*---------------------------------------------------------------TIM4配置-----------------------------------------------------*/

#define            GENERAL_TIM4                   TIM4
#define            GENERAL_TIM4_CLK               RCC_APB1Periph_TIM4
//#define            GENERAL_TIM4_CLK               RCC_APB1Periph_TIM3
#define            GENERAL_TIM4_Period            (20000-1)
#define            GENERAL_TIM4_Prescaler         (72-1)


// TIM4 输出比较通道1
#define            GENERAL_TIM4_CH1_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            GENERAL_TIM4_CH1_PORT          GPIOB
#define            GENERAL_TIM4_CH1_PIN           GPIO_Pin_6

// TIM4 输出比较通道2
#define            GENERAL_TIM4_CH2_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            GENERAL_TIM4_CH2_PORT          GPIOB
#define            GENERAL_TIM4_CH2_PIN           GPIO_Pin_7




/*------------------------------------------------TIM5配置-------------------------------------------------------*/

#define            GENERAL_TIM5                   TIM5
#define            GENERAL_TIM5_CLK               RCC_APB1Periph_TIM5
#define            GENERAL_TIM_Period_Run         (7200-1)
#define            GENERAL_TIM_Prescaler_Run      (1-1)
// TIM5 输出比较通道1
#define            GENERAL_TIM5_CH1_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM5_CH1_PORT          GPIOA
#define            GENERAL_TIM5_CH1_PIN           GPIO_Pin_0

// TIM5 输出比较通道2
#define            GENERAL_TIM5_CH2_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM5_CH2_PORT          GPIOA
#define            GENERAL_TIM5_CH2_PIN           GPIO_Pin_1

// TIM5 输出比较通道3
#define            GENERAL_TIM5_CH3_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM5_CH3_PORT          GPIOA
#define            GENERAL_TIM5_CH3_PIN           GPIO_Pin_2

// TIM5 输出比较通道3
#define            GENERAL_TIM5_CH4_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM5_CH4_PORT          GPIOA
#define            GENERAL_TIM5_CH4_PIN           GPIO_Pin_3






/**************************函数声明********************************/



/**************************函数声明********************************/

void GENERAL_TIM_Init(void);


#endif	/* __BSP_GENERALTIME_H */


