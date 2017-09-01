


/* Includes ------------------------------------------------------------------*/
#include "global.h"
#include "key.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
u8 st_main;
u8 st_test;
int count;
int height_mm = 1720;
int wieght_100g = 950;
u8 debug[4];

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

int set_main(int state){
	st_main = (u8)state;
	if(state != S_IDLE)
		count ++;
	return 0;
}

int set_test(int state){
	st_test = state;
	return 0;
}

int get_main(void){
	return st_main;
}

int get_test(void){
	return st_test;
}

int get_height_mm(void){
	return height_mm;
}

int set_height_mm(int height){
	if(height > 9999)
		height_mm = 9999;
	else if(height <= 100)
		height_mm = 100;
	else 
		height_mm = height;
	return height_mm;
}

int get_weight_100g(void){
	return wieght_100g;
}

u32 get_key(int id){
	switch(id){
		case 0: return key0;
		case 1: return key1;
		case 2: return key2;
		default :;
	}
	return 0;
}



//------------------------------------------------
//------------ ARM operation ------------
u8 read_regs(u8 addr_h,u8 addr_l){
	u8 res;
	switch(addr_h){
		case 0x0:	 res = get_stat_regs(addr_l);break;
		case 0xE0: res = get_version_regs(addr_l);break;
		case 0xF0: res = get_debug_regs(addr_l);break;
		default : res = 0;
	}
	return res;
}


u8 write_regs(u8 addr_h,u8 addr_l, u8 data){
	u8 res;
	switch(addr_h){
		case 0x0 : res = set_stat_regs(addr_l,data);break;
		case 0x10: break;
		case 0xF0: res = set_debug_regs(addr_l,data);break;
		default : res = 0;
	}
	return res;
}


//---------- 00 ------------
u8 get_stat_regs(u8 addr_l){
	u8 res;
	switch (addr_l){
		case(0x8) : res = st_main;
		default :res = 0;
	}
	return res;
}
u8 set_stat_regs(u8 addr_l,u8 data){
	u8 res;
	switch (addr_l){
		case(0x8) : st_main = data;
		default :res = 0x4F;
	}	
	return res;
}

//u32 SN 	 = 0x00000002;

//--------- E0 ----------
u8 get_version_regs(u8 addr_l){
	u8 res;
	switch(addr_l){
		case 0x0: res = (SN & 0xff) ; break;
		case 0x1: res = (SN & 0xff00) >> 8 ; break;
		case 0x2: res = (SN & 0xff0000) >> 16 ; break;
		case 0x3: res = (SN & 0xff000000) >> 24 ; break;
		case 0x4: res = (key0 & 0xff) ; break;
		case 0x5: res = (key0 & 0xff00) >> 8 ; break;
		case 0x6: res = (key0 & 0xff0000) >> 16 ; break;
		case 0x7: res = (key0 & 0xff000000) >> 24 ; break;
		case 0x8: res = (key1 & 0xff) ; break;
		case 0x9: res = (key1 & 0xff00) >> 8 ; break;
		case 0xa: res = (key1 & 0xff0000) >> 16 ; break;
		case 0xb: res = (key1 & 0xff000000) >> 24 ; break;
		case 0xc: res = (key2 & 0xff) ; break;
		case 0xd: res = (key2 & 0xff00) >> 8 ; break;
		case 0xe: res = (key2 & 0xff0000) >> 16 ; break;
		case 0xf: res = (key2 & 0xff000000) >> 24 ; break;
		default : res = 0;
	}	
	return res;
}


//--------- F0 ----------
u8 get_debug_regs(u8 addr_l){
	u8 res;
	switch(addr_l){
		case 0x0: res = debug[0] ; break;
		case 0x1: res = debug[1] ; break;
		case 0x2: res = debug[2] ; break;
		case 0x3: res = debug[3] ; break;
		default : res = 0;
	}	
	return res;
}
u8 set_debug_regs(u8 addr_l,u8 data){
	switch(addr_l){
		case 0x0: debug[0] = data; break;
		case 0x1: debug[1] = data; break;
		case 0x2: debug[2] = data; break;
		case 0x3: debug[3] = data; break;
		default : ;
	}
	return 0x4F;
}


