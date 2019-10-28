#include "jiaodu.h"
#include "systick.h"
#include "bsp-gpio.h"


void turn_left(u16 tt)
{
	GPIO_SetBits(Rwheel1_GPIO_PORT, Rwheel1_GPIO_PIN);							//������ת
	GPIO_ResetBits(Lwheel2_GPIO_PORT, Lwheel2_GPIO_PIN);						//������ת
	TIM_SetCompare3(TIM3,0);																				//���� BO�������ֵĿ���
	TIM_SetCompare4(TIM3,400);																			//���� B1�������ֵĿ���
//	SysTick_Dwelay_us(tt);
	delay_ms(tt);
}

void turn_right(u16 tt)
{
	GPIO_SetBits(Rwheel1_GPIO_PORT, Rwheel1_GPIO_PIN);							//������ת
	GPIO_ResetBits(Lwheel2_GPIO_PORT, Lwheel2_GPIO_PIN);						//������ת
	TIM_SetCompare3(TIM3,400);																			//���� BO�������ֵĿ���
	TIM_SetCompare4(TIM3,0);																				//���� B1�������ֵĿ���
	//SysTick_Dwelay_us(tt);
	delay_ms(tt);
}
void qian_jin(void)
{ 
	GPIO_SetBits(Rwheel1_GPIO_PORT, Rwheel1_GPIO_PIN);							//������ת
	GPIO_ResetBits(Lwheel2_GPIO_PORT, Lwheel2_GPIO_PIN);						//������ת	
	TIM_SetCompare3(TIM3,400);																			//���� BO�������ֵĿ���
	TIM_SetCompare4(TIM3,400);																			//���� B1�������ֵĿ���
}
void stop(void)
{
	TIM_SetCompare3(TIM3,0);																				//���� BO�������ֵĿ���
	TIM_SetCompare4(TIM3,0);																				//���� B1�������ֵĿ���
}
void back(void)
{
	GPIO_ResetBits(Rwheel1_GPIO_PORT, Rwheel1_GPIO_PIN);						//���ַ�ת
	GPIO_SetBits(Lwheel2_GPIO_PORT, Lwheel2_GPIO_PIN);							//���ַ�ת
	TIM_SetCompare3(TIM3,400);																			//���� BO�������ֵĿ���
	TIM_SetCompare4(TIM3,400);																			//���� B1�������ֵĿ���	
}
void left_back(u16 tt)
{
	GPIO_ResetBits(Rwheel1_GPIO_PORT, Rwheel1_GPIO_PIN);						//���ַ�ת
	GPIO_SetBits(Lwheel2_GPIO_PORT, Lwheel2_GPIO_PIN);							//���ַ�ת
	TIM_SetCompare3(TIM3,400);																			//���� BO�������ֵĿ���
	TIM_SetCompare4(TIM3,0);																				//���� B1�������ֵĿ���	
	delay_ms(tt);
}
void right_back(u16 tt)
{
	GPIO_ResetBits(Rwheel1_GPIO_PORT, Rwheel1_GPIO_PIN);						//���ַ�ת
	GPIO_SetBits(Lwheel2_GPIO_PORT, Lwheel2_GPIO_PIN);							//���ַ�ת
	TIM_SetCompare3(TIM3,0);																			//���� BO�������ֵĿ���
	TIM_SetCompare4(TIM3,400);																			//���� B1�������ֵĿ���		
	delay_ms(tt);
}


