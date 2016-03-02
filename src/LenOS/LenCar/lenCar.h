#ifndef __LENCAR__
#define __LENCAR__

#include "GUI.h"
#include "WGT.h"

class LenCar
{
private:
	typedef enum
	{
		X, Y, Z
	}DIR;

	typedef enum
	{
		GYRO_X, GYRO_Y, GYRO_Z
	}GYRO_TYPE;

	typedef enum
	{
		ACCEL_X, ACCEL_Y, ACCEL_Z
	}ACCEL_TYPE;

	#define AX	(I2C_read_accel(ACCEL_X)/8192.0)
	#define AY	(I2C_read_accel(ACCEL_Y)/8192.0)
	#define AZ	(I2C_read_accel(ACCEL_Z)/8192.0)


	#define SCL_PORT 	GPIO_B
	#define SCL_PIN		PIN_6
	#define SDA_PORT	GPIO_B
	#define SDA_PIN		PIN_7

	#define SDA_IN		GPIO_set_input_FLT(SDA_PORT, SDA_PIN)					//����������Ϊ��������ģʽ
	#define SDA_OUT		GPIO_set_output_50MHZ_OD(SDA_PORT, SDA_PIN)		//����������Ϊ��©���ģʽ

	#define SCL_IN		GPIO_set_input_FLT(SCL_PORT, SCL_PIN)					//����������Ϊ��������ģʽ
	#define SCL_OUT		GPIO_set_output_50MHZ_OD(SCL_PORT, SCL_PIN)		//����������Ϊ��©���ģʽ


	#define SDA				GPIO_read_pin(SDA_PORT, SDA_PIN)	//��ȡSDA����
	#define SCL				GPIO_read_pin(SCL_PORT, SCL_PIN)	//��ȡSDA����

	#define SDA_1			GPIO_send_pin(SDA_PORT, SDA_PIN, 1)
	#define SDA_0			GPIO_send_pin(SDA_PORT, SDA_PIN, 0)
	#define SDA_(d)		GPIO_send_pin(SDA_PORT, SDA_PIN, d ? 1 : 0)

	#define SDA_RELEASE	SDA_1

	#define SCL_HIGH	GPIO_send_pin(SCL_PORT, SCL_PIN, 1)
	#define SCL_LOW		GPIO_send_pin(SCL_PORT, SCL_PIN, 0)

	#define D5US			delay_5us()

	#define ADD				(0xD0)
	#define ADD_READ	(0xD1)
	#define ADD_SEND	(0xD0)


	// ����MPU6050�ڲ���ַ
	//****************************************
	#define	SMPLRT_DIV		0x19	//�����ǲ����ʣ�����ֵ��0x07(125Hz)
	#define	CONFIG				0x1A	//��ͨ�˲�Ƶ�ʣ�����ֵ��0x06(5Hz)
	#define	GYRO_CONFIG		0x1B	//�������Լ켰������Χ������ֵ��0x18(���Լ죬2000deg/s)
	#define	ACCEL_CONFIG	0x1C	//���ټ��Լ졢������Χ����ͨ�˲�Ƶ�ʣ�����ֵ��0x01(���Լ죬2G��5Hz)
	#define	ACCEL_XOUT_H	0x3B
	#define	ACCEL_XOUT_L	0x3C
	#define	ACCEL_YOUT_H	0x3D
	#define	ACCEL_YOUT_L	0x3E
	#define	ACCEL_ZOUT_H	0x3F
	#define	ACCEL_ZOUT_L	0x40
	#define	TEMP_OUT_H		0x41
	#define	TEMP_OUT_L		0x42

	//
	#define	GYRO_XOUT_H		0x43
	#define	GYRO_XOUT_L		0x44	
	#define	GYRO_YOUT_H		0x45
	#define	GYRO_YOUT_L		0x46
	#define	GYRO_ZOUT_H		0x47
	#define	GYRO_ZOUT_L		0x48

	#define	PWR_MGMT_1		0x6B	//��Դ��������ֵ��0x00(��������)
	#define	WHO_AM_I			0x75	//IIC��ַ�Ĵ���(Ĭ����ֵ0x68��ֻ��)


	#define SPEED_DATA_ON			0xFC
	#define SPEED_DATA_OFF		0xFB

	#define SPEED_DATA_START	0xFA

	#define _max(a,b) ((a > b) ? a : b)
	#define _min(a,b) ((a > b) ? b : a)

	#define SYM(a) 	  ( a >= 0 ? 1 : -1)
	
	static void delay_5us();
	static void MPU6050_IO_init();
	static void I2C_start();
	
	//����ź�
	static void I2C_stop();
	static bool I2C_send_byte(char byte);
	static void I2C_NACK();
	static void I2C_ACK();
	//OK
	static U8 I2C_read_byte();
	static U8 I2C_read_address(U8 add);
	static bool I2C_send_address(U8 add, U8 byte);
	static S16 I2C_read_gyro(GYRO_TYPE gyro);
	static S16 I2C_read_accel(ACCEL_TYPE acce);
	static double get_angle(DIR d);
	static void MPU6050_init();
	static void MPU6050_test();
	static void UI_init();
	static void update_speed();
	
	static void Switch_release_handler(const Graphic::Point p, Touchable *self, Touchable *father);
	static void OnOff_release_handler(const Graphic::Point p, Touchable *self, Touchable *father);
	static void pad_left_event();
	static void pad_right_event();
	static void pad_up_event();
	static void pad_down_event();
	static void pad_idle_event();

	static Window* window;
	
	static Text* textState;
	static Text* textSpeed;
	static Text* textMode;
	
	static Button* btnSwtich;
	static Button* btnOnOFF;
	static ControlPad* padControl;
	static bool on;
	
	static bool bodyMode;
	static void send_speed(U8 l, U8 r);
	
public:
	static void init();
	static void go();
	static S8 	leftSpeed;
	static S8 	rightSpeed;
};

#endif
