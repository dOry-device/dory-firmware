/*
 * Copyright (c) 2015, Texas Instruments Incorporated
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
 *  ======== MSP_EXP430F5529.c ========
 *  This file is responsible for setting up the board specific items for the
 *  MSP_EXP430F5529 board.
 */

#include <xdc/std.h>
#include <xdc/cfg/global.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Timestamp.h>

#include <msp430.h>
#include <inc/hw_memmap.h>
#include <dma.h>
#include <usci_a_uart.h>
#include <usci_b_i2c.h>
#include <usci_b_spi.h>
#include <usci_a_spi.h>
#include <ucs.h>
#include <gpio.h>
#include <pmm.h>
#include <wdt_a.h>

#include "MSP_EXP430F5529.h"

#include <ti/drivers/SPI.h>

const SPI_Config SPI_config[];

/*
 *  ======== MSP_EXP430F5529_initGeneral ========
 */
void MSP_EXP430F5529_initGeneral(void) {
}

/*
 *  ======== MSP_EXP430F5529_isrDMA ========
 *  This is a application defined DMA ISR. This ISR must map and call the
 *  appropriate Driver_event(handle) API to indicate completed DMA transfers.
 */
Void MSP_EXP430F5529_isrDMA(UArg arg)
{
#if TI_DRIVERS_WIFI_INCLUDED
    /* Call the SPI DMA function, passing the SPI handle used for WiFi */
    SPI_serviceISR((SPI_Handle) &(SPI_config[1]));
#else
    /* Use the SPI_Handle that operates the SPI driver */
    SPI_serviceISR((SPI_Handle) &(SPI_config[0]));
#endif
}

/*
 *  =============================== GPIO ===============================
 */
/* Place into subsections to allow linkers to remove items properly */
#if defined(__TI_COMPILER_VERSION__)
#pragma DATA_SECTION(GPIOMSP430_config, ".const:GPIOMSP430_config")
#endif

#include <ti/drivers/GPIO.h>
#include <ti/drivers/gpio/GPIOMSP430.h>

/*
 * Array of Pin configurations
 * NOTE: The order of the pin configurations must coincide with what was
 *       defined in MSP_EXP430F5529.h
 * NOTE: Pins not used for interrupts should be placed at the end of the
 *       array.  Callback entries can be omitted from callbacks array to
 *       reduce memory usage.
 */
GPIO_PinConfig gpioPinConfigs[] = {
    /* Input pins */
    /* MSP_EXP430F5529_S1 */
    GPIOMSP430_P1_7 | GPIO_CFG_IN_PU | GPIO_CFG_IN_INT_RISING,
    /* MSP_EXP430F5529_S2 */
    GPIOMSP430_P2_2 | GPIO_CFG_IN_PU | GPIO_CFG_IN_INT_RISING,

    /* Output pins */
    /* MSP_EXP430F5529_LED1 */
    GPIOMSP430_P1_0 | GPIO_CFG_OUT_STD | GPIO_CFG_OUT_STR_HIGH | GPIO_CFG_OUT_LOW,
    /* MSP_EXP430F5529_LED2 */
    GPIOMSP430_P8_1 | GPIO_CFG_OUT_STD | GPIO_CFG_OUT_STR_HIGH | GPIO_CFG_OUT_LOW,
    /* MSP_EXP430F5529_LED3 */
    GPIOMSP430_P8_2 | GPIO_CFG_OUT_STD | GPIO_CFG_OUT_STR_HIGH | GPIO_CFG_OUT_LOW,
    /* MSP_EXP430F5529_PAD1(Cross) */
    GPIOMSP430_P1_1 | GPIO_CFG_OUT_STD | GPIO_CFG_OUT_STR_HIGH | GPIO_CFG_OUT_LOW,
    /* MSP_EXP430F5529_PAD2(Square) */
    GPIOMSP430_P1_2 | GPIO_CFG_OUT_STD | GPIO_CFG_OUT_STR_HIGH | GPIO_CFG_OUT_LOW,
    /* MSP_EXP430F5529_PAD3(Octagon) */
    GPIOMSP430_P1_3 | GPIO_CFG_OUT_STD | GPIO_CFG_OUT_STR_HIGH | GPIO_CFG_OUT_LOW,
    /* MSP_EXP430F5529_PAD4(Triangle) */
    GPIOMSP430_P1_4 | GPIO_CFG_OUT_STD | GPIO_CFG_OUT_STR_HIGH | GPIO_CFG_OUT_LOW,
    /* MSP_EXP430F5529_PAD5(Circle) */
    GPIOMSP430_P1_5 | GPIO_CFG_OUT_STD | GPIO_CFG_OUT_STR_HIGH | GPIO_CFG_OUT_LOW
};

