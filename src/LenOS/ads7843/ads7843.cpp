
#include <cstdlib>

#include "com.h"
#include "base.h"
#include "screen.h"
#include "ads7843.h"
#include "out.h"

#define ADS7483_IS_PRESSED()	(!GPIO_receive_pin(INT_PORT, INT_PIN))	//�����Ļ����״̬

#define ADS7483_PORT	GPIO_B      //ADS7483��ʹ�õĶ˿�

#define SCK_PORT   	ADS7483_PORT    //ʱ�Ӷ˿�
#define SCK_PIN    	13              //ʱ������

#define OUT_PORT  	ADS7483_PORT    //����˿�
#define OUT_PIN   	15              //�������

#define IN_PORT  	ADS7483_PORT    //����˿�
#define IN_PIN   	14              //��������

#define CS_PORT   	ADS7483_PORT    //Ƭѡ�˿�
#define CS_PIN    	12              //Ƭѡ����

#define INT_PORT	GPIO_G			//�ж϶˿�
#define INT_PIN		7           	//�ж�����

#define INT_LINE	7            	//�ж���

//ʱ�Ӹ�/��
#define SCK_HIGH   	GPIO_send_pin(SCK_PORT, SCK_PIN, 1)
#define SCK_LOW    	GPIO_send_pin(SCK_PORT, SCK_PIN, 0)

//�����/��
#define OUT_HIGH	GPIO_send_pin(OUT_PORT, OUT_PIN, 1)
#define OUT_LOW		GPIO_send_pin(OUT_PORT, OUT_PIN, 0)

//����������
#define GET_IN		GPIO_receive_pin(IN_PORT, IN_PIN)

//Ƭѡ����
#define CS_HIGH		GPIO_send_pin(CS_PORT, CS_PIN, 1)
#define CS_LOW		GPIO_send_pin(CS_PORT, CS_PIN, 0)

//ADS7843 æ��־
#define ADS7483_BUSY_PORT	GPIO_G
#define ADS7483_BUSY_PIN	8
#define ADS7483_IS_BUSY()	GPIO_receive_pin(ADS7483_BUSY_PORT, ADS7483_BUSY_PIN)

#define CMD_X				0x90
#define CMD_Y				0xD0


/*
	�˽ṹ��������ĸ����˵�ǰ��������״̬
	isTouched;		//�����Ƿ���ʱ����
	isHold;     	//�����Ƿ�һֱ����
	point;			//��ǰ�������ĵ�
	�����ڳ�ʼ���˴�����֮��,���κ�
	�ط���������ṹ������֪��������״̬
	�˽ṹ����ADS7483_update_state������
	ADS7483_update_state�ڴ����������»��ͷ�ʱ���ⲿ�ж�7�����ϱ�����
*/
ADS7843::TouchState ADS7843::touchState;
bool	ADS7843::isInitialized = false;


//�ⲿINT����
void ADS7843::interrupt_init()
{
	RCC_enable_GPIO_x_clock(INT_PORT);					//�ṩʱ��
	RCC_enable_AFIO_clock();							//ʹ��AFIOʱ��
	
	GPIO_set_input_PP(INT_PORT, INT_PIN);				//�ж���������������
	AFIO_EXTI_set_entry_at_line_x(INT_LINE, INT_PORT);  //AFIO����EXTI������·��
	EXTI_enable_falling_trigger_at_line_x(INT_LINE);	//�ⲿ�ź��½��ؼ����ж�
	EXTI_enable_rising_trigger_at_line_x(INT_LINE);		//�ⲿ�ź������ؼ����ж�
	EXTI_enable_interrupt_at_line_x(INT_LINE);			//ʹ���ж�
	
	//NVIC_enable_interrupt(_EXTI9_5_IRQn);						//NVIC�ж�����
}

void ADS7843::sleep()
{
	EXTI_disable_interrupt_at_line_x(INT_LINE);
	NVIC_disable_interrupt(_EXTI9_5_IRQn);						//NVIC�ж�����
}

