// TIM��ͨ��-����-�������� Ӧ��
#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_usart.h"
#include "bsp_GeneralTim.h"  

/**
  * @brief  ������
  * @param  ��  
  * @retval ��
  */
int main(void)
{
	
	/* ���ڳ�ʼ�� */
	USART_Config();
	
	/* ��ʱ����ʼ�� */
	GENERAL_TIM_Init();
	
	printf ( "\r\nҰ�� STM32 ���벶��ʵ��\r\n" );
	printf ( "\r\n����K1������K1���µ�ʱ��\r\n" );
	
	while ( 1 )
	{
		
	}
}
/*********************************************END OF FILE**********************/


