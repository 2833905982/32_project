#include "bsp_led.h"

/************4个灯*********************/
void led (void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(LED1_GPIO_CLK | LED2_GPIO_CLK | LED3_GPIO_CLK | LED4_GPIO_CLK | LED5_GPIO_CLK, ENABLE);
	
	/***************第一个灯***********************/
	GPIO_InitStruct.GPIO_Pin = LED1_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LED1_GPIO_PORT, &GPIO_InitStruct);
	
	/***************第二个灯***********************/
	GPIO_InitStruct.GPIO_Pin = LED2_GPIO_PIN;
	GPIO_Init(LED2_GPIO_PORT, &GPIO_InitStruct);
	
	/***************第三个灯***********************/
	GPIO_InitStruct.GPIO_Pin = LED3_GPIO_PIN;
	GPIO_Init(LED3_GPIO_PORT, &GPIO_InitStruct);
	
	/***************第四个灯***********************/
	GPIO_InitStruct.GPIO_Pin = LED4_GPIO_PIN;
	GPIO_Init(LED4_GPIO_PORT, &GPIO_InitStruct);
	
	/***************第五个灯***********************/
	GPIO_InitStruct.GPIO_Pin = LED5_GPIO_PIN;
	GPIO_Init(LED5_GPIO_PORT, &GPIO_InitStruct);
	
	
}

