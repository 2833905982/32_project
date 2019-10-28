#include "jiaodu.h"
#include "systick.h"
#include "bsp-gpio.h"


void turn_left(u16 tt)
{
	GPIO_SetBits(Rwheel1_GPIO_PORT, Rwheel1_GPIO_PIN);							//右轮正转
	GPIO_ResetBits(Lwheel2_GPIO_PORT, Lwheel2_GPIO_PIN);						//左轮正转
	TIM_SetCompare3(TIM3,0);																				//调节 BO，即左轮的快慢
	TIM_SetCompare4(TIM3,400);																			//调节 B1，即右轮的快慢
//	SysTick_Dwelay_us(tt);
	delay_ms(tt);
}

void turn_right(u16 tt)
{
	GPIO_SetBits(Rwheel1_GPIO_PORT, Rwheel1_GPIO_PIN);							//右轮正转
	GPIO_ResetBits(Lwheel2_GPIO_PORT, Lwheel2_GPIO_PIN);						//左轮正转
	TIM_SetCompare3(TIM3,400);																			//调节 BO，即右轮的快慢
	TIM_SetCompare4(TIM3,0);																				//调节 B1，即左轮的快慢
	//SysTick_Dwelay_us(tt);
	delay_ms(tt);
}
void qian_jin(void)
{ 
	GPIO_SetBits(Rwheel1_GPIO_PORT, Rwheel1_GPIO_PIN);							//右轮正转
	GPIO_ResetBits(Lwheel2_GPIO_PORT, Lwheel2_GPIO_PIN);						//左轮正转	
	TIM_SetCompare3(TIM3,400);																			//调节 BO，即右轮的快慢
	TIM_SetCompare4(TIM3,400);																			//调节 B1，即左轮的快慢
}
void stop(void)
{
	TIM_SetCompare3(TIM3,0);																				//调节 BO，即右轮的快慢
	TIM_SetCompare4(TIM3,0);																				//调节 B1，即左轮的快慢
}
void back(void)
{
	GPIO_ResetBits(Rwheel1_GPIO_PORT, Rwheel1_GPIO_PIN);						//右轮反转
	GPIO_SetBits(Lwheel2_GPIO_PORT, Lwheel2_GPIO_PIN);							//左轮反转
	TIM_SetCompare3(TIM3,400);																			//调节 BO，即右轮的快慢
	TIM_SetCompare4(TIM3,400);																			//调节 B1，即左轮的快慢	
}
void left_back(u16 tt)
{
	GPIO_ResetBits(Rwheel1_GPIO_PORT, Rwheel1_GPIO_PIN);						//右轮反转
	GPIO_SetBits(Lwheel2_GPIO_PORT, Lwheel2_GPIO_PIN);							//左轮反转
	TIM_SetCompare3(TIM3,400);																			//调节 BO，即右轮的快慢
	TIM_SetCompare4(TIM3,0);																				//调节 B1，即左轮的快慢	
	delay_ms(tt);
}
void right_back(u16 tt)
{
	GPIO_ResetBits(Rwheel1_GPIO_PORT, Rwheel1_GPIO_PIN);						//右轮反转
	GPIO_SetBits(Lwheel2_GPIO_PORT, Lwheel2_GPIO_PIN);							//左轮反转
	TIM_SetCompare3(TIM3,0);																			//调节 BO，即右轮的快慢
	TIM_SetCompare4(TIM3,400);																			//调节 B1，即左轮的快慢		
	delay_ms(tt);
}


