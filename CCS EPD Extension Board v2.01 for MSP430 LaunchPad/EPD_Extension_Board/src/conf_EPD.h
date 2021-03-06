/**
* \file
*
* \brief The EPD configurations
*
* Copyright (c) 2012-2015 Pervasive Displays Inc. All rights reserved.
*
*  Authors: Pervasive Displays Inc.
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions
*  are met:
*
*  1. Redistributions of source code must retain the above copyright
*     notice, this list of conditions and the following disclaimer.
*  2. Redistributions in binary form must reproduce the above copyright
*     notice, this list of conditions and the following disclaimer in
*     the documentation and/or other materials provided with the
*     distribution.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <msp430.h>
#ifndef CONF_EPD_H_INCLUDED
#define CONF_EPD_H_INCLUDED
/**
 * \brief Developer needs to create an external function if wants to read flash */
typedef void (*EPD_read_memory_handler)(long flash_address,uint8_t *target_buffer,
		uint8_t byte_length);

#if !defined(FALSE)
#define FALSE 0 /**< define FALSE=0 */
#endif

#if !defined(TRUE)
#define TRUE (1) /**< define TRUE=1 */
#endif

#if !defined(NULL)
#define NULL (void *)0  /**< define NULL */
#endif

#if !defined(_NOP)
#define _NOP() asm("nop")
#endif

#if !defined(bool)
#define bool uint8_t
#endif

extern void delay_ms(unsigned int ms);

#define EPD_144 0 /**< 1.44 inch PDi EPD */
#define EPD_200 1 /**< 2 inch PDi EPD */
#define EPD_270 2 /**< 2.7 inch PDi EPD */
#define EPD_190 3 /**< 1.9 inch PDi EPD */
#define EPD_260 4 /**< 2.6 inch PDi EPD */



/** Define EPD_KIT_TOOL_FUNCTIONS if the code will work with EPD Kit Tool.
 * \note Comment out the #define below if you won't work with EPD Kit tool and
 *       just want to show two images change alternately by predefined image array.  */
#define EPD_KIT_TOOL_FUNCTIONS


/** Using which EPD size for demonstration.
 * \note You don't need to configure this if working with EPD Kit Tool. */
#ifndef EPD_KIT_TOOL_FUNCTIONS
/* Options are
 * EPD_144 for 1.44 inch
 * EPD_200 for 2.00 inch
 * EPD_270 for 2.70 inch
 * EPD_190 for 1.90 inch
 * EPD_260 for 2.60 inch*/
#define USE_EPD_Type EPD_270
#endif

/** \brief Supported COG and FPL type
 * \note
 * - Configure the option here to assign which COG+FPL driving waveform will be used.
 * - Options are G2_Aurora_Ma, G1_Aurora_Mb and G2_Aurora_Mb
 * - How to identify the COG and FPL type of your EPD, visit http://www.pervasivedisplays.com/products/label_info */
#define G2_Aurora_Mb

#define D_PartialUpdate_StageTime     480  //ms

/** The SPI frequency of this kit where MSP-EXP430F5529LP=(25MHz/2) and MSP-EXP430G=(16MHz/2) */
#define COG_SPI_baudrate 12500000

/** Define the number of ram buffer for system packet used interchangeably*/
#define BUFFER_SIZE	1


/** System Packet length=6~64, maximum=64.
* The payload length of MSP430 LaunchPad is 32 bytes only.
* ========================
* | Byte | Name          |
* |------|---------------|
* | 0    | Packet Header |
* | 1    | Packet Length |
* | 2-3  | Kit ID        |
* | 4    | Command Type  |
* | 5-62 | Data          |
* | 63   | CRC           |
*/
#define PAYLOAD_SIZE 32

/** Firmware version to display on EPD Kit Tool  */
#define EPD_KIT_TOOL_VERSION	"2.00 "

/** \brief Kit ID for recognizing by EPD Kit Tool
 * \note
 * - High byte is IC vendor, low byte is the name of supported development kit
 * - Texas Instruments=01, MSP-EXP430G2=01, MSP-EXP430F5529LP=02 */

#if (defined __MSP430F5529__)
#define EPD_KIT_TOOL_ID			(uint16_t)0x0102
#elif(defined __MSP430G2553__)
#define EPD_KIT_TOOL_ID			(uint16_t)0x0101
#endif


#include "EPD_hardware_driver.h"
#include "COG_FPL.h"
#include "EPD_interface.h"
#include "EPD_partial_interface.h"
#endif /* CONF_EPD_H_INCLUDED */

