#include "textbox.h"

TextBox::TextBox(String text,  U16 _sizeX, U16 _sizeY, Color::ColorValue fontColor, Color::ColorValue backColor):
		TouchWidget(_sizeX + 10, _sizeY), text(text), 
		slider(new Slider(Font::string_width(text.c_str()) / (area.xSize - 10) * Font::font_high(), area.ySize,  Slider::VERTICAL, 10, area.ySize)),
		backColor(backColor), fontColor(fontColor), sliderEnable(true)
{
	slider->set_controlObj(this);
}
		
		
TextBox::~TextBox()	
{
	if(slider) 
		delete slider; 
}
		
String TextBox::set_text(String& _text)
{
	String old = text; 
	text = _text;
	update();
	return old;
}

int TextBox::draw(Point p)
{
	area.position = p;
	drawed = true; 
	
	//Out::print(real_position().x, real_position().y, "Text Box");
	//Graphic::draw_empty_rectangle(real_area().position, area.xSize, area.ySize, ~backColor);

	update();
	
	return 1;
}

int  TextBox::update(void* p) 	
{ 
	bool sliderEnbaleTemp = sliderEnable;
	
	RectType rec = set_father_window(true);
	
	/*
			如果slider被Enable了则程序自动计算是否显示Slider
	*/
	if(sliderEnbaleTemp)
	{
		int len = Font::string_width(text.c_str(), Font::fontFormat.fontType);
		int lineN = len/area.xSize;
		if(lineN * Font::font_high() < area.ySize)
			sliderEnbaleTemp = false;
	}
	
	Graphic::draw_empty_rectangle(real_position(), area.xSize, area.ySize, ~backColor);
	
	if(sliderEnbaleTemp)
			slider->draw(Point(real_position().x + area.xSize - slider->area.xSize, real_position().y));
	
	Color::ColorValue c;
	
	c = Font::set_font_back_color(backColor);
	
	RectType r = Screen::set_vwindow(real_area());
	
	int line = slider->get_pos() / Font::font_high();	//获得当前位置对应的行
	int v = area.xSize / Font::font_width() * line;		//获得便宜字数
	
	if(v > 0)
		v--;
	
	if(sliderEnbaleTemp)
	{
		Graphic::draw_rectangle(real_area().position + Point(1, 1), real_area().xSize - slider->area.xSize - 2, 
		real_area().ySize - 2, backColor);
		
		Font::set_window(Graphic::RectType(real_position() + Point(1 , 1), 
		(area.xSize - slider->area.xSize)/Font::font_width(), area.ySize/Font::font_high()));
		
		Color::ColorValue c1 = Font::set_font_color(fontColor);
	
		Out::print(real_position().x, real_position().y - slider->get_pos(), text.c_str() + v);
		Font::set_font_color(c1);
	}
	else
	{
		Graphic::draw_rectangle(real_area().position + Point(1, 1), real_area().xSize - 2, 
		real_area().ySize - 2, backColor);
		
		Font::set_window(Graphic::RectType(real_position() + Point(1 , 1), 
		area.xSize/Font::font_width(), area.ySize/Font::font_high()));
		
		Color::ColorValue c1 = Font::set_font_color(fontColor);
	
		Out::print(real_position().x, real_position().y , text.c_str() + v);
		Font::set_font_color(c1);
	}
	
	Font::set_full_window();
	
	if(father)
		Font::set_font_back_color(c);
	
	release_father_window(rec);
	
	return 0;
}


void		TextBox::set_father(Pad* f)
{
	if(slider)
	{
		slider->set_father(f);
	}
	father = f;
}


bool TextBox::meet_condition(Graphic::Point touchPoint)				//是否满足激活条件
{
	return slider->meet_condition(touchPoint);
}

void TextBox::touch_handler(const  Graphic::Point p, Touchable *self, Touchable* father)				//触摸事件
{
	RectType rec = this->set_father_window(true);
	slider->touch_handler(p, self, father);
	this->release_father_window(rec);
}

void TextBox::hold_handler(const  Graphic::Point p, Touchable *self, Touchable* father)				//保持事件
{
	RectType rec = this->set_father_window(true);
	slider->hold_handler(p, self, father);
	this->release_father_window(rec);
}
void TextBox::long_hold_handler(const  Graphic::Point p, Touchable *self, Touchable* father)		//长按事件
{
	RectType rec = this->set_father_window(true);
	slider->long_hold_handler(p, self, father);
	this->release_father_window(rec);
}
void TextBox::release_handler(const  Graphic::Point p, Touchable *self, Touchable* father)			//释放事件
{
	RectType rec = this->set_father_window(true);
	slider->release_handler(p, self, father);
	this->release_father_window(rec);
}
	


