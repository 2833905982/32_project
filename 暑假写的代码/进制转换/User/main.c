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
  * ʵ��ƽ̨:Ұ�� F103-ָ���� STM32 ������ 
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */ 
 
 
#include "stm32f10x.h"
#include "bsp_usart.h"
#include <string.h>

/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
void binary_to_ascii(int value)
{  
	int quotient;
	quotient = value/10;	
	if(quotient != 0)	
	binary_to_ascii( quotient );	
	putchar( value%10+ '0');
}
	
int main(void)
{	
  /*��ʼ��USART ����ģʽΪ 115200 8-N-1���жϽ���*/
  USART_Config();
	
	/* ����һ���ַ��� */
	Usart_SendString( DEBUG_USARTx,"����һ�������жϽ��ջ���ʵ��\n");
	printf("��ӭʹ��Ұ��STM32������\n\n\n\n");
	
	int i=0;
	char a[]="woyouyigemengxiang1234";
	int b[400];
	
  while(1)
	{		
		for(i=0;i<strlen(a);i++)
		{
			b[i]=(int)a[i];
			printf("%d  ",b[i]);
		}

			
	}	
}
/*********************************************END OF FILE**********************/
