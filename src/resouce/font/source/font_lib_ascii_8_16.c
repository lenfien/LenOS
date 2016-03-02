
#include "font_lib.h"
#include "font_operation.h"

const unsigned char ansi_font8x16[][16];

FONT_LIB ansi_font8x16_inf = 
{
		WIDTH_FIXED,	//�ȿ�����
		8,              //����Ϊ8
	   16,             //�߶�Ϊ16
		ALIGN_LEFT,     //���������ģʽ
};

FONT ansi_8x16_font = {&ansi_font8x16_inf};		//�ڴ˶����font�᷵�ظ��ܶ����get_font����������

//����һ����ĸ�����������ĸ����Ϣ��ָ��
//���c�����⣬��Ȼ��NULL


/*
	�˺�����8*16
*/
PFONT FONT_interface_ascii_8x16_get_font(char c)
{
	//������ڿ��ӷ�Χ�ڣ�����0
	if(c < 0x20 || c > 126)
	{
		ansi_8x16_font.pChar = 0;	
		ansi_8x16_font.fontHigh = 0;     //�ַ��߶�
		ansi_8x16_font.fontWidth = 0;		//ָ������ָ��
	}
	else
	{
		//��ʼ��font
		ansi_8x16_font.pChar = ansi_font8x16[c - 0x20];			//ָ������ָ��
	    ansi_8x16_font.fontHigh = ansi_font8x16_inf.fontHigh;     //�ַ��߶�
		ansi_8x16_font.fontWidth = ansi_font8x16_inf.fontWidth;   //�ַ�����
	}
	
	return &ansi_8x16_font;
}

//�˺�������
const FONT_LIB* FONT_interface_ascii_8x16_get_lib()
{
	return &ansi_font8x16_inf;
}


