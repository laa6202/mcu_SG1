#ifndef __LED_H
#define __LED_H
#include "sys.h"

//////////////////////////////////////////////////////////////////////////////////	 
//STM32F4工程模板-库函数版本
//淘宝店铺：http://mcudev.taobao.com									  
////////////////////////////////////////////////////////////////////////////////// 	


//LED端口定义
#define LED0 PAout(6)	// D2
#define LED1 PAout(7)	// D3	 

void LED_Init(void);//初始化		 

void D2_On(void);
void D2_Off(void);
void D3_On(void);
void D3_Off(void);

#endif
