
#ifndef __WIDGET_TEXT__
#define __WIDGET_TEXT__

#include "GUI.h"

class Text: public Widget
{
	private:
		String text;
		
	public:
		Color::ColorValue frontColor;
		Color::ColorValue backColor;
		
	
		Text(String text,  U16 _sizeX = 100, U16 _sizeY = 20, Point _leftTop = Point(0, 0)):
		Widget(_sizeX, _sizeY), text(text), frontColor(Color::RGB_WHITE)
		{
			
		}
		
		String set_text(String _text);
		
		virtual int draw(Point p);
		
		virtual int 	dedraw()	{drawed = false; return 0;}
		virtual int 	update(void* p = 0);
};


#endif
