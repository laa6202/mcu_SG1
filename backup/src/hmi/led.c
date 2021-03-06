#include "led.h" 
//////////////////////////////////////////////////////////////////////////////////	 
//STM32F4工程模板-库函数版本
//淘宝店铺：http://mcudev.taobao.com							  
////////////////////////////////////////////////////////////////////////////////// 	 

//初始化PA6和PA7为输出口.并使能这两个口的时钟		    
//LED IO初始化
void LED_Init(void)
{    	 
  GPIO_InitTypeDef  GPIO_InitStructure1;

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);//使能GPIOA时钟

  //GPIOF9,F10初始化设置
  GPIO_InitStructure1.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;//LED0和LED1对应IO口
  GPIO_InitStructure1.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
  GPIO_InitStructure1.GPIO_OType = GPIO_OType_PP;//推挽输出
  GPIO_InitStructure1.GPIO_Speed = GPIO_Speed_2MHz;//2MHz
  GPIO_InitStructure1.GPIO_PuPd = GPIO_PuPd_UP;//GPIO_PuPd_UP;//上拉
  GPIO_Init(GPIOA, &GPIO_InitStructure1);//初始化GPIO
	
	D2_Off();
	D3_Off();
}


void D2_On(void){
	GPIO_ResetBits(GPIOA,GPIO_Pin_6); 
}


void D2_Off(void){
	GPIO_SetBits(GPIOA,GPIO_Pin_6);	
}


void D3_On(void){
	GPIO_ResetBits(GPIOA,GPIO_Pin_7);
}


void D3_Off(void){
	GPIO_SetBits(GPIOA,GPIO_Pin_7);
}






