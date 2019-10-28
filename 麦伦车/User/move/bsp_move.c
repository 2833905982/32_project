#include "bsp_move.h"
#include "bsp_adc.h"
#include "bsp_led.h"
#include "bsp_encoder.h"
#include "bsp_timer.h" 
#include "bsp_GeneralTim.h"
#include "Robotic_arm_function.h" 
#include <Servo.h>

  int Encoder_Left;             //左编码器的脉冲计数
  int Encoder_Right;						//右编码器的脉冲计数
// ADC1转换的电压值通过MDA方式传到SRAM
  extern __IO uint16_t ADC_ConvertedValue[NOFCHANEL];
// 局部变量，用于保存转换计算后的电压值 	 
  float ADC_ConvertedValueLocal[NOFCHANEL]; 

int maopao_time=350;//抓放盲跑时间

int sudu_a=6000,//双线速度
	  sudu_b=5000;//单线速度

int mangpao_time_shuang=80;
 
 
 //转速
// extern  int  zhuanshu=7200;
/******************************************************寻迹程序***************************************************/
/******************************************************寻迹程序***************************************************/
/******************************************************寻迹程序***************************************************/
/******************************************************寻迹程序***************************************************/
/******************************************************寻迹程序***************************************************/
/******************************************************寻迹程序***************************************************/
/******************************************************寻迹程序***************************************************/
/******************************************************寻迹程序***************************************************/
/******************************************************寻迹程序***************************************************/
/*寻迹直行到检测到路口     （正向）     */
void zhixing1(u16 zhuansu)
{
	while(1)
	{
			 int time = 10;
			
			
					//前行
					 sudu(zhuansu,zhuansu,0,1);
		
		
			
		    	//检测路口
				 if(GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN8 )==1 || GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN12 )==1)
				 {
					 //停
						sudu(0,0,0,1);
					 break;
				 }
			
			
					//左边灰度
					for(;GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN7 )==1;)
					{
						 //左拐
					   sudu(zhuansu,zhuansu,1,1);
						 //检测路口
						 if(GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN8 )==1 || GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN12 )==1)
						 {
							 //停
						   sudu(0,0,0,1);
							 break;
						 }						
					}
					
					//右边灰度
					for(;GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN13 )==1;)
					{
						 //右拐
             sudu(zhuansu,zhuansu,0,0);						
						 //检测路口
						 if(GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN8 )==1 || GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN12 )==1)
						 {
							 //停
						   sudu(0,0,0,1);
							 break;
						 }											
					}
				}
				
}

/*寻迹直行到检测到路口     （倒向）     */
void zhixing2(u16 zhuansu)
{
	while(1)
	{
			 int time = 10;
			    
					//前行
					 sudu(zhuansu,zhuansu,1,0);
			
		    	//检测路口
				 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN15 )==1 || GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN12 )==1)
				 {
					 //停
						sudu(0,0,0,1);
					 break;
				 }
			
			
					//左边灰度
					for(;GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN5 )==1;)
					{
						 //左拐
             sudu(zhuansu,zhuansu,1,1);
						 //检测路口
						 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN15 )==1 || GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN12 )==1)
						 {
							 //停
						   sudu(0,0,0,1);
							 break;
						 }							
					}
					
					//右边灰度
					for(;GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN9 )==1;)
					{
						 //右拐
             sudu(zhuansu,zhuansu,0,0);
						 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN15 )==1 || GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN12 )==1)
						  {
								//停
						    sudu(0,0,0,1);
							  break;
						  }					
					}
				}
				
}
/*寻迹直行到检测到路口     （正向）     */
void zhixing1_danxian_jingdu(u16 zhuansu)
{
	while(1)
	{
			
			
					//前行
					 sudu(zhuansu,zhuansu,0,1);
			
		    	//检测路口
				 if(GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN8 )==1 || GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN12 )==1)
				 {
					 //停
						sudu(0,0,0,1);
					 break;
				 }
			
			
					//左边灰度
					for(;GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN7 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN6 )==1;)
					{
						 //左拐
					   sudu(zhuansu,zhuansu,1,1);
						 //检测路口
						 if(GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN8 )==1 || GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN12 )==1)
						 {
							 //停
						   sudu(0,0,0,1);
							 break;
						 }						
					}
					
					//右边灰度
					for(;GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN13 )==1 || GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN14 )==1;)
					{
						 //右拐
             sudu(zhuansu,zhuansu,0,0);						
						 //检测路口
						 if(GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN8 )==1 || GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN12 )==1)
						 {
							 //停
						   sudu(0,0,0,1);
							 break;
						 }											
					}
				}
				
}

