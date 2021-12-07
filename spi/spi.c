#include <sys/attribs.h>
#include <stdint.h>
#include <xc.h>
#include "spi.h"
#include "initBoard.h"
#include "console32.h"
#include <string.h>


#define SYS_FREQ    80000000
#define SS          _LATG9
//#define DRAWRECTANGLE	  0x22




void spi_init(int baud, int cpol, int cpha) {//SPI mode: Master, Communication mode 8 bits.
    
    SPI2BRG =(SYS_FREQ/2*baud)-1;
    SPI2CONbits.CKP=cpol; //cpol = CKP
    SPI2CONbits.CKE = ~cpha;   // SPI Clock Edge -CPHA =1
    SPI2CONbits.SMP= 0; //cpha = CPHA
    SPI2CONbits.SSEN = 0;  // SS pin is control by port function
    SPI2CONbits.MSTEN= 1; //master mode
    SPI2CONbits.MODE16= 0; //communication mode     0:8bits | 1:16bits
    SPI2CONbits.MODE32 = 0;   
    SPI2CONbits.ON = 1;       // enable SPI
    
    
    TRISGbits.TRISG9 =0;// SS
    TRISBbits.TRISB15 = 0; // D/C
}


int spi_ld_buffer(int spibuffer) {


SPI2BUF = spibuffer;
while(!SPI2STATbits.SPIRBF);
return SPI2BUF;


}
