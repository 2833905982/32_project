#ifndef _TIM_H
#define _TIM_H

#include "stm32f10x.h"

#define          ADVANCE_TIM                      TIM1
#define          ADVANCE_TIM_APBxClock_FUN        RCC_APB2PeriphClockCmd
#define          ADVANCE_TIM_CLK                  RCC_APB2Periph_TIM1

//PWM�źŵ�Ƶ�� F = TIM_CLK/{(ARR+1)*(PSC+1)}
#define          ADVANCE_TIM_PERIOD               (20000-1)       //���� ,20ms
#define          ADVANCE_TIM_PSC            			(72-1)      //�����˼�������һ�ε�ʱ��
#define          ADVANCE_TIM_PULSE          			0             //���Ĵ���ɸ���ռ�ձ�

#define          ADVANCE_TIM_IRQ        					TIM1_UP_IRQn
#define          ADVANCE_TIM_IRQHandler    				TIM1_UP_IRQHandler

//TIM1 ����Ƚ�ͨ��
#define      		 ADVANCE_TIM_CH1_GPIO_CLK          RCC_APB2Periph_GPIOA
#define          ADVANCE_TIM_CH1_PORT        			 GPIOA
#define        	 ADVANCE_TIM_CH1_PIN       				 GPIO_Pin_8

//TIM2 ����Ƚ�ͨ��
#define      		 ADVANCE_TIM_CH2_GPIO_CLK          RCC_APB2Periph_GPIOA
#define          ADVANCE_TIM_CH2_PORT        			 GPIOA
#define        	 ADVANCE_TIM_CH2_PIN       				 GPIO_Pin_9


//TIM3 ����Ƚ�ͨ��
#define      		 ADVANCE_TIM_CH3_GPIO_CLK          RCC_APB2Periph_GPIOA
#define          ADVANCE_TIM_CH3_PORT        			 GPIOA
#define        	 ADVANCE_TIM_CH3_PIN       				 GPIO_Pin_10


//TIM4 ����Ƚ�ͨ��
#define      		 ADVANCE_TIM_CH4_GPIO_CLK          RCC_APB2Periph_GPIOA
#define          ADVANCE_TIM_CH4_PORT        			 GPIOA
#define        	 ADVANCE_TIM_CH4_PIN       				 GPIO_Pin_11



void TIM_Init(void);

#endif /*_TIM_H*/


