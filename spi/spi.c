#include <sys/attribs.h>
#include <stdint.h>
#include <xc.h>
#include "spi.h"
#include "initBoard.h"
#include "console32.h"
#include <string.h>


#define SYS_FREQ    80000000
#define SS          _LATD12
//#define DRAWRECTANGLE	  0x22


int rx;

void spi_init(int baud, int cpol, int cpha) {//SPI mode: Master, Communication mode 8 bits.
    
    SPI1BRG =(SYS_FREQ/2*baud)-1;
    SPI1CONbits.CKP=cpol; //cpol = CKP
    SPI1CONbits.SMP= cpha; //cpha = CPHA
    SPI1CONbits.MSTEN= 1; //master mode
    SPI1CONbits.MODE16= 0; //communication mode     0:8bits | 1:16bits
    
}


void spi_ld_buffer(SPI1BUF) {

//SPI1BUF = 0xFF;
while(!SPI1STATbits.SPIRBF){
rx = SPI1BUF;
}

}
