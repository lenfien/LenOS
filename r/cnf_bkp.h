#ifndef __CNF_BKP
#define __CNF_BKP

void BKP_init(void);

//�رպͱ�������ص�����ģ��
void BKP_shutdown(void);

//����data��������Ĵ����е�xλ��
//���ظ�λ��֮ǰֵ
U16 BKP_save_data(U16 data, U8 x);

//��λ������Ĵ����е�����ֵΪ0
void BKP_reset(void);

#endif