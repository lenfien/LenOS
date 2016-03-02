/*
WindowResources
ά�����д����Ĵ�����Դ�� ʹwindow�ĸ���ֻ�����ڵ������ڣ�Window��Ķ���ֻ����һ�����ڣ����Window��ȴȥ����������window��Դ�� �����ϲ�����

Window
���ܣ�1.���������Ϸ���TouchWidget��Widget
	���ǵ�ά����ʽ����ͬ��Padά��Widget��TouchWidget�� ��TouchPadά��TouchWidget��
		ǰ�ߵ�ά������ֻ��ͼ���ϵģ� TouchPadά������TouchWidget���¼���
		2.�����ĸ���
			��0����Ǽ���Ĵ��ڣ�ÿ�μ���һ�����ڣ�Ҫ�����µĹ�����
			1.�Ƚ�����Ĵ��ڻ�ԭ
			2.���������������ڵĲ����1
			3.�Դ�����������ݲ����Ӵ�С���½�������
			4.��������Ľ�����·���㣬��С��1��ʼ
			5.���ղ�Ӵ�С���»������д���
			6.���Ƶ�ǰ����Ĵ���
		3.�Խ�������µ�����
		������������ӿ�߿� ������ʱ�����ı߿���ɫ�������������꣬ ֻ��������window��ӿؼ�ʱ�����������õ������ϼ���һ���߿�Ŀ�Ⱦ����ˡ�
		4.�Լ���Ĵ���
		���㴥�����������ڹ�����������ʱ��Ӧ�ø��ݲ�ĸ���Ǹ���С���ͼ����ĸ��� ��ʵ�������ô����������е�˳�����ɨ�裬
		ɨ�赽��һ������ִ���ˣ��Ͳ�ȥ����ɨ���ˣ� ���ԣ� WindowӦ�����¶���execute������
		5�����̺����� ���Լ�������̣�֮����ӣ�
���ɶ�Widget���¼����й���
UI����������TouchPad�� һ��Ϊ���⣬ һ��
ʵ�ַ�����
�̳У� Graphic
���ݣ�Vector<Pad*>
*/

#ifndef __WINDOW__
#define __WINDOW__

#include "touchpad.h"
#include "string.h"
#include "Graphic.h"
#include "font.h"
#include "color.h"
#include "system.h"
#include "button.h"
#include "slider.h"
#include "paintable.h"

class Window: public TouchPad, public Paintable
{
	private:
			static void shutdown_handler(Point p, Touchable *self, Touchable *father );
			
	private:
			String name;
			
			Button *distroyButton;		//�����ݻ�����window��button
			
			Slider *horizonSlider;		//ˮƽ������
			Slider *verticalSlider;		//��ֱ������
			
			Color::ColorValue titleColor;
			Proc 	process;			//���ڽ���
			Point vPosition;		//���ڵ�������ʼλ�ã� ���еĿؼ�����ѭ����������ʼλ�ÿ�ʼ��ʾ
			void 	(*userUI)(Window*);					//�û���UI���������������
	
	public:
			void 	(*set_UI(void (*)(Window*)))(Window*);	
	
	/*
			���ô��ڵ���ʾ
	*/
	public:
			bool 	sliderEnable;	//�Ƿ���ʾSlider
			bool 	closeEnable;	//�Ƿ���ʾ�رհ�ť
			bool 	titleEnable;	//�Ƿ���ʾ������
	
	public:	
/*������ȡ������*/
	
			int 	high_of_title() 	{return distroyButton->area.ySize;	}															//
			Point valid_position()	{return area.position + Point(1, high_of_title() + 1);}		//���õĻ�ͼ�ط�
			
			virtual Point widget_off_position() {return Point(1, high_of_title()) - vPosition; }
			
			//Color::ColorValue set_color(Color::ColorValue cv) { this-> }
			void 	(*close_handler)(Window* w);
			void (*set_close_handler(void (*h)(Window*)))(Window* w);
			
			/*
				��ȡ�����û����õľ�������
			*/
			virtual RectType& valid_area(int i = 0);
			
/*��������������*/			
	public:
			Window(String name = "No name", 
			U16 _sizeX = 50, U16 _sizeY = 50,
			Color::ColorValue cv = Color::RGB_BLUE, 
			void (*_touchHandler)(const  Graphic::Point p, Touchable *self, Touchable *father ) = 0,					//�����¼�
			void (*_holdHandler)(const  Graphic::Point p, Touchable *self, Touchable *father ) = 0,						//�����¼�
			void (*_longHoldHandler)(const  Graphic::Point p, Touchable *self, Touchable *father ) = 0,				//�����¼�
			void (*_releaseHandler)(const  Graphic::Point p, Touchable *self, Touchable *father ) = 0
			);
			
			virtual ~Window();
			
/*����ģ��*/
			void 					update_slider();
			
			virtual Window& add_widget(Widget* tw, Point p);				//��Ӵ����ؼ���
			virtual int 	update(void*);
			virtual int 	draw(Point p = Point(-1, -1));
			virtual void 	touch_handler(const  Graphic::Point p, Touchable *self, Touchable *father );				//�����¼�
			virtual void 	hold_handler(const  Graphic::Point p, Touchable *self, Touchable *father );					//�����¼�
			virtual void 	long_hold_handler(const  Graphic::Point p, Touchable *self, Touchable *father );		//�����¼�
			virtual void 	release_handler(const  Graphic::Point p, Touchable *self, Touchable *father );			//�ͷ��¼�
			
			void add_thread(void (*)());			//����߳�
			void delete_thread(void (*)());		//ȡ���߳�
			void run_process();
			
			void dispose();
			
};




#endif
