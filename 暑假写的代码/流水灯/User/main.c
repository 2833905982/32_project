#include "stm32f10x.h"   // �൱��51��Ƭ���е�  #include <reg51.h>
#include "bsp_systick.h"
#include "liushuideng.h"
#include "bsp_usart.h"
#include "key.h"
#include "led.h"


int main(void)
{
	// ���������ʱ��ϵͳ��ʱ���Ѿ������ó�72M��
	
	uint16_t i = 1;
	LED_GPIO_Config();
	KEY_GPIO_Config();
	USART_Config();
	
	
	ximie();//Ϩ������С�ƣ���ֹ����
	
	printf( "����printf��������\n" );
	
		GPIO_ResetBits(LED1_GPIO_PORT,LED1_GPIO_PIN);
		SysTick_Delay_ms(100);
//		GPIO_SetBits(LED1_GPIO_PORT,LED1_GPIO_PIN);
//		SysTick_Delay_ms(100);
	
//	while(1)
//	{
//		if(Key_Scan(KEY1_GPIO_PORT,KEY1_GPIO_PIN)==0)
//		{
//			i++;
//		}
//		printf("i1=%d\n",i);
//		if(i==1)
//		{
//				R_liushuideng();
//		}
//		printf("i2=%d\n",i);
//		if(i==2)
//		{
//				L_liushuideng();
//		}
//		printf("i3=%d\n",i);
//		if(i==3)
//		{
//				R_liushuideng();
//				L_liushuideng();
//		}
//		if(i>3)
//		{
//			i=1;
//		}

//	}
//	
	
}


