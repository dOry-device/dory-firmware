/*
 * doryI2C.h
 *
 *  Created on: Apr 20, 2015
 *      Author: traffael
 */

#ifndef DORYI2C_H_
#define DORYI2C_H_

#include <ti/drivers/I2C.h>
#include <xdc/runtime/System.h>

I2C_Handle	i2c_handle;
I2C_Params	params;
I2C_Transaction i2cTransaction;
UChar writeBuffer[1];
UChar readBuffer[1];
Bool transferOK;


void doryI2C_init();
void doryI2C_checkBus();

void doryI2C_getTemperature();

void doryI2C_close();



#endif /* DORYI2C_H_ */
