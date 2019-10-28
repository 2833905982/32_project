/**
  ******************************************************************************
  * @file    bsp_led.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   ledӦ�ú����ӿ�
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:���� F103-�Ե� STM32 ������ 
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */
  
#include "bsp_led.h"   

 /**
  * @brief  ��ʼ������LED��IO
  * @param  ��
  * @retval ��
  */
void LED_GPIO_Config(void)/*LDE��ʾ�Ƴ�ʼ��*/
{		
		/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
		GPIO_InitTypeDef GPIO_InitStructure;

		/*����LED��ص�GPIO����ʱ��*/
		RCC_APB2PeriphClockCmd( LED1_GPIO_CLK , ENABLE);
		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = LED1_GPIO_PIN;	

		/*��������ģʽΪͨ���������*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

		/*������������Ϊ50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

		/*���ÿ⺯������ʼ��GPIO*/
		GPIO_Init(LED1_GPIO_PORT, &GPIO_InitStructure);	
	
	
	//KEY1����
	
	/*����LED��ص�GPIO����ʱ��*/
		RCC_APB2PeriphClockCmd( KEY1_GPIO_CLK , ENABLE);
		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = KEY1_GPIO_PIN;	

		/*��������ģʽΪͨ���������*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;   

		/*���ÿ⺯������ʼ��GPIO*/
		GPIO_Init(KEY1_GPIO_PORT, &GPIO_InitStructure);	
		
	//KEY2����
	
	/*����LED��ص�GPIO����ʱ��*/
		RCC_APB2PeriphClockCmd( KEY2_GPIO_CLK , ENABLE);
		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = KEY2_GPIO_PIN;	

		/*��������ģʽΪͨ���������*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;   

		/*���ÿ⺯������ʼ��GPIO*/
		GPIO_Init(KEY2_GPIO_PORT, &GPIO_InitStructure);	
		
		
}



void GPIO_shuzihuidu_Config(void)
{

	GPIO_InitTypeDef     GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(SHUZIHUIDU_GPIO_CLK_ABCD,ENABLE);
	//PA15�Ҷ�
	GPIO_InitStruct.GPIO_Pin  =  SHUZIHUIDU_GPIO_PIN15;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(SHUZIHUIDU_GPIO_PORT_A,&GPIO_InitStruct);
  //PC12�Ҷ�
	GPIO_InitStruct.GPIO_Pin  =  SHUZIHUIDU_GPIO_PIN12;
	GPIO_Init(SHUZIHUIDU_GPIO_PORT_C,&GPIO_InitStruct);
	//PD2�Ҷ�
	GPIO_InitStruct.GPIO_Pin  =  SHUZIHUIDU_GPIO_PIN2;
	GPIO_Init(SHUZIHUIDU_GPIO_PORT_D,&GPIO_InitStruct);
	//PB3�Ҷ�
	GPIO_InitStruct.GPIO_Pin  =  SHUZIHUIDU_GPIO_PIN3;
	GPIO_Init(SHUZIHUIDU_GPIO_PORT_B,&GPIO_InitStruct);
	//PB4�Ҷ�
	GPIO_InitStruct.GPIO_Pin  =  SHUZIHUIDU_GPIO_PIN4;
	GPIO_Init(SHUZIHUIDU_GPIO_PORT_B,&GPIO_InitStruct);
	//PB5�Ҷ�
	GPIO_InitStruct.GPIO_Pin  =  SHUZIHUIDU_GPIO_PIN5;
	GPIO_Init(SHUZIHUIDU_GPIO_PORT_B,&GPIO_InitStruct);
	//PB12�Ҷ�
	GPIO_InitStruct.GPIO_Pin  =  SHUZIHUIDU_GPIO_PIN12;
	GPIO_Init(SHUZIHUIDU_GPIO_PORT_B,&GPIO_InitStruct);
	//PB13�Ҷ�
	GPIO_InitStruct.GPIO_Pin  =  SHUZIHUIDU_GPIO_PIN13;
	GPIO_Init(SHUZIHUIDU_GPIO_PORT_B,&GPIO_InitStruct);
	//PB14�Ҷ�
	GPIO_InitStruct.GPIO_Pin  =  SHUZIHUIDU_GPIO_PIN14;
	GPIO_Init(SHUZIHUIDU_GPIO_PORT_B,&GPIO_InitStruct);
	//PB15�Ҷ�
	GPIO_InitStruct.GPIO_Pin  =  SHUZIHUIDU_GPIO_PIN15;
	GPIO_Init(SHUZIHUIDU_GPIO_PORT_B,&GPIO_InitStruct);
	//PC6�Ҷ�
	GPIO_InitStruct.GPIO_Pin  =  SHUZIHUIDU_GPIO_PIN6;
	GPIO_Init(SHUZIHUIDU_GPIO_PORT_C,&GPIO_InitStruct);
	//PC7�Ҷ�
	GPIO_InitStruct.GPIO_Pin  =  SHUZIHUIDU_GPIO_PIN7;
	GPIO_Init(SHUZIHUIDU_GPIO_PORT_C,&GPIO_InitStruct);
	//PC8�Ҷ�
	GPIO_InitStruct.GPIO_Pin  =  SHUZIHUIDU_GPIO_PIN8;
	GPIO_Init(SHUZIHUIDU_GPIO_PORT_C,&GPIO_InitStruct);
	//PC9�Ҷ�
	GPIO_InitStruct.GPIO_Pin  =  SHUZIHUIDU_GPIO_PIN9;
	GPIO_Init(SHUZIHUIDU_GPIO_PORT_C,&GPIO_InitStruct);
	//PA11�Ҷ�
	GPIO_InitStruct.GPIO_Pin  =  SHUZIHUIDU_GPIO_PIN11;
	GPIO_Init(SHUZIHUIDU_GPIO_PORT_A,&GPIO_InitStruct);
	//PA12�Ҷ�
	GPIO_InitStruct.GPIO_Pin  =  SHUZIHUIDU_GPIO_PIN12;
	GPIO_Init(SHUZIHUIDU_GPIO_PORT_A,&GPIO_InitStruct);
	//PB8�Ҷ�
	GPIO_InitStruct.GPIO_Pin  =  SHUZIHUIDU_GPIO_PIN8;
	GPIO_Init(SHUZIHUIDU_GPIO_PORT_B,&GPIO_InitStruct);
	//PB9�Ҷ�
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
