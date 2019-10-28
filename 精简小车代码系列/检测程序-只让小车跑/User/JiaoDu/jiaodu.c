#include "jiaodu.h"
#include "systick.h"


void turn_left(u16 left1,u16 left2)
{
	TIM_SetCompare3(TIM3,left1);																			//调节 BO，即左轮的快慢
	TIM_SetCompare4(TIM3,left2);																			//调节 B1，即右轮的快慢
}

void turn_right(u16 tt)
{
	TIM_SetCompare3(TIM3,250);																			//调节 BO，即右轮的快慢
	TIM_SetCompare4(TIM3,0);																			//调节 B1，即左轮的快慢
	SysTick_Dwelay_us(tt);
}
void qian_jin(void)
{ 
	TIM_SetCompare3(TIM3,250);																			//调节 BO，即右轮的快慢
	TIM_SetCompare4(TIM3,250);																			//调节 B1，即左轮的快慢
}
void stop(void)
{
	TIM_SetCompare3(TIM3,0);																			//调节 BO，即右轮的快慢
	TIM_SetCompare4(TIM3,0);																			//调节 B1，即左轮的快慢
}



