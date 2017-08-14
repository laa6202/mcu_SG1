
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SPEAKER_CONTENT_H
#define __SPEAKER_CONTENT_H

/* Includes ------------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

char cmd_check[] = 	{0xFD,0x00,0x02,0x21,0xDE};//查询命令 FD 00 02 21 DE
char content1[] = 	{0xFD,0x00,0x0B,0x01,0x00,
										0xD3,0xEE,0xD2,0xF4,0xCC,0xEC,0xCF,0xC2,
										0xFF};	//0xC1

char content2[] = 	{0xFD,0x00,0xFF,0x01,0x00,
										0xC9,0xED,0xB8,0xDF,	//身高
										0xA3,0xB1,0xA3,0xB7,0xA3,0xB5,	//175
										0xC0,0xE5,0xC3,0xD7,0xA3,0xAC,	//厘米，
										0xcc,0xE5,0xD6,0xD8,		//体重
										0xA3,0xB9,0xA3,0xB2,		//92
										0xB9,0xAb,0xBD,0xEF,0xA1,0xA3,		//公斤。
										0xFF};	//XOR

char content3[] = 	{0xFD,0x00,0x17,0x01,0x00,
										0xC2,0xAC,0xCA,0xB1,0xD0,0xF2,0xA3,0xAC,
										0xB0,0xD6,0xB0,0xD6,0xBD,0xD0,0xC4,0xE3,
										0xBA,0xC8,0xCB,0xAE,0xC1,0xCB,
										0xFF};
char content4[200];


/* Exported macro ------------------------------------------------------------*/





/* Exported functions ------------------------------------------------------- */
#endif /* __SPEAKER_H */


