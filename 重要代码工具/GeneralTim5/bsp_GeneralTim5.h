#ifndef _BSP_GENERALTIM5_H
#define _BSP_GENERALTIM5_H

#include "stm32f10x.h"

/************ͨ�ö�ʱ��TIM�������壬ֻ��TIM2��3��4��5************/
// ��ʹ�ò�ͬ�Ķ�ʱ����ʱ�򣬶�Ӧ��GPIO�ǲ�һ���ģ����Ҫע��
// ��������Ĭ��ʹ��TIM3


  /* Time base configuration */		 
	/* PWM�źŵ�ƽ����ֵ */
//((1+TIM_Prescaler )/72M)*(1+TIM_Period )=((1+71)/72M)*(1+19999)=20000us	
//u16 CCR4_Val =499;500us,0�� 
//u16 CCR4_Val =999;1000us,45�� 
//u16 CCR4_Val =1499;1500us,90��
//u16 CCR4_Val =1999;2000us,135�� 
//u16 CCR4_Val =2499;2500us,180�� 


#define            GENERAL_TIM5                   TIM5
#define            GENERAL_TIM5_APBxClock_FUN      RCC_APB1PeriphClockCmd
#define            GENERAL_TIM5_CLK               RCC_APB1Periph_TIM5
#define            GENERAL_TIM5_Period            20000-1
#define            GENERAL_TIM5_Prescaler         72-1
// TIM5 ����Ƚ�ͨ��1
#define            GENERAL_TIM5_CH1_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM5_CH1_PORT          GPIOA
#define            GENERAL_TIM5_CH1_PIN           GPIO_Pin_0

// TIM5 ����Ƚ�ͨ��2
#define            GENERAL_TIM5_CH2_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM5_CH2_PORT          GPIOA
#define            GENERAL_TIM5_CH2_PIN           GPIO_Pin_1

// TIM5 ����Ƚ�ͨ��3
#define            GENERAL_TIM5_CH3_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM5_CH3_PORT          GPIOA
#define            GENERAL_TIM5_CH3_PIN           GPIO_Pin_2

// TIM5 ����Ƚ�ͨ��4
#define            GENERAL_TIM5_CH4_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM5_CH4_PORT          GPIOA
#define            GENERAL_TIM5_CH4_PIN           GPIO_Pin_3


/**************************��������********************************/
void GENERAL_TIM5_Init(void);

#endif /* _BSP_GENERALTIM5_H */


