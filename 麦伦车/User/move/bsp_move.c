#include "bsp_move.h"
#include "bsp_adc.h"
#include "bsp_led.h"
#include "bsp_encoder.h"
#include "bsp_timer.h" 
#include "bsp_GeneralTim.h"
#include "Robotic_arm_function.h" 
#include <Servo.h>

  int Encoder_Left;             //����������������
  int Encoder_Right;						//�ұ��������������
// ADC1ת���ĵ�ѹֵͨ��MDA��ʽ����SRAM
  extern __IO uint16_t ADC_ConvertedValue[NOFCHANEL];
// �ֲ����������ڱ���ת�������ĵ�ѹֵ 	 
  float ADC_ConvertedValueLocal[NOFCHANEL]; 

int maopao_time=350;//ץ��ä��ʱ��

int sudu_a=6000,//˫���ٶ�
	  sudu_b=5000;//�����ٶ�

int mangpao_time_shuang=80;
 
 
 //ת��
// extern  int  zhuanshu=7200;
/******************************************************Ѱ������***************************************************/
/******************************************************Ѱ������***************************************************/
/******************************************************Ѱ������***************************************************/
/******************************************************Ѱ������***************************************************/
/******************************************************Ѱ������***************************************************/
/******************************************************Ѱ������***************************************************/
/******************************************************Ѱ������***************************************************/
/******************************************************Ѱ������***************************************************/
/******************************************************Ѱ������***************************************************/
/*Ѱ��ֱ�е���⵽·��     ������     */
void zhixing1(u16 zhuansu)
{
	while(1)
	{
			 int time = 10;
			
			
					//ǰ��
					 sudu(zhuansu,zhuansu,0,1);
		
		
			
		    	//���·��
				 if(GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN8 )==1 || GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN12 )==1)
				 {
					 //ͣ
						sudu(0,0,0,1);
					 break;
				 }
			
			
					//��߻Ҷ�
					for(;GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN7 )==1;)
					{
						 //���
					   sudu(zhuansu,zhuansu,1,1);
						 //���·��
						 if(GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN8 )==1 || GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN12 )==1)
						 {
							 //ͣ
						   sudu(0,0,0,1);
							 break;
						 }						
					}
					
					//�ұ߻Ҷ�
					for(;GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN13 )==1;)
					{
						 //�ҹ�
             sudu(zhuansu,zhuansu,0,0);						
						 //���·��
						 if(GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN8 )==1 || GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN12 )==1)
						 {
							 //ͣ
						   sudu(0,0,0,1);
							 break;
						 }											
					}
				}
				
}

/*Ѱ��ֱ�е���⵽·��     ������     */
void zhixing2(u16 zhuansu)
{
	while(1)
	{
			 int time = 10;
			    
					//ǰ��
					 sudu(zhuansu,zhuansu,1,0);
			
		    	//���·��
				 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN15 )==1 || GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN12 )==1)
				 {
					 //ͣ
						sudu(0,0,0,1);
					 break;
				 }
			
			
					//��߻Ҷ�
					for(;GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN5 )==1;)
					{
						 //���
             sudu(zhuansu,zhuansu,1,1);
						 //���·��
						 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN15 )==1 || GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN12 )==1)
						 {
							 //ͣ
						   sudu(0,0,0,1);
							 break;
						 }							
					}
					
					//�ұ߻Ҷ�
					for(;GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN9 )==1;)
					{
						 //�ҹ�
             sudu(zhuansu,zhuansu,0,0);
						 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN15 )==1 || GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN12 )==1)
						  {
								//ͣ
						    sudu(0,0,0,1);
							  break;
						  }					
					}
				}
				
}
/*Ѱ��ֱ�е���⵽·��     ������     */
void zhixing1_danxian_jingdu(u16 zhuansu)
{
	while(1)
	{
			
			
					//ǰ��
					 sudu(zhuansu,zhuansu,0,1);
			
		    	//���·��
				 if(GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN8 )==1 || GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN12 )==1)
				 {
					 //ͣ
						sudu(0,0,0,1);
					 break;
				 }
			
			
					//��߻Ҷ�
					for(;GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN7 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN6 )==1;)
					{
						 //���
					   sudu(zhuansu,zhuansu,1,1);
						 //���·��
						 if(GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN8 )==1 || GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN12 )==1)
						 {
							 //ͣ
						   sudu(0,0,0,1);
							 break;
						 }						
					}
					
					//�ұ߻Ҷ�
					for(;GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN13 )==1 || GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN14 )==1;)
					{
						 //�ҹ�
             sudu(zhuansu,zhuansu,0,0);						
						 //���·��
						 if(GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN8 )==1 || GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN12 )==1)
						 {
							 //ͣ
						   sudu(0,0,0,1);
							 break;
						 }											
					}
				}
				
}

