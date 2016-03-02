#include "screen.h"
#include "color.h"


const Color::ColorValue Color::RGB_RED = Color::RGB(0x3F, 0, 0);
const Color::ColorValue Color::RGB_GREEN = Color::RGB(0x00, 0x3F, 0x00);
const Color::ColorValue Color::RGB_BLUE = Color::RGB(0x00, 0x00, 0x3F); 
const Color::ColorValue Color::RGB_BLACK = Color::RGB(0x00, 0x00, 0x00);
const Color::ColorValue Color::RGB_WHITE = Color::RGB(0x3F, 0x3F, 0x3F) ;


Color::ColorValue Color::buttonColor = Color::RGB_GREEN;

Color::ColorValue Color::RGB262K(int R, int G, int B)	
{
	return (R << 12) | (G << 6) | B;
}		


Color::ColorValue Color::RGB65K(int R, int G, int B)    	
{
	return ((R << 11) | (G << 5) | B);
}
	

Color::ColorValue Color::RGB(int R, int G, int B)
{
	if(Screen::color_quality() == COLOR_262K)
		return (R << 12) | (G << 6) | B;
	else
		return ((R << 11) | (G << 5) | B);
}

Color::ColorValue Color::ColorRGB(int r, int g, int b)
{
	return Screen::color_quality() == Color::COLOR_262K ? RGB262K(r, g, b) : RGB65K(r, g, b);
}





//这里假设cv的值是连续的RGB
Color::ColorType 	Color::value2RGB262K(ColorValue cv)
{
	U32 b = cv & 0x3F;
	U32 g = (cv >> 6) & 0x3F;
	U32 r = (cv >> 12) & 0x3F;
	ColorType ct = {r, g, b};
	return ct;
}

//这里假设cv的值是连续的RGB
Color::ColorType 	Color::value2RGB65K(ColorValue cv)
{
	U16 b = cv & 0x1F;
	U16 g = (cv >> 5) & 0x3F;
	U16 r = (cv >> 11) & 0x1F;
	ColorType ct = {r, g, b};
	return ct;
}

Color::ColorType 	Color::value2RGB(ColorValue cv)
{
	if(Screen::color_quality() == COLOR_262K )
		return value2RGB262K(cv);
	else 
		return value2RGB65K(cv);
}
