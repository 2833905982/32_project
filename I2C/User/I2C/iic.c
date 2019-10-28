#include "iic.h"

void IIC_EEPROM_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	I2C_InitTypeDef I2C_InitStructure;

	// ��  I2C  GPIO��ʱ��
	EEPROM_I2C_GPIO_APBxClkCmd(EEPROM_I2C_SCL_GPIO_CLK | EEPROM_I2C_SDA_GPIO_CLK, ENABLE);
	
	// ��  I2C  �����ʱ��
	EEPROM_I2C_APBxClkCmd(EEPROM_I2C_CLK, ENABLE);

	// ��  I2C SCL  ��GPIO����Ϊ��©����ģʽ
	GPIO_InitStructure.GPIO_Pin = EEPROM_I2C_SCL_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(EEPROM_I2C_SCL_GPIO_PORT, &GPIO_InitStructure);

  // ��  I2C SDA  ��GPIO����Ϊ��©����ģʽ
	GPIO_InitStructure.GPIO_Pin = EPROM_I2C_SDA_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;
	GPIO_Init(EPROM_I2C_SDA_GPIO_PORT, &GPIO_InitStructure);
	
	// ����  I2C  �Ĺ�������
	// ���ò�����
	//ʹ��Ӧ��
	I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;
	//ʹ��7Ϊ��ַģʽ
	I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
	//����  scl  ʱ��Ƶ��
	I2C_InitStructure.I2C_ClockSpeed = EEPROM_I2C_BAUDRATE;
	
	I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;
	
	I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
	
	//����STM32  IIC �豸��ַ��ֻҪ���豸��Ψһ���ɡ�
	I2C_InitStructure.I2C_OwnAddress1 = STM32_I2C_OWN_ADDR;
	
	I2C_Init(EEPROM_I2C,&I2C_InitStructure);
	
	// ʹ�ܴ���
	I2C_Cmd(EEPROM_I2C, ENABLE);	    
}

/* ��EEPROMд��һ���ֽ� */
void EEPROM_Byte_Write(uint8_t addr,uint8_t data)
{
	/* ������ʼ�ź� */
	I2C_GenerateSTART(EEPROM_I2C,ENABLE);
	
	/* ��ʾ�Ѿ���⵽ EV5 �¼� */
	while(I2C_CheckEvent(EEPROM_I2C,I2C_EVENT_MASTER_MODE_SELECT)==ERROR);
	
	/* ����7λ���豸��ַ */
	I2C_Send7bitAddress(EEPROM_I2C,EEPROM_ADDR,I2C_Direction_Transmitter);
	
	/* ��� EV6 �¼� */
	while(I2C_CheckEvent(EEPROM_I2C,I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED )==ERROR);
	
	/* EV6 �¼�����⵽������Ҫ�������豸���浥Ԫ��ַ */
	I2C_SendData(EEPROM_I2C,addr);
	
	while(I2C_CheckEvent(EEPROM_I2C,I2C_EVENT_MASTER_BYTE_TRANSMITTING )==ERROR);

	/* EV8 �¼�����⵽������Ҫ�������豸��������� */
	I2C_SendData(EEPROM_I2C,data);
	
	/* ���ݴ������ */
	while(I2C_CheckEvent(EEPROM_I2C,I2C_EVENT_MASTER_BYTE_TRANSMITTED )==ERROR);
	
	/* ���ݴ������ */
	I2C_GenerateSTOP(EEPROM_I2C,ENABLE);
}

/* ��EEPROMд�����ֽڣ�ҳд�룩ÿ�β��ܳ���8�ֽ� */
void EEPROM_Page_Write(uint8_t addr,uint8_t *data,uint8_t numByteToWrite)
{
	/* ������ʼ�ź� */
	I2C_GenerateSTART(EEPROM_I2C,ENABLE);
	
	/* ��ʾ�Ѿ���⵽ EV5 �¼� */
	while(I2C_CheckEvent(EEPROM_I2C,I2C_EVENT_MASTER_MODE_SELECT)==ERROR);
	
	/* ����7λ���豸��ַ */
	I2C_Send7bitAddress(EEPROM_I2C,EEPROM_ADDR,I2C_Direction_Transmitter);
	
	/* ��� EV6 �¼� */
	while(I2C_CheckEvent(EEPROM_I2C,I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED )==ERROR);
	
	/* EV6 �¼�����⵽������Ҫ�������豸���浥Ԫ��ַ */
	I2C_SendData(EEPROM_I2C,addr);
	
	while(I2C_CheckEvent(EEPROM_I2C,I2C_EVENT_MASTER_BYTE_TRANSMITTING )==ERROR);

	
	while(numByteToWrite)
	{
		/* EV8 �¼�����⵽������Ҫ�������豸��������� */
		I2C_SendData(EEPROM_I2C,*data);
		
		/* ���ݴ������ */
		while(I2C_CheckEvent(EEPROM_I2C,I2C_EVENT_MASTER_BYTE_TRANSMITTED )==ERROR);
		
		data++;
		numByteToWrite--;
		
	}
	
	
	/* ���ݴ������ */
	I2C_GenerateSTOP(EEPROM_I2C,ENABLE);
}



