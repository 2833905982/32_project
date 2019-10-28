#include "move.h"



/*  轮子方向gpio定义  */
void wheel_configer(void)
{

	/*定义一个GPIO_InitTypeDef类型的结构体*/
		GPIO_InitTypeDef GPIO_InitStructure;

		/*开启LED相关的GPIO外设时钟*/
		RCC_APB2PeriphClockCmd( LUN_ZUO_GPIO_CLK, ENABLE);
		/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = LUN_ZUO_GPIO_PIN;	
		/*设置引脚模式为通用推挽输出*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
		/*设置引脚速率为50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
		/*调用库函数，初始化GPIO*/
		GPIO_Init(LUN_GPIO_PORT, &GPIO_InitStructure);	
		
		/*开启LED相关的GPIO外设时钟*/
		RCC_APB2PeriphClockCmd( LUN_YOU_GPIO_CLK, ENABLE);
		/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = LUN_YOU_GPIO_PIN;	
		/*调用库函数，初始化GPIO*/
		GPIO_Init(LUN_GPIO_PORT, &GPIO_InitStructure);	
			
}



//左轮
void Leftsudu(u16 left,u16 fangxiang)//第一个参数速度  第二个参数方向
{
	
	TIM_SetCompare3(TIM3,left);
	LUN_ZUO(fangxiang);
}

//右轮
void Rightsudu(u16 right,u16 fangxiang)//第一个参数速度  第二个参数方向
{

	TIM_SetCompare4(TIM3,right);
	LUN_YOU(fangxiang);
}

////控制两组电机
//void sudu(u16 left,u16 right,u16 Fangxiang1,u16 Fangxiang2)//前两个参数左右电机速度  后两个参数方向
//{
//	
//	TIM_SetCompare4(TIM4,left);
//	TIM_SetCompare3(TIM4,right);
//	LUN_ZUO(Fangxiang1);
//	LUN_YOU(Fangxiang2);
//}

void move_Init(void)
{
	void wheel_configer(void);
	void Leftsudu(u16 left,u16 fangxiang);
	void Rightsudu(u16 right,u16 fangxiang);
}
