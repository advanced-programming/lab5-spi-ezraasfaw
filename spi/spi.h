/* 
 * File:   spi.h
 * Author: 1934089
 *
 * Created on November 23, 2021, 10:18 AM
 */


#ifndef SPI_H
#define	SPI_H

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
#define SYS_FREQ    80000000
#define SS    	_LATD12

/**
    Section: Function Prototypes
*/
void spi_init(int baud, int cpol, int cpha);
void spi_ld_buffer();

#ifdef	__cplusplus
}
#endif
#endif