/*Ѱ��ֱ�е���⵽·��     ������     */
void zhixing2_danxian_jingdu(u16 zhuansu)
{
	while(1)
	{
			    
					//ǰ��
					 sudu(zhuansu,zhuansu,1,0);
			
		    	//���·��
				 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN15 )==1 || GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN12 )==1)
				 {
					 //ͣ
						sudu(0,0,0,1);
					 break;
				 }
			
			
					//��߻Ҷ�
					for(;GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN5 )==1 || GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN4 )==1;)
					{
						 //���
             sudu(zhuansu,zhuansu,1,1);
						 //���·��
						 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN15 )==1 || GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN12 )==1)
						 {
							 //ͣ
						   sudu(0,0,0,1);
							 break;
						 }							
					}
					
					//�ұ߻Ҷ�
					for(;GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN9 )==1 || GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN8 )==1;)
					{
						 //�ҹ�
             sudu(zhuansu,zhuansu,0,0);
						 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN15 )==1 || GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN12 )==1)
						  {
								//ͣ
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
			
			
					//ǰ��
					 sudu(zhuansu,zhuansu,0,1);
		
		
			
		    	//���·��
				 if(GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN8 )==1)
				 {
					 //ͣ
						sudu(0,0,0,1);
					 break;
				 }
			
			
					//��߻Ҷ�
					for(;GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN7 )==1;)
					{
						 //���
					   sudu(zhuansu,zhuansu,1,1);
						 //���·��
						 if(GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN8 )==1)
						 {
							 //ͣ
						   sudu(0,0,0,1);
							 break;
						 }						
					}
					
					//�ұ߻Ҷ�
					for(;GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN13 )==1;)
					{
						 //�ҹ�
             sudu(zhuansu,zhuansu,0,0);						
						 //���·��
						 if(GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN8 )==1)
						 {
							 //ͣ
						   sudu(0,0,0,1);
							 break;
						 }											
					}
				}
				
}

/*Ѱ��ֱ�е���⵽·��     ������     */
void zhixing1_danxian_jingdu_zuo(u16 zhuansu)
{
	while(1)
	{
			
			
					//ǰ��
					 sudu(zhuansu,zhuansu,0,1);
			
		    	//���·��
				 if(GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN8 )==1)
				 {
					 //ͣ
						sudu(0,0,0,1);
					 break;
				 }
			
			
					//��߻Ҷ�
					for(;GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN7 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN6 )==1;)
					{
						 //���
					   sudu(zhuansu,zhuansu,1,1);
						 //���·��
						 if(GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN8 )==1)
						 {
							 //ͣ
						   sudu(0,0,0,1);
							 break;
						 }						
					}
					
					//�ұ߻Ҷ�
					for(;GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN13 )==1 || GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN14 )==1;)
					{
						 //�ҹ�
             sudu(zhuansu,zhuansu,0,0);						
						 //���·��
						 if(GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN8 )==1)
						 {
							 //ͣ
						   sudu(0,0,0,1);
							 break;
						 }											
					}
				}
				
}


