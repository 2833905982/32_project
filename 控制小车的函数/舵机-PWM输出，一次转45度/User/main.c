#include "stm32f10x.h"
#include "systick.h"
#include "TIM.h"


void huxideng(void);

int main (void)
{
	TIM_Init();							//高级定时器初始化
	uint32_t i;
	while (1)
	{
		
//		for(i=0;i<190;i++)
//		{
//			TIM_SetCompare1(ADVANCE_TIM,i);//对应180度
//			delay_ms(50);
//		}
//		for(i=190;i>0;i--)
//		{
//			TIM_SetCompare1(ADVANCE_TIM,i);//对应180度
//			delay_ms(50);
//		}			
	

	}

}



//void huxideng(void)
//{
//		delay_ms(500);
//		TIM_SetCompare1(ADVANCE_TIM,175);//对应180度
//		delay_ms(500);
//		TIM_SetCompare1(ADVANCE_TIM,180);//对应135度
//		delay_ms(500);
//		TIM_SetCompare1(ADVANCE_TIM,185);//对应90度
//		delay_ms(500);
//		TIM_SetCompare1(ADVANCE_TIM,190);//对应45度
//		delay_ms(500);
//		TIM_SetCompare1(ADVANCE_TIM,195);//对应0度
//		delay_ms(500);
//		TIM_SetCompare1(ADVANCE_TIM,190);//对应45度
//		delay_ms(500);
//		TIM_SetCompare1(ADVANCE_TIM,185);//对应90度
//		delay_ms(500);
//		TIM_SetCompare1(ADVANCE_TIM,180);//对应135度
//		
//		//如果配置的是PWM1模式，那么对应的占空比为25,20,15,10,5
//}
