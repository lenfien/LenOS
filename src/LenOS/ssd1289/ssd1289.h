


#ifndef __SSD1289__
#define __SSD1289__

#define __CPlusPlus

#include "com.h"
#include "base.h"
#include "color.h"
#include "datas.h"

class SSD1289
{
	#define REG_INDEX 	FSMC_NORPSRAM4_VALUE(0)  //只能写
	#define REG_STATE		FSMC_NORPSRAM4_VALUE(0)	 //只能读
	#define REG_VALUE		FSMC_NORPSRAM4_VALUE(2)	 //可读可写

	#define LCD_REG			FSMC_NORPSRAM4_VALUE(0)		//向IR处写数据
	#define LCD_RAM			FSMC_NORPSRAM4_VALUE(2)   //向RAM中写数据

	#define SSD1289_CMD_X_POS
	#define SSD1289_CMD_Y_POS

	#define SSD1289_CMD_WINDOW_H_START_END	0x44  	//X后半字
	#define SSD1289_CMD_WINDOW_V_START  ````0x45		//Y起始
	#define SSD1289_CMD_WINDOW_V_END    		0x46    //Y末尾
	
	friend int main();
public:
	//屏幕方向
	typedef enum	
	{
		ORITATION_320_240,     //320 * 240（板子端子朝向自己，屏幕的左上角为0, 0）
		ORITATION_240_320      //240 * 320 (板子串口朝向自己，屏幕的左上角为0, 0）
	}Oritation;			
	
	//SSD1289 初始化结构体
	typedef struct
	{
		Oritation 		oritation;          //屏幕的方向
		Color::ColorQuality	colorQuality;              //颜色质量
		U32						backgroundColor;    //背景颜色
		U8						backLight;					//背景灯状态(1:打开 0:关闭)
	}InitialStruct;
	
protected:
	static InitialStruct state;
	static bool 	isInitialized;	//标识是否被初始化
	static const unsigned ScreenSizeLong = 320;
	static const unsigned ScreenSizeShort = 240;

protected:
	static void 	init(InitialStruct initialState);
	static void 	set_window(U16 hStart, U16 vStart, U16 hEnd, U16 vEnd);
	static void 	set_full_window(void);

private:	
	static void 	pins_init();
	static void 	FSMC_init();
	static void		internal_init(InitialStruct initialState);
	inline static void  	send_data(U16 regIndex, U16 regValue)
	{
		REG_INDEX = regIndex;
		REG_VALUE = regValue;
	}
	
	inline static U16	 	read_register(U16 regIndex)
	{
		REG_INDEX = regIndex;
		return REG_VALUE;
	}
	
	static U32 get_data(U16 regIndex)
	{
		U32 r;
		REG_INDEX = regIndex;
		r = REG_VALUE;
		return r;
	}
	
protected:
	/*
设置下一个颜色将要去的地址
	该位产生的效果跟屏幕方向有关
	屏幕方向跟TB位有关
	TB位控制G0 - G319 
	也就是设置的X，Y所产生的地址所对应的Gate跟屏幕方向有关

	可配置在240 * 320情况下
	可配置在320 * 240情况下
	来产生不同的Gate地址
*/
	inline static void 	set_GDDRAM_position(U16 x, U16 y)
	{
		if(state.oritation == ORITATION_240_320)  //如果是240*320模式
		{
			if(x > 240 || y > 320 )
			return;
			
			send_data(0x004e, x);	//设置x坐标
			send_data(0x004f, y); //设置y坐标
		}
		else											//如果是320*240模式
		{
			if(x > 320 || y > 240)
			return;
		
			send_data(0x004e, y);
			send_data(0x004f, x);
		}
	}
	
	/*
	在AC所指GDDRAM处绘制颜色
		可在COLOR_262K模式下
		可在COLOR_65K模式下
		262K颜色需要18位:R,G,B各6位
		65K颜色需要16位:R5 G6 B5 
	*/
	inline static void set_point_262K(U32 RGB_color)
	{
		static U32 R;
		static U32 G;
		static U32 B;
		
		R = ((RGB_color)>>12)&0x3F;
		G = ((RGB_color)>>6)&0x3F;
		B = RGB_color&0x3F;
		
		send_data(0x22, (R<<10) | (G << 2));
		
		REG_VALUE = (B<<2);
	}
	
	inline static void 	set_point_65K(U32 RGB_color)
	{
		send_data(0x22, RGB_color);
	}
	
	static Color::ColorValue 		get_point_262K(U16 x, U16 y);
	static Color::ColorValue 		get_point_65K(U16 x, U16 y);
	
	static U32		get_points_262K(U16 xStart, U16 yStart, U16 xEnd, U16 yEnd, Datas<Color::ColorType>& );
	static U32		get_points_262K(U16 xStart, U16 yStart, U16 xEnd, U16 yEnd, unsigned char* );
	
	static U32		get_points_65K(U16 xStart, U16 yStart, U16 xEnd, U16 yEnd, Datas<Color::ColorType>&  );
	static U32		get_points_65K(U16 xStart, U16 yStart, U16 xEnd, U16 yEnd, unsigned char* );
	
	static void 	clear_screen_262K(U32 color);
	static void 	clear_screen_65K(U32 color);
	
public:
	static U16		width()	{return state.oritation == ORITATION_320_240 ? 320 : 240;}
	static U16		high()	{return state.oritation == ORITATION_320_240 ? 240 : 320;}
	static void 	turn_on_back_light()	{ GPIO_send_pin(GPIO_A, 1, 1); }
	static void 	turn_off_back_light()	{ GPIO_send_pin(GPIO_A, 1, 0); }
};


#endif
