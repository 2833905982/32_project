#ifndef _SYSTICK_H
#define _SYSTICK_H


#include "stm32f10x.h"
#include "core_cm3.h"


//void SysTick_Dwelay_us( uint32_t us );
//void SysTick_Dwelay_ms( uint32_t ms );

void SysTick_Init(void);				
void delay_us(__IO u32 nTime);			//��λus
#define delay_ms(x) delay_us(1000*x)	 //��λms
#define delay_s(x) delay_ms(1000*x)	 //��λms


#endif /* _SYSTICK */


