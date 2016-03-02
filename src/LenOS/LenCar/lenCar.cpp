
#include "base.h"
#include "cnf.h"
#include "lencar.h"
#include "out.h"

#include <math.h>


void LenCar::delay_5us()
{
	int i = 30;
	while(i--);
}

void LenCar::MPU6050_IO_init()
{
		RCC_enable_GPIO_B_clock();
		SCL_OUT;
		SCL_LOW;
		SDA_OUT;
}

void LenCar::I2C_start()
{
	SDA_OUT;		//数据输出
	SDA_1;			//数据拉高, 释放
	SCL_HIGH;		//时钟有效
	D5US;				//延迟5us
	SDA_0;			//产生下降沿
	D5US;
	SCL_LOW;		//时钟下来
	D5US;
}

//输出信号
void LenCar::I2C_stop()
{
	SDA_OUT;
	SDA_0;
	SCL_HIGH;
	D5US;
	SDA_1;
	D5US;
	SCL_LOW;
	D5US;
}

bool LenCar::I2C_send_byte(char byte)
{
	int i = 8;
	bool ack;
	SDA_OUT;
	SCL_LOW;
	while(i--)
	{
		bool b = (byte & 0x80) ? 1 : 0;
		byte <<= 1;
		SDA_(b);
		SCL_HIGH;
		D5US;
		SCL_LOW;
		D5US;
	}

	//接收第9个ACK
	SDA_1;
	SDA_IN;			//输入模式,自动释放总线
	D5US;				
	SCL_HIGH;		
	D5US;				
	ack = SDA;	
	SCL_LOW;		
	D5US;				
	
	if(ack)
	//	CMD_printf("Send Error!");
	SDA_OUT;
	return !ack;
}


void LenCar::I2C_NACK()
{
	//发送NACK信号
	SDA_OUT;	//数据线输出
	SDA_1;		//输出高电平
	SCL_HIGH;	//时钟线拉高
	D5US;			//延迟
	SCL_LOW;	//时钟线拉低
	SDA_1;		//回复SDA高
}

void LenCar::I2C_ACK()
{
	//发送ACK信号
	SDA_OUT;	//数据线输出
	SDA_0;		//输出低电平
	SCL_HIGH;	//时钟线拉高
	D5US;			//延迟
	SCL_LOW;	//时钟线拉低
	SDA_1;		//回复SDA高
}

//OK
U8 LenCar::I2C_read_byte()
{
	U8 data = 0;
	int i = 8;
	SDA_1;
	SDA_IN;
	
	while(i--)
	{
		data <<= 1;
		SCL_HIGH;
		D5US;
		data |= SDA;
		SCL_LOW;
		D5US;
	}
	SDA_OUT;
	return data;
}

U8 LenCar::I2C_read_address(U8 add)
{
	U8 d;
	I2C_start();
	I2C_send_byte(0xD0);
	I2C_send_byte(add);
	delay(500);
	I2C_start();
	I2C_send_byte(0xD1);
	d = I2C_read_byte();
	I2C_NACK();
	I2C_stop();
	return d;
}

bool LenCar::I2C_send_address(U8 add, U8 byte)
{
	I2C_start();
	I2C_send_byte(ADD_SEND);
	I2C_send_byte(add);
	I2C_send_byte(byte);
	I2C_stop();
	
	return true;
}


S16 LenCar::I2C_read_gyro(LenCar::GYRO_TYPE gyro)
{
	S16 dh = I2C_read_address(gyro == GYRO_X ? GYRO_XOUT_H : ((gyro == GYRO_Y) ? GYRO_YOUT_H : GYRO_ZOUT_H));
	S16 dl = I2C_read_address(gyro == GYRO_X ? GYRO_XOUT_L : ((gyro == GYRO_Y) ? GYRO_YOUT_L : GYRO_ZOUT_L));
	return (dh << 8)|dl;
}


S16 LenCar::I2C_read_accel(LenCar::ACCEL_TYPE acce)
{
	S16 dh = I2C_read_address(acce == ACCEL_X ? ACCEL_XOUT_H : ((acce == ACCEL_Y) ? ACCEL_YOUT_H : ACCEL_ZOUT_H));
	S16 dl = I2C_read_address(acce == ACCEL_X ? ACCEL_XOUT_L : ((acce == ACCEL_Y) ? ACCEL_YOUT_L : ACCEL_ZOUT_L));
	return (dh << 8)|dl;
}




double LenCar::get_angle(DIR d)
{
	double r;
	switch(d)
	{
		case X:
			r = (90.0/0.98) * AX;
			break;
		case Y:
			r = (90.0/0.98) * AY;
			break;
		case Z:                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
			r = (90.0/0.98) * AZ;
			break;
	}                                                                                    
	return r;// * 180/3.14;
}

void LenCar::MPU6050_init()
{
	MPU6050_IO_init();
	
	I2C_send_address(PWR_MGMT_1, 0x00);		//解除休眠状态
	I2C_send_address(SMPLRT_DIV, 0x07);		//
	I2C_send_address(CONFIG, 0x06);			
	I2C_send_address(GYRO_CONFIG, 0x18);	
	I2C_send_address(ACCEL_CONFIG, 0x08);	
}



