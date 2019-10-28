#include "stm32f10x.h"   // �൱��51��Ƭ���е�  #include <reg51.h>
#include "bsp_GeneralTim.h" 
#include "systick.h"
#include "jiaodu.h"
#include "usart.h"
#include "huidu.h"
#include "bsp-gpio.h"
#include "exti.h"
#include "color.h"
#include "weidai.h"
#include "xunji.h"

uint16_t i = 0;


//��ע����Ҫ��Ѱ�������ŵ�while(1)�У�ʹ��һֱѰ��

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
	
	printf("����,���!");
	
	/*��һ�Ѷ��ǳ�ʼ����ɫʶ��ģ���*/
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
	
	

//	
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
		if(/* scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON  && */ scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON )
		{
			i++;
			SysTick_Dwelay_ms(200);
			while(1)
			{
				qian_jin();				
				if(/* scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == OFF && */scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == OFF)
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
	}
	/*�����������λ��*/
	while(1)
	{		
		xunji();
		if(/*scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON && */scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
		{
			stop();
			SysTick_Dwelay_ms(1000);
			SysTick_Dwelay_ms(1000);
			SysTick_Dwelay_ms(1000);
			SysTick_Dwelay_ms(1000);
			SysTick_Dwelay_ms(1000);
			SysTick_Dwelay_ms(1000);
			SysTick_Dwelay_ms(1000);
			break;
		}
	}
	

/*��ɫʶ�𣬼���������������������ɫʶ��ģ�飬ʶ����ǰ����ʲô��ɫ
���Ұ���Ӧ�����ŵ�ָ��λ��*/
	
	/*�����⵽������ɫ����ɫ*/
	if(TCS230_Distinguish2()==1)
 	{
		printf("��ɫ��\n");
		qian_jin();
		SysTick_Dwelay_ms(1000);//ǰ��һ��Ϊ��ʹ���߹�����
			
		while(1)
		{
			xunji();
			
			//������һ�������ߵĵ�����С��ͣ��һ��,���Ҵ˽׶�Ѱ������
			if(/*scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == OFF &&*/ scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == OFF)
			{
				stop();
				SysTick_Dwelay_ms(1000);
				SysTick_Dwelay_ms(1000);
				SysTick_Dwelay_ms(1000);
				SysTick_Dwelay_ms(1000);
				SysTick_Dwelay_ms(1000);
				
				break;
			}
		}
		turn_left(250);//����ת��90��,�������Ż���Ѳ��Ѳ�ߣ�����250Ϊ90�ȣ�
		SysTick_Dwelay_ms(10);
		
		while(1)
		{
			xunji();
			
			/*��ʱֻ��һ���Ҷȿ��Լ��·�ڣ���Ҫ������·�ڿ��Ե�����ɫ������*/
			if(scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
			{
				i++;
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
				SysTick_Dwelay_ms(1000);
				SysTick_Dwelay_ms(1000);
				SysTick_Dwelay_ms(1000);
				SysTick_Dwelay_ms(1000);
				SysTick_Dwelay_ms(1000);
				break;
			}
		}	
		
			/*����ǰ��һ��·�ڵ���A��������ʶ��A����ɫ���ź���*/
		while(1)
		{
			xunji();
			
			//�������A��������
			if(/* scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON &&  */ scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
			{
				stop();
				SysTick_Dwelay_ms(100);
				SysTick_Dwelay_ms(100);
				SysTick_Dwelay_ms(100);
				SysTick_Dwelay_ms(100);
				SysTick_Dwelay_ms(100);
				SysTick_Dwelay_ms(100);
				break;//��һ�׶ν�����
			}
		}
		
				/*��ʼʶ����ɫ�����A����Ǻ�ɫ,
				������ǰ�ߣ�������·�ڣ�����������λ�ã���ת90��
		    ֮����ǰ�ߣ������ɫλ�ã�֮���˻���*/
				if(TCS230_Distinguish2()==3)
				{
					qian_jin();
					SysTick_Dwelay_ms(50);//��ʱ50ms�ûҶȹ�A���ں���
					while(1)
					{
						xunji();
						if(/*scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON && */scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
						{
							stop();
							SysTick_Dwelay_ms(1000);
							SysTick_Dwelay_ms(1000);
							SysTick_Dwelay_ms(1000);
							SysTick_Dwelay_ms(1000);
							SysTick_Dwelay_ms(1000);
							SysTick_Dwelay_ms(1000);
							break;//����������·��
						}
					}
					/*������С���Ѿ��ص�������·��
					��һ�����ɫ������������*/
					
					turn_left(250);//����ת��90��
					SysTick_Dwelay_ms(10);
					
					/*С���������������ߵ���ɫ������*/
					while(1)
					{
						xunji();
						SysTick_Dwelay_ms(50);//������ʱ��Ŀ����ʹС�����԰�ȫ��ȥ�����ͽ��������Ӱ��
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
							SysTick_Dwelay_ms(1000);
							SysTick_Dwelay_ms(1000);
							SysTick_Dwelay_ms(1000);
							SysTick_Dwelay_ms(1000);
							SysTick_Dwelay_ms(1000);
							break;
						}
					}
					/*���������Ҫ�ں���ӻҶȣ�ʹ�����ʱҲ����Ѱ����
					����Ѱ�������������ĵ�λ��ͣ����*/
					houtui();
					
					/*֮�����ҹ�90��,��ʼѲ�ߣ�������·�ڣ���E���Ƶ���ɫ����*/
					turn_right(250);
					SysTick_Dwelay_ms(10);
					while(1)
					{
						xunji();
						SysTick_Dwelay_ms(50);//������ʱ��Ŀ����ʹС�����԰�ȫ��ȥ�����ͽ��������Ӱ��
						
						if(/*scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON && */scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
						{
							i++;
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
							SysTick_Dwelay_ms(1000);
							SysTick_Dwelay_ms(1000);
							SysTick_Dwelay_ms(1000);
							SysTick_Dwelay_ms(1000);
							SysTick_Dwelay_ms(1000);
							SysTick_Dwelay_ms(1000);
							break;
						}
					}//����һ��֮������Ѿ����Ƶ�����ɫ����
					
					
					/*Ȼ����˻ص����ĵ㣬������ת��ʮ�ȣ�
					���˻ص���ʼλ�ã��˴����*/
					
					houtui();//����ҲҪ�ûҶ�Ѱ�����ж�·�ڣ�ʹ����Ե������ĵ�
					turn_left(250);
					houtui();//�ص���ʼλ��	
					
				}
				/*ʶ����ɫ�����AΪ��ɫ*/
				if(TCS230_Distinguish2()==5)
				{
					while(1)
					{
						xunji();
						SysTick_Dwelay_ms(50);//������ʱ��Ŀ����ʹС����ȫ��ȥA�㴦�Ľ���
						
						//��������е�
						if(/*scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON && */ scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
						{
							stop();
							SysTick_Dwelay_ms(50);
							break;
						}
					}
					turn_left(250);//��ת90��
					SysTick_Dwelay_ms(10);
					qian_jin();
					SysTick_Dwelay_ms(50);//ǰ��һ���ֹ����Ӱ��
					
					while(1)
					{
						xunji();
						if(/* scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON && */ scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
						{
							i++;
							while(1)
							{
								qian_jin();
								if(/* scan ( HUI3_GPIO_PORT,HUI3_GPIO_PIN) == OFF && */ scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == OFF)//���˺���
									break;
							}
						}
						if(i>=2)
						{
							i=0;
							stop();
							SysTick_Dwelay_ms(10);
							break;
						}
					}//��һ��������С���ߵ��˺�ɫ�ķ�����
					
					/*��һ����С���Ӻ�ɫ���ߵ���ɫ��*/
					turn_right(250);//��ת90��
					while(1)
					{
						xunji();
						if(scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
						{
							i++;
							while(1)
							{
								if(scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == OFF)
									break;
							}
						}
						if(i==2)
							{
								i=0;
								stop();
								SysTick_Dwelay_ms(10);
								break;
							}
					}//��ʱС���Ѿ�������ɫ������
					SysTick_Dwelay_ms(50);
					
					/*��һ����Ϊ����С������ɫ����������E��*/
					while(1)
					{
						xunji();
						if(/*scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON &&  */ scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
						{
							stop();
							SysTick_Dwelay_ms(10);//����E��
							break;
						}
					}
					/*,Ȼ���E�͵���ɫ������*/
					while(1)
					{
						qian_jin();
						SysTick_Dwelay_ms(50);//�����Ŀ����ʹС����ȫ�ȹ�����E������Ӱ��
						if(/* scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON &&  */ scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
						{
							stop();
							SysTick_Dwelay_ms(50);//�����������ĵ�
							break;//��һ�׶ε�Ѱ��������
						}
					}
					/*������ʹС�����Դ����������ĵ㵽���ɫ������*/
					turn_right(250);
					SysTick_Dwelay_ms(10);
					
					qian_jin();
					SysTick_Dwelay_ms(50);//ʹС��������Ӱ��ĺ���
					while(1)
					{
						xunji();
						if(/* scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON &&  */scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
						{
							i++;
							while(1)
							{
								qian_jin();
								if(/* scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == OFF &&  */ scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == OFF)
									break;
							}
						}
						if(i==2)
						{
							i=0;
							stop();
							SysTick_Dwelay_ms(50);
							break;
						}
					}//������С���Ѿ������˺�ɫ��������
					
					/*С���˻ص�������*/
					houtui();
					//�˴ΰ��˽���
				}
		}										
		/*�����⵽��C��ɫ�Ǻ�ɫ*/
	if(TCS230_Distinguish2()==3)
	{
		qian_jin();
		SysTick_Dwelay_ms(10);//ǰ��һ��Ϊ��ʹ���߹�����
		//�����ŵ���ɫ����
		while(1)
		{
			xunji();
			if(/* scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == OFF &&  */ scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
			{
				stop();
				break;
			}
		}
			//�˻��������ĵ�
		houtui();
		
		turn_left(250);
		//ǰ����A��
		while(1)
		{
			xunji();
			if(/* scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == OFF &&  */ scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
			{
				stop();
				break;
			}
		}
		
		/*���AΪ��ɫ*/
		if(TCS230_Distinguish2()==1)
		{
			qian_jin();
			SysTick_Dwelay_ms(10);//ǰ��һ��Ϊ��ʹ���߹�����
			while(1)
			{	
				xunji();
				if(/* scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == OFF &&  */  scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
				{
					stop();
					break;
				}
			}
			//�˻ص�������
			houtui();
			//������ת90�ȣ���ת90��
			turn_right(250);
			SysTick_Dwelay_ms(10);
			turn_right(250);
			SysTick_Dwelay_ms(10);
			
			//��EΪ��ɫ,С��������E��
			while(1)
			{
				xunji();
				if(/* scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == OFF &&  */  scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON)
				{
					i++;
					while(1)
					{
						if(/* scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == OFF &&  */ scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == OFF)
						{
							stop();
							SysTick_Dwelay_ms(10);
							break;//������ָ�Ѿ�������E��
						}
					}
				}
				if(i==2)//С���Ѿ���������ɫ������
					{
						i=0;
						stop();
						SysTick_Dwelay_ms(10);
						break;
					}
				}
			//���˻��������ĵ�
				houtui();
			//�������ĵ����ת90��
				turn_left(250);
			//���˻ص�������
				houtui();		
	}
	
}

}
