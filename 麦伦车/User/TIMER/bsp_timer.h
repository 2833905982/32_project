#ifndef __BSP_TIMER_H
#define __BSP_TIMER_H
	 
#include "stm32f10x.h"

void TIM6_Int_Init(u16 arr,u16 psc);
void TIM7_Int_Init(u16 arr,u16 psc);
void Read_Distane(void);
void TIM6_IRQHandler(void);
void TIM7_IRQHandler(void);

#endif /*__BSP_TIMER_H*/
