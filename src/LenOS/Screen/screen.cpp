
#include <cstdio>
#include <cstdlib>
#include <cmath>

#include "com.h"
#include "out.h"
#include "color.h"
#include "font.h"
#include "screen.h"


Screen::RectType Screen::window(Graphic::Point(0, 0), Screen::width(), Screen::high());

/******************************����************************/
Screen::
Screen()	
{
	if(!SSD1289::isInitialized)
	{
		InitialStruct it = 
		{
			ORITATION_320_240,
			Color::COLOR_262K,
			0,
			1
		};
		init(it);
		clear_screen(it.backgroundColor );
	}
}
	
Screen::
Screen(Color::ColorValue backColor, Oritation oritation, 
				Color::ColorQuality colorQuality, 
				bool light)
{
	InitialStruct it = 
		{
			oritation,
			colorQuality,
			backColor,
			light
		};
		init(it);
		clear_screen(it.backgroundColor );
}
		

Screen::Oritation 
Screen::
oritation()
{
	return Screen::state.oritation;
}


Color::ColorQuality Screen::color_quality()
{
	return Screen::state.colorQuality;
}

U8 Screen::back_light()
{
	return Screen::state.backLight;
}

Color::ColorValue Screen::background_color()
{
	return Screen::state.backgroundColor;
}


/****************************************ͼ�δ���************************************/
/*
	��������:���ݲ�������Ļ�ϻ���һ��262K��ɫ��ͼƬ
	bitMapWidth��bitMapHigh����xStar,yStart�Ĳ�ͬ�в�ͬ�ķ�Χ����Ҫ�����÷�Χ������ͼƬ���ص���ʾ
*/
void 
Screen::
draw_bitmap_262K(
		S16 xStart, 			S16 yStart, 
		S16 bitMapWidth, 	S16 bitMapHigh, 
		const unsigned char *pPic)
{
	U32 index = bitMapWidth * bitMapHigh ;                                   //�����������
	U32 color_temp;
	      
	RectType r(Point(xStart, yStart), bitMapWidth, bitMapHigh);
	RectType res;
	
	if(!Graphic::mix_rectangle(r, window, res))
		return;
	
	set_window(res.position.x, res.position.y, res.xSize, res.ySize);
	
	int x = xStart;
	int y = yStart;
	
	while(index--)
	{
		color_temp = Color::RGB262K((*pPic), *(pPic + 1), (*pPic + 2));
		pPic += 3;
		if(Graphic::is_in_rectangle(Point(x, y), window))
			set_point_262K(color_temp);
		
		x++;
		if(x == xStart + bitMapWidth)
		{
			y++;
			x = xStart;
		}
	}
	set_full_window();               
}


/*
	��������:���ݲ�������Ļ�ϻ���һ��262K��ɫ��ͼƬ
	bitMapWidth��bitMapHigh����xStar,yStart�Ĳ�ͬ�в�ͬ�ķ�Χ����Ҫ�����÷�Χ������ͼƬ���ص���ʾ
*/
void 
Screen::
draw_bitmap_262K(
		S16 xStart, 			S16 yStart, 
		S16 bitMapWidth, 	S16 bitMapHigh, 
		Datas<Color::ColorType >& pic)
{
	U32 index = bitMapWidth * bitMapHigh ;                                   //�����������                               
	
	RectType r(Point(xStart, yStart), bitMapWidth, bitMapHigh);
	RectType res;
	
	if(!Graphic::mix_rectangle(r, window, res))
		return;
	
	set_window(res.position.x, res.position.y, res.xSize, res.ySize);
	
	
	Color::ColorType c;
	
	int x = xStart;
	int y = yStart;
	
	pic.set_current_position(0);
	
	while(index--)
	{
		c = pic.next();
		
		//Out::printl(0, 8, "%d %d %d", c.r, c.g, c.b);
		
		if(Graphic::is_in_rectangle(Point(x, y), window))
			set_point_262K(Color::RGB262K(c.r, c.g, c.b));
		
		x++;
		
		if(x == xStart + bitMapWidth)
		{
			y++;
			x = xStart;
		}
	}
	
	set_full_window();               
}




