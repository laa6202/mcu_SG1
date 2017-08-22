
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SPEAKER_H
#define __SPEAKER_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"


/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

int init_speaker(void );
int check_busy(void);
int check_stat(void);
int wait_idle(void);
int speaker_putch(char c);
int speaker_putstr(char * str, u16 len);
int speak_content(int id);
char calcXOR(char * content,int len);
int calcFrmLen(char * content,int len);
int speak_h3(int h3);
int speak_w2(int w2);
int speak_h3w2(int h3,int w2);
#endif /* __SPEAKER_H */


