#include "stm32f10x.h"   // �൱��51��Ƭ���е�  #include <reg51.h>
#include "systick.h"
#include "usart.h"
#include "exti.h"
#include "led.h"

uint8_t ch = 1;
void qianjin(void);
void houtui(void);
void zuoguai(void);
void youguai(void);
void tingzhi(void);

int main(void)
{
	// ���������ʱ��ϵͳ��ʱ���Ѿ������ó�72M��

	
	LED1_GPIO_Config();																			//���ú�����װ�������ܿ顣
	
	EXTI_Key_Config();
	
	USART_Config();
	
	/*---------------------��ʼ��С������ǰ������Ĺ̶�----------------------------*/

		//����A2����
		GPIO_SetBits(Rwheel1_GPIO_PORT, Rwheel1_GPIO_PIN);							//������ת
		//GPIO_ResetBits(Rwheel1_GPIO_PORT, Rwheel1_GPIO_PIN);					//���ַ�ת		
		
			//������A4����
		//GPIO_SetBits(Lwheel2_GPIO_PORT, Lwheel2_GPIO_PIN);					  //���ַ�ת
		GPIO_ResetBits(Lwheel2_GPIO_PORT, Lwheel2_GPIO_PIN);						//������ת
		
	
	while(1)
	{
		
		
		GPIO_SetBits(LED1_GPIO_PORT, LED1_GPIO_PIN);							//GPIO_SetBits�������ø�GPIO�õף�ʹС�����������Ŀ��ܡ�
		GPIO_SetBits(LED2_GPIO_PORT, LED2_GPIO_PIN);							//GPIO_SetBits�������ø�GPIO�õף�ʹС�����������Ŀ��ܡ�

		//Delay(0xFFFFF);
		SysTick_Dwelay_us(50);
		
		
		GPIO_ResetBits(LED1_GPIO_PORT, LED1_GPIO_PIN);						//GPIO_ResetBits��������GPIO�øߣ���С�������
		GPIO_ResetBits(LED2_GPIO_PORT, LED2_GPIO_PIN);						//GPIO_ResetBits��������GPIO�øߣ���С�������		
		//Delay(0xFFFFF);
		SysTick_Dwelay_us(50);
		
		
/*-------------------------------���ڵ���---------------------------------*/		


  		ch = getchar();
		
			printf("ch = %c",ch);
			
			if(ch != 0)
			{
				switch(ch)
				{
						/* ǰ�� */
					case '1':qianjin(); break;
						/* ���� */
					case '2':  houtui();break;
						/* ��� */
					case '3': zuoguai();break;
						/* �ҹ� */
					case '4': youguai();break;
						/* ֹͣ */
					case '5':tingzhi();break;
					default : break;
				}
				
			}
			
	}
	
} 
	

void qianjin(void)
{
		GPIO_SetBits(Rwheel1_GPIO_PORT, Rwheel1_GPIO_PIN);							//������ת
		GPIO_ResetBits(Lwheel2_GPIO_PORT, Lwheel2_GPIO_PIN);						//������ת
}
void houtui(void)
{
		GPIO_ResetBits(Rwheel1_GPIO_PORT, Rwheel1_GPIO_PIN);						//���ַ�ת		
		GPIO_SetBits(Lwheel2_GPIO_PORT, Lwheel2_GPIO_PIN);				 	 	 //���ַ�ת
}
void zuoguai(void)
{
		GPIO_ResetBits(Rwheel1_GPIO_PORT, Rwheel1_GPIO_PIN);				  	//���ַ�ת		
		GPIO_ResetBits(Lwheel2_GPIO_PORT, Lwheel2_GPIO_PIN);						//������ת
}
void youguai(void)
{
		GPIO_SetBits(Lwheel2_GPIO_PORT, Lwheel2_GPIO_PIN);					     //���ַ�ת
		GPIO_SetBits(Rwheel1_GPIO_PORT, Rwheel1_GPIO_PIN);							//������ת
}
void tingzhi(void)
{
	GPIO_ResetBits(LED1_GPIO_PORT, LED1_GPIO_PIN);						//GPIO_ResetBits��������GPIO�øߣ���С�������
	GPIO_ResetBits(LED2_GPIO_PORT, LED2_GPIO_PIN);						//GPIO_ResetBits��������GPIO�øߣ���С�������		
	while(1)
	{
		ch = getchar();
		if(ch != '0' && ch != '5' )
		{
			break;
		}

	}
}

























