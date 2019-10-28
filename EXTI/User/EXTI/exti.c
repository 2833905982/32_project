#include "exti.h"

static void EXTI_NVIC_Config(void)
{
	//NVIC Ƕ���ж�����������������ṹ����� NVIC
	NVIC_InitTypeDef NVIC_InitStruct;			 
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	NVIC_InitStruct.NVIC_IRQChannel = EXTI0_IRQn;
	//���������ȼ�Ϊ 1
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	//���������ȼ�Ϊ 1
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStruct);
}

void EXTI_Key_Config(void)
{
	//����ṹ�������
	GPIO_InitTypeDef GPIO_InitStruct;													
	
	//��ʼ���ṹ�� EXTI
	EXTI_InitTypeDef EXTI_InitStruct;
	
	//�����ж����ȼ�
	
	EXTI_NVIC_Config();
	
	//��ʼ������ EXTI �� GPIO.
	RCC_APB2PeriphClockCmd(KEY1_INT_GPIO_CLK, ENABLE);							//rcc ��ʱ�ӣ�����APB2���ߡ�
	GPIO_InitStruct.GPIO_Pin = KEY1_INT_GPIO_PIN;										//����IO�ڣ�����PB�˿ڡ�
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;							//���������ʽ��Ϊ�������룬���ⲿ�ĵ�ѹ������
	GPIO_Init(KEY1_INT_GPIO_PORT, &GPIO_InitStruct);								//��IO�ڣ��ͽṹ�������ֵ��
	
	//��ʼ��EXTI
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource0);
	
	EXTI_InitStruct.EXTI_Line = EXTI_Line0;
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
	//�����ж���Ӧ����Ϊ������.
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
	EXTI_Init( &EXTI_InitStruct );
}



