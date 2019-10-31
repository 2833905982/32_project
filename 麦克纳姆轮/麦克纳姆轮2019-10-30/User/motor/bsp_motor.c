#include "./led/bsp_led.h"
#include "./motor/bsp_motor.h"
#include "./GeneralTim4/bsp_GeneralTim4.h"

/********************车轮初始化******************************/
void lun_zuo1_GPIO_Config(void)
{
	GPIO_InitTypeDef  GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(LUN_ZUO_GPIO_CLK, ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = LUN_ZUO1_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(LUN_GPIO_PORT, &GPIO_InitStruct);	
}

void Lun_zuo2_GPIO_Config(void)
{
	GPIO_InitTypeDef  GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(LUN_ZUO_GPIO_CLK, ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = LUN_ZUO2_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(LUN_GPIO_PORT, &GPIO_InitStruct);	
}

void Lun_you1_GPIO_Config(void)
{
	GPIO_InitTypeDef  GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(LUN_YOU_GPIO_CLK, ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = LUN_YOU1_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(LUN_GPIO_PORT, &GPIO_InitStruct);	
}

void Lun_you2_GPIO_Config(void)
{
	GPIO_InitTypeDef  GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(LUN_YOU_GPIO_CLK, ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = LUN_YOU2_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(LUN_GPIO_PORT, &GPIO_InitStruct);	
}


void wheel_GPIO_Config(void)
{
	lun_zuo1_GPIO_Config();
	Lun_zuo2_GPIO_Config();
	Lun_you1_GPIO_Config();
	Lun_you2_GPIO_Config();
}

/*********************************电机驱动程序************************************/

void motor_qudong(u16 left,u16 right,u16 Fangxiang1,u16 Fangxiang2,u16 Fangxiang3,u16 Fangxiang4)
{
	TIM_SetCompare2(TIM4,left);
	TIM_SetCompare1(TIM4,right);
	LUN_ZUO1(Fangxiang1);
	LUN_ZUO2(Fangxiang2);
	LUN_YOU1(Fangxiang3);
	LUN_YOU2(Fangxiang4);
}

void go_stright(void)
{
	motor_qudong(7200,7200,0,0,1,1);
}

void go_back(void)
{
	motor_qudong(7200,7200,1,1,0,0);
}   

void turn_right(void)
{
	motor_qudong(7200,7200,0,0,0,0);
}

void turn_left(void)
{
	motor_qudong(7200,7200,1,1,1,1);	
}

void left_parall(void)
{
	motor_qudong(7200,7200,0,1,0,1);
}

void right_parall(void)
{
	motor_qudong(7200,7200,1,0,1,0);
}