void ADS7843::awake()
{
	//EXTI_enable_interrupt_at_line_x(INT_LINE);
	//NVIC_enable_interrupt(_EXTI9_5_IRQn);						//NVIC�ж�����
}


//���ų�ʼ��
void ADS7843::port_init()
{
	RCC_enable_GPIO_x_clock(ADS7483_PORT);  				//ʹ��GPIO_B
	RCC_enable_GPIO_x_clock(ADS7483_BUSY_PORT);				//ʹ��GPIO_G��BUSY��
	
	GPIO_set_output_50MHZ_PP(SCK_PORT, SCK_PIN); 			//��SCK��������Ϊ���������
	GPIO_set_output_50MHZ_PP(OUT_PORT, OUT_PIN);			//��MOSI�������ø������������
	GPIO_set_input_PP(IN_PORT, IN_PIN);						//��MISO����Ϊ����������
	GPIO_set_output_50MHZ_PP(CS_PORT, CS_PIN); 				//��NSS����Ϊ�������
	
	GPIO_set_input_PP(ADS7483_BUSY_PORT, ADS7483_BUSY_PIN);	//��ADS7843��BUSY��������Ϊ����������
}


void ADS7843::init()
{
	port_init(); 		//�˿ڳ�ʼ��
	interrupt_init();  	//�жϳ�ʼ��
	CS_HIGH;					//Ƭѡ����
	SCK_LOW;					//ʱ��Ϊ��
	CS_LOW;             		//Ƭѡ����
	
	isInitialized = true;
}

//��ADS7483��������
void ADS7843::send_command(U8 cmd)
{
	U8 index = 0;
	
	for(index = 0; index < 8; index ++)
	{
		(cmd & 0x80)?OUT_HIGH:OUT_LOW;	//MSB first, ��������λ���߻�����OUT

		SCK_LOW;                        //����
		SCK_HIGH;						//����  ����һ��������
		cmd <<= 1;
	}
	SCK_LOW;							//�������������ʱ��
}

//��ADS7483�������
U16	ADS7843::receive_data()
{
	U16 data = 0;
	U8 index;
	
	for(index = 0; index < 12; index ++)
	{
		data <<= 1;
		SCK_LOW;			//�ȵ��ٸߣ�ģ��һ��������
		SCK_HIGH;
		data |= GET_IN;   	//�������ؽ�������
	}
	SCK_LOW;
	
	return data;
}

/*
	�������:
	�˺�����õ����겻���ӵ���д���
*/	

U8 ADS7843::get_exact_coordinate(Graphic::Point* point)
{	
	if(!ADS7483_IS_PRESSED())   //�����Ļ����û�����򷵻�0
		return 0;

	//ȡ4��,��ȡ�м��2����ƽ��ֵ (���������Լ������)
	//��ȡX,Y
	send_command(CMD_X); 		 				//����X����
	SCK_HIGH;												//����һ���ߵ�������������һ�������ر��ͳ�
	SCK_LOW;
	point->x = receive_data();  		//����X
	
	send_command(CMD_Y);        		//����Y����
	SCK_HIGH;
	SCK_LOW;
	point->y = receive_data();     	//����Y
	
	return conversion(point);
}

