
#ifndef __CORTEX_MSP
#define __CORTEX_MSP

#define ACK										0xd0

#define CMD_STOP							0x80	//数据停止
#define CMD_SUPERSONIC_START	0x81	//超声波数据开始
#define CMD_COMPASS_START			0x83	//指南针数据开始
#define CMD_STATE_START       0x84	//状态信息开始

#define DIR_UP		0x81	
#define DIR_DOWN	0x82
#define DIR_LEFT	0x83
#define DIR_RIGHT	0x84
#define DIR_STOP	0x80

#define PI 3.14159

#define FUNC_BARRIER_ON   0x91		//开启Barrier
#define FUNC_BARRIER_OFF  0x90		//关闭Barrier

#define CMD_GO_FREE_ON         	0xE0	//开启自由行走
#define CMD_GO_FREE_OFF        	0xE1	//关闭自由行走

#define CMD_GET_BARRIER_DATA   	0x92		//获取Barrier数据
#define CMD_GET_COMPASS_DATA   	0xb2		//获取Compass数据
#define CMD_GET_STATE						0xF0		
#define CMD_TURN_ON							0xF1		//开启小车
#define CMD_TURN_OFF						0xF2		//关闭小车

//主题颜色
#define PAD_BACK_COLOR		RGB(0xd, 0x23, 0x0)
#define PAD_FRONT_COLOR		RGB(0x1f, 0x30, 0x3)
#define PAD_FRAME_COLOR		RGB(0x50, 0x50, 0x50)
#define PAD_WORD_COLOR		PAD_FRONT_COLOR

//更新Pad状态
//主要用来更新Pad旁边的文字
void cortexMsp_update_pad_state(char *msg);

void cortexMsp_init(void);

extern S8 AckSignal ;  		//当MSP对第一个数据有回馈信号时，此值被置一
extern S8 AckSignalSure;	//当MSP响应完成命令时，第二个ACK
extern S8 FreeState ;			//是否小车处于自由状态
extern S8 OnLineState ;		//小车是否在线
extern S8 BarrierState;		//小车是否开启超声波
extern U8 FreeState_helper;		//Free状态下，存储将要发送的指令
typedef enum 
{
	_char = 1,
	_int = 2,
	_float = 3,
	_double = 4
}DATA_TYPE;

extern char dataBuffer[32];
extern int  dataBufferIndex;	
extern int 	intBuffer[12];
extern int 	intBufferIndex;
void cortexMsp_update_compass_state(void);
void cortexMsp_update_supersonic_state(void);
void cortexMsp_update_free_state(void);
bool cortexMsp_send_data(U8 data);

void 	COMPASS_draw_UI(void);
void 	COMPASS_update_UI(S16 angle);
void 	COMPASS_draw_indicator(S16 angle, S16 length, U32 color);
POINT COMPASS_angle2point(S16 angle, S16 x, S16 y, S16 lineLength);
void 	cortexMsp_update_connect_state(void);
void 	cortexMsp_update_state(void);

//更新BarrierSwitch按钮的文字提示信息
void cortexMsp_update_barrier_state(void);

bool cortexMsp_send_data(U8 data);
void cortexMsp_data_handler(U8 data);

DATA_TYPE cortexMsp_data_combine(U8 cmd, DATA_TYPE dataType, U8 dataSize, U32 dataAmount);

void 	cortexMsp_btnHandler_pad_press(BUTTON* pBtn);
void 	cortexMsp_btnHandler_pad_hold(POINT* p, BUTTON* pBtn);
void 	cortexMsp_btnHandler_pad_release(BUTTON* pBtn);

void 	cortexMsp_btnHandler_barrierSwitch_press(BUTTON* pBtn);
void	cortexMsp_btnHandler_barrierSwitch_hold(POINT* p, BUTTON* pBtn);
void	cortexMsp_btnHandler_barrierSwitch_release(BUTTON* pBtn);

void 	cortexMsp_btnHandler_getBarrier_press(BUTTON* pBtn);
void 	cortexMsp_btnHandler_getBarrier_hold(POINT *p, BUTTON* pBtn);
void 	cortexMsp_btnHandler_getBarrier_release(BUTTON* pBtn);

void 	cortexMsp_btnHandler_getAngle_press(BUTTON* pBtn);
void 	cortexMsp_btnHandler_getAngle_hold(POINT* p, BUTTON* pBtn);
void 	cortexMsp_btnHandler_getAngle_release(BUTTON* pBtn);

void 	cortexMsp_btnHandler_free_press(BUTTON* pBtn) ;
void 	cortexMsp_btnHandler_free_hold(POINT* p, BUTTON* pBtn);
void 	cortexMsp_btnHandler_free_release(BUTTON* pBtn);

void  cortexMsp_btnHandler_onOff_release(BUTTON* pBtn);
#endif