/*寻迹直行到检测到路口     （倒向）     */
void zhixing2_danxian_jingdu(u16 zhuansu)
{
	while(1)
	{
			    
					//前行
					 sudu(zhuansu,zhuansu,1,0);
			
		    	//检测路口
				 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN15 )==1 || GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN12 )==1)
				 {
					 //停
						sudu(0,0,0,1);
					 break;
				 }
			
			
					//左边灰度
					for(;GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN5 )==1 || GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN4 )==1;)
					{
						 //左拐
             sudu(zhuansu,zhuansu,1,1);
						 //检测路口
						 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN15 )==1 || GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN12 )==1)
						 {
							 //停
						   sudu(0,0,0,1);
							 break;
						 }							
					}
					
					//右边灰度
					for(;GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN9 )==1 || GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN8 )==1;)
					{
						 //右拐
             sudu(zhuansu,zhuansu,0,0);
						 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN15 )==1 || GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN12 )==1)
						  {
								//停
						    sudu(0,0,0,1);
							  break;
						  }					
					}
				}
				
}

void zhixing1_chufa(u16 zhuansu)
{
	while(1)
	{
			 int time = 10;
			
			
					//前行
					 sudu(zhuansu,zhuansu,0,1);
		
		
			
		    	//检测路口
				 if(GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN8 )==1)
				 {
					 //停
						sudu(0,0,0,1);
					 break;
				 }
			
			
					//左边灰度
					for(;GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN7 )==1;)
					{
						 //左拐
					   sudu(zhuansu,zhuansu,1,1);
						 //检测路口
						 if(GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN8 )==1)
						 {
							 //停
						   sudu(0,0,0,1);
							 break;
						 }						
					}
					
					//右边灰度
					for(;GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN13 )==1;)
					{
						 //右拐
             sudu(zhuansu,zhuansu,0,0);						
						 //检测路口
						 if(GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN8 )==1)
						 {
							 //停
						   sudu(0,0,0,1);
							 break;
						 }											
					}
				}
				
}

/*寻迹直行到检测到路口     （正向）     */
void zhixing1_danxian_jingdu_zuo(u16 zhuansu)
{
	while(1)
	{
			
			
					//前行
					 sudu(zhuansu,zhuansu,0,1);
			
		    	//检测路口
				 if(GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN8 )==1)
				 {
					 //停
						sudu(0,0,0,1);
					 break;
				 }
			
			
					//左边灰度
					for(;GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN7 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN6 )==1;)
					{
						 //左拐
					   sudu(zhuansu,zhuansu,1,1);
						 //检测路口
						 if(GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN8 )==1)
						 {
							 //停
						   sudu(0,0,0,1);
							 break;
						 }						
					}
					
					//右边灰度
					for(;GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN13 )==1 || GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN14 )==1;)
					{
						 //右拐
             sudu(zhuansu,zhuansu,0,0);						
						 //检测路口
						 if(GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN8 )==1)
						 {
							 //停
						   sudu(0,0,0,1);
							 break;
						 }											
					}
				}
				
}


/***************************************************寻迹到中心程序***************************************************/
/***************************************************寻迹到中心程序***************************************************/
/***************************************************寻迹到中心程序***************************************************/
/***************************************************寻迹到中心程序***************************************************/
/***************************************************寻迹到中心程序***************************************************/
/***************************************************寻迹到中心程序***************************************************/
/***************************************************寻迹到中心程序***************************************************/
/*寻迹直行到中心检测到路口     （正向）     */
void zhongxin1(u16 zhuansu1,u16 mangpao_time,u16 zhuansu2)
{
	zhixing1(zhuansu1);
	mangpao1(mangpao_time);
	while(1)
	{
			 int sudu1 = 0;
			
			
					//前行
					 sudu(zhuansu2,zhuansu2,0,1);
			
		    	//检测路口
				 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
				 {
					 //停
						sudu(0,0,0,1);
					 break;
				 }
			
			
					//左边灰度
					for(;GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN7 )==1;)
					{
						 //左拐
					   sudu(zhuansu2,zhuansu2,1,1);
						 //检测路口
						 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
						 {
							 //停
						   sudu(0,0,0,1);
							 break;
						 }				
					}
					
					//右边灰度
					for(;GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN13 )==1;)
					{
						 //右拐
             sudu(zhuansu2,zhuansu2,0,0);						
						 //检测路口
						 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
						 {
							 //停
						   sudu(0,0,0,1);
							 break;
						 }								
					}
				}
}


