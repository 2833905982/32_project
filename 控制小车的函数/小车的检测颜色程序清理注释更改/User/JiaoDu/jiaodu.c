#include "jiaodu.h"
#include "systick.h"
#include "bsp-gpio.h"


void turn_left(u16 tt)
{
	TIM_SetCompare3(TIM3,0);																			//���� BO�������ֵĿ���
	TIM_SetCompare4(TIM3,400);																			//���� B1�������ֵĿ���
	delay_us(tt);
}

void turn_right(u16 tt)
{
	TIM_SetCompare3(TIM3,400);																			//���� BO�������ֵĿ���
	TIM_SetCompare4(TIM3,0);																			//���� B1�������ֵĿ���
	delay_us(tt);
}
void qian_jin(void)
{ 
	TIM_SetCompare3(TIM3,400);																			//���� BO�������ֵĿ���
	TIM_SetCompare4(TIM3,400);																			//���� B1�������ֵĿ���
}
void stop(void)
{
	TIM_SetCompare3(TIM3,0);																			//���� BO�������ֵĿ���
	TIM_SetCompare4(TIM3,0);																			//���� B1�������ֵĿ���
}
void houtui(void)
{
	GPIO_ResetBits(Rwheel1_GPIO_PORT, Rwheel1_GPIO_PIN);
	GPIO_SetBits(Lwheel2_GPIO_PORT, Lwheel2_GPIO_PIN);
}



