#include <xc.h>
#include "initBoard.h"
#include "oled_init.h"
#include "spi.h"
#include "Tick_core.h"
#include "oled.h"
#include "util.h"

static int stamp;




void rotating_line(int x1,int y1,int x2,int y2){
        while(1){

            
if(TickDiff(stamp) > TICKS_PER_SECOND ){
            
           oled_drw_line(x1, y1, x2, y2,0,0,0xff);

              
                x1++;
                y1++;
                x2--;
                y2--;
                //oled_clr();
                //delay_ms(1);
                stamp = TickGet();
        }
    }
}



void zoomin_rect(int x1,int y1,int x2,int y2){
        while(1){

            
if(TickDiff(stamp) > TICKS_PER_SECOND ){
            
           oled_drw_rect(x1, y1, x2, y2,0,0xff,0);

              
                x1++;
                y1++;
                x2--;
                y2--;
                oled_clr();
                delay_ms(1);
                stamp = TickGet();
        
        }   



    }
}


void loading_box(int x1,int y1,int x2,int y2){
        while(1){

            
if(TickDiff(stamp) > TICKS_PER_SECOND ){
            
           oled_drw_rect(x1, y1, x2, y2,0xff,0,0);

              
                x1;
                y1--;
                x2;
                y2--;
                oled_clr();
                

        stamp = TickGet();
        }   

    }
}