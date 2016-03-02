
#ifndef __ADS7843__
#define __ADS7843__

#include "com.h"
#include "graphic.h"

class ADS7843
{
public:
	//触摸的当前状态
	typedef struct 
	{
		bool 	free;											//屏幕此时有无从左
		bool	isTouch;									//触屏是否被暂时按下
		bool	isHold;     							//手指一直保留在屏幕上的话会激活这个状态
		Graphic::Point touchPoint;			//当前被触摸的点
	}TouchState;
	
protected:
	static TouchState touchState;
	static bool	isInitialized;
	static void interrupt_init();			//外部INT配置
	static void port_init();					//引脚初始化
	
public:
	static void init();										//总初始化
	static S8 	update_state();
	
	static void sleep();									//停止触摸屏的中断
	static void awake();									//唤醒触摸屏的中断
private:
	static void send_command(U8 cmd);			//给ADS7843发送命令
	static U16	receive_data();						//从ADS7483获得数据
	static U8 	get_exact_coordinate(Graphic::Point* point);
	static U8 	get_coordinate(Graphic::Point* point);
	static U8 	conversion(Graphic::Point* point);
	static int 	point_filter(U16 *start, U8 num);
	
public:
	static void interrupt_process();
};

#endif
