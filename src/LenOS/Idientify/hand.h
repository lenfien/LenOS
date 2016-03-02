#ifndef __HAND__
#define __HAND__
#include "GUI.h"
#include "WGT.h"

class Hand
{
	private:
		static unsigned char handDatas[30000];
		
	public:
		Hand();
		
		Window* mainWindow;
		Button* btnDisposal;
		void draw_hand();
		void UI_init();
		void disposal();
};

#endif
