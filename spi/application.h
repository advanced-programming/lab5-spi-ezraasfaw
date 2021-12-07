/* 
 * File:   application.h
 * Author: 1934089
 *
 * Created on December 7, 2021, 10:37 AM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

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


/**
    Section: Function Prototypes
*/
void rotating_line(int x1,int y1,int x2,int y2);
void zoomin_rect(int x1,int y1,int x2,int y2);
void loading_box(int x1,int y1,int x2,int y2);

#ifdef	__cplusplus
}
#endif
#endif