/*
 * Array of callback function pointers
 * NOTE: The order of the pin configurations must coincide with what was
 *       defined in MSP_EXP430F5529.h
 * NOTE: Pins not used for interrupts can be omitted from callbacks array to
 *       reduce memory usage (if placed at end of gpioPinConfigs array).
 */
GPIO_CallbackFxn gpioCallbackFunctions[] = {
    NULL,  /* MSP_EXP430F5529_S1 */
    NULL   /* MSP_EXP430F5529_S2 */
};

/* The device-specific GPIO_config structure */
const GPIOMSP430_Config GPIOMSP430_config = {
    .pinConfigs = (GPIO_PinConfig *) gpioPinConfigs,
    .callbacks = (GPIO_CallbackFxn *) gpioCallbackFunctions,
    .numberOfPinConfigs = sizeof(gpioPinConfigs) / sizeof(GPIO_PinConfig),
    .numberOfCallbacks = sizeof(gpioCallbackFunctions)/sizeof(GPIO_CallbackFxn)
};

/*
 *  ======== MSP_EXP430F5529_initGPIO ========
 */
void MSP_EXP430F5529_initGPIO(void)
{
    /* Initialize peripheral and pins */
    GPIO_init();
}

/* Place into subsections to allow linkers to remove items properly */
#if defined(__TI_COMPILER_VERSION__)
#pragma DATA_SECTION(I2C_config, ".const:I2C_config")
#pragma DATA_SECTION(i2cUSCIBHWAttrs, ".const:i2cUSCIBHWAttrs")
#endif

#include <ti/drivers/I2C.h>
#include <ti/drivers/i2c/I2CUSCIB.h>

/* I2C objects */
I2CUSCIB_Object i2cUSCIBObjects[MSP_EXP430F5529_I2CCOUNT];

/* I2C configuration structure */
const I2CUSCIB_HWAttrs i2cUSCIBHWAttrs[MSP_EXP430F5529_I2CCOUNT] = {
    {
        USCI_B0_BASE,
        USCI_B_I2C_CLOCKSOURCE_SMCLK
    },
    {
        USCI_B1_BASE,
        USCI_B_I2C_CLOCKSOURCE_SMCLK
    }
};

const I2C_Config I2C_config[] = {
    {
        &I2CUSCIB_fxnTable,
        &i2cUSCIBObjects[0],
        &i2cUSCIBHWAttrs[0]
    },
    {
        &I2CUSCIB_fxnTable,
        &i2cUSCIBObjects[1],
        &i2cUSCIBHWAttrs[1]
    },
    {NULL, NULL, NULL}
};

/*
 *  ======== MSP_EXP430F5529_initI2C ========
 */
void MSP_EXP430F5529_initI2C(void)
{
    /* USCIB0 */
    GPIO_setAsPeripheralModuleFunctionInputPin(
        GPIO_PORT_P3,
        GPIO_PIN0 | GPIO_PIN1);

    /* USCIB1 */
    /*
     * NOTE: TI-RTOS examples configure USCIB1 as either SPI or I2C.  Thus,
     * a conflict occurs when the I2C & SPI drivers are used simultaneously in
     * an application.  Modify the pin mux settings in this file and resolve the
     * conflict before running your the application.
     */
    GPIO_setAsPeripheralModuleFunctionInputPin(
        GPIO_PORT_P4,
        GPIO_PIN1 | GPIO_PIN2);

    I2C_init();
}

/* Place into subsections to allow linkers to remove items properly */
#if defined(__TI_COMPILER_VERSION__)
#pragma DATA_SECTION(SDSPI_config, ".const:SDSPI_config")
#pragma DATA_SECTION(sdspiUSCIBHWAttrs, ".const:sdspiUSCIBHWAttrs")
#endif

