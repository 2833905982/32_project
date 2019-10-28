#include "exti.h"

static void EXTI_NVIC_Config(void)
{
	//NVIC 嵌套中断向量控制器，定义结构体变量 NVIC
	NVIC_InitTypeDef NVIC_InitStruct;			 
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	NVIC_InitStruct.NVIC_IRQChannel = EXTI0_IRQn;
	//配置主优先级为 1
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	//配置子优先级为 1
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStruct);
}

void EXTI_Key_Config(void)
{
	//定义结构体变量。
	GPIO_InitTypeDef GPIO_InitStruct;													
	
	//初始化结构体 EXTI
	EXTI_InitTypeDef EXTI_InitStruct;
	
	//配置中断优先级
	
	EXTI_NVIC_Config();
	
	//初始化连接 EXTI 的 GPIO.
	RCC_APB2PeriphClockCmd(KEY1_INT_GPIO_CLK, ENABLE);							//rcc 打开时钟，设置APB2总线。
	GPIO_InitStruct.GPIO_Pin = KEY1_INT_GPIO_PIN;										//定义IO口，设置PB端口。
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;							//设置输出方式，为浮空输入，有外部的电压决定。
	GPIO_Init(KEY1_INT_GPIO_PORT, &GPIO_InitStruct);								//传IO口，和结构体变量的值。
	
	//初始化EXTI
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource0);
	
	EXTI_InitStruct.EXTI_Line = EXTI_Line0;
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
	//配置中断响应条件为上升沿.
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
	EXTI_Init( &EXTI_InitStruct );
}



