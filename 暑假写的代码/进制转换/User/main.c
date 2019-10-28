/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   串口中断接收测试
  ******************************************************************************
  * @attention
  *
  * 实验平台:野火 F103-指南者 STM32 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */ 
 
 
#include "stm32f10x.h"
#include "bsp_usart.h"
#include <string.h>

/**
  * @brief  主函数
  * @param  无
  * @retval 无
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
  /*初始化USART 配置模式为 115200 8-N-1，中断接收*/
  USART_Config();
	
	/* 发送一个字符串 */
	Usart_SendString( DEBUG_USARTx,"这是一个串口中断接收回显实验\n");
	printf("欢迎使用野火STM32开发板\n\n\n\n");
	
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
