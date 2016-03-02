#include "GUI.h"

#include "text.h"

String Text::set_text(String _text)
{
	String old = text;
	
	Color::ColorValue cb;
	Color::ColorValue cf;
	
	//将背景和前景设置为一样, 以便清除文字
	if(father)
	{
		cb = Font::set_font_back_color(father->backColor);
		cf = Font::set_font_color(father->backColor);
	}
	else
	{
		cb = Font::set_font_back_color(backColor);
		cf = Font::set_font_color(backColor);
	}
	
	update();
	
	text = _text;
	
	Font::set_font_color(frontColor);
	
	update();
	
	Font::set_font_color(cf);
	Font::set_font_back_color(cb);

	return old;
}

int Text::update(void* p) 	
{
	RectType r= set_father_window(true);
	
	Font::set_window(Graphic::RectType(real_position(), area.xSize/Font::font_width() , area.ySize/Font::font_high()));
	Out::print(real_position().x, real_position().y, text.c_str()); 
	Font::set_full_window();
	
	release_father_window(r);
	return 0;
}

int Text::draw(Point p)
{
	area.position = p;

	drawed = true;
	Color::ColorValue cb;
	Color::ColorValue cf;
	
	//设置背景色
	if(father)	//如果有父窗口， 则显示父窗口的背景， 否则为黑色
		cb = Font::set_font_back_color(father->backColor);
	else
		cb = Font::set_font_back_color(Color::RGB_BLACK);
	
	//设置前景色
	cf = Font::set_font_color(frontColor);
	
	update();
	
	//还原背景和前景色
	Font::set_font_back_color(cb);
	Font::set_font_color(cf);
	
	return 1;
}



// int 	Text::dedraw()
// {
// 	drawed = false;
// 	
// 	
// 	
// 	return 0;
// }
