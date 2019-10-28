#include "stm32f10x.h"   // �൱��51��Ƭ���е�  #include <reg51.h>
#include "bsp_GeneralTim.h" 
#include "systick.h"
#include "jiaodu.h"
#include "usart.h"
#include "huidu.h"
#include "bsp-gpio.h"
#include "exti.h"


uint16_t i = 0;
int main(void)
{
	/* ��ʼ�� GPIO�� */
	LUN_GPIO_Config();
	
	/* ��ʼ������ */
	EXTI_Key_Config();
	
	/* ��ʼ�� PWM */
	GENERAL_TIM_Init();
	 
 
	/* ��ʼ������ */
	USART_Config();
	
	/* ��ʼ���Ҷ� */
	huidu ();
		
	printf("��ã������ˣ�");

	
	/*---------------------��ʼ��С������ǰ������Ĺ̶�----------------------------*/

		/* ����A2���� */
		GPIO_SetBits(Rwheel1_GPIO_PORT, Rwheel1_GPIO_PIN);											//������ת
		//GPIO_ResetBits(Rwheel1_GPIO_PORT, Rwheel1_GPIO_PIN);									//���ַ�ת
		
		/* ������A4���� */
		//GPIO_SetBits(Lwheel2_GPIO_PORT, Lwheel2_GPIO_PIN);					  				//���ַ�ת
		GPIO_ResetBits(Lwheel2_GPIO_PORT, Lwheel2_GPIO_PIN);										//������ת
		
	

}
	

