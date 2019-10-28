#ifndef __SERVO_H
#define __SERVO_H
/**
  ******************************************************************************
  * @file    Servo.h
  * @version V3.2
  * @date    2018.10.6
  * @brief   ����switch(case)����
  ******************************************************************************
  * @attention	1.ֻ�����ڴ������Ŀ����塢ʹ�ñ�Ŀ�������ܶ�ʱ��������
								2.ֻ��ʹ�ö�ʱ��1,2,3,4,8//
								3.��ʱ��2��1ͨ�����ܻ����δ����
								4.δ��ӳ���״̬�£���ʱ��5�Ͷ�ʱ��2�������໥��ͻ������Ĭ��ʹ�ö�ʱ��2
								5.δ������ӳ��
								6.ʹ���˾ֲ�����Servo_Delay_us(us),����ÿ����һ�κ����ʱ
  *
  * ʵ��ƽ̨		:stm32f103zet6 ���İ�
  * ��Ȩ����		:��������ѧ��е������Ʋ�
  * ������			:��̫��
  *
  ******************************************************************************
 **/
// #define PA8 TIM1_CH1							/*	Ĭ�ϸ��ã�USART1_CK/MCO			*/ 
// #define PA9 TIM1_CH2							/*	Ĭ�ϸ��ã�USART1_TX 			*/
// #define PA10	TIM1_CH3						/*	Ĭ�ϸ��ã�USART1_RX 					*/
// #define PA11	TIM1_CH4 						/*	Ĭ�ϸ��ã�USART1_CTS/USBDMCAN_RX*/
// 
// #define PA0 TIM2_CH1//TIM5_CH1 	/*	Ĭ�ϸ��ã�WKUP/USART2_CTS/ADC123_IN0/TIM2_CH1_ETR/TIM5_CH1/TIM8_ETR*/
// #define PA1 TIM2_CH2//TIM5_CH1 	/*	Ĭ�ϸ��ã�USART2_RTS/ADC123_IN1/TIM5_CH2*/
// #define PA2 TIM2_CH3//TIM5_CH1 	/*	Ĭ�ϸ��ã�USART1_CTS/USBDMCAN_RX*/
// #define PA3 TIM2_CH4//TIM5_CH1 	/*	Ĭ�ϸ��ã�USART1_CTS/USBDMCAN_RX*/
 
// #define PA6 TIM3_CH1							/*	Ĭ�ϸ��ã�SPI1_MISO/TIM8_BKIN/ADC12_IN6/TIM3_CH1	��ӳ�䣺TIM1_BKIN*/
// #define PA7 TIM3_CH2							/*	Ĭ�ϸ��ã�SPI1_MOSI/TIM8_CH1N/ADC12_IN7/TIM3_CH2	��ӳ�䣺TIM1_CH1N*/
// #define PB0 TIM3_CH3							/*	Ĭ�ϸ��ã�ADC12_IN8/TIM8_CH2N										��ӳ�䣺TIM1_CH2N*/
// #define PB1 TIM3_CH4							/*	Ĭ�ϸ��ã�ADC12_IN9/TIM8_CH3N										��ӳ�䣺TIM1_CH3N*/
// 
// #define PB6 TIM4_CH1							/*	Ĭ�ϸ��ã�I2C1_SCL						��ӳ�䣺USART1_TX*/
// #define PB7 TIM4_CH2							/*	Ĭ�ϸ��ã�I2C1_SDA/FSMC_NADV	��ӳ�䣺USART1_RX*/
// #define PB8 TIM4_CH3							/*	Ĭ�ϸ��ã�SDIO_D4						��ӳ�䣺I2C1_SCL/CAN_RX*/
// #define PB9 TIM4_CH4							/*	Ĭ�ϸ��ã�I2C1_SDA/SDIO_D5		��ӳ�䣺I2C1_SDA/CAN_TX*/

	/***************************ע��һ�㲻Ҫ��TIM5������******************************************/
// #define PA0 TIM5_CH1//TIM2_CH1		/*	Ĭ�ϸ��ã�WKUP/USART2_CTS/ADC123_IN0/TIM2_CH1_ETR/TIM5_CH1/TIM8_ETR*/
// #define PA1 TIM5_CH2//TIM2_CH2		/*	Ĭ�ϸ��ã�USART2_RTS/ADC123_IN1/TIM5_CH2*/
// #define PA2 TIM5_CH3//TIM2_CH3		/*	Ĭ�ϸ��ã�USART1_CTS/USBDMCAN_RX*/
// #define PA3 TIM5_CH4//TIM2_CH4		/*	Ĭ�ϸ��ã�USART1_CTS/USBDMCAN_RX*/
	/***************************ע��һ�㲻Ҫ��TIM5������******************************************/
	
