#include "adc.h"

__IO uint32_t ADC_ConvertedValue[NOFCHANEL] = {0};


static void ADCx_GPIO_Config(void)
{
	
	GPIO_InitTypeDef GPIO_InitStructure;
	
	// ADCx_1 GPIO ��ʼ��
	ADCx_1_GPIO_APBxClock_FUN ( ADCx_1_GPIO_CLK, ENABLE );
	GPIO_InitStructure.GPIO_Pin = ADCx_1_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_Init(ADCx_1_PORT, &GPIO_InitStructure);

	// ADCx_2 GPIO ��ʼ��
	ADCx_1_GPIO_APBxClock_FUN ( ADCx_2_GPIO_CLK, ENABLE );
	GPIO_InitStructure.GPIO_Pin = ADCx_2_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_Init(ADCx_2_PORT, &GPIO_InitStructure);
}

static void ADCx_Mode_Config(void)
{
	
	DMA_InitTypeDef DMA_InitStructure;
	
/*---------------------------��ʼ��DMA-------------------------------*/
		// ��DMAʱ��
	RCC_AHBPeriphClockCmd(ADC_DMA_CLK, ENABLE);
	
		// ��λDMA������
	DMA_DeInit(ADC_DMA_CHANNEL);
	
	// ���� DMA ��ʼ���ṹ��
	// �����ַΪ��ADC ���ݼĴ�����ַ
	DMA_InitStructure.DMA_PeripheralBaseAddr = ( uint32_t ) ( & ( ADCx_1->DR ) );
	
	// �洢����ַ��ʵ���Ͼ���һ���ڲ�SRAM�ı���
	DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)ADC_ConvertedValue;
	
	// ����Դ��������
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
	
	// ��������СΪ1���������Ĵ�СӦ�õ��ڴ洢���Ĵ�С
	DMA_InitStructure.DMA_BufferSize = NOFCHANEL;
	
	// ����Ĵ���ֻ��һ������ַ���õ���
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;

	// �洢����ַ�̶�
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Disable; 
	
	// �������ݴ�СΪ���֣��������ֽ�
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Word;
	
	// �洢�����ݴ�СҲΪ���֣����������ݴ�С��ͬ
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Word;
	
	// ѭ������ģʽ
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;	

	// DMA ����ͨ�����ȼ�Ϊ�ߣ���ʹ��һ��DMAͨ��ʱ�����ȼ����ò�Ӱ��
	DMA_InitStructure.DMA_Priority = DMA_Priority_High;
	
	// ��ֹ�洢�����洢��ģʽ����Ϊ�Ǵ����赽�洢��
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
	
	DMA_Init(ADC_DMA_CHANNEL, &DMA_InitStructure);
	
	DMA_Cmd(ADC_DMA_CHANNEL , ENABLE);
	

	
	/*----------------------------------------------------*/
	
	
	/*-------------------ADC1��ʼ��----------------------*/
	
		/* ����һ���ṹ����� */
	ADC_InitTypeDef ADC_InitStruct;
	
	/* ��ADCʱ�� */
	ADCx_1_APBxClock_FUN (ADCx_1_CLK, ENABLE );
	
	/* ����ֻ��һ��ADC���򿪵�ͨ��ģʽ */
	ADC_InitStruct.ADC_Mode = ADC_Mode_RegSimult;
	
	/* ֻ��һ��ADC�����Բ���ɨ�� */
	ADC_InitStruct.ADC_ScanConvMode = DISABLE;
	
	/* �Ƿ�����ת����ѡ���� */
	ADC_InitStruct.ADC_ContinuousConvMode = ENABLE;
	
	/* ѡ�񴥷�ģʽ����ѡ��None */
	ADC_InitStruct.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	
	/* ADC ѡ���Ҷ��� */
	ADC_InitStruct.ADC_DataAlign  = ADC_DataAlign_Right;
	
	/* ѡ��ͨ����Ϊ1��ͨ�� */
	ADC_InitStruct.ADC_NbrOfChannel = NOFCHANEL;
	
	
	ADC_Init(ADCx_1,&ADC_InitStruct);
	
	/* ����ʱ�ӣ�����Ϊ8��Ƶ */
	RCC_ADCCLKConfig(RCC_PCLK2_Div8);
	
	/* ADC �������ã����ĸ��βΣ���һ��Ϊȷ��ʹ���Ǹ�ADC���ڶ���Ϊʹ���ĸ�ͨ��������������ת��˳�򣬵��ĸ�ѡ��������ڡ� */
	ADC_RegularChannelConfig(ADCx_1, ADCx_1_CHANNEL, 1, ADC_SampleTime_55Cycles5);
	
	/*----------------------------------------------------*/
	
	
	/*-------------------ADC2��ʼ��----------------------*/


		/* ����һ���ṹ����� */
