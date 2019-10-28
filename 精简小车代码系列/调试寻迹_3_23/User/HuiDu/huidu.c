#include "huidu.h"

/***************** 子業GPIO兜兵晒 **********************************/

//子業1
void huidu1 (void)
{
	GPIO_InitTypeDef    GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(HUI1_GPIO_CLK,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = HUI1_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_IN_FLOATING;
	GPIO_Init (HUI1_GPIO_PORT,&GPIO_InitStruct);	
}

//子業2
void huidu2 (void)
{
	GPIO_InitTypeDef    GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(HUI2_GPIO_CLK,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = HUI2_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_IN_FLOATING;
	GPIO_Init (HUI2_GPIO_PORT,&GPIO_InitStruct);	
}

//子業3
void huidu3 (void)
{
	GPIO_InitTypeDef    GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(HUI3_GPIO_CLK,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = HUI3_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_IN_FLOATING;
	GPIO_Init (HUI3_GPIO_PORT,&GPIO_InitStruct);
}

//子業4
void huidu4 (void)
{
	GPIO_InitTypeDef    GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(HUI4_GPIO_CLK,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = HUI4_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_IN_FLOATING;
	GPIO_Init (HUI4_GPIO_PORT,&GPIO_InitStruct);
}

//子業5
void huidu5 (void)
{
	GPIO_InitTypeDef    GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(HUI5_GPIO_CLK,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = HUI5_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_IN_FLOATING;
	GPIO_Init (HUI5_GPIO_PORT,&GPIO_InitStruct);
}

//子業6
void huidu6 (void)
{
	GPIO_InitTypeDef    GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(HUI6_GPIO_CLK,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = HUI6_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_IN_FLOATING;
	GPIO_Init (HUI6_GPIO_PORT,&GPIO_InitStruct);	
}

//子業7
void huidu7 (void)
{
	GPIO_InitTypeDef    GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(HUI7_GPIO_CLK,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = HUI7_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_IN_FLOATING;
	GPIO_Init (HUI7_GPIO_PORT,&GPIO_InitStruct);	
}

//子業8
void huidu8 (void)
{
	GPIO_InitTypeDef    GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(HUI8_GPIO_CLK,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = HUI8_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_IN_FLOATING;
	GPIO_Init (HUI8_GPIO_PORT,&GPIO_InitStruct);	
}

//子業9
void huidu9 (void)
{
	GPIO_InitTypeDef    GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(HUI9_GPIO_CLK,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = HUI9_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_IN_FLOATING;
	GPIO_Init (HUI9_GPIO_PORT,&GPIO_InitStruct);	
}

//子業10
void huidu10 (void)
{
	GPIO_InitTypeDef    GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(HUI10_GPIO_CLK,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = HUI10_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_IN_FLOATING;
	GPIO_Init (HUI10_GPIO_PORT,&GPIO_InitStruct);	
}
//子業11
void huidu11 (void)
{
	GPIO_InitTypeDef    GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(HUI11_GPIO_CLK,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = HUI11_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_IN_FLOATING;
	GPIO_Init (HUI11_GPIO_PORT,&GPIO_InitStruct);	
}
//子業12
void huidu12 (void)
{
	GPIO_InitTypeDef    GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(HUI12_GPIO_CLK,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = HUI12_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_IN_FLOATING;
	GPIO_Init (HUI12_GPIO_PORT,&GPIO_InitStruct);	
}
//子業13
void huidu13 (void)
{
	GPIO_InitTypeDef    GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(HUI13_GPIO_CLK,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = HUI13_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_IN_FLOATING;
	GPIO_Init (HUI13_GPIO_PORT,&GPIO_InitStruct);	
}
//子業14
void huidu14 (void)
{
	GPIO_InitTypeDef    GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(HUI14_GPIO_CLK,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = HUI14_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_IN_FLOATING;
	GPIO_Init (HUI14_GPIO_PORT,&GPIO_InitStruct);	
}

/*********************** END ******************************/

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
	huidu8();
	huidu9();
	huidu10();
	huidu11();
	huidu12();
	huidu13();
	huidu14();
}

