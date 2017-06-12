#include "gpio.h" 

void GPIO_PB_Init(void)
{    	 
  GPIO_InitTypeDef  GPIO_InitStructure1;

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);//使能GPIOA时钟

  //GPIOF9,F10初始化设置
  GPIO_InitStructure1.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14;//LED0和LED1对应IO口
  GPIO_InitStructure1.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
  GPIO_InitStructure1.GPIO_OType = GPIO_OType_PP;//推挽输出
  GPIO_InitStructure1.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure1.GPIO_PuPd = GPIO_PuPd_UP;//GPIO_PuPd_UP;//上拉
  GPIO_Init(GPIOB, &GPIO_InitStructure1);//初始化GPIO
	

}