/***************************************************Ѱ�������ĳ���***************************************************/
/***************************************************Ѱ�������ĳ���***************************************************/
/***************************************************Ѱ�������ĳ���***************************************************/
/***************************************************Ѱ�������ĳ���***************************************************/
/***************************************************Ѱ�������ĳ���***************************************************/
/***************************************************Ѱ�������ĳ���***************************************************/
/***************************************************Ѱ�������ĳ���***************************************************/
/*Ѱ��ֱ�е����ļ�⵽·��     ������     */
void zhongxin1(u16 zhuansu1,u16 mangpao_time,u16 zhuansu2)
{
	zhixing1(zhuansu1);
	mangpao1(mangpao_time);
	while(1)
	{
			 int sudu1 = 0;
			
			
					//ǰ��
					 sudu(zhuansu2,zhuansu2,0,1);
			
		    	//���·��
				 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
				 {
					 //ͣ
						sudu(0,0,0,1);
					 break;
				 }
			
			
					//��߻Ҷ�
					for(;GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN7 )==1;)
					{
						 //���
					   sudu(zhuansu2,zhuansu2,1,1);
						 //���·��
						 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
						 {
							 //ͣ
						   sudu(0,0,0,1);
							 break;
						 }				
					}
					
					//�ұ߻Ҷ�
					for(;GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN13 )==1;)
					{
						 //�ҹ�
             sudu(zhuansu2,zhuansu2,0,0);						
						 //���·��
						 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
						 {
							 //ͣ
						   sudu(0,0,0,1);
							 break;
						 }								
					}
				}
}


/*Ѱ��ֱ�е����ļ�⵽·��     ������     */
void zhongxin2(u16 zhuansu1,u16 mangpao_time,u16 zhuansu2)
{
	zhixing2(zhuansu1);
	mangpao2(mangpao_time);
	while(1)
	{
			    
					//ǰ��
					 sudu(zhuansu2,zhuansu2,1,0);
			
		    	//���·��
					if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
						{
							//ͣ
						  sudu(0,0,0,1);
							break;
						}				
			
			
					//��߻Ҷ�
					for(;GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN5 )==1;)
					{
						 //���
             sudu(zhuansu2,zhuansu2,1,1);
						 //���·��
						 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
						 {
							 //ͣ
						   sudu(0,0,0,1);
							 break;
						 }								
					}
					
					//�ұ߻Ҷ�
					for(;GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN9 )==1;)
					{
						 //�ҹ�
             sudu(zhuansu2,zhuansu2,0,0);
						 //���·��
						 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
						 {
							 //ͣ
						   sudu(0,0,0,1);
							 break;
						 }						
					}
				}
}
/*Ѱ��ֱ�е����ļ�⵽·��     �����򣩣����ߣ�     */
void zhongxin1_danxian(u16 zhuansu1,u16 zhuansu2)
{
	zhixing1(zhuansu1);
	mangpao1_danxian();
	while(1)
	{
			 int sudu1 = 0;
			
			
					//ǰ��
					 sudu(zhuansu2,zhuansu2,0,1);
			
		    	//���·��
				 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
				 {
					 //ͣ
						sudu(0,0,0,1);
					 break;
				 }
			
			
					//��߻Ҷ�
					for(;GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN7 )==1;)
					{
						 //���
					   sudu(zhuansu2,zhuansu2,1,1);
						 //���·��
						 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
						 {
							 //ͣ
						   sudu(0,0,0,1);
							 break;
						 }				
					}
					
					//�ұ߻Ҷ�
					for(;GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN13 )==1;)
					{
						 //�ҹ�
             sudu(zhuansu2,zhuansu2,0,0);						
						 //���·��
						 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
						 {
							 //ͣ
						   sudu(0,0,0,1);
							 break;
						 }								
					}
				}
}


/*Ѱ��ֱ�е����ļ�⵽·��     ������ �����ߣ�    */
void zhongxin2_danxian(u16 zhuansu1,u16 zhuansu2)
{
	zhixing2(zhuansu1);
	mangpao2_danxian();
	while(1)
	{
			    
					//ǰ��
					 sudu(zhuansu2,zhuansu2,1,0);
			
		    	//���·��
					if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
						{
							//ͣ
						  sudu(0,0,0,1);
							break;
						}				
			
			
					//��߻Ҷ�
					for(;GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN5 )==1;)
					{
						 //���
             sudu(zhuansu2,zhuansu2,1,1);
						 //���·��
						 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
						 {
							 //ͣ
						   sudu(0,0,0,1);
							 break;
						 }								
					}
					
					//�ұ߻Ҷ�
					for(;GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN9 )==1;)
					{
						 //�ҹ�
             sudu(zhuansu2,zhuansu2,0,0);
						 //���·��
						 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
						 {
							 //ͣ
						   sudu(0,0,0,1);
							 break;
						 }						
					}
				}
}

