#include "adc.h"


static void ADCx_GPIO_Config(void)
{
	/* ��ʼ���ṹ����� */
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/* �� ADC IO�˿�ʱ�� */
	ADC_GPIO_APBxClock_FUN ( ADC_GPIO_CLK, ENABLE );
	
	// ���� ADC IO ����ģʽ
	GPIO_InitStructure.GPIO_Pin = ADC_PIN;
	
	/* ����GPIO��ģʽΪ����ģʽ   _AIN */
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	
	/* ��ʼ�� ADC IO */
	GPIO_Init(ADC_PORT, &GPIO_InitStructure);	
}

static void ADCx_Mode_Config(void)
{
	/* ����һ���ṹ����� */
	ADC_InitTypeDef ADC_InitStruct;
	
	/* ��ADCʱ�� */
	ADC_APBxClock_FUN ( ADC_CLK, ENABLE );
	
	/* ����ֻ��һ��ADC���򿪵�ͨ��ģʽ */
	ADC_InitStruct.ADC_Mode = ADC_Mode_Independent;
	
	/* ֻ��һ��ADC�����Բ���ɨ�� */
	ADC_InitStruct.ADC_ScanConvMode = DISABLE;
	
	/* �Ƿ�����ת����ѡ���� */
	ADC_InitStruct.ADC_ContinuousConvMode = ENABLE;
	
	/* ѡ�񴥷�ģʽ����ѡ��None */
	ADC_InitStruct.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	
	/* ADC ѡ���Ҷ��� */
	ADC_InitStruct.ADC_DataAlign  = ADC_DataAlign_Right;
	
	/* ѡ��ͨ����Ϊ1��ͨ�� */
	ADC_InitStruct.ADC_NbrOfChannel = 1;
	
	
	ADC_Init(ADC_x,&ADC_InitStruct);
	
	/* ����ʱ�ӣ�����Ϊ8��Ƶ */
	RCC_ADCCLKConfig(RCC_PCLK2_Div8);
	
	/* ADC �������ã����ĸ��βΣ���һ��Ϊȷ��ʹ���Ǹ�ADC���ڶ���Ϊʹ���ĸ�ͨ��������������ת��˳�򣬵��ĸ�ѡ��������ڡ� */
	ADC_RegularChannelConfig( ADC_x , ADC_CHANNEL , 1 , ADC_SampleTime_55Cycles5 );
	
	/* �����жϺ�������һ��Ϊ�Ǹ�ADC���ڶ���Ϊ�������͵��ж�,Ϊ�������ж� */
	ADC_ITConfig(ADC_x , ADC_IT_EOC , ENABLE);
	
	/* ʹ��ADC����ʼת�� */
	ADC_Cmd(ADC_x , ENABLE);
	
		// ADC��ʼУ׼
	ADC_StartCalibration(ADC_x);
	
	// �ȴ�У׼���
	while(ADC_GetCalibrationStatus(ADC_x));
	
	// ����û�в����ⲿ����������ʹ���������ADCת�� 
	ADC_SoftwareStartConvCmd(ADC_x, ENABLE);
	
}

static void ADC_NVIC_Config(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;
	// ���ȼ�����
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

  // �����ж����ȼ�
  NVIC_InitStructure.NVIC_IRQChannel = ADC_IRQ;
	
	/*  �����������ȼ�Ϊ1  */
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	
	/* ���������ȼ�Ϊ1 */
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
}


void ADCx_Init(void)
{
	ADC_NVIC_Config();
	ADCx_Mode_Config();
	ADCx_GPIO_Config();
}




















