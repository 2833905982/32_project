#include "usart.h"


void USART_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;

	// �򿪴���GPIO��ʱ��
	DEBUG_USART_GPIO_APBxClkCmd(DEBUG_USART_GPIO_CLK, ENABLE);
	
	// �򿪴��������ʱ��
	DEBUG_USART_APBxClkCmd(DEBUG_USART_CLK, ENABLE);

	// ��USART Tx��GPIO����Ϊ���츴��ģʽ
	GPIO_InitStructure.GPIO_Pin = DEBUG_USART_TX_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(DEBUG_USART_TX_GPIO_PORT, &GPIO_InitStructure);

  // ��USART Rx��GPIO����Ϊ��������ģʽ
	GPIO_InitStructure.GPIO_Pin = DEBUG_USART_RX_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(DEBUG_USART_RX_GPIO_PORT, &GPIO_InitStructure);
	
	// ���ô��ڵĹ�������
	// ���ò�����
	USART_InitStructure.USART_BaudRate = DEBUG_USART_BAUDRATE;
	// ���� �������ֳ�
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	// ����ֹͣλ
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	// ����У��λ
	USART_InitStructure.USART_Parity = USART_Parity_No ;
	// ����Ӳ��������
	USART_InitStructure.USART_HardwareFlowControl = 
	USART_HardwareFlowControl_None;
	// ���ù���ģʽ���շ�һ��
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	// ��ɴ��ڵĳ�ʼ������
	USART_Init(DEBUG_USARTx, &USART_InitStructure);
	

//	USART_ITConfig(DEBUG_USARTx, USART_IT_RXNE, ENABLE);	
	
	// ʹ�ܴ���
	USART_Cmd(DEBUG_USARTx, ENABLE);	    
}

/* ����һ���ֽ� */
void Usart_SendByte(USART_TypeDef* pUSARTx,uint8_t data)
{
	USART_SendData(pUSARTx,data);
	while( USART_GetFlagStatus(pUSARTx,USART_FLAG_TXE) == RESET );
}
/* ���Ͷ����ֽڵ����� */
void Usart_SendHalfword(USART_TypeDef* pUSARTx,uint16_t data)
{
	uint8_t temp_h,temp_l;
	
	/* ȡ�����ݸ߰�λ */
	temp_h = (data & 0xFF00) >> 8;
	/* ȡ�����ݵͰ�λ */
	temp_l = data & 0xFF;
	
	/* �������ݵĸ߰�λ */
	USART_SendData(pUSARTx,temp_h);
	while( USART_GetFlagStatus(pUSARTx,USART_FLAG_TXE) == RESET );
	
	/* �������ݵĵͰ�λ */
	USART_SendData(pUSARTx,temp_l);
	while( USART_GetFlagStatus(pUSARTx,USART_FLAG_TXE) == RESET );
}


/* ����8λ���������� */
void Usart_SendArray(USART_TypeDef* pUSARTx,uint8_t *array,uint8_t num)
{
	uint8_t i;
	for(i=0;i<num;i++)
	{
		Usart_SendByte(pUSARTx,array[i]);
	}
	while( USART_GetFlagStatus(pUSARTx,USART_FLAG_TC) == RESET );
}

/* ����һ�������ַ����� */
void Usart_SendStr(USART_TypeDef* pUSARTx,uint8_t *Str)
{
	uint8_t i = 0;
	do
	{
		Usart_SendByte(pUSARTx , *(Str+i) );
		i++;
	}while( *(Str+i) != '\0' );
	while( USART_GetFlagStatus(pUSARTx,USART_FLAG_TC) == RESET );
}
/* ʹ��ţ�Ƶ�printf���� */
int fputc(int ch, FILE *f)
{
		/* ����һ���ֽ����ݵ����� */
		USART_SendData(DEBUG_USARTx, (uint8_t) ch);
		
		/* �ȴ�������� */
		while (USART_GetFlagStatus(DEBUG_USARTx, USART_FLAG_TXE) == RESET);		
	
		return (ch);
}

//�ض���c�⺯��scanf�����ڣ���д����ʹ��scanf��getchar�Ⱥ���
int fgetc(FILE *f)
{
		/* �ȴ������������� */
		while (USART_GetFlagStatus(DEBUG_USARTx, USART_FLAG_RXNE) == RESET);

		return (int)USART_ReceiveData(DEBUG_USARTx);
}




