/*寻迹直行到中心检测到路口     （倒向）     */
void zhongxin2(u16 zhuansu1,u16 mangpao_time,u16 zhuansu2)
{
	zhixing2(zhuansu1);
	mangpao2(mangpao_time);
	while(1)
	{
			    
					//前行
					 sudu(zhuansu2,zhuansu2,1,0);
			
		    	//检测路口
					if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
						{
							//停
						  sudu(0,0,0,1);
							break;
						}				
			
			
					//左边灰度
					for(;GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN5 )==1;)
					{
						 //左拐
             sudu(zhuansu2,zhuansu2,1,1);
						 //检测路口
						 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
						 {
							 //停
						   sudu(0,0,0,1);
							 break;
						 }								
					}
					
					//右边灰度
					for(;GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN9 )==1;)
					{
						 //右拐
             sudu(zhuansu2,zhuansu2,0,0);
						 //检测路口
						 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
						 {
							 //停
						   sudu(0,0,0,1);
							 break;
						 }						
					}
				}
}
/*寻迹直行到中心检测到路口     （正向）（单线）     */
void zhongxin1_danxian(u16 zhuansu1,u16 zhuansu2)
{
	zhixing1(zhuansu1);
	mangpao1_danxian();
	while(1)
	{
			 int sudu1 = 0;
			
			
					//前行
					 sudu(zhuansu2,zhuansu2,0,1);
			
		    	//检测路口
				 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
				 {
					 //停
						sudu(0,0,0,1);
					 break;
				 }
			
			
					//左边灰度
					for(;GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN7 )==1;)
					{
						 //左拐
					   sudu(zhuansu2,zhuansu2,1,1);
						 //检测路口
						 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
						 {
							 //停
						   sudu(0,0,0,1);
							 break;
						 }				
					}
					
					//右边灰度
					for(;GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN13 )==1;)
					{
						 //右拐
             sudu(zhuansu2,zhuansu2,0,0);						
						 //检测路口
						 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
						 {
							 //停
						   sudu(0,0,0,1);
							 break;
						 }								
					}
				}
}


/*寻迹直行到中心检测到路口     （倒向） （单线）    */
void zhongxin2_danxian(u16 zhuansu1,u16 zhuansu2)
{
	zhixing2(zhuansu1);
	mangpao2_danxian();
	while(1)
	{
			    
					//前行
					 sudu(zhuansu2,zhuansu2,1,0);
			
		    	//检测路口
					if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
						{
							//停
						  sudu(0,0,0,1);
							break;
						}				
			
			
					//左边灰度
					for(;GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN5 )==1;)
					{
						 //左拐
             sudu(zhuansu2,zhuansu2,1,1);
						 //检测路口
						 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
						 {
							 //停
						   sudu(0,0,0,1);
							 break;
						 }								
					}
					
					//右边灰度
					for(;GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN9 )==1;)
					{
						 //右拐
             sudu(zhuansu2,zhuansu2,0,0);
						 //检测路口
						 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
						 {
							 //停
						   sudu(0,0,0,1);
							 break;
						 }						
					}
				}
}

/*寻迹直行到中心检测到路口     （正向） （双线）    */
void zhongxin1_shuangxian(u16 zhuansu1,u16 zhuansu2)
{
	zhixing1(zhuansu1);
	mangpao1_shuanxian();
	while(1)
	{
			 int sudu1 = 0;
			
			
					//前行
					 sudu(zhuansu2,zhuansu2,0,1);
			
		    	//检测路口
				 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
				 {
					 //停
						sudu(0,0,0,1);
					 break;
				 }
			
			
					//左边灰度
					for(;GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN7 )==1;)
					{
						 //左拐
					   sudu(zhuansu2,zhuansu2,1,1);
						 //检测路口
						 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
						 {
							 //停
						   sudu(0,0,0,1);
							 break;
						 }				
					}
					
					//右边灰度
					for(;GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN13 )==1;)
					{
						 //右拐
             sudu(zhuansu2,zhuansu2,0,0);						
						 //检测路口
						 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
						 {
							 //停
						   sudu(0,0,0,1);
							 break;
						 }								
					}
				}
}


