#include "bsp_fangxiang.h" 


void LUN_GPIO_Config(void)
{		
		/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
		GPIO_InitTypeDef GPIO_InitStructure;

		/*����LED��ص�GPIO����ʱ��*/
		RCC_APB2PeriphClockCmd( LUN1_GPIO_CLK | LUN2_GPIO_CLK | LUN3_GPIO_CLK | LUN4_GPIO_CLK | LUN5_GPIO_CLK | LUN6_GPIO_CLK | LUN7_GPIO_CLK | LUN8_GPIO_CLK, ENABLE);
		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = LUN1_GPIO_PIN;	

		/*��������ģʽΪͨ���������*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

		/*������������Ϊ50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

		/*���ÿ⺯������ʼ��GPIO*/
		GPIO_Init(LUN1_GPIO_PORT, &GPIO_InitStructure);	
		
		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = LUN2_GPIO_PIN;

		/*���ÿ⺯������ʼ��GPIO*/
		GPIO_Init(LUN2_GPIO_PORT, &GPIO_InitStructure);
		
		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = LUN3_GPIO_PIN;

		/*���ÿ⺯������ʼ��GPIOF*/
		GPIO_Init(LUN3_GPIO_PORT, &GPIO_InitStructure);
		
		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = LUN4_GPIO_PIN;

		/*���ÿ⺯������ʼ��GPIOF*/
		GPIO_Init(LUN4_GPIO_PORT, &GPIO_InitStructure);
		
		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = LUN5_GPIO_PIN;

		/*���ÿ⺯������ʼ��GPIOF*/
		GPIO_Init(LUN5_GPIO_PORT, &GPIO_InitStructure);
		
		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = LUN6_GPIO_PIN;

		/*���ÿ⺯������ʼ��GPIOF*/
		GPIO_Init(LUN6_GPIO_PORT, &GPIO_InitStructure);
		
		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = LUN7_GPIO_PIN;

		/*���ÿ⺯������ʼ��GPIOF*/
		GPIO_Init(LUN7_GPIO_PORT, &GPIO_InitStructure);
		
		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = LUN8_GPIO_PIN;

		/*���ÿ⺯������ʼ��GPIOF*/
		GPIO_Init(LUN8_GPIO_PORT, &GPIO_InitStructure);


}









