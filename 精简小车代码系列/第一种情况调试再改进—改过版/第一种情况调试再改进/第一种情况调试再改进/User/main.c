#include "stm32f10x.h"   
#include "bsp_GeneralTim.h" 
#include "systick.h"
#include "usart.h"
#include "huidu.h"
#include "bsp-gpio.h"
#include "exti.h"
#include "move.h"
#include "weidai.h"
#include "color.h"

int main(void)
{
	//��ʼ������
	W_GPIO_Config();/*���ӷ���*/
	GENERAL_TIM_Init();/* PWM */	
	USART_Config();/* ��ʼ������ */
	huidu ();/* ��ʼ���Ҷ� */
	color();/*��ɫ*/

	//���к���
	
	chufa();

//	//���45
//	turn_left(400);
//	delay_ms(10);
//	qianjin_xunji();
	
	//���130
	turn_left(800);
	qianjin(300);
//	qianjin_xunji();

	
}
