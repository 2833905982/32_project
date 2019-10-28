#include "stm32f10x.h"  
#include "stm32f10x_it.h"
#include "mpu6050.h"
#include "systick.h"
#include "usart.h"
#include "led.h"
#include "i2c.h"


//�����Ƿ�ʹ��LCD������ʾ������Ҫ�Ļ������ע�͵�����
//#define USE_LCD_DISPLAY


#ifdef USE_LCD_DISPLAY
#include "bsp_ili9341_lcd.h"
#endif



#define TASK_ENABLE 0
extern unsigned int Task_Delay[NumOfTask];
/*
 * t : ��ʱʱ�� 
 * Ticks : ���ٸ�ʱ�����ڲ���һ���ж� 
 * f : ʱ��Ƶ�� 72000000
 * t = Ticks * 1/f = (72000000/100000) * (1/72000000) = 10us 
 */ 

/**
  * @brief  ������
  * @param  ��  
  * @retval ��
  */
int main(void)
{
	short Accel[3];
	short Gyro[3];
	float Temp;
	
#ifdef USE_LCD_DISPLAY

	ILI9341_Init ();         //LCD ��ʼ��
  ILI9341_GramScan ( 6 );
	LCD_SetFont(&Font8x16);
	LCD_SetColors(RED,BLACK);
	
	ILI9341_Clear ( 0, 0, 240, 320);	
  ILI9341_DispString_EN ( 20, 20, "This is a MPU6050 demo" );
#endif
  
  //��ʼ��systick
	SysTick_Init();
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk;
	/* LED �˿ڳ�ʼ�� */
	LED_GPIO_Config();
	/* ����1ͨ�ų�ʼ�� */
	USART_Config();

	//I2C��ʼ��
	i2c_GPIO_Config();
  //MPU6050��ʼ��
	MPU6050_Init();
	
	printf("\r\n �������ˣ�\r\n");		 

	printf("\r\n ����һ��MPU6050�������̣� \r\n");


	//���MPU6050
	if (MPU6050ReadID() == 1)
	{	
	
		while(1)
		{
			if(Task_Delay[0]==TASK_ENABLE)
			{
				LED2_TOGGLE;
				Task_Delay[0]=1000;
			}
			
			if(Task_Delay[1]==0)
			{
				MPU6050ReadAcc(Accel);			
				printf("\r\n���ٶȣ� %8d%8d%8d    ",Accel[0],Accel[1],Accel[2]);
				MPU6050ReadGyro(Gyro);
				printf("�����ǣ� %8d%8d%8d    ",Gyro[0],Gyro[1],Gyro[2]);
				
				MPU6050_ReturnTemp(&Temp); 
				printf("�¶ȣ� %8.2f",Temp);
				
				#ifdef USE_LCD_DISPLAY	
					{
						char cStr [ 70 ];
						
						ILI9341_DispStringLine_EN(LINE(7),"Acceleration");		
						sprintf ( cStr, "%8d%8d%8d",Accel[0],Accel[1],Accel[2] );	//���ٶ�ԭʼ����
						ILI9341_DispStringLine_EN(LINE(8),cStr);					


						ILI9341_DispStringLine_EN(LINE(11),"Gyro        :");			
						sprintf ( cStr, "%8d%8d%8d",Gyro[0],Gyro[1],Gyro[2] );	//��ԭʼ����
						ILI9341_DispStringLine_EN(LINE(12),cStr);	

						sprintf ( cStr, "Temperture  :%8.2f",Temp );	//�¶�ֵ
						ILI9341_DispStringLine_EN(LINE(15),cStr);			

					}
				#endif
				
				Task_Delay[1]=100;//����һ�����ݣ��ɸ����Լ���������߲���Ƶ�ʣ���100ms����һ��
			}

			//*************************************	��������������ĸ�ʽ************************************//
	//		if(Task_Delay[i]==0)
	//		{
	//			Task(i);
	//			Task_Delay[i]=;
	//		}

		}   
	}
	else
	{
			printf("\r\nû�м�⵽MPU6050��������\r\n");
			LED_RED; 
			#ifdef USE_LCD_DISPLAY			
				/*����������ɫ������ı�����ɫ*/
				LCD_SetColors(BLUE,BLACK);	

				ILI9341_DispStringLine_EN(LINE(4),"No MPU6050 detected! ");			
				ILI9341_DispStringLine_EN(LINE(5),"Please check the hardware connection! ");		

			#endif
		while(1);	
	}
	
}

/*********************************************END OF FILE**********************/