/*
��ȡ����:
	��óɹ�:����N�β����м�������ƽ��ֵ(��SAMPLIE_TIME����)
	���ʧ��:����0
���ʧ�ܵ�ԭ����:
	����û�б�����
	SAMPLE_TIMES�����������������(�����)
	�����㲻����ʾ��Ļ��

	ֻ���ڻ�øú����ķ���ֵΪ1ʱ���ű�������ȥ�Ĳ���point�������ȷ������ֵ
*/
#define SAMPLE_TIMES	4
U8 ADS7843::get_coordinate(Graphic::Point* point)
{
	static U16 xs[SAMPLE_TIMES + 1];
	static U16 ys[SAMPLE_TIMES + 1];
	U8 index;
	U8 _index;

	if(!ADS7483_IS_PRESSED())   //�����Ļ����û�����򷵻�0
	{
		return 0;
	}
	
	//ȡ4��,��ȡ�м��2����ƽ��ֵ (���������Լ������)
	//��ȡX,Y
	for(index = 1; index <= SAMPLE_TIMES; index ++)
	{
		ADS7843::send_command(CMD_X); 		 	//����X����
		SCK_HIGH;
		SCK_LOW;
		xs[index] = receive_data();  	//����X
		
		send_command(CMD_Y);        	//����Y����
		SCK_HIGH;
		SCK_LOW;
		ys[index] = receive_data();     //����Y
	}
	
	//����õ�4��ֵ��С������������
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
	
	//ȥ���ӵ�(x,y��������������ſ��Լ�������)
	if(!point_filter(xs + 1, SAMPLE_TIMES) || !point_filter(ys + 1, SAMPLE_TIMES))
	{
		return 0;
	}
		
	
	//��������Ľ��(���м�2������ƽ��ֵ)
	point->x = (xs[2] + xs[3])>>1;	//����2
	point->y = (ys[2] + ys[3])>>1;	//����2
	
	return conversion(point);
}


/*
	��ADS7483�õ���ADֵת��Ϊ��320*240Ϊ�����(x,y)ֵ.
	���ADֵ��������Ļ�ķ�Χ��point�����ݽ�����,������0
	���򽫱�Ϊ(x, y)��������1

	���LCD�ķ���Ϊ240 * 320���˺�������� 320 * 240�������Ϊ240 * 320
*/

U8 ADS7843::conversion(Graphic::Point* point)
{
	//�˲����ǴӴ�����LCD֮���ƫ�Ʋ��Գ�����340��240��ƫ����
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


//������㺯�����������������ĵ�.
//�ú���������Щ�㲻�����������ʱ����1���򷵻�0 

#define DELICACY 4					//������ Խ��Խ����  ԽСԽ��ȷ
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

//*********************************������Ļ����״̬�ĺ���*********************************//
/*
	�˺����ڴ������ͷ���Ļʱ���������µ�ǰ�Ĵ���״̬
	���µ������У�
		��Ļ�Ƿ񱻰���
		�����Ƿ�����
			�Ƿ������ļ�ⷽʽΪ:
				�����N�°���֮��û��̧������������״̬������
				N���ȡ����10(�������ԣ�N���̫С������״̬�����)
					����ԭ��:��Ϊ�������˹��ܣ���ʱ��Ĵ�����Ϊ(���������ɷ�Χ��)��û�б�ʶ��Ϊ������
					����N�������������㣬��˺��������Ľ���N�˴�����Ϊ�ж�Ϊ�����Ĵ�����������������
					״̬�����
					����ܻ�Ӱ�쵽LCD_ADS7483_interrupt_draw_line�Ĺ�����
*/
#define N 10	//����������n�ΰ��£��ż�������ģʽŶ
S8 ADS7843::update_state()
{
	static U8  preTouchState = 0;
	static int preTouchStateNum = 0;
	
	touchState.isTouch = ADS7483_IS_PRESSED();   	//��ȡ���εİ���״̬
	
	//������κ��ϴζ�û�а��£� ֱ�ӷ���
	if(preTouchState == 0 && touchState.isTouch == 0)
	{
		touchState.free = true;
		return -1;
	}
	else 
		touchState.free = false;
	
	//����û�а���
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
	
	return  touchState.isTouch;              							//���ص�ǰ�İ���״̬
}


//**************************�жϷ�����**************************//
class Touch;
void ADS7843::interrupt_process()
{
	//������ڴ�����Ļ��ʱ����һ�����飬����԰ѳ���д������
	Out::printl(2, 3, "%3d %3d", touchState.touchPoint.x, touchState.touchPoint.y);
}

