#include "gpio.h"


void motor1_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;													//�������ʱ�����
	
	RCC_APB2PeriphClockCmd(motor1_GPIO_CLK, ENABLE);							//rcc ��ʱ�ӣ�����APB2���ߡ�
	GPIO_InitStruct.GPIO_Pin = motor1_GPIO_PIN;									//����IO�ڣ�����PB�˿ڡ�
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;							//���������ʽ��Ϊ�������
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;						//�����ٶ�Ϊ50MHZ.
	GPIO_Init(motor1_GPIO_PORT, &GPIO_InitStruct);								//��IO�ڣ��ͽṹ�������ֵ��
}

void motor2_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;													//�������ʱ�����
	
	RCC_APB2PeriphClockCmd(motor2_GPIO_CLK, ENABLE);							//rcc ��ʱ�ӣ�����APB2���ߡ�
	GPIO_InitStruct.GPIO_Pin = motor2_GPIO_PIN;									//����IO�ڣ�����PB�˿ڡ�
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;							//���������ʽ��Ϊ�������
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;						//�����ٶ�Ϊ50MHZ.
	GPIO_Init(motor2_GPIO_PORT, &GPIO_InitStruct);								//��IO�ڣ��ͽṹ�������ֵ��
}

void motor3_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;													//�������ʱ�����
	
	RCC_APB2PeriphClockCmd(motor3_GPIO_CLK, ENABLE);							//rcc ��ʱ�ӣ�����APB2���ߡ�
	GPIO_InitStruct.GPIO_Pin = motor3_GPIO_PIN;									//����IO�ڣ�����PB�˿ڡ�
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;							//���������ʽ��Ϊ�������
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;						//�����ٶ�Ϊ50MHZ.
	GPIO_Init(motor3_GPIO_PORT, &GPIO_InitStruct);								//��IO�ڣ��ͽṹ�������ֵ��
}

void motor4_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;													//�������ʱ�����
	
	RCC_APB2PeriphClockCmd(motor4_GPIO_CLK, ENABLE);							//rcc ��ʱ�ӣ�����APB2���ߡ�
	GPIO_InitStruct.GPIO_Pin = motor4_GPIO_PIN;									//����IO�ڣ�����PB�˿ڡ�
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;							//���������ʽ��Ϊ�������
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;						//�����ٶ�Ϊ50MHZ.
	GPIO_Init(motor4_GPIO_PORT, &GPIO_InitStruct);								//��IO�ڣ��ͽṹ�������ֵ��
}

void motor5_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;													//�������ʱ�����
	
	RCC_APB2PeriphClockCmd(motor5_GPIO_CLK, ENABLE);							//rcc ��ʱ�ӣ�����APB2���ߡ�
	GPIO_InitStruct.GPIO_Pin = motor5_GPIO_PIN;									//����IO�ڣ�����PB�˿ڡ�
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;							//���������ʽ��Ϊ�������
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;						//�����ٶ�Ϊ50MHZ.
	GPIO_Init(motor5_GPIO_PORT, &GPIO_InitStruct);								//��IO�ڣ��ͽṹ�������ֵ��
}

void motor6_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;													//�������ʱ�����
	
	RCC_APB2PeriphClockCmd(motor6_GPIO_CLK, ENABLE);							//rcc ��ʱ�ӣ�����APB2���ߡ�
	GPIO_InitStruct.GPIO_Pin = motor6_GPIO_PIN;									//����IO�ڣ�����PB�˿ڡ�
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;							//���������ʽ��Ϊ�������
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;						//�����ٶ�Ϊ50MHZ.
	GPIO_Init(motor6_GPIO_PORT, &GPIO_InitStruct);								//��IO�ڣ��ͽṹ�������ֵ��
}

void motor7_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;													//�������ʱ�����
	
	RCC_APB2PeriphClockCmd(motor7_GPIO_CLK, ENABLE);							//rcc ��ʱ�ӣ�����APB2���ߡ�
	GPIO_InitStruct.GPIO_Pin = motor7_GPIO_PIN;									//����IO�ڣ�����PB�˿ڡ�
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;							//���������ʽ��Ϊ�������
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;						//�����ٶ�Ϊ50MHZ.
	GPIO_Init(motor7_GPIO_PORT, &GPIO_InitStruct);								//��IO�ڣ��ͽṹ�������ֵ��
}

void motor8_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;													//�������ʱ�����
	
	RCC_APB2PeriphClockCmd(motor8_GPIO_CLK, ENABLE);							//rcc ��ʱ�ӣ�����APB2���ߡ�
	GPIO_InitStruct.GPIO_Pin = motor8_GPIO_PIN;									//����IO�ڣ�����PB�˿ڡ�
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;							//���������ʽ��Ϊ�������
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;						//�����ٶ�Ϊ50MHZ.
	GPIO_Init(motor8_GPIO_PORT, &GPIO_InitStruct);								//��IO�ڣ��ͽṹ�������ֵ��
}
void mortor_GPIO_Config(void)
{
	motor1_GPIO_Config();
	motor2_GPIO_Config();
	motor3_GPIO_Config();
	motor4_GPIO_Config();
	motor5_GPIO_Config();
	motor6_GPIO_Config();
	motor7_GPIO_Config();
	motor8_GPIO_Config();
}




