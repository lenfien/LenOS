
#ifndef __CNF_DAC
#define __CND_DAC
/*
	mode1
	����Channel1Ϊ�Ǵ���������ͨģʽ
	�ڴ�ģʽ�£�ֻҪһ��DHRx�Ĵ�����д�������ͻ�����ת�Ƶ�DORx�У�����3��APB1ʱ�Ӻ�
	���������
	��ʹ��DMA
	����������
	���������ǲ�
	�����ѹ�ɵ�
*/
void DAC_cnf_mode1(void);


//��ģʽ1��ʹ�ܺ󣬵��ô˺���,�����ѹ���ɷ����仯
void DAC_cnf_write_holding_data(U16 hd);



/*
	Channel1���ó��������ģʽ�µ���ͨģʽ
	12λ�Ҷ���ģʽ
	���������
	����ת��
	�������
	�޲��β���
*/
void DAC_cnf_mode2(void);


/*
	Channel1����Ϊ����ģʽ�µ����ǲ�������
	12λ�Ҷ���
	�������
	���ǲ��в���
*/
void DAC_cnf_mode3(void);


#endif
