#ifndef __LED_H
#define	__LED_H


#include "stm32f10x.h"


/* 定义LED连接的GPIO端口, 用户只需要修改下面的代码即可改变控制的LED引脚 */
// 寻迹左指示灯
#define LED1_GPIO_PORT    	GPIOA			              /* GPIO端口 */
#define LED1_GPIO_CLK 	    RCC_APB2Periph_GPIOA		/* GPIO端口时钟 */
#define LED1_GPIO_PIN		    GPIO_Pin_8	        /* 连接到SCL时钟线的GPIO */

//按键key1配置
#define KEY1_GPIO_PORT    	GPIOC			              /* GPIO端口 */
#define KEY1_GPIO_CLK 	    RCC_APB2Periph_GPIOC		/* GPIO端口时钟 */
#define KEY1_GPIO_PIN		    GPIO_Pin_12	        /* 连接到SCL时钟线的GPIO */

//按键key2配置
#define KEY2_GPIO_PORT    	GPIOD			              /* GPIO端口 */
#define KEY2_GPIO_CLK 	    RCC_APB2Periph_GPIOD		/* GPIO端口时钟 */
#define KEY2_GPIO_PIN		    GPIO_Pin_2	        /* 连接到SCL时钟线的GPIO */

/** the macro definition to trigger the led on or off 
  * 1 - off
  *0 - on
  */
#define ON  1
#define OFF 0

/* 使用标准的固件库控制IO*/
#define LED1(a)	if (a)	\
					GPIO_SetBits(LED1_GPIO_PORT,LED1_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LED1_GPIO_PORT,LED1_GPIO_PIN)



//数字灰度
#define SHUZIHUIDU_GPIO_CLK_ABCD      RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOD
#define SHUZIHUIDU_GPIO_PIN0       GPIO_Pin_0
#define SHUZIHUIDU_GPIO_PIN1       GPIO_Pin_1
#define SHUZIHUIDU_GPIO_PIN2       GPIO_Pin_2
#define SHUZIHUIDU_GPIO_PIN3       GPIO_Pin_3
#define SHUZIHUIDU_GPIO_PIN4       GPIO_Pin_4
#define SHUZIHUIDU_GPIO_PIN5       GPIO_Pin_5
#define SHUZIHUIDU_GPIO_PIN6       GPIO_Pin_6
#define SHUZIHUIDU_GPIO_PIN7       GPIO_Pin_7
#define SHUZIHUIDU_GPIO_PIN8       GPIO_Pin_8
#define SHUZIHUIDU_GPIO_PIN9       GPIO_Pin_9
#define SHUZIHUIDU_GPIO_PIN10      GPIO_Pin_10
#define SHUZIHUIDU_GPIO_PIN11      GPIO_Pin_11
#define SHUZIHUIDU_GPIO_PIN12      GPIO_Pin_12
#define SHUZIHUIDU_GPIO_PIN13      GPIO_Pin_13
#define SHUZIHUIDU_GPIO_PIN14      GPIO_Pin_14
#define SHUZIHUIDU_GPIO_PIN15      GPIO_Pin_15
#define SHUZIHUIDU_GPIO_PORT_A     GPIOA
#define SHUZIHUIDU_GPIO_PORT_B     GPIOB
#define SHUZIHUIDU_GPIO_PORT_C     GPIOC
#define SHUZIHUIDU_GPIO_PORT_D     GPIOD				



void LED_GPIO_Config(void);			
void GPIO_shuzihuidu_Config(void);		
uint8_t Key1_Scan(void);
uint8_t Key2_Scan(void);

#endif /* __LED_H */
