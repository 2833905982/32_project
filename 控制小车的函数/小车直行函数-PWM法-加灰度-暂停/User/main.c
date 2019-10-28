#include "stm32f10x.h"   // 相当于51单片机中的  #include <reg51.h>
#include "bsp_GeneralTim.h" 
#include "systick.h"
#include "usart.h"
#include "exti.h"
#include "led.h"

void qianjin(void);
void houtui(void);
void zuoguai(void);
void youguai(void);
int main(void)
{
	// 来到这里的时候，系统的时钟已经被配置成72M。
	//uint8_t ch;
	
	/* 初始化 GPIO口 */
	LED1_GPIO_Config();																			//设置函数封装各个功能块。
	
	/* 初始化按键 */
	EXTI_Key_Config();
	
	/* 初始化 PWM */
	GENERAL_TIM_Init();
	
	/* 初始化串口 */
	USART_Config();
	
	printf("渣子来了");	
	
	while(1)
	{
		
		TIM_SetCompare3(TIM3,25);												//更改参数就可以更改PWM占空比的函数。
		
/*---------------------初始化小车，即前进方向的固定----------------------------*/

		GPIO_SetBits(Rwheel1_GPIO_PORT, Rwheel1_GPIO_PIN);							//操作A2引脚
		//GPIO_ResetBits(Rwheel1_GPIO_PORT, Rwheel1_GPIO_PIN);							//左轮正转
		
		//GPIO_SetBits(Lwheel2_GPIO_PORT, Lwheel2_GPIO_PIN);					  		//操作的A4引脚
		GPIO_ResetBits(Lwheel2_GPIO_PORT, Lwheel2_GPIO_PIN);						//右轮正转
		
		
/*-------------------------------串口调试---------------------------------*/		


//		ch = getchar();
//		
//		printf("ch = %c",ch);
//		
//		switch(ch)
//		{
//						/* 前进 */
//			case '1': qianjin();break;
//						/* 后退 */
//			case '2': houtui();break;
//						/* 左拐 */
//			case '3': zuoguai();break;
//						/* 右拐 */
//			case '4': youguai();break;
//			default : break;
//		}
		
	}
	
}
	

//void qianjin(void)
//{
//	GPIO_ResetBits(Rwheel1_GPIO_PORT, Rwheel1_GPIO_PIN);
//	GPIO_SetBits(Lwheel2_GPIO_PORT, Lwheel2_GPIO_PIN);	
//}
//void houtui(void)
//{
//	GPIO_SetBits(Rwheel1_GPIO_PORT, Rwheel1_GPIO_PIN);
//	GPIO_ResetBits(Lwheel2_GPIO_PORT, Lwheel2_GPIO_PIN);
//}
//void zuoguai(void)
//{
//	GPIO_SetBits(Lwheel2_GPIO_PORT, Lwheel2_GPIO_PIN);
//	GPIO_SetBits(Rwheel1_GPIO_PORT, Rwheel1_GPIO_PIN);
//}
//void youguai(void)
//{
//	GPIO_ResetBits(Lwheel2_GPIO_PORT, Lwheel2_GPIO_PIN);
//	GPIO_ResetBits(Rwheel1_GPIO_PORT, Rwheel1_GPIO_PIN);
//}


























