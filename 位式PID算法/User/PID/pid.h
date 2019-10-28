#ifndef _PID_H
#define _PID_H

#include "stm32f10x.h"  

typedef struct
{
	float Sv;						//�û��趨ֵ
	float Pv;						//Ŀ�����ڵ�ֵ
	
	float Kp;						//����ϵ��
	float T;     			  //PID�ļ������ڣ�Ҳ�Ʋ�������
	float Ti;						//PID ����ʱ��
	float Td;    			  //΢��ϵ��
	
	float Ek;  				  //���ε�ƫ��
	float Ek_1;				  //�ϴε�ƫ��
	float SEK;				 	//��ʷƫ��֮��
	
	float OUT0;					//Ĭ�����������
	
	float OUT;					//����Ӧ�������������
	
	u16 calc_time;			//PID��������
	
	u16 pwmcycle;				//pwm ����
	
}PID;

extern PID pid;							//���PID�㷨������

void PID_Calc(void);				


#endif /* _PID_H */


