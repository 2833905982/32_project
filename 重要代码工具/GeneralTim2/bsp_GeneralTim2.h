#ifndef BSP__GENERALTIME2_H
#define BSP__GENERALTIME2_H


#include "stm32f10x.h"


/************通用定时器TIM参数定义，只限TIM2、3、4、5************/
// 当使用不同的定时器的时候，对应的GPIO是不一样的，这点要注意
// 我们这里默认使用TIM3

#define            GENERAL_TIM2                   TIM2
#define            GENERAL_TIM2_APBxClock_FUN     RCC_APB1PeriphClockCmd
#define            GENERAL_TIM2_CLK               RCC_APB1Periph_TIM3
#define            GENERAL_TIM2_Period            599							/*  计算 PWM   波的公式 72M/( 10*72 )=100KHZ ， 占 空 比 为 GENERAL_TIM_CCR1/（GENERAL_TIM_PERIOD+1） = 50%。					*/
#define            GENERAL_TIM2_Prescaler         71


//// TIM2 输出比较通道1
//#define            GENERAL_TIM2_CH1_GPIO_CLK      RCC_APB2Periph_GPIOA
//#define            GENERAL_TIM2_CH1_PORT          GPIOA
//#define            GENERAL_TIM2_CH1_PIN           GPIO_Pin_0

// TIM2 输出比较通道2
#define            GENERAL_TIM2_CH2_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM2_CH2_PORT          GPIOA
#define            GENERAL_TIM2_CH2_PIN           GPIO_Pin_1

// TIM2 输出比较通道3
#define            GENERAL_TIM2_CH3_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM2_CH3_PORT          GPIOA
#define            GENERAL_TIM2_CH3_PIN           GPIO_Pin_2

// TIM2 输出比较通道4
#define            GENERAL_TIM2_CH4_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM2_CH4_PORT          GPIOA
#define            GENERAL_TIM2_CH4_PIN           GPIO_Pin_3


	
					
					
/**************************函数声明********************************/


void GENERAL_TIM2_Init(void);


#endif	/* BSP__GENERALTIME2_H */


