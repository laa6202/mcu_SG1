#include "gpio.h" 

void GPIO_PB_Init(void)
{    	 
  GPIO_InitTypeDef  GPIO_InitStructure1;

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);//ʹ��GPIOAʱ��

  //GPIOF9,F10��ʼ������
  GPIO_InitStructure1.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14;//LED0��LED1��ӦIO��
  GPIO_InitStructure1.GPIO_Mode = GPIO_Mode_OUT;//��ͨ���ģʽ
  GPIO_InitStructure1.GPIO_OType = GPIO_OType_PP;//�������
  GPIO_InitStructure1.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure1.GPIO_PuPd = GPIO_PuPd_UP;//GPIO_PuPd_UP;//����
  GPIO_Init(GPIOB, &GPIO_InitStructure1);//��ʼ��GPIO
	

}








