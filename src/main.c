#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"


//�����ʵ�� -�⺯���汾
//STM32F4����ģ��-�⺯���汾
//�Ա����̣�http://mcudev.taobao.com

int main(void)
{ 
 
	delay_init(168);		  //��ʼ����ʱ����
	LED_Init();		        //��ʼ��LED�˿�
	
	while(1){
		D2_On();
		delay_ms(500);
		D2_Off();
		delay_ms(500);
	}
}



 



