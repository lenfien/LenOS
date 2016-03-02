
/*
	Touchable
	����: ���м̳�Touchable����, ����������������ʱ���������¼�
	Touchable��Ĭ����ϵͳ�ṩ�Ĵ����ؼ�����������ӿؼ�, ���Ҵӵײ�ά����Щ�ؼ��Ĵ����¼�, 
	
	��Ҳ�����Լ��ṩ��һ��������, ��ô������Լ�ά���Լ����ṩ���������еĿؼ��Ĵ����¼�.
	�ƺ��Լ��޷��ṩά����Щ�ؼ��Ĵ����¼�, ��Ϊ�㲻����ϵͳ�ж�����Ӻ���, �������ǲ������. 
	���������ô��, ���ṩһ��TouchPad��ϵͳ, ϵͳ��ά��ִ��TouchPad�����¼�, 
	��TouchPad��ά��һ���Լ��Ĵ����ؼ�����,  TouchPad�ϵĿؼ����Լ��Ĵ�����������ΪTouchPad��ά���Ĵ�������,  
	����,��Ϳ�����ϵͳ����TouchPad�Ĵ����¼�ʱȥ����Pad���������Ŀؼ����¼�. 
	
	����γ���һ�����ϵͳ, System ---> TouchPad --->Widget.
	
	ϸ��: ������TouchPad��ӿؼ�ʱ, TouchPad�����Widget��set_touch_vector������Widget�Ĵ�����������Ϊ�Լ���.
	
	����: ��TouchPad��ʲô�¼���ȥ����Widget���¼�.
	
	�������: touch�¼��д������пؼ���touch�¼�, ���ͷ��¼��д������пؼ����ͷ��¼�, �ȵ�, 
	�����ڳ����¼�, �����¼�Ӧ����ϵͳȫ�ֵĻ��ǿؼ����е���, �����ķ�ʽӦ���ǿؼ����е�, 
	�Ǹ���ôʵ����?  ����, ����Ľ������Ӧ�������ƶ�Ϊ: ��Pad��touch release �¼�ʱ, 
	���ؼ���ִ��touch release�¼�, ��touchPad��hold�¼���, �㲻����ִ�����пؼ��� hold �¼�,
	���ü���, �ȵ�, �������������touchable���Ѿ��ǹ�����, �ܲ��ܴ�����õ�? �ð�, 
	TouchableӦ����hold��ͬʱ������ṩһ���û�holdס��Ļ��ʱ��, ������Ǻ����, �Ǿ���ô��.
	
	----------------------------------------------------------------------------------------------------
	Touchable��˵��
	�̳�: Touch��
	����:	�̳�Touchable���඼���пɴ�������
	˵��:	
	���ڴ���:
		���м̳�Touchable����, ����̳�
		virtual void touch_handler(const Point p);				//���û�������Ļʱ�ἤ��˺���
		virtual void hold_handler(const Point p);				//���û����ִ�����Ļһ��ʱ����, ���ظ�ִ�иú���
		virtual void long_hold_handler(const Point p);		//���û�������Ļһ�ο����õ�ʱ���, ִ�иú���, ��ִֻ��һ��
		virtual void release_handler(const Point p);			//���û��ͷ��˴�����ִ�иú���
		�ĸ��麯��, ���������, ��Ӧ������ʵ�����ĸ�����.
		
	--------------------------------------------------------
	���ڴ�������:
		���������¼�ֻ��
		virtual bool meet_condition();		//�Ƿ����㼤������
		������ʱִ�к���
		�˺���Ĭ�Ϸ�����, ������Ӧ���Լ������������, ��������Ҫ�������²�ִ��
		����ĺ���
		
	---------------------------------------------------------
	���ڳ����¼���ʱ������
		Ҫʹlong_hold_handlerִ��һ��, �û���ס��Ļ��ʱ�����ﵽlongHoldTime�����õ�
		ʱ��, �ֱ���ԼΪ1ms, ��ɿ����ֶ�����:
		longHoldTime();
		����ø�ֵ, Ҳ���Ե���
		longHoldTime(U32)
		�����ø�ֵ
	
	something_being_dragged:
	�˱�����������־�Ƿ��ж������ڱ���ק��ΪʲôҪ������������أ� ��Ϊ���һ���ж���
	����ק�� ��ô����������������һ��û�б���ק�Ķ����ڣ� �Ǹ�����Ĵ����¼�Ҳ���ᷢ��
	�������һ�㱻���� meet_condition�����С�
	�������ֻ�����ͷ��¼��У� ���ͷ��¼���ʱ�����Ϊ���������û�б�ִ�У���ᵼ��һ��BUG
	����δ�����
	
	����Touchable�������˵��:
		Touchable�Ὣ�Լ���ӵ�һ���������У�����������������ڴ�������ʱ����������ɨ��ģ�ɨ��
	�Ĺ����л����meet_contidition���ж��Ƿ�ִ�С��¼����� ���ԣ� ������Touchable֪���Լ�Ӧ����
	��һ����������ӣ� ������;������ָ��Touchable��������
		1.����ʱ������ʱ��vector<Touchable*>* pTouches��ʼ��Ϊ������ĵ�ַ
		2.����set_touch_vector�趨Touchable�������� �ú����Ὣthis�Ӿɵ���������ȡ���� Ȼ�������
		���µ���������
*/

