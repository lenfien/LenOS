


#ifndef __SSD1289__
#define __SSD1289__

#define __CPlusPlus

#include "com.h"
#include "base.h"
#include "color.h"
#include "datas.h"

class SSD1289
{
	#define REG_INDEX 	FSMC_NORPSRAM4_VALUE(0)  //ֻ��д
	#define REG_STATE		FSMC_NORPSRAM4_VALUE(0)	 //ֻ�ܶ�
	#define REG_VALUE		FSMC_NORPSRAM4_VALUE(2)	 //�ɶ���д

	#define LCD_REG			FSMC_NORPSRAM4_VALUE(0)		//��IR��д����
	#define LCD_RAM			FSMC_NORPSRAM4_VALUE(2)   //��RAM��д����

	#define SSD1289_CMD_X_POS
	#define SSD1289_CMD_Y_POS

	#define SSD1289_CMD_WINDOW_H_START_END	0x44  	//X�����
	#define SSD1289_CMD_WINDOW_V_START  ````0x45		//Y��ʼ
	#define SSD1289_CMD_WINDOW_V_END    		0x46    //Yĩβ
	
	friend int main();
public:
	//��Ļ����
	typedef enum	
	{
		ORITATION_320_240,     //320 * 240�����Ӷ��ӳ����Լ�����Ļ�����Ͻ�Ϊ0, 0��
		ORITATION_240_320      //240 * 320 (���Ӵ��ڳ����Լ�����Ļ�����Ͻ�Ϊ0, 0��
	}Oritation;			
	
	//SSD1289 ��ʼ���ṹ��
	typedef struct
	{
		Oritation 		oritation;          //��Ļ�ķ���
		Color::ColorQuality	colorQuality;              //��ɫ����
		U32						backgroundColor;    //������ɫ
		U8						backLight;					//������״̬(1:�� 0:�ر�)
	}InitialStruct;
	
protected:
	static InitialStruct state;
	static bool 	isInitialized;	//��ʶ�Ƿ񱻳�ʼ��
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
������һ����ɫ��Ҫȥ�ĵ�ַ
	��λ������Ч������Ļ�����й�
	��Ļ�����TBλ�й�
	TBλ����G0 - G319 
	Ҳ�������õ�X��Y�������ĵ�ַ����Ӧ��Gate����Ļ�����й�

	��������240 * 320�����
	��������320 * 240�����
	��������ͬ��Gate��ַ
*/
	inline static void 	set_GDDRAM_position(U16 x, U16 y)
	{
		if(state.oritation == ORITATION_240_320)  //�����240*320ģʽ
		{
			if(x > 240 || y > 320 )
			return;
			
			send_data(0x004e, x);	//����x����
			send_data(0x004f, y); //����y����
		}
		else											//�����320*240ģʽ
		{
			if(x > 320 || y > 240)
			return;
		
			send_data(0x004e, y);
			send_data(0x004f, x);
		}
	}
	
	/*
	��AC��ָGDDRAM��������ɫ
		����COLOR_262Kģʽ��
		����COLOR_65Kģʽ��
		262K��ɫ��Ҫ18λ:R,G,B��6λ
		65K��ɫ��Ҫ16λ:R5 G6 B5 
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
