#ifndef __GPIO_H
#define __GPIO_H


#include "stm32f10x.h"


#define motor1_GPIO_PIN         GPIO_Pin_0 										//宏定义，定义IO口的引脚号。
#define motor1_GPIO_PORT        GPIOB													//定义IO口的序号。
#define motor1_GPIO_CLK         RCC_APB2Periph_GPIOB						//RCC,时钟函数打开时钟。

#define motor2_GPIO_PIN         GPIO_Pin_1 										//宏定义，定义IO口的引脚号。
#define motor2_GPIO_PORT        GPIOB													//定义IO口的序号。
#define motor2_GPIO_CLK         RCC_APB2Periph_GPIOB						//RCC,时钟函数打开时钟。

#define motor3_GPIO_PIN         GPIO_Pin_8 										//宏定义，定义IO口的引脚号。
#define motor3_GPIO_PORT        GPIOB													//定义IO口的序号。
#define motor3_GPIO_CLK         RCC_APB2Periph_GPIOB						//RCC,时钟函数打开时钟。

#define motor4_GPIO_PIN         GPIO_Pin_3 										//宏定义，定义IO口的引脚号。
#define motor4_GPIO_PORT        GPIOB													//定义IO口的序号。
#define motor4_GPIO_CLK         RCC_APB2Periph_GPIOB						//RCC,时钟函数打开时钟。

#define motor5_GPIO_PIN         GPIO_Pin_4										//宏定义，定义IO口的引脚号。
#define motor5_GPIO_PORT        GPIOB													//定义IO口的序号。
#define motor5_GPIO_CLK         RCC_APB2Periph_GPIOB						//RCC,时钟函数打开时钟。

#define motor6_GPIO_PIN         GPIO_Pin_5 										//宏定义，定义IO口的引脚号。
#define motor6_GPIO_PORT        GPIOB													//定义IO口的序号。
#define motor6_GPIO_CLK         RCC_APB2Periph_GPIOB						//RCC,时钟函数打开时钟。

#define motor7_GPIO_PIN         GPIO_Pin_6 										//宏定义，定义IO口的引脚号。
#define motor7_GPIO_PORT        GPIOB													//定义IO口的序号。
#define motor7_GPIO_CLK         RCC_APB2Periph_GPIOB						//RCC,时钟函数打开时钟。

#define motor8_GPIO_PIN         GPIO_Pin_7 										//宏定义，定义IO口的引脚号。
#define motor8_GPIO_PORT        GPIOB													//定义IO口的序号。
#define motor8_GPIO_CLK         RCC_APB2Periph_GPIOB						//RCC,时钟函数打开时钟。


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

