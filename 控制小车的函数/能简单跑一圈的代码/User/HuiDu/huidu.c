#include "huidu.h"

void huidu1 (void)
{
	GPIO_InitTypeDef    GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(HUI1_GPIO_CLK,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = HUI1_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_IN_FLOATING;
	GPIO_Init (HUI1_GPIO_PORT,&GPIO_InitStruct);	
}

void huidu2 (void)
{
	GPIO_InitTypeDef    GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(HUI2_GPIO_CLK,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = HUI2_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_IN_FLOATING;
	GPIO_Init (HUI2_GPIO_PORT,&GPIO_InitStruct);
}

void huidu3 (void)
{
	GPIO_InitTypeDef    GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(HUI3_GPIO_CLK,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = HUI3_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_IN_FLOATING;
	GPIO_Init (HUI3_GPIO_PORT,&GPIO_InitStruct);
}

void huidu4 (void)
{
	GPIO_InitTypeDef    GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(HUI4_GPIO_CLK,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = HUI4_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_IN_FLOATING;
	GPIO_Init (HUI4_GPIO_PORT,&GPIO_InitStruct);
}

void huidu5 (void)
{
	GPIO_InitTypeDef    GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(HUI5_GPIO_CLK,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = HUI5_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_IN_FLOATING;
	GPIO_Init (HUI5_GPIO_PORT,&GPIO_InitStruct);
}
void huidu6 (void)
{
	GPIO_InitTypeDef    GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(HUI6_GPIO_CLK,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = HUI6_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_IN_FLOATING;
	GPIO_Init (HUI6_GPIO_PORT,&GPIO_InitStruct);
}

void huidu7 (void)
{
	GPIO_InitTypeDef    GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(HUI7_GPIO_CLK,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = HUI7_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_IN_FLOATING;
	GPIO_Init (HUI7_GPIO_PORT,&GPIO_InitStruct);
}

int scan (GPIO_TypeDef *GPIOx,int GPIO_Pin)
{
	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == OFF)
	{
  		//if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == OFF);
			return OFF;
	}
		else
			return ON;
}

void huidu(void)
{
	huidu1();
	huidu2();
	huidu3();
	huidu4();
	huidu5();
	huidu6();
	huidu7();
}