/*Ѱ��ֱ�е����ļ�⵽·��     ������ ��˫�ߣ�    */
void zhongxin1_shuangxian(u16 zhuansu1,u16 zhuansu2)
{
	zhixing1(zhuansu1);
	mangpao1_shuanxian();
	while(1)
	{
			 int sudu1 = 0;
			
			
					//ǰ��
					 sudu(zhuansu2,zhuansu2,0,1);
			
		    	//���·��
				 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
				 {
					 //ͣ
						sudu(0,0,0,1);
					 break;
				 }
			
			
					//��߻Ҷ�
					for(;GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN7 )==1;)
					{
						 //���
					   sudu(zhuansu2,zhuansu2,1,1);
						 //���·��
						 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
						 {
							 //ͣ
						   sudu(0,0,0,1);
							 break;
						 }				
					}
					
					//�ұ߻Ҷ�
					for(;GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN13 )==1;)
					{
						 //�ҹ�
             sudu(zhuansu2,zhuansu2,0,0);						
						 //���·��
						 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
						 {
							 //ͣ
						   sudu(0,0,0,1);
							 break;
						 }								
					}
				}
}


/*Ѱ��ֱ�е����ļ�⵽·��     ������  ��˫�ߣ�    */
void zhongxin2_shuangxian(u16 zhuansu1,u16 zhuansu2)
{
	zhixing2(zhuansu1);
	mangpao1_shuanxian();
	while(1)
	{
			    
					//ǰ��
					 sudu(zhuansu2,zhuansu2,1,0);
			
		    	//���·��
					if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
						{
							//ͣ
						  sudu(0,0,0,1);
							break;
						}				
			
			
					//��߻Ҷ�
					for(;GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN5 )==1;)
					{
						 //���
             sudu(zhuansu2,zhuansu2,1,1);
						 //���·��
						 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
						 {
							 //ͣ
						   sudu(0,0,0,1);
							 break;
						 }								
					}
					
					//�ұ߻Ҷ�
					for(;GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN9 )==1;)
					{
						 //�ҹ�
             sudu(zhuansu2,zhuansu2,0,0);
						 //���·��
						 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
						 {
							 //ͣ
						   sudu(0,0,0,1);
							 break;
						 }						
					}
				}
}
/*Ѱ��ֱ�е����ļ�⵽·��     ������     */
void zhongxin1_danxian_jingdu(u16 zhuansu1,u16 mangpao_time,u16 zhuansu2)
{
	zhixing1_danxian_jingdu(zhuansu1);
	mangpao1(mangpao_time);
	while(1)
	{
			
			
					//ǰ��
					 sudu(zhuansu2,zhuansu2,0,1);
			
		    	//���·��
				 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
				 {
					 //ͣ
						sudu(0,0,0,1);
					 break;
				 }
			
			
					//��߻Ҷ�
					for(;GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN7 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN6 )==1;)
					{
						 //���
					   sudu(zhuansu2,zhuansu2,1,1);
						 //���·��
						 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
						 {
							 //ͣ
						   sudu(0,0,0,1);
							 break;
						 }				
					}
					
					//�ұ߻Ҷ�
					for(;GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN13 )==1 || GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN14 )==1;)
					{
						 //�ҹ�
             sudu(zhuansu2,zhuansu2,0,0);						
						 //���·��
						 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
						 {
							 //ͣ
						   sudu(0,0,0,1);
							 break;
						 }								
					}
				}
}


