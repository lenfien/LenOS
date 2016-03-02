/*
Widget
	��һ�������, ������������Ҫ��Pad��Vector<Widget&>���̵�, 
	��Pad����Ҫֻ����Widget�Ĵ�С, ���λ��, �ߴ���Ϣ, 
	���ܻ������һЩ��ȡ��widget��������Ϣ�ĺ���, �ڴ˶���Ϊget_info, 
	��Ȼ, update�Ǹ��¿ؼ��ĺ���, �˺����ᱻPad�ڱ�����, ���ҿ���ʱִ��
	~Widget��������Ҳ�Ǳ�pad���õ�.
	ÿһ��Widget����һ�������Pad���Ͻǵ�����, ��ֻ����drawʱ, 
	����֪���������, draw�ᴫ��Widget�������, �����drawһ��
	�Ǳ�pad���õ�.
*/
#ifndef __WIDGET__
#define __WIDGET__
#include "com.h"
#include "graphic.h"
#include "touchable.h"

class Pad;

class Widget: public Graphic
{
	protected:
		Widget(
				U16 _sizeX = 100, 
				U16 _sizeY = 50 
		);
	
	public:
		virtual ~Widget() {}
		
	public:
		Point 						relaPosition;						//����ռ�����λ��
		Graphic::RectType area;				
		Pad*							father;									//Widget���ĸ�Pad��
		bool							dignity;								//һ���ؼ���dignity��־�˿ؼ���ϵͳ�ؼ�������ͨ�ؼ�
		
	public:
		virtual bool 		is_touch_widget()	{return false;}					//�Ƿ�ΪTouchWidget
		
		virtual void 		set_position(Graphic::Point p)	{area.position = p;}
		
		virtual Point 	set_relataive_position(Point p);
		
		virtual Point 	real_position()	{ return area.position + relaPosition;}
		
		virtual RectType 
										real_area()		
		{
			RectType r = area;
			r.position = real_position();
			return r;
		}
		
		virtual void		set_father(Pad* f) {father = f; }
		
		/*
			v = false ȫ������
			v= true		valid ����
			x, y Ϊƫ����
		*/
		virtual RectType 	set_father_window(bool v = 0, int x = 0, int y = 0);
		virtual void		release_father_window(Graphic::RectType);
		
	public:
		virtual int draw(Point p = Point(0, 0)) = 0;
		virtual int update(void *p = 0) = 0;		//�еĿؼ����ܻ�����Լ��� ���������������д
};


#endif
