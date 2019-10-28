#ifndef _TIM_H
#define _TIM_H

#include "stm32f10x.h"

/************通用定时器TIM参数定义，只限TIM2、3、4、5************/
// 当使用不同的定时器的时候，对应的GPIO是不一样的，这点要注意
// 我们这里默认使用TIM3


  /* Time base configuration */		 
	/* PWM信号电平跳变值 */
//((1+TIM_Prescaler )/72M)*(1+TIM_Period )=((1+71)/72M)*(1+19999)=20000us	
//u16 CCR4_Val =499;500us,0度 
//u16 CCR4_Val =999;1000us,45度 
//u16 CCR4_Val =1499;1500us,90度
//u16 CCR4_Val =1999;2000us,135度 
//u16 CCR4_Val =2499;2500us,180度 


#define            GENERAL_TIM4                   TIM4
#define            GENERAL_TIM_APBxClock_FUN     RCC_APB1PeriphClockCmd
#define            GENERAL_TIM4_CLK               RCC_APB1Periph_TIM4
#define            GENERAL_TIM4_Period            20000-1
#define            GENERAL_TIM4_Prescaler         72-1
// TIM3 输出比较通道1
#define            GENERAL_TIM4_CH1_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            GENERAL_TIM4_CH1_PORT          GPIOB
#define            GENERAL_TIM4_CH1_PIN           GPIO_Pin_6

//// TIM3 输出比较通道2
//#define            GENERAL_TIM4_CH2_GPIO_CLK      RCC_APB2Periph_GPIOB
//#define            GENERAL_TIM4_CH2_PORT          GPIOB
//#define            GENERAL_TIM4_CH2_PIN           GPIO_Pin_7

// TIM3 输出比较通道3
#define            GENERAL_TIM4_CH3_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            GENERAL_TIM4_CH3_PORT          GPIOB
#define            GENERAL_TIM4_CH3_PIN           GPIO_Pin_8

// TIM3 输出比较通道4
#define            GENERAL_TIM4_CH4_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            GENERAL_TIM4_CH4_PORT          GPIOB
#define            GENERAL_TIM4_CH4_PIN           GPIO_Pin_9




/*------------------------------------------------TIM5配置-------------------------------------------------------*/

#define            GENERAL_TIM5                   TIM5
#define            GENERAL_TIM5_CLK               RCC_APB1Periph_TIM5
#define            GENERAL_TIM_Period_Run         (20000-1)
#define            GENERAL_TIM_Prescaler_Run      (72-1)

// TIM5 输出比较通道1
#define            GENERAL_TIM5_CH1_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM5_CH1_PORT          GPIOA
#define            GENERAL_TIM5_CH1_PIN           GPIO_Pin_0


/**************************函数声明********************************/

void GENERAL_TIM4_Init(void);
void S1riseup(void);
void S1down(void);
void S2open(void);
void S2close(void);
void S4leftright(uint16_t k,uint16_t a);
void S3updown(uint16_t j,uint16_t b);

#endif /*_TIM_H*/


