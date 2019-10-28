#ifndef __BSP_GENERALTIME_H
#define __BSP_GENERALTIME_H


#include "stm32f10x.h"


//行走数据
#define   leftgo    2600  //左轮
#define   rightgo   2100  //右轮

#define   voltage   3.299194   //电压

/************通用定时器TIM参数定义，只限TIM2、3、4、5************/
// 当使用不同的定时器的时候，对应的GPIO是不一样的，这点要注意

/*------------------------------------------------TIM3配置-------------------------------------------------------*/

#define            GENERAL_TIM3                   TIM3
#define            GENERAL_TIM_APBxClock_FUN      RCC_APB1PeriphClockCmd
#define            GENERAL_TIM3_CLK               RCC_APB1Periph_TIM3
#define            GENERAL_TIM_Period            (20000-1)
#define            GENERAL_TIM_Prescaler         (72-1)
// TIM3 输出比较通道1
#define            GENERAL_TIM3_CH1_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM3_CH1_PORT          GPIOA
#define            GENERAL_TIM3_CH1_PIN           GPIO_Pin_6

// TIM3 输出比较通道2
#define            GENERAL_TIM3_CH2_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM3_CH2_PORT          GPIOA
#define            GENERAL_TIM3_CH2_PIN           GPIO_Pin_7

// TIM3 输出比较通道3
#define            GENERAL_TIM3_CH3_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            GENERAL_TIM3_CH3_PORT          GPIOB
#define            GENERAL_TIM3_CH3_PIN           GPIO_Pin_0

// TIM3 输出比较通道4
#define            GENERAL_TIM3_CH4_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            GENERAL_TIM3_CH4_PORT          GPIOB
#define            GENERAL_TIM3_CH4_PIN           GPIO_Pin_1

/*------------------------------------------------TIM5配置-------------------------------------------------------*/

#define            GENERAL_TIM5                   TIM5
#define            GENERAL_TIM5_CLK               RCC_APB1Periph_TIM5
// TIM5 输出比较通道1
#define            GENERAL_TIM5_CH1_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM5_CH1_PORT          GPIOA
#define            GENERAL_TIM5_CH1_PIN           GPIO_Pin_0

// TIM5 输出比较通道2
#define            GENERAL_TIM5_CH2_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM5_CH2_PORT          GPIOA
#define            GENERAL_TIM5_CH2_PIN           GPIO_Pin_1

// TIM5 输出比较通道3
#define            GENERAL_TIM5_CH3_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM5_CH3_PORT          GPIOA
#define            GENERAL_TIM5_CH3_PIN           GPIO_Pin_2

// TIM5 输出比较通道3
#define            GENERAL_TIM5_CH4_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM5_CH4_PORT          GPIOA
#define            GENERAL_TIM5_CH4_PIN           GPIO_Pin_3

/*---------------------------------------------------------------TIM4配置-----------------------------------------------------*/

#define            GENERAL_TIM4                   TIM4
#define            GENERAL_TIM4_CLK               RCC_APB1Periph_TIM4
#define            GENERAL_TIM_Period_Run         (7200-1)
#define            GENERAL_TIM_Prescaler_Run      (1-1)

// TIM4 输出比较通道1
#define            GENERAL_TIM4_CH1_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            GENERAL_TIM4_CH1_PORT          GPIOB
#define            GENERAL_TIM4_CH1_PIN           GPIO_Pin_6

// TIM4 输出比较通道2
#define            GENERAL_TIM4_CH2_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            GENERAL_TIM4_CH2_PORT          GPIOB
#define            GENERAL_TIM4_CH2_PIN           GPIO_Pin_7





//++++++++++++++++++轮子方向引脚定义+++++++++++++++++++++++++++++++++

#define LUN_GPIO_PORT       	GPIOB		                /* GPIO端口 */
#define LUN_ZUO_GPIO_CLK 	    RCC_APB2Periph_GPIOB		/* GPIO端口时钟 *///左轮
#define LUN_ZUO1_GPIO_PIN		  GPIO_Pin_12	            /* 连接到SCL时钟线的GPIO */
#define LUN_ZUO2_GPIO_PIN		  GPIO_Pin_13	            /* 连接到SCL时钟线的GPIO */
#define LUN_YOU_GPIO_CLK 	    RCC_APB2Periph_GPIOB		/* GPIO端口时钟 *///右轮
#define LUN_YOU1_GPIO_PIN		  GPIO_Pin_14              /* 连接到SCL时钟线的GPIO */
#define LUN_YOU2_GPIO_PIN		  GPIO_Pin_15              /* 连接到SCL时钟线的GPIO */





/* 使用标准的固件库控制IO*/
#define LUN_ZUO1(a)	if (a)	\
					GPIO_SetBits(LUN_GPIO_PORT,LUN_ZUO1_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LUN_GPIO_PORT,LUN_ZUO1_GPIO_PIN)
/* 使用标准的固件库控制IO*/
#define LUN_ZUO2(a)	if (a)	\
					GPIO_SetBits(LUN_GPIO_PORT,LUN_ZUO2_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LUN_GPIO_PORT,LUN_ZUO2_GPIO_PIN)					
					
/* 使用标准的固件库控制IO*/
#define LUN_YOU1(a)	if (a)	\
					GPIO_SetBits(LUN_GPIO_PORT,LUN_YOU1_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LUN_GPIO_PORT,LUN_YOU1_GPIO_PIN)					
/* 使用标准的固件库控制IO*/
#define LUN_YOU2(a)	if (a)	\
					GPIO_SetBits(LUN_GPIO_PORT,LUN_YOU2_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LUN_GPIO_PORT,LUN_YOU2_GPIO_PIN)									
					
/**************************函数声明********************************/
void LED_GPIO_Config(void);/*LDE显示灯初始化*/

void	GENERAL_TIM_GPIO_Config(void);	
void GENERAL_TIM_Mode_Config(void);
void Leftsudu(u16 left,u16 fangxiang);//第一个参数速度  第二个参数方向
void Rightsudu(u16 right,u16 fangxiang);//第一个参数速度  第二个参数方向
void sudu(u16 left,u16 right,u16 Fangxiang1,u16 Fangxiang2,u16 Fangxiang3,u16 Fangxiang4);//前两个参数左右电机速度  后两个参数方向

int ZhuanPan(u16 intend_angle,u32 us);
int DuoJi1(u16 intend_angle,u32 us);
int DuoJi2(u16 intend_angle,u32 us);
int DuoJi3(u16 intend_angle,u32 us);
int ZhaZi(u16 intend_angle,u32 us);


int Servo_move(TIM_TypeDef* TIMx,uint8_t CCRx,u16 intend_angle,u32 us);

#endif	/* __BSP_GENERALTIME_H */


