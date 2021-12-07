#include <xc.h>
#include "initBoard.h"
#include "oled_init.h"
#include "spi.h"
#include "util.h"

#define 	DRAWLINE	0x21 
#define 	DRAWRECTANGLE	0x22
#define 	CLEAR	0x25

//#define TICKS_THOUSAND_US    TICKS_PER_SECOND/1000 //1000uS

void oled_drw_line(int x1, int y1, int x2, int y2, int r, int g, int b) {
    
        SS=0; 
        spi_ld_buffer(DRAWLINE); 
        spi_ld_buffer(x1);
        spi_ld_buffer(y1); 
        spi_ld_buffer(x2);
        spi_ld_buffer(y2);
        spi_ld_buffer(r); 
        spi_ld_buffer(g);
        spi_ld_buffer(b); 
        SS=1;  
    
}

void oled_clr(void){
        SS=0; 
        spi_ld_buffer(CLEAR); 
        spi_ld_buffer(0);
        spi_ld_buffer(0); 
        spi_ld_buffer(94);
        spi_ld_buffer(62);
        delay_ms(1);
        SS=1; 
} 

void oled_drw_rect(int x1, int y1, int x2, int y2,  int r, int g, int b) {
        SS=0; 
        spi_ld_buffer(DRAWRECTANGLE); 
        spi_ld_buffer(x1);
        spi_ld_buffer(y1); 
        spi_ld_buffer(x2);
        spi_ld_buffer(y2);
        spi_ld_buffer(r); 
        spi_ld_buffer(g); 
        spi_ld_buffer(b); 
        SS=1;  
}