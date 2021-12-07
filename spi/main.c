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
 *  *                    11/30/2021     3.0      I finished the second part of the lab, and started working on the third part which consist of writing an application file that
 *                                               containt dynamic application.
 */

#include <xc.h>
#include "initBoard.h"
#include "oled_init.h"
#include "spi.h"
#include "Tick_core.h"
#include "oled.h"
#include "application.h"
#include "util.h"


#define TICKS_TEN_MS    TICKS_PER_SECOND/100
#define TICKS_TEN_US    TICKS_PER_SECOND/10
#define SS          _LATG9
#define DC          _LATB15







int dummy;
static int stamp;

int x1 = 1;
int y1 = 1;
int x2 = 80;
int y2 = 60;

int main(void) {
    
    /* When using the OLED, the following line MUST always be the first line 
     * to run when entering the main                                        */
    oled_init();  // Uncomment this line part 2 and part 3 only
    initIOs();
    spi_init(100000, 1, 1); //baud, cpol, cpha
    

//    oled_drw_line(1, 1, 80, 60,0,0,0xff);
//    delay_ms(1);   
//    oled_clr();
//    delay_ms(1);        
//    oled_drw_rect(1, 1, 80, 60,0xff,0,0);
    
//    /* Super loop*/
    while(1){
        /* Every 10 mS*/ 
        if(TickDiff(stamp) > TICKS_PER_SECOND ){  
//        SS=0; 
//        dummy = spi_ld_buffer(DRAWLINE); 
//        delay_10us(100);
//        SS=1;  
            
//            oled_drw_line(x1, y1, x2, y2,0,0,0xff);
//           // oled_clr();
//              
//            x1++;
//            y1++;
//            x2--;
//            y2--;
            //oled_drw_rect(1, 1, 80, 60,0xff,0,0);
  
            //rotating_line(x1,y1,x2,y2);
            //zoomin_rect(x1,y1,x2,y2);
           loading_box(x1,y1,x2,y2);
        stamp = TickGet();
       }
       // oled_clr();
    }
    return 0;
}


