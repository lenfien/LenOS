
#include <cmath>

#include "screen.h"
#include "graphic.h"

U32 Graphic::hashCodeCounter = 0;

//bold是半宽度
void 
Graphic::draw_line(Point pStart, Point pEnd, Color::ColorValue cv, U8 bold)
{
	S16 distance;
	S16 sb = bold;
	if(bold == 1)
	{
		Screen::draw_line(pStart.x, pStart.y, pEnd.x, pEnd.y, cv);
		return;
	}
	
	/*
		竖直情况
	*/
	if(pEnd.x - pStart.x == 0)
	{
		for(S16 b = -(sb / 2); b < sb/2 ; b ++)
			Screen::draw_line(pStart.x + b, pStart.y, pEnd.x + b, pEnd.y, cv);
		return;
	}
	
	double k = (pEnd.y - pStart.y)/(pEnd.x - pStart.x);
	
	if(k == 0)
	{
		for(S16 b = -(sb / 2); b < sb/2 ; b ++)
			Screen::draw_line(pStart.x, pStart.y + b, pEnd.x, pEnd.y + b, cv);
		return;
	}
	
	k = - (1.0/k);	
	
	distance = std::abs(std::sin(std::atan(k)) * ((double)sb));
	
	Point beg, end;
	
	for(S16 indDis = -distance; indDis < distance; indDis++)
	{
		S16 xBeg = pStart.x + indDis;
		S16 yBeg = k*(xBeg - pStart.x) + pStart.y;
		S16 xEnd = pEnd.x + indDis;
		S16 yEnd = k*(xEnd - pEnd.x) + pEnd.y;
		
		if(xBeg < 0 || yBeg < 0 || xEnd < 0 || yEnd < 0)
			return;
			
		Screen::draw_line(xBeg, yBeg, xEnd, yEnd, cv);
	}
}

void 
Graphic::draw_lines(Point* pBeg, Point* pEnd, Color::ColorValue v, U16 bold)
{
	if(pBeg >= pEnd - 1 || !pBeg || !pEnd)
		return ;
	
	Point* it = pBeg;
	
	while(it < pEnd - 1)
	{
		Graphic::draw_line(Point(it->x, it->y), Point((it + 1)->x, (it + 1)->y), v, bold);
		it ++;
	}
}


void Graphic::draw_rectangle(Point leftTop, U16 xLen, U16 yLen, Color::ColorValue c, Color::ColorValue cl, U16 bold)
{
	//revise_rectangle_position(leftTop, xLen, yLen);
	
	Screen::draw_rectangle(leftTop.x, leftTop.y, xLen, yLen, c);
	
	if(cl != Color::InvalidColor)
		draw_empty_rectangle(leftTop, xLen, yLen, cl, bold);
}

void Graphic::draw_empty_rectangle(Point leftTop, U16 xLen, U16 yLen, Color::ColorValue cv, U16 bold)
{
	//revise_rectangle_position(leftTop, xLen, yLen);
	
	Vector<Point> ps;
	
	ps.push_back(Point( leftTop.x, leftTop.y));
	ps.push_back(Point(leftTop.x + xLen - 1, leftTop.y));
	ps.push_back(Point(leftTop.x + xLen - 1, leftTop.y + yLen - 1)); 
	ps.push_back(Point(leftTop.x, leftTop.y + yLen - 1));
	ps.push_back(Point(leftTop.x, leftTop.y));
	
	draw_lines(ps.begin() , ps.end() , cv, bold);
}


void Graphic::draw_circle(Point oc, U16 r, Color::ColorValue cv)
{
	U16 x;
	U16 yu;
	U16 yf;
	
	for(x = oc.x - r; x <= oc.x + r; x ++)
	{
		yu = std::sqrt((double)(r * r - (x - oc.x ) * (x - oc.x))) + oc.y ;
		yf = -std::sqrt((double)(r * r - (x - oc.x ) * (x - oc.x))) + oc.y ;
		
		Screen::draw_line(x, yu, x, yf, cv);
	}
}

