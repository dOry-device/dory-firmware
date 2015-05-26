/*
 * doryUART.h
 *
 *  Created on: May 25, 2015
 *      Author: vagrant
 */

#ifndef DORYUART_H_
#define DORYUART_H_


/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/cfg/global.h>
#include <xdc/runtime/System.h>

#define CARRIAGE_RETURN 0x0A
#define LINE_FEED 0x0D

void doryUARTinit();
Void doryUARTfxn(UArg argument);
void doryUARTtask();


#endif /* DORYUART_H_ */