//	ADC_InitTypeDef ADC_InitStruct;

	/* ��ADCʱ�� */
	ADCx_2_APBxClock_FUN (ADCx_2_CLK, ENABLE );
	
	/* ����ֻ��һ��ADC���򿪵�ͨ��ģʽ */
	ADC_InitStruct.ADC_Mode = ADC_Mode_RegSimult;
	
	/* ֻ��һ��ADC�����Բ���ɨ�� */
	ADC_InitStruct.ADC_ScanConvMode = DISABLE;
	
	/* �Ƿ�����ת����ѡ���� */
	ADC_InitStruct.ADC_ContinuousConvMode = ENABLE;
	
	/* ѡ�񴥷�ģʽ����ѡ��None */
	ADC_InitStruct.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	
	/* ADC ѡ���Ҷ��� */
	ADC_InitStruct.ADC_DataAlign  = ADC_DataAlign_Right;
	
	/* ѡ��ͨ����Ϊ1��ͨ�� */
	ADC_InitStruct.ADC_NbrOfChannel = NOFCHANEL;
	
	
	ADC_Init(ADCx_2,&ADC_InitStruct);
	
	/* ����ʱ�ӣ�����Ϊ8��Ƶ */
	RCC_ADCCLKConfig(RCC_PCLK2_Div8);
	
	/* ADC �������ã����ĸ��βΣ���һ��Ϊȷ��ʹ���Ǹ�ADC���ڶ���Ϊʹ���ĸ�ͨ��������������ת��˳�򣬵��ĸ�ѡ��������ڡ� */
	ADC_RegularChannelConfig(ADCx_2, ADCx_2_CHANNEL, 1, ADC_SampleTime_55Cycles5);
	
	/*----------------------------------------------------*/


	/* ----------------ADCx_1 У׼--------------------- */
	// ����ADC ������ʼת��
	ADC_Cmd(ADCx_1, ENABLE);	
	// ��ʼ��ADC У׼�Ĵ���  
	ADC_ResetCalibration(ADCx_1);
	// �ȴ�У׼�Ĵ�����ʼ�����
	while(ADC_GetResetCalibrationStatus(ADCx_1));	
	// ADC��ʼУ׼
	ADC_StartCalibration(ADCx_1);
	// �ȴ�У׼���
	while(ADC_GetCalibrationStatus(ADCx_1));
	
  /* ----------------ADCx_2 У׼--------------------- */
		// ����ADC ������ʼת��
	ADC_Cmd(ADCx_2, ENABLE);	
	// ��ʼ��ADC У׼�Ĵ���  
	ADC_ResetCalibration(ADCx_2);
	// �ȴ�У׼�Ĵ�����ʼ�����
	while(ADC_GetResetCalibrationStatus(ADCx_2));	
	// ADC��ʼУ׼
	ADC_StartCalibration(ADCx_2);
	// �ȴ�У׼���
	while(ADC_GetCalibrationStatus(ADCx_2));
		/* ʹ��ADCx_2���ⲿ����ת�� */
  ADC_ExternalTrigConvCmd(ADC2, ENABLE);
	
	// ����û�в����ⲿ����������ʹ���������ADCת�� 
	ADC_SoftwareStartConvCmd(ADCx_1, ENABLE);
	
}

void ADCx_Init(void)
{
	ADCx_Mode_Config();
	ADCx_GPIO_Config();
}




















