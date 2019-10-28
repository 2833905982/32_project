#include "pid.h"


PID pid;							//���PID�㷨������


void PID_Calc(void)			//PID�������ڼ��
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
	
	if(pid.calc_time<(pid.T/10))					//PID��������δ��
	{
		return;
	}
	
	pid.Ek=pid.Sv-pid.Pv;									//�õ���ǰ��ƫ��ֵ���������㷨
	
	Pout=pid.Kp*pid.Ek;										//�������
	
	pid.SEK+=pid.Ek;											//��ʷƫ���ܺ�
	
	DelEk=pid.Ek-pid.Ek_1;								//�������ƫ��֮��
	
	ti=pid.T/pid.Ti;
	ki=ti*pid.Kp;
	
	Iout=ki*pid.SEK*pid.Kp;									//����������
	
	td=pid.Td/pid.T;
	kd=pid.Kp*td;
	
	Dout=kd*DelEk;												//΢�����
	
	out=Pout+Iout+Dout+pid.OUT0;					//���μ���������
	
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
	pid.Ek_1=pid.Ek;											//����ƫ��
	
	
	pid.calc_time=0;
}


