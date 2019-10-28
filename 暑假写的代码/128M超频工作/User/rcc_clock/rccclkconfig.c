#include "rccclkconfig.h"

void HSE_SetSysCLK( uint32_t RCC_PLLMul_x )									//ʹ��HSE�����ⲿ��������ϵͳʱ�ӡ�        //Ƶ�ʵĴ�С����RCC_PLLMul_x * 8��ȷ����
{
	ErrorStatus HSEStatus;																		//����һ��	ErrorStatus�����͵ı�����	

	RCC_DeInit();																							//��RCC�Ĵ�����λ�ɸ�λֵ��
	
	RCC_HSEConfig( RCC_HSE_ON );															//ʹ�� HSE 
	
	HSEStatus = RCC_WaitForHSEStartUp();
	
	if( HSEStatus == SUCCESS )
	{
		FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);			//ʹ��Ԥȡֵ
		FLASH_SetLatency(FLASH_Latency_2);													//�ȴ������У��ֱ���0��1��2������ʼֵΪ2���ȴ���
		
		RCC_HCLKConfig(RCC_SYSCLK_Div1);
    RCC_PCLK1Config(RCC_HCLK_Div2);
    RCC_PCLK2Config(RCC_HCLK_Div1);
		//���໷����
		//����PLLCLK = HSE * RCC_PLLMul_x
		RCC_PLLConfig(RCC_PLLSource_HSE_Div1,RCC_PLLMul_x);				//����볬Ƶ����ͨ���������������ʵ�֡�
		//ʹ��PLL
    RCC_PLLCmd(ENABLE);
		//�ȴ�PLLʱ���ȶ�
		while( RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET);
		//ѡ��ϵͳʱ��
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		while( RCC_GetSYSCLKSource() != 0x08);
	}
	else
	{
		/*���HSE ����ʧ�ܣ��û����������ﴦ�����Ĵ��롣*/
	}
}

