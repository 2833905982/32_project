#include "stm32f10x.h"
#include "systick.h"
#include "TIM.h"


void huxideng(void);

int main (void)
{
	TIM_Init();							//�߼���ʱ����ʼ��
	uint32_t i;
	while (1)
	{
		
//		for(i=0;i<190;i++)
//		{
//			TIM_SetCompare1(ADVANCE_TIM,i);//��Ӧ180��
//			delay_ms(50);
//		}
//		for(i=190;i>0;i--)
//		{
//			TIM_SetCompare1(ADVANCE_TIM,i);//��Ӧ180��
//			delay_ms(50);
//		}			
	

	}

}



//void huxideng(void)
//{
//		delay_ms(500);
//		TIM_SetCompare1(ADVANCE_TIM,175);//��Ӧ180��
//		delay_ms(500);
//		TIM_SetCompare1(ADVANCE_TIM,180);//��Ӧ135��
//		delay_ms(500);
//		TIM_SetCompare1(ADVANCE_TIM,185);//��Ӧ90��
//		delay_ms(500);
//		TIM_SetCompare1(ADVANCE_TIM,190);//��Ӧ45��
//		delay_ms(500);
//		TIM_SetCompare1(ADVANCE_TIM,195);//��Ӧ0��
//		delay_ms(500);
//		TIM_SetCompare1(ADVANCE_TIM,190);//��Ӧ45��
//		delay_ms(500);
//		TIM_SetCompare1(ADVANCE_TIM,185);//��Ӧ90��
//		delay_ms(500);
//		TIM_SetCompare1(ADVANCE_TIM,180);//��Ӧ135��
//		
//		//������õ���PWM1ģʽ����ô��Ӧ��ռ�ձ�Ϊ25,20,15,10,5
//}
