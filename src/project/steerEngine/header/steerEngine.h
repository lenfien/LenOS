#ifndef __STEER_ENGINE
#define __STEER_ENGINE


void STEER_init(void);

//ռ�ձ����λ0.5ms,���λ2.5ms
//��Ӧλ:500us��2500ms,�м���2000�����ȿ��Ե���
//pos = 1 - 2000
void STEER_set_pos(U32 pos);

#endif
