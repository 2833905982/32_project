#include "stm32f10x.h"
#include "bsp_GeneralTim.h"  
#include "bsp_delay.h" 
#include "bsp_encoder.h"
#include "bsp_usart.h"
#include "bsp_adc.h"
#include "oled.h"
#include "sys.h"
#include "Robotic_arm_function.h" 
#include <Servo.h>
#include "bsp_usart4.h"

extern   int  num_1,num_2,num_3;


/*---------------------------------------------------------主程序--------------------------------------------------*/
int main(void)
{
	uint16_t lujing=1,//赛道
	    a=0,//左1颜色3600
	    b=0,//中间颜色;
	    c=0;
	char ch;
	
	     
	/*--------------------------初始化----------------------*/
	GENERAL_TIM_GPIO_Config();
	GENERAL_TIM_Mode_Config();
	USART_Config();
	delay_init();
	Encoder_Init_TIM1();
	Encoder_Init_TIM8();
	ADCx_Init();
	LED_GPIO_Config();

	OLED_Init();			//初始化OLED  
	OLED_Clear(); 
	USART4_Config();
	Servo_init();			

	

	printf("我有一个梦想！\n");
	

while(1)
		{
			ch= getchar();
			//printf("ch=%c",ch);
			
			switch(ch)
			{
				case 'A':sudu(7200,7200,0,0,1,1);//直行
					break;
				
				case 'C':sudu(7200,7200,1,1,1,1);//左拐
					break;
				
				case 'D':sudu(7200,7200,0,0,0,0);//右拐
					break;
				
				case 'B':sudu(7200,7200,1,1,0,0);//后退
					break;
				
				case '1':sudu(7200,7200,0,1,0,1);//左平行
					break;
				
				case '2':sudu(7200,7200,1,0,1,0);//右平行
					break;
				
				default:sudu(0,0,0,1,0,1);//停止
					break;
			}
			
		}
			



}

/*********************************************END OF FILE**********************/
