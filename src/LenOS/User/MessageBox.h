#include "GUI.h"

#ifndef __MESSAGEBOX__
#define __MESSAGEBOX__

class MessageBox
{
public:
	enum EnumResult
	{
		ResultOK, ResultCancel, ResultYes, ResultNo
	};
	
	enum EnumShow
	{
		ShowOk, ShowOkCancel, ShowYesNo
	};
	
	static bool selected;
	static EnumResult result;
	
	/*
	*/
	static EnumResult show(String msg, String title = "", EnumShow sw = ShowOk);
	
private:
	static void message_box_handler(const  Graphic::Point p, Touchable *self, Touchable* father);			//ÊÍ·ÅÊÂ¼þ

};

#endif
