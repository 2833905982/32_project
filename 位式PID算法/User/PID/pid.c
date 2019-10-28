#include "pid.h"


PID pid;							//存放PID算法的数据


void PID_Calc(void)			//PID计算周期检测
{
	float DelEk;
	float ti;
	float ki;
	float Iout;
	float Pout;
	float td;
	float kd;
	float Dout;
	float out;
	
	if(pid.calc_time<(pid.T/10))					//PID计算周期未到
	{
		return;
	}
	
	pid.Ek=pid.Sv-pid.Pv;									//得到当前的偏差值，即比例算法
	
	Pout=pid.Kp*pid.Ek;										//比例输出
	
	pid.SEK+=pid.Ek;											//历史偏差总和
	
	DelEk=pid.Ek-pid.Ek_1;								//最近两次偏差之差
	
	ti=pid.T/pid.Ti;
	ki=ti*pid.Kp;
	
	Iout=ki*pid.SEK*pid.Kp;									//积分项的输出
	
	td=pid.Td/pid.T;
	kd=pid.Kp*td;
	
	Dout=kd*DelEk;												//微分输出
	
	out=Pout+Iout+Dout+pid.OUT0;					//本次计算结果结束
	
	if(out>pid.pwmcycle)
	{
		pid.OUT=pid.pwmcycle;
	}
	if(out<0)
	{
		pid.OUT=0;
	}
	else
	{
		pid.OUT=out;
	}
	pid.Ek_1=pid.Ek;											//更新偏差
	
	
	pid.calc_time=0;
}