#ifndef __TOUCHABLE__
#define __TOUCHABLE__

#include "touch.h"
#include "ads7843.h"
#include "vector.h"
#include "system.h"
#include "graphic.h"

class Touchable: public Touch
{
public:
	int					touchTimes;												//����ֵ��touch�¼�������һ�� ��release�¼��м�ȥ1�������������touch�¼��У���ֵΪ��0�����ʾreleaseû�б�ִ�е��� ��ϣ����touch�¼�����ִ��release�¼�
	static bool something_being_dragged;					//���Ͽ�
	static U32 	holdTime;													//��holdʱ, touchable��������ṩһ��hold��ʱ�������(�û��Լ�ά������������ʱ���õ�)
	virtual void execute(Touchable* ta, Touchable* source);					//
	
public:
	/*
			��Ϊ��ͬ�Ŀؼ���ʹ�ò�ͬ�ռ�������, 
			��button�Ŀؼ������������Pad��, 
			��Pad�Ŀؼ���������window��, window�Ŀؼ�������system��, 
			�����еĿɴ����ؼ����̳�touchable,
			��������ָ��ʵʹ�õ�touches����������
	*/
	Vector<Touchable*>* pTouches;														//
	virtual Vector<Touchable*>* set_touch_vector(Vector<Touchable*>* );
	
	unsigned int _longHoldTime;															//�����״̬ʱ��
	void (*touchHandler)(const Graphic::Point p, Touchable *self, Touchable* father);					//�����¼�
	void (*holdHandler)(const  Graphic::Point p, Touchable *self, Touchable* father);					//�����¼�
  void (*longHoldHandler)(const  Graphic::Point p, Touchable *self, Touchable* father);			//�����¼�
	void (*releaseHandler)(const  Graphic::Point p, Touchable *self, Touchable* father);				//�ͷ��¼�
	
public:
	virtual bool meet_condition(Graphic::Point touchPoint);				//�Ƿ����㼤������
	
public:
	Touchable(
			Vector<Touchable*>* _pTouches = &System::systemTouches,
			
			void (*_touchHandler)(const  Graphic::Point p, 		Touchable *self, 	Touchable* father) = 0,					//�����¼�
			void (*_holdHandler)(const  Graphic::Point p, 		Touchable *self, 	Touchable* father) = 0,						//�����¼�
			void (*_longHoldHandler)(const  Graphic::Point p, Touchable *self, 	Touchable* father) = 0,				//�����¼�
			void (*_releaseHandler)(const  Graphic::Point p, 	Touchable *self, 	Touchable* father) = 0					//�ͷ��¼�				//�ͷ��¼�
	);
	
	virtual ~Touchable();
	
public:
	unsigned int long_hold_time();						//��ȡlong_hold_time��ʱ��
	unsigned int long_hold_time(unsigned nl);	//����long_hold_time��ʱ��
	
	void (*set_touch_handler(void 	(*_touchHandler)(const 	Graphic::Point p, Touchable *self, Touchable* father)))(const  Graphic::Point, Touchable *self, Touchable* father);		//
	void (*set_hold_handler(void 	(*_holdHandler)(const  Graphic::Point p, 	Touchable *self, Touchable* father)))(const  Graphic::Point, Touchable *self, Touchable* father);		//
	void (*set_long_hold_handler(void 	(*_longHoldHandler)(const  Graphic::Point p, 	Touchable *self, Touchable* father)))(const  Graphic::Point, Touchable *self, Touchable* father);		
	void (*set_release_handler(void 	(*_releaseHandler)(const  Graphic::Point p, 	Touchable *self, Touchable* father)))(const  Graphic::Point, Touchable *self, Touchable* father);		
	
protected:
	virtual void touch_handler(const  Graphic::Point p, Touchable *self, Touchable* father);				//�����¼�
	virtual void hold_handler(const  Graphic::Point p, Touchable *self, Touchable* father);				//�����¼�
	virtual void long_hold_handler(const  Graphic::Point p, Touchable *self, Touchable* father);		//�����¼�
	virtual void release_handler(const  Graphic::Point p, Touchable *self, Touchable* father);			//�ͷ��¼�
	
public:
	
};


#endif
