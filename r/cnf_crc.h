

#ifndef	__Q_CRC
#define __Q_CRC

void CRC_init(void);

/*
	�˺������������ pData ����ʼ����pData + dataSize*4��֮������ݵ�CRC�롣
*/
U32 CRC_check_data(U32 *pData, U32 dataSize);

#endif
