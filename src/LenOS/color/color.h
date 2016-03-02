#ifndef __COLOR__
#define __COLOR__

#include "com.h"

class Color
{
public:
	typedef	struct tag
	{
		U8 r, g, b;
		//U8 transparent;	//透明度
		bool operator==(struct tag t)	{ return r == t.r && g == t.g && b == t.b; }
	}ColorType;
	
	typedef enum
	{
		COLOR_65K,
		COLOR_262K
	}ColorQuality;
	
	typedef U32 ColorValue;
	const static ColorValue InvalidColor = 0xFFFFFFFF;

	static ColorValue RGB262K(int R, int G, int B);
	static ColorValue RGB65K(int R, int G, int B);
	
	static ColorValue RGB(int R, int G, int B);
	static ColorValue ColorRGB(int r, int g, int b);
	
	static ColorType	value2RGB262K(ColorValue);
	static ColorType	value2RGB65K(ColorValue);
	static ColorType 	value2RGB(ColorValue cv);
	
	const static ColorValue RGB_RED;
	const static ColorValue RGB_GREEN;
	const static ColorValue RGB_BLUE;
	const static ColorValue RGB_BLACK;
	const static ColorValue RGB_WHITE;
	
//*******************系统颜色定义************************//

	static ColorValue buttonColor;
};

#endif

/*
	//262K颜色定义
	#define RGB_262K_RED      RGB_262K(0x3F, 0, 0)
	#define RGB_262K_GREEN    RGB_262K(0, 0x3F, 0)
	#define RGB_262K_BLUE     RGB_262K(0, 0, 0x3F)
	#define RGB_262K_BLACK    RGB_262K(0, 0, 0)
	#define RGB_262K_WHITE    RGB_262K(0x3F, 0x3F, 0x3F)

	//65K颜色定义
	#define RGB_65K_RED		  RGB_65K(0x1F, 0, 0) 
	#define RGB_65K_GREEN     RGB_65K(0, 0x3F, 0) 
	#define RGB_65K_BLUE      RGB_65K(0, 0, 0x1F) 
	#define RGB_65K_BLACK     RGB_65K(0, 0, 0) 
	#define RGB_65K_WHITE     RGB_65K(0x1F, 0x3F, 0x1F)
*/
