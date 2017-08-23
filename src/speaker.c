
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
	
	GPIOA->MODER &= 0xfffffff3;		//PA1 input
	GPIOA->PUPDR |= 0x2 << 2;			//PA1 pull down
	
	NVIC_EnableIRQ(USART2_IRQn);
	NVIC_SetPriority(USART2_IRQn,(5<<1)+1);
	
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


int check_busy(void){
	int busy = 
		((GPIOA->IDR & GPIO_IDR_IDR_1) == GPIO_IDR_IDR_1) ? 1 : 0;
	return busy;
}

int check_stat(void){
	while(rx_vld == 0) ;	//wait while no respose
	return rx_data;
}

int wait_idle(void){
	int stat;
	do{
		stat = check_stat();
	}while (stat != 0x4f);
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


int speak_h3(int h3){		//单位mm
	int height = h3 /10;
	rx_vld = 0;
	int len;
	len = sizeof(content_h3);
	int h3_100 = height/100;
	int h3_10 = (height -100 * h3_100) / 10;
	int h3_1  = (height -100 * h3_100) % 10;
	content_h3[10] += h3_100;
	content_h3[12] += h3_10;
	content_h3[14] += h3_1;
	calcFrmLen(content_h3,len);
	calcXOR(content_h3,len);
	speaker_putstr(content_h3,len);
	content_h3[10] -= h3_100;
	content_h3[12] -= h3_10;
	content_h3[14] -= h3_1;
	return 0;
}


int speak_w2(int w2){		//单位100g
	int weight_l = w2 /10;
	int w2_s = w2 % 10;
	rx_vld = 0;
	int len;
	len = sizeof(content_h3);
	int w2_10 = (weight_l ) / 10;
	int w2_1  = (weight_l ) % 10;
	content_w2[10] += w2_10;
	content_w2[12] += w2_1;
	content_w2[16] += w2_s;
	calcFrmLen(content_w2,len);
	calcXOR(content_w2,len);
	speaker_putstr(content_w2,len);
	content_w2[10] -= w2_10;
	content_w2[12] -= w2_1;
	content_w2[16] -= w2_s;
	return 0;
}


int speak_h3w2(int h3,int w2){		//单位mm
	int height = h3 /10;
	int weight_l = w2 /10;
	int w2_s = w2 % 10;
	rx_vld = 0;
	int len;
	len = sizeof(content_h3w2);
	int h3_100 = height/100;
	int h3_10 = (height -100 * h3_100) / 10;
	int h3_1  = (height -100 * h3_100) % 10;
	int w2_10 = (weight_l ) / 10;
	int w2_1  = (weight_l ) % 10;
	content_h3w2[10] += h3_100;
	content_h3w2[12] += h3_10;
	content_h3w2[14] += h3_1;
	content_h3w2[26] += w2_10;
	content_h3w2[28] += w2_1;
	content_h3w2[32] += w2_s;
	calcFrmLen(content_h3w2,len);
	calcXOR(content_h3w2,len);
	speaker_putstr(content_h3w2,len);
	content_h3w2[10] -= h3_100;
	content_h3w2[12] -= h3_10;
	content_h3w2[14] -= h3_1;
	content_h3w2[26] -= w2_10;
	content_h3w2[28] -= w2_1;
	content_h3w2[32] -= w2_s;
	return 0;
}

