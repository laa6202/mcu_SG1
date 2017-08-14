#include "led.h" 
//////////////////////////////////////////////////////////////////////////////////	 
//STM32F4����ģ��-�⺯���汾
//�Ա����̣�http://mcudev.taobao.com							  
////////////////////////////////////////////////////////////////////////////////// 	 

//��ʼ��PA6��PA7Ϊ�����.��ʹ���������ڵ�ʱ��		    
//LED IO��ʼ��
void LED_Init(void)
{    	 
  GPIO_InitTypeDef  GPIO_InitStructure1;

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);//ʹ��GPIOAʱ��

  //GPIOF9,F10��ʼ������
  GPIO_InitStructure1.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;//LED0��LED1��ӦIO��
  GPIO_InitStructure1.GPIO_Mode = GPIO_Mode_OUT;//��ͨ���ģʽ
  GPIO_InitStructure1.GPIO_OType = GPIO_OType_PP;//�������
  GPIO_InitStructure1.GPIO_Speed = GPIO_Speed_2MHz;//2MHz
  GPIO_InitStructure1.GPIO_PuPd = GPIO_PuPd_UP;//GPIO_PuPd_UP;//����
  GPIO_Init(GPIOA, &GPIO_InitStructure1);//��ʼ��GPIO
	
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






