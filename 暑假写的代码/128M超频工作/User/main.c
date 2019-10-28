#include "stm32f10x.h"   // �൱��51��Ƭ���е�  #include <reg51.h>
#include "rccclkconfig.h"
#include "bsp_SysTick.h"
#include "led.h"



int main(void)
{
	//���������ʱ��ϵͳʱ���Ѿ�������Ϊ72M.
	  LED_GPIO_Config();																			//���ú�����װ�������ܿ顣

	  HSE_SetSysCLK( RCC_PLLMul_9 );
	while(1)
	{
		
		GPIO_SetBits(LED_GPIO_PORT, LED_GPIO_PIN);							//GPIO_SetBits�������ø�GPIO�õף�ʹС�����������Ŀ��ܡ�
		SysTick_Delay_Ms(50);
		
		GPIO_ResetBits(LED_GPIO_PORT, LED_GPIO_PIN);						//GPIO_ResetBits��������GPIO�øߣ���С�������
		SysTick_Delay_Ms(50);
	}
}