#include <ti/drivers/SDSPI.h>
#include <ti/drivers/sdspi/SDSPIUSCIB.h>

/* SDSPI objects */
SDSPIUSCIB_Object sdspiUSCIBobjects[MSP_EXP430F5529_SDSPICOUNT];

/* SDSPI configuration structure, describing which pins are to be used */
const SDSPIUSCIB_HWAttrs sdspiUSCIBHWAttrs[MSP_EXP430F5529_SDSPICOUNT] = {
    {
        USCI_B1_BASE,   /* SPI base address */
        USCI_B_SPI_CLOCKSOURCE_SMCLK, /* Clock source */

        GPIO_PORT_P4,   /* SPI SCK PORT */
        GPIO_PIN3,      /* SCK PIN */
        GPIO_PORT_P4,   /* SPI MISO PORT */
        GPIO_PIN2,      /* MISO PIN */
        GPIO_PORT_P4,   /* SPI MOSI PORT */
        GPIO_PIN1,      /* MOSI PIN */
        GPIO_PORT_P3,   /* GPIO CS PORT */
        GPIO_PIN7,      /* CS PIN */
    }
};

const SDSPI_Config SDSPI_config[] = {
    {
        &SDSPIUSCIB_fxnTable,
        &sdspiUSCIBobjects[0],
        &sdspiUSCIBHWAttrs[0]
    },
    {NULL, NULL, NULL}
};

/*
 *  ======== MSP_EXP430F5529_initSDSPI ========
 */
void MSP_EXP430F5529_initSDSPI(void)
{
    SDSPI_init();
}

/* Place into subsections to allow linkers to remove items properly */
#if defined(__TI_COMPILER_VERSION__)
#pragma DATA_SECTION(SPI_config, ".const:SPI_config")
#pragma DATA_SECTION(spiUSCIBDMAHWAttrs, ".const:spiUSCIBDMAHWAttrs")
#endif

#include <ti/drivers/SPI.h>
#include <ti/drivers/spi/SPIUSCIBDMA.h>

/* SPI objects */
SPIUSCIBDMA_Object spiUSCIBDMAobjects[MSP_EXP430F5529_SPICOUNT];
uint8_t spiUSCIBDMAscratchBuf[MSP_EXP430F5529_SPICOUNT];

/* SPI configuration structure */
const SPIUSCIBDMA_HWAttrs spiUSCIBDMAHWAttrs[MSP_EXP430F5529_SPICOUNT] = {
    {
        USCI_B1_BASE,
        USCI_B_SPI_CLOCKSOURCE_SMCLK,
        USCI_B_SPI_MSB_FIRST,
        &spiUSCIBDMAscratchBuf[0],
        0,

        /* DMA */
        DMA_BASE,
        /* Rx Channel */
        DMA_CHANNEL_1,
        DMA_TRIGGERSOURCE_22,
        /* Tx Channel */
        DMA_CHANNEL_0,
        DMA_TRIGGERSOURCE_23
    },
    {
        USCI_B0_BASE,
        USCI_B_SPI_CLOCKSOURCE_SMCLK,
        USCI_B_SPI_MSB_FIRST,
        &spiUSCIBDMAscratchBuf[1],
        0,

        /* DMA */
        DMA_BASE,
        /* Rx Channel */
        DMA_CHANNEL_1,
        DMA_TRIGGERSOURCE_18,
        /* Tx Channel */
        DMA_CHANNEL_0,
        DMA_TRIGGERSOURCE_19
    }
};

const SPI_Config SPI_config[] = {
    {
        &SPIUSCIBDMA_fxnTable,
        &spiUSCIBDMAobjects[0],
        &spiUSCIBDMAHWAttrs[0]
    },
    {
        &SPIUSCIBDMA_fxnTable,
        &spiUSCIBDMAobjects[1],
        &spiUSCIBDMAHWAttrs[1]
    },
    {NULL, NULL, NULL},
};

/*
 *  ======== MSP_EXP430F5529_initSPI ========
 */