/*寻迹直行到中心检测到路口     （倒向）  （双线）    */
void zhongxin2_shuangxian(u16 zhuansu1,u16 zhuansu2)
{
	zhixing2(zhuansu1);
	mangpao1_shuanxian();
	while(1)
	{
			    
					//前行
					 sudu(zhuansu2,zhuansu2,1,0);
			
		    	//检测路口
					if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
						{
							//停
						  sudu(0,0,0,1);
							break;
						}				
			
			
					//左边灰度
					for(;GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN5 )==1;)
					{
						 //左拐
             sudu(zhuansu2,zhuansu2,1,1);
						 //检测路口
						 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
						 {
							 //停
						   sudu(0,0,0,1);
							 break;
						 }								
					}
					
					//右边灰度
					for(;GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN9 )==1;)
					{
						 //右拐
             sudu(zhuansu2,zhuansu2,0,0);
						 //检测路口
						 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
						 {
							 //停
						   sudu(0,0,0,1);
							 break;
						 }						
					}
				}
}
/*寻迹直行到中心检测到路口     （正向）     */
void zhongxin1_danxian_jingdu(u16 zhuansu1,u16 mangpao_time,u16 zhuansu2)
{
	zhixing1_danxian_jingdu(zhuansu1);
	mangpao1(mangpao_time);
	while(1)
	{
			
			
					//前行
					 sudu(zhuansu2,zhuansu2,0,1);
			
		    	//检测路口
				 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
				 {
					 //停
						sudu(0,0,0,1);
					 break;
				 }
			
			
					//左边灰度
					for(;GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN7 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN6 )==1;)
					{
						 //左拐
					   sudu(zhuansu2,zhuansu2,1,1);
						 //检测路口
						 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
						 {
							 //停
						   sudu(0,0,0,1);
							 break;
						 }				
					}
					
					//右边灰度
					for(;GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN13 )==1 || GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN14 )==1;)
					{
						 //右拐
             sudu(zhuansu2,zhuansu2,0,0);						
						 //检测路口
						 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
						 {
							 //停
						   sudu(0,0,0,1);
							 break;
						 }								
					}
				}
}


/*寻迹直行到中心检测到路口     （倒向）     */
void zhongxin2_danxian_jingdu(u16 zhuansu1,u16 mangpao_time,u16 zhuansu2)
{
	zhixing2_danxian_jingdu(zhuansu1);
	mangpao2(mangpao_time);
	while(1)
	{
			    
					//前行
					 sudu(zhuansu2,zhuansu2,1,0);
			
		    	//检测路口
					if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
						{
							//停
						  sudu(0,0,0,1);
							break;
						}				
			
			
					//左边灰度
					for(;GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN5 )==1 || GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN4 )==1;)
					{
						 //左拐
             sudu(zhuansu2,zhuansu2,1,1);
						 //检测路口
						 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
						 {
							 //停
						   sudu(0,0,0,1);
							 break;
						 }								
					}
					
					//右边灰度
					for(;GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN9 )==1 || GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN8 )==1;)
					{
						 //右拐
             sudu(zhuansu2,zhuansu2,0,0);
						 //检测路口
						 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
						 {
							 //停
						   sudu(0,0,0,1);
							 break;
						 }						
					}
				}
}


/***************************************************盲跑程序***************************************************/
/***************************************************盲跑程序***************************************************/
/***************************************************盲跑程序***************************************************/
/***************************************************盲跑程序***************************************************/
/***************************************************盲跑程序***************************************************/
/***************************************************盲跑程序***************************************************/
/***************************************************盲跑程序***************************************************/
void mangpao1(u16 Time)//正向盲跑
{
	 sudu(7200,7200,0,1);
	 delay_ms(Time);
	 //停
	 sudu(0,0,0,1);
}


void mangpao2(u16 Time)//反向盲跑
{
	 sudu(7200,7200,1,0);
	 delay_ms(Time);
	 //停
	 sudu(0,0,0,1);
}

void mangpao1_danxian(void)//正向盲跑_单线
{
	 sudu(7200,7200,0,1);
	
	while(1)
	{
		if(GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN15 )==1)
		 {
			 break;
		 }
	}
	 
	while(1)
	{
		
			if(GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN15 )==0)
		 {
			 //停
			 sudu(0,0,0,1);
			 break;
		 }
	 }

}


void mangpao2_danxian(void)//反向盲跑_单线
{
	 sudu(7200,7200,1,0);
	
	 while(1)
	{
		if(GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN3 )==1)
		 {
			 break;
		 }
	}
	 
	while(1)
	{
		
			if(GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN3 )==0)
		 {
			 //停
			 sudu(0,0,0,1);
			 break;
		 }
	 }
}
void mangpao1_shuanxian(void)//正向盲跑_双线
{
	 sudu(7200,7200,0,1);
	while(1)
	 {
			if(GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN15 )==1)
		 {
			 break;
		 }
   }
	 while(1)
	 {
			if(GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN15 )==0)
		 {
			 break;
		 }
   }
	 while(1)
	 {
			if(GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN15 )==1)
		 {
			 break;
		 }
   }
	 while(1)
	 {
			if(GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN15 )==0)
		 {
			 //停
	     sudu(0,0,0,1);
			 break;
		 }
   }
	 
}


