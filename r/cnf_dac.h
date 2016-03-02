
#ifndef __CNF_DAC
#define __CND_DAC
/*
	mode1
	配置Channel1为非触发的最普通模式
	在此模式下，只要一往DHRx寄存器里写东西，就会立即转移到DORx中，并在3个APB1时钟后
	输出到引脚
	不使能DMA
	不开启噪音
	不开启三角波
	输出电压可调
*/
void DAC_cnf_mode1(void);


//在模式1下使能后，调用此函数,输出电压即可发生变化
void DAC_cnf_write_holding_data(U16 hd);



/*
	Channel1配置成软件触发模式下的普通模式
	12位右对齐模式
	带输出缓冲
	触发转换
	软件触发
	无波形产生
*/
void DAC_cnf_mode2(void);


/*
	Channel1配置为触发模式下的三角波发生器
	12位右对齐
	软件触发
	三角波行产生
*/
void DAC_cnf_mode3(void);


#endif
