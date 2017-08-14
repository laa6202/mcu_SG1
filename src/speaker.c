
/* Includes ------------------------------------------------------------------*/
#include "speaker.h"
#include "speaker_content.h"
#include "led.h"


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
u8 rx_data;
u8 rx_vld;
char a[21];

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

int init_speaker(void){
	//using uart2 PA2/PA3 to speaker control
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;		//	168MHz/4 = 42MHz
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;		//	168MHz
	
	NVIC_EnableIRQ(USART2_IRQn);
	
	GPIOA->MODER |= 0x2 << 4;  //PA2 -- UART1_TX
	GPIOA->MODER |= 0x2 << 6;  //PA3 -- UART1_RX
	GPIOA->AFR[0] |= 0x7 << 8;		//PA2-AF7
	GPIOA->AFR[0] |= 0x7 << 12;		//PA3-AF7
	
	//freq div = 42000000 / (16 * 9600) = 273.4375
	USART2->BRR |= 273 << 4;		
	USART2->BRR |= 0x7;

	USART2->CR1 |= USART_CR1_RXNEIE;
	
	USART2->CR1 |= USART_CR1_TE | USART_CR1_RE;
	USART2->CR1 |= USART_CR1_UE;
	
	rx_vld = 0;
	
	return 0;
}


int speaker_putch(char c){
	while((USART2->SR & USART_SR_TC)!= USART_SR_TC);	
	USART2->DR = c;
	
	return 0;
}

int speaker_putstr(char * str, u16 len){
	for(int i=0;i<len;i++)
		speaker_putch(*(str+i));
	return 0;
}	



int speak_content(int id){
	rx_vld = 0;
	int len;
	switch(id){
		case 1:
			len = sizeof(content1);
			calcFrmLen(content1,len);
			calcXOR(content1,len);
			speaker_putstr(content1,len);
			break;
		case 2:
			len = sizeof(content2);
			calcFrmLen(content2,len);
			calcXOR(content2,len);
			speaker_putstr(content2,len);
			break;
		case 3:
			len = sizeof(content3);
			calcFrmLen(content3,len);	
			calcXOR(content3,len);
			speaker_putstr(content3,len);
			break;
		default : break;	
	}
	return 0;
}


void USART2_IRQHandler(void){
	D2_On();
	if((USART2->SR & USART_SR_RXNE) == USART_SR_RXNE){
		rx_data = USART2->DR;	
		rx_vld = 1;
	}
	D2_Off();
}


int check_speak_stat(void){
	rx_vld = 0;
	speaker_putstr(cmd_check,5);
	while(rx_vld != 1) ;		//wait rx_vld = 1 by IRQ
	if( rx_data == 0x4F)		//FINISH and IDEL
		return 0;
	if( rx_data == 0x4A)		//INIT DONE and IDEL
		return 0;	
	if( rx_data == 0x4E)		//BUSY
		return 2;	
	if(rx_data == 0x41)			//RX cmd and busy
		return 1;
	if(rx_data == 0x45)			//FAILD to rx cmd
		return -1;
	return -2;
}


char calcXOR(char * content,int len){
	char xor_res = 0;
	for(int i=0;i<len-1;i++)		//not calc last char 
		xor_res ^=  content[i];
	content[len-1] = xor_res;
	return xor_res;
}


int calcFrmLen(char * content,int len){
	int frmLen = len - 3;
	content[1] = (char)((frmLen & 0xff00) >> 8);
	content[2] = (char)(frmLen & 0xff);
	return frmLen;
	
}

