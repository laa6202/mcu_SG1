
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __US100_H
#define __US100_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"


/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

int init_us100(void );
int us100_measure(void);
int get_h3(void);

#endif /* __US100_H */


