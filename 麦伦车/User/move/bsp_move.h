#ifndef __BSP_MOVE_H
#define __BSP_MOVE_H
	 

#include "stm32f10x.h" 
#include "bsp_delay.h"
#include "bsp_GeneralTim.h" 


//Ѱ������
void zhixing1(u16 zhuansu);//������
void zhixing2(u16 zhuansu);//������
void zhixing1_danxian_jingdu(u16 zhuansu);//���򾫶���
void zhixing2_danxian_jingdu(u16 zhuansu);//���򾫶���
void zhixing1_chufa(u16 zhuansu);//������_����
void zhixing1_danxian_jingdu_zuo(u16 zhuansu);//���򾫶���_��

//Ѱ�������ĳ���
void zhongxin1(u16 zhuansu1,u16 mangpao_time,u16 zhuansu2);/*Ѱ��ֱ�е����ļ�⵽·��     ������     */
void zhongxin2(u16 zhuansu1,u16 mangpao_time,u16 zhuansu2);/*Ѱ��ֱ�е����ļ�⵽·��     ������     */
void zhongxin1_danxian(u16 zhuansu1,u16 zhuansu2);/*Ѱ��ֱ�е����ļ�⵽·��     ������(���ߣ�     */
void zhongxin2_danxian(u16 zhuansu1,u16 zhuansu2);/*Ѱ��ֱ�е����ļ�⵽·��     ������(���ߣ�     */
void zhongxin1_shuangxian(u16 zhuansu1,u16 zhuansu2);/*Ѱ��ֱ�е����ļ�⵽·��     ������(˫�ߣ�     */
void zhongxin2_shuangxian(u16 zhuansu1,u16 zhuansu2);/*Ѱ��ֱ�е����ļ�⵽·��     ������(˫�ߣ�     */
void zhongxin1_danxian_jingdu(u16 zhuansu1,u16 mangpao_time,u16 zhuansu2);//���򾫶ȵ����ļ�⵽·��
void zhongxin2_danxian_jingdu(u16 zhuansu1,u16 mangpao_time,u16 zhuansu2);//���򾫶ȵ����ļ�⵽·��


//ä�ܳ���
void mangpao1(u16 Time);//����ä��
void mangpao2(u16 Time);//����ä��
void mangpao1_danxian(void);//����ä��_����
void mangpao2_danxian(void);//����ä��_����
void mangpao1_shuanxian(void);//����ä��_˫��
void mangpao2_shuanxian(void);//����ä��_˫��
void mangpao1_tiaosu(u16 zhuansu,u16 Time);//����ä��-����
void mangpao2_tiaosu(u16 zhuansu,u16 Time);//����ä��-����
void mangpao1_tiaozheng(u16 zhuansu);//����ä��-����
void mangpao1_zhongjian(u16 zhuansu);//����ä��-����

//�������
void zuoguai1(u16 zhuansu,u16 time);//������ռ��м�Ҷȵ���
void youguai1(u16 zhuansu,u16 time);//�����ҹռ��м�Ҷȵ���
void zuoguai2(u16 zhuansu,u16 time);//������ռ��м�Ҷȵ���
void youguai2(u16 zhuansu,u16 time);//�����ҹռ��м�Ҷȵ���
void zuoguai1_mangguai(u16 zhuansu,u16 time);//��գ�ä�գ�
void youguai1_mangguai(u16 zhuansu,u16 time);//�ҹգ�ä�գ�
void youguai1_jiance(u16 zhuansu);//�ҹգ���⣩

//�����������
void youguai_2_chufa(u16 zhuansu);//�����ҹ�_2�μ�⵽����
void youguai_2_chufa_hou(u16 zhuansu);//�����ҹ�_����Ҷȼ�⵽����
void youguai_2_chufa_hou1(u16 zhuansu);//�����ҹ�_����Ҷȼ�⵽����(�ڲࣩ
void zhongxin1_shuangxian1(u16 zhuansu);

//����ä�ܳ���
void mangpao1_fanhui(u16 zhuansu1,u16 zhuansu2);//����ä��_����
void mangpao2_fanhui(u16 zhuansu);//����ä��_����
//ʶ���������
void tiaozheng_shibie(u16 zhuansu);



//================================�ܳ���========================================
void chufaqu_saoma(void);
void saoma_banququ(void);
void youguai_and_tiaozheng(void);
void banququ_1_lanse_banququ(void);
void banququ_1_lvse_banququ(void);
void banququ_1_hongse_banququ(void);
void banququ_2_lanse_banququ(void);
void banququ_2_lvse_banququ(void);
void banququ_2_hongse_banququ(void);
void banququ_3_lanse_banququ(void);
void banququ_3_lvse_banququ(void);
void banququ_3_hongse_banququ(void);

void banququ_1_lanse_banququ_home(void);
void banququ_1_lvse_banququ_home(void);
void banququ_1_hongse_banququ_home(void);
void banququ_2_lanse_banququ_home(void);
void banququ_2_lvse_banququ_home(void);
void banququ_2_hongse_banququ_home(void);
void banququ_3_lanse_banququ_home(void);
void banququ_3_lvse_banququ_home(void);
void banququ_3_hongse_banququ_home(void);
void fancheng(void);

#endif /*__BSP_MOVE_H*/
