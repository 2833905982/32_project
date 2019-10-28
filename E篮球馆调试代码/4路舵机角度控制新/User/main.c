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
		//其他舵机控制可别对应TIM_SetCompare(1,2,3,4),角度参数不变
		//舵机分别为舵机1号（控制齿条上下）舵机2（控制套筒开合）舵机3（控制钩子竖直运动）舵机4（控制钩子水平运动），对应TIM_SetCompare(1,2,3,4)。