void mangpao2_shuanxian(void)//反向盲跑_双线
{
	 sudu(7200,7200,1,0);
	 while(1)
	 {
			if(GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN3 )==1)
		 {
			 break;
		 }
   }
	 while(1)
	 {
			if(GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN3 )==0)
		 {
			 break;
		 }
   }
	 while(1)
	 {
			if(GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN3 )==1)
		 {
			 break;
		 }
   }
	 while(1)
	 {
			if(GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN3 )==0)
		 {
			 //停
	     sudu(0,0,0,1);
			 break;
		 }
   }
}
void mangpao1_tiaosu(u16 zhuansu,u16 Time)//正向盲跑-调速
{
	 sudu(zhuansu,zhuansu,0,1);
	 delay_ms(Time);
	 //停
	 sudu(0,0,0,1);
}
void mangpao2_tiaosu(u16 zhuansu,u16 Time)//反向盲跑-调速
{
	 sudu(zhuansu,zhuansu,1,0);
	 delay_ms(Time);
	 //停
	 sudu(0,0,0,1);
}

void mangpao1_tiaozheng(u16 zhuansu)//正向盲跑-调整
{
	 sudu(zhuansu,zhuansu,0,1);
	  while(1)
	 {
			if(GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN8 )==1)
		 {
			 break;
		 }
   }
	 while(1)
	 {
			if(GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN8 )==0)
		 {
			 break;
		 }
   }
	 while(1)
	 {
			if(GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN8 )==1)
		 {
			 break;
		 }
   }
	 while(1)
	 {
			if(GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN8 )==0)
		 {
			 //停
	     sudu(0,0,0,1);
			 break;
		 }
   }
}

void mangpao1_zhongjian(u16 zhuansu)//正向盲跑-调整
{
	 sudu(zhuansu,zhuansu,0,1);
	 
	 while(1)
	 {
			if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1||GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
		 {
			 //停
	     sudu(0,0,0,1);
			 break;
		 }
   }
}
/***************************************************拐弯程序***************************************************/
/***************************************************拐弯程序***************************************************/
/***************************************************拐弯程序***************************************************/
/***************************************************拐弯程序***************************************************/
/***************************************************拐弯程序***************************************************/
/***************************************************拐弯程序***************************************************/
/***************************************************拐弯程序***************************************************/
//左拐加中间灰度调整
void zuoguai1(u16 zhuansu,u16 time)//10
{	
	//左拐
	sudu(zhuansu,zhuansu,1,1);
  delay_ms(time);
	while(1)
	{
		if(GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN15 )==1)
			{
				//停
				sudu(0,0,0,1);
				break;
			}		
	}		
}

//右拐加中间灰度调整
void youguai1(u16 zhuansu,u16 time)//10
{	
	//右拐
	sudu(zhuansu,zhuansu,0,0);
  delay_ms(time);
	while(1)
	{
		if(GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN15 )==1)
			{
				//停
				sudu(0,0,0,1);
				break;		
			}		
	}		
}

//左拐加中间灰度调整
void zuoguai2(u16 zhuansu,u16 time)//反方向左拐
{
	//左拐
	sudu(zhuansu,zhuansu,1,1);
  delay_ms(10);
	while(1)
	{
		if(GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN3 )==1)
			{
				//停
				sudu(0,0,0,1);
				break;
			}		
	}			
}

//右拐加中间灰度调整
void youguai2(u16 zhuansu,u16 time)//反方向右拐
{
  //右拐
	sudu(zhuansu,zhuansu,0,0);
  delay_ms(10);
	while(1)
	{
		if(GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN3 )==1)
			{
				//停
				sudu(0,0,0,1);
				break;
			}	
	}		
}
//左拐（盲拐）
void zuoguai1_mangguai(u16 zhuansu,u16 time)
{		
	//左拐
	sudu(zhuansu,zhuansu,1,1);
  delay_ms(time);
	
	//停
	sudu(0,0,0,1);
}

//右拐（盲拐）
void youguai1_mangguai(u16 zhuansu,u16 time)
{		
	//右拐
	sudu(zhuansu,zhuansu,0,0);
  delay_ms(time);
	
	//停
	sudu(0,0,0,1);
}

//右拐（检测）
void youguai1_jiance(u16 zhuansu)
{		
	//右拐
	sudu(zhuansu,zhuansu,0,0);
	while(1)
	{
		if(GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN8 )==1)
		{
			break;
		}
	}
	while(1)
	{
		if(GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN15 )==1)
		{
			//停
	    sudu(0,0,0,1);
			break;
		}
	}
	
}
/***************************************************出发拐弯程序***************************************************/
/***************************************************出发拐弯程序***************************************************/
/***************************************************出发拐弯程序***************************************************/
/***************************************************出发拐弯程序***************************************************/
/***************************************************出发拐弯程序***************************************************/
/***************************************************出发拐弯程序***************************************************/
/***************************************************出发拐弯程序***************************************************/
/***************************************************出发拐弯程序***************************************************/
void youguai_2_chufa(u16 zhuansu)
{		
	//右拐
	sudu(zhuansu,zhuansu,0,0);
	while(1)
	{
		if(GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN15 )==0)
			{
				break;
			}		
	}	
	while(1)
	{
		if(GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN15 )==1)
			{
				break;
			}		
	}	
  while(1)
	{
		if(GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN15 )==0)
			{
				break;
			}		
	}	
  while(1)
	{
		if(GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN15 )==1)
			{
				break;
			}		
	}		
  while(1)
	{
		if(GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN15 )==0)
			{
				sudu(0,0,0,1);
				break;
			}		
	}			
}

