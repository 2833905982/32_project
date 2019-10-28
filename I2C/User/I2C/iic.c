#include "iic.h"

void IIC_EEPROM_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	I2C_InitTypeDef I2C_InitStructure;

	// 打开  I2C  GPIO的时钟
	EEPROM_I2C_GPIO_APBxClkCmd(EEPROM_I2C_SCL_GPIO_CLK | EEPROM_I2C_SDA_GPIO_CLK, ENABLE);
	
	// 打开  I2C  外设的时钟
	EEPROM_I2C_APBxClkCmd(EEPROM_I2C_CLK, ENABLE);

	// 将  I2C SCL  的GPIO配置为开漏输入模式
	GPIO_InitStructure.GPIO_Pin = EEPROM_I2C_SCL_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(EEPROM_I2C_SCL_GPIO_PORT, &GPIO_InitStructure);

  // 将  I2C SDA  的GPIO配置为开漏输入模式
	GPIO_InitStructure.GPIO_Pin = EPROM_I2C_SDA_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;
	GPIO_Init(EPROM_I2C_SDA_GPIO_PORT, &GPIO_InitStructure);
	
	// 配置  I2C  的工作参数
	// 配置波特率
	//使能应答
	I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;
	//使用7为地址模式
	I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
	//配置  scl  时钟频率
	I2C_InitStructure.I2C_ClockSpeed = EEPROM_I2C_BAUDRATE;
	
	I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;
	
	I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
	
	//这是STM32  IIC 设备地址，只要是设备上唯一即可。
	I2C_InitStructure.I2C_OwnAddress1 = STM32_I2C_OWN_ADDR;
	
	I2C_Init(EEPROM_I2C,&I2C_InitStructure);
	
	// 使能串口
	I2C_Cmd(EEPROM_I2C, ENABLE);	    
}

/* 向EEPROM写入一个字节 */
void EEPROM_Byte_Write(uint8_t addr,uint8_t data)
{
	/* 产生起始信号 */
	I2C_GenerateSTART(EEPROM_I2C,ENABLE);
	
	/* 表示已经检测到 EV5 事件 */
	while(I2C_CheckEvent(EEPROM_I2C,I2C_EVENT_MASTER_MODE_SELECT)==ERROR);
	
	/* 发送7位的设备地址 */
	I2C_Send7bitAddress(EEPROM_I2C,EEPROM_ADDR,I2C_Direction_Transmitter);
	
	/* 检测 EV6 事件 */
	while(I2C_CheckEvent(EEPROM_I2C,I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED )==ERROR);
	
	/* EV6 事件被检测到，发送要操作的设备储存单元地址 */
	I2C_SendData(EEPROM_I2C,addr);
	
	while(I2C_CheckEvent(EEPROM_I2C,I2C_EVENT_MASTER_BYTE_TRANSMITTING )==ERROR);

	/* EV8 事件被检测到，发送要操作的设备储存的数据 */
	I2C_SendData(EEPROM_I2C,data);
	
	/* 数据传输完成 */
	while(I2C_CheckEvent(EEPROM_I2C,I2C_EVENT_MASTER_BYTE_TRANSMITTED )==ERROR);
	
	/* 数据传输完成 */
	I2C_GenerateSTOP(EEPROM_I2C,ENABLE);
}

/* 向EEPROM写入多个字节（页写入）每次不能超过8字节 */
void EEPROM_Page_Write(uint8_t addr,uint8_t *data,uint8_t numByteToWrite)
{
	/* 产生起始信号 */
	I2C_GenerateSTART(EEPROM_I2C,ENABLE);
	
	/* 表示已经检测到 EV5 事件 */
	while(I2C_CheckEvent(EEPROM_I2C,I2C_EVENT_MASTER_MODE_SELECT)==ERROR);
	
	/* 发送7位的设备地址 */
	I2C_Send7bitAddress(EEPROM_I2C,EEPROM_ADDR,I2C_Direction_Transmitter);
	
	/* 检测 EV6 事件 */
	while(I2C_CheckEvent(EEPROM_I2C,I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED )==ERROR);
	
	/* EV6 事件被检测到，发送要操作的设备储存单元地址 */
	I2C_SendData(EEPROM_I2C,addr);
	
	while(I2C_CheckEvent(EEPROM_I2C,I2C_EVENT_MASTER_BYTE_TRANSMITTING )==ERROR);

	
	while(numByteToWrite)
	{
		/* EV8 事件被检测到，发送要操作的设备储存的数据 */
		I2C_SendData(EEPROM_I2C,*data);
		
		/* 数据传输完成 */
		while(I2C_CheckEvent(EEPROM_I2C,I2C_EVENT_MASTER_BYTE_TRANSMITTED )==ERROR);
		
		data++;
		numByteToWrite--;
		
	}
	
	
	/* 数据传输完成 */
	I2C_GenerateSTOP(EEPROM_I2C,ENABLE);
}



