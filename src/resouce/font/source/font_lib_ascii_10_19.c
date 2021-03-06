


#include "font_lib.h"
#include "font_operation.h"

FONT_LIB ansi_font10x19_inf = 
{
	WIDTH_FIXED,	//宽度为固定
	10,             //宽
	19,             //高
	ALIGN_LEFT      //对其方式
};


FONT ansi_10x19_font = {&ansi_font10x19_inf};

PFONT FONT_interface_ascii_10x19_get_font(char c)
{
	//如果不在可视范围内，返回0
	if(c < 0x20 || c > 126)
	{
		ansi_10x19_font.pChar = 0;									//指向点阵的指针
		ansi_10x19_font.fontHigh = 0;     //字符高度
		ansi_10x19_font.fontWidth = 0;   //字符宽度
	}
	else
	{
		ansi_10x19_font.pChar = ansi_font10x19[c - 0x20];			//指向点阵的指针
		ansi_10x19_font.fontHigh = ansi_font10x19_inf.fontHigh;     //字符高度
		ansi_10x19_font.fontWidth = ansi_font10x19_inf.fontWidth;   //字符宽度
	}
	
	
	return &ansi_10x19_font;
}

const FONT_LIB* FONT_interface_ascii_10x19_get_lib()
{
	return &ansi_font10x19_inf;
}

