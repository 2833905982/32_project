/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   �����жϽ��ղ���
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:���� F103-�Ե� STM32 ������ 
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */ 
 
 
#include "stm32f10x.h"
#include "bsp_usart.h"


/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main(void)
{	
  /*��ʼ��USART ����ģʽΪ 115200 8-N-1���жϽ���*/
  USART_Config();
	
	USART3_Config();
	
	/* ����һ���ַ��� */
	int a=0;
//	Usart_SendString( DEBUG_USARTx,"����һ�������жϽ��ջ���ʵ��\n");
	
//	Usart_SendString( DEBUG_USARTx,""a=%d\n",a");
//	printf2("aaa");
	
	
	usart1Printf("a=%d",a);
	usart1Printf("a=%d",a);
	usart1Printf("a=%d\r\n",a);
	usart1Printf("a=%d\r\n",a);
	usart1Printf("��ӭ����a=%d\r\n",a);
	
	printf("��ӭʹ�ñ���STM32������\n\n\n\n");
	
  while(1)
	{	
		
	}	
}
/*********************************************END OF FILE**********************/
