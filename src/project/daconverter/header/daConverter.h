

#ifndef __DACONVERTER
#define __DACONVERTER

#include "button.h"
//≥ı ºªØ
void DAConverter_init(void);


void DAConverter_draw_UI(void);

void DAConverter_click_handler(BUTTON* pBtn);

void DAConverter_hold_handler(POINT* pPoint, BUTTON* pBtn);

void DAConverter_release_handler(BUTTON* pBtn);


#endif
