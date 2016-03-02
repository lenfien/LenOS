

//#include "GUI.h"
//#include "SYS.h"

#include "GUI.h"
#include "button.h"
#include "textbox.h"

#include "MessageBox.h"

bool MessageBox::selected = false;
MessageBox::EnumResult MessageBox::result = MessageBox::ResultCancel;

MessageBox::EnumResult
MessageBox::show(String msg, String title, EnumShow sw)
{
	selected = false;
	
	Button *btnLeft = 0;
	Button *btnRight = 0;
	
	switch(sw)
	{
		case ShowOk:
			btnLeft = new Button("OK");
			btnLeft->set_release_handler(message_box_handler);
			break;
		case ShowOkCancel:
			btnLeft = new Button("OK");
			btnRight = new Button("Cancel");
			btnLeft->set_release_handler(message_box_handler);
			btnRight->set_release_handler(message_box_handler);
			break;
		case ShowYesNo:
			btnLeft = new Button("Yes");
			btnRight = new Button("No");
			btnLeft->set_release_handler(message_box_handler);
			btnRight->set_release_handler(message_box_handler);
			break;
		default:
			break;
	};
	
	TextBox* ptb = new TextBox(msg, 184, 50);
	Window* pw = new Window(title, 200, 100, Color::ColorRGB(0x05, 0x03, 00));
	
	//pw->closeEnable =false;
	pw->sliderEnable = false;
	
	pw->add_widget(ptb, Screen::Point(2, 1));
	pw->add_widget(btnLeft, Screen::Point(20, 55));
	
	if(btnRight)
		pw->add_widget(btnRight, Screen::Point(130, 55));
	
	pw->draw(Graphic::Point(50, 50));
	
 	while(selected == false)
 		System::system_wait();
// 	
 	pw->dispose();
// 	
	return result;
}

void MessageBox::message_box_handler(const  Graphic::Point p, Touchable *self, Touchable* father)			//ÊÍ·ÅÊÂ¼þ
{
	Button* pb = (Button*)self;
	
	if(pb->content == "Yes")
		result = ResultYes;
	else if(pb->content == "No")
		result = ResultNo;
	else if(pb->content == "Ok")
		result = ResultOK;
	else if(pb->content == "Cancel")
		result = ResultCancel;
	
	selected = true;
}
