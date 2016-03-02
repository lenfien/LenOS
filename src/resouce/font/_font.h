


#ifndef __FONT__
#define __FONT__

/*
	Font��: 
		Font��̳�Screen��. ����Screen ���ȡ��������, ��x, y��, ����һ����.
*/

#define __CPlusPlus
#include "com.h"
#include "_SSD1289.h"
#include "color.h"
/*
����Font��ص���Ϣ
	��ͨ��Font, ���ݲ�ͬ���ַ�, ��ͬ������, ��ȡ�����ַ���size �� ������Ϣ
*/
class Font
{
/****************���Ͷ��岿��*************/
public:
	typedef enum
	{
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
	
	typedef enum
	{
		VARIABLE,			//�ַ���Ϊ�ɱ������
		FIXED     		//�ַ���Ϊ�̶��������
	}WidthType;
	
	//�ַ�����Ϣ
	typedef struct
	{
		WidthType widthType;   		//�ַ����Ƿ�Ϊ�ɱ���ַ���
		U32  			fontWidth;      //����ǿɱ�����壬����������
		U32 		 	fontHigh;				//�ַ��߶�
		FontAlign align;       		//���ݵĶ���ģʽ
		const unsigned char *pLibPixel;	
	}LibInfo;
	
	//������Ϣ����
	typedef struct
	{
	
		U32 fontWidth;
		U32 fontHigh;
		const unsigned char *pPixel;    		//ָ���ַ�������Ϣ��ָ��
		const	LibInfo* pLib;								//ָ������������ַ�����Ϣ��ָ��
	}FontInfo;

	typedef struct
	{
		U32 fontWidth;
		U32 fontHigh;
	}FontSize;
	
	typedef struct
	{
		S32 lineSpacing;   		//�о�
		S32 rowSpacing;    		//�о�
		Color::ColorValue fontColor;    	//������ɫ
		Color::ColorValue fontBackColor; //������ɫ
		FontType fontType;		//��������
	}FontFormat;						//�����ʽ

/***********************���ݶ��岿��*************************/
private:
	static const unsigned char ascii_8x16[][16];			//����ָ����Ϣ
	static const unsigned char ascii_10x19[][38];		//����ָ����Ϣ
	static const unsigned char ascii_YAHEI[][42];		//����ָ����Ϣ
												//���嵱ǰ������ʾ��ʽ

public:
	static FontFormat fontFormat;
	static const FontType ASCII_8x16 = Ascii_8x16;
	static const FontType ASCII_10x19 = Ascii_10x19;
	static const FontType ASCII_YAHEI = Ascii_YAHEI;

private:
	static const FontInfo& ascii_8x16_char_info(char c);
	static const FontInfo& ascii_10x19_char_info(char c);
	static const FontInfo& ascii_YAHEI_char_info(char c);
	
public:
	static const LibInfo libInfos[3];											//�洢�����������Ϣ
	static const FontInfo& 	font_info(const char c, const FontType& type);	//�����ַ�����������,���ض�Ӧ��������Ϣ
	static const LibInfo&		lib_info(const FontType &type);
	static U32 	 font_width(const unsigned char *pFont, U32 charAmount, U32 fontHigh);
	static U32 	 string_width(char *str, FontType fontType);
	static U32 	 char_width(char c, FontType fontType);
	static U32 	char_high(char c, FontType fontType);
	
public:
	//����
	static S32 set_line_spacing(S32);
	static S32 set_row_spacing(S32);
	static Color::ColorValue set_font_color(Color::ColorValue);
	static Color::ColorValue set_font_back_color(Color::ColorValue);
	static FontType set_font_type(FontType);
};

#endif