/* 从EEPROM中读取数据 */
void EEPROM_Read(uint8_t addr,uint8_t *data,uint8_t numByteToRead)
{
	/* 产生起始信号 */
	I2C_GenerateSTART(EEPROM_I2C,ENABLE);
	
	/* 表示已经检测到 EV5 事件 */
	while(I2C_CheckEvent(EEPROM_I2C,I2C_EVENT_MASTER_MODE_SELECT)==ERROR);
	
	/* 发送7位的设备地址 */
	I2C_Send7bitAddress(EEPROM_I2C,EEPROM_ADDR,I2C_Direction_Transmitter);
	
	/* 检测 EV6 事件 */
	while(I2C_CheckEvent(EEPROM_I2C,I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED )==ERROR);
	
	/* EV6 事件被检测到，发送要操作的设备储存单元地址 */
	I2C_SendData(EEPROM_I2C,addr);
	
	while(I2C_CheckEvent(EEPROM_I2C,I2C_EVENT_MASTER_BYTE_TRANSMITTING )==ERROR);
	
	/* 第二次起始信号 */
	
	/* 产生起始信号 */
	I2C_GenerateSTART(EEPROM_I2C,ENABLE);
	
	/* 表示已经检测到 EV5 事件 */
	while(I2C_CheckEvent(EEPROM_I2C,I2C_EVENT_MASTER_MODE_SELECT)==ERROR);
	
	/* 发送7位的设备地址 */
	I2C_Send7bitAddress(EEPROM_I2C,EEPROM_ADDR,I2C_Direction_Receiver);
	
	/* 检测 EV6 事件 */
	while(I2C_CheckEvent(EEPROM_I2C,I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED )==ERROR);
	
	/* 检测 EV7 事件，即有新的有效数据 */
	while(I2C_CheckEvent(EEPROM_I2C,I2C_EVENT_MASTER_BYTE_RECEIVED )==ERROR);
	
	*data = I2C_ReceiveData(EEPROM_I2C);
	
	
	
	while(numByteToRead)
	{			
		if(numByteToRead == 1)
		{
			/* 如果位最后剖一个字节 */
			I2C_AcknowledgeConfig(EEPROM_I2C,DISABLE);
			
			*data = I2C_ReceiveData(EEPROM_I2C);
		}
	  /* 检测 EV7 事件，即有新的有效数据 */
		while(I2C_CheckEvent(EEPROM_I2C,I2C_EVENT_MASTER_BYTE_RECEIVED )==ERROR);
			
		*data = I2C_ReceiveData(EEPROM_I2C);
	
		*data++;
		
		numByteToRead--;
	}
	
	/* 数据传输完成 */
	I2C_GenerateSTOP(EEPROM_I2C,ENABLE);
	
	/* 重新配置 ASK 函数，以变下次使用 */
	I2C_AcknowledgeConfig(EEPROM_I2C,ENABLE);

}

/* 等待EEPROM内部时序完成 */
void EEPROM_WaitForWriteEnd(void)
{
	do
	{
		/* 产生起始信号 */
		I2C_GenerateSTART(EEPROM_I2C,ENABLE);
		
		/* 表示已经检测到 EV5 事件 */
		while(I2C_GetITStatus(EEPROM_I2C,I2C_IT_SB)==RESET);
		
		/* 发送7位的设备地址 */
		I2C_Send7bitAddress(EEPROM_I2C,EEPROM_ADDR,I2C_Direction_Transmitter);
	}
	/* 检测 EV6 事件 */
	while(I2C_GetITStatus(EEPROM_I2C,I2C_IT_ADDR )==RESET);
	
	/* EEPROM内部时序传输完成 */
	I2C_GenerateSTOP(EEPROM_I2C,ENABLE);
	
}






























