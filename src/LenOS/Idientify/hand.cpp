#include "hand.h"

extern Hand* ph;
void disposal_handler(Graphic::Point p, Touchable *here, Touchable* father)
{
	if(ph == 0)
		return;

	ph->disposal();
	ph->draw_hand();
}

void display_pixel_RGB(Graphic::Point p, Touchable *here, Touchable* father)
{
	Color::ColorType r = Color::value2RGB262K( Screen::get_point(p.x, p.y));
	Out::print(0,0, "%3d %3d %3d", r.r, r.g, r.b);
}

Hand::Hand()
{
		UI_init();
}

void Hand::draw_hand()
{
	this->mainWindow->idraw_bitmap(Graphic::Point(20, 20), 100, 100, handDatas);
}

void Hand::UI_init()
{
	this->mainWindow = new Window("Hand", 150, 150);
	btnDisposal = new Button("Dispo", 0,0, 0, 0, 0, disposal_handler);
	mainWindow->add_widget(btnDisposal, Graphic::Point(0, 0));
	mainWindow->set_hold_handler(display_pixel_RGB);
	mainWindow->draw(Graphic::Point(50, 50));
}

void Hand::disposal()
{
	mainWindow->iprintf(Graphic::Point(50, 1), "doing...");
	
	for(int l = 0; l < 100; l ++)
	{
		for(int r = 0; r < 300; r += 3 )
		{
			int v = l * 300 + r;
			
			int R = handDatas[v];
			int G = handDatas[v + 1];
			int B = handDatas[v + 2];
			
			if(R > 20 || G > 20 || B > 20)
			{
				*(handDatas + v)= 0xFF;
				*(handDatas + v + 1) = 0xFF;
				*(handDatas + v + 2) = 0xFF;
			}
			else
			{
				*(handDatas + v)= 0;
				*(handDatas + v + 1) = 0;
				*(handDatas + v + 2) = 0;
			}
		}
	}
	
	for(int l = 0; l < 100; l ++)
	{
		bool start = true;
		int startX;
		int endX;
		int countStart = 0;	//一行中有几个指头
		int newV;
		for(int r = 0; r < 300; r += 3 )
		{
			int v = l * 300 + r;
			
			int R = handDatas[v];
			int G = handDatas[v + 1];
			int B = handDatas[v + 2];
					
			*(handDatas + v)= 0;
			*(handDatas + v + 1) = 0;
			*(handDatas + v + 2) = 0;
	
			if(start)
			{
				if(R == 0 && G == 0 && B == 0)
				{
					start = false;
					startX = v;
				}
			}
			else
			{
				
				if(R != 0 && G != 0 && B != 0)
				{
					start = false;
					endX = v;
					countStart ++;
					
					if((endX - startX) < 50 && (endX - startX) > 3)
					{
						newV = (endX - startX)/2 + startX;
					
						*(handDatas + newV)= 0xFF;
						*(handDatas + newV + 1) = 0xFF;
						*(handDatas + newV + 2) = 0xFF;
					}
					
					start = true;
				}
			}
		}
	}
	
	mainWindow->iprintf(Graphic::Point(50, 1), "doing...OK");
}



