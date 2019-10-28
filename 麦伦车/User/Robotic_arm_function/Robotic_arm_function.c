#include "Robotic_arm_function.h" 

 int zhuazi_kai=1550,
	   zhuazi_he=1850;

/*************************定义舵机**************************************/
			Servo servo[5]={
			{GPIOA,GPIO_Pin_0,900,900},//900
			{GPIOA,GPIO_Pin_1,2180,2180},
			{GPIOA,GPIO_Pin_2,510,510},
			{GPIOA,GPIO_Pin_3,1900,1900},
			{GPIOA,GPIO_Pin_6,1550,1550}//1550
			};//定义四个舵机，分别连在PA0,PA1,PA2,PA3上，初始角度为1500（相对中值）
			//舵机千万不能定义多了！！！！！
/*************************获取定义的舵机个数**************************************/		
		int Length=sizeof(servo)/sizeof(servo[0]);//定义一个全局变量，以判断舵机的个数
			
		static void Servo_Delay_ms(uint16_t ms)//不精确的ms计延时.如果没有延时函数需要去注释
{
	u32 i;//1us的时钟周期大概为80次
	while(ms--)
	{
	 i=80000;
		while(i--);
	}
}


void Servo_init()
{
	/*************************舵机使能**************************************/
	int Length=sizeof(servo)/sizeof(servo[0]);
	int Servo_deal_flag=0;//舵机处理函数的状态、如果返回1说明处理成功、否则失败。
	Servo_deal_flag=Servo_Init(servo,Length);//使能舵机结构体的所有成员。
	//Servo_deal_flag=NServo_Write(servo,1000,Length);//响应舵机结构体数组中需要调整的参数，并每偏转一个角度进行延时，以微妙计时。
	//printf("Servo_deal_flag=%d",Servo_deal_flag);//返回查看舵机处理是否成功。需要初始化串口
//	
//	/*************************单个舵机处理**************************************/
//	servo[0].intent_angle=2000;//改变舵机0的目的角度
//	NServo_Write(servo,1000,Length);//响应变化。
//	Servo_Delay_ms(10);//等待舵机稳定、不需要加太长
//	
	/*************************多个舵机处理**************************************/
//	//		{GPIOA,GPIO_Pin_3,2200,2200}
//			};//定义四个舵机，分别连在PA0,PA1,PA2,PA3上，初始角度为1500（相对中值）
//			//舵机千万不能定义多了！！！！


}
void Servo_up_Grab(int ms)
{
//	Servo_Delay_ms(50);
	servo[4].intent_angle=zhuazi_kai;
	servo[3].intent_angle=1250;
	servo[2].intent_angle=800;
	servo[1].intent_angle=1250;
	servo[0].intent_angle=853;
	NServo_Write(servo,ms,Length);//响应变化
  //抓
	Servo_Delay_ms(50);
	servo[4].intent_angle=zhuazi_he;
	servo[3].intent_angle=1250;
	servo[2].intent_angle=800;
	servo[1].intent_angle=1250;
	servo[0].intent_angle=853;
	NServo_Write(servo,ms,Length);//响应变化
	//正前方抓取

}
void Servo_left_Grab(int ms)
{
//	Servo_Delay_ms(50);
	servo[4].intent_angle=zhuazi_kai;
	servo[3].intent_angle=1200;
	servo[2].intent_angle=900;
	servo[1].intent_angle=1200;
	servo[0].intent_angle=1050;
	NServo_Write(servo,ms,Length);//响应变化
  //抓
  Servo_Delay_ms(50);
	servo[4].intent_angle=zhuazi_he;
	servo[3].intent_angle=1200;
	servo[2].intent_angle=900;
	servo[1].intent_angle=1200;
	servo[0].intent_angle=1050;
	NServo_Write(servo,ms,Length);//响应变化
//	Servo_Delay_ms(10);
	//起
	Servo_Delay_ms(50);
	servo[4].intent_angle=zhuazi_he;
	servo[3].intent_angle=1200;
	servo[2].intent_angle=900;
	servo[1].intent_angle=1500;
	servo[0].intent_angle=1050;
	NServo_Write(servo,ms,Length);//响应变化
//	左前方抓取
}
void Servo_right_Grab(int ms)
{
	servo[4].intent_angle=zhuazi_kai;
	servo[3].intent_angle=1200;
	servo[2].intent_angle=900;
	servo[1].intent_angle=1200;
	servo[0].intent_angle=720;
	NServo_Write(servo,ms,Length);//响应变化
  //抓
  Servo_Delay_ms(50);
	servo[4].intent_angle=zhuazi_he;
	servo[3].intent_angle=1200;
	servo[2].intent_angle=900;
	servo[1].intent_angle=1200;
	servo[0].intent_angle=720;
	NServo_Write(servo,ms,Length);//响应变化
	//起
	Servo_Delay_ms(50);
	servo[4].intent_angle=zhuazi_he;
	servo[3].intent_angle=1200;
	servo[2].intent_angle=900;
	servo[1].intent_angle=1500;
	servo[0].intent_angle=720;
	NServo_Write(servo,ms,Length);//响应变化
//	右前方抓取
}
void Servo_up_Place(int ms)
{
	//快速转向
	servo[4].intent_angle=zhuazi_he;
	servo[3].intent_angle=1000;
	servo[2].intent_angle=510;
	servo[1].intent_angle=2100;
	servo[0].intent_angle=2100;
	NServo_Write(servo,10,Length);
	//定位	
	servo[4].intent_angle=zhuazi_he;
	servo[3].intent_angle=900;
	servo[2].intent_angle=650;
	servo[1].intent_angle=1000;
	servo[0].intent_angle=2100;
	NServo_Write(servo,ms,Length);//响应变化
	//放
	servo[4].intent_angle=zhuazi_kai;
	servo[3].intent_angle=900;
	servo[2].intent_angle=650;
	servo[1].intent_angle=1000;
	servo[0].intent_angle=2100;
	NServo_Write(servo,ms,Length);//响应变化
	//起
	servo[4].intent_angle=zhuazi_kai;
	servo[3].intent_angle=900;
	servo[2].intent_angle=650;
	servo[1].intent_angle=1500;
	servo[0].intent_angle=2100;
	NServo_Write(servo,ms,Length);//响应变化
	//转回去
	servo[4].intent_angle=zhuazi_kai;
	servo[3].intent_angle=900;
	servo[2].intent_angle=650;
	servo[1].intent_angle=1500;
	servo[0].intent_angle=900;
	NServo_Write(servo,10,Length);//响应变化
  
	//正前方放置
}
void Servo_left_Place(int ms)//100
{
	//快速转向
	servo[4].intent_angle=zhuazi_he;
	servo[3].intent_angle=1000;
	servo[2].intent_angle=510;
	servo[1].intent_angle=1700;
	servo[0].intent_angle=1810;//1780
	NServo_Write(servo,10,Length);
	delay_ms(100);
  //定位
	servo[4].intent_angle=zhuazi_he;
	servo[3].intent_angle=1200;
	servo[2].intent_angle=1050;
	servo[1].intent_angle=1010;//1000
	servo[0].intent_angle=1810;
	NServo_Write(servo,ms,Length);//响应变化
	
	//等待物块放稳
	delay_ms(150);
	
	//放
	servo[4].intent_angle=zhuazi_kai;
	servo[3].intent_angle=1200;
	servo[2].intent_angle=1050;
	servo[1].intent_angle=1010;
	servo[0].intent_angle=1810;
	NServo_Write(servo,ms,Length);//响应变化
	//起
	servo[4].intent_angle=zhuazi_kai;
	servo[3].intent_angle=1200;
	servo[2].intent_angle=1050;
	servo[1].intent_angle=1500;
	servo[0].intent_angle=1810;
	NServo_Write(servo,ms,Length);//响应变化
	//转回去
	servo[4].intent_angle=zhuazi_kai;
	servo[3].intent_angle=1200;
	servo[2].intent_angle=1050;
	servo[1].intent_angle=1500;
	servo[0].intent_angle=900;
	NServo_Write(servo,10,Length);//响应变化
	
}
void Servo_right_Place(int ms)
{
	//快速转向
	servo[4].intent_angle=zhuazi_he;
	servo[3].intent_angle=1000;
	servo[2].intent_angle=510;
	servo[1].intent_angle=1700;
	servo[0].intent_angle=2400;
	NServo_Write(servo,10,Length);
	delay_ms(300);
  //定位
	servo[4].intent_angle=zhuazi_he;
	servo[3].intent_angle=1200;
	servo[2].intent_angle=1050;
	servo[1].intent_angle=1000;
	servo[0].intent_angle=2400;
	NServo_Write(servo,ms,Length);//响应变化
	
	//等待物块放稳
	delay_ms(150);
	
	//放
	servo[4].intent_angle=zhuazi_kai;
	servo[3].intent_angle=1200;
	servo[2].intent_angle=1050;
	servo[1].intent_angle=1000;
	servo[0].intent_angle=2400;
	NServo_Write(servo,ms,Length);//响应变化
	//起
	servo[4].intent_angle=zhuazi_kai;
	servo[3].intent_angle=1200;
	servo[2].intent_angle=1050;
	servo[1].intent_angle=1500;
	servo[0].intent_angle=2400;
	NServo_Write(servo,ms,Length);//响应变化
	//转回去
	servo[4].intent_angle=zhuazi_kai;
	servo[3].intent_angle=1200;
	servo[2].intent_angle=1050;
	servo[1].intent_angle=1500;
	servo[0].intent_angle=900;
	NServo_Write(servo,10,Length);//响应变化
}

void Servo_Scan(int ms)//调试舵机专用
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

void Servo_over(int ms)//任务执行完毕。舵机归位
{
	servo[4].intent_angle=zhuazi_he;
	servo[3].intent_angle=1000;
	servo[2].intent_angle=510;
	servo[1].intent_angle=2100;
	servo[0].intent_angle=900;
	NServo_Write(servo,ms,Length); /************************************************/
}




/*********************************************END OF FILE**********************/
