/**
  ******************************************************************************
  * @file    bsp_led.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   led应用函数接口
  ******************************************************************************
  * @attention
  *
  * 实验平台:秉火 F103-霸道 STM32 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */
  
#include "bsp_led.h"   

 /**
  * @brief  初始化控制LED的IO
  * @param  无
  * @retval 无
  */
void LED_GPIO_Config(void)/*LDE显示灯初始化*/
{		
		/*定义一个GPIO_InitTypeDef类型的结构体*/
		GPIO_InitTypeDef GPIO_InitStructure;

		/*开启LED相关的GPIO外设时钟*/
		RCC_APB2PeriphClockCmd( LED1_GPIO_CLK , ENABLE);
		/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = LED1_GPIO_PIN;	

		/*设置引脚模式为通用推挽输出*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

		/*设置引脚速率为50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

		/*调用库函数，初始化GPIO*/
		GPIO_Init(LED1_GPIO_PORT, &GPIO_InitStructure);	
	
	
	//KEY1配置
	
	/*开启LED相关的GPIO外设时钟*/
		RCC_APB2PeriphClockCmd( KEY1_GPIO_CLK , ENABLE);
		/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = KEY1_GPIO_PIN;	

		/*设置引脚模式为通用推挽输出*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;   

		/*调用库函数，初始化GPIO*/
		GPIO_Init(KEY1_GPIO_PORT, &GPIO_InitStructure);	
		
	//KEY2配置
	
	/*开启LED相关的GPIO外设时钟*/
		RCC_APB2PeriphClockCmd( KEY2_GPIO_CLK , ENABLE);
		/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = KEY2_GPIO_PIN;	

		/*设置引脚模式为通用推挽输出*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;   

		/*调用库函数，初始化GPIO*/
		GPIO_Init(KEY2_GPIO_PORT, &GPIO_InitStructure);	
		
		
}



void GPIO_shuzihuidu_Config(void)
{

	GPIO_InitTypeDef     GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(SHUZIHUIDU_GPIO_CLK_ABCD,ENABLE);
	//PA15灰度
	GPIO_InitStruct.GPIO_Pin  =  SHUZIHUIDU_GPIO_PIN15;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(SHUZIHUIDU_GPIO_PORT_A,&GPIO_InitStruct);
  //PC12灰度
	GPIO_InitStruct.GPIO_Pin  =  SHUZIHUIDU_GPIO_PIN12;
	GPIO_Init(SHUZIHUIDU_GPIO_PORT_C,&GPIO_InitStruct);
	//PD2灰度
	GPIO_InitStruct.GPIO_Pin  =  SHUZIHUIDU_GPIO_PIN2;
	GPIO_Init(SHUZIHUIDU_GPIO_PORT_D,&GPIO_InitStruct);
	//PB3灰度
	GPIO_InitStruct.GPIO_Pin  =  SHUZIHUIDU_GPIO_PIN3;
	GPIO_Init(SHUZIHUIDU_GPIO_PORT_B,&GPIO_InitStruct);
	//PB4灰度
	GPIO_InitStruct.GPIO_Pin  =  SHUZIHUIDU_GPIO_PIN4;
	GPIO_Init(SHUZIHUIDU_GPIO_PORT_B,&GPIO_InitStruct);
	//PB5灰度
	GPIO_InitStruct.GPIO_Pin  =  SHUZIHUIDU_GPIO_PIN5;
	GPIO_Init(SHUZIHUIDU_GPIO_PORT_B,&GPIO_InitStruct);
	//PB12灰度
	GPIO_InitStruct.GPIO_Pin  =  SHUZIHUIDU_GPIO_PIN12;
	GPIO_Init(SHUZIHUIDU_GPIO_PORT_B,&GPIO_InitStruct);
	//PB13灰度
	GPIO_InitStruct.GPIO_Pin  =  SHUZIHUIDU_GPIO_PIN13;
	GPIO_Init(SHUZIHUIDU_GPIO_PORT_B,&GPIO_InitStruct);
	//PB14灰度
	GPIO_InitStruct.GPIO_Pin  =  SHUZIHUIDU_GPIO_PIN14;
	GPIO_Init(SHUZIHUIDU_GPIO_PORT_B,&GPIO_InitStruct);
	//PB15灰度
	GPIO_InitStruct.GPIO_Pin  =  SHUZIHUIDU_GPIO_PIN15;
	GPIO_Init(SHUZIHUIDU_GPIO_PORT_B,&GPIO_InitStruct);
	//PC6灰度
	GPIO_InitStruct.GPIO_Pin  =  SHUZIHUIDU_GPIO_PIN6;
	GPIO_Init(SHUZIHUIDU_GPIO_PORT_C,&GPIO_InitStruct);
	//PC7灰度
	GPIO_InitStruct.GPIO_Pin  =  SHUZIHUIDU_GPIO_PIN7;
	GPIO_Init(SHUZIHUIDU_GPIO_PORT_C,&GPIO_InitStruct);
	//PC8灰度
	GPIO_InitStruct.GPIO_Pin  =  SHUZIHUIDU_GPIO_PIN8;
	GPIO_Init(SHUZIHUIDU_GPIO_PORT_C,&GPIO_InitStruct);
	//PC9灰度
	GPIO_InitStruct.GPIO_Pin  =  SHUZIHUIDU_GPIO_PIN9;
	GPIO_Init(SHUZIHUIDU_GPIO_PORT_C,&GPIO_InitStruct);
	//PA11灰度
	GPIO_InitStruct.GPIO_Pin  =  SHUZIHUIDU_GPIO_PIN11;
	GPIO_Init(SHUZIHUIDU_GPIO_PORT_A,&GPIO_InitStruct);
	//PA12灰度
	GPIO_InitStruct.GPIO_Pin  =  SHUZIHUIDU_GPIO_PIN12;
	GPIO_Init(SHUZIHUIDU_GPIO_PORT_A,&GPIO_InitStruct);
	//PB8灰度
	GPIO_InitStruct.GPIO_Pin  =  SHUZIHUIDU_GPIO_PIN8;
	GPIO_Init(SHUZIHUIDU_GPIO_PORT_B,&GPIO_InitStruct);
	//PB9灰度
	GPIO_InitStruct.GPIO_Pin  =  SHUZIHUIDU_GPIO_PIN9;
	GPIO_Init(SHUZIHUIDU_GPIO_PORT_B,&GPIO_InitStruct);
	
 }


uint8_t Key1_Scan(void)
{
	if((GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN12 )==0))
	{
		while((GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN12 )==0));
		return 0;
	}
	else return 1;
}

uint8_t Key2_Scan(void)
{
	if((GPIO_ReadInputDataBit(GPIOD,SHUZIHUIDU_GPIO_PIN2 )==0))
	{
		while((GPIO_ReadInputDataBit(GPIOD,SHUZIHUIDU_GPIO_PIN2 )==0));
		return 0;
	}
	else return 1;
}

/*********************************************END OF FILE**********************/