/*Ѱ��ֱ�е����ļ�⵽·��     ������     */
void zhongxin2_danxian_jingdu(u16 zhuansu1,u16 mangpao_time,u16 zhuansu2)
{
	zhixing2_danxian_jingdu(zhuansu1);
	mangpao2(mangpao_time);
	while(1)
	{
			    
					//ǰ��
					 sudu(zhuansu2,zhuansu2,1,0);
			
		    	//���·��
					if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
						{
							//ͣ
						  sudu(0,0,0,1);
							break;
						}				
			
			
					//��߻Ҷ�
					for(;GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN5 )==1 || GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN4 )==1;)
					{
						 //���
             sudu(zhuansu2,zhuansu2,1,1);
						 //���·��
						 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
						 {
							 //ͣ
						   sudu(0,0,0,1);
							 break;
						 }								
					}
					
					//�ұ߻Ҷ�
					for(;GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN9 )==1 || GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN8 )==1;)
					{
						 //�ҹ�
             sudu(zhuansu2,zhuansu2,0,0);
						 //���·��
						 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
						 {
							 //ͣ
						   sudu(0,0,0,1);
							 break;
						 }						
					}
				}
}


/***************************************************ä�ܳ���***************************************************/
/***************************************************ä�ܳ���***************************************************/
/***************************************************ä�ܳ���***************************************************/
/***************************************************ä�ܳ���***************************************************/
/***************************************************ä�ܳ���***************************************************/
/***************************************************ä�ܳ���***************************************************/
/***************************************************ä�ܳ���***************************************************/
void mangpao1(u16 Time)//����ä��
{
	 sudu(7200,7200,0,1);
	 delay_ms(Time);
	 //ͣ
	 sudu(0,0,0,1);
}


void mangpao2(u16 Time)//����ä��
{
	 sudu(7200,7200,1,0);
	 delay_ms(Time);
	 //ͣ
	 sudu(0,0,0,1);
}

void mangpao1_danxian(void)//����ä��_����
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
			 //ͣ
			 sudu(0,0,0,1);
			 break;
		 }
	 }

}


void mangpao2_danxian(void)//����ä��_����
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
			 //ͣ
			 sudu(0,0,0,1);
			 break;
		 }
	 }
}
void mangpao1_shuanxian(void)//����ä��_˫��
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
			 //ͣ
	     sudu(0,0,0,1);
			 break;
		 }
   }
	 
}


void mangpao2_shuanxian(void)//����ä��_˫��
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
			 //ͣ
	     sudu(0,0,0,1);
			 break;
		 }
   }
}
void mangpao1_tiaosu(u16 zhuansu,u16 Time)//����ä��-����
{
	 sudu(zhuansu,zhuansu,0,1);
	 delay_ms(Time);
	 //ͣ
	 sudu(0,0,0,1);
}
void mangpao2_tiaosu(u16 zhuansu,u16 Time)//����ä��-����
{
	 sudu(zhuansu,zhuansu,1,0);
	 delay_ms(Time);
	 //ͣ
	 sudu(0,0,0,1);
}

void mangpao1_tiaozheng(u16 zhuansu)//����ä��-����
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
			 //ͣ
	     sudu(0,0,0,1);
			 break;
		 }
   }
}

void mangpao1_zhongjian(u16 zhuansu)//����ä��-����
{
	 sudu(zhuansu,zhuansu,0,1);
	 
	 while(1)
	 {
			if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1||GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
		 {
			 //ͣ
	     sudu(0,0,0,1);
			 break;
		 }
   }
}
/***************************************************�������***************************************************/
/***************************************************�������***************************************************/
/***************************************************�������***************************************************/
/***************************************************�������***************************************************/
/***************************************************�������***************************************************/
/***************************************************�������***************************************************/
/***************************************************�������***************************************************/
//��ռ��м�Ҷȵ���
void zuoguai1(u16 zhuansu,u16 time)//10
{	
	//���
	sudu(zhuansu,zhuansu,1,1);
  delay_ms(time);
	while(1)
	{
		if(GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN15 )==1)
			{
				//ͣ
				sudu(0,0,0,1);
				break;
			}		
	}		
}

//�ҹռ��м�Ҷȵ���
void youguai1(u16 zhuansu,u16 time)//10
{	
	//�ҹ�
	sudu(zhuansu,zhuansu,0,0);
  delay_ms(time);
	while(1)
	{
		if(GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN15 )==1)
			{
				//ͣ
				sudu(0,0,0,1);
				break;		
			}		
	}		
}

