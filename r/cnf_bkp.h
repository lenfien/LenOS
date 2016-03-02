#ifndef __CNF_BKP
#define __CNF_BKP

void BKP_init(void);

//关闭和备份域相关的所有模块
void BKP_shutdown(void);

//保存data到备份域寄存器中的x位置
//返回该位置之前值
U16 BKP_save_data(U16 data, U8 x);

//复位备份域寄存器中的所有值为0
void BKP_reset(void);

#endif