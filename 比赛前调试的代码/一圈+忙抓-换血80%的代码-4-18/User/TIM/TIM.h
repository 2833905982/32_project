#ifndef _TIM_H
#define _TIM_H

#include "stm32f10x.h"

#define          ADVANCE_TIM                      TIM1
#define          ADVANCE_TIM_APBxClock_FUN        RCC_APB2PeriphClockCmd
#define          ADVANCE_TIM_CLK                  RCC_APB2Periph_TIM1

//PWM�źŵ�Ƶ�� F = TIM_CLK/{(ARR+1)*(PSC+1)}
#define          ADVANCE_TIM_PERIOD               (200-1)      //���� ,20ms
#define          ADVANCE_TIM_PSC            			(7200-1)      //�����˼�������һ�ε�ʱ��
#define          ADVANCE_TIM_PULSE          			0       //���Ĵ���ɸ���ռ�ձ�

#define          ADVANCE_TIM_IRQ        					TIM1_UP_IRQn
#define          ADVANCE_TIM_IRQHandler    				TIM1_UP_IRQHandler

//TIM1 ����Ƚ�ͨ��
#define      		 ADVANCE_TIM_CH1_GPIO_CLK          RCC_APB2Periph_GPIOA
#define          ADVANCE_TIM_CH1_PORT        			 GPIOA
#define        	 ADVANCE_TIM_CH1_PIN       				 GPIO_Pin_8

//TIM1 ����Ƚ�ͨ���Ļ���ͨ��CLK     		 
#define          ADVANCE_TIM_CH1N_GPIO_CLK         RCC_APB2Periph_GPIOB
#define					 ADVANCE_TIM_CH1N_PORT        		 GPIOB
#define      		 ADVANCE_TIM_CH1N_PIN      				 GPIO_Pin_13

//TIM1 ����Ƚ�ͨ����ɲ��ͨ��
#define          ADVANCE_TIM_BKIN_GPIO_CLK         RCC_APB2Periph_GPIOB
#define			     ADVANCE_TIM_BKIN_PORT     				 GPIOB
#define          ADVANCE_TIM_BKIN_PIN      				 GPIO_Pin_12

void TIM_Init(void);

#endif /*_TIM_H*/


