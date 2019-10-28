#include "Robotic_arm_function.h" 

 int zhuazi_kai=1550,
	   zhuazi_he=1850;

/*************************������**************************************/
			Servo servo[5]={
			{GPIOA,GPIO_Pin_0,900,900},//900
			{GPIOA,GPIO_Pin_1,2180,2180},
			{GPIOA,GPIO_Pin_2,510,510},
			{GPIOA,GPIO_Pin_3,1900,1900},
			{GPIOA,GPIO_Pin_6,1550,1550}//1550
			};//�����ĸ�������ֱ�����PA0,PA1,PA2,PA3�ϣ���ʼ�Ƕ�Ϊ1500�������ֵ��
			//���ǧ���ܶ�����ˣ���������
/*************************��ȡ����Ķ������**************************************/		
		int Length=sizeof(servo)/sizeof(servo[0]);//����һ��ȫ�ֱ��������ж϶���ĸ���
			
		static void Servo_Delay_ms(uint16_t ms)//����ȷ��ms����ʱ.���û����ʱ������Ҫȥע��
{
	u32 i;//1us��ʱ�����ڴ��Ϊ80��
	while(ms--)
	{
	 i=80000;
		while(i--);
	}
}


void Servo_init()
{
	/*************************���ʹ��**************************************/
	int Length=sizeof(servo)/sizeof(servo[0]);
	int Servo_deal_flag=0;//�����������״̬���������1˵������ɹ�������ʧ�ܡ�
	Servo_deal_flag=Servo_Init(servo,Length);//ʹ�ܶ���ṹ������г�Ա��
	//Servo_deal_flag=NServo_Write(servo,1000,Length);//��Ӧ����ṹ����������Ҫ�����Ĳ�������ÿƫתһ���ǶȽ�����ʱ����΢���ʱ��
	//printf("Servo_deal_flag=%d",Servo_deal_flag);//���ز鿴��������Ƿ�ɹ�����Ҫ��ʼ������
//	
//	/*************************�����������**************************************/
//	servo[0].intent_angle=2000;//�ı���0��Ŀ�ĽǶ�
//	NServo_Write(servo,1000,Length);//��Ӧ�仯��
//	Servo_Delay_ms(10);//�ȴ�����ȶ�������Ҫ��̫��
//	
	/*************************����������**************************************/
//	//		{GPIOA,GPIO_Pin_3,2200,2200}
//			};//�����ĸ�������ֱ�����PA0,PA1,PA2,PA3�ϣ���ʼ�Ƕ�Ϊ1500�������ֵ��
//			//���ǧ���ܶ�����ˣ�������


}
void Servo_up_Grab(int ms)
{
//	Servo_Delay_ms(50);
	servo[4].intent_angle=zhuazi_kai;
	servo[3].intent_angle=1250;
	servo[2].intent_angle=800;
	servo[1].intent_angle=1250;
	servo[0].intent_angle=853;
	NServo_Write(servo,ms,Length);//��Ӧ�仯
  //ץ
	Servo_Delay_ms(50);
	servo[4].intent_angle=zhuazi_he;
	servo[3].intent_angle=1250;
	servo[2].intent_angle=800;
	servo[1].intent_angle=1250;
	servo[0].intent_angle=853;
	NServo_Write(servo,ms,Length);//��Ӧ�仯
	//��ǰ��ץȡ

}
void Servo_left_Grab(int ms)
{
//	Servo_Delay_ms(50);
	servo[4].intent_angle=zhuazi_kai;
	servo[3].intent_angle=1200;
	servo[2].intent_angle=900;
	servo[1].intent_angle=1200;
	servo[0].intent_angle=1050;
	NServo_Write(servo,ms,Length);//��Ӧ�仯
  //ץ
  Servo_Delay_ms(50);
	servo[4].intent_angle=zhuazi_he;
	servo[3].intent_angle=1200;
	servo[2].intent_angle=900;
	servo[1].intent_angle=1200;
	servo[0].intent_angle=1050;
	NServo_Write(servo,ms,Length);//��Ӧ�仯
//	Servo_Delay_ms(10);
	//��
	Servo_Delay_ms(50);
	servo[4].intent_angle=zhuazi_he;
	servo[3].intent_angle=1200;
	servo[2].intent_angle=900;
	servo[1].intent_angle=1500;
	servo[0].intent_angle=1050;
	NServo_Write(servo,ms,Length);//��Ӧ�仯
//	��ǰ��ץȡ
}
void Servo_right_Grab(int ms)
{
	servo[4].intent_angle=zhuazi_kai;
	servo[3].intent_angle=1200;
	servo[2].intent_angle=900;
	servo[1].intent_angle=1200;
	servo[0].intent_angle=720;
	NServo_Write(servo,ms,Length);//��Ӧ�仯
  //ץ
  Servo_Delay_ms(50);
	servo[4].intent_angle=zhuazi_he;
	servo[3].intent_angle=1200;
	servo[2].intent_angle=900;
	servo[1].intent_angle=1200;
	servo[0].intent_angle=720;
	NServo_Write(servo,ms,Length);//��Ӧ�仯
	//��
	Servo_Delay_ms(50);
	servo[4].intent_angle=zhuazi_he;
	servo[3].intent_angle=1200;
	servo[2].intent_angle=900;
	servo[1].intent_angle=1500;
	servo[0].intent_angle=720;
	NServo_Write(servo,ms,Length);//��Ӧ�仯
//	��ǰ��ץȡ
}
void Servo_up_Place(int ms)
{
	//����ת��
	servo[4].intent_angle=zhuazi_he;
	servo[3].intent_angle=1000;
	servo[2].intent_angle=510;
	servo[1].intent_angle=2100;
	servo[0].intent_angle=2100;
	NServo_Write(servo,10,Length);
	//��λ	
	servo[4].intent_angle=zhuazi_he;
	servo[3].intent_angle=900;
	servo[2].intent_angle=650;
	servo[1].intent_angle=1000;
	servo[0].intent_angle=2100;
	NServo_Write(servo,ms,Length);//��Ӧ�仯
	//��
	servo[4].intent_angle=zhuazi_kai;
	servo[3].intent_angle=900;
	servo[2].intent_angle=650;
	servo[1].intent_angle=1000;
	servo[0].intent_angle=2100;
	NServo_Write(servo,ms,Length);//��Ӧ�仯
	//��
	servo[4].intent_angle=zhuazi_kai;
	servo[3].intent_angle=900;
	servo[2].intent_angle=650;
	servo[1].intent_angle=1500;
	servo[0].intent_angle=2100;
	NServo_Write(servo,ms,Length);//��Ӧ�仯
	//ת��ȥ
	servo[4].intent_angle=zhuazi_kai;
	servo[3].intent_angle=900;
	servo[2].intent_angle=650;
	servo[1].intent_angle=1500;
	servo[0].intent_angle=900;
	NServo_Write(servo,10,Length);//��Ӧ�仯
  
	//��ǰ������
}
void Servo_left_Place(int ms)//100
{
	//����ת��
	servo[4].intent_angle=zhuazi_he;
	servo[3].intent_angle=1000;
	servo[2].intent_angle=510;
	servo[1].intent_angle=1700;
	servo[0].intent_angle=1810;//1780
	NServo_Write(servo,10,Length);
	delay_ms(100);
  //��λ
	servo[4].intent_angle=zhuazi_he;
	servo[3].intent_angle=1200;
	servo[2].intent_angle=1050;
	servo[1].intent_angle=1010;//1000
	servo[0].intent_angle=1810;
	NServo_Write(servo,ms,Length);//��Ӧ�仯
	
	//�ȴ�������
	delay_ms(150);
	
	//��
	servo[4].intent_angle=zhuazi_kai;
	servo[3].intent_angle=1200;
	servo[2].intent_angle=1050;
	servo[1].intent_angle=1010;
	servo[0].intent_angle=1810;
	NServo_Write(servo,ms,Length);//��Ӧ�仯
	//��
	servo[4].intent_angle=zhuazi_kai;
	servo[3].intent_angle=1200;
	servo[2].intent_angle=1050;
	servo[1].intent_angle=1500;
	servo[0].intent_angle=1810;
	NServo_Write(servo,ms,Length);//��Ӧ�仯
	//ת��ȥ
	servo[4].intent_angle=zhuazi_kai;
	servo[3].intent_angle=1200;
	servo[2].intent_angle=1050;
	servo[1].intent_angle=1500;
	servo[0].intent_angle=900;
	NServo_Write(servo,10,Length);//��Ӧ�仯
	
}
void Servo_right_Place(int ms)
{
	//����ת��
	servo[4].intent_angle=zhuazi_he;
	servo[3].intent_angle=1000;
	servo[2].intent_angle=510;
	servo[1].intent_angle=1700;
	servo[0].intent_angle=2400;
	NServo_Write(servo,10,Length);
	delay_ms(300);
  //��λ
	servo[4].intent_angle=zhuazi_he;
	servo[3].intent_angle=1200;
	servo[2].intent_angle=1050;
	servo[1].intent_angle=1000;
	servo[0].intent_angle=2400;
	NServo_Write(servo,ms,Length);//��Ӧ�仯
	
	//�ȴ�������
	delay_ms(150);
	
	//��
	servo[4].intent_angle=zhuazi_kai;
	servo[3].intent_angle=1200;
	servo[2].intent_angle=1050;
	servo[1].intent_angle=1000;
	servo[0].intent_angle=2400;
	NServo_Write(servo,ms,Length);//��Ӧ�仯
	//��
	servo[4].intent_angle=zhuazi_kai;
	servo[3].intent_angle=1200;
	servo[2].intent_angle=1050;
	servo[1].intent_angle=1500;
	servo[0].intent_angle=2400;
	NServo_Write(servo,ms,Length);//��Ӧ�仯
	//ת��ȥ
	servo[4].intent_angle=zhuazi_kai;
	servo[3].intent_angle=1200;
	servo[2].intent_angle=1050;
	servo[1].intent_angle=1500;
	servo[0].intent_angle=900;
	NServo_Write(servo,10,Length);//��Ӧ�仯
}

void Servo_Scan(int ms)//���Զ��ר��
{
	servo[4].intent_angle=zhuazi_kai;
	servo[3].intent_angle=1000;
	servo[2].intent_angle=510;
	servo[1].intent_angle=2100;
	servo[0].intent_angle=900;
	NServo_Write(servo,ms,Length); 
	delay_ms(1000);
	delay_ms(1000);
	delay_ms(1000);
	
	servo[4].intent_angle=zhuazi_he;
	servo[3].intent_angle=1000;
	servo[2].intent_angle=510;
	servo[1].intent_angle=2100;
	servo[0].intent_angle=900;
	NServo_Write(servo,ms,Length); /************************************************/
}

void Servo_over(int ms)//����ִ����ϡ������λ
{
	servo[4].intent_angle=zhuazi_he;
	servo[3].intent_angle=1000;
	servo[2].intent_angle=510;
	servo[1].intent_angle=2100;
	servo[0].intent_angle=900;
	NServo_Write(servo,ms,Length); /************************************************/
}




/*********************************************END OF FILE**********************/
