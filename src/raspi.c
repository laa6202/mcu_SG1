
/* Includes ------------------------------------------------------------------*/
#include "raspi.h"
#include "action.h"


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
u8 spi_recv[5];
u8 spi_send;
int cnt_data;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/


int raspi_init(){
	//using SPI2  PB12-NSS	PB13-SCK 	PB14-MISO		PB15-MOSI
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
	RCC->APB1ENR |= RCC_APB1ENR_SPI2EN;		//168MHz / 4 = 42MHz
	
	GPIOB->MODER |= 0xaa000000 ;	//PB12~15	ALT mode
	GPIOB->AFR[1] |= GPIO_AF_SPI2 << 16;		//PB12 AF5
	GPIOB->AFR[1] |= GPIO_AF_SPI2 << 20;		//PB13 AF5
	GPIOB->AFR[1] |= GPIO_AF_SPI2 << 24;		//PB14 AF5
	GPIOB->AFR[1] |= GPIO_AF_SPI2 << 28;		//PB15 AF5
	
	NVIC_EnableIRQ(SPI2_IRQn);
	NVIC_SetPriority(SPI2_IRQn,(4<<1) + 1);
	
	SPI2->CR1 |= SPI_CR1_BR_2;		//set baud rate = fAPB1 / 32
	SPI2->CR1 |= SPI_CR1_SSM;			//soft NSS
	SPI2->CR1 &= (~SPI_CR1_SSI);	//NSS = 0
	SPI2->CR1 &= (~SPI_CR1_MSTR);	//set slave mode
	SPI2->CR2 |= SPI_CR2_RXNEIE;
	SPI2->CR1 |= SPI_CR1_SPE;			//enable spi
	
	
	cnt_data = 0;
	return 0;
}


void SPI2_IRQHandler(void){
	if((SPI2-> SR & SPI_SR_RXNE) == SPI_SR_RXNE){
		spi_recv[cnt_data] = SPI2->DR;
		cnt_data ++;
		if(cnt_data == 4){
			action_raspi();
			SPI2->DR = spi_send;
		}
		else if(cnt_data == 5)
			cnt_data = 0;
		else ;
	}
}


u8 * get_spi_recv(){
	return spi_recv;
}

int set_spi_send(u8 data){
	spi_send = data;
	return 0;
}