//��ռ��м�Ҷȵ���
void zuoguai2(u16 zhuansu,u16 time)//���������
{
	//���
	sudu(zhuansu,zhuansu,1,1);
  delay_ms(10);
	while(1)
	{
		if(GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN3 )==1)
			{
				//ͣ
				sudu(0,0,0,1);
				break;
			}		
	}			
}

//�ҹռ��м�Ҷȵ���
void youguai2(u16 zhuansu,u16 time)//�������ҹ�
{
  //�ҹ�
	sudu(zhuansu,zhuansu,0,0);
  delay_ms(10);
	while(1)
	{
		if(GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN3 )==1)
			{
				//ͣ
				sudu(0,0,0,1);
				break;
			}	
	}		
}
//��գ�ä�գ�
void zuoguai1_mangguai(u16 zhuansu,u16 time)
{		
	//���
	sudu(zhuansu,zhuansu,1,1);
  delay_ms(time);
	
	//ͣ
	sudu(0,0,0,1);
}

//�ҹգ�ä�գ�
void youguai1_mangguai(u16 zhuansu,u16 time)
{		
	//�ҹ�
	sudu(zhuansu,zhuansu,0,0);
  delay_ms(time);
	
	//ͣ
	sudu(0,0,0,1);
}

//�ҹգ���⣩
void youguai1_jiance(u16 zhuansu)
{		
	//�ҹ�
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
			//ͣ
	    sudu(0,0,0,1);
			break;
		}
	}
	
}
/***************************************************�����������***************************************************/
/***************************************************�����������***************************************************/
/***************************************************�����������***************************************************/
/***************************************************�����������***************************************************/
/***************************************************�����������***************************************************/
/***************************************************�����������***************************************************/
/***************************************************�����������***************************************************/
/***************************************************�����������***************************************************/
void youguai_2_chufa(u16 zhuansu)
{		
	//�ҹ�
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
	//�ҹ�
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
	//�ҹ�
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
			
			
					//ǰ��
					 sudu(zhuansu,zhuansu,0,1);
			
		    	//���·��
				 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1 || GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
				 {
					 //ͣ
						sudu(0,0,0,1);
					 break;
				 }
	 }
			
}
/***************************************************����ä�ܳ���***************************************************/
/***************************************************����ä�ܳ���***************************************************/
/***************************************************����ä�ܳ���***************************************************/
/***************************************************����ä�ܳ���***************************************************/
/***************************************************����ä�ܳ���***************************************************/
/***************************************************����ä�ܳ���***************************************************/
/***************************************************����ä�ܳ���***************************************************/
void mangpao1_fanhui(u16 zhuansu1,u16 zhuansu2)//����ä��-����
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
	     //ͣ
	     sudu(0,0,0,1);

	 while(1)
	 {
			if(GPIO_ReadInputDataBit(GPIOB,SHUZIHUIDU_GPIO_PIN15 )==1)
		 {
			 //ͣ
	     sudu(0,0,0,1);
			 break;
		 }
   }
}

void mangpao2_fanhui(u16 zhuansu)//����ä��-����
{
	 sudu(zhuansu,zhuansu,1,0);
	  while(1)
	 {
			if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN15 )==1)
		 {
			 //ͣ
	     sudu(0,0,0,1);
		 }
   }
	
}

/***************************************************ʶ���������***************************************************/
/***************************************************ʶ���������***************************************************/
/***************************************************ʶ���������***************************************************/
/***************************************************ʶ���������***************************************************/
/***************************************************ʶ���������***************************************************/
/***************************************************ʶ���������***************************************************/
/***************************************************ʶ���������***************************************************/
void tiaozheng_shibie(u16 zhuansu)
{
	//����
	sudu(zhuansu,zhuansu,1,0);
	while(1)
	{				
		    	//���·��
				 if(GPIO_ReadInputDataBit(GPIOA,SHUZIHUIDU_GPIO_PIN11 )==1||GPIO_ReadInputDataBit(GPIOC,SHUZIHUIDU_GPIO_PIN9 )==1)
				 {
					 //ͣ
						sudu(0,0,0,1);
					 break;
				 }
	}
			
}





////============================================�ܳ���===================================================

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
	
	
	//����
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
	
	//����
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



