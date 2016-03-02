#ifndef __SLIDER__
#define __SLIDER__
#include "button.h"
#include "touchWidget.h"
#include "graphic.h"
#include "touchpad.h"
#include "color.h"
/*
	Slider��һ���ؼ��� ����ؼ�����һ�����ӣ�������ӿ��Ա��϶��� ������������ʾ��ʽ�����������
	�϶�Slider�еĿ���ʱ�� Slider��ʱ���¿��ӵ�ֵ.
	���ӵ�ֵ��һ����Χ�ڣ������Χ���û�ָ����
	Slider����������ť�� һ�����ӿ��ӵ�λ�ã���һ����С��
*/

class Slider: public TouchWidget
{
	public:
	typedef enum
	{
		VERTICAL,
		HORIZON
	}DIR;
	
private:
	int 		curPos;					//��ǰλ��
	int 		range;					//Slider����ʾ���ܷ�Χ
	int 		page;						//һҳ��ռ�ķ�Χ, ���Լ�����ӵĳ���(���ӵĳ�����size��ռ�ı�����page��range��ռ�ı�����ͬ)
	DIR 		direction;			//����
	int 		controlLength;	//�������ĳ���
	double 	perRange;				//ÿһ��range������ٸ�����
	
	Color::ColorValue backColor;
	Color::ColorValue controlColor;
	
	/*
		�����ӿ��ƵĶ��� �϶��������controlObj�е�update������ʵʱ�ĸ���controlObj����ʾ
	*/
	Graphic* controlObj;
	
public:
	
	Slider(int range,  int _page, DIR dir, int bold, int length, 
						Color::ColorValue backColor = Color::RGB_RED, Color::ColorValue controlColor = Color::RGB_BLUE);
	
	virtual 	~Slider()	{	drawed = false;	}
	
	int 			get_pos();
	Graphic*	set_controlObj(Graphic* g);
	void			set_range(int range, int page);
	
	virtual int 	draw(Point p);
	virtual int 	dedraw() {return 0;}
	virtual int 	update(void *p = 0);
	
	virtual void touch_handler(const  Graphic::Point p, Touchable *self, Touchable* father);				//�����¼�
	virtual void hold_handler(const  Graphic::Point p, Touchable *self, Touchable* father);					//�����¼�
	virtual void long_hold_handler(const  Graphic::Point p, Touchable *self, Touchable* father);		//�����¼�
	virtual void release_handler(const  Graphic::Point p, Touchable *self, Touchable* father);			//�ͷ��¼�
};



#endif
