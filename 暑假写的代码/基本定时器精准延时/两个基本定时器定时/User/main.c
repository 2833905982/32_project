// ������ʱ��TIMx,x[6,7]��ʱӦ��
#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_TiMbase.h"
#include "bsp_usart.h"

volatile uint32_t time1 = 0; // ms ��ʱ���� 
volatile uint32_t time2 = 0; // ms ��ʱ���� 
/**
  * @brief  ������
  * @param  ��  
  * @retval ��
  */
int main(void)
{
	/* led �˿����� */ 
	LED_GPIO_Config();
	
	BASIC_TIM_Init();
	
	/* ��ʼ������ */
	USART_Config();
	
	printf("�������\n");
	
  while(1)
  {
    if ( time1 == 1000 ) /* 1000 * 1 ms = 1s ʱ�䵽 */
    {
      time1 = 0;
			
			/* LED1 ȡ�� */      
			printf("һ�밮��һ��\n");
    }   
    if ( time2 == 500 ) /* 1000 * 1 ms = 1s ʱ�䵽 */
    {
      time2 = 0;
			
			/* LED1 ȡ�� */      
			printf("���밮��һ��\n");
    }		
  }
}
/*********************************************END OF FILE**********************/

