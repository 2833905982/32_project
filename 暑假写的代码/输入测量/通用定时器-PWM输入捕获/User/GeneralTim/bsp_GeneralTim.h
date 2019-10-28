#ifndef __BSP_GENERALTIME_H
#define __BSP_GENERALTIME_H


#include "stm32f10x.h"


/************ͨ�ö�ʱ��TIM�������壬ֻ��TIM2��3��4��5************/
// ��ʹ�ò�ͬ�Ķ�ʱ����ʱ�򣬶�Ӧ��GPIO�ǲ�һ���ģ����Ҫע��
// ��������Ĭ��ʹ��TIM5

#define            GENERAL_TIM5                   TIM5
#define            GENERAL_TIM5_APBxClock_FUN     RCC_APB1PeriphClockCmd
#define            GENERAL_TIM5_CLK               RCC_APB1Periph_TIM5


// ���벶���ܲ��񵽵���С��Ƶ��Ϊ 72M/{ (ARR+1)*(PSC+1) }
#define            GENERAL_TIM5_PERIOD           (1000-1)
#define            GENERAL_TIM5_PSC              (72-1)


// �ж���غ궨��
//#define            GENERAL_TIM5_IT_CCx            TIM_IT_CC1
#define            GENERAL_TIM5_IRQ              	 TIM5_IRQn
#define            GENERAL_TIM5_IRQHandler         TIM5_IRQHandler

// TIM ���벶��ͨ��GPIO��غ궨��
#define            GENERAL_TIM5_CH1_GPIO_CLK       RCC_APB2Periph_GPIOA
#define            GENERAL_TIM5_CH1_PORT           GPIOA
#define            GENERAL_TIM5_CH1_PIN            GPIO_Pin_0

#define            GENERAL_TIM5_IC1PWM_CHANNEL     TIM_Channel_1
#define            GENERAL_TIM5_IC2PWM_CHANNEL     TIM_Channel_2



/**************************��������********************************/

void GENERAL_TIM_Init(void);


#endif	/* __BSP_GENERALTIME_H */


