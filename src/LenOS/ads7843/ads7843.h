
#ifndef __ADS7843__
#define __ADS7843__

#include "com.h"
#include "graphic.h"

class ADS7843
{
public:
	//�����ĵ�ǰ״̬
	typedef struct 
	{
		bool 	free;											//��Ļ��ʱ���޴���
		bool	isTouch;									//�����Ƿ���ʱ����
		bool	isHold;     							//��ָһֱ��������Ļ�ϵĻ��ἤ�����״̬
		Graphic::Point touchPoint;			//��ǰ�������ĵ�
	}TouchState;
	
protected:
	static TouchState touchState;
	static bool	isInitialized;
	static void interrupt_init();			//�ⲿINT����
	static void port_init();					//���ų�ʼ��
	
public:
	static void init();										//�ܳ�ʼ��
	static S8 	update_state();
	
	static void sleep();									//ֹͣ���������ж�
	static void awake();									//���Ѵ��������ж�
private:
	static void send_command(U8 cmd);			//��ADS7843��������
	static U16	receive_data();						//��ADS7483�������
	static U8 	get_exact_coordinate(Graphic::Point* point);
	static U8 	get_coordinate(Graphic::Point* point);
	static U8 	conversion(Graphic::Point* point);
	static int 	point_filter(U16 *start, U8 num);
	
public:
	static void interrupt_process();
};

#endif
