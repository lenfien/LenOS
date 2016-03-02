

#ifndef __LCD_SSD1289
#define __LCD_SSD1289

#include "com.h"

#include "ssd1289_type.h"

#define RGB_262K(R, G, B)	((R << 12) | (G << 6) | B)			
#define RGB_65K(R, G, B)    ((R << 11) | (G << 5) | B)

#define RGB(R, G, B)	((ScreenState.color==COLOR_262K)?RGB_262K(R, G, B):RGB_65K(R, G, B))

//�ڲ�ͬ��������Ļ�ĺ������ֵ
#define SCREEN_SIZE_X			((ScreenState.oritation == ORITATION_320_240) ? 319 : 239)
#define SCREEN_SIZE_Y			((ScreenState.oritation == ORITATION_320_240) ? 239 : 319)

#define SCREEN_WIDTH			SCREEN_SIZE_X
#define SCREEN_HIGH				SCREEN_SIZE_Y

#define SCREEN_SIZE_HALF_X      (SCREEN_SIZE_X/2)
#define SCREEN_SIZE_HALF_Y		(SCREEN_SIZE_Y/2)

//262K��ɫ����
#define RGB_262K_RED      RGB_262K(0x3F, 0, 0)
#define RGB_262K_GREEN    RGB_262K(0, 0x3F, 0)
#define RGB_262K_BLUE     RGB_262K(0, 0, 0x3F)
#define RGB_262K_BLACK    RGB_262K(0, 0, 0)
#define RGB_262K_WHITE    RGB_262K(0x3F, 0x3F, 0x3F)

//65K��ɫ����
#define RGB_65K_RED		  RGB_65K(0x1F, 0, 0) 
#define RGB_65K_GREEN     RGB_65K(0, 0x3F, 0) 
#define RGB_65K_BLUE      RGB_65K(0, 0, 0x1F) 
#define RGB_65K_BLACK     RGB_65K(0, 0, 0) 
#define RGB_65K_WHITE     RGB_65K(0x1F, 0x3F, 0x1F)

#define RGB_RED      	((ScreenState.color == COLOR_262K) ? RGB_262K_RED : RGB_65K_RED)
#define RGB_GREEN   	((ScreenState.color == COLOR_262K) ? RGB_262K_GREEN : RGB_65K_GREEN)
#define RGB_BLUE     	((ScreenState.color == COLOR_262K) ? RGB_262K_BLUE : RGB_65K_BLUE)
#define RGB_BLACK   	((ScreenState.color == COLOR_262K) ? RGB_262K_BLACK : RGB_65K_BLACK)
#define RGB_WHITE   	((ScreenState.color == COLOR_262K) ? RGB_262K_WHITE : RGB_65K_WHITE)

#define BACKGROUND_COLOR	ScreenState.backgroundColor

/*
	LCD״̬:
*/
extern SSD1289_INITIAL_STRUCT ScreenState;


//SSD1289�ڲ���ʼ�� ����240 * 320ģʽ���� 320 * 240ģʽ������
//oritation = 1 240 * 320
//oritation = 0 320 * 240
void	SSD1289_internal_init(SSD1289_INITIAL_STRUCT initialState);




//SSD1289��ʼ�� ����240 * 320ģʽ���� 320 * 240ģʽ������
//oritation = 1 240 * 320
//oritation = 0 320 * 240
void 	SSD1289_init(SSD1289_INITIAL_STRUCT initialState);




//��LCD��������
void 	SSD1289_send_data(U16 regIndex, U16 regValue);





//����GDDRAM��Ҫ���ʵĵ�ַ 240 * 320�����Ӵ��ڳ����Լ�����Ļ�����Ͻ�Ϊ0, 0��
void 	SSD1289_set_GDDRAM_position(U16 x, U16 y);




/*
��AC��ָGDDRAM��������ɫ
	����COLOR_262Kģʽ��
	����COLOR_65Kģʽ��
	262K��ɫ��Ҫ18λ:R,G,B��6λ
	65K��ɫ��Ҫ16λ:R5 G6 B5 
*/
void 	SSD1289_set_point(U32 RGB_color);

/*
���AC��ָGDDRAM������ɫ
	����COLOR_262Kģʽ��
	����COLOR_65Kģʽ��
*/
U32 	SSD1289_get_point(void);


//���ô���
void 	SSD1289_set_window(U16 hStart, U16 vStart, U16 hEnd, U16 vEnd);


//��color���LCD
void 	SSD1289_clear_screen(U32 color);

#define	LCD_clear_screen	SSD1289_clear_screen

/*
	��������:���ݲ�������Ļ�ϻ���һ��262K��ɫ��ͼƬ
	bitMapWidth��bitMapHigh����xStar,yStart�Ĳ�ͬ�в�ͬ�ķ�Χ����Ҫ�����÷�Χ������ͼƬ���ص���ʾ
*/
void 	SSD1289_draw_bitmap_262K(U16 bitMapWidth, U16 bitMapHigh, U16 xStart, U16 yStart, const unsigned char *pPic);

/*
//�ָ�ȫ������
//�ָ���Ĵ��ڽ�Ϊȫ��
//���һ��Ƶĵ�һ�㽫�ڴ��ڵ����Ͻ�λ��
*/
void 	SSD1289_set_full_window(void);


/*
	��ʾ����������뷽ʽ���е��ַ�
		�Ҷ�����: 	0011 1111 1111 1111 
		�������:   1111 1111 1111 1100
	fontWidthָ�������С:
		���������д�С������
	ָ����ʾλ��:
		xStart��yStart ��ΧӦ������Ӧ��Ļ����Ķ�Ӧ��x��y��
	ǰ��ɫ
		color
	����ɫ
		backColor
	ָ���ַ���ַ
*/
void 	SSD1289_draw_font_left_align(
							U16 fontWidth,   //�ַ����
							U16 fontHigh,    //�ַ��߶�
							U16 xStart,      //��ʼxλ��
							U16 yStart,      //��ʼyλ��
							U32	color,		 //��ɫ
							U32 backColor,   //����ɫ
							const unsigned char *pFont
							);
							
/*
	��ʾ�������Ҷ��뷽ʽ���е��ַ�
		�Ҷ�����: 	0011 1111 1111 1111 
		�������:   1111 1111 1111 1100
	fontWidthָ�������С:
		���������д�С������
	ָ����ʾλ��:
		xStart��yStart ��ΧӦ������Ӧ��Ļ����Ķ�Ӧ��x��y��
	ǰ��ɫ
		color
	����ɫ
		backColor
	ָ���ַ���ַ
*/
void 	SSD1289_draw_font_right_align(
							U16 fontWidth,   //�ַ����
							U16 fontHigh,    //�ַ��߶�
							U16 xStart,      //��ʼxλ��
							U16 yStart,      //��ʼyλ��
							U32	color,		 //��ɫ
							U32 backColor,   //����ɫ
							const unsigned char *pFont
							);
					

#endif
