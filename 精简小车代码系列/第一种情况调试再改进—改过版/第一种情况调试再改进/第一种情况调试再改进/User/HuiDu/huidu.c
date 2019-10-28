//#include "huidu.h"

///***************** �Ҷ�GPIO��ʼ�� **********************************/

////�Ҷ�1
//void huidu1 (void)
//{
//	GPIO_InitTypeDef    GPIO_InitStruct;
//	
//	RCC_APB2PeriphClockCmd(HUI1_GPIO_CLK,ENABLE);
//	
//	GPIO_InitStruct.GPIO_Pin = HUI1_GPIO_PIN;
//	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_IN_FLOATING;
//	GPIO_Init (HUI1_GPIO_PORT,&GPIO_InitStruct);	
//}

////�Ҷ�2
//void huidu2 (void)
//{
//	GPIO_InitTypeDef    GPIO_InitStruct;
//	
//	RCC_APB2PeriphClockCmd(HUI1_GPIO_CLK,ENABLE);
//	
//	GPIO_InitStruct.GPIO_Pin = HUI1_GPIO_PIN;
//	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_IN_FLOATING;
//	GPIO_Init (HUI1_GPIO_PORT,&GPIO_InitStruct);	
//}

////�Ҷ�3
//void huidu3 (void)
//{
//	GPIO_InitTypeDef    GPIO_InitStruct;
//	
//	RCC_APB2PeriphClockCmd(HUI2_GPIO_CLK,ENABLE);
//	
//	GPIO_InitStruct.GPIO_Pin = HUI2_GPIO_PIN;
//	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_IN_FLOATING;
//	GPIO_Init (HUI2_GPIO_PORT,&GPIO_InitStruct);
//}

////�Ҷ�4
//void huidu4 (void)
//{
//	GPIO_InitTypeDef    GPIO_InitStruct;
//	
//	RCC_APB2PeriphClockCmd(HUI3_GPIO_CLK,ENABLE);
//	
//	GPIO_InitStruct.GPIO_Pin = HUI3_GPIO_PIN;
//	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_IN_FLOATING;
//	GPIO_Init (HUI3_GPIO_PORT,&GPIO_InitStruct);
//}

////�Ҷ�5
//void huidu5 (void)
//{
//	GPIO_InitTypeDef    GPIO_InitStruct;
//	
//	RCC_APB2PeriphClockCmd(HUI4_GPIO_CLK,ENABLE);
//	
//	GPIO_InitStruct.GPIO_Pin = HUI4_GPIO_PIN;
//	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_IN_FLOATING;
//	GPIO_Init (HUI4_GPIO_PORT,&GPIO_InitStruct);
//}

////�Ҷ�6
//void huidu6 (void)
//{
//	GPIO_InitTypeDef    GPIO_InitStruct;
//	
//	RCC_APB2PeriphClockCmd(HUI5_GPIO_CLK,ENABLE);
//	
//	GPIO_InitStruct.GPIO_Pin = HUI5_GPIO_PIN;
//	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_IN_FLOATING;
//	GPIO_Init (HUI5_GPIO_PORT,&GPIO_InitStruct);	
//}

////�Ҷ�7
//void huidu7 (void)
//{
//	GPIO_InitTypeDef    GPIO_InitStruct;
//	
//	RCC_APB2PeriphClockCmd(HUI6_GPIO_CLK,ENABLE);
//	
//	GPIO_InitStruct.GPIO_Pin = HUI6_GPIO_PIN;
//	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_IN_FLOATING;
//	GPIO_Init (HUI6_GPIO_PORT,&GPIO_InitStruct);	
//}

////�Ҷ�8
//void huidu8 (void)
//{
//	GPIO_InitTypeDef    GPIO_InitStruct;
//	
//	RCC_APB2PeriphClockCmd(HUI7_GPIO_CLK,ENABLE);
//	
//	GPIO_InitStruct.GPIO_Pin = HUI7_GPIO_PIN;
//	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_IN_FLOATING;
//	GPIO_Init (HUI7_GPIO_PORT,&GPIO_InitStruct);	
//}

////�Ҷ�9
//void huidu9 (void)
//{
//	GPIO_InitTypeDef    GPIO_InitStruct;
//	
//	RCC_APB2PeriphClockCmd(HUI8_GPIO_CLK,ENABLE);
//	
//	GPIO_InitStruct.GPIO_Pin = HUI8_GPIO_PIN;
//	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_IN_FLOATING;
//	GPIO_Init (HUI8_GPIO_PORT,&GPIO_InitStruct);	
//}

////�Ҷ�10
//void huidu10 (void)
//{
//	GPIO_InitTypeDef    GPIO_InitStruct;
//	
//	RCC_APB2PeriphClockCmd(HUI9_GPIO_CLK,ENABLE);
//	
//	GPIO_InitStruct.GPIO_Pin = HUI9_GPIO_PIN;
//	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_IN_FLOATING;
//	GPIO_Init (HUI9_GPIO_PORT,&GPIO_InitStruct);	
//}

///*********************** END ******************************/

//int scan (GPIO_TypeDef *GPIOx,int GPIO_Pin)
//{
//	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == OFF)
//	{
//  		//if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == OFF);
//			return OFF;
//	}
//		else
//			return ON;
//}

