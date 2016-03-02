
#ifndef __CNF_SYSTICK
#define __CNF_SYSTICK

void SYSTICK_init(void);

//将Systick配置成ms为单位中断的函数
void SYSTICK_init_ms(U32 ms);

#endif
