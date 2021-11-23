/*
 *		main.c
 *			
 * Lab to control the position of a BDC motor
 * 
 * Author                Date        Version     Description
 * Ezra-Fikru Asfaw      11/23/2021     1.0      I created an SPI protocol which receive data from the shift register and place it inside the register buffer in file spi.c.
 */

#include <xc.h>
#include "initBoard.h"
#include "oled_init.h"
#include "spi.h"





int main(void) {
    /* When using the OLED, the following line MUST always be the first line 
     * to run when entering the main                                        */
    //oled_init();  // Uncomment this line part 2 and part 3 only
    spi_init(100000, 0, 0); //baud, cpol, cpha
    initIOs();

    /* Super loop*/
    while(1){
        
       /* Every 10 mS*/ 
        SS=1; 
        spi_ld_buffer(0xA3); 
        SS=0;  
    }
    return 0;
}


