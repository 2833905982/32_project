#include "jiaodu.h"
#include "systick.h"


void turn_left(u16 tt)
{
	TIM_SetCompare3(TIM3,0);																			//���� BO�������ֵĿ���
	TIM_SetCompare4(TIM3,400);																			//���� B1�������ֵĿ���
	SysTick_Dwelay_us(tt);
}

void turn_right(u16 tt)
{
	TIM_SetCompare3(TIM3,400);																			//���� BO�������ֵĿ���
	TIM_SetCompare4(TIM3,0);																			//���� B1�������ֵĿ���
	SysTick_Dwelay_us(tt);
}