/*
	��������:���ݲ�������Ļ�ϻ���һ��65K��ɫ��ͼƬ
	bitMapWidth��bitMapHigh����xStar,yStart�Ĳ�ͬ�в�ͬ�ķ�Χ����Ҫ�����÷�Χ������ͼƬ���ص���ʾ
*/
void 
Screen::
draw_bitmap_65K(
					S16 xStart, 			S16 yStart, 
					S16 bitMapWidth, 	S16 bitMapHigh, 
					Datas<Color::ColorType >& pic)
{
	U32 index = bitMapWidth * bitMapHigh ;                                    //�����������
	set_window(xStart, yStart, bitMapWidth, bitMapHigh); //���ô���
	
	pic.set_current_position(0);
	Color::ColorType c;
	
	while(index--)
	{
		c = pic.next();
		set_point_65K(Color::RGB65K(c.r, c.g, c.b));
	}
	set_full_window();
}


/*
	��������:���ݲ�������Ļ�ϻ���һ��65K��ɫ��ͼƬ
	bitMapWidth��bitMapHigh����xStar,yStart�Ĳ�ͬ�в�ͬ�ķ�Χ����Ҫ�����÷�Χ������ͼƬ���ص���ʾ
*/
void 
Screen::
draw_bitmap_65K(
					S16 xStart, 			S16 yStart, 
					S16 bitMapWidth, 	S16 bitMapHigh, 
					const unsigned char *pPic)
{
	U32 index = bitMapWidth * bitMapHigh ;                                    //�����������
	U32 color_temp;
	set_window(xStart, yStart, bitMapWidth, bitMapHigh); //���ô���
	
	while(index--)
	{
		color_temp = *pPic++;
		color_temp = (color_temp << 8) | *pPic++;
		set_point_65K(color_temp);
	}
	set_full_window();
}


void 	
Screen::
draw_bitmap(S16 xStart, S16 yStart, S16 bitMapWidth, S16 bitMapHigh,   const unsigned char *pPic)
{
	switch(color_quality())
	{
		case Color::COLOR_262K:
			draw_bitmap_262K(xStart, yStart, bitMapWidth, bitMapHigh, pPic);
		break;
		case Color::COLOR_65K:
			draw_bitmap_65K(xStart, yStart, bitMapWidth, bitMapHigh, pPic);	
	}
}

void 	
Screen::
draw_bitmap(S16 xStart, S16 yStart, S16 bitMapWidth, S16 bitMapHigh,   Datas<Color::ColorType >& pic)
{
	if(pic.amount == 0)
		return;
	switch(color_quality())
	{
		case Color::COLOR_262K:
			draw_bitmap_262K(xStart, yStart, bitMapWidth, bitMapHigh, pic);
		break;
		case Color::COLOR_65K:
			draw_bitmap_65K(xStart, yStart, bitMapWidth, bitMapHigh, pic);	
	}
}




/*
	����
*/
Color::ColorValue 
Screen::
draw_point(Point p, Color::ColorValue color)					//����
{
	if(p.x >= width() || p.y >= high())
		return 0;
	
	if(!Graphic::is_in_rectangle(p, window))
		return 0;
	
	set_GDDRAM_position(p.x, p.y);
	
	set_point(color);
	
	return 0;
}

/*
	ȡ����
	�Ὣ��ǰ��window���������õ�windowȡ����
*/
Screen::RectType Screen::set_vwindow(RectType w)
{
	RectType old = window;
	
	RectType w1 = w;
  if(Graphic::mix_rectangle(w, window, w1))
		window = w1;
	
	return old;
}

/*
	��ȡ����
*/
Screen::RectType	Screen::reset_vwindow(RectType w)
{
	RectType old = window;
	window = w;
	return old;
}

/*
	ֱ�Ӹ�ֵ
*/
void Screen::restore_vwindow(RectType w)
{
	window = w;
}

Screen::RectType Screen::set_full_vwindow()
{
	RectType old = window;
	window = RectType(Point(0, 0), width(), high());
	return old;
}

/*
	����
*/
void
Screen::draw_line(
	S16 xStart, S16 yStart, 
	S16 xEnd, S16 yEnd, 
	Color::ColorValue color
)
{
	if(xStart == xEnd)
	{
		for(S16 y = min(yStart, yEnd); y <= max(yStart, yEnd); y++)
			draw_point(Point(xStart, y), color);
		return;
	}
	
	double k = (double)(yEnd - yStart)/(double)(xEnd - xStart);
	
	for(S16 x= min(xStart, xEnd); x <= max(xStart, xEnd); x++)
	{
		U16 y = k * (x - xStart) + yStart;
		draw_point(Point(x, y), color);
	}
}