void youguai_2_chufa_hou(u16 zhuansu)
{		
	//右拐
	sudu(zhuansu,zhuansu,0,0);
	while(1)
	{
		if(GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN5 )==1)
			{
				break;
			}		
	}	
  while(1)
	{
		if(GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN5)==0)
			{
				sudu(0,0,0,1);
				break;
			}		
	}	
 
}

void youguai_2_chufa_hou1(u16 zhuansu)
{		
	//右拐
	sudu(zhuansu,zhuansu,0,0);
	while(1)
	{
		if(GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN4 )==1)
			{
				break;
			}		
	}	
  while(1)
	{
		if(GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN4)==0)
			{
				sudu(0,0,0,1);
				break;
			}		
	}	
 
}

void zhongxin1_shuangxian1(u16 zhuansu)
{
	sudu(zhuansu,zhuansu,0,1);
	while(1)
	{
		if(GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN15)==1)
				{
					sudu(0,0,0,1);
					break;
				}		
	}
	while(1)
	{
			 int sudu1 = 0;
			
			
					//前行
					 sudu(zhuansu,zhuansu,0,1);
			
		    	//检测路口
				 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
				 {
					 //停
						sudu(0,0,0,1);
					 break;
				 }
	 }
			
}
/***************************************************返回盲跑程序***************************************************/
/***************************************************返回盲跑程序***************************************************/
/***************************************************返回盲跑程序***************************************************/
/***************************************************返回盲跑程序***************************************************/
/***************************************************返回盲跑程序***************************************************/
/***************************************************返回盲跑程序***************************************************/
/***************************************************返回盲跑程序***************************************************/
void mangpao1_fanhui(u16 zhuansu1,u16 zhuansu2)//正向盲跑-返回
{
	 sudu(zhuansu1,zhuansu1,0,1);
	  while(1)
	 {
			if(GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN15 )==1)
		 {
			 break;
		 }
   }
	 while(1)
	 {
			if(GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN15 )==0)
		 {
			 break;
		 }
   }
	 while(1)
	 {
			if(GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN15 )==1)
		 {
			 break;
		 }
   }
	  while(1)
	 {
			if(GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN15 )==0)
		 {
			 sudu(zhuansu2,zhuansu2,0,1);
			 break;
		 }
   }
			 delay_ms(1000);
//			 delay_ms(1000);
//			 delay_ms(1000);
	     //停
	     sudu(0,0,0,1);

	 while(1)
	 {
			if(GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN15 )==1)
		 {
			 //停
	     sudu(0,0,0,1);
			 break;
		 }
   }
}

void mangpao2_fanhui(u16 zhuansu)//正向盲跑-返回
{
	 sudu(zhuansu,zhuansu,1,0);
	  while(1)
	 {
			if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN15 )==1)
		 {
			 //停
	     sudu(0,0,0,1);
		 }
   }
	
}

/***************************************************识别调整程序***************************************************/
/***************************************************识别调整程序***************************************************/
/***************************************************识别调整程序***************************************************/
/***************************************************识别调整程序***************************************************/
/***************************************************识别调整程序***************************************************/
/***************************************************识别调整程序***************************************************/
/***************************************************识别调整程序***************************************************/
void tiaozheng_shibie(u16 zhuansu)
{
	//后退
	sudu(zhuansu,zhuansu,1,0);
	while(1)
	{				
		    	//检测路口
				 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1||GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
				 {
					 //停
						sudu(0,0,0,1);
					 break;
				 }
	}
			
}





////============================================总程序===================================================

void chufaqu_saoma(void)
{
	mangpao1_shuanxian();
	mangpao1(100);
	mangpao1(100);
	mangpao1(100);
	zhongxin1_shuangxian1(sudu_a);
//	zhongxin1_shuangxian(7200,5000);
//	youguai_2_chufa(5000);
//	youguai_2_chufa_hou(5000);

	youguai1_mangguai(5000,930);//1030
	mangpao1_zhongjian(sudu_a);

	zhixing1_chufa(sudu_a);
	mangpao1(120);
	zhixing1(sudu_a);
	mangpao1(mangpao_time_shuang);
	zhongxin1(sudu_a,mangpao_time_shuang,3000);
}


