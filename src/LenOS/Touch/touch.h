#ifndef __TOUCH__
#define __TOUCH__

#include "ads7843.h"
#include "graphic.h"

class Touch: private ADS7843 
{	
friend class System;
	
protected:
	Touch()	
	{
		if(ADS7843::isInitialized == false)
			ADS7843::init();
	}
	
public:
		using ADS7843::TouchState;
		using ADS7843::sleep;
		using ADS7843::awake;
		
		static const TouchState& touch_state();
		static const Graphic::Point& touch_point() { return touchState.touchPoint;}
};

#endif
