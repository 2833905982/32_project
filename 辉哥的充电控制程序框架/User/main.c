#include "stm32f10x.h"   // 相当于51单片机中的  #include <reg51.h>
#include "GeneralTim.h" 
#include "SysTick.h"
#include "usart.h"
#include "gpio.h"
#include "adc.h"



extern __IO uint16_t ADC_ConvertedValue[NOFCHANEL];

// 局部变量，用于保存转换计算后的电压值 	 
float ADC_ConvertedValueLocal[NOFCHANEL];    
float PP = 0;
float DR;
uint8_t i = 50;
void da_dong_zuo(void);
int main(void)
{
	/* 初始化串口函数 */
	USART_Config();
	
	/* 初始化 GPIO 口*/
	GPIO_Config();
	
	/* 初始化 PWM */
	GENERAL_TIM_Init();
	
	printf( "我有一个梦想！\n" );
	
	/* 初始化ADC */
	ADCx_Init();
	
//	/* 使能一个 GPIO 口，让主控板开始工作 */
//	GPIO_SetBits(GPIO1_PORT, GPIO1_PIN);
	//GPIO_SetBits(GPIO1_PORT,GPIO1_PIN);					//置高，PWM 输出停止
	while(1)
	{
			ADC_ConvertedValueLocal[0] =(float) ADC_ConvertedValue[0]/4096*3.3;
			ADC_ConvertedValueLocal[1] =(float) ADC_ConvertedValue[1]/4096*3.3;
			ADC_ConvertedValueLocal[2] =(float) ADC_ConvertedValue[2]/4096*3.3;
//			ADC_ConvertedValueLocal[3] =(float) ADC_ConvertedValue[3]/4096*3.3;
//			ADC_ConvertedValueLocal[4] =(float) ADC_ConvertedValue[4]/4096*3.3;
//			ADC_ConvertedValueLocal[5] =(float) ADC_ConvertedValue[5]/4096*3.3;
		
			printf("\r\n XQ value = %f V \r\n",ADC_ConvertedValueLocal[0]);
			printf("\r\n DR value = %f V \r\n",ADC_ConvertedValueLocal[1]);
			printf("\r\n DL value = %f V \r\n",ADC_ConvertedValueLocal[2]);
//			printf("\r\n CH3 value = %f V \r\n",ADC_ConvertedValueLocal[3]);
//			printf("\r\n CH4 value = %f V \r\n",ADC_ConvertedValueLocal[4]);
//			printf("\r\n CH5 value = %f V \r\n",ADC_ConvertedValueLocal[5]);
		
			printf("\r\n\r\n");
		
			SysTick_Dwelay_us(100);
		
			da_dong_zuo();
		
	}
}

void da_dong_zuo(void)
{
	/* 使能芯片 */
	GPIO_SetBits(GPIO2_PORT,GPIO2_PIN);	

//	/* 开启PWM */
//	GPIO_ResetBits(GPIO1_PORT,GPIO1_PIN);
//	
	/* 计算功率 */
	
		TIM_SetCompare3(TIM3,i);

	
	PP = ADC_ConvertedValueLocal[2] * ADC_ConvertedValueLocal[0];
	
	if(PP < 35 )
	{
		
	}
	
	
	if(DR < 1.2)
	{
 
		
	}
	else
	{
	
	}
		
}