void saoma_banququ(void)
{
	zhixing2(7200);
	mangpao2(100);
	zhongxin2(7200,80,5000);
	delay_ms(1000);
}
void youguai_and_tiaozheng(void)
{
//	tiaozheng_shibie(5000);
//	youguai1(5000,500);
//	youguai1_jiance(5000);
	youguai1_mangguai(5000,830);//1030
//	while(1)
//	{
//		
//	}
	zhixing1_danxian_jingdu_zuo(sudu_b);
	mangpao1_tiaozheng(sudu_b);
	
	
	//调整
	zhongxin2_danxian_jingdu(sudu_b,180,sudu_b);
	zhixing1_danxian_jingdu(sudu_b);
}



void banququ_1_lanse_banququ(void)
{
	Servo_left_Grab(80);
	
	Servo_over(10);
	zhixing2_danxian_jingdu(sudu_b);
	mangpao2_tiaosu(sudu_b,maopao_time);
	zhixing2_danxian_jingdu(sudu_b);
	
  Servo_left_Place(100);
	
	Servo_over(10);
	zhixing1_danxian_jingdu(sudu_b);
	mangpao1_tiaosu(sudu_b,maopao_time);
	zhixing1_danxian_jingdu(sudu_b);
}

void banququ_2_lanse_banququ(void)
{
	Servo_up_Grab(80);
	
	Servo_over(10);
	zhixing2_danxian_jingdu(sudu_b);
	mangpao2_tiaosu(sudu_b,maopao_time);
	zhixing2_danxian_jingdu(sudu_b);
	
  Servo_left_Place(100);
	
	Servo_over(10);
	zhixing1_danxian_jingdu(sudu_b);
	mangpao1_tiaosu(sudu_b,maopao_time);
	zhixing1_danxian_jingdu(sudu_b);
}

void banququ_3_lanse_banququ(void)
{
	Servo_right_Grab(80);
	
	Servo_over(10);
	zhixing2_danxian_jingdu(sudu_b);
	mangpao2_tiaosu(sudu_b,maopao_time);
	zhixing2_danxian_jingdu(sudu_b);
	
  Servo_left_Place(100);
	
	Servo_over(10);
	zhixing1_danxian_jingdu(sudu_b);
	mangpao1_tiaosu(sudu_b,maopao_time);
	zhixing1_danxian_jingdu(sudu_b);
}

void banququ_1_lvse_banququ(void)
{
	Servo_left_Grab(80);
	
	Servo_over(10);
	zhixing2_danxian_jingdu(sudu_b);
	mangpao2_tiaosu(sudu_b,maopao_time);
	zhixing2_danxian_jingdu(sudu_b);
	
  Servo_up_Place(80);
	
	Servo_over(10);
	zhixing1_danxian_jingdu(sudu_b);
	mangpao1_tiaosu(sudu_b,maopao_time);
	zhixing1_danxian_jingdu(sudu_b);
}	

void banququ_2_lvse_banququ(void)
{	
	Servo_up_Grab(80);
	
	Servo_over(10);
	zhixing2_danxian_jingdu(sudu_b);
	mangpao2_tiaosu(sudu_b,maopao_time);
	zhixing2_danxian_jingdu(sudu_b);
	
  Servo_up_Place(80);
	
	Servo_over(10);
	zhixing1_danxian_jingdu(sudu_b);
	mangpao1_tiaosu(sudu_b,maopao_time);
	zhixing1_danxian_jingdu(sudu_b);
}	

void banququ_3_lvse_banququ(void)
{
	Servo_right_Grab(80);
	
	Servo_over(10);
	zhixing2_danxian_jingdu(sudu_b);
	mangpao2_tiaosu(sudu_b,maopao_time);
	zhixing2_danxian_jingdu(sudu_b);
	
  Servo_up_Place(80);
	
	Servo_over(10);
	zhixing1_danxian_jingdu(sudu_b);
	mangpao1_tiaosu(sudu_b,maopao_time);
	zhixing1_danxian_jingdu(sudu_b);
}	

void banququ_1_hongse_banququ(void)
{
	Servo_left_Grab(80);
	
	Servo_over(10);
	zhixing2_danxian_jingdu(sudu_b);
	mangpao2_tiaosu(sudu_b,maopao_time);
	zhixing2_danxian_jingdu(sudu_b);
	
  Servo_right_Place(100);
	
	Servo_over(10);
	zhixing1_danxian_jingdu(sudu_b);
	mangpao1_tiaosu(sudu_b,maopao_time);
	zhixing1_danxian_jingdu(sudu_b);
}	

void banququ_2_hongse_banququ(void)
{
	Servo_up_Grab(80);
	
	Servo_over(10);
	zhixing2_danxian_jingdu(sudu_b);
	mangpao2_tiaosu(sudu_b,maopao_time);
	zhixing2_danxian_jingdu(sudu_b);
	
  Servo_right_Place(100);
	
	Servo_over(10);
	zhixing1_danxian_jingdu(sudu_b);
	mangpao1_tiaosu(sudu_b,maopao_time);
	zhixing1_danxian_jingdu(sudu_b);
}

