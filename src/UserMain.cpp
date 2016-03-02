#include "GUI.h"
#include "WGT.h"

#include "hand.h"

#include "GUI.h"
#include "WGT.h"
#include "lencar.h"

/*
	此函数只会在系统初始化完成后被执行一次
*/
void window_UI(Window* w)
{
	w->idraw_oval(100, 100, Graphic::Point(100, 100), 0);
	Color::ColorValue c= Font::set_font_back_color(w->backColor);
	w->iprintf(Graphic::Point(100, 100),_TEXT("lenfien"));
	Font::set_font_back_color(c);
}

void btn_lenCar_handler(Graphic::Point p, Touchable* self, Touchable* father)
{
	LenCar::init();
}

/***************************************************************************/
/***********************多进程**********************************************/
/***************************************************************************/
Window *pw1;
Window *pw2;
Window* pw;

void multi_process_test_handler()
{
		static int i = 0;
		static int prei = -1;
		static bool mode = false;
		
		if(prei != -1)
			pw1->idraw_circle(Graphic::Point(50, 50), i, pw2->backColor);
		
		if(!mode)
		{
			i+=2;
			if(i >= 30)
			{
				mode = true;
			}
		}
		else
		{
			i-=2;
			if(i <= 2)
			{
				mode = false;
			}
		}
		
		pw1->idraw_circle(Graphic::Point(50, 50), i, Color::RGB_RED);
		prei = i;
}

void multi_process_test_handler1()
{
		static int i = 0;
		static int prei = -1;
		static bool mode = false;
		
		if(prei != -1)
			pw2->idraw_rectangle(Graphic::Point(5, 5), i, i, pw2->backColor);
		
		if(!mode)
		{
			i++;
			if(i == 80)
			{
				mode = true;
			}
		}
		else
		{
			i--;
			if(i == 1)
			{
				mode = false;
			}
		}
		
		pw2->idraw_rectangle(Graphic::Point(5, 5), i, i, Color::RGB_RED);
		prei = i;
		
		//pw2->iprintf(Screen::Point(0, 0), "%d", i++);
}


void multi_process_test(const  Graphic::Point p, Touchable *self, Touchable *father )
{
	static bool accessed = false;
	if(accessed)
		return;
	
	accessed  = true;
	
	pw1 = new Window("Task1", 100, 100);
	pw2 = new Window("Task2", 100, 100);

	pw1->add_thread(multi_process_test_handler);
	pw2->add_thread(multi_process_test_handler1);
	
	pw1->draw(Graphic::Point(10, 10));
	pw2->draw(Graphic::Point(120, 10));
	
	pw1->run_process();
	pw2->run_process();
}

void multi_window_test(const  Graphic::Point p, Touchable *self, Touchable *father )
{
	static bool accessed = false;
	if(accessed)
		return;
	
	accessed  = true;
	
	int i = 0;
	
	while(i <= 3)
	{
		Window *pw1 = new Window(String::format("Win%d", i++), 100, 100);
		pw1->draw();
	}
}

Text *_pt;
void left_event()
{
	_pt->set_text("Left");
}

void right_event()
{
	_pt->set_text("Right");
}

void up_event()
{
	_pt->set_text("Up");
}

void down_event()
{
	_pt->set_text("Down");
}

/*
	下面是系统函数
*/

#include "lencar.h"
Hand* ph = 0;

	
ControlPad *cp;
void setup()
{
	TextBox *t = new TextBox("This is a TextBox Controler. You can drag the slider to check the remaining text.", 150, 60);
	_pt = new Text("--", 100, 20);
	
	Button *btn_lencar = new Button("LenCar");
	btn_lencar->set_release_handler(btn_lenCar_handler);
	
	Button *btn_mtask = new Button("Mtask", 50, 20, 0, 0, 0, multi_process_test);
	Button *btn_mulWin = new Button("MWin", 50, 20, 0, 0, 0, multi_window_test);
	
	cp = new ControlPad(50);
	
	cp->set_leftEvent(left_event);
	cp->set_rightEvent(right_event);
	cp->set_upEvent(up_event);
	cp->set_downEvent(down_event);
 	
	pw = new Window("Window", 200, 150, Color::RGB_RED);
	
	pw->set_UI(window_UI);
	pw->add_widget(t, Graphic::Point(10, 10));
	
	pw->add_widget(btn_mulWin, Graphic::Point(100, 80));
	pw->add_widget(btn_lencar, Graphic::Point(100, 100));
	pw->add_widget(btn_mtask, Graphic::Point(100, 120));
	pw->add_widget(cp, Graphic::Point(10, 100));
	pw->add_widget(_pt, Graphic::Point(10, 200));
	
	pw->draw(Graphic::Point(30, 30));
	
	//ph = new Hand();
	//ph->draw_hand();
	
	//OV7670::test();
	
	//LenCar::init();
}


/*
	此函数会被加入到系统进程中，循环执行
*/
void update(int i)
{
	//LenCar::go();
}

