#include "jiaodu.h"
#include "systick.h"
#include "bsp-gpio.h"


void turn_left(u16 tt)
{
	TIM_SetCompare3(TIM3,0);																			//调节 BO，即左轮的快慢
	TIM_SetCompare4(TIM3,400);																			//调节 B1，即右轮的快慢
	delay_us(tt);
}

void turn_right(u16 tt)
{
	TIM_SetCompare3(TIM3,400);																			//调节 BO，即右轮的快慢
	TIM_SetCompare4(TIM3,0);																			//调节 B1，即左轮的快慢
	delay_us(tt);
}
void qian_jin(void)
{ 
	TIM_SetCompare3(TIM3,400);																			//调节 BO，即右轮的快慢
	TIM_SetCompare4(TIM3,400);																			//调节 B1，即左轮的快慢
}
void stop(void)
{
	TIM_SetCompare3(TIM3,0);																			//调节 BO，即右轮的快慢
	TIM_SetCompare4(TIM3,0);																			//调节 B1，即左轮的快慢
}
void houtui(void)
{
	GPIO_ResetBits(Rwheel1_GPIO_PORT, Rwheel1_GPIO_PIN);
	GPIO_SetBits(Lwheel2_GPIO_PORT, Lwheel2_GPIO_PIN);
}



