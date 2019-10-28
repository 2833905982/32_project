#ifndef _TIM_H
#define _TIM_H

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


#define            GENERAL_TIM4                   TIM4
#define            GENERAL_TIM_APBxClock_FUN     RCC_APB1PeriphClockCmd
#define            GENERAL_TIM4_CLK               RCC_APB1Periph_TIM4
#define            GENERAL_TIM4_Period            20000-1
#define            GENERAL_TIM4_Prescaler         72-1
// TIM3 ����Ƚ�ͨ��1
#define            GENERAL_TIM4_CH1_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            GENERAL_TIM4_CH1_PORT          GPIOB
#define            GENERAL_TIM4_CH1_PIN           GPIO_Pin_6

//// TIM3 ����Ƚ�ͨ��2
//#define            GENERAL_TIM4_CH2_GPIO_CLK      RCC_APB2Periph_GPIOB
//#define            GENERAL_TIM4_CH2_PORT          GPIOB
//#define            GENERAL_TIM4_CH2_PIN           GPIO_Pin_7

// TIM3 ����Ƚ�ͨ��3
#define            GENERAL_TIM4_CH3_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            GENERAL_TIM4_CH3_PORT          GPIOB
#define            GENERAL_TIM4_CH3_PIN           GPIO_Pin_8

// TIM3 ����Ƚ�ͨ��4
#define            GENERAL_TIM4_CH4_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            GENERAL_TIM4_CH4_PORT          GPIOB
#define            GENERAL_TIM4_CH4_PIN           GPIO_Pin_9




/*------------------------------------------------TIM5����-------------------------------------------------------*/

#define            GENERAL_TIM5                   TIM5
#define            GENERAL_TIM5_CLK               RCC_APB1Periph_TIM5
#define            GENERAL_TIM_Period_Run         (20000-1)
#define            GENERAL_TIM_Prescaler_Run      (72-1)

// TIM5 ����Ƚ�ͨ��1
#define            GENERAL_TIM5_CH1_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM5_CH1_PORT          GPIOA
#define            GENERAL_TIM5_CH1_PIN           GPIO_Pin_0


/**************************��������********************************/

void GENERAL_TIM4_Init(void);
void S1riseup(void);
void S1down(void);
void S2open(void);
void S2close(void);
void S4leftright(uint16_t k,uint16_t a);
void S3updown(uint16_t j,uint16_t b);

#endif /*_TIM_H*/


