#ifndef _PID_H
#define _PID_H

#include "stm32f10x.h"  

typedef struct
{
	float Sv;						//用户设定值
	float Pv;						//目标现在的值
	
	float Kp;						//比例系数
	float T;     			  //PID的计算周期，也称采样周期
	float Ti;						//PID 积分时间
	float Td;    			  //微分系数
	
	float Ek;  				  //本次的偏差
	float Ek_1;				  //上次的偏差
	float SEK;				 	//历史偏差之和
	
	float OUT0;					//默认输出的数据
	
	float OUT;					//本次应该输出的数据量
	
	u16 calc_time;			//PID计算周期
	
	u16 pwmcycle;				//pwm 周期
	
}PID;

extern PID pid;							//存放PID算法的数据

void PID_Calc(void);				


#endif /* _PID_H */


