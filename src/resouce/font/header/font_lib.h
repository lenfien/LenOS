
#ifndef __FONT_LIB
#define __FONT_LIB


#include "font_operation.h"
#include "com.h"

//定义了所以的字库的标识信息


/*
	ASCII 8*16
*/
extern const unsigned char ansi_font8x16[][16];       	//提供对库的底层的访问(调试用)
extern FONT_LIB ansi_font8x16_inf;                      //提供对库的修改权(调试用)

PFONT FONT_interface_ascii_8x16_get_font(char c);		//该库对外界提供的放访问其内部数据的通道
const FONT_LIB* FONT_interface_ascii_8x16_get_lib(void);	//提供对外界访问其库信息的通道(但外界不可改变之)


/*
	ASCII 10*19
*/
extern  const unsigned char ansi_font10x19[][38];

PFONT FONT_interface_ascii_10x19_get_font(char c);
const FONT_LIB* FONT_interface_ascii_10x19_get_lib(void);


//可变宽度字体，YAHEI

PFONT FONT_interface_ascii_YAHEI_get_font(char c);
const FONT_LIB* FONT_interface_ascii_YAHEI_get_lib(void);


#endif
