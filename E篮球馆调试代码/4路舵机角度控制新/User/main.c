#include "stm32f10x.h"
#include "systick.h"
#include "TIM.h"


int main (void)
{
  GENERAL_TIM4_Init();
//  S2open();
//	S2close();
	TIM_SetCompare2(GENERAL_TIM4,499);
	delay_ms(2000);
	TIM_SetCompare2(GENERAL_TIM4,999);
	delay_ms(2000);
	TIM_SetCompare2(GENERAL_TIM4,2499);
}
		//����������ƿɱ��ӦTIM_SetCompare(1,2,3,4),�ǶȲ�������
		//����ֱ�Ϊ���1�ţ����Ƴ������£����2��������Ͳ���ϣ����3�����ƹ�����ֱ�˶������4�����ƹ���ˮƽ�˶�������ӦTIM_SetCompare(1,2,3,4)��


