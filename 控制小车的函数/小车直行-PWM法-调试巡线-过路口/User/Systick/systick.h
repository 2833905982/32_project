#ifndef _SYSTICK_H
#define _SYSTICK_H


#include "stm32f10x.h"
#include "core_cm3.h"


void SysTick_Dwelay_us( uint32_t us );
void SysTick_Dwelay_ms( uint32_t ms );

#endif /* _SYSTICK */