/*
ʵ�ľ���
*/
void 
Screen::draw_rectangle(
S16 xStart, S16 yStart, 
S16 xLen, S16 yLen, 
Color::ColorValue color
)
{
	RectType r(Point(xStart, yStart), xLen, yLen);
	RectType res;
	
	if(!Graphic::mix_rectangle(r, window, res))
		return;
	
	set_window(res.position.x, res.position.y, res.xSize, res.ySize);
	
	int index = res.xSize * res.ySize;
	
	while(index --)
		set_point(color);
	
	SSD1289::set_full_window();
}

//*************************************������ʾ����*****************************************//
/*
	��ʾ�������Ҷ��뷽ʽ���е��ַ�
		�Ҷ�����: 	0011 1111 1111 1111 
		�������:   1111 1111 1111 1100
	fontWidthָ�������С:
		���������д�С������
	ָ����ʾλ��:
		xStart��yStart ��ΧӦ������Ӧ��Ļ����Ķ�Ӧ��x��y��
	ǰ��ɫ
		color
	����ɫ
		backColor
	ָ���ַ���ַ
*/
void
Screen::
draw_font_right_align(
							U16 fontWidth,   //�ַ����
							U16 fontHigh,    //�ַ��߶�
							U16 xStart,      //��ʼxλ��
							U16 yStart,      //��ʼyλ��
							U32	color,		 //��ɫ
							U32 backColor,   //����ɫ
							const unsigned char *pFont
							)
{
	U32 index_temp = 0;
	U32 font_temp = 0;
	U32 bitOp = 0x1 << 7;
	U32 byteNumPerLine = (fontWidth%8) ? (fontWidth/8 + 1) : (fontWidth/8);		//ÿһ����Ҫ�����ֽ�
		
	set_window(xStart, yStart, fontWidth, fontHigh);	//�������ִ���
	
	while(fontHigh--)
	{
		U32 bitCounter = 8;         //λ����
		U32 temp ;
		for(index_temp = 1; index_temp <= fontWidth; index_temp ++)
		{
			if(index_temp == 1)		                        //ÿһ�еĿ�ʼ��ȡһ������
			{
				font_temp = *pFont++;
				temp = 8*byteNumPerLine - fontWidth;	//temp��ʾ����λ�ĸ���
				font_temp  <<= temp;
				bitCounter -= temp;							//bitCounter��������λ�ĸ���
			}	
			if(bitCounter == 0)		//���һ���ֽ���ʾ���ˣ�����һ���ֽ�
			{
				bitCounter = 8;
				font_temp =  *pFont++;
			}
			set_point((font_temp&bitOp)?color:backColor);
			font_temp <<= 1;
			bitCounter -- ;				//��ʾһ��λ����
		}		
	}
	set_full_window();
}


/*
	��ʾ����������뷽ʽ���е��ַ�
		�Ҷ�����: 	0011 1111 1111 1111 
		�������:   1111 1111 1111 1100
	fontWidthָ�������С:
		���������д�С������
	ָ����ʾλ��:
		xStart��yStart ��ΧӦ������Ӧ��Ļ����Ķ�Ӧ��x��y��
	ǰ��ɫ
		color
	����ɫ
		backColor
	ָ���ַ���ַ
*/
void 
Screen::
draw_font_left_align(
							U16 fontWidth,   //�ַ����
							U16 fontHigh,    //�ַ��߶�
							U16 xStart,      //��ʼxλ��
							U16 yStart,      //��ʼyλ��
							U32	color,		 //��ɫ
							U32 backColor,   //����ɫ
							const unsigned char *pFont
							)
{
	U32 index_temp = 0;
	U32 font_temp = 0;
	U32 bitOp = 0x1 << 7;	
	
	RectType r(Point(xStart, yStart), fontWidth, fontHigh);
	RectType res;
	
	if(!Graphic::mix_rectangle(r, window, res))
		return;
	
	set_window(res.position.x, res.position.y, res.xSize, res.ySize);
	
	int x = xStart;
	int y = yStart;
	
	while(fontHigh--)
	{
		U32 bitCounter = 8;         //λ����
		for(index_temp = 1; index_temp <= fontWidth; index_temp ++)
		{
			if((index_temp == 1) || (bitCounter == 0) || ((index_temp < fontWidth) && (index_temp%fontWidth == 0)))	 //ÿһ�еĿ�ʼ��ȡһ������
			{
				font_temp = *pFont++;
				bitCounter = 8;
			}
			
			if(Graphic::is_in_rectangle(Point(x, y), window))
				set_point((font_temp&bitOp)?color:backColor);
			
			font_temp <<= 1;
			bitCounter -- ;			//��ʾһ��λ����
			
			x++;
			if(x == xStart + fontWidth)
			{
				y++;
				x = xStart;
			}
		}		
	}
	set_full_window();
}

