#include "usart.h"

//static void NVIC_Configuration(void)
//{
//	NVIC_InitTypeDef  NVIC_InitStructure;
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);									//Ƕ�������жϿ�������ѡ��
//	NVIC_InitStructure.NVIC_IRQChannel = DEBUG_USART_IRQ;						//�������ȼ�
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;				//�����ȼ�
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;							//ʹ���ж�
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;									//��ʼ������NVIC
//	NVIC_Init(&NVIC_InitStructure);
//}

void USART_Config(void)
{
	//GPIO��ʼ������7�е�25�У�
  GPIO_InitTypeDef         GPIO_InitStructure;
  USART_InitTypeDef        USART_InitStructure;
 
  DEBUG_USART_GPIO_APBxClkCmd(DEBUG_USART_GPIO_CLK,ENABLE);        //�򿪴��ڵ�GPIO��ʱ��

  DEBUG_USART_APBxClkCmd(DEBUG_USART_CLK, ENABLE);      				  //�򿪴��������ʱ��
	
	
  //��USART  Tx��GPIO����Ϊ���츴��ģʽ
  GPIO_InitStructure.GPIO_Pin = DEBUG_USART_TX_GPIO_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(DEBUG_USART_TX_GPIO_PORT,&GPIO_InitStructure);

	
  //��USART Rx��GPIO����Ϊ��������ģʽ(����������Ҳ��������)
  GPIO_InitStructure.GPIO_Pin = DEBUG_USART_RX_GPIO_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(DEBUG_USART_RX_GPIO_PORT,&GPIO_InitStructure);
	

  //���ô��ڵĹ�������
  USART_InitStructure.USART_BaudRate = DEBUG_USART_BAUDRATE;      							  //���ò�����
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;											//�����������ֳ�8λ
  USART_InitStructure.USART_StopBits = USART_StopBits_1;													//����ֹͣλ1λ
  USART_InitStructure.USART_Parity = USART_Parity_No;															//����У��λ����ʹ��У��
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; //����Ӳ�������ƣ���ʹ��
  USART_InitStructure.USART_Mode = USART_Mode_Rx|USART_Mode_Tx;										//���ù���ģʽ���շ�һ��
  USART_Init(DEBUG_USARTx, &USART_InitStructure);																	//��ɴ��ڵĳ�ʼ������
	//NVIC_Configuration();																														//�����ж����ȼ�����
	//USART_ITConfig(DEBUG_USARTx,USART_IT_RXNE,ENABLE);															//ʹ�ܴ��ڽ����ж�
	USART_Cmd(DEBUG_USARTx, ENABLE);																								//ʹ�ܴ���
}


/*����һ���ֽ�*/
void  Usart_SendByte(USART_TypeDef* pUSARTx,uint8_t data)	
{
	USART_SendData(pUSARTx, data);
	while( USART_GetFlagStatus(pUSARTx, USART_FLAG_TXE) == RESET );//����һֱΪ0��һֱ�ȴ�
}


/*���������ֽڵ�����*/
void Usart_send(USART_TypeDef* pUSARTx,uint16_t data)
{
	uint8_t high,low;
	
	high = (data&0xff00) >>8;
	low  = data&0xff;
	
	USART_SendData(pUSARTx, high);
	while( USART_GetFlagStatus(pUSARTx, USART_FLAG_TXE) == RESET );

	USART_SendData(pUSARTx, low);
	while( USART_GetFlagStatus(pUSARTx, USART_FLAG_TXE) == RESET );
	
}

/*����8λ���ݵ�����*/
void Usart_send8(USART_TypeDef* pUSARTx,uint8_t *array,uint8_t num)
{
	uint8_t i;
	for(i=0;i<num;i++)
	{
		Usart_SendByte(pUSARTx, array[i]);	
	}	
	while( USART_GetFlagStatus(pUSARTx, USART_FLAG_TC) == RESET );
	
}


/*�����ַ���*/
void Usart_sendstr(USART_TypeDef* pUSARTx,uint8_t *str)
{
	uint8_t i=0;;
	
	do
	{
		Usart_SendByte(pUSARTx,*(str+i));
		i++	;	
	}while(*(str+i) != '\0');														//����ʱ���������
	while( USART_GetFlagStatus(pUSARTx, USART_FLAG_TC) == RESET );

}


//�ض���c�⺯��printf�����ڣ��ض�����ʹ��printf����
int fputc(int ch, FILE *f)
{
		
	USART_SendData(DEBUG_USARTx, (uint8_t) ch);      										//����һ���ֽ����ݵ�����
		
	while (USART_GetFlagStatus(DEBUG_USARTx, USART_FLAG_TXE) == RESET);	//�ȴ�������� 	
	return (ch);
}


//�ض���c�⺯��scanf�����ڣ���д����ʹ��scanf��getchar�Ⱥ���
int fgetc(FILE *f)
{
	while (USART_GetFlagStatus(DEBUG_USARTx, USART_FLAG_RXNE) == RESET);//�ȴ�������������
	return (int)USART_ReceiveData(DEBUG_USARTx);
}
