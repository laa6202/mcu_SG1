
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __US100_H
#define __US100_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"


/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

int us100_init(void );
int us100_measure(void);
int get_height(void);

#endif /* __US100_H */


