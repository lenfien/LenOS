

#ifndef __OUT__
#define __OUT__

#include "com.h"
#include "font.h"
#include "ssd1289.h"
#include "screen.h"
#include "string.h"

class Out: protected Screen
{
	private:
		static U16 preX;	//上一次调用printf时的坐标
		static U16 preY;	//上一次调用printf时的坐标
	
	public:
		static char buffer[512];
	
	protected:
		static S8 	_print(S16 x, S16 y, char c, Font::FontType fontType);
	
	public:
		static char* _print(S16 xStart, S16 yStart, char *str, Font::FontType fontType);
		
	public:
		static char*	print(const char *format, ...);									//CMD形式输出
		static char* 	print(S16 x, S16 y, const char *format, ...);		//
		static char* 	printl(S16 x, S16 y, const char *format, ...);	//
};



#endif
