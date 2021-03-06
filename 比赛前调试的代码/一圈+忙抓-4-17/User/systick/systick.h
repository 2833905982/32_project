
#ifndef __SYSTICK_H
#define __SYSTICK_H

#include "stm32f10x.h"

void SysTick_Init(void);				
void delay_us(__IO u32 nTime);													//单位us
#define delay_ms(x) delay_us(1000*x)										//单位ms
#define delay_s(x) delay_ms(1000*x)										 //单位s

#endif /* __SYSTICK_H */

