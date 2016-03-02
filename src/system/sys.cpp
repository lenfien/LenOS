

#include "com.h"
#include "base.h"
#include "cnf.h"

/*
	在进入main函数之前, 会执行该函数
	在这里初始化系统时钟
*/
extern "C" void SystemInit()
{
	RCC_init();      				//配置时钟为48MHZ,具体看函数内部定义
}


