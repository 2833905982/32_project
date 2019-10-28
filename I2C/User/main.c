#include "stm32f10x.h"   // �൱��51��Ƭ���е�  #include <reg51.h>
#include "usart.h"
#include "iic.h"


#define LED_GPIO_PIN         GPIO_Pin_5 										//�궨�壬����IO�ڵ����źš�
#define LED_GPIO_PORT        GPIOB													//����IO�ڵ���š�
#define LED_GPIO_CLK         RCC_APB2Periph_GPIOB						//RCC,ʱ�Ӻ�����ʱ�ӡ�

uint8_t readData[10]={0};
uint8_t writeData[8]={1,2,3,4,5,6,7,8};
int main(void)
{
	uint8_t i;
	//uint8_t a[10]={1,2,3,4,5,6,7,8,9,10};
	USART_Config();
	//���˴�����ֵ�����͵������ϣ�һ���ֽڡ�
	//Usart_SendByte(DEBUG_USARTx,1);
	
	//���������ֽڵ����ݡ�
	//Usart_SendHalfword(DEBUG_USARTx,0xFF56);
	
	/* ����һ����������� */
  //Usart_SendArray(DEBUG_USARTx ,a, 10);

	/* �����ַ����� */
	Usart_SendStr(DEBUG_USARTx,"STM32,��ã��������ˣ�\n");
	
	printf( "����һ�����룡\n" );
	
	/* ��ʼ��IIC */
	IIC_EEPROM_Config();
	
	/* д��һ���ֽ� */
	EEPROM_Byte_Write(11,0x55);
	
	/* �ȴ�д�������� */
	EEPROM_WaitForWriteEnd();
	
	/* д��һ���ֽ� */
	EEPROM_Byte_Write(12,0x52);
	
	/* �ȴ�д�������� */
	EEPROM_WaitForWriteEnd();
	
	/* д�����ֽ� */
	//����ֻ��addr%8 == 0������ַ����
	EEPROM_Page_Write(13,writeData,8);
	
	/* �ȴ�д�������� */
	EEPROM_WaitForWriteEnd();

	/* ��ȡ���� */
	EEPROM_Read(11,readData,10);
	
//	printf("\r\n���յ�������Ϊ0x%x,0x%x\r\n",readData[0],readData[1]);
	
	
	for(i=0;i<10;i++)
	{
		printf("���յ���������0x%x  ",readData[i]);
	}
	while(1)
	{
		
	}
}






























