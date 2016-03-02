


#ifndef __FONT__
#define __FONT__

#include "com.h"
#include "screen.h"
#include "color.h"
#include "graphic.h"

/*
����Font��ص���Ϣ
	��ͨ��Font, ���ݲ�ͬ���ַ�, ��ͬ������, ��ȡ�����ַ���size �� ������Ϣ
*/
/*
����������10x19�������yahei����, ��ע��ȥ��, Ȼ��Ϳ���ʹ��set_font_type����ϵͳ����
����Ϊ�������е�һ����
*/
#define  __ASCII_10x19
#define	 __ASCII_YAHEI


class Font
{
/************************���Ͷ��岿�ֿ�ʼ*****************/
public:
	//��������
	typedef enum {
		Ascii_8x16,
		Ascii_10x19,
		Ascii_YAHEI
	}FontType;
	
	//�������ݶ���
	typedef enum
	{
		ALIGN_LEFT,
		ALIGN_RIGH
	}FontAlign;
	
	//�Ƿ�Ϊ�ɱ�������
	typedef enum
	{
		VARIABLE,			//�ַ���Ϊ�ɱ������
		FIXED     		//�ַ���Ϊ�̶��������
	}WidthType;
	
	//�ַ�����Ϣ
	typedef struct
	{
		WidthType 					widthType;   		//�ַ����Ƿ�Ϊ�ɱ���ַ���
		U32  								fontWidth;      //����ǿɱ�����壬����������
		U32 		 						fontHigh;				//�ַ��߶�
		FontAlign 					align;       		//���ݵĶ���ģʽ
		const unsigned char *pLibPixel;			//ָ���ַ�������Ϣ
	}LibInfo;
	
	//������Ϣ����
	typedef struct
	{
		U32 								fontWidth;			//���ֿ��
		U32 								fontHigh;				//���ָ߶�
		const unsigned char *pPixel;    		//ָ���ַ�������Ϣ��ָ��
		const								LibInfo* pLib;	//ָ������������ַ�����Ϣ��ָ��
	}FontInfo;

	typedef struct
	{
		U32 fontWidth;
		U32 fontHigh;
	}FontSize;
	
	typedef struct
	{
		S32 							lineSpacing;   		//�о�
		S32 							rowSpacing;    		//�о�
		Color::ColorValue fontColor;    		//������ɫ
		Color::ColorValue fontBackColor; 		//������ɫ
		FontType 					fontType;					//��������
	}FontFormat;													//�����ʽ
/************************���Ͷ��岿�ֽ���********************/
	
	
/***********************���ݶ��岿�ֿ�ʼ*************************/
public:
	static FontFormat 					fontFormat;						//���嵱ǰ������ʾ��ʽ
	
private:	
	static const LibInfo 				libInfos[3];					//�洢�����������Ϣ
	static const unsigned char ascii_8x16[][16];			//����ָ����Ϣ
	static const unsigned char ascii_10x19[][38];			//����ָ����Ϣ
	static const unsigned char ascii_YAHEI[][42];			//����ָ����Ϣ

private:
	static const FontInfo& ascii_8x16_char_info(const char c);		//��ȡ8x16�ַ�����Ϣ
	static const FontInfo& ascii_10x19_char_info(const char c);		//��ȡ10x16�ַ�����Ϣ
	static const FontInfo& ascii_YAHEI_char_info(const char c);		//��ȡYAHEI�ɱ��ַ�����Ϣ
	
public:
	static const FontInfo& char_info(const char c);

/***********************���ݶ��岿�ֽ���*************************/


/***********************������ʼ************************************/
public:
	static const FontInfo& 	font_info(const char c, const FontType& type = fontFormat.fontType);	//�����ַ�����������,���ض�Ӧ��������Ϣ
	static const LibInfo&		lib_info(const FontType &type = fontFormat.fontType );

private:
	static U32 	 font_width(const unsigned char *pFont, U32 charAmount, U32 fontHigh);

public:	
	static U32 	 string_width(const char* str, FontType fontType = fontFormat.fontType);
	static U32 	 char_width(const char c, FontType fontType = fontFormat.fontType);
	static U32 	 char_high(const char c, FontType fontType = fontFormat.fontType);
	static U32 	 font_width() {return char_width('C');}
	static U32 	 font_high()	{return char_high('C'); }
/***********************��������************************************/	

/*************************������Ϣ���ÿ�ʼ****************************/
public:
	static S32 								set_line_spacing(S32);									//�����о�
	static S32 								set_row_spacing(S32);										//�����о���
	static Color::ColorValue 	set_font_color(Color::ColorValue);			//����������ɫ
	static Color::ColorValue 	set_font_back_color(Color::ColorValue);	//�������ֵı���ɫ
	static FontType 					set_font_type(FontType);								//������������

	static  Graphic::RectType window;

	static  Graphic::RectType set_window(Graphic::RectType r);				//�������ִ���
	static 	Graphic::RectType set_full_window();											//�������ִ���Ϊȫ��
/*************************������Ϣ���ý���****************************/
};

#endif
