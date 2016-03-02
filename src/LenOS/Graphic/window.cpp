#include "window.h"
#include "out.h"
#include "color.h"
#include "vector.h"

Window::Window(String _name, 
				U16 _sizeX, U16 _sizeY, 
				Color::ColorValue cv,
				void (*_touchHandler)(const  Graphic::Point p, Touchable *self, Touchable *father ) ,					//触摸事件
				void (*_holdHandler)(const  Graphic::Point p, Touchable *self, Touchable *father ),						//保持事件
				void (*_longHoldHandler)(const  Graphic::Point p, Touchable *self, Touchable *father ),				//长按事件
				void (*_releaseHandler)(const  Graphic::Point p, Touchable *self, Touchable *father )):
				TouchPad(_sizeX, _sizeY, cv, 
				_touchHandler,					//触摸事件
				_holdHandler,						//保持事件
				_longHoldHandler,				//长按事件
				_releaseHandler),
				Paintable(&validArea),
				name(_name),
				distroyButton(new Button("*" , 1, 1, 0, 0, 0, shutdown_handler, touchWidgets)), 
				verticalSlider(new Slider(200, _sizeY, Slider::VERTICAL, 10, _sizeY - high_of_title() - 1)),
				titleColor(~cv), vPosition(Point(0, 0)), userUI(0), 
				sliderEnable(true), closeEnable(true),
				close_handler(0)
{
	touchWidgets->push_back(distroyButton);
	
	distroyButton->set_relataive_position(area.position);
	
	verticalSlider->set_relataive_position(area.position);
	verticalSlider->set_controlObj(this);
	verticalSlider->set_father(this);
	verticalSlider->set_touch_vector(touchWidgets);
	
	update_slider();
}


Window::~Window()
{
	if(verticalSlider)
		delete verticalSlider;
	
	if(distroyButton)
		delete distroyButton;
}

void Window::dispose()
{
	this->process.stop();
	
	if(close_handler)
		close_handler(this);
	
	System::Event e  = {System::WindowDistroy , this};
	System::push_event(e);
}

Graphic::RectType& Window::valid_area(int i)
{
	static RectType r;
	
	if(sliderEnable)
	{
		r = RectType(area.position + Point(1, high_of_title()),
										area.xSize - verticalSlider->area.xSize - 1, area.ySize - high_of_title() - 1);
	}
	else
	{
		r = RectType(area.position + Point(1, high_of_title()),
										area.xSize - 2, area.ySize - high_of_title() - 1);
	}

	return r;
}

int Window::draw(Point p)
{
	static Point defP = Point(0, 0);
	
	if(p == Point(-1, -1))
	{
		if(defP.y + area.ySize >= Screen::high())
		{
			defP.x += 10;
			defP.y = 0;
		}
		else
		{
			defP.x += 10;
			defP.y += 15;
		}
		
		p = defP;
	}
	else
	{
		defP = Point(0, 0);
	}
	
	drawed = false;
	Pad::draw(p);
	
	if(sliderEnable)
		verticalSlider->draw(Point(area.position.x + area.xSize - verticalSlider->area.xSize - 1 , area.position.y + high_of_title()));
	
	drawed = true;
	return 0;
}
		
int Window::update(void* p)
{
	Color::ColorValue c;
	c = layer ? ~backColor : 0;
	
	/*
		根据滑动条的位置更新内容
	*/
	if(vPosition.y != verticalSlider->get_pos())
	{
		vPosition.x = 0;
		vPosition.y = verticalSlider->get_pos();
		update_widgets_rela_position();
	}
	
	RectType vr = valid_area();
	
	draw_rectangle(vr.position, vr.xSize, vr.ySize, backColor, ~backColor);
	
	RectType r = Screen::set_vwindow(vr);		//设置当前的虚拟窗口
	
	if(userUI)
		userUI(this);
	
	Pad::update();
	Screen::restore_vwindow(r);			//恢复虚拟窗口为之前的值
	
	if(drawed == false)
	{
		Graphic::draw_rectangle(area.position, area.xSize, high_of_title(), c, ~backColor); 
		
		if(closeEnable)
		{
			distroyButton->buttonColor.backColor = ~c;
			distroyButton->buttonColor.contentColor = c;
			
			int x = area.position.x + area.xSize - distroyButton->area.xSize;
			
			distroyButton->draw(Point(x, area.position.y));	
		}
		
		Color::ColorValue cv = Font::set_font_back_color(c);
		Color::ColorValue cf = Font::set_font_color(~c);
		
		Out::print(area.position.x + 1, area.position.y + 1, name.c_str());	//显示标题
		Font::set_font_back_color(cv);
		Font::set_font_color(cf);
	}
	
	return 1;
}

void Window::add_thread(void (*thread)())
{
	process.add_thread(thread);
}

void Window::delete_thread(void (*thread)())
{
	process.delete_thread(thread);
}

void Window::run_process()
{
	process.run();
}

extern Graphic::Point _div;
int t = 0;
void Window::touch_handler(const  Graphic::Point p, Touchable *self, Touchable *father )
{
	RectType r(area.position, area.xSize, high_of_title());
	          
	if(if_in(p, r))
	{
		something_being_dragged = true;
		_div = area.position - p;
		drag = true;
	}
	else
	{
		something_being_dragged = false;
		drag = false;
	}
	
	pressed = true;
	active();
}

/*
	 更新Slider的范围
*/
void Window::update_slider()
{
	Vector<Widget*>::iterator it = widgets.begin();
	
	int maxPos = 0;
	
	for(; it != widgets.end(); it ++)
	{
		int pos = (*it)->real_position().y + (*it)->area.ySize - valid_area().position.y;
		if(pos > maxPos)
			maxPos = pos;
	}
	verticalSlider->set_range(maxPos, valid_area().ySize);
}

Window& Window::add_widget(Widget* tw, Point p)
{
	TouchPad::add_widget(tw, p);
	update_slider();
	return *this;
}


void (*Window::set_close_handler(void (*h)(Window* )))(Window*)
{
	void (*old)(Window*) = close_handler;
	close_handler = h;
	return old;
}

/////////////////////
void Window::shutdown_handler(Graphic::Point p, Touchable *self, Touchable *father)
{
	Window* pf = (Window*)father;
	pf->dispose();
}


Graphic::Point pMove1;
Graphic::Point preFramPos = Graphic::Point(-1, -1);
void Window::hold_handler(const  Graphic::Point p, Touchable *self, Touchable *father )
{
	TouchPad::hold_handler(p, self, father);
}


void Window::long_hold_handler(const  Graphic::Point p, Touchable *self, Touchable *father )
{
	
}


void Window::release_handler(const  Graphic::Point p, Touchable *self, Touchable *father )
{
	something_being_dragged = false;
	drag = false;
	pressed = false;
}


void (*Window::set_UI(void (*u)(Window*)))(Window*)
{
	void (*old)(Window*) = userUI;
	userUI = u;
	return old;
}

