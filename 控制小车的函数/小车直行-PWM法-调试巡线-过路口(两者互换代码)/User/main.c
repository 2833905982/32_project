#include "stm32f10x.h"   // �൱��51��Ƭ���е�  #include <reg51.h>
#include "bsp_GeneralTim.h" 
#include "systick.h"
#include "jiaodu.h"
#include "usart.h"
#include "huidu.h"
#include "bsp-gpio.h"
#include "exti.h"


uint16_t i = 0;
int main(void)
{
	//uint8_t ch;
	
	/* ��ʼ�� GPIO�� */
	LUN_GPIO_Config();
	
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
		//stop();
	
	while(1)
	{
		
		//�����Ҷ�
		if(scan (HUI1_GPIO_PORT,HUI1_GPIO_PIN) == ON && scan (HUI2_GPIO_PORT,HUI2_GPIO_PIN) == OFF)
		{
			turn_left(25);
		}
		//����һҶ�
		if(scan (HUI2_GPIO_PORT,HUI2_GPIO_PIN) == ON && scan (HUI1_GPIO_PORT,HUI1_GPIO_PIN) == OFF)
		{
			turn_right(25);
		}
		if(scan (HUI2_GPIO_PORT,HUI2_GPIO_PIN) == OFF && scan (HUI1_GPIO_PORT,HUI1_GPIO_PIN) == OFF)
		{
			qian_jin();		
		}
		if(scan (HUI2_GPIO_PORT,HUI2_GPIO_PIN) == ON && scan (HUI1_GPIO_PORT,HUI1_GPIO_PIN) == ON)
		{
			qian_jin();	
		}
//   if(/*scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON  &&*/ scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
//		{
//			i++;
//			
//			if(i>=5) 
//			{
//			//	break;
//				while(1)
//				{
//					stop();
//				}
//			}
//			while(1)
//			{
//				qian_jin();
//				if(/*scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == OFF  &&*/ scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == OFF )
//				{
//					break;
//				}
//			}
//		}
							if(/* scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON  && */ scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON )
						{
							i++;

							while(1)
							{
								if(/* scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == OFF && */scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == OFF)
								{
									qian_jin();
									printf("i=%d \n",i);
									SysTick_Dwelay_ms(1000);					
									break;
								}
							}
						}
								if(i>=5)
							{
								i=0;
								stop();
								printf("xiaozhazha");
								SysTick_Dwelay_ms(1000);
								SysTick_Dwelay_ms(1000);
								SysTick_Dwelay_ms(1000);
								SysTick_Dwelay_ms(1000);
								SysTick_Dwelay_ms(1000);
								SysTick_Dwelay_ms(1000);
								SysTick_Dwelay_ms(1000);
								break;
							}

			
			printf("i=%d",i);
			SysTick_Dwelay_ms(100);
	}
}
	





//if(/* scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON  && */ scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON )
//		{
//			i++;

//			while(1)
//			{
//				if(/* scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == OFF && */scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == OFF)
//				{
//					qian_jin();
//					printf("i=%d \n",i);
//					SysTick_Dwelay_ms(1000);					
//					break;
//				}
//			}
//		}
//		if(i>=5)
//			{
//				i=0;
//				stop();
//				printf("xiaozhazha");
//				SysTick_Dwelay_ms(1000);
//				SysTick_Dwelay_ms(1000);
//				SysTick_Dwelay_ms(1000);
//				SysTick_Dwelay_ms(1000);
//				SysTick_Dwelay_ms(1000);
//				SysTick_Dwelay_ms(1000);
//				SysTick_Dwelay_ms(1000);
//				break;
//			}
//	}
//	/*�����������λ��*/
//	while(1)
//	{		
//		xunji();
//		if(/*scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON && */scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
//		{
//			stop();
//			SysTick_Dwelay_ms(1000);
//			SysTick_Dwelay_ms(1000);
//			SysTick_Dwelay_ms(1000);
//			SysTick_Dwelay_ms(1000);
//			SysTick_Dwelay_ms(1000);
//			SysTick_Dwelay_ms(1000);
//			SysTick_Dwelay_ms(1000);
//			break;
//		}
//	}
//	

///*��ɫʶ�𣬼���������������������ɫʶ��ģ�飬ʶ����ǰ����ʲô��ɫ
//���Ұ���Ӧ�����ŵ�ָ��λ��*/
//	
//	
//	/*�����⵽������ɫ����ɫ*/
//	if(TCS230_Distinguish2()==1)
//	{
//		qian_jin();
//		SysTick_Dwelay_ms(1000);//ǰ��һ��Ϊ��ʹ���߹�����
//			
//		while(1)
//		{
//			xunji();
//			
//			//������һ�������ߵĵ�����С��ͣ��һ��,���Ҵ˽׶�Ѱ������
//			if(/*scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == OFF &&*/ scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == OFF)
//			{
//				stop();
//				SysTick_Dwelay_ms(1000);
//				SysTick_Dwelay_ms(1000);
//				SysTick_Dwelay_ms(1000);
//				SysTick_Dwelay_ms(1000);
//				SysTick_Dwelay_ms(1000);
//				
//				break;
//			}
//		}