const unsigned char ansi_font10x19[][38];	
/*= 
{
		//Char: 
		//Val:(0x0020)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:!
		//Val:(0x0021)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x1c, 0x00, 0x1c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:"
		//Val:(0x0022)
		{0x00, 0x00, 0x1f, 0x80, 0x3f, 0x80, 0x3f, 0x00, 0x7e, 0x00, 0x6c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
	
		//Char:#
		//Val:(0x0023)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x33, 0x00, 0x33, 0x00, 0x33, 0x00, 0xff, 0xc0, 0x33, 0x00, 0x33, 0x00, 0x33, 0x00, 0x33, 0x00, 0x73, 0x00, 0xff, 0xc0, 0x67, 0x00, 0x66, 0x00, 0x66, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:$
		//Val:(0x0024)
		{0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x1f, 0x00, 0x7f, 0x80, 0x7f, 0x80, 0x7c, 0x00, 0x7c, 0x00, 0x3c, 0x00, 0x0e, 0x00, 0x0f, 0x00, 0x0f, 0x80, 0x7f, 0x80, 0x7f, 0x80, 0x7f, 0x80, 0x3e, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x00, 0x00},

		//Char:%
		//Val:(0x0025)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf3, 0x00, 0xdb, 0x00, 0xde, 0x00, 0xde, 0x00, 0xde, 0x00, 0xfc, 0x00, 0xff, 0x80, 0x1e, 0xc0, 0x1e, 0xc0, 0x36, 0xc0, 0x36, 0xc0, 0x36, 0xc0, 0x63, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:&
		//Val:(0x0026)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x7e, 0x00, 0x6e, 0x00, 0x6e, 0x00, 0x7c, 0x00, 0x7f, 0x80, 0x7b, 0x00, 0xfb, 0x00, 0xdf, 0x00, 0xde, 0x00, 0xce, 0x00, 0xef, 0xc0, 0x7f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:'
		//Val:(0x0027)
		{0x00, 0x00, 0x70, 0x00, 0x70, 0x00, 0x30, 0x00, 0x70, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:(
		//Val:(0x0028)
		{0x00, 0x00, 0x01, 0xc0, 0x03, 0x80, 0x03, 0x00, 0x06, 0x00, 0x0e, 0x00, 0x0e, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0e, 0x00, 0x0e, 0x00, 0x06, 0x00, 0x07, 0x00, 0x03, 0x80, 0x01, 0xc0, 0x00, 0x00},

		//Char:)
		//Val:(0x0029)
		{0x00, 0x00, 0xe0, 0x00, 0x70, 0x00, 0x30, 0x00, 0x18, 0x00, 0x1c, 0x00, 0x1c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x1c, 0x00, 0x1c, 0x00, 0x18, 0x00, 0x30, 0x00, 0x70, 0x00, 0xe0, 0x00, 0x00, 0x00},

		//Char:*
		//Val:(0x002a)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x1c, 0x00, 0xed, 0xc0, 0xff, 0xc0, 0x1e, 0x00, 0x1e, 0x00, 0xff, 0xc0, 0xed, 0xc0, 0x1c, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:+
		//Val:(0x002b)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0xff, 0xc0, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:,
		//Val:(0x002c)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x70, 0x00, 0x30, 0x00, 0x70, 0x00, 0xe0, 0x00, 0x00, 0x00},

		//Char:-
		//Val:(0x002d)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:.
		//Val:(0x002e)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:/
		//Val:(0x002f)
		{0x00, 0x00, 0x01, 0x80, 0x01, 0x80, 0x03, 0x00, 0x03, 0x00, 0x07, 0x00, 0x06, 0x00, 0x0e, 0x00, 0x0c, 0x00, 0x1c, 0x00, 0x18, 0x00, 0x38, 0x00, 0x30, 0x00, 0x70, 0x00, 0x60, 0x00, 0x60, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:0
		//Val:(0x0030)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x3f, 0x00, 0x73, 0x80, 0x63, 0x80, 0xe1, 0xc0, 0xe1, 0xc0, 0xe1, 0xc0, 0xe1, 0xc0, 0xe1, 0xc0, 0x63, 0x80, 0x73, 0x80, 0x3f, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:1
		//Val:(0x0031)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x3c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0e, 0x00, 0x3f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:2
		//Val:(0x0032)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x00, 0x73, 0x80, 0x61, 0x80, 0x71, 0x80, 0x01, 0x80, 0x03, 0x80, 0x07, 0x00, 0x0e, 0x00, 0x1c, 0x00, 0x38, 0x00, 0x71, 0x80, 0x61, 0x80, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:3
		//Val:(0x0033)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x00, 0x73, 0x80, 0x63, 0x80, 0x73, 0x80, 0x07, 0x00, 0x1e, 0x00, 0x03, 0x00, 0x03, 0x80, 0x01, 0x80, 0x71, 0x80, 0xf3, 0x80, 0x73, 0x80, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:4
		//Val:(0x0034)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x0f, 0x00, 0x0f, 0x00, 0x1f, 0x00, 0x3f, 0x00, 0x37, 0x00, 0x67, 0x00, 0x67, 0x00, 0xff, 0xc0, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x1f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:5
		//Val:(0x0035)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x80, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x7f, 0x00, 0x73, 0x80, 0x01, 0x80, 0x01, 0x80, 0x71, 0x80, 0x61, 0x80, 0x73, 0x80, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:6
		//Val:(0x0036)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x3b, 0x80, 0x73, 0x80, 0x60, 0x00, 0xe0, 0x00, 0xff, 0x00, 0xf3, 0x80, 0xe1, 0xc0, 0xe1, 0xc0, 0xe1, 0xc0, 0x71, 0x80, 0x7b, 0x80, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:7
		//Val:(0x0037)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x80, 0x63, 0x80, 0x63, 0x00, 0x07, 0x00, 0x06, 0x00, 0x0e, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x1c, 0x00, 0x1c, 0x00, 0x1c, 0x00, 0x1c, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
	
		//Char:8
		//Val:(0x0038)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x00, 0x73, 0x80, 0x61, 0x80, 0x61, 0x80, 0x71, 0x80, 0x3b, 0x00, 0x3f, 0x00, 0x77, 0x80, 0xe3, 0x80, 0xe1, 0xc0, 0xe1, 0x80, 0x73, 0x80, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:9
		//Val:(0x0039)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x73, 0x80, 0xe3, 0x80, 0xe1, 0x80, 0xe1, 0xc0, 0xe3, 0xc0, 0x77, 0xc0, 0x3f, 0x80, 0x03, 0x80, 0x03, 0x80, 0x73, 0x80, 0x77, 0x00, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char::
		//Val:(0x003a)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:;
		//Val:(0x003b)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x0c, 0x00, 0x1c, 0x00, 0x00, 0x00},

		//Char:<
		//Val:(0x003c)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x03, 0x00, 0x06, 0x00, 0x1c, 0x00, 0x38, 0x00, 0x70, 0x00, 0xe0, 0x00, 0x70, 0x00, 0x38, 0x00, 0x1c, 0x00, 0x0e, 0x00, 0x07, 0x00, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:=
		//Val:(0x003d)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:>
		//Val:(0x003e)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x70, 0x00, 0x38, 0x00, 0x1c, 0x00, 0x06, 0x00, 0x03, 0x00, 0x01, 0x80, 0x03, 0x00, 0x06, 0x00, 0x0c, 0x00, 0x18, 0x00, 0x30, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:?
		//Val:(0x003f)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x00, 0x73, 0x80, 0xe1, 0xc0, 0xf1, 0xc0, 0xf1, 0xc0, 0x03, 0x80, 0x07, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:@
		//Val:(0x0040)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x39, 0x80, 0x7f, 0xc0, 0x7f, 0xc0, 0xfb, 0xc0, 0xfb, 0xc0, 0xff, 0xc0, 0xff, 0xc0, 0xff, 0xc0, 0xff, 0x80, 0x60, 0xc0, 0x31, 0x80, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:A
		//Val:(0x0041)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x1c, 0x00, 0x1e, 0x00, 0x3e, 0x00, 0x3e, 0x00, 0x36, 0x00, 0x37, 0x00, 0x77, 0x00, 0x7f, 0x00, 0x63, 0x00, 0x63, 0x80, 0xe3, 0x80, 0xf7, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:B
		//Val:(0x0042)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x73, 0x80, 0x71, 0x80, 0x71, 0x80, 0x73, 0x80, 0x7e, 0x00, 0x73, 0x80, 0x71, 0xc0, 0x71, 0xc0, 0x71, 0xc0, 0x71, 0xc0, 0x73, 0x80, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:C
		//Val:(0x0043)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x80, 0x3b, 0x80, 0x71, 0xc0, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0xc0, 0x71, 0x80, 0x73, 0x80, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:D
		//Val:(0x0044)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x77, 0x80, 0x73, 0x80, 0x71, 0xc0, 0x71, 0xc0, 0x71, 0xc0, 0x71, 0xc0, 0x71, 0xc0, 0x71, 0xc0, 0x71, 0xc0, 0x73, 0x80, 0x77, 0x80, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:E
		//Val:(0x0045)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x80, 0x73, 0x80, 0x71, 0x80, 0x73, 0x00, 0x77, 0x00, 0x7f, 0x00, 0x77, 0x00, 0x73, 0x00, 0x70, 0x00, 0x70, 0x00, 0x70, 0xc0, 0x71, 0x80, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:F
		//Val:(0x0046)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x80, 0x71, 0xc0, 0x70, 0xc0, 0x73, 0x00, 0x73, 0x00, 0x7f, 0x00, 0x73, 0x00, 0x73, 0x00, 0x70, 0x00, 0x70, 0x00, 0x70, 0x00, 0x70, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:G
		//Val:(0x0047)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x80, 0x73, 0x80, 0x71, 0x80, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe7, 0xc0, 0xe3, 0x80, 0xe3, 0x80, 0x73, 0x80, 0x73, 0x80, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:H
		//Val:(0x0048)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf3, 0xc0, 0x61, 0x80, 0x61, 0x80, 0x61, 0x80, 0x61, 0x80, 0x61, 0x80, 0x7f, 0x80, 0x61, 0x80, 0x61, 0x80, 0x61, 0x80, 0x61, 0x80, 0x61, 0x80, 0xf3, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
	
		//Char:I
		//Val:(0x0049)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x80, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x7f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:J
		//Val:(0x004a)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xc0, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0xee, 0x00, 0xfc, 0x00, 0x00, 0x00},

		//Char:K
		//Val:(0x004b)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xc0, 0x73, 0x00, 0x77, 0x00, 0x76, 0x00, 0x7c, 0x00, 0x7c, 0x00, 0x7c, 0x00, 0x7e, 0x00, 0x77, 0x00, 0x77, 0x00, 0x73, 0x80, 0x73, 0x80, 0xfb, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:L
		//Val:(0x004c)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x70, 0x00, 0x70, 0x00, 0x70, 0x00, 0x70, 0x00, 0x70, 0x00, 0x70, 0x00, 0x70, 0x00, 0x70, 0x00, 0x70, 0x00, 0x70, 0xc0, 0x71, 0x80, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:M
		//Val:(0x004d)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe3, 0xc0, 0xe3, 0x80, 0xf3, 0x80, 0xf3, 0x80, 0xf7, 0x80, 0xf7, 0x80, 0xff, 0x80, 0xff, 0x80, 0xff, 0x80, 0xdd, 0x80, 0xdd, 0x80, 0xdd, 0x80, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:N
		//Val:(0x004e)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe3, 0xc0, 0x71, 0x80, 0x79, 0x80, 0x79, 0x80, 0x7d, 0x80, 0x7d, 0x80, 0x6f, 0x80, 0x6f, 0x80, 0x67, 0x80, 0x63, 0x80, 0x63, 0x80, 0x61, 0x80, 0xf1, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:O
		//Val:(0x004f)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x73, 0x80, 0x71, 0x80, 0xe1, 0xc0, 0xe1, 0xc0, 0xe1, 0xc0, 0xe1, 0xc0, 0xe1, 0xc0, 0xe1, 0xc0, 0xe1, 0xc0, 0x71, 0x80, 0x33, 0x80, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:P
		//Val:(0x0050)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x73, 0x80, 0x71, 0xc0, 0x71, 0xc0, 0x71, 0xc0, 0x73, 0x80, 0x7f, 0x00, 0x70, 0x00, 0x70, 0x00, 0x70, 0x00, 0x70, 0x00, 0x70, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:Q
		//Val:(0x0051)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x00, 0x73, 0x80, 0x71, 0x80, 0xe1, 0xc0, 0xe1, 0xc0, 0xe1, 0xc0, 0xe1, 0xc0, 0xe1, 0xc0, 0xe1, 0xc0, 0xff, 0xc0, 0x7f, 0xc0, 0x77, 0x80, 0x3f, 0x00, 0x07, 0xc0, 0x03, 0x80, 0x00, 0x00},

		//Char:R
		//Val:(0x0052)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x73, 0x80, 0x71, 0xc0, 0x71, 0x80, 0x73, 0x80, 0x7f, 0x00, 0x7e, 0x00, 0x76, 0x00, 0x77, 0x00, 0x77, 0x00, 0x73, 0x80, 0x73, 0x80, 0xf9, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:S
		//Val:(0x0053)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x80, 0x73, 0x80, 0xe1, 0xc0, 0xe0, 0x00, 0x60, 0x00, 0x38, 0x00, 0x1f, 0x00, 0x03, 0x80, 0x01, 0x80, 0xc1, 0xc0, 0xe1, 0x80, 0x73, 0x80, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
	
		//Char:T
		//Val:(0x0054)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x80, 0xed, 0xc0, 0xcc, 0xc0, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:U
		//Val:(0x0055)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf3, 0xc0, 0x61, 0x80, 0x61, 0x80, 0x61, 0x80, 0x61, 0x80, 0x61, 0x80, 0x61, 0x80, 0x61, 0x80, 0x61, 0x80, 0x61, 0x80, 0x71, 0x80, 0x73, 0x80, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:V
		//Val:(0x0056)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf3, 0xc0, 0x61, 0x80, 0x71, 0x80, 0x73, 0x80, 0x73, 0x00, 0x3b, 0x00, 0x3f, 0x00, 0x3e, 0x00, 0x1e, 0x00, 0x1e, 0x00, 0x1c, 0x00, 0x1c, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:W
		//Val:(0x0057)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xc0, 0xed, 0xc0, 0xed, 0x80, 0x6f, 0x80, 0x6f, 0x80, 0x7f, 0x80, 0x7f, 0x80, 0x7f, 0x80, 0x7f, 0x00, 0x3f, 0x00, 0x3f, 0x00, 0x37, 0x00, 0x33, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:X
		//Val:(0x0058)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xc0, 0x73, 0x00, 0x33, 0x00, 0x3e, 0x00, 0x3e, 0x00, 0x1c, 0x00, 0x1c, 0x00, 0x1e, 0x00, 0x1e, 0x00, 0x37, 0x00, 0x37, 0x00, 0x63, 0x80, 0xf7, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:Y
		//Val:(0x0059)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfb, 0xc0, 0x71, 0x80, 0x73, 0x00, 0x33, 0x00, 0x3f, 0x00, 0x3e, 0x00, 0x1e, 0x00, 0x1c, 0x00, 0x1c, 0x00, 0x1c, 0x00, 0x1c, 0x00, 0x1c, 0x00, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:Z
		//Val:(0x005a)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xc0, 0x73, 0x80, 0x63, 0x80, 0x07, 0x00, 0x06, 0x00, 0x0e, 0x00, 0x0c, 0x00, 0x1c, 0x00, 0x38, 0x00, 0x38, 0x00, 0x71, 0x80, 0x73, 0x80, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:[
		//Val:(0x005b)
		{0x00, 0x00, 0x1f, 0x80, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x1f, 0x80, 0x00, 0x00, 0x00, 0x00},

		//Char:\
		//Val:(0x005c)
		{0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x70, 0x00, 0x30, 0x00, 0x30, 0x00, 0x38, 0x00, 0x18, 0x00, 0x1c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0e, 0x00, 0x06, 0x00, 0x07, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x80, 0x01, 0x80, 0x00, 0x00},

		//Char:]
		//Val:(0x005d)
		{0x00, 0x00, 0xfe, 0x00, 0x0e, 0x00, 0x0e, 0x00, 0x0e, 0x00, 0x0e, 0x00, 0x0e, 0x00, 0x0e, 0x00, 0x0e, 0x00, 0x0e, 0x00, 0x0e, 0x00, 0x0e, 0x00, 0x0e, 0x00, 0x0e, 0x00, 0x0e, 0x00, 0x0e, 0x00, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:^
		//Val:(0x005e)
		{0x00, 0x00, 0x1e, 0x00, 0x37, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:_
		//Val:(0x005f)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xc0},

		//Char:`
		//Val:(0x0060)
		{0x00, 0x00, 0x78, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:a
		//Val:(0x0061)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x00, 0x73, 0x80, 0x63, 0x80, 0x1f, 0x80, 0x73, 0x80, 0xe3, 0x80, 0xe3, 0xc0, 0x7f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:b
		//Val:(0x0062)
		{0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0xe0, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x7f, 0x00, 0x7b, 0x80, 0x71, 0xc0, 0x61, 0xc0, 0x61, 0xc0, 0x61, 0x80, 0x73, 0x80, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:c
		//Val:(0x0063)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x00, 0x73, 0x80, 0x63, 0x80, 0xe0, 0x00, 0xe0, 0x00, 0x61, 0x80, 0x73, 0x80, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:d
		//Val:(0x0064)
		{0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x07, 0x80, 0x03, 0x80, 0x03, 0x80, 0x03, 0x80, 0x03, 0x80, 0x3f, 0x80, 0x73, 0x80, 0x63, 0x80, 0xe3, 0x80, 0xe3, 0x80, 0x63, 0x80, 0x73, 0x80, 0x3f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:e
		//Val:(0x0065)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x00, 0x73, 0x80, 0x61, 0x80, 0x7f, 0xc0, 0x60, 0x00, 0x61, 0x80, 0x73, 0x80, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:f
		//Val:(0x0066)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x80, 0x1d, 0xc0, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x7f, 0x80, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:g
		//Val:(0x0067)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xc0, 0x73, 0x00, 0x63, 0x80, 0x73, 0x00, 0x3f, 0x00, 0x60, 0x00, 0x3f, 0x80, 0x61, 0x80, 0xe1, 0x80, 0x7f, 0x00, 0x00, 0x00},

		//Char:h
		//Val:(0x0068)
		{0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0xf0, 0x00, 0x70, 0x00, 0x70, 0x00, 0x70, 0x00, 0x70, 0x00, 0x7f, 0x00, 0x7b, 0x80, 0x73, 0x80, 0x73, 0x80, 0x73, 0x80, 0x73, 0x80, 0x73, 0x80, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:i
		//Val:(0x0069)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x7f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:j
		//Val:(0x006a)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x80, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x77, 0x00, 0x7e, 0x00, 0x00, 0x00},

		//Char:k
		//Val:(0x006b)
		{0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0xf0, 0x00, 0x70, 0x00, 0x70, 0x00, 0x70, 0x00, 0x70, 0x00, 0x77, 0xc0, 0x76, 0x00, 0x7c, 0x00, 0x7c, 0x00, 0x7e, 0x00, 0x77, 0x00, 0x73, 0x80, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:l
		//Val:(0x006c)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x7f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:m
		//Val:(0x006d)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xc0, 0xef, 0xc0, 0xed, 0xc0, 0xed, 0xc0, 0xed, 0xc0, 0xed, 0xc0, 0xed, 0xc0, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:n
		//Val:(0x006e)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x7b, 0x80, 0x73, 0x80, 0x73, 0x80, 0x73, 0x80, 0x73, 0x80, 0x73, 0x80, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:o
		//Val:(0x006f)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x00, 0x73, 0x80, 0x61, 0xc0, 0xe1, 0xc0, 0xe1, 0xc0, 0xe1, 0xc0, 0x73, 0x80, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:p
		//Val:(0x0070)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x7b, 0x80, 0x71, 0xc0, 0x71, 0xc0, 0x71, 0xc0, 0x71, 0xc0, 0x73, 0x80, 0x7f, 0x00, 0x70, 0x00, 0xf8, 0x00, 0x00, 0x00},

		//Char:q
		//Val:(0x0071)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x80, 0x73, 0x80, 0x63, 0x80, 0xe3, 0x80, 0xe3, 0x80, 0x63, 0x80, 0x73, 0x80, 0x3f, 0x80, 0x03, 0x80, 0x07, 0xc0, 0x00, 0x00},
	
		//Char:r
		//Val:(0x0072)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x80, 0x3d, 0xc0, 0x38, 0x00, 0x38, 0x00, 0x38, 0x00, 0x38, 0x00, 0x38, 0x00, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:s
		//Val:(0x0073)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x80, 0x73, 0x80, 0x71, 0x80, 0x3c, 0x00, 0x07, 0x80, 0x61, 0x80, 0x71, 0x80, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:t
		//Val:(0x0074)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0xff, 0x80, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x19, 0x80, 0x1d, 0x80, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:u
		//Val:(0x0075)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe7, 0x80, 0x63, 0x80, 0x63, 0x80, 0x63, 0x80, 0x63, 0x80, 0x63, 0x80, 0x73, 0x80, 0x3f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:v
		//Val:(0x0076)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfb, 0xc0, 0x71, 0x80, 0x33, 0x00, 0x3b, 0x00, 0x3e, 0x00, 0x1e, 0x00, 0x1e, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:w
		//Val:(0x0077)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xc0, 0xed, 0x80, 0x6d, 0x80, 0x7f, 0x80, 0x7f, 0x80, 0x7f, 0x00, 0x3f, 0x00, 0x37, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:x
		//Val:(0x0078)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x80, 0x77, 0x00, 0x3e, 0x00, 0x1c, 0x00, 0x1e, 0x00, 0x3e, 0x00, 0x73, 0x00, 0xf7, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:y
		//Val:(0x0079)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xc0, 0x73, 0x00, 0x33, 0x00, 0x3e, 0x00, 0x1e, 0x00, 0x1e, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x08, 0x00, 0x78, 0x00, 0x00, 0x00},

		//Char:z
		//Val:(0x007a)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x80, 0x67, 0x00, 0x66, 0x00, 0x0c, 0x00, 0x1c, 0x00, 0x39, 0x80, 0x73, 0x80, 0x7f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

		//Char:{
		//Val:(0x007b)
		{0x00, 0x00, 0x03, 0x80, 0x07, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x0c, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x07, 0x00, 0x03, 0x80, 0x00, 0x00},

		//Char:|
		//Val:(0x007c)
		{0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00},

		//Char:},
		//Val:(0x007d)
		{0x00, 0x00, 0x70, 0x00, 0x38, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x0c, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x38, 0x00, 0x70, 0x00, 0x00, 0x00},

		//Char:~
		//Val:(0x007e)
		{0x78, 0x00, 0xfc, 0xc0, 0xcf, 0x80, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
};
*/


