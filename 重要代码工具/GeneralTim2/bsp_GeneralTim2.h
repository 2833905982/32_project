#ifndef BSP__GENERALTIME2_H
#define BSP__GENERALTIME2_H


#include "stm32f10x.h"


/************ͨ�ö�ʱ��TIM�������壬ֻ��TIM2��3��4��5************/
// ��ʹ�ò�ͬ�Ķ�ʱ����ʱ�򣬶�Ӧ��GPIO�ǲ�һ���ģ����Ҫע��
// ��������Ĭ��ʹ��TIM3

#define            GENERAL_TIM2                   TIM2
#define            GENERAL_TIM2_APBxClock_FUN     RCC_APB1PeriphClockCmd
#define            GENERAL_TIM2_CLK               RCC_APB1Periph_TIM3
#define            GENERAL_TIM2_Period            599							/*  ���� PWM   ���Ĺ�ʽ 72M/( 10*72 )=100KHZ �� ռ �� �� Ϊ GENERAL_TIM_CCR1/��GENERAL_TIM_PERIOD+1�� = 50%��					*/
#define            GENERAL_TIM2_Prescaler         71


//// TIM3 ����Ƚ�ͨ��1
//#define            GENERAL_TIM2_CH1_GPIO_CLK      RCC_APB2Periph_GPIOA
//#define            GENERAL_TIM2_CH1_PORT          GPIOA
//#define            GENERAL_TIM2_CH1_PIN           GPIO_Pin_0

// TIM3 ����Ƚ�ͨ��2
#define            GENERAL_TIM2_CH2_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM2_CH2_PORT          GPIOA
#define            GENERAL_TIM2_CH2_PIN           GPIO_Pin_1

// TIM3 ����Ƚ�ͨ��3
#define            GENERAL_TIM2_CH3_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM2_CH3_PORT          GPIOA
#define            GENERAL_TIM2_CH3_PIN           GPIO_Pin_2

// TIM3 ����Ƚ�ͨ��4
#define            GENERAL_TIM2_CH4_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM2_CH4_PORT          GPIOA
#define            GENERAL_TIM2_CH4_PIN           GPIO_Pin_3


	
					
					
/**************************��������********************************/


void GENERAL_TIM2_Init(void);


#endif	/* BSP__GENERALTIME2_H */


