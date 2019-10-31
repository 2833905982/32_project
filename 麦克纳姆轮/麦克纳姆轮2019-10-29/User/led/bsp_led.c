#include "./led/bsp_led.h"


void LED1_GPIO_Config(void)
{
	GPIO_InitTypeDef  GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(LED1_GPIO_CLK, ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = LED1_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(LED1_GPIO_PORT, &GPIO_InitStruct);	
}

void LED2_GPIO_Config(void)
{
	GPIO_InitTypeDef  GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(LED2_GPIO_CLK, ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = LED2_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(LED2_GPIO_PORT, &GPIO_InitStruct);	
}

void LED3_GPIO_Config(void)
{
	GPIO_InitTypeDef  GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(LED3_GPIO_CLK, ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = LED3_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(LED3_GPIO_PORT, &GPIO_InitStruct);	
}

void LED4_GPIO_Config(void)
{
	GPIO_InitTypeDef  GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(LED4_GPIO_CLK, ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = LED4_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(LED4_GPIO_PORT, &GPIO_InitStruct);	
}

void LED5_GPIO_Config(void)
{
	GPIO_InitTypeDef  GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(LED5_GPIO_CLK, ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = LED5_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(LED5_GPIO_PORT, &GPIO_InitStruct);	
}

void LED6_GPIO_Config(void)
{
	GPIO_InitTypeDef  GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(LED6_GPIO_CLK, ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = LED6_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(LED6_GPIO_PORT, &GPIO_InitStruct);	
}

void LED7_GPIO_Config(void)
{
	GPIO_InitTypeDef  GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(LED7_GPIO_CLK, ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = LED7_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(LED7_GPIO_PORT, &GPIO_InitStruct);	
}

void LED8_GPIO_Config(void)
{
	GPIO_InitTypeDef  GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(LED8_GPIO_CLK, ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = LED8_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(LED8_GPIO_PORT, &GPIO_InitStruct);	
}

void LED_GPIO_Config(void)
{
	LED1_GPIO_Config();
	LED2_GPIO_Config();
	LED3_GPIO_Config();
	LED4_GPIO_Config();
	LED5_GPIO_Config();
	LED6_GPIO_Config();
	LED7_GPIO_Config();
	LED8_GPIO_Config();
}



