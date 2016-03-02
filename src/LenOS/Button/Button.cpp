#include "button.h"
#include "out.h"
#include "font.h"
#include "widget.h"
#include "touchPad.h"

Button::
Button(			String _content,  
						U16 	_sizeX, 
						U16 	_sizeY , 
						void (*_touchHandler)(const  Graphic::Point p, Touchable *self, Touchable *father ),					//触摸事件
						void (*_holdHandler)(const  Graphic::Point p, Touchable *self, Touchable *father ),						//保持事件
						void (*_longHoldHandler)(const  Graphic::Point p, Touchable *self, Touchable *father ) ,				//长按事件
						void (*_releaseHandler)(const  Graphic::Point p, Touchable *self, Touchable *father ),
			 			Vector<Touchable*>* touches
			):TouchWidget(_sizeX, _sizeY, touches, _touchHandler, _holdHandler, _longHoldHandler, _releaseHandler), content(_content), pressed(false)
{
	area.xSize = max(Font::string_width(content.c_str()) + 2, _sizeX);
	area.ySize = max(Font::char_high('A') + 2, _sizeY);
	drawed = false;
	buttonColor.backColor = Color::RGB_BLUE;
	buttonColor.contentColor = Color::RGB_WHITE;
	buttonColor.frameColor = Color::RGB_GREEN;
}


bool Button::draw_myself()
{
	area.xSize = max(Font::string_width(content.c_str()) + 2, area.xSize);
	area.ySize = max(Font::char_high('A') + 2, area.ySize);
	
	if(real_position().x + area.xSize >= Screen::width() ||real_position().y + area.ySize >= Screen::high())
	{
		return drawed = false;
	}
	
	RectType rec = set_father_window(1);
	
	Graphic::draw_rectangle(real_position(), area.xSize, area.ySize, 
					buttonColor.backColor, buttonColor.frameColor, 1);
	
	Color::ColorValue cvb = Font::set_font_back_color(buttonColor.backColor);
	Color::ColorValue cvf = Font::set_font_color(buttonColor.contentColor);
	
	Out::print(real_position().x + ( area.xSize - Font::string_width(content.c_str()))/2, 
							real_position().y + ( area.ySize - Font::char_high('A'))/2, content.c_str());	
	
	Font::set_font_back_color(cvb);
	Font::set_font_color(cvf);
	
	release_father_window(rec);
	
	return true;
}


//绘制
int Button::draw(Point p)
{
	if(p.x >= 0 && p.y >= 0)
		area.position = p;
	
	return drawed = update();
}

int Button::dedraw()
{
	drawed = false;
	return 0;
}


void* Button::get_info()
{
	return this;
}

int Button::update(void *p)
{
	
	draw_myself();

	return true;
}


String	Button::get_content()
{
	return content;
}

String 	Button::set_content(String newContent)
{
	String old = content;
	content = newContent;
	
	update();
	
	return old;
}
	

void Button::touch_handler(const Graphic::Point p, Touchable *self, Touchable *father )
{
	TouchPad::some_widget_down = true; 
	pressed = true;
	
	buttonColor.backColor = ~buttonColor.backColor;
	buttonColor.contentColor = ~buttonColor.contentColor;
	this->draw_myself();
	buttonColor.backColor = ~buttonColor.backColor;
	buttonColor.contentColor = ~buttonColor.contentColor;
}

void Button::hold_handler(const Graphic::Point p, Touchable *self, Touchable *father )
{
	
}

void Button::long_hold_handler(const Graphic::Point p, Touchable *self, Touchable *father )
{
	
}

void Button::release_handler(const Graphic::Point p, Touchable *self, Touchable *father )
{
	TouchPad::some_widget_down = false; 
	pressed = false;
	
	this->draw_myself();
}
