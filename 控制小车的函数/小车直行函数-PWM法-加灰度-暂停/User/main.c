#include "stm32f10x.h"   // �൱��51��Ƭ���е�  #include <reg51.h>
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
	// ���������ʱ��ϵͳ��ʱ���Ѿ������ó�72M��
	//uint8_t ch;
	
	/* ��ʼ�� GPIO�� */
	LED1_GPIO_Config();																			//���ú�����װ�������ܿ顣
	
	/* ��ʼ������ */
	EXTI_Key_Config();
	
	/* ��ʼ�� PWM */
	GENERAL_TIM_Init();
	
	/* ��ʼ������ */
	USART_Config();
	
	printf("��������");	
	
	while(1)
	{
		
		TIM_SetCompare3(TIM3,25);												//���Ĳ����Ϳ��Ը���PWMռ�ձȵĺ�����
		
/*---------------------��ʼ��С������ǰ������Ĺ̶�----------------------------*/

		GPIO_SetBits(Rwheel1_GPIO_PORT, Rwheel1_GPIO_PIN);							//����A2����
		//GPIO_ResetBits(Rwheel1_GPIO_PORT, Rwheel1_GPIO_PIN);							//������ת
		
		//GPIO_SetBits(Lwheel2_GPIO_PORT, Lwheel2_GPIO_PIN);					  		//������A4����
		GPIO_ResetBits(Lwheel2_GPIO_PORT, Lwheel2_GPIO_PIN);						//������ת
		
		
/*-------------------------------���ڵ���---------------------------------*/		


//		ch = getchar();
//		
//		printf("ch = %c",ch);
//		
//		switch(ch)
//		{
//						/* ǰ�� */
//			case '1': qianjin();break;
//						/* ���� */
//			case '2': houtui();break;
//						/* ��� */
//			case '3': zuoguai();break;
//						/* �ҹ� */
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


























