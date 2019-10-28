#ifndef _BSP_ADVANCETIM8_H
#define _BSP_ADVANCETIM8_H

#include "stm32f10x.h"

/************�߼���ʱ��TIM�������壬ֻ��TIM1��TIM8************/
// ��ʹ�ò�ͬ�Ķ�ʱ����ʱ�򣬶�Ӧ��GPIO�ǲ�һ���ģ����Ҫע��
// ��������ʹ�ø߼����ƶ�ʱ��TIM1

#define            ADVANCE_TIM8                   TIM8
#define            ADVANCE_TIM8_APBxClock_FUN     RCC_APB2PeriphClockCmd
#define            ADVANCE_TIM8_CLK               RCC_APB2Periph_TIM8
// PWM �źŵ�Ƶ�� F = TIM_CLK/{(ARR+1)*(PSC+1)}
#define            ADVANCE_TIM8_PERIOD            (8-1)					//��������
#define            ADVANCE_TIM8_PSC               (9-1)					//������Ƶ����
#define            ADVANCE_TIM8_PULSE             4							//����ռ�ձ�

#define            ADVANCE_TIM8_IRQ               TIM1_UP_IRQn
#define            ADVANCE_TIM8_IRQHandler        TIM1_UP_IRQHandler

// TIM1 ����Ƚ�ͨ��
#define            ADVANCE_TIM8_CH1_GPIO_CLK      RCC_APB2Periph_GPIOC
#define            ADVANCE_TIM8_CH1_PORT          GPIOC
#define            ADVANCE_TIM8_CH1_PIN           GPIO_Pin_6

// TIM1 ����Ƚ�ͨ���Ļ���ͨ��
#define            ADVANCE_TIM8_CH1N_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            ADVANCE_TIM8_CH1N_PORT          GPIOA
#define            ADVANCE_TIM8_CH1N_PIN           GPIO_Pin_7

// TIM1 ����Ƚ�ͨ����ɲ��ͨ��
#define            ADVANCE_TIM8_BKIN_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            ADVANCE_TIM8_BKIN_PORT          GPIOB
#define            ADVANCE_TIM8_BKIN_PIN           GPIO_Pin_6

void ADVANCE_TIM8_Init(void);


#endif /* _BSP_ADVANCETIM_H */

