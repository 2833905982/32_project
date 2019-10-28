#include "jiaodu.h"
#include "systick.h"


void turn_left(u16 tt)
{
	TIM_SetCompare3(TIM3,0);																			//调节 BO，即左轮的快慢
	TIM_SetCompare4(TIM3,400);																			//调节 B1，即右轮的快慢
	SysTick_Dwelay_us(tt);
}

void turn_right(u16 tt)
{
	TIM_SetCompare3(TIM3,400);																			//调节 BO，即右轮的快慢
	TIM_SetCompare4(TIM3,0);																			//调节 B1，即左轮的快慢
	SysTick_Dwelay_us(tt);
}


