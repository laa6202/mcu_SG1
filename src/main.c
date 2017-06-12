#include "sys.h"
#include "delay.h"
#include "led.h"
#include "exti.h"


//跑马灯实验 -库函数版本
//STM32F4工程模板-库函数版本
//淘宝店铺：http://mcudev.taobao.com

int main(void)
{ 
 
	delay_init(168);		  //初始化延时函�
	EXTIX_Init();       //
	LED_Init();		        //初始化LED端口
	
	while(1){
		D2_On();
		delay_ms(500);
		D2_Off();
		delay_ms(500);
	}
}



 



