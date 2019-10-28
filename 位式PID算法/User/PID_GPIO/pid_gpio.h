#ifndef PID_GPIO_H
#define PID_GPIO_H


#include "stm32f10x.h"


#define PID_GPIO_PIN         GPIO_Pin_0 										//�궨�壬����IO�ڵ����źš�
#define PID_GPIO_PORT        GPIOB													//����IO�ڵ���š�
#define PID_GPIO_CLK         RCC_APB2Periph_GPIOB						//RCC,ʱ�Ӻ�����ʱ�ӡ�


#define pwmout_1 				 		GPIO_SetBits(PID_GPIO_PORT,PID_GPIO_PIN)
#define pwmout_0						GPIO_ResetBits(PID_GPIO_PORT,PID_GPIO_PIN)

void PID_GPIO_Config(void);								//PID����ܽų�ʼ��
void PID_out(void);

#endif /* PID_GPIO_H */

