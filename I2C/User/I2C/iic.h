#ifndef _IIC
#define _IIC


#include "stm32f10x.h"


#define STM32_I2C_OWN_ADDR         0x5F
/*  EEPROM 设备地址 */
#define EEPROM_ADDR                0xA0

// I2C1
#define  EEPROM_I2C                     I2C1
#define  EEPROM_I2C_CLK                 RCC_APB1Periph_I2C1
#define  EEPROM_I2C_APBxClkCmd          RCC_APB1PeriphClockCmd
#define  EEPROM_I2C_BAUDRATE            400000

// IIC GPIO 引脚宏定义
#define  EEPROM_I2C_SCL_GPIO_CLK           (RCC_APB2Periph_GPIOB)
#define  EEPROM_I2C_SDA_GPIO_CLK           (RCC_APB2Periph_GPIOB)



#define  EEPROM_I2C_GPIO_APBxClkCmd    RCC_APB2PeriphClockCmd
  
	
	
/* 切记TX与开发板上的RX连接 */  
#define  EEPROM_I2C_SCL_GPIO_PORT       GPIOB   
#define  EEPROM_I2C_SCL_GPIO_PIN        GPIO_Pin_6


/* 切记RX与开发板上的TX连接 */  
#define  EPROM_I2C_SDA_GPIO_PORT       GPIOB
#define  EPROM_I2C_SDA_GPIO_PIN        GPIO_Pin_7


void IIC_EEPROM_Config(void);
void EEPROM_Byte_Write(uint8_t addr,uint8_t data);
void EEPROM_Read(uint8_t addr,uint8_t *data,uint8_t numByteToRead);
void EEPROM_Page_Write(uint8_t addr,uint8_t *data,uint8_t numByteToWrite);
void EEPROM_WaitForWriteEnd(void);



#endif /* _IIC */

