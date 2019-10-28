#include "stm32f10x.h"   				// �൱��51��Ƭ���е�  #include <reg51.h>
#include "bsp_GeneralTim.h" 
#include "systick.h"
#include "usart.h"
#include "huidu.h"
#include "exti.h"
#include "led.h"

void qianjin(void);
void houtui(void);
void zuoguai(void);
void youguai(void);

//uint16_t i = 0;
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
	
	/* ��ʼ���Ҷ� */
	huidu ();
	
	printf("��ã������ˣ�");

	
	/*---------------------��ʼ��С������ǰ������Ĺ̶�----------------------------*/

		/* ����A2���� */
		GPIO_SetBits(Rwheel1_GPIO_PORT, Rwheel1_GPIO_PIN);											//������ת
		//GPIO_ResetBits(Rwheel1_GPIO_PORT, Rwheel1_GPIO_PIN);									//���ַ�ת
		
		/* ������A4���� */
		//GPIO_SetBits(Lwheel2_GPIO_PORT, Lwheel2_GPIO_PIN);					  				//���ַ�ת
		GPIO_ResetBits(Lwheel2_GPIO_PORT, Lwheel2_GPIO_PIN);										//������ת
		
	
	while(1)
	{
		
		//�����Ҷ�
		if(scan (HUI1_GPIO_PORT,HUI1_GPIO_PIN) == ON && scan (HUI2_GPIO_PORT,HUI2_GPIO_PIN) == OFF )
		{
			//LED1;
			TIM_SetCompare3(TIM3,0);																		//���� BO�������ֵĿ���
			TIM_SetCompare4(TIM3,50);																			//���� B1�������ֵĿ���
//			SysTick_Dwelay_us(50);
//										
//			GPIO_ResetBits(Lwheel2_GPIO_PORT, Lwheel2_GPIO_PIN);										//������ת
//			GPIO_ResetBits(Rwheel1_GPIO_PORT, Rwheel1_GPIO_PIN);										//���ַ�ת
////			printf("zhazhilaile!\n");
////			SysTick_Dwelay_ms(100);
		}

		//����һҶ�
		if(scan (HUI2_GPIO_PORT,HUI2_GPIO_PIN) == ON && scan (HUI1_GPIO_PORT,HUI1_GPIO_PIN) == OFF )
		{
			//LED1;
			TIM_SetCompare3(TIM3,50);																									//���� BO�������ֵĿ���
			TIM_SetCompare4(TIM3,0);																									//���� B1�������ֵĿ���
//			SysTick_Dwelay_us(250);
////			//LED2;
////			GPIO_SetBits(Lwheel2_GPIO_PORT, Lwheel2_GPIO_PIN);					  					//���ַ�ת
////			GPIO_SetBits(Rwheel1_GPIO_PORT, Rwheel1_GPIO_PIN);											//������ת

////			printf("��������!\n");
////			SysTick_Dwelay_ms(100);
		}
		if(scan (HUI2_GPIO_PORT,HUI2_GPIO_PIN) == OFF && scan (HUI1_GPIO_PORT,HUI1_GPIO_PIN) == OFF)
		{
			
			TIM_SetCompare3(TIM3,50);																									//���� BO�������ֵĿ���
			TIM_SetCompare4(TIM3,50);																									//���� B1�������ֵĿ���
//			SysTick_Dwelay_us(250);
//			GPIO_SetBits(Rwheel1_GPIO_PORT, Rwheel1_GPIO_PIN);											//������ת
//			GPIO_ResetBits(Lwheel2_GPIO_PORT, Lwheel2_GPIO_PIN);										//������ת
//			printf("���ͣ�\n");
//			SysTick_Dwelay_ms(100);			
		}
		if(scan (HUI2_GPIO_PORT,HUI2_GPIO_PIN) == ON && scan (HUI1_GPIO_PORT,HUI1_GPIO_PIN) == ON)
		{
			TIM_SetCompare3(TIM3,50);																									//���� BO�������ֵĿ���
			TIM_SetCompare4(TIM3,50);																									//���� B1�������ֵĿ���
	//		i++;
//			GPIO_SetBits(Rwheel1_GPIO_PORT, Rwheel1_GPIO_PIN);											//������ת
//			GPIO_ResetBits(Lwheel2_GPIO_PORT, Lwheel2_GPIO_PIN);										//������ת
////			printf("�������\n");			
////			SysTick_Dwelay_ms(100);			
		}

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


























