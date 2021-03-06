/*
 * Copyright (c) 2014, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ======== empty_min.c ========
 */
/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/cfg/global.h>
#include <xdc/runtime/System.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>

/* TI-RTOS Header files */
#include <ti/drivers/GPIO.h>

// #include <ti/drivers/SDSPI.h>
// #include <ti/drivers/SPI.h>
#include <ti/drivers/UART.h>
// #include <ti/drivers/Watchdog.h>
// #include <ti/drivers/WiFi.h>

/* Board Header file */
#include "Board.h"
#include "doryI2C.h"
#include "doryUART.h"
#include "doryGPIO.h"



/*
 *  ======== heartBeatFxn ========
 *  Toggle the Board_LED0. The Task_sleep is determined by arg0 which
 *  is configured for the heartBeat Task instance.
 */
Void heartBeatFxn(UArg arg0, UArg arg1)
{
	doryI2C_init();

    while(1) {
    	//doryI2C_getTemperature();
    	doryI2C_checkBus();
    	Task_sleep((unsigned int)arg0);
	}

    //doryI2C_close();
}

Void greenLedFxn(UArg arg0, UArg arg1)
{
    while (1) {
        Task_sleep((unsigned int)200);
        GPIO_toggle(Board_LED1);
	}
}


/*
 *  ======== echoFxn ========
 *  Task for this function is created statically. See the project's .cfg file.
 */
Void echoFxn(UArg arg0, UArg arg1)
{
    char input;
    UART_Handle uart;
    //UART_Handle uartGPS;
    UART_Params uartParams;
    const char echoPrompt[] = "\fEchoing characters:\r\n";


    /* Create a UART with data processing off. */
    UART_Params_init(&uartParams);
    uartParams.writeDataMode = UART_DATA_BINARY;
    uartParams.readDataMode = UART_DATA_BINARY;
    uartParams.readReturnMode = UART_RETURN_FULL;
    uartParams.readEcho = UART_ECHO_OFF;
    uartParams.baudRate = 9600;


    /* Loop forever echoing
    uart = UART_open(Board_UART0, &uartParams);
	if (uart == NULL) {
			System_abort("Error opening the UART");
	}

	/*uartGPS = UART_open(Board_UART_GPS, &uartParams);
	if (uart == NULL) {
		System_abort("Error opening the UART_GPS");
	}

    while (1) {

    	UART_write(uart, echoPrompt, sizeof(echoPrompt));
    	Task_sleep((unsigned int)200);

    	UART_read(uart, &input, 1);
    	UART_write(uart, &input,1);
    	//UART_close(uart);

/*
    	while(!doryUARTtask())
    	{
    		Task_sleep((unsigned int)200);
    	}

    }*/
}

/*
 *  ======== gpsTaskFxn ========
 *  Task for this function is created statically. See the project's .cfg file.
 */
Void gpsTaskFxn(UArg arg0, UArg arg1)
{


    UART_Handle uartGPS;
    UART_Params uartParamsGPS;

    /* Create a UART with data processing off. */
    UART_Params_init(&uartParamsGPS);
    uartParamsGPS.writeDataMode = UART_DATA_BINARY;
    uartParamsGPS.readDataMode = UART_DATA_BINARY;
    uartParamsGPS.readReturnMode = UART_RETURN_FULL;
    uartParamsGPS.readEcho = UART_ECHO_OFF;
    uartParamsGPS.baudRate = 9600;

	uartGPS = UART_open(Board_UART_GPS, &uartParamsGPS);
	if (uartGPS == NULL) {
		System_abort("Error opening the UART_GPS");
	}
	doryUARTinit();

	int iuart;

    while (1) {

    /*	while(!doryUARTtask())
    	{
    		Task_sleep((unsigned int)50);
    	}
     */

    	Task_sleep((unsigned int)2000);

    	//for(iuart=0;iuart<400;iuart++)
    	//{
    		System_printf(a);
    		System_flush();
    	//}
    	System_printf("\n");
    	System_flush();


    }
}

/*
 *  ======== main ========
 */
int main(void)
{
    /* Call board init functions. */
    Board_initGeneral();
    Board_initGPIO();
	Board_initI2C();
    // Board_initSDSPI();
    // Board_initSPI();
    Board_initUART();
    // Board_initUSB(Board_USBDEVICE);
    // Board_initWatchdog();
    // Board_initWiFi();


    dory_GPIO_init();
    /* Turn on user LED  */
    GPIO_write(Board_LED0, Board_LED_ON);


    System_printf("hoil\n");
    System_flush();

    /* Start BIOS */
    BIOS_start();

    return (0);
}



