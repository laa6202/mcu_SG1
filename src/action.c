


/* Includes ------------------------------------------------------------------*/
#include "action.h" 
#include "global.h"
#include "speaker.h"
#include "us100.h"
#include "raspi.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

int action_speak(){
	int height_mm = get_height_mm();
	int weight_100g = get_weight_100g();
	speak_h3w2(height_mm,weight_100g);
	wait_idle();
	return 0;
}


int action_height(){
	int height;
	us100_measure();
	height = get_height();
	set_height_mm(height);
	return 0;
}


int action_weight(){
	
	
	return 0;
}


int action_raspi(){
	u8 * spi_recv;
	u8 spi_send;
	spi_recv = get_spi_recv();
	
	switch(spi_recv[0]){
		case 0x55: 	
			spi_send = 0xaa;
			break;
		case 0xaa: 	
			spi_send = 0x55;
			break;
		case 0x57:
			spi_send = write_regs(spi_recv[1],spi_recv[2],spi_recv[3]);
			break;
		case 0x52:
			spi_send = read_regs(spi_recv[1],spi_recv[2]);
			break;
		default : ;
	}
	set_spi_send(spi_send);
	return 0;
}


