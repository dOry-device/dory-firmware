/*
 * doryI2C.cpp
 *
 *  Created on: Apr 20, 2015
 *      Author: traffael
 */
#include "Board.h"
#include "doryI2C.h"


void doryI2C_init() {
	const UInt i2cConfigIndexValueTest = 0;   //TODO: give a more meaningful index

	I2C_Params_init(&params);
	params.transferMode = I2C_MODE_BLOCKING;
	//TODO: change to callback
	params.transferCallbackFxn = NULL;

	Board_initI2C();

	handle = I2C_open(i2cConfigIndexValueTest, &params);

	if(!handle)
	{
		System_printf("I2C did not open");
		System_flush();
	}
	else
	{
		System_printf("I2C open");
				System_flush();
	}
}


void doryI2C_getTemperature() {
	i2cTransaction.slaveAddress=0x48;
	writeBuffer[0]=0; //read temperature command
	i2cTransaction.writeBuf = writeBuffer;
	i2cTransaction.writeCount = 1;
	i2cTransaction.readBuf = readBuffer;
	i2cTransaction.readCount=1;

	transferOK=I2C_transfer(handle, &i2cTransaction);
	if(!transferOK)
	{
		System_printf("I2C transaction failed");
		System_flush();
	}
	else
	{
		System_printf("I2C transaction ok");
		System_flush();
	}

}