/*
	���ĵ����������еĿ���ASCII��: ��32 -  126  �����СΪ:8 * 16
*/
const unsigned char ansi_font8x16[][16] = 
{
	//char:SPACE  
	//value:0x0020 
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

	//char:! 
	//value:0x0021 
	{0x00, 0x00, 0x00, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00},

	//char:" 
	//value:0x0022 
	{0x00, 0x12, 0x36, 0x24, 0x48, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

	//char:# 
	//value:0x0023 
	{0x00, 0x00, 0x00, 0x24, 0x24, 0x24, 0xfe, 0x48, 0x48, 0x48, 0xfe, 0x48, 0x48, 0x48, 0x00, 0x00},

	//char:$ 
	//value:0x0024 
	{0x00, 0x00, 0x10, 0x38, 0x54, 0x54, 0x50, 0x30, 0x18, 0x14, 0x14, 0x54, 0x54, 0x38, 0x10, 0x10},

	//char:% 
	//value:0x0025 
	{0x00, 0x00, 0x00, 0x44, 0xa4, 0xa8, 0xa8, 0xa8, 0x54, 0x1a, 0x2a, 0x2a, 0x2a, 0x44, 0x00, 0x00},

	//char:& 
	//value:0x0026 
	{0x00, 0x00, 0x00, 0x30, 0x48, 0x48, 0x48, 0x50, 0x6e, 0xa4, 0x94, 0x88, 0x89, 0x76, 0x00, 0x00},

	//char:' 
	//value:0x0027 
	{0x00, 0x60, 0x60, 0x20, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

	//char:( 
	//value:0x0028 
	{0x00, 0x02, 0x04, 0x08, 0x08, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x04, 0x02, 0x00},

	//char:  
	//value:0x0029 
	{0x00, 0x40, 0x20, 0x10, 0x10, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x10, 0x10, 0x20, 0x40, 0x00},

	//char:* 
	//value:0x002a 
	{0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0xd6, 0x38, 0x38, 0xd6, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00},

	//char:+ 
	//value:0x002b 
	{0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x10, 0x10, 0xfe, 0x10, 0x10, 0x10, 0x10, 0x00, 0x00, 0x00},

	//char:, 
	//value:0x002c 
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x60, 0x20, 0xc0},

	//char:- 
	//value:0x002d 
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

	//char:. 
	//value:0x002e 
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x60, 0x00, 0x00},

	//char:/ 
	//value:0x002f 
	{0x00, 0x00, 0x01, 0x02, 0x02, 0x04, 0x04, 0x08, 0x08, 0x10, 0x10, 0x20, 0x20, 0x40, 0x40, 0x00},

	//char:0 
	//value:0x0030 
	{0x00, 0x00, 0x00, 0x18, 0x24, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x24, 0x18, 0x00, 0x00},

	//char:1 
	//value:0x0031 
	{0x00, 0x00, 0x00, 0x10, 0x70, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x7c, 0x00, 0x00},

	//char:2 
	//value:0x0032 
	{0x00, 0x00, 0x00, 0x3c, 0x42, 0x42, 0x42, 0x04, 0x04, 0x08, 0x10, 0x20, 0x42, 0x7e, 0x00, 0x00},

	//char:3 
	//value:0x0033 
	{0x00, 0x00, 0x00, 0x3c, 0x42, 0x42, 0x04, 0x18, 0x04, 0x02, 0x02, 0x42, 0x44, 0x38, 0x00, 0x00},

	//char:4 
	//value:0x0034 
	{0x00, 0x00, 0x00, 0x04, 0x0c, 0x14, 0x24, 0x24, 0x44, 0x44, 0x7e, 0x04, 0x04, 0x1e, 0x00, 0x00},

	//char:5 
	//value:0x0035 
	{0x00, 0x00, 0x00, 0x7e, 0x40, 0x40, 0x40, 0x58, 0x64, 0x02, 0x02, 0x42, 0x44, 0x38, 0x00, 0x00},

	//char:6 
	//value:0x0036 
	{0x00, 0x00, 0x00, 0x1c, 0x24, 0x40, 0x40, 0x58, 0x64, 0x42, 0x42, 0x42, 0x24, 0x18, 0x00, 0x00},

	//char:7 
	//value:0x0037 
	{0x00, 0x00, 0x00, 0x7e, 0x44, 0x44, 0x08, 0x08, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x00, 0x00},

	//char:8 
	//value:0x0038 
	{0x00, 0x00, 0x00, 0x3c, 0x42, 0x42, 0x42, 0x24, 0x18, 0x24, 0x42, 0x42, 0x42, 0x3c, 0x00, 0x00},

	//char:9 
	//value:0x0039 
	{0x00, 0x00, 0x00, 0x18, 0x24, 0x42, 0x42, 0x42, 0x26, 0x1a, 0x02, 0x02, 0x24, 0x38, 0x00, 0x00},

	//char:: 
	//value:0x003a 
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00},
 
	//char:; 
	//value:0x003b 
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x20},
 
	//char:< 
	//value:0x003c 
	{0x00, 0x00, 0x00, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x00, 0x00},
 
	//char:= 
	//value:0x003d 
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00},
 
	//char:> 
	//value:0x003e 
	{0x00, 0x00, 0x00, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x00, 0x00},
 
	//char:? 
	//value:0x003f 
	{0x00, 0x00, 0x00, 0x3c, 0x42, 0x42, 0x62, 0x02, 0x04, 0x08, 0x08, 0x00, 0x18, 0x18, 0x00, 0x00},
 
	//char:@ 
	//value:0x0040 
	{0x00, 0x00, 0x00, 0x38, 0x44, 0x5a, 0xaa, 0xaa, 0xaa, 0xaa, 0xb4, 0x42, 0x44, 0x38, 0x00, 0x00},
 
	//char:A 
	//value:0x0041 
	{0x00, 0x00, 0x00, 0x10, 0x10, 0x18, 0x28, 0x28, 0x24, 0x3c, 0x44, 0x42, 0x42, 0xe7, 0x00, 0x00},
 
	//char:B 
	//value:0x0042 
	{0x00, 0x00, 0x00, 0xf8, 0x44, 0x44, 0x44, 0x78, 0x44, 0x42, 0x42, 0x42, 0x44, 0xf8, 0x00, 0x00},
 
	//char:C 
	//value:0x0043 
	{0x00, 0x00, 0x00, 0x3e, 0x42, 0x42, 0x80, 0x80, 0x80, 0x80, 0x80, 0x42, 0x44, 0x38, 0x00, 0x00},
 
	//char:D 
	//value:0x0044 
	{0x00, 0x00, 0x00, 0xf8, 0x44, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x44, 0xf8, 0x00, 0x00},
 
	//char:E 
	//value:0x0045 
	{0x00, 0x00, 0x00, 0xfc, 0x42, 0x48, 0x48, 0x78, 0x48, 0x48, 0x40, 0x42, 0x42, 0xfc, 0x00, 0x00},
 
	//char:F 
	//value:0x0046 
	{0x00, 0x00, 0x00, 0xfc, 0x42, 0x48, 0x48, 0x78, 0x48, 0x48, 0x40, 0x40, 0x40, 0xe0, 0x00, 0x00},
 
	//char:G 
	//value:0x0047 
	{0x00, 0x00, 0x00, 0x3c, 0x44, 0x44, 0x80, 0x80, 0x80, 0x8e, 0x84, 0x44, 0x44, 0x38, 0x00, 0x00},
 
	//char:H 
	//value:0x0048 
	{0x00, 0x00, 0x00, 0xe7, 0x42, 0x42, 0x42, 0x42, 0x7e, 0x42, 0x42, 0x42, 0x42, 0xe7, 0x00, 0x00},
 
	//char:I 
	//value:0x0049 
	{0x00, 0x00, 0x00, 0x7c, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x7c, 0x00, 0x00},
 
	//char:J 
	//value:0x004a 
	{0x00, 0x00, 0x00, 0x3e, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x88, 0xf0},
 
	//char:K 
	//value:0x004b 
	{0x00, 0x00, 0x00, 0xee, 0x44, 0x48, 0x50, 0x70, 0x50, 0x48, 0x48, 0x44, 0x44, 0xee, 0x00, 0x00},
 
	//char:L 
	//value:0x004c 
	{0x00, 0x00, 0x00, 0xe0, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x42, 0xfe, 0x00, 0x00},
 
	//char:M 
	//value:0x004d 
	{0x00, 0x00, 0x00, 0xee, 0x6c, 0x6c, 0x6c, 0x6c, 0x54, 0x54, 0x54, 0x54, 0x54, 0xd6, 0x00, 0x00},
 
	//char:N 
	//value:0x004e 
	{0x00, 0x00, 0x00, 0xc7, 0x62, 0x62, 0x52, 0x52, 0x4a, 0x4a, 0x4a, 0x46, 0x46, 0xe2, 0x00, 0x00},
 
	//char:O 
	//value:0x004f 
	{0x00, 0x00, 0x00, 0x38, 0x44, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x44, 0x38, 0x00, 0x00},
 
	//char:P 
	//value:0x0050 
	{0x00, 0x00, 0x00, 0xfc, 0x42, 0x42, 0x42, 0x42, 0x7c, 0x40, 0x40, 0x40, 0x40, 0xe0, 0x00, 0x00},
 
	//char:Q 
	//value:0x0051 
	{0x00, 0x00, 0x00, 0x38, 0x44, 0x82, 0x82, 0x82, 0x82, 0x82, 0xb2, 0xca, 0x4c, 0x38, 0x06, 0x00},
 
	//char:R 
	//value:0x0052 
	{0x00, 0x00, 0x00, 0xfc, 0x42, 0x42, 0x42, 0x7c, 0x48, 0x48, 0x44, 0x44, 0x42, 0xe3, 0x00, 0x00},
 
	//char:S 
	//value:0x0053 
	{0x00, 0x00, 0x00, 0x3e, 0x42, 0x42, 0x40, 0x20, 0x18, 0x04, 0x02, 0x42, 0x42, 0x7c, 0x00, 0x00},
 
	//char:T 
	//value:0x0054 
	{0x00, 0x00, 0x00, 0xfe, 0x92, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x38, 0x00, 0x00},
 
	//char:U 
	//value:0x0055 
	{0x00, 0x00, 0x00, 0xe7, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3c, 0x00, 0x00},
 
	//char:V 
	//value:0x0056 
	{0x00, 0x00, 0x00, 0xe7, 0x42, 0x42, 0x44, 0x24, 0x24, 0x28, 0x28, 0x18, 0x10, 0x10, 0x00, 0x00},
 
	//char:W 
	//value:0x0057 
	{0x00, 0x00, 0x00, 0xd6, 0x92, 0x92, 0x92, 0x92, 0xaa, 0xaa, 0x6c, 0x44, 0x44, 0x44, 0x00, 0x00},
 
	//char:X 
	//value:0x0058 
	{0x00, 0x00, 0x00, 0xe7, 0x42, 0x24, 0x24, 0x18, 0x18, 0x18, 0x24, 0x24, 0x42, 0xe7, 0x00, 0x00},
 
	//char:Y 
	//value:0x0059 
	{0x00, 0x00, 0x00, 0xee, 0x44, 0x44, 0x28, 0x28, 0x10, 0x10, 0x10, 0x10, 0x10, 0x38, 0x00, 0x00},
 
	//char:Z 
	//value:0x005a 
	{0x00, 0x00, 0x00, 0x7e, 0x84, 0x04, 0x08, 0x08, 0x10, 0x20, 0x20, 0x42, 0x42, 0xfc, 0x00, 0x00},
 
	//char:[ 
	//value:0x005b 
	{0x00, 0x1e, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x1e, 0x00},
 
	//char:\
	//value:0x005c 
	{0x00, 0x00, 0x40, 0x40, 0x20, 0x20, 0x10, 0x10, 0x10, 0x08, 0x08, 0x04, 0x04, 0x04, 0x02, 0x02},
 
	//char:] 
	//value:0x005d 
	{0x00, 0x78, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x78, 0x00},
 
	//char:^ 
	//value:0x005e 
	{0x00, 0x1c, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
 
	//char:_ 
	//value:0x005f 
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff},
 
	//char:` 
	//value:0x0060 
	{0x00, 0x60, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
 
	//char:a 
	//value:0x0061 
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x42, 0x1e, 0x22, 0x42, 0x42, 0x3f, 0x00, 0x00},
 
	//char:b 
	//value:0x0062 
	{0x00, 0x00, 0x00, 0xc0, 0x40, 0x40, 0x40, 0x58, 0x64, 0x42, 0x42, 0x42, 0x64, 0x58, 0x00, 0x00},
 
	//char:c 
	//value:0x0063 
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x22, 0x40, 0x40, 0x40, 0x22, 0x1c, 0x00, 0x00},
 
	//char:d 
	//value:0x0064 
	{0x00, 0x00, 0x00, 0x06, 0x02, 0x02, 0x02, 0x1e, 0x22, 0x42, 0x42, 0x42, 0x26, 0x1b, 0x00, 0x00},
 
	//char:e 
	//value:0x0065 
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x42, 0x7e, 0x40, 0x40, 0x42, 0x3c, 0x00, 0x00},
 
	//char:f 
	//value:0x0066 
	{0x00, 0x00, 0x00, 0x0f, 0x11, 0x10, 0x10, 0x7e, 0x10, 0x10, 0x10, 0x10, 0x10, 0x7c, 0x00, 0x00},
 
	//char:g 
	//value:0x0067 
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x44, 0x44, 0x38, 0x40, 0x3c, 0x42, 0x42, 0x3c},
 
	//char:h 
	//value:0x0068 
	{0x00, 0x00, 0x00, 0xc0, 0x40, 0x40, 0x40, 0x5c, 0x62, 0x42, 0x42, 0x42, 0x42, 0xe7, 0x00, 0x00},
 
	//char:i 
	//value:0x0069 
	{0x00, 0x00, 0x00, 0x30, 0x30, 0x00, 0x00, 0x70, 0x10, 0x10, 0x10, 0x10, 0x10, 0x7c, 0x00, 0x00},
 
	//char:j 
	//value:0x006a 
	{0x00, 0x00, 0x00, 0x0c, 0x0c, 0x00, 0x00, 0x1c, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x44, 0x78},
 
	//char:k 
	//value:0x006b 
	{0x00, 0x00, 0x00, 0xc0, 0x40, 0x40, 0x40, 0x4e, 0x48, 0x50, 0x68, 0x48, 0x44, 0xee, 0x00, 0x00},
 
	//char:l 
	//value:0x006c 
	{0x00, 0x00, 0x00, 0x70, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x7c, 0x00, 0x00},
 
	//char:m 
	//value:0x006d 
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x49, 0x49, 0x49, 0x49, 0x49, 0xed, 0x00, 0x00},
 
	//char:n 
	//value:0x006e 
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xdc, 0x62, 0x42, 0x42, 0x42, 0x42, 0xe7, 0x00, 0x00},
 
	//char:o 
	//value:0x006f 
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3c, 0x00, 0x00},
 
	//char:p 
	//value:0x0070 
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd8, 0x64, 0x42, 0x42, 0x42, 0x44, 0x78, 0x40, 0xe0},
 
	//char:q 
	//value:0x0071 
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x22, 0x42, 0x42, 0x42, 0x22, 0x1e, 0x02, 0x07},
 
	//char:r 
	//value:0x0072 
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xee, 0x32, 0x20, 0x20, 0x20, 0x20, 0xf8, 0x00, 0x00},
 
	//char:s 
	//value:0x0073 
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x42, 0x40, 0x3c, 0x02, 0x42, 0x7c, 0x00, 0x00},

	//char:t 
	//value:0x0074 
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x7c, 0x10, 0x10, 0x10, 0x10, 0x10, 0x0c, 0x00, 0x00},

	//char:u 
	//value:0x0075 
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc6, 0x42, 0x42, 0x42, 0x42, 0x46, 0x3b, 0x00, 0x00},

	//char:v 
	//value:0x0076 
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe7, 0x42, 0x24, 0x24, 0x28, 0x10, 0x10, 0x00, 0x00},

	//char:w 
	//value:0x0077 
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd7, 0x92, 0x92, 0xaa, 0xaa, 0x44, 0x44, 0x00, 0x00},

	//char:x 
	//value:0x0078 
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6e, 0x24, 0x18, 0x18, 0x18, 0x24, 0x76, 0x00, 0x00},

	//char:y 
	//value:0x0079 
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe7, 0x42, 0x24, 0x24, 0x28, 0x18, 0x10, 0x10, 0xe0},

	//char:z 
	//value:0x007a 
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x44, 0x08, 0x10, 0x10, 0x22, 0x7e, 0x00, 0x00},

	//char:{ 
	//value:0x007b 
	{0x00, 0x03, 0x04, 0x04, 0x04, 0x04, 0x04, 0x08, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x03, 0x00},

	//char:| 
	//value:0x007c 
	{0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08},

	//char:}, 
	//value:0x007d 
	{0x00, 0x60, 0x10, 0x10, 0x10, 0x10, 0x10, 0x08, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x60, 0x00},

	//char:~ 
	//value:0x007e 
	{0x30, 0x4c, 0x43, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
};