/*

	U32 index = bitMapWidth * bitMapHigh ;                                   //�����������                               
	
	RectType r(Point(xStart, yStart), bitMapWidth, bitMapHigh);
	RectType res;
	
	if(!Graphic::mix_rectangle(r, window, res))
		return;
	
	//set_window(xStart, yStart, bitMapWidth, bitMapHigh); //���ô���
	
	set_window(res.position.x, res.position.y, res.xSize, res.ySize);
	
	pic.set_current_position(0);
	
	Color::ColorType c;
	
	int x = xStart;
	int y = yStart;
	
	while(index--)
	{
		c = pic.next();
		
		if(Graphic::is_in_rectangle(Point(x, y), window))
			set_point_262K( Color::RGB262K(c.r, c.g, c.b));
		
		x++;
		if(x == xStart + bitMapWidth)
		{
			y++;
			x = xStart;
		}
	}
	
	set_full_window(); 
	
	*/

void Screen::draw_font(
							U16 fontWidth,   //�ַ����
							U16 fontHigh,    //�ַ��߶�
							U16 xStart,      //��ʼxλ��
							U16 yStart,      //��ʼyλ��
							U32	color,		 //��ɫ
							U32 backColor,   //����ɫ
							const unsigned char *pFont
							)
{
	switch(Font::lib_info().align)
	{
		case Font::ALIGN_LEFT:
			draw_font_left_align(fontWidth, fontHigh, xStart, yStart,	color, backColor, pFont);
			break;
		case Font::ALIGN_RIGH:
			draw_font_right_align(fontWidth, fontHigh, xStart, yStart, color, backColor, pFont);
			break;
	}
}


void Screen::set_point(U32 color)
{
	switch(color_quality())
	{
		case Color::COLOR_262K:
			set_point_262K(color);
			break;
		case Color::COLOR_65K:
			set_point_65K(color);
			break;
	}
}


Color::ColorValue Screen::get_point(U16 x, U16 y)
{
	Color::ColorValue t;
	switch(color_quality())
	{
		case Color::COLOR_262K:
			t = get_point_262K(x, y);
			break;
		case Color::COLOR_65K:
			t = get_point_65K(x, y);
			break;
	}
	return t;
}


U32 Screen::get_points(S16 xStart, S16 yStart,
	S16 xLen, S16 yLen, 
	Datas<Color::ColorType>& d)
{
	U32 u;
	switch(color_quality())
	{
		case Color::COLOR_262K:
			u = get_points_262K(xStart, yStart, xLen, yLen, d);
			break;
		case Color::COLOR_65K:
			u = get_points_65K(xStart, yStart, xLen, yLen, d);
	}
	return u;
}


U32 Screen::get_points(S16 xStart, S16 yStart,
	S16 xLen, S16 yLen, 
	unsigned char* d)
{
	U32 u;
	switch(color_quality())
	{
		case Color::COLOR_262K:
			u = get_points_262K(xStart, yStart, xLen, yLen, d);
			break;
		case Color::COLOR_65K:
			u = get_points_65K(xStart, yStart, xLen, yLen, d);
	}
	return u;
}


void Screen::clear_screen(U32 color)
{
	switch(color_quality())
	{
		case Color::COLOR_262K:
			clear_screen_262K(color);
			break;
		case Color::COLOR_65K:
			clear_screen_65K(color);
			break;
	}
}




