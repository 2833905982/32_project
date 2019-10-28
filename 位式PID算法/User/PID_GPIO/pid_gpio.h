#ifndef PID_GPIO_H
#define PID_GPIO_H


#include "stm32f10x.h"


#define PID_GPIO_PIN         GPIO_Pin_0 										//宏定义，定义IO口的引脚号。
#define PID_GPIO_PORT        GPIOB													//定义IO口的序号。
#define PID_GPIO_CLK         RCC_APB2Periph_GPIOB						//RCC,时钟函数打开时钟。


#define pwmout_1 				 		GPIO_SetBits(PID_GPIO_PORT,PID_GPIO_PIN)
#define pwmout_0						GPIO_ResetBits(PID_GPIO_PORT,PID_GPIO_PIN)

void PID_GPIO_Config(void);								//PID输出管脚初始化
void PID_out(void);

#endif /* PID_GPIO_H */

