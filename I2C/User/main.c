#include "stm32f10x.h"   // 相当于51单片机中的  #include <reg51.h>
#include "usart.h"
#include "iic.h"


#define LED_GPIO_PIN         GPIO_Pin_5 										//宏定义，定义IO口的引脚号。
#define LED_GPIO_PORT        GPIOB													//定义IO口的序号。
#define LED_GPIO_CLK         RCC_APB2Periph_GPIOB						//RCC,时钟函数打开时钟。

uint8_t readData[10]={0};
uint8_t writeData[8]={1,2,3,4,5,6,7,8};
int main(void)
{
	uint8_t i;
	//uint8_t a[10]={1,2,3,4,5,6,7,8,9,10};
	USART_Config();
	//往此处输入值，则发送到电脑上，一个字节。
	//Usart_SendByte(DEBUG_USARTx,1);
	
	//发送两个字节的数据。
	//Usart_SendHalfword(DEBUG_USARTx,0xFF56);
	
	/* 发送一个数组的数据 */
  //Usart_SendArray(DEBUG_USARTx ,a, 10);

	/* 发送字符数据 */
	Usart_SendStr(DEBUG_USARTx,"STM32,你好，渣子来了！\n");
	
	printf( "我有一个梦想！\n" );
	
	/* 初始化IIC */
	IIC_EEPROM_Config();
	
	/* 写入一个字节 */
	EEPROM_Byte_Write(11,0x55);
	
	/* 等待写入操作完成 */
	EEPROM_WaitForWriteEnd();
	
	/* 写入一个字节 */
	EEPROM_Byte_Write(12,0x52);
	
	/* 等待写入操作完成 */
	EEPROM_WaitForWriteEnd();
	
	/* 写入多个字节 */
	//但是只有addr%8 == 0，即地址对齐
	EEPROM_Page_Write(13,writeData,8);
	
	/* 等待写入操作完成 */
	EEPROM_WaitForWriteEnd();

	/* 读取数据 */
	EEPROM_Read(11,readData,10);
	
//	printf("\r\n接收到的数据为0x%x,0x%x\r\n",readData[0],readData[1]);
	
	
	for(i=0;i<10;i++)
	{
		printf("接收到的数据有0x%x  ",readData[i]);
	}
	while(1)
	{
		
	}
}






























