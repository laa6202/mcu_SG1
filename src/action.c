


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


int action_raspi(){
	u8 * spi_recv;
	u8 spi_send;
	spi_recv = get_spi_recv();
	
	switch(spi_recv[0]){
		case 0x55: 	
			spi_send = 0xaa;
			set_spi_send(spi_send);
			break;
		case 0xaa: 	
			spi_send = 0x55;
			set_spi_send(spi_send);
			break;
		default : ;
	}
	
	return 0;
}

