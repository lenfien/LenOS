#ifndef __STEER_ENGINE
#define __STEER_ENGINE


void STEER_init(void);

//占空比最低位0.5ms,最高位2.5ms
//对应位:500us和2500ms,中间有2000个幅度可以调节
//pos = 1 - 2000
void STEER_set_pos(U32 pos);

#endif