void MSP_EXP430F5529_initSPI(void)
{
    /* USCIB1 */
    /*
     * NOTE: TI-RTOS examples configure USCIB1 as either SPI or I2C.  Thus,
     * a conflict occurs when the I2C & SPI drivers are used simultaneously in
     * an application.  Modify the pin mux settings in this file and resolve the
     * conflict before running your the application.
     */
    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P4,
            GPIO_PIN3 | GPIO_PIN2 | GPIO_PIN1);

    /* SOMI/MISO */
    GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P4,
            GPIO_PIN2);

    /* CLK and SIMO/MOSI */
    GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P4,
            GPIO_PIN3 | GPIO_PIN1);

    SPI_init();
}

/* Place into subsections to allow linkers to remove items properly */
#if defined(__TI_COMPILER_VERSION__)
#pragma DATA_SECTION(UART_config, ".const:UART_config")
#pragma DATA_SECTION(uartUSCIAHWAttrs, ".const:uartUSCIAHWAttrs")
#endif

#include <ti/drivers/UART.h>
#include <ti/drivers/uart/UARTUSCIA.h>

/* UART objects */
UARTUSCIA_Object uartUSCIAObjects[MSP_EXP430F5529_UARTCOUNT];

/*
 * The baudrate dividers were determined by using the MSP430 baudrate
 * calculator
 * http://software-dl.ti.com/msp430/msp430_public_sw/mcu/msp430/MSP430BaudRateConverter/index.html
 */
const UARTUSCIA_BaudrateConfig uartUSCIABaudrates[] = {
    /* baudrate, input clock, prescalar, UCBRFx, UCBRSx, oversampling */
    {115200, 8192000, 4,   7, 0, 1},
    {9600,   8192000, 53,  5, 0, 1},
    {9600,   32768,   3,   0, 3, 0},
};

/* UART configuration structure */
const UARTUSCIA_HWAttrs uartUSCIAHWAttrs[MSP_EXP430F5529_UARTCOUNT] = {
    {
        USCI_A1_BASE,
        USCI_A_UART_CLOCKSOURCE_SMCLK,
        USCI_A_UART_LSB_FIRST,
        sizeof(uartUSCIABaudrates)/sizeof(UARTUSCIA_BaudrateConfig),
        uartUSCIABaudrates
    },
};

const UART_Config UART_config[] = {
    {
        &UARTUSCIA_fxnTable,
        &uartUSCIAObjects[0],
        &uartUSCIAHWAttrs[0]
    },
    {NULL, NULL, NULL}
};

/*
 *  ======== MSP_EXP430F5529_initUART ========
 */
void MSP_EXP430F5529_initUART(void)
{
    /* P4.4,5 = USCI_A1 TXD/RXD */
    GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P4,
            GPIO_PIN4 | GPIO_PIN5);

    /* Initialize the UART driver */
    UART_init();
}

/*
 *  ======== MSP_EXP430F5529_initUSB ========
 */
void MSP_EXP430F5529_initUSB(unsigned int arg)
{
    PMM_setVCore(PMM_CORE_LEVEL_3);

}

/* Place into subsections to allow linkers to remove items properly */
#if defined(__TI_COMPILER_VERSION__)
#pragma DATA_SECTION(Watchdog_config, ".const:Watchdog_config")
#pragma DATA_SECTION(watchdogMSP430HWAttrs, ".const:watchdogMSP430HWAttrs")
#endif

#include <ti/drivers/Watchdog.h>
#include <ti/drivers/watchdog/WatchdogMSP430.h>

/* Watchdog objects */
WatchdogMSP430_Object watchdogMSP430Objects[MSP_EXP430F5529_WATCHDOGCOUNT];

/* Watchdog configuration structure */
const WatchdogMSP430_HWAttrs watchdogMSP430HWAttrs[MSP_EXP430F5529_WATCHDOGCOUNT] = {
    {
        WDT_A_BASE,
        SFR_BASE,
        WDT_A_CLOCKSOURCE_SMCLK,
        WDT_A_CLOCKDIVIDER_8192K
    }, /* MSP430F5529_WATCHDOG */
};

const Watchdog_Config Watchdog_config[] = {
    {
        &WatchdogMSP430_fxnTable,
        &watchdogMSP430Objects[0],
        &watchdogMSP430HWAttrs[0]
    },
    {NULL, NULL, NULL}
};

/*
 *  ======== MSP_EXP430F5529_initWatchdog ========
 */
void MSP_EXP430F5529_initWatchdog(void)
{
    /* Initialize the Watchdog driver */
    Watchdog_init();
}
