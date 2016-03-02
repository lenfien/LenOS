
#include <cstdlib>

#include "com.h"
#include "base.h"
#include "screen.h"
#include "ads7843.h"
#include "out.h"

#define ADS7483_IS_PRESSED()	(!GPIO_receive_pin(INT_PORT, INT_PIN))	//检测屏幕按下状态

#define ADS7483_PORT	GPIO_B      //ADS7483所使用的端口

#define SCK_PORT   	ADS7483_PORT    //时钟端口
#define SCK_PIN    	13              //时钟引脚

#define OUT_PORT  	ADS7483_PORT    //输出端口
#define OUT_PIN   	15              //输出引脚

#define IN_PORT  	ADS7483_PORT    //输入端口
#define IN_PIN   	14              //输入引脚

#define CS_PORT   	ADS7483_PORT    //片选端口
#define CS_PIN    	12              //片选引脚

#define INT_PORT	GPIO_G			//中断端口
#define INT_PIN		7           	//中断引脚

#define INT_LINE	7            	//中断线

//时钟高/低
#define SCK_HIGH   	GPIO_send_pin(SCK_PORT, SCK_PIN, 1)
#define SCK_LOW    	GPIO_send_pin(SCK_PORT, SCK_PIN, 0)

//输出高/低
#define OUT_HIGH	GPIO_send_pin(OUT_PORT, OUT_PIN, 1)
#define OUT_LOW		GPIO_send_pin(OUT_PORT, OUT_PIN, 0)

//读引脚数据
#define GET_IN		GPIO_receive_pin(IN_PORT, IN_PIN)

//片选定义
#define CS_HIGH		GPIO_send_pin(CS_PORT, CS_PIN, 1)
#define CS_LOW		GPIO_send_pin(CS_PORT, CS_PIN, 0)

//ADS7843 忙标志
#define ADS7483_BUSY_PORT	GPIO_G
#define ADS7483_BUSY_PIN	8
#define ADS7483_IS_BUSY()	GPIO_receive_pin(ADS7483_BUSY_PORT, ADS7483_BUSY_PIN)

#define CMD_X				0x90
#define CMD_Y				0xD0


/*
	此结构体很潇洒的给出了当前触摸屏的状态
	isTouched;		//触屏是否被暂时按下
	isHold;     	//触屏是否被一直按下
	point;			//当前被触摸的点
	可以在初始化了触摸屏之后,在任何
	地方访问这个结构体来获知触摸屏的状态
	此结构体在ADS7483_update_state被更新
	ADS7483_update_state在触摸屏被按下或释放时在外部中断7线事上被调用
*/
ADS7843::TouchState ADS7843::touchState;
bool	ADS7843::isInitialized = false;


//外部INT配置
void ADS7843::interrupt_init()
{
	RCC_enable_GPIO_x_clock(INT_PORT);					//提供时钟
	RCC_enable_AFIO_clock();							//使能AFIO时钟
	
	GPIO_set_input_PP(INT_PORT, INT_PIN);				//中断引脚上下拉输入
	AFIO_EXTI_set_entry_at_line_x(INT_LINE, INT_PORT);  //AFIO配置EXTI的输入路径
	EXTI_enable_falling_trigger_at_line_x(INT_LINE);	//外部信号下降沿激活中断
	EXTI_enable_rising_trigger_at_line_x(INT_LINE);		//外部信号上升沿激活中断
	EXTI_enable_interrupt_at_line_x(INT_LINE);			//使能中断
	
	//NVIC_enable_interrupt(_EXTI9_5_IRQn);						//NVIC中断允许
}

void ADS7843::sleep()
{
	EXTI_disable_interrupt_at_line_x(INT_LINE);
	NVIC_disable_interrupt(_EXTI9_5_IRQn);						//NVIC中断允许
}

void ADS7843::awake()
{
	//EXTI_enable_interrupt_at_line_x(INT_LINE);
	//NVIC_enable_interrupt(_EXTI9_5_IRQn);						//NVIC中断允许
}


