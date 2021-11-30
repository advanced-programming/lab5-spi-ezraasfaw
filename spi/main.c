/*
 *		main.c
 *			
 * Lab to control the position of a BDC motor
 * 
 * Author                Date        Version     Description
 * Ezra-Fikru Asfaw      11/23/2021     1.0      I worked on the first part of the lab which was to created an SPI protocol which receive data from the shift register 
 *                                               and place it inside the register buffer in file spi.c.
 *                       11/30/2021     2.0      I finished the first part of the lab, and started working on the second part which consist of writing a library to be 
 *                                               able to communicate with the OLED display.
 */

#include <xc.h>
#include "initBoard.h"
#include "oled_init.h"
#include "spi.h"
#include "Tick_core.h"


#define TICKS_TEN_MS    TICKS_PER_SECOND/100
#define SS          _LATG9

int dummy;
extern static int stamp;

int main(void) {
    /* When using the OLED, the following line MUST always be the first line 
     * to run when entering the main                                        */
    //oled_init();  // Uncomment this line part 2 and part 3 only
    spi_init(100000, 1, 1); //baud, cpol, cpha
    initIOs();
    oled_init();
    /* Super loop*/
    while(1){
        /* Every 10 mS*/ 
        if(TickDiff(stamp) > TICKS_TEN_MS){  
        SS=0; 
        dummy = spi_ld_buffer(0xA3); 
        SS=1;  
        stamp = TickGet();
       }
    }
    return 0;
}