/* ��EEPROM�ж�ȡ���� */
void EEPROM_Read(uint8_t addr,uint8_t *data,uint8_t numByteToRead)
{
	/* ������ʼ�ź� */
	I2C_GenerateSTART(EEPROM_I2C,ENABLE);
	
	/* ��ʾ�Ѿ���⵽ EV5 �¼� */
	while(I2C_CheckEvent(EEPROM_I2C,I2C_EVENT_MASTER_MODE_SELECT)==ERROR);
	
	/* ����7λ���豸��ַ */
	I2C_Send7bitAddress(EEPROM_I2C,EEPROM_ADDR,I2C_Direction_Transmitter);
	
	/* ��� EV6 �¼� */
	while(I2C_CheckEvent(EEPROM_I2C,I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED )==ERROR);
	
	/* EV6 �¼�����⵽������Ҫ�������豸���浥Ԫ��ַ */
	I2C_SendData(EEPROM_I2C,addr);
	
	while(I2C_CheckEvent(EEPROM_I2C,I2C_EVENT_MASTER_BYTE_TRANSMITTING )==ERROR);
	
	/* �ڶ�����ʼ�ź� */
	
	/* ������ʼ�ź� */
	I2C_GenerateSTART(EEPROM_I2C,ENABLE);
	
	/* ��ʾ�Ѿ���⵽ EV5 �¼� */
	while(I2C_CheckEvent(EEPROM_I2C,I2C_EVENT_MASTER_MODE_SELECT)==ERROR);
	
	/* ����7λ���豸��ַ */
	I2C_Send7bitAddress(EEPROM_I2C,EEPROM_ADDR,I2C_Direction_Receiver);
	
	/* ��� EV6 �¼� */
	while(I2C_CheckEvent(EEPROM_I2C,I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED )==ERROR);
	
	/* ��� EV7 �¼��������µ���Ч���� */
	while(I2C_CheckEvent(EEPROM_I2C,I2C_EVENT_MASTER_BYTE_RECEIVED )==ERROR);
	
	*data = I2C_ReceiveData(EEPROM_I2C);
	
	
	
	while(numByteToRead)
	{			
		if(numByteToRead == 1)
		{
			/* ���λ�����һ���ֽ� */
			I2C_AcknowledgeConfig(EEPROM_I2C,DISABLE);
			
			*data = I2C_ReceiveData(EEPROM_I2C);
		}
	  /* ��� EV7 �¼��������µ���Ч���� */
		while(I2C_CheckEvent(EEPROM_I2C,I2C_EVENT_MASTER_BYTE_RECEIVED )==ERROR);
			
		*data = I2C_ReceiveData(EEPROM_I2C);
	
		*data++;
		
		numByteToRead--;
	}
	
	/* ���ݴ������ */
	I2C_GenerateSTOP(EEPROM_I2C,ENABLE);
	
	/* �������� ASK �������Ա��´�ʹ�� */
	I2C_AcknowledgeConfig(EEPROM_I2C,ENABLE);

}

/* �ȴ�EEPROM�ڲ�ʱ����� */
void EEPROM_WaitForWriteEnd(void)
{
	do
	{
		/* ������ʼ�ź� */
		I2C_GenerateSTART(EEPROM_I2C,ENABLE);
		
		/* ��ʾ�Ѿ���⵽ EV5 �¼� */
		while(I2C_GetITStatus(EEPROM_I2C,I2C_IT_SB)==RESET);
		
		/* ����7λ���豸��ַ */
		I2C_Send7bitAddress(EEPROM_I2C,EEPROM_ADDR,I2C_Direction_Transmitter);
	}
	/* ��� EV6 �¼� */
	while(I2C_GetITStatus(EEPROM_I2C,I2C_IT_ADDR )==RESET);
	
	/* EEPROM�ڲ�ʱ������� */
	I2C_GenerateSTOP(EEPROM_I2C,ENABLE);
	
}






























