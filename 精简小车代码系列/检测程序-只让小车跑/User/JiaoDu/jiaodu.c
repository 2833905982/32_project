#include "jiaodu.h"
#include "systick.h"


void turn_left(u16 left1,u16 left2)
{
	TIM_SetCompare3(TIM3,left1);																			//���� BO�������ֵĿ���
	TIM_SetCompare4(TIM3,left2);																			//���� B1�������ֵĿ���
}

void turn_right(u16 tt)
{
	TIM_SetCompare3(TIM3,250);																			//���� BO�������ֵĿ���
	TIM_SetCompare4(TIM3,0);																			//���� B1�������ֵĿ���
	SysTick_Dwelay_us(tt);
}
void qian_jin(void)
{ 
	TIM_SetCompare3(TIM3,250);																			//���� BO�������ֵĿ���
	TIM_SetCompare4(TIM3,250);																			//���� B1�������ֵĿ���
}
void stop(void)
{
	TIM_SetCompare3(TIM3,0);																			//���� BO�������ֵĿ���
	TIM_SetCompare4(TIM3,0);																			//���� B1�������ֵĿ���
}



