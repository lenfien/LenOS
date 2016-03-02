
#ifndef __GRAPHIC__
#define __GRAPHIC__

#include "vector.h"
#include "screen.h"

/*
	Graphic��ּ���ṩ�����Ļ�ͼ����, 
	������Ϊ����ͼ�ζ���Ļ���, ��Ϊ�����������ṩ�麯��, 
	��draw, ����Ϊͼ�λ�Ԫ��
	�ṩΨһ��ʶ��.
*/

class Graphic: public Screen
{
	public:
		static U32 hashCodeCounter;
	
	public:
		bool 							drawed; 					//�Ƿ��Ѿ����Ƶ���Ļ��
		
	public:
		using Screen::draw_bitmap;
		//using Screen::draw_line;
		using Screen::draw_point;
		using Screen::draw_rectangle;
		
/*********************��ͼ����***********************/	
	public:
		using Screen::Point;
		static void draw_line(Point pStart, Point pEnd, Color::ColorValue cv, U8 bold = 1);
		static void draw_rectangle(Point leftTop, U16 xLen, U16 yLen, 
																Color::ColorValue c, Color::ColorValue cl =Color::InvalidColor, 
																	U16 bold = 1);
		
		static void draw_lines(Point* pBeg, Point* pEnd, Color::ColorValue cv, U16 bold);
		static void draw_empty_rectangle(Point leftTop, U16 xLen, U16 yLen, Color::ColorValue cv, U16 bold = 1);
		static void draw_circle(Point oc, U16 r, Color::ColorValue cv);
		static void draw_empty_circle(Point oc, U16 r, Color::ColorValue lv);
		static void draw_oval(U16 a, U16 b, Point o, 	Color::ColorValue p);
		
		static void draw_bitmap(Point leftTop, S16 bitMapWidth, S16 bitMapHigh, const unsigned char *pPic);
		static void draw_bitmap(Point leftTop, S16 bitMapWidth, S16 bitMapHigh, Datas<Color::ColorType>&);
		
		//�������ε�λ�ã� ʹ�䲻������Ļ��Χ
		static void revise_rectangle_position(Point& p, S16 sizeX, S16 sizeY);
		
		//�����������εĽ�����Σ�����false��ʾû�н��棬���򽫽�����������dis��
		static bool mix_rectangle(RectType r1, RectType r2, RectType& dis);
		
		//��p�Ƿ��ھ���r��
		inline static bool	is_in_rectangle(Point p, RectType r)
		{
			if(p.x >= r.position.x && p.y >= r.position.y && p.x < r.position.x + r.xSize && p.y < r.position.y + r.ySize)
				return true;
			
			return false;
		}
		
		static int distance(Point p1, Point p2);
		
/********************��Ϊ���������***************************/	
	protected:
		const U32 hashCode;
		virtual ~Graphic(){}
		
	public:	
		virtual int 	draw(Graphic::Point p) = 0;
		virtual int 	dedraw() = 0;
		/*
				�ڸ��µ�ʱ����ϣ��������ָ���ķ�ʽ����, ����pָ�����
		*/
		virtual int 	update(void *p = 0) = 0;
		virtual int 	hash_code()	{return hashCode;}
		
	protected:
		Graphic():drawed(false), hashCode(hashCodeCounter++) {}
			
};


#endif
