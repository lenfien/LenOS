#ifndef __PAINTER__
#define __PAINTER__

/*
	Paintable��һ�������࣬
	�̳и������;���������Ļ�ϻ���ͼ�εĹ��ܡ�
	Paintable ������������ ���λ�õ�ָ��ͷ�Χ��ָ��, ����������Ļ�Ļ��ƽ���Ϊ�����λ��Ϊ0��0�㲢���ڷ�Χ�ڵĻ�ͼ.
	����ΪʲôҪ��ָ�룿��Ϊ���λ�úͷ�Χ���ܻᷢ���仯, ��Paintable��Ҫʱ��֪�������Ϣ��
*/

#include "graphic.h"
#include "screen.h"

class Paintable
{
protected:
		Graphic::RectType* pArea;	//�����ͼ������
		Paintable(Graphic::RectType* r):pArea(r)	{}
		
public:		virtual void 	idraw_line(Graphic::Point pStart, Graphic::Point pEnd, Color::ColorValue cv, U8 bold = 1);
		virtual void 	idraw_rectangle(Graphic::Point leftTop, U16 xLen, U16 yLen, Color::ColorValue c, Color::ColorValue cl =Color::InvalidColor, U16 bold = 1);
		virtual void 	idraw_lines(Graphic::Point* pBeg, Graphic::Point* pEnd, Color::ColorValue cv, U16 bold);
		virtual void 	idraw_empty_rectangle(Graphic::Point leftTop, U16 xLen, U16 yLen, Color::ColorValue cv, U16 bold = 1);
		virtual void 	idraw_circle(Graphic::Point oc, U16 r, Color::ColorValue cv);
		virtual void 	idraw_empty_circle(Graphic::Point oc, U16 r, Color::ColorValue lv);
		virtual void 	idraw_oval(U16 a, U16 b, Graphic::Point o, 	Color::ColorValue p);
		virtual void 	idraw_point(Graphic::Point p, Color::ColorValue color);
		virtual void 	idraw_bitmap(Graphic::Point leftTop, S16 bitMapWidth, S16 bitMapHigh, const unsigned char *pPic);
		virtual void 	idraw_bitmap(Graphic::Point leftTop, S16 bitMapWidth, S16 bitMapHigh, Datas<Color::ColorType>& pic);	
		virtual char*	iprintf(Graphic::Point p, char *format, ...);
};


#endif