//引脚初始化
void ADS7843::port_init()
{
	RCC_enable_GPIO_x_clock(ADS7483_PORT);  				//使能GPIO_B
	RCC_enable_GPIO_x_clock(ADS7483_BUSY_PORT);				//使能GPIO_G（BUSY）
	
	GPIO_set_output_50MHZ_PP(SCK_PORT, SCK_PIN); 			//将SCK引脚配置为上下拉输出
	GPIO_set_output_50MHZ_PP(OUT_PORT, OUT_PIN);			//将MOSI引脚配置复用上下拉输出
	GPIO_set_input_PP(IN_PORT, IN_PIN);						//将MISO配置为上下拉输入
	GPIO_set_output_50MHZ_PP(CS_PORT, CS_PIN); 				//将NSS配置为推挽输出
	
	GPIO_set_input_PP(ADS7483_BUSY_PORT, ADS7483_BUSY_PIN);	//将ADS7843的BUSY引脚设置为输入上下拉
}


void ADS7843::init()
{
	port_init(); 		//端口初始化
	interrupt_init();  	//中断初始化
	CS_HIGH;					//片选拉高
	SCK_LOW;					//时钟为低
	CS_LOW;             		//片选拉低
	
	isInitialized = true;
}

//给ADS7483发送命令
void ADS7843::send_command(U8 cmd)
{
	U8 index = 0;
	
	for(index = 0; index < 8; index ++)
	{
		(cmd & 0x80)?OUT_HIGH:OUT_LOW;	//MSB first, 根据数据位拉高或拉低OUT

		SCK_LOW;                        //拉低
		SCK_HIGH;						//拉高  产生一个上升沿
		cmd <<= 1;
	}
	SCK_LOW;							//发送完后再拉低时钟
}

//从ADS7483获得数据
U16	ADS7843::receive_data()
{
	U16 data = 0;
	U8 index;
	
	for(index = 0; index < 12; index ++)
	{
		data <<= 1;
		SCK_LOW;			//先低再高，模拟一个上升沿
		SCK_HIGH;
		data |= GET_IN;   	//在上升沿接收数据
	}
	SCK_LOW;
	
	return data;
}

/*
	获得坐标:
	此函数获得的坐标不对杂店进行处理
*/	

U8 ADS7843::get_exact_coordinate(Graphic::Point* point)
{	
	if(!ADS7483_IS_PRESSED())   //如果屏幕根本没按下则返回0
		return 0;

	//取4次,并取中间的2个的平均值 (这样做可以减少噪点)
	//读取X,Y
	send_command(CMD_X); 		 				//发送X命令
	SCK_HIGH;												//经过一个高地脉冲数据在下一个上升沿被送出
	SCK_LOW;
	point->x = receive_data();  		//接收X
	
	send_command(CMD_Y);        		//发送Y命令
	SCK_HIGH;
	SCK_LOW;
	point->y = receive_data();     	//接收Y
	
	return conversion(point);
}

/*
获取坐标:
	获得成功:返回N次采样中间两个的平均值(由SAMPLIE_TIME设置)
	获得失败:返回0
获得失败的原因有:
	触屏没有被按下
	SAMPLE_TIMES次连续采样距离过大(有噪点)
	采样点不在显示屏幕上

	只有在获得该函数的返回值为1时，才表明带进去的参数point获得了正确的坐标值
*/
#define SAMPLE_TIMES	4
U8 ADS7843::get_coordinate(Graphic::Point* point)
{
	static U16 xs[SAMPLE_TIMES + 1];
	static U16 ys[SAMPLE_TIMES + 1];
	U8 index;
	U8 _index;

	if(!ADS7483_IS_PRESSED())   //如果屏幕根本没按下则返回0
	{
		return 0;
	}
	
	//取4次,并取中间的2个的平均值 (这样做可以减少噪点)
	//读取X,Y
	for(index = 1; index <= SAMPLE_TIMES; index ++)
	{
		ADS7843::send_command(CMD_X); 		 	//发送X命令
		SCK_HIGH;
		SCK_LOW;
		xs[index] = receive_data();  	//接收X
		
		send_command(CMD_Y);        	//发送Y命令
		SCK_HIGH;
		SCK_LOW;
		ys[index] = receive_data();     //接收Y
	}
	
	//将获得的4个值从小到大重新排序
	for(index = 1; index <= SAMPLE_TIMES; index ++)
	{
		for(_index = index + 1; index <= SAMPLE_TIMES; index ++)
		{
			U16 temp;
			if(xs[index] > xs[_index])
			{
				temp = xs[index];
				xs[index] = xs[_index];
				xs[_index] = temp;
			}
			
			if(ys[index] > ys[_index])
			{
				temp = ys[index];
				ys[index] = ys[_index];
				ys[_index] = temp;
			}
		}
	}
	
	//去除杂点(x,y都满足过滤条件才可以继续进行)
	if(!point_filter(xs + 1, SAMPLE_TIMES) || !point_filter(ys + 1, SAMPLE_TIMES))
	{
		return 0;
	}
		
	
	//计算出最后的结果(求中间2个数的平均值)
	point->x = (xs[2] + xs[3])>>1;	//除以2
	point->y = (ys[2] + ys[3])>>1;	//除以2
	
	return conversion(point);
}