//void huidu(void)
//{
//	huidu1();
//	huidu2();
//	huidu3();
//	huidu4();
//	huidu5();
//	huidu6();
//	huidu7();
//	huidu8();
//	huidu9();
//	huidu10();
//}

#include "huidu.h"

void hui1 (void)
{
	GPIO_InitTypeDef    GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(HUI1_GPIO_CLK,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = HUI1_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_IN_FLOATING;
	GPIO_Init (HUI1_GPIO_PORT,&GPIO_InitStruct);	
}

void hui2 (void)
{
	GPIO_InitTypeDef    GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(HUI2_GPIO_CLK,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = HUI2_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_IN_FLOATING;
	GPIO_Init (HUI2_GPIO_PORT,&GPIO_InitStruct);
}

void hui3 (void)
{
	GPIO_InitTypeDef    GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(HUI3_GPIO_CLK,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = HUI3_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_IN_FLOATING;
	GPIO_Init (HUI3_GPIO_PORT,&GPIO_InitStruct);
}

void hui4 (void)
{
	GPIO_InitTypeDef    GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(HUI4_GPIO_CLK,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = HUI4_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_IN_FLOATING;
	GPIO_Init (HUI4_GPIO_PORT,&GPIO_InitStruct);	
}

void hui5 (void)
{
	GPIO_InitTypeDef    GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(HUI5_GPIO_CLK,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = HUI5_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_IN_FLOATING;
	GPIO_Init (HUI5_GPIO_PORT,&GPIO_InitStruct);
}

void hui6 (void)
{
	GPIO_InitTypeDef    GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(HUI6_GPIO_CLK,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = HUI6_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_IN_FLOATING;
	GPIO_Init (HUI6_GPIO_PORT,&GPIO_InitStruct);
}
void hui7 (void)
{
	GPIO_InitTypeDef    GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(HUI7_GPIO_CLK,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = HUI7_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_IN_FLOATING;
	GPIO_Init (HUI7_GPIO_PORT,&GPIO_InitStruct);
}

void hui8 (void)
{
	GPIO_InitTypeDef    GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(HUI8_GPIO_CLK,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = HUI8_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_IN_FLOATING;
	GPIO_Init (HUI8_GPIO_PORT,&GPIO_InitStruct);
}
void hui9 (void)
{
	GPIO_InitTypeDef    GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(HUI9_GPIO_CLK,ENABLE);    
	
	GPIO_InitStruct.GPIO_Pin = HUI9_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_IN_FLOATING;
	GPIO_Init (HUI9_GPIO_PORT,&GPIO_InitStruct);
}
void hui10 (void)
{
	GPIO_InitTypeDef    GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(HUI10_GPIO_CLK,ENABLE);    
	
	GPIO_InitStruct.GPIO_Pin = HUI10_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_IN_FLOATING;
	GPIO_Init (HUI10_GPIO_PORT,&GPIO_InitStruct);
}

void huiP1 (void)
{
	GPIO_InitTypeDef    GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(HUIP1_GPIO_CLK,ENABLE);    
	
	GPIO_InitStruct.GPIO_Pin = HUIP1_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_IN_FLOATING;
	GPIO_Init (HUIP1_GPIO_PORT,&GPIO_InitStruct);
}
void huiP2 (void)
{
	GPIO_InitTypeDef    GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(HUIP2_GPIO_CLK,ENABLE);    
	
	GPIO_InitStruct.GPIO_Pin = HUIP2_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_IN_FLOATING;
	GPIO_Init (HUIP2_GPIO_PORT,&GPIO_InitStruct);
}
//void hui12 (void)
//{
//	GPIO_InitTypeDef    GPIO_InitStruct;
//	
//	RCC_APB2PeriphClockCmd(HUI6_GPIO_CLK,ENABLE);    
//	
//	GPIO_InitStruct.GPIO_Pin = HUI6_GPIO_PIN;
//	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_IN_FLOATING;
//	GPIO_Init (HUI6_GPIO_PORT,&GPIO_InitStruct);
//}

//void hui (void)
//{
//	GPIO_InitTypeDef    GPIO_InitStruct;
//	
//	RCC_APB2PeriphClockCmd(HUICZ_GPIO_CLK,ENABLE);
//	
//	GPIO_InitStruct.GPIO_Pin = HUICZ_GPIO_PIN;
//	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_IN_FLOATING;
//	GPIO_Init (HUICZ_GPIO_PORT,&GPIO_InitStruct);	
//}

//void huicy (void)
//{
//	GPIO_InitTypeDef    GPIO_InitStruct;
//	
//	RCC_APB2PeriphClockCmd(HUICY_GPIO_CLK,ENABLE);
//	
//	GPIO_InitStruct.GPIO_Pin = HUICY_GPIO_PIN;
//	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_IN_FLOATING;
//	GPIO_Init (HUICY_GPIO_PORT,&GPIO_InitStruct);
//}


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
	hui1();
	hui2();
	hui3();
	hui4();
	hui5();
	hui6();
	hui7();
	hui8();
	hui9();
	hui10();
	huiP1();
	huiP2();
}