void Graphic::draw_empty_circle(Point oc, U16 r, Color::ColorValue lv)
{
	U16 x;
	U16 yu;
	U16 yf;
	
	for(x = oc.x - r; x <= oc.x + r; x ++)
	{
		yu = std::sqrt((double)(r * r - (x - oc.x ) * (x - oc.x))) + oc.y ;
		yf = -std::sqrt((double)(r * r - (x - oc.x ) * (x - oc.x))) + oc.y ;
		
		Screen::draw_point(Point(x, yu), lv);
		Screen::draw_point(Point(x, yf), lv);
	}
	
	U16 y;
	U16 xu;
	U16 xf;
	
	for(y = oc.y - r; y <= oc.y + r; y ++)
	{
		xu = std::sqrt((double)(r * r - (y - oc.y ) * (y - oc.y))) + oc.x;
		xf = -std::sqrt((double)(r * r - (y - oc.y ) * (y - oc.y))) + oc.x;
		
		Screen::draw_point(Point(xu, y), lv);
		Screen::draw_point(Point(xf, y), lv);
	}
}

void Graphic::revise_rectangle_position(Point& p, S16 sizeX, S16 sizeY)
{
	p.x = max(0, p.x);
	p.y = max(0, p.y);
	
	p.x = min(Screen::width() - sizeX - 1, p.x);
	p.y = min(Screen::high() - sizeY - 1, p.y);
}

void Graphic::draw_oval(U16 a, U16 b, Point o, 	Color::ColorValue p)
{
	U16 xIndex = o.x - a;
  U16 yV = 0;
  U16 _a = a * a;
  U16 _b = b * b;
  for(xIndex = o.x - a; xIndex <= o.x + a; xIndex ++)
  {
    yV = std::sqrt((1.0 - (((float)((o.x - xIndex)*(o.x - xIndex)))/((float)_a))) * (float)_b);
    Screen::draw_point(Point(xIndex, o.y - yV), p);
    Screen::draw_point(Point(xIndex, o.y + yV), p);
  }
  for(xIndex = o.y - b; xIndex <= o.y + b; xIndex ++)
  {
    yV = std::sqrt((1.0 - (((float)((o.y - xIndex)*(o.y - xIndex)))/((float)_b))) * (float)_a);
    Screen::draw_point(Point(o.x + yV, xIndex), p);
    Screen::draw_point(Point(o.x - yV, xIndex), p);
  }
}


bool Graphic::mix_rectangle(Graphic::RectType r1, Graphic::RectType r2, Graphic::RectType& dis)
{
	dis.position.x = max(r1.position.x, r2.position.x);
	dis.position.y = max(r1.position.y, r2.position.y);
	
	Point p1(r1.position.x + r1.xSize, r1.position.y + r1.ySize);
	Point p2(r2.position.x + r2.xSize, r2.position.y + r2.ySize);
	
	Point r(min(p1.x, p2.x), min(p1.y, p2.y)) ;
	
	dis.xSize = r.x - dis.position.x;
	dis.ySize = r.y - dis.position.y;
	
	if(dis.xSize<= 0 || dis.ySize <= 0)
		return false;
	return true;
}



void Graphic::draw_bitmap(Point leftTop, S16 bitMapWidth, S16 bitMapHigh, const unsigned char *pPic)
{
	Screen::draw_bitmap(leftTop.x, leftTop.y, bitMapWidth, bitMapHigh, pPic);
}

void Graphic::draw_bitmap(Point leftTop, S16 bitMapWidth, S16 bitMapHigh, Datas<Color::ColorType>& pic)
{
	Screen::draw_bitmap(leftTop.x, leftTop.y, bitMapWidth, bitMapHigh, pic);
}

int Graphic::distance(Point p1, Point p2)
{
	return std::sqrt(std::pow((double)(p1.x - p2.x), 2) +  std::pow((double)(p1.y - p2.y), 2));
}
