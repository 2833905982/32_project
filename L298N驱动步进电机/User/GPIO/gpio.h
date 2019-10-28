#ifndef __GPIO_H
#define __GPIO_H


#include "stm32f10x.h"


#define motor1_GPIO_PIN         GPIO_Pin_0 										//�궨�壬����IO�ڵ����źš�
#define motor1_GPIO_PORT        GPIOB													//����IO�ڵ���š�
#define motor1_GPIO_CLK         RCC_APB2Periph_GPIOB						//RCC,ʱ�Ӻ�����ʱ�ӡ�

#define motor2_GPIO_PIN         GPIO_Pin_1 										//�궨�壬����IO�ڵ����źš�
#define motor2_GPIO_PORT        GPIOB													//����IO�ڵ���š�
#define motor2_GPIO_CLK         RCC_APB2Periph_GPIOB						//RCC,ʱ�Ӻ�����ʱ�ӡ�

#define motor3_GPIO_PIN         GPIO_Pin_8 										//�궨�壬����IO�ڵ����źš�
#define motor3_GPIO_PORT        GPIOB													//����IO�ڵ���š�
#define motor3_GPIO_CLK         RCC_APB2Periph_GPIOB						//RCC,ʱ�Ӻ�����ʱ�ӡ�

#define motor4_GPIO_PIN         GPIO_Pin_3 										//�궨�壬����IO�ڵ����źš�
#define motor4_GPIO_PORT        GPIOB													//����IO�ڵ���š�
#define motor4_GPIO_CLK         RCC_APB2Periph_GPIOB						//RCC,ʱ�Ӻ�����ʱ�ӡ�

#define motor5_GPIO_PIN         GPIO_Pin_4										//�궨�壬����IO�ڵ����źš�
#define motor5_GPIO_PORT        GPIOB													//����IO�ڵ���š�
#define motor5_GPIO_CLK         RCC_APB2Periph_GPIOB						//RCC,ʱ�Ӻ�����ʱ�ӡ�

#define motor6_GPIO_PIN         GPIO_Pin_5 										//�궨�壬����IO�ڵ����źš�
#define motor6_GPIO_PORT        GPIOB													//����IO�ڵ���š�
#define motor6_GPIO_CLK         RCC_APB2Periph_GPIOB						//RCC,ʱ�Ӻ�����ʱ�ӡ�

#define motor7_GPIO_PIN         GPIO_Pin_6 										//�궨�壬����IO�ڵ����źš�
#define motor7_GPIO_PORT        GPIOB													//����IO�ڵ���š�
#define motor7_GPIO_CLK         RCC_APB2Periph_GPIOB						//RCC,ʱ�Ӻ�����ʱ�ӡ�

#define motor8_GPIO_PIN         GPIO_Pin_7 										//�궨�壬����IO�ڵ����źš�
#define motor8_GPIO_PORT        GPIOB													//����IO�ڵ���š�
#define motor8_GPIO_CLK         RCC_APB2Periph_GPIOB						//RCC,ʱ�Ӻ�����ʱ�ӡ�


void mortor_GPIO_Config(void);
void motor1_GPIO_Config(void);
void motor2_GPIO_Config(void);
void motor3_GPIO_Config(void);
void motor4_GPIO_Config(void);
void motor5_GPIO_Config(void);
void motor6_GPIO_Config(void);
void motor7_GPIO_Config(void);
void motor8_GPIO_Config(void);
	
	
#endif /* __GPIO_H */

