
#include <cmath>
#include "com.h"
#include "pad.h"
#include "out.h"
#include "font.h"
#include "widget.h"
#include "vector.h"

Vector<Pad*>		PadSources::pads;

Pad::Pad( U16 _sizeX, U16 _sizeY, Color::ColorValue cv):
area(RectType(Point(0,0), _sizeX, _sizeY)), validArea(valid_area()), backColor(cv), layer(-1)
{
	
}

Pad::~Pad()	
{
	active();
	recover();
	
	Vector<Widget*>::iterator it = widgets.begin();
	
	while(it != widgets.end())
	{
		if(*it != null)
			delete *it;
		it++;
	}
	
	widgets.clear();
	if(backUp.amount)
		backUp.clear(); 
}

/*
	���浱ǰ��leftTop, sizeX, sizeY��ָ��������ĵ���
*/
void Pad::record(bool front)
{
	backUp.clear();
	Graphic::get_points(area.position.x, area.position.y, area.xSize, area.ySize, backUp);
}

/*
	�ָ�����ĵ�����Ϣ����ǰleftTop, sizeX, sizeY��ָ��������
*/
void Pad::recover(bool front)
{
	if(backUp.amount == 0)
		return;
	
	Graphic::draw_bitmap(area.position.x, area.position.y, area.xSize, area.ySize, backUp);
}

Graphic::Point pt;
void Pad::record_frame(Point p)
{
	pt = p;
	
	Graphic::get_points(p.x, p.y, area.xSize, 1, backUpFrame[0]);
	Graphic::get_points(p.x, p.y, 1, area.ySize, backUpFrame[1]);
	Graphic::get_points(p.x + area.xSize - 1, p.y, 1, area.ySize, backUpFrame[2]);
	Graphic::get_points(p.x, p.y + area.ySize - 1, area.xSize, 1, backUpFrame[3]);
}

void Pad::recover_frame()
{
	//Graphic::RectType t = RectType(pt, area.xSize, area.ySize);
	
	Graphic::draw_bitmap(pt.x, pt.y, area.xSize, 1, backUpFrame[0]);
	Graphic::draw_bitmap(pt.x, pt.y, 1, area.ySize, backUpFrame[1]);
	Graphic::draw_bitmap(pt.x + area.xSize - 1, pt.y, 1, area.ySize, backUpFrame[2]);
	Graphic::draw_bitmap(pt.x, pt.y + area.ySize - 1, area.xSize, 1, backUpFrame[3]);
	
	backUpFrame[0].clear();
	backUpFrame[1].clear();
	backUpFrame[2].clear();
	backUpFrame[3].clear();
}


void Pad::draw_frame(Point p)
{
	Graphic::draw_empty_rectangle(p, area.xSize, area.ySize, backColor);
}

int Pad::draw(Point p)
{
	if(p.x + area.xSize >= Screen::width() || p.y + area.ySize >= Screen::high())
		return false;
		
	area.position = p;
	
	update_widgets_rela_position();
	
	validArea = valid_area();
	
	record();
	
	draw_rectangle(area.position, area.xSize, area.ySize, backColor, ~backColor);
	
	update();
	
	drawed = true;
	
	if(layer == -1)
	{
		PadSources::pads.push_back(this);
		
		Vector<Pad*>::iterator it1 = PadSources::pads.begin();

		while(it1 != PadSources::pads.end())
		{
			(*it1)->layer++;
			it1++;
		}
	}
	return true;
}

bool if_cover()
{
	return false;
}

int Pad::update(void *p)
{
	Vector<Widget*>::iterator it = widgets.begin();
	
	//RectType r = Screen::set_vwindow(valid_area());
	
	//draw_rectangle(area.position, area.xSize, area.ySize, backColor, ~backColor);
	
	for(; it != widgets.end(); it++ )
		(*it)->draw((*it)->area.position);
	
	//Screen::restore_vwindow(r);
	return 1;
}


bool is_maller(Pad* p1, Pad* p2)
{
	return p1->layer < p2->layer;
}

/*
	���Լ�������߲㣬 ���������������ƶ�
*/
int Pad::active()
{
	if(layer == 0)
		return 0;
	
	sort(PadSources::pads.begin(), PadSources::pads.end(), is_maller);
	
	Vector<Pad*>::iterator it = PadSources::pads.begin();
	
	//����߲㵽��Ͳ㻹ԭ
	for(it = PadSources::pads.rbegin(); (*it)->layer <= layer && it != PadSources::pads.rend(); it--)
		(*it)->recover();
	
	it += 2;
	
	for(; it < PadSources::pads.end(); it ++)
	{
		(*it)->layer++;
		(*it)->draw((*it)->area.position);
	}
	
	layer = 0;
	
	draw(area.position);
	
	return 0;
}

void Pad::redraw_all()
{
	sort(PadSources::pads.begin(), PadSources::pads.end(), is_maller);
	
	Vector<Pad*>::iterator it;
	
	//����߲㵽��Ͳ㻹ԭ
	for(it = PadSources::pads.rbegin(); (*it)->layer <= layer && it != PadSources::pads.rend(); it--)
		(*it)->recover();
	
	it = PadSources::pads.begin();
	
	for(; it < PadSources::pads.end(); it ++)
	{
		(*it)->layer++;
		(*it)->draw((*it)->area.position);
	}
}


int Pad::dedraw()
{
	active();
	recover();
	
	drawed = false;
	
	this->backUp.clear();
	
	PadSources::pads.erase(PadSources::pads.find(this));
	
	Vector<Pad*>::iterator it = PadSources::pads.begin();
	
	while(it != PadSources::pads.end())
	{
		if((*it)->layer != 0)
			(*it)->layer--;

		it++;
	}
	
	//redraw_all();
	
	return 0;
}

/*
	��P�Ƿ���Pad��
*/
bool Pad::if_in(Graphic::Point p, Graphic::RectType& r)
{
	if(p.x >= r.position.x && p.y >= r.position.y && p.x < r.position.x + r.xSize && p.y < r.position.y + r.ySize)
		return true;
	
	return false;
}


//�����������֮�串�ǵľ��Σ� �洢��dis�У� ��������Ƿ���false
bool Pad::if_covered(Point p)
{
	Vector<Pad*>::iterator it = PadSources::pads.begin();
	
	while(it != PadSources::pads.end())
	{
		if((*it)->if_in(p, (*it)->area) && (*it)->layer < layer)
			return true;
		it++;
	}
	
	return false;
}




bool Pad::move(Point newLeftTop)
{
	if(newLeftTop == area.position)
		return true;
	
	Graphic::revise_rectangle_position(newLeftTop, area.xSize, area.ySize);
	
	if(std::abs(newLeftTop.x - area.position.x) < 5 && std::abs(newLeftTop.y - area.position.y) < 5)
		return true;
	
	active();
	
	recover();
	
	draw(newLeftTop);
	
	return 0;
}


Pad& Pad::add_widget(Widget* w, Graphic::Point p)
{
	w->area.position = p;
	w->set_father(this);
	
	widgets.push_back(w);
	w->set_relataive_position(area.position + widget_off_position());
	
	if(drawed)
		update();
	return *this;
}

void  Pad::update_widgets_rela_position()
{
	Vector<Widget*>::iterator it = widgets.begin();
	for(; it != widgets.end(); it++ )
		(*it)->set_relataive_position(area.position + widget_off_position());
}



