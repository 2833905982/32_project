#ifndef __SERVO_H
#define __SERVO_H
/**
  ******************************************************************************
  * @file    Servo.h
  * @version V3.2
  * @date    2018.10.6
  * @brief   修正switch(case)错误
  ******************************************************************************
  * @attention	1.只适用于大容量的开发板、使用别的开发板可能定时器不够。
								2.只能使用定时器1,2,3,4,8//
								3.定时器2的1通道可能会出错、未检验
								4.未重映射的状态下，定时器5和定时器2的引脚相互冲突，所以默认使用定时器2
								5.未考虑重映射
								6.使用了局部函数Servo_Delay_us(us),进行每调整一次后的延时
  *
  * 实验平台		:stm32f103zet6 核心板
  * 版权所有		:河南理工大学机械创新设计部
  * 责任人			:王太杰
  *
  ******************************************************************************
 **/
// #define PA8 TIM1_CH1							/*	默认复用：USART1_CK/MCO			*/ 
// #define PA9 TIM1_CH2							/*	默认复用：USART1_TX 			*/
// #define PA10	TIM1_CH3						/*	默认复用：USART1_RX 					*/
// #define PA11	TIM1_CH4 						/*	默认复用：USART1_CTS/USBDMCAN_RX*/
// 
// #define PA0 TIM2_CH1//TIM5_CH1 	/*	默认复用：WKUP/USART2_CTS/ADC123_IN0/TIM2_CH1_ETR/TIM5_CH1/TIM8_ETR*/
// #define PA1 TIM2_CH2//TIM5_CH1 	/*	默认复用：USART2_RTS/ADC123_IN1/TIM5_CH2*/
// #define PA2 TIM2_CH3//TIM5_CH1 	/*	默认复用：USART1_CTS/USBDMCAN_RX*/
// #define PA3 TIM2_CH4//TIM5_CH1 	/*	默认复用：USART1_CTS/USBDMCAN_RX*/
 
// #define PA6 TIM3_CH1							/*	默认复用：SPI1_MISO/TIM8_BKIN/ADC12_IN6/TIM3_CH1	重映射：TIM1_BKIN*/
// #define PA7 TIM3_CH2							/*	默认复用：SPI1_MOSI/TIM8_CH1N/ADC12_IN7/TIM3_CH2	重映射：TIM1_CH1N*/
// #define PB0 TIM3_CH3							/*	默认复用：ADC12_IN8/TIM8_CH2N										重映射：TIM1_CH2N*/
// #define PB1 TIM3_CH4							/*	默认复用：ADC12_IN9/TIM8_CH3N										重映射：TIM1_CH3N*/
// 
// #define PB6 TIM4_CH1							/*	默认复用：I2C1_SCL						重映射：USART1_TX*/
// #define PB7 TIM4_CH2							/*	默认复用：I2C1_SDA/FSMC_NADV	重映射：USART1_RX*/
// #define PB8 TIM4_CH3							/*	默认复用：SDIO_D4						重映射：I2C1_SCL/CAN_RX*/
// #define PB9 TIM4_CH4							/*	默认复用：I2C1_SDA/SDIO_D5		重映射：I2C1_SDA/CAN_TX*/

	/***************************注：一般不要用TIM5！！！******************************************/
// #define PA0 TIM5_CH1//TIM2_CH1		/*	默认复用：WKUP/USART2_CTS/ADC123_IN0/TIM2_CH1_ETR/TIM5_CH1/TIM8_ETR*/
// #define PA1 TIM5_CH2//TIM2_CH2		/*	默认复用：USART2_RTS/ADC123_IN1/TIM5_CH2*/
// #define PA2 TIM5_CH3//TIM2_CH3		/*	默认复用：USART1_CTS/USBDMCAN_RX*/
// #define PA3 TIM5_CH4//TIM2_CH4		/*	默认复用：USART1_CTS/USBDMCAN_RX*/
	/***************************注：一般不要用TIM5！！！******************************************/
	
// #define PC6 TIM8_CH1							/*	默认复用：I2S2_MCK/SDIO_D6		重映射：TIM3_CH1*/
// #define PC7 TIM8_CH2							/*	默认复用：I2S3_MCK/SDIO_D7		重映射：TIM3_CH2*/
// #define PC8 TIM8_CH3							/*	默认复用：SDIO_D0						重映射：TIM3_CH3*/
// #define PC9 TIM8_CH4							/*	默认复用：SDIO_D1						重映射：TIM3_CH4*/
 
