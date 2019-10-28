#ifndef __BSP_DELAY_H
#define __BSP_DELAY_H
#include "stm32f10x.h"
 

	 
void delay_init(void);
void delay_ms(u16 nms);
void delay_us(u32 nus);

#endif /*__BSP_DELAY_H*/





























