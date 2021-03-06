/*
 * doryI2C.cpp
 *
 *  Created on: Apr 20, 2015
 *      Author: traffael
 */
#include "Board.h"
#include "doryI2C.h"

void doryI2C_init() {
	I2C_Params_init(&params);
	params.transferMode = I2C_MODE_BLOCKING;

	i2c_handle = I2C_open(Board_I2C0, &params);
	if(!i2c_handle)
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

void doryI2C_checkBus()
{
	i2cTransaction.slaveAddress=0x40; //TODO 0x48
	writeBuffer[0]=0x00; //read temperature command
	i2cTransaction.writeBuf = writeBuffer;
	i2cTransaction.writeCount = 1;
	i2cTransaction.readBuf = readBuffer;
	i2cTransaction.readCount=1;
	transferOK=I2C_transfer(i2c_handle, &i2cTransaction);
	if(!transferOK)
	{
		System_printf("address 0x40 not available\n");
		System_flush();
	}
	else
	{
		System_printf("address 0x40 available\n");
		System_flush();
	}

	i2cTransaction.slaveAddress=0x48; //TODO 0x48

	transferOK=I2C_transfer(i2c_handle, &i2cTransaction);
	if(!transferOK)
	{
		System_printf("address 0x48 not available\n");
		System_flush();
	}
	else
	{
		System_printf("address 0x48 available\n");
		System_flush();
	}
}

void doryI2C_getTemperature() {
	i2cTransaction.slaveAddress=0x40; //TODO 0x48
	writeBuffer[0]=0x00; //read temperature command
	i2cTransaction.writeBuf = writeBuffer;
	i2cTransaction.writeCount = 1;
	i2cTransaction.readBuf = readBuffer;
	i2cTransaction.readCount=1;

	transferOK=I2C_transfer(i2c_handle, &i2cTransaction);
	if(!transferOK)
	{
		System_printf("I2C transaction failed");
		System_flush();
	}
	else
	{
		System_printf("I2C transaction ok %u  \n",readBuffer[0]);
		System_flush();
	}
}

void doryI2C_close()
{
	I2C_close(i2c_handle);
	System_printf("I2C closed\n");
	System_flush();
}
