#include "bsp_fangxiang.h" 


void LUN_GPIO_Config(void)
{		
		/*定义一个GPIO_InitTypeDef类型的结构体*/
		GPIO_InitTypeDef GPIO_InitStructure;

		/*开启LED相关的GPIO外设时钟*/
		RCC_APB2PeriphClockCmd( LUN1_GPIO_CLK | LUN2_GPIO_CLK | LUN3_GPIO_CLK | LUN4_GPIO_CLK | LUN5_GPIO_CLK | LUN6_GPIO_CLK | LUN7_GPIO_CLK | LUN8_GPIO_CLK, ENABLE);
		/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = LUN1_GPIO_PIN;	

		/*设置引脚模式为通用推挽输出*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

		/*设置引脚速率为50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

		/*调用库函数，初始化GPIO*/
		GPIO_Init(LUN1_GPIO_PORT, &GPIO_InitStructure);	
		
		/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = LUN2_GPIO_PIN;

		/*调用库函数，初始化GPIO*/
		GPIO_Init(LUN2_GPIO_PORT, &GPIO_InitStructure);
		
		/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = LUN3_GPIO_PIN;

		/*调用库函数，初始化GPIOF*/
		GPIO_Init(LUN3_GPIO_PORT, &GPIO_InitStructure);
		
		/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = LUN4_GPIO_PIN;

		/*调用库函数，初始化GPIOF*/
		GPIO_Init(LUN4_GPIO_PORT, &GPIO_InitStructure);
		
		/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = LUN5_GPIO_PIN;

		/*调用库函数，初始化GPIOF*/
		GPIO_Init(LUN5_GPIO_PORT, &GPIO_InitStructure);
		
		/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = LUN6_GPIO_PIN;

		/*调用库函数，初始化GPIOF*/
		GPIO_Init(LUN6_GPIO_PORT, &GPIO_InitStructure);
		
		/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = LUN7_GPIO_PIN;

		/*调用库函数，初始化GPIOF*/
		GPIO_Init(LUN7_GPIO_PORT, &GPIO_InitStructure);
		
		/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = LUN8_GPIO_PIN;

		/*调用库函数，初始化GPIOF*/
		GPIO_Init(LUN8_GPIO_PORT, &GPIO_InitStructure);


}









