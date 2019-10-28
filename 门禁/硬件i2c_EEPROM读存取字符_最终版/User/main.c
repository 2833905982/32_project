/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   I2C EEPROM(AT24C02)���ԣ�������Ϣͨ��USART1��ӡ�ڵ��Եĳ����ն�
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
#include "./led/bsp_led.h"
#include "./usart/bsp_usart.h"
#include "./i2c/bsp_i2c_ee.h"
#include <string.h>

#define  EEP_Firstpage      0x00
#define  SIZE								256
uint8_t I2c_Buf_Write[SIZE];
uint8_t I2c_Buf_Read[SIZE];
uint8_t I2C_Test(void);

char ICard[]="woyouyigemengxiang123";

/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main(void)
{ 
  LED_GPIO_Config();
  
  LED_BLUE;
  /* ���ڳ�ʼ�� */
	USART_Config();
	
	printf("\r\n ����һ��I2C����(AT24C02)��д�������� \r\n");

	/* I2C �����(AT24C02)ʼ�� */
	I2C_EE_Init();

	printf("\r\n ����һ��I2C����(AT24C02)��д�������� \r\n");	
	
	printf("\r\n �洢���ַ��ǣ�");
	
	int i=0;
	int sign;
//	char 
	for( i=0; i<=strlen(ICard); i++ ) //��仺��
  {   
    printf("%c ", ICard[i]);
	
  }
	 	 
  //EEPROM ��д����
	if(I2C_Test() ==1)
	{
			LED_GREEN;
	}
	else
	{
			LED_RED;
	}
	if(I2C_Test() ==1)
	{
		printf("EEPROM����洢���ַ��ǣ�");
		
		for( i=0; i<=strlen(ICard); i++)
		{
			sign=(int)ICard[i];
			printf("%c ",sign);
		}
			printf("\n\r"); 
	}
  
  while (1)
  {      
  }
}

/**
  * @brief  I2C(AT24C02)��д����
  * @param  ��
  * @retval ��������1���쳣����0
  */
uint8_t I2C_Test(void)
{
	uint16_t i;

	printf("\r\nд�������\n\r");
    
	for ( i=0; i<=strlen(ICard); i++ ) //��仺��
  {   
    I2c_Buf_Write[i] = (int)ICard[i];

    printf("%d ", I2c_Buf_Write[i]);
    if(i%16 == 15)    
        printf("\n\r");    
   }

  //��I2c_Buf_Write��˳�����������д��EERPOM�� 
	I2C_EE_BufferWrite( I2c_Buf_Write, EEP_Firstpage, SIZE);
  
  EEPROM_INFO("\n\rд�ɹ�\n\r");
   
   EEPROM_INFO("\n\r����������\n\r");
  //��EEPROM��������˳�򱣳ֵ�I2c_Buf_Read��
	I2C_EE_BufferRead(I2c_Buf_Read, EEP_Firstpage, SIZE); 
   
  //��I2c_Buf_Read�е�����ͨ�����ڴ�ӡ
	for (i=0; i<strlen(ICard); i++)
	{	
		if(I2c_Buf_Read[i] != I2c_Buf_Write[i])
		{
			EEPROM_ERROR("%d   ", I2c_Buf_Read[i]);
			EEPROM_ERROR("����:I2C EEPROMд������������ݲ�һ��\n\r");
			return 0;
		}
    printf("%d ", I2c_Buf_Read[i]);
    if(i%16 == 15)    
        printf("\n\r");
    
	}
  EEPROM_INFO("I2C(AT24C02)��д���Գɹ�\n\r");
  
  return 1;
}
/*********************************************END OF FILE**********************/