// #define PC6 TIM8_CH1							/*	Ĭ�ϸ��ã�I2S2_MCK/SDIO_D6		��ӳ�䣺TIM3_CH1*/
// #define PC7 TIM8_CH2							/*	Ĭ�ϸ��ã�I2S3_MCK/SDIO_D7		��ӳ�䣺TIM3_CH2*/
// #define PC8 TIM8_CH3							/*	Ĭ�ϸ��ã�SDIO_D0						��ӳ�䣺TIM3_CH3*/
// #define PC9 TIM8_CH4							/*	Ĭ�ϸ��ã�SDIO_D1						��ӳ�䣺TIM3_CH4*/
 
//	static bool REMAP=false;
//	#if (REMAP)
//	#endif /* REMAP*/
#include "stm32f10x.h"
#define Servo_angle_max 2500 //�������ƫת�����Ƕȡ������ֹ����Գ��д����д���ն��
#define Servo_angle_min	500	 //�������ƫת����С�Ƕȡ������ֹ����Գ��д����д���ն��
typedef struct 
{
    GPIO_TypeDef* Servo_GPIOx;//�����λ�ڵ�GPIO��
    uint16_t Servo_GPIO_Pin;//�����pin��
		uint16_t start_angle;//�������Ҫ��ֵ�ĳ�ʼ�Ƕ�(500-2500);��ʼ�����ڶ��ת���Ĺ�����һֱ�ڱ�ˢ��
    uint16_t intent_angle;//intent_angle����д���ˡ����򡣺���Ҳ������

}Servo;


int Servo_Init(Servo Servox[],int array_length);//Ҫʹ�ܵĶ���ṹ�����顣
int NServo_Write(Servo Servox[],uint32_t us,int array_length);//Ҫ���в����Ľṹ�����顢����ʱ
#endif	/* __SERVO_H */

//////				/*************************ʾ������**************************************/
//////				/**
//////					******************************************************************************
//////					* @file    main.c
//////					* @version V1.0
//////					* @date    2018.10.6
//////					* @brief   �������ʾ������
//////					******************************************************************************
//////					* @attention	Servo_Delay_ms(ms)��ʱ�����ѱ�ע�͡�����ʹ���Լ��Ĺ��̵���ʱ����
//////					
//////					*
//////					* ʵ��ƽ̨		:stm32f103zet6 ���İ�
//////					* ��Ȩ����		:��������ѧ��е������Ʋ�
//////					* ������			:��̫��
//////					*
//////					******************************************************************************
//////				 **/
//////				#include <Servo.h>
//////				#include <stm32f10x.h>
//////				#include <stm32f10x_gpio.h>
//////				/*************************������**************************************/
//////							Servo servo[4]={
//////							{GPIOA,GPIO_Pin_0,1500,1500},
//////							{GPIOA,GPIO_Pin_1,1500,1500},
//////							{GPIOA,GPIO_Pin_2,1500,1500}
//////							};//�����ĸ�������ֱ�����PA0,PA1,PA2,PA3�ϣ���ʼ�Ƕ�Ϊ1500�������ֵ��
//////							//���ǧ���ܶ�����ˣ���������
//////				/*************************��ȡ����Ķ������**************************************/		
//////						int Length=sizeof(servo)/sizeof(servo[0]);//����һ��ȫ�ֱ��������ж϶���ĸ���
//////							
//////						static void Servo_Delay_ms(uint16_t ms)//����ȷ��ms����ʱ.���û����ʱ������Ҫȥע��
//////				{
//////					u32 i;//1us��ʱ�����ڴ��Ϊ80��
//////					while(ms--)
//////					{
//////					 i=80000;
//////						while(i--);
//////					}
//////				}
//////				int main(void)
//////				{			
//////					/*************************���ʹ��**************************************/
//////					int Length=sizeof(servo)/sizeof(servo[0]);
//////					int Servo_deal_flag=0;//�����������״̬���������1˵������ɹ�������ʧ�ܡ�
//////					Servo_deal_flag=Servo_Init(servo,Length);//ʹ�ܶ���ṹ������г�Ա��
//////					//Servo_deal_flag=NServo_Write(servo,1000,Length);//��Ӧ����ṹ����������Ҫ�����Ĳ�������ÿƫתһ���ǶȽ�����ʱ����΢���ʱ��
//////					//printf("Servo_deal_flag=%d",Servo_deal_flag);//���ز鿴��������Ƿ�ɹ�����Ҫ��ʼ������
//////				//	
//////				//	/*************************�����������**************************************/
//////				//	servo[0].intent_angle=2000;//�ı���0��Ŀ�ĽǶ�
//////				//	NServo_Write(servo,1000,Length);//��Ӧ�仯��
//////				//	Servo_Delay_ms(10);//�ȴ�����ȶ�������Ҫ��̫��
//////				//	
//////					/*************************����������**************************************/
//////					Servo_Delay_ms(100);
//////					servo[0].intent_angle=2000;//�ı���0��Ŀ�ĽǶ�
//////					servo[1].intent_angle=2000;//�ı���1��Ŀ�ĽǶ�
//////					servo[2].intent_angle=1500;//�ı���0��Ŀ�ĽǶ�
//////					NServo_Write(servo,300,Length);//��Ӧ�仯��
//////					Servo_Delay_ms(10);//�ȴ�����ȶ�������Ҫ��̫��
//////				}
