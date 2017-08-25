
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __RASPI_H
#define __RASPI_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"


/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
int raspi_init(void);
u8 * get_spi_recv(void);
int set_spi_send(u8 data);

#endif /* __RASPI_H */


