#include "stm32f10x.h"   // �൱��51��Ƭ���е�  #include <reg51.h>
#include "bsp_systick.h"
#include "liushuideng.h"
#include "stm32f10x_it.h"
#include "bsp_usart.h"
//#include "key.h"
#include "led.h"
#include "exti.h"

uint16_t i=0;

int main(void)
{
	// ���������ʱ��ϵͳ��ʱ���Ѿ������ó�72M��
		EXTI_Key_Config();
	LED_GPIO_Config();
//	KEY_GPIO_Config();
	USART_Config();

	
	ximie();//Ϩ������С�ƣ���ֹ����
	
	printf( "����printf��������\n" );
	
	while(1)
	{
			
		if(i==1)
		{
				R_liushuideng();
		}

		if(i==2)
		{
				L_liushuideng();
		}

		if(i==3)
		{
				R_liushuideng();
				L_liushuideng();
		}
		if(i==4)
		{
				dan_shan();
		}
		if(i>4)
		{
			i=1;
		}

	}
	
	
}


