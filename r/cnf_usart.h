

#ifndef __Q_USART
#define __Q_USART

typedef enum 
{
	BAUD_9600, BAUD_115200
}USART_BAUD_RATE;

void USART1_init(USART_BAUD_RATE);

//Êä³ö×Ö·û
void USART1_put_char(char c);

//Êä³ö×Ö·û´®
int USART1_put_string(char *str);

int USART1_put_int(int i);

int USART1_put_float(float f);

int USART1_put_double(double d);

int USART1_put_long(long l);

int USART1_printf(char *format, ...);



void USART2_init(USART_BAUD_RATE);

//Êä³ö×Ö·û
void USART2_put_char(char c);

//Êä³ö×Ö·û´®
int USART2_put_string(char *str);

int USART2_put_int(int i);

int USART2_put_float(float f);

int USART2_put_double(double d);

int USART2_put_long(long l);

int USART2_printf(char *format, ...);
#endif