void banququ_3_hongse_banququ(void)
{
	Servo_right_Grab(80);
	
	Servo_over(10);
	zhixing2_danxian_jingdu(sudu_b);
	mangpao2_tiaosu(sudu_b,maopao_time);
	zhixing2_danxian_jingdu(sudu_b);
	
  Servo_right_Place(100);
	
	Servo_over(10);
	zhixing1_danxian_jingdu(sudu_b);
	mangpao1_tiaosu(sudu_b,maopao_time);
	zhixing1_danxian_jingdu(sudu_b);
}	

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void banququ_1_lanse_banququ_home(void)
{
	Servo_left_Grab(80);
	
	Servo_over(10);
	zhixing2_danxian_jingdu(sudu_b);
	mangpao2_tiaosu(sudu_b,maopao_time);
	zhixing2_danxian_jingdu(sudu_b);
	
  Servo_left_Place(100);
	
	Servo_over(10);
}

void banququ_2_lanse_banququ_home(void)
{
	Servo_up_Grab(80);
	
	Servo_over(10);
	zhixing2_danxian_jingdu(sudu_b);
	mangpao2_tiaosu(sudu_b,maopao_time);
	zhixing2_danxian_jingdu(sudu_b);
	
  Servo_left_Place(100);
	
	Servo_over(10);
}

void banququ_3_lanse_banququ_home(void)
{
	Servo_right_Grab(80);
	
	Servo_over(10);
	zhixing2_danxian_jingdu(sudu_b);
	mangpao2_tiaosu(sudu_b,maopao_time);
	zhixing2_danxian_jingdu(sudu_b);
	
  Servo_left_Place(100);
	
	Servo_over(10);
}

void banququ_1_lvse_banququ_home(void)
{
	Servo_left_Grab(80);
	
	Servo_over(10);
	zhixing2_danxian_jingdu(sudu_b);
	mangpao2_tiaosu(sudu_b,maopao_time);
	zhixing2_danxian_jingdu(sudu_b);
	
  Servo_up_Place(80);
	
	Servo_over(10);
}	

void banququ_2_lvse_banququ_home(void)
{
	Servo_up_Grab(80);
	
	Servo_over(10);
	zhixing2_danxian_jingdu(sudu_b);
	mangpao2_tiaosu(sudu_b,maopao_time);
	zhixing2_danxian_jingdu(sudu_b);
	
  Servo_up_Place(80);
	
	Servo_over(10);
}	

void banququ_3_lvse_banququ_home(void)
{
	Servo_right_Grab(80);
	
	Servo_over(10);
	zhixing2_danxian_jingdu(sudu_b);
	mangpao2_tiaosu(sudu_b,maopao_time);
	zhixing2_danxian_jingdu(sudu_b);
	
  Servo_up_Place(80);
	
	Servo_over(10);
}	

void banququ_1_hongse_banququ_home(void)
{
	Servo_left_Grab(80);
	
	Servo_over(10);
	zhixing2_danxian_jingdu(sudu_b);
	mangpao2_tiaosu(sudu_b,maopao_time);
	zhixing2_danxian_jingdu(sudu_b);
	
  Servo_right_Place(100);
	
	Servo_over(10);
}	

void banququ_2_hongse_banququ_home(void)
{
	Servo_up_Grab(80);
	
	Servo_over(10);
	zhixing2_danxian_jingdu(sudu_b);
	mangpao2_tiaosu(sudu_b,maopao_time);
	zhixing2_danxian_jingdu(sudu_b);
	
  Servo_right_Place(100);
	
	Servo_over(10);
}

void banququ_3_hongse_banququ_home(void)
{
	Servo_right_Grab(80);
	
	Servo_over(10);
	zhixing2_danxian_jingdu(sudu_b);
	mangpao2_tiaosu(sudu_b,maopao_time);
	zhixing2_danxian_jingdu(sudu_b);
	
  Servo_right_Place(100);
	
	Servo_over(10);
}	

void fancheng(void)
{
	
	//返程
  zhongxin1(sudu_a,80,5000);
	youguai1(5000,500);
	//  youguai1_jiance(u16 zhuansu);
	
	zhixing1(sudu_a);
	mangpao1(mangpao_time_shuang);
	zhixing1(sudu_a);
	mangpao1(mangpao_time_shuang);
	zhixing1(sudu_a);
	mangpao1(300);
	
	zuoguai1_mangguai(5000,800);	
	mangpao1_fanhui(sudu_a,sudu_a);
	
//	mangpao2_fanhui(5000);

}	



