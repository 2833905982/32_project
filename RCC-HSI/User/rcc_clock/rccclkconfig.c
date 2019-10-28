#include "rccclkconfig.h"

void HSI_SetSysCLK( uint32_t RCC_PLLMul_x )									//ʹ��HSE�����ⲿ��������ϵͳʱ�ӡ�        //Ƶ�ʵĴ�С����RCC_PLLMul_x * 8��ȷ����
{
	__IO uint32_t HSIStatus = 0;																		//����һ��	ErrorStatus�����͵ı�����	
	//��RCC�Ĵ�����λ�ɸ�λֵ��
	RCC_DeInit();																	
	
	//ʹ�� HSE 
	RCC_HSICmd(ENABLE);														
	
	HSIStatus = RCC ->CR & RCC_CR_HSIRDY;
	
	if( HSIStatus == RCC_CR_HSIRDY )
	{
		FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);			//ʹ��Ԥȡֵ
		FLASH_SetLatency(FLASH_Latency_2);													//�ȴ������У��ֱ���0��1��2������ʼֵΪ2���ȴ���
		
		RCC_HCLKConfig(RCC_SYSCLK_Div1);
    RCC_PCLK1Config(RCC_HCLK_Div2);
    RCC_PCLK2Config(RCC_HCLK_Div1);
		//���໷����
		//����PLLCLK = HSE * RCC_PLLMul_x
		RCC_PLLConfig(RCC_PLLSource_HSI_Div2,RCC_PLLMul_x);				//����볬Ƶ����ͨ���������������ʵ�֡�
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
		/*���HSI ����ʧ�ܣ��û����������ﴦ�����Ĵ��롣*/
	}
}

