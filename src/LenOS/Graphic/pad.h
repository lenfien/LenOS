
/*
Pad�ĸ���
		��һ���ؼ�����, ���ҿ��������ƶ�, �� TouchPad��ͬ����, PAD
		��Ҫ����ά��ͼ�η��������, ��touchpad��Ҫ����ά���¼������
		����.
		
Ӧ��ʵ�ֵĹ���:
		����һ��vector, ���vector�ڴ����widget&���͵Ŀؼ�, 
		Ӧ����һ����ʼ����ͳߴ��С, ֮�����еĿؼ�����ʵ��������ʼ��������λ����ʾ.
		����ʵ�������ƶ�, Ӧ����һ��Datas<Color::ColorType>��������,
		����һ��move����, ���move����Ӧ�û����recover �� record�ĺ���.
		��Ȼ, draw����������, ��Ϊdraw��c���麯������.
		�Ƿ���ҪCOlor? ����ɫ��, Ҫ�ϰ�
	������ԵĻ�, ��Ӳ�������
		�м�, �����, �Ҷ���, �϶���, �¶���.
	��Pad������ʱ, PadӦ��ѭ����ִ��һ������, �����������ѭ���ĵ���ÿһ���ռ��
	���º���(update).
*/

#ifndef __PAD__
#define __PAD__

#include "vector.h"

#include "color.h"
#include "graphic.h"

class Pad;

/*
	���д�����Pad��������
*/
class PadSources
{
public:
	static Vector<Pad*>		pads;
};

class Widget;

class Pad: public Graphic
{
	friend class PadSources;
	
protected:
			
/***********************���ݳ�Ա**************************/
//-------------�ռ����--------------------//
			Vector<Widget*> 				widgets; 
			
//-------------�����ƶ����----------------//
			Datas<Color::ColorType> backUp;
			//Datas<Color::ColorType> backUpFront;		//��ǰ��ɫ�ı��ݣ� ��Ҫ����active������ԭ��move�������ƶ�
			
			Datas<Color::ColorType> backUpFrame[4];		//�����洢Pad�ı߿� �ƶ�padʱʹ��
			
//-------------�ߴ����-------------------//
public:
			RectType area;
			RectType validArea;
			
			virtual RectType& valid_area(int i = 0)	{return area;}
			virtual RectType& all_area()							{return area;}
			Color::ColorValue				backColor;
			
			int layer;
			void draw_frame(Point p);		
			
/***********************������Ա****************************/
//-------------���캯��---------------//
public:
			Pad(U16 _sizeX = 100, U16 _sizeY = 50, 
			Color::ColorValue cv = Color::RGB_BLUE);
			
			virtual ~Pad();
			
public:
			/*
				�洢�ͻָ�	
			*/
			virtual void record(bool front = false);
			virtual void recover(bool front = false);
			virtual void record_frame(Point p);
			virtual void recover_frame();
			/*
					�������пؼ������λ�ã� 
					�˺���������position���ı�֮��
			*/
			void 		
			update_widgets_rela_position();	//���ƶ�Padʱ, ���еĿռ�����λ�ö���仯, ����, �����������widgets�����λ��
			
public:
			/*
					�Ӿ�λ���ƶ�����λ�ã� ���Ҽ���
			*/
			bool 		
			move(Point newLeftTop);
			
			/*
					��ؼ������������Widget
			*/
			virtual Pad& 
			add_widget(Widget* w, Point p);
			
			/*
					����ؼ������Pad���Ͻǵ�ƫ��λ��
			*/
			inline virtual Point 
			widget_off_position() {return Point(1, 1);}
			
public:			
			virtual int  active();												//���Լ����������, ���޸����������ǵĲ�
			bool if_covered(RectType r);									//
			bool if_coverd();															//
			bool if_covered(Point p);											//��p���Ƿ��в�����Լ�������pad,���жϵ���¼�ʱʹ��
			bool if_in(Point p, RectType& r);							//��p�Ƿ���Pad��
			void draw_bitmap(Graphic::RectType newArea, Graphic::RectType& oldArea,  
					Datas<Color::ColorType >& pic);
			
public:
			virtual int 	draw(Graphic::Point p);	
			virtual int 	dedraw();								//��ȥ��ʾ
			virtual int 	update(void* p = 0);	// {draw_myself();}	
			
			void redraw_all();

};

#endif