//	static bool REMAP=false;
//	#if (REMAP)
//	#endif /* REMAP*/
#include "stm32f10x.h"
#define Servo_angle_max 2500 //舵机所能偏转的最大角度、软件防止程序猿多写、多写会烧舵机
#define Servo_angle_min	500	 //舵机所能偏转的最小角度、软件防止程序猿少写、少写会烧舵机
typedef struct 
{
    GPIO_TypeDef* Servo_GPIOx;//舵机所位于的GPIO口
    uint16_t Servo_GPIO_Pin;//舵机的pin口
		uint16_t start_angle;//舵机所想要赋值的初始角度(500-2500);初始化后，在舵机转动的过程中一直在被刷新
    uint16_t intent_angle;//intent_angle不能写超了、否则。后果我不清楚。

}Servo;


int Servo_Init(Servo Servox[],int array_length);//要使能的舵机结构体数组。
int NServo_Write(Servo Servox[],uint32_t us,int array_length);//要进行操作的结构体数组、和延时
#endif	/* __SERVO_H */

//////				/*************************示例程序**************************************/
//////				/**
//////					******************************************************************************
//////					* @file    main.c
//////					* @version V1.0
//////					* @date    2018.10.6
//////					* @brief   舵机函数示例程序
//////					******************************************************************************
//////					* @attention	Servo_Delay_ms(ms)延时函数已被注释、可以使用自己的工程的延时函数
//////					
//////					*
//////					* 实验平台		:stm32f103zet6 核心板
//////					* 版权所有		:河南理工大学机械创新设计部
//////					* 责任人			:王太杰
//////					*
//////					******************************************************************************
//////				 **/
//////				#include <Servo.h>
//////				#include <stm32f10x.h>
//////				#include <stm32f10x_gpio.h>
//////				/*************************定义舵机**************************************/
//////							Servo servo[4]={
//////							{GPIOA,GPIO_Pin_0,1500,1500},
//////							{GPIOA,GPIO_Pin_1,1500,1500},
//////							{GPIOA,GPIO_Pin_2,1500,1500}
//////							};//定义四个舵机，分别连在PA0,PA1,PA2,PA3上，初始角度为1500（相对中值）
//////							//舵机千万不能定义多了！！！！！
//////				/*************************获取定义的舵机个数**************************************/		
//////						int Length=sizeof(servo)/sizeof(servo[0]);//定义一个全局变量，以判断舵机的个数
//////							
//////						static void Servo_Delay_ms(uint16_t ms)//不精确的ms计延时.如果没有延时函数需要去注释
//////				{
//////					u32 i;//1us的时钟周期大概为80次
//////					while(ms--)
//////					{
//////					 i=80000;
//////						while(i--);
//////					}
//////				}
//////				int main(void)
//////				{			
//////					/*************************舵机使能**************************************/
//////					int Length=sizeof(servo)/sizeof(servo[0]);
//////					int Servo_deal_flag=0;//舵机处理函数的状态、如果返回1说明处理成功、否则失败。
//////					Servo_deal_flag=Servo_Init(servo,Length);//使能舵机结构体的所有成员。
//////					//Servo_deal_flag=NServo_Write(servo,1000,Length);//响应舵机结构体数组中需要调整的参数，并每偏转一个角度进行延时，以微妙计时。
//////					//printf("Servo_deal_flag=%d",Servo_deal_flag);//返回查看舵机处理是否成功。需要初始化串口
//////				//	
//////				//	/*************************单个舵机处理**************************************/
//////				//	servo[0].intent_angle=2000;//改变舵机0的目的角度
//////				//	NServo_Write(servo,1000,Length);//响应变化。
//////				//	Servo_Delay_ms(10);//等待舵机稳定、不需要加太长
//////				//	
//////					/*************************多个舵机处理**************************************/
//////					Servo_Delay_ms(100);
//////					servo[0].intent_angle=2000;//改变舵机0的目的角度
//////					servo[1].intent_angle=2000;//改变舵机1的目的角度
//////					servo[2].intent_angle=1500;//改变舵机0的目的角度
//////					NServo_Write(servo,300,Length);//响应变化。
//////					Servo_Delay_ms(10);//等待舵机稳定、不需要加太长
//////				}
