#include "stm32f10x.h"
#include "bsp_led.h"
#include "systick.h"
#include "exti.h"
#include "base.h"
#include "color.h"
#include "weidai.h"
#include "usart.h"
#include "bsp_GeneralTim.h"
#include "bsp-gpio.h"
#include "huidu.h"
#include "jiaodu.h"
#include "xunji.h"


uint16_t i = 0;

void green(void)
{
	/*�����⵽������ɫ����ɫ*/
		printf("��ɫ��\n");
		qian_jin();
	qian_jin();
	qian_jin();
	qian_jin();
	
//		SysTick_Dwelay_ms(1000);//ǰ��һ��Ϊ��ʹ���߹�����
		delay_ms(1000);	
		while(1)
		{
			xunji();
			
			//������һ�������ߵĵ�����С��ͣ��һ��,���Ҵ˽׶�Ѱ������
			if(/*scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == OFF &&*/ scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
			{
				stop();
				delay_ms(1000);
				delay_ms(1000);
				
				delay_ms(1000);
				
				break;
			}
		}
		turn_left(1000);//����ת��90��,�������Ż���Ѳ��Ѳ��
		//SysTick_Dwelay_ms(10);
		delay_ms(1000);
		while(1)
		{
			xunji();
			
			/*��ʱֻ��һ���Ҷȿ��Լ��·�ڣ���Ҫ������·�ڿ��Ե�����ɫ������*/
			if(scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
			{
					i++;
					delay_ms(200);
					while(1)
					{
						qian_jin();
						if(scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == OFF)//���˺���
							break;
					}
			}
			if(i>=2)//����ʱ������ɫ������,��һ�׶�Ѱ������
			{
				i=0;
				stop();
				delay_ms(1000);
				delay_ms(1000);
				delay_ms(1000);
				delay_ms(1000);
				delay_ms(1000);
				break;
			}
		}	
			turn_left(1000);//����ת��90��,�������Ż���Ѳ��Ѳ��
			//SysTick_Dwelay_ms(10);
			delay_ms(1200);
		
			/*����ǰ��һ��·�ڵ���A��������ʶ��A����ɫ���ź���*/
		while(1)
		{
			xunji();
			//�������A��������
			if(/* scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON &&  */ scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
			{
					stop();
					delay_ms(1000);
					delay_ms(1000);
					delay_ms(1000);
					break;//��һ�׶ν�����
			}
		}
		
		
		
				/*��ʼʶ����ɫ�����A����Ǻ�ɫ,
				������ǰ�ߣ�������·�ڣ�����������λ�ã���ת90��
		 		֮����ǰ�ߣ������ɫλ�ã�֮���˻���*/
		i=0;
		while(1)
		{
			/* ���Ϊ��ɫ����ִ�д˺��� */
			if(TCS230_Distinguish2()==3)
				{
					qian_jin();
					qian_jin();
					qian_jin();
					qian_jin();													
					delay_ms(1000);				//��ʱ50ms�ûҶȹ�A���ں���
					while(1)
					{
						xunji();
						delay_ms(100);
						if(/*scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON && */scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
						{
							i++;
							delay_ms(200);
							while(1)
							{
								qian_jin();
								if(/*scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON && */scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == OFF)
								break;
							}
						}
							if(i>=2)
							{
								i=0;
								stop();
								delay_ms(1000);
								delay_ms(1000);
								delay_ms(1000);
								delay_ms(1000);
								delay_ms(1000);	
							break;//����������·��								
							}
					}
					/*������С���Ѿ��ص�������·��
					��һ�����ɫ������������*/
					
					turn_left(1000);//����ת��90��
					delay_ms(1000);
					
					/*С���������������ߵ���ɫ������*/
					while(1)
					{
						xunji();
						
						//������ʱ��Ŀ����ʹС�����԰�ȫ��ȥ�����ͽ��������Ӱ��
						delay_ms(100);
						
						if(/*scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON && */scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
						{
							i++;
							while(1)
							{
								qian_jin();
								if(/*scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == OFF &&*/ scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == OFF)//���˺���
									break;
							}
						}
						if(i>=2)
						{
							i=0;
							stop();
							delay_ms(1000);
							delay_ms(1000);						
							delay_ms(1000);
							delay_ms(1000);
							delay_ms(1000);
							break;
						}
					}
					/*���������Ҫ�ں���ӻҶȣ�ʹ�����ʱҲ����Ѱ����
					����Ѱ�������������ĵ�λ��ͣ����*/

						back();
						back();
						back();
						back();
						delay_ms(1000);	
					while(1)
					{
						back_xunji();
						if(/*scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON && */scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
						{
							i++;
							delay_ms(200);	
							while(1)
							{
								back();
								back_xunji();
								if(/*scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON && */scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == OFF)
								break;
							}
						}
						if(i>=3)
						{
								i=0;
								stop();
								delay_ms(1000);
								delay_ms(1000);
								delay_ms(1000);
								delay_ms(1000);
								delay_ms(1000);	
							break;//����������·��		
						}
					}
					/*֮�����ҹ�90��,��ʼѲ�ߣ�������·�ڣ���E���Ƶ���ɫ����*/
					turn_right(1000);
					delay_ms(600);
					while(1)
					{
						xunji();
						delay_ms(100);					//������ʱ��Ŀ����ʹС�����԰�ȫ��ȥ�����ͽ��������Ӱ��					
						if(/*scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON && */scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
						{
							i++;
							delay_ms(200);
							while(1)
							{
								qian_jin();
								if(/*scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == OFF && */scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == OFF)//���˺���
									break;
							}
						}
						if(i>=2)
						{
							i=0;
							stop();
              delay_ms(1000);
							delay_ms(1000);
							delay_ms(1000);
							delay_ms(1000);
							delay_ms(1000);
							delay_ms(1000);
							
							break;
						}
					}//����һ��֮������Ѿ����Ƶ�����ɫ����

					
					/*Ȼ����˻ص����ĵ㣬������ת��ʮ�ȣ�
					���˻ص���ʼλ�ã��˴����*/
					
					back();//����ҲҪ�ûҶ�Ѱ�����ж�·�ڣ�ʹ����Ե������ĵ�
					back();
					back();
					back();
					while(1)
					{
						back_xunji();
						if(/*scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON && */scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
						{
							i++;
							delay_ms(500);	
							while(1)
							{
								back();
								if(/*scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON && */scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == OFF)
								break;
							}
						}
					if(i>=3)
					{
						i=0;
						stop();
						delay_ms(1000);
						delay_ms(1000);
						delay_ms(1000);
						delay_ms(1000);
						delay_ms(1000);
						delay_ms(1000);
						break;						
					}
				}
					turn_right(1000);
					delay_ms(850);
					
					qian_jin();
					qian_jin();
					qian_jin();
					qian_jin();													
					delay_ms(1000);				
					
					while(1)
					{
						xunji();
						delay_ms(100);
						if(/*scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON && */scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
						{
							i++;
							delay_ms(200);
							while(1)
							{
								qian_jin();
								if(/*scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON && */scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == OFF)
								break;
							}
						}
							if(i>=4)
							{
								i=0;
								stop();
								delay_ms(1000);
								delay_ms(1000);
								delay_ms(1000);
								delay_ms(1000);
								delay_ms(1000);	
							break;//����������·��								
							}
					}
					//�ص���ʼλ��	
					break;
					
				}
		}//��while
	}//����
//				/*ʶ����ɫ�����AΪ��ɫ*/
//				if(TCS230_Distinguish2()==5)
//				{
//					qian_jin();
//					qian_jin();
//					qian_jin();
//					qian_jin();													
//					delay_ms(1000);				//��ʱ1000ms�ûҶȹ�A���ں���								
//					while(1)
//					{
//						xunji();
//						delay_ms(1000);    //������ʱ��Ŀ����ʹС����ȫ��ȥA�㴦�Ľ���						
//						//��������е�
//						if(scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
//						{
//							stop();
//							delay_ms(50);
//							break;
//						}
//					}
//					turn_left(1000);//��ת90��
//					delay_ms(1000);
//					qian_jin();
//					//SysTick_Dwelay_ms(50);//ǰ��һ���ֹ����Ӱ��
//					delay_ms(50);
//					
//					while(1)
//					{
//						xunji();
//						if(/* scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON && */ scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
//						{
//							i++;
//							while(1)
//							{
//								qian_jin();
//								if(/* scan ( HUI3_GPIO_PORT,HUI3_GPIO_PIN) == OFF && */ scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == OFF)//���˺���
//									break;
//							}
//						}
//						if(i>=2)
//						{
//							i=0;
//							stop();
//							//SysTick_Dwelay_ms(10);
//							delay_ms(50);
//							break;
//						}
//					}//��һ��������С���ߵ��˺�ɫ�ķ�����
//					
//					/*��һ����С���Ӻ�ɫ���ߵ���ɫ��*/
//					turn_right(250);//��ת90��
//					while(1)
//					{
//						xunji();
//						if(scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
//						{
//							i++;
//							while(1)
//							{
//								if(scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == OFF)
//									break;
//							}
//						}
//						if(i==2)
//							{
//								i=0;
//								stop();
//								//SysTick_Dwelay_ms(10);
//								delay_ms(50);
//								break;
//							}
//					}//��ʱС���Ѿ�������ɫ������
//				//	SysTick_Dwelay_ms(50);
//					delay_ms(50);
//					
//					
//					
//					
//					
//					/*��һ����Ϊ����С������ɫ����������E��*/
//					while(1)
//					{
//						xunji();
//						if(/*scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON &&  */ scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
//						{
//							stop();
//							//SysTick_Dwelay_ms(10);//����E��
//							delay_ms(50);
//							break;
//						}
//					}
//					/*,Ȼ���E�͵���ɫ������*/
//					while(1)
//					{
//						qian_jin();
//						delay_ms(50);
//						//SysTick_Dwelay_ms(50);//�����Ŀ����ʹС����ȫ�ȹ�����E������Ӱ��
//						if(/* scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON &&  */ scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
//						{
//							stop();
//							delay_ms(50);
//							//SysTick_Dwelay_ms(50);//�����������ĵ�
//							break;//��һ�׶ε�Ѱ��������
//						}
//					}
//					/*������ʹС�����Դ����������ĵ㵽���ɫ������*/
//					turn_right(250);
//					delay_ms(50);
//				//	SysTick_Dwelay_ms(10);
//					
//					qian_jin();
//					delay_ms(50);
//					//SysTick_Dwelay_ms(50);//ʹС��������Ӱ��ĺ���
//					while(1)
//					{
//						xunji();
//						if(/* scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON &&  */scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
//						{
//							i++;
//							while(1)
//							{
//								qian_jin();
//								if(/* scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == OFF &&  */ scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == OFF)
//									break;
//							}
//						}
//						if(i==2)
//						{
//							i=0;
//							stop();
//							delay_ms(50);
//							//SysTick_Dwelay_ms(50);
//							break;
//						}
//					}//������С���Ѿ������˺�ɫ��������
//					
//					/*С���˻ص�������*/
//					back();
//					//�˴ΰ��˽���
//					break;
//				}
//		}
//	}		
//	

int main (void)
{
	//uint8_t ch;
	
	/* ��ʼ�� GPIO�� */
	LUN_GPIO_Config();
	
	/* ��ʼ������ */
//	EXTI_Key_Config();
	
	/* ��ʼ�� PWM */
	GENERAL_TIM_Init();
	 
 
	/* ��ʼ������ */
	USART_Config();
	
	/* ��ʼ���Ҷ� */
	huidu ();
	
	
	/*��ɫ*/
	TIM2_Configuration();
	TIM2_NVIC_Configuration();
	Color2_GPIO_Config();
	EXTI2_NVIC_Configuration();
	EXTI_PG2_Config();
	color_Init();
	TCS230_Start2();
	EXTI_PG2_Config_on();
	EXTI_PG2_Config_off();
	USART_Config();
	SysTick_Init();
	
	
	printf("color");
	
	//	/*---------------------��ʼ��С������ǰ������Ĺ̶�----------------------------*/

//	/* ����A2���� */
	GPIO_SetBits(Rwheel1_GPIO_PORT, Rwheel1_GPIO_PIN);											//������ת
//	//GPIO_ResetBits(Rwheel1_GPIO_PORT, Rwheel1_GPIO_PIN);									//���ַ�ת
//		
//	/* ������A4���� */
//	//GPIO_SetBits(Lwheel2_GPIO_PORT, Lwheel2_GPIO_PIN);					  				//���ַ�ת
	GPIO_ResetBits(Lwheel2_GPIO_PORT, Lwheel2_GPIO_PIN);										//������ת
//

/*����������ǰ��Ѱ�����ж�·��*/
	while(1)
	{
		xunji();
		if( scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON )
		{
			i++;
			delay_ms(200);
			while(1)
			{
				qian_jin();				
				if(scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == OFF)
				{

					printf("i=%d \n",i);
					break;
				}
			}
		}
		if(i>=5)
			{
				i=0;
				stop();
				delay_ms(1000);
				delay_ms(1000);
				delay_ms(1000);
				delay_ms(1000);				
				break;
			}
	}
	/*�����������λ��*/
	while(1)
	{		
		xunji();
		if(scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
		{
			stop();
			delay_ms(1000);
			delay_ms(1000);
			delay_ms(1000);
			break;
		}
	}
	
	
	
	while(1)
	{		
		switch(TCS230_Distinguish2())
		{
			case 1:green();break;
			case 2:printf(" ��ɫ \n");break;
			case 3:printf(" ��ɫ \n");break;
			case 4:printf(" ��ɫ \n");break;		
			case 5:printf(" ��ɫ \n");break;
			case 0:printf(" ��֪ \n");break;										
		}delay_s(1);
	}
}

	