void LenCar::update_speed()
{
	double x = AX;
	double y = AY;
	
	double speed;
	double div;
		S8 l;
		S8 r;
	x = 1.5 * x;
	y = 1.5 * y;
	
	if(x > 1.0)
		x = 1.0;
	else if(x < -1.0)
		x = -1.0;
	
	if(y > 1.0)
		y = 1.0;
	else if(y < -1.0)
		y = - 1.0;
	
	//FONT_printf(3, 5, "x %6.2f", x);
	//FONT_printf(3, 6, "y %6.2f", y);
	
	speed = -100 * x;

	div = abs(100.0 * y);		//左右差值
	
	rightSpeed = leftSpeed = speed;
	
	if(abs(div) < 20)
		return;
	
	if(div < 0)
		div += 20;
	else
		div -= 20;
	
	
	
		l = SYM(leftSpeed);
	
		r = SYM(rightSpeed);
		
		leftSpeed = l * leftSpeed;
		rightSpeed = r * rightSpeed;
		
	
	if(y < 0)
	{
		leftSpeed -= div/2;
		rightSpeed += div/2;
	}
	else if(y > 0)
	{
		rightSpeed -= div/2;
		leftSpeed += div/2;
	}
	
	leftSpeed = l * leftSpeed;
		rightSpeed = r * rightSpeed;

	if(leftSpeed > 0 && leftSpeed > 100)
			leftSpeed = 100;
	
	if(rightSpeed > 0 && rightSpeed > 100)
			rightSpeed = 100;
	
	if(leftSpeed < 0 && leftSpeed < -100)
			leftSpeed = -100;
	
	if(rightSpeed < 0 && rightSpeed < -100)
			rightSpeed = -100;
}

#define POWER_ON	GPIO_send_pin(GPIO_G, 9, 1)
#define POWER_OFF	GPIO_send_pin(GPIO_G, 9, 0)

void LenCar::init()
{
	UI_init();
	
	RCC_enable_GPIO_x_clock(GPIO_G);
	GPIO_set_output_50MHZ_PP(GPIO_G, 9);
	POWER_ON;

	MPU6050_init();
	USART1_init(BAUD_9600);
}


void LenCar::go()
{
 	if(on)
 	{
		if(bodyMode)
			update_speed();
	}
	else
	{
		LenCar::leftSpeed = LenCar::rightSpeed = 0;
	}
	
	delay_us(1000);
	USART1_put_char(SPEED_DATA_START);
	delay_us(1000);
	USART1_put_char(LenCar::leftSpeed);
	delay_us(1000);
	USART1_put_char(LenCar::rightSpeed);

	String s = String::format("%d %d", leftSpeed, rightSpeed);
	textSpeed->set_text(s);
}

void LenCar::Switch_release_handler(const Graphic::Point p, Touchable *self, Touchable *father)
{
	bodyMode = !bodyMode;
	
	delay_us(5000);
	USART1_put_char(SPEED_DATA_START);
	delay_us(5000);
	USART1_put_char(LenCar::leftSpeed);
	delay_us(5000);
	USART1_put_char(LenCar::rightSpeed);

	delay_us(5000);
	USART1_put_char(SPEED_DATA_START);
	delay_us(5000);
	USART1_put_char(LenCar::leftSpeed);
	delay_us(5000);
	USART1_put_char(LenCar::rightSpeed);
	
	String str = bodyMode ? String("BodyMode") : String("Control");
	
	Color::ColorValue c = Font::set_font_back_color(window->backColor);
	
	window->iprintf(Graphic::Point(1, 1), str.c_str());
	
	Font::set_font_back_color(c);
}

void LenCar::OnOff_release_handler(const Graphic::Point p, Touchable *self, Touchable *father)
{
	on = !on;
	textState->set_text(on ? "ON" : "OFF");	
}

#include "GUI.h"
#include "WGT.h"

Window* 		LenCar::window = 0;
Text* 			LenCar::textState = 0;
Button*		 	LenCar::btnSwtich = 0;
Button*			LenCar::btnOnOFF = 0;
ControlPad* LenCar::padControl = 0;
Text*				LenCar::textSpeed = 0;
Text*				LenCar::textMode = 0;
bool				LenCar::bodyMode = true;
bool 				LenCar::on = true;
S8 					LenCar::leftSpeed = 0;
S8 					LenCar::rightSpeed = 0;

void LenCar::pad_left_event()
{
	leftSpeed = -80;
	rightSpeed = 80;
}

void LenCar::pad_right_event()
{
	leftSpeed = 80;
	rightSpeed = -80;
}

void LenCar::pad_up_event()
{
	leftSpeed = 80;
	rightSpeed = 80;
}

void LenCar::pad_down_event()
{
	leftSpeed = -80;
	rightSpeed = -80;
}

void LenCar::pad_idle_event()
{
	leftSpeed = 0;
	rightSpeed = 0;
}

void LenCar::UI_init()
{
	window = new Window("LenCar", 150, 150, Color::RGB_RED);
	window->sliderEnable = false;
	
	window->add_thread(go);
	
	btnSwtich = new Button("Switch", 50, 20, 0, 0,0 , Switch_release_handler);
	btnOnOFF = new Button("On/OFF", 50, 20, 0, 0, 0, OnOff_release_handler);
	
	textState = new Text("OFF", 100, 20);
	textSpeed = new Text("- -", 100, 20);
	
	textMode = new Text(bodyMode ? "Body" : "Control", 100, 20);
	
	padControl = new ControlPad(80);
	
	padControl->set_upEvent(pad_up_event);
	padControl->set_downEvent(pad_down_event);
	padControl->set_rightEvent(pad_right_event);
	padControl->set_leftEvent(pad_left_event);
	padControl->set_idleEvent(pad_idle_event);
	
 	window->add_widget(btnSwtich, Graphic::Point(3, 20));
 	window->add_widget(btnOnOFF, Graphic::Point(3, 40));
 	window->add_widget(textState, Graphic::Point(100, 110));
 	window->add_widget(textSpeed, Graphic::Point(0, 110));
	//window->add_widget(textMode, Graphic::Point(2, 2));
	
	window->add_widget(padControl, Graphic::Point(60, 30));
	
	window->draw();
	
	window->run_process();
}

