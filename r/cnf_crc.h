

#ifndef	__Q_CRC
#define __Q_CRC

void CRC_init(void);

/*
	此函数用来计算从 pData 处开始，到pData + dataSize*4处之间的数据的CRC码。
*/
U32 CRC_check_data(U32 *pData, U32 dataSize);

#endif
