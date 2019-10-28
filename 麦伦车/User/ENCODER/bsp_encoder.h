#ifndef __BSP_ENCODER_H
#define __BSP_ENCODER_H
	 

#include "stm32f10x.h" 
#define ENCODER_TIM_PERIOD (u16)(65535)   //���ɴ���65535 ��ΪF103�Ķ�ʱ����16λ�ġ�
void Encoder_Init_TIM1(void);
//void Encoder_Init_TIM2(void);
//void Encoder_Init_TIM4(void);
void Encoder_Init_TIM8(void);
int Read_Encoder(u8 TIMX);
//void TIM4_IRQHandler(void);
//void TIM2_IRQHandler(void);
void TIM1_IRQHandler(void);
void TIM8_IRQHandler(void);

#endif /*__BSP_ENCODER_H*/
