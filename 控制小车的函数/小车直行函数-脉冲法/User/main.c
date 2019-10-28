#include "stm32f10x.h"   // 相当于51单片机中的  #include <reg51.h>
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
	
	LED1_GPIO_Config();																			//设置函数封装各个功能块。
	
	EXTI_Key_Config();
	
	USART_Config();
	
	while(1)
	{
		
		
		GPIO_SetBits(LED1_GPIO_PORT, LED1_GPIO_PIN);							//GPIO_SetBits函数，让改GPIO置底，使小灯有亮起来的可能。
		GPIO_SetBits(LED2_GPIO_PORT, LED2_GPIO_PIN);							//GPIO_SetBits函数，让改GPIO置底，使小灯有亮起来的可能。

		//Delay(0xFFFFF);
		SysTick_Dwelay_ms(5);
		
		GPIO_ResetBits(LED1_GPIO_PORT, LED1_GPIO_PIN);						//GPIO_ResetBits函数，让GPIO置高，是小灯灭掉。
		GPIO_ResetBits(LED2_GPIO_PORT, LED2_GPIO_PIN);						//GPIO_ResetBits函数，让GPIO置高，是小灯灭掉。
		//Delay(0xFFFFF);																					//关于延时函数的数字输入，好像10进制不行。
		SysTick_Dwelay_ms(5); 
		
		

		
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


























