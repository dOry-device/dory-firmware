/*
 * doryGPIO.h
 *
 *  Created on: Aug 27, 2015
 *      Author: vagrant
 */

#ifndef DORYGPIO_H_
#define DORYGPIO_H_

#include <ti/drivers/GPIO.h>

/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/cfg/global.h>
#include <xdc/runtime/System.h>

#include "Board.h"
#include <msp430.h>


void dory_GPIO_init();

void port1_isr();


void btn0_isr();
void btn1_isr();
void btn2_isr();
void btn3_isr();



#endif /* DORYGPIO_H_ */