/*
	将ADS7483得到的AD值转换为以320*240为坐标的(x,y)值.
	如果AD值超出了屏幕的范围，point的内容将不变,并返回0
	否则将变为(x, y)，并返回1

	如果LCD的方向为240 * 320，此函数还会把 320 * 240的坐标变为240 * 320
*/

U8 ADS7843::conversion(Graphic::Point* point)
{
	//此操作是从触屏和LCD之间的偏移测试出来，340和240是偏移量
	int x = point->x - 340;    
	int y = point->y - 240;
	
	float x_temp;
	float y_temp;
	
	if(x <0 || y < 0)
		return 0;
	
	x_temp = (float)x/(3940-340);
	y_temp = (float)y/(3940-240);
	
	point->x = (int)(319.0 * x_temp);
	point->y = (int)(239.0 * y_temp);
	
	if(Screen::oritation() == Screen::ORITATION_240_320 )
	{
		int temp = point->x;
		point->x = point->y;
		point->y = 319 - temp;
	}
	
	return 1;
}


//过滤噪点函数，带入连续采样的点.
//该函数会在这些点不满足过滤条件时返回1否则返回0 

#define DELICACY 4					//灵敏度 越大越灵敏  越小越精确
int ADS7843::point_filter(U16 *start, U8 num)
{
	int maxSub = 0;
	int temp;
	
	while(num--)
	{
		if((temp = std::abs(*(start+1) - (*start))) > maxSub)
			maxSub = temp;
	}
	return maxSub < DELICACY;
}

//*********************************更新屏幕按下状态的函数*********************************//
/*
	此函数在触摸和释放屏幕时调用来更新当前的触摸状态
	更新的内容有：
		屏幕是否被按下
		按下是否连续
			是否连续的检测方式为:
				如果在N下按下之间没有抬起，则连续按下状态被激活
				N最好取大于10(经过测试，N如果太小，连续状态会混乱)
					导致原因:因为有噪点过滤功能，有时候的触摸行为(在噪点的容纳范围外)并没有被识别为触摸，
					而在N次内如果都是噪点，则此函数会错误的将这N此触摸行为判断为连续的触摸操作，导致连续
					状态被激活。
					这可能会影响到LCD_ADS7483_interrupt_draw_line的工作。
*/
#define N 10	//连续采样到n次按下，才激活连续模式哦
S8 ADS7843::update_state()
{
	static U8  preTouchState = 0;
	static int preTouchStateNum = 0;
	
	touchState.isTouch = ADS7483_IS_PRESSED();   	//获取本次的按下状态
	
	//如果本次和上次都没有按下， 直接返回
	if(preTouchState == 0 && touchState.isTouch == 0)
	{
		touchState.free = true;
		return -1;
	}
	else 
		touchState.free = false;
	
	//本次没有按下
	if(touchState.isTouch == 0)
	{
		preTouchStateNum = 0;
		touchState.isHold = 0;
	}
	else
	{
		bool b;
		do
		{
			b = get_coordinate(&touchState.touchPoint);
		}
		while(!b && ADS7483_IS_PRESSED());
		
		//Out::printl(0, 8, "%d %d %d" , touchState.touchPoint.x, touchState.touchPoint.y, i);
	}
	
	if(touchState.isTouch && preTouchState)
		preTouchStateNum ++;
	
	if(preTouchStateNum >= N)
		touchState.isHold = 1;
	
	preTouchState = touchState.isTouch;
	
	return  touchState.isTouch;              							//返回当前的按下状态
}


//**************************中断服务区**************************//
class Touch;
void ADS7843::interrupt_process()
{
	//如果想在触摸屏幕的时候发生一点事情，你可以把程序写在这里
	Out::printl(2, 3, "%3d %3d", touchState.touchPoint.x, touchState.touchPoint.y);
}

