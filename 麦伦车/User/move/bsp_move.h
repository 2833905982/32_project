#ifndef __BSP_MOVE_H
#define __BSP_MOVE_H
	 

#include "stm32f10x.h" 
#include "bsp_delay.h"
#include "bsp_GeneralTim.h" 


//寻迹程序
void zhixing1(u16 zhuansu);//正向跑
void zhixing2(u16 zhuansu);//反向跑
void zhixing1_danxian_jingdu(u16 zhuansu);//正向精度跑
void zhixing2_danxian_jingdu(u16 zhuansu);//反向精度跑
void zhixing1_chufa(u16 zhuansu);//正向跑_出发
void zhixing1_danxian_jingdu_zuo(u16 zhuansu);//正向精度跑_左

//寻迹到中心程序
void zhongxin1(u16 zhuansu1,u16 mangpao_time,u16 zhuansu2);/*寻迹直行到中心检测到路口     （正向）     */
void zhongxin2(u16 zhuansu1,u16 mangpao_time,u16 zhuansu2);/*寻迹直行到中心检测到路口     （倒向）     */
void zhongxin1_danxian(u16 zhuansu1,u16 zhuansu2);/*寻迹直行到中心检测到路口     （正向）(单线）     */
void zhongxin2_danxian(u16 zhuansu1,u16 zhuansu2);/*寻迹直行到中心检测到路口     （倒向）(单线）     */
void zhongxin1_shuangxian(u16 zhuansu1,u16 zhuansu2);/*寻迹直行到中心检测到路口     （正向）(双线）     */
void zhongxin2_shuangxian(u16 zhuansu1,u16 zhuansu2);/*寻迹直行到中心检测到路口     （倒向）(双线）     */
void zhongxin1_danxian_jingdu(u16 zhuansu1,u16 mangpao_time,u16 zhuansu2);//正向精度到中心检测到路口
void zhongxin2_danxian_jingdu(u16 zhuansu1,u16 mangpao_time,u16 zhuansu2);//反向精度到中心检测到路口


//盲跑程序
void mangpao1(u16 Time);//正向盲跑
void mangpao2(u16 Time);//反向盲跑
void mangpao1_danxian(void);//正向盲跑_单线
void mangpao2_danxian(void);//反向盲跑_单线
void mangpao1_shuanxian(void);//正向盲跑_双线
void mangpao2_shuanxian(void);//反向盲跑_双线
void mangpao1_tiaosu(u16 zhuansu,u16 Time);//正向盲跑-调速
void mangpao2_tiaosu(u16 zhuansu,u16 Time);//反向盲跑-调速
void mangpao1_tiaozheng(u16 zhuansu);//反向盲跑-调整
void mangpao1_zhongjian(u16 zhuansu);//正向盲跑-调整

//拐弯程序
void zuoguai1(u16 zhuansu,u16 time);//正向左拐加中间灰度调整
void youguai1(u16 zhuansu,u16 time);//正向右拐加中间灰度调整
void zuoguai2(u16 zhuansu,u16 time);//反向左拐加中间灰度调整
void youguai2(u16 zhuansu,u16 time);//反向右拐加中间灰度调整
void zuoguai1_mangguai(u16 zhuansu,u16 time);//左拐（盲拐）
void youguai1_mangguai(u16 zhuansu,u16 time);//右拐（盲拐）
void youguai1_jiance(u16 zhuansu);//右拐（检测）

//出发拐弯程序
void youguai_2_chufa(u16 zhuansu);//出发右拐_2次检测到白线
void youguai_2_chufa_hou(u16 zhuansu);//出发右拐_后面灰度检测到白线
void youguai_2_chufa_hou1(u16 zhuansu);//出发右拐_后面灰度检测到白线(内侧）
void zhongxin1_shuangxian1(u16 zhuansu);

//返回盲跑程序
void mangpao1_fanhui(u16 zhuansu1,u16 zhuansu2);//正向盲跑_返回
void mangpao2_fanhui(u16 zhuansu);//反向盲跑_返回
//识别调整程序
void tiaozheng_shibie(u16 zhuansu);



//================================总程序========================================
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
