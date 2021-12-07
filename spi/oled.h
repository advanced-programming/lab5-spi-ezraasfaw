/* 
 * File:   oled.h
 * Author: 1934089
 *
 * Created on December 7, 2021, 9:24 AM
 */

#ifndef OLED_H
#define	OLED_H

#ifdef	__cplusplus
extern "C" {
#endif
/**
    Section: Includes
*/
#include <sys/attribs.h>
#include <stdint.h>
#include <xc.h>
#include "spi.h"
#include "initBoard.h"
#include "console32.h"
#include <string.h>
/**
    Section: Macros
*/
#define 	DRAWLINE	0x21 
#define 	DRAWRECTANGLE	0x22
#define 	CLEAR	0x25

/**
    Section: Function Prototypes
*/
void oled_drw_line(int x1, int y1, int x2, int y2, int r, int g, int b) ;
void oled_clr(void);
void oled_drw_rect(int x1, int y1, int x2, int y2, int r, int g, int b) ;

#ifdef	__cplusplus
}
#endif
#endif