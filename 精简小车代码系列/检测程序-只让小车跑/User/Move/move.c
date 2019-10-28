#include "move.h"



/*  ���ӷ���gpio����  */
void wheel_configer(void)
{

	/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
		GPIO_InitTypeDef GPIO_InitStructure;

		/*����LED��ص�GPIO����ʱ��*/
		RCC_APB2PeriphClockCmd( LUN_ZUO_GPIO_CLK, ENABLE);
		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = LUN_ZUO_GPIO_PIN;	
		/*��������ģʽΪͨ���������*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
		/*������������Ϊ50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
		/*���ÿ⺯������ʼ��GPIO*/
		GPIO_Init(LUN_GPIO_PORT, &GPIO_InitStructure);	
		
		/*����LED��ص�GPIO����ʱ��*/
		RCC_APB2PeriphClockCmd( LUN_YOU_GPIO_CLK, ENABLE);
		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = LUN_YOU_GPIO_PIN;	
		/*���ÿ⺯������ʼ��GPIO*/
		GPIO_Init(LUN_GPIO_PORT, &GPIO_InitStructure);	
			
}



//����
void Leftsudu(u16 left,u16 fangxiang)//��һ�������ٶ�  �ڶ�����������
{
	
	TIM_SetCompare3(TIM3,left);
	LUN_ZUO(fangxiang);
}

//����
void Rightsudu(u16 right,u16 fangxiang)//��һ�������ٶ�  �ڶ�����������
{

	TIM_SetCompare4(TIM3,right);
	LUN_YOU(fangxiang);
}

////����������
//void sudu(u16 left,u16 right,u16 Fangxiang1,u16 Fangxiang2)//ǰ�����������ҵ���ٶ�  ��������������
//{
//	
//	TIM_SetCompare4(TIM4,left);
//	TIM_SetCompare3(TIM4,right);
//	LUN_ZUO(Fangxiang1);
//	LUN_YOU(Fangxiang2);
//}

void move_Init(void)
{
	void wheel_configer(void);
	void Leftsudu(u16 left,u16 fangxiang);
	void Rightsudu(u16 right,u16 fangxiang);
}
