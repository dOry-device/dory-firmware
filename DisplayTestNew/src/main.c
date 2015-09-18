/**
 * \file
 *
 * \brief Sample project code for demonstrating Pervasive Displays 1.44", 1.9", 2", 2.6" and 2.7" EPD
 *
 * \note There is quick start guide at the bottom of this file
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

/**
 * \brief Demonstration on EPD Extension board with EPD for toggling between two images
 *        or working with EPD Kit Tool
 *
 * \par Content
 * -# Include Pervasive_Displays_small_EPD.h: EPD definitions
 * -# Include If defined EPD_KIT_TOOL_FUNCTIONS in conf_EPD.h,
 *            includes EPD_Kit_Tool_Process.h for working with EPD Kit Tool,
 *            or includes image_data.h to load from image data array
 */

#include "conf_EPD.h"
//#include <stdio.h>
#include <string.h>
#if (defined EPD_KIT_TOOL_FUNCTIONS)
#include "EPD_Kit_Tool_Process.h"
#else
#include "image_data.h"
#endif


//uint8_t flipped_image_array_270_1[5808];
//uint8_t flipped_image_array_270_2[5808];

/** The main function will start toogling between two images on corresponding EPD
 *  depends on specified EPD size or working with EPD Kit Tool */
int main(void) {
	/* Initialize system clock and TI LaunchPad board */
	system_init();

	/*flip image bytes*/
	flip_image_bytes((uint8_t *)&image_array_270_1,(uint8_t *)&image_array_270_1);
//	flip_image_bytes((uint8_t *)&image_array_270_2,(uint8_t *)&image_array_270_2);


	/* Initialize EPD hardware */
	EPD_display_init();
	__enable_interrupt();//enable interrupts
	//__bis_SR_register(GIE);

#if (defined EPD_KIT_TOOL_FUNCTIONS) /** if working with EPD Kit Tool ***************/
	LED_init();
	EPD_Kit_Tool_process_init();
	for(;;) {
		EPD_Kit_tool_process_task();
	}

#else /* if showing two images alternatively ***************************************/
	for(;;) {
		//puts("he");//TODO : remove debug

		/* User selects which EPD size to run demonstration by changing the
		 * USE_EPD_Type in conf_EPD.h
		 * The Image data arrays for each EPD size are predefined at image_data.c */
#if(USE_EPD_Type==EPD_144)
		EPD_display_from_pointer(EPD_144,(uint8_t *)&image_array_144_2,(uint8_t *)&image_array_144_1);
#elif(USE_EPD_Type==EPD_200)
		EPD_display_from_pointer(EPD_200,(uint8_t *)&image_array_200_2,(uint8_t *)&image_array_200_1);
#elif(USE_EPD_Type==EPD_270)
		/* Due to if loading two image arrays for 2.7", the code size will exceed the MSP430G2553 flash.
		 * So the demo will load 1st image continuously.*/
#ifdef G2_Aurora_Ma
		EPD_display_from_pointer(EPD_270,(uint8_t *)&image_array_270_1,(uint8_t *)&image_array_270_1);
#else
		EPD_display_from_pointer(EPD_270,image_array_270_1,image_array_270_1);
#endif
#elif(USE_EPD_Type==EPD_190)
        EPD_display_from_pointer(EPD_190,(uint8_t *)&image_array_190_2,(uint8_t *)&image_array_190_1);
#elif(USE_EPD_Type==EPD_260)
        EPD_display_from_pointer(EPD_260,(uint8_t *)&image_array_260_2,(uint8_t *)&image_array_260_1);
#endif

		/* The interval of two images alternatively change is 5 seconds */
		delay_ms(5000);

		P2OUT |= BIT0;

#if(USE_EPD_Type==EPD_144)
		EPD_display_from_pointer(EPD_144,(uint8_t *)&image_array_144_1,(uint8_t *)&image_array_144_2);
#elif(USE_EPD_Type==EPD_200)
		EPD_display_from_pointer(EPD_200,(uint8_t *)&image_array_200_1,(uint8_t *)&image_array_200_2);
#elif(USE_EPD_Type==EPD_270)
		/* Due to if loading two image arrays for 2.7", the code size will exceed the MSP430G2553 flash.
		 * So the demo will load 1st image continuously.*/
#ifdef G2_Aurora_Ma
		EPD_display_from_pointer(EPD_270,(uint8_t *)&image_array_270_1,(uint8_t *)&image_array_270_1);
#else
	//	EPD_display_from_pointer(EPD_270,flipped_image_array_270_2,flipped_image_array_270_1);
#endif
#elif(USE_EPD_Type==EPD_190)
        EPD_display_from_pointer(EPD_190,(uint8_t *)&image_array_190_1,(uint8_t *)&image_array_190_2);
#elif(USE_EPD_Type==EPD_260)
        EPD_display_from_pointer(EPD_260,(uint8_t *)&image_array_260_1,(uint8_t *)&image_array_260_2);
#endif

		/* The interval of two images alternatively change is 5 seconds */
		delay_ms(5000);

		P2OUT &= ~BIT0;
	}
#endif
}

/**
 * \page - Quick Start Guide
 *
 * This is the quick start guide for the EPD Extension board made by Pervasive Displays Inc.
 * with its small size EPDs on how to setup the kit to MSP430 LaunchPads(MSP-EXP430G2 and MSP-EXP430F5529LP).
 * The code example in main.c provides two ways for EPD updates:
 *  (1) toggling between two images from image array
 *  (2) working with PDi's EPD Kit Tool (a graphic user interface tool)
 * It also instructs how to use the display functions.
 *
 * \note
 * - Released Date: 18 Mar, 2015.  Version: 2.01
 *   which is able to work with EPD Kit Tool v2.0
 * - Compiled by CCStudio version = v6.0.1 with MSP430 compiler v4.4.3
 * - PDi = Pervasive Displays Inc. http://www.pervasivedisplays.com
 * - EPD = Electronic Paper Display (Electrophoretic Display)
 * - EPD Extension Board/Kit = The driving board has direct socket to LaunchPad and
 *   also features 20 pin-out bridges to your product or development kit
 * - EPD Kit Tool = The application(user graphic interface) to work with EPD
 *   Extension kit. You can download the installer and source code at here:
 *   http://www.pervasivedisplays.com/kits/ext_kit#tab5
 * - COG = Chip on Glass, the driver IC on EPD module
 * - COG G1 or G2: G is for generation.
 * - FPL = Front Plane Laminate which is E-Ink material film.
 *   There are Vizplex(V110, EOL already), Aurora Ma(V230) and Aurora Mb(V231) type
 * - PDi offers Aurora_Ma and Aurora_Mb material with G2 COG to the market.
 *   Some customers got our Aurora_Mb+G1 combination. The sample code is also provided.
 * - Basically, the Aurora_Mb+G1 is the replacement for Vizplex+G1.
 * - How to identify the FPL material type of your displays, please visit
 *   http://www.pervasivedisplays.com/products/label_info
 * - For driving PDi's small size EPDs, please read the "COG Driver Interface
 *   Timing" document(hereinafter COG Document) first. It explains the interface
 *   to the COG driver of EPD for a MCU based solution.
 * - COG Document no.: 4P008-00 (for Vizplex+G1)  : http://www.pervasivedisplays.com/LiteratureRetrieve.aspx?ID=138408
 * - COG Document no.: 4P015-00 (for Aurora_Ma+G2): http://www.pervasivedisplays.com/LiteratureRetrieve.aspx?ID=198794
 * - COG Document no.: 4P016-00 (for Aurora_Mb+G1): http://www.pervasivedisplays.com/LiteratureRetrieve.aspx?ID=220874
 * - COG Document no.: 4P018-00 (for Aurora_Mb+G2): http://www.pervasivedisplays.com/LiteratureRetrieve.aspx?ID=220873
 * - This project code supports EPD size: 1.44", 1.9", 2", 2.6" and 2.7"
 * - Supports MSP430 LaunchPad: MSP-EXP430G2 http://www.ti.com/ww/en/launchpad/launchpads-msp430-msp-exp430g2.html#tabs
 * - Supports MSP430 LaunchPad: MSP-EXP430F5529LP http://www.ti.com/ww/en/launchpad/launchpads-msp430-msp-exp430f5529lp.html#tabs
 * - The Aurora_Ma EPD doesn't support partial updated. The ASCII function of EPD
 *   Kit Tool when connecting with Aurora_Ma G2 type displays has been disabled.
 *   When clicking [Send] button in EPD Kit Tool, there will do nothing on EPD.
 * - The Aurora_Mb (and old material Vizplex) with G1 or G2 supports partial update.
 *
 * \section File_Explanation
 * - <b>image_data:</b>\n
 *   It defines the image arrays for each EPD size. User can use the array without
 *   application input.
 * - <b>conf_EPD.h:</b> The EPD configurations.\n
 *   -# EPD_KIT_TOOL_FUNCTIONS: define it if you will work with EPD Kit Tool
 *      ,or comment out this define if just toggling between two images(auto-run)
 *   -# USE_EPD_Type: if commented out the define of EPD_KIT_TOOL_FUNCTIONS, must define this size of EPD
 *   -# Gx_Aurora_xx: define which FPL material with COG driving waveform of the EPD you're connecting
 *   -# D_PartialUpdate_StageTime: define the stage duration for partial update
 *   -# COG_SPI_baudrate: SPI speed, G1 works in 4-12MHz, G2 works in 4-20MHz
 *   -# EPD_KIT_TOOL_VERSION: the firmware version of this project code
 *   -# EPD_KIT_TOOL_KIT_ID: define this kit ID, 0x0101
 * - <b>EPD_Kit_Tool</b> folder:\n
 *   If you will work with PDi's EPD Extension Kit, the commands and definitions
 *   are located in this folder.
 *     -# <b>Mem_Flash:</b>\n
 *        The functions of working with flash memory including saving image, easing
 *        images and get/set parameters.
 *     -# <b>Uart_Controller:</b>\n
 *        The functions to control and return system packets with EPD Kit Tool.
 *     -# <b>Char:</b>\n
 *        The definition of ASCII characters.
 *     -# <b>EPD_Kit_Tool_Process:</b>\n
 *        All of the functions that are provided on EPD Kit Tool.
 *     -# <b>Drivers folder:</b>\n
 *        The driver of UART and LED.
 * - <b>Pervasive_Displays_small_EPD</b> folder:\n
 *   All of the COG driving waveforms are located in this folder. Logically developer
 *   doesn't need to change the codes in this folder in order to keep correct driving
 *   to the EPDs.\n\n
 *   <b><em>Software architecture:</em></b>\n
 *   [Application (ex. EPD Kit Tool)] <-- [COG interface (<em>EPD_interface</em>)] <--
 *   [COG driving process (<em>EPD_Gx_Aurora_Mx</em> in COG_FPL folder)] <--
 *   [Hardware Driver & GPIO (<em>EPD_hardware_driver</em>)]\n\n
 *    -# <b>EPD_hardware_driver:</b>\n
 *       Most of the COG hardware initialization, GPIO and configuration. User can implement
 *       the driver layer of EPD if some variables need to be adjusted. The provided
 *       settings and functions are Timer, SPI, PWM, temperature and EPD hardware initialization.
 *    -# <b>COG_FPL</b> folder:\n
 *       The driving process for each sub-folder represents the different display module.
 *       - <b>EPD_UpdateMethod_Gx_Aurora_Mx:</b>\n
 *         UpdateMethod: Global update or Partial update. If none, it means both.
 *         Gx: G1 or G2.
 *         Aurora_Mx: Aurora_Ma or Aurora_Mb.
 *    -# <b>EPD_interface, EPD_partial_interface:</b>\n
 *       The application interfaces to work with EPD.
 *
 *
 * \section Use_Case
 * -# <b>EPD_display_from_pointer</b>: Load two image data arrays from image_data.c
 *   according to predefined EPD size.
 * -# <b>EPD_display_from_flash</b>:
 *   Load image data from flash memory according to the commands by EPD Kit Tool.
 *
 * \section Steps
 * -# Ensure the EPD is connected correctly on the EPD Extension board
 * -# Stack the EPD Extension board onto MSP430 LaunchPad board directly
 * -# Connect the LaunchPad board to computer's USB port via its USB cable
 * -# Right click on project name and choose pop-up menu from [Build Configurations]/[Set Active],
 *    Select the MSP430 LaunchPad that you are connecting.
 * -# Find #define Gx_Aurora_Mx in "conf_EPD.h" file. Change to the correct type of EPD you are connecting.
 *    - <b>Toggle between two images (auto-run, without any tool):</b>\n
 *         -# Open "conf_EPD.h" file and find
 *            "#define USE_EPD_Type USE_EPDxxx". Change the USE_EPDXXX to the correct size.
 *         -# Comment out "#define EPD_KIT_TOOL_FUNCTIONS"
 *         -# Start debugging to program the project code to MSP430 MCU. The EPD will show
 *            two images change alternately every 5 seconds (default).
 *    - <b>Work with EPD Kit Tool:</b>\n
 *         -# Open "conf_EPD.h" file and ensure "#define EPD_KIT_TOOL_FUNCTIONS".
 *         -# Start debugging to program the project code to MSP430 MCU.
 *         -# Install EPD Kit Tool and then execute it. On the EPD Kit Tool, click [Scan]
 *            button to search "TI_LaunchPad" kit. If found, click [Connect].
 *         -# Refer to EPD Extension Kit_User manual. http://www.pervasivedisplays.com/kits/ext_kit#tab5
 *
 *
 * \section PDi EPD displays
 * ======================================
 * | Size | PDi Model  |   FPL + COG    |
 * |------|------------|----------------|
 * | 1.44 | EK014BS011 | Aurora_Ma + G2 |
 * | 2.0  | EG020BS011 | Aurora_Ma + G2 |
 * | 2.7  | EM027BS013 | Aurora_Ma + G2 |
 * | 1.44 | EK014CS011 | Aurora_Mb + G1 |
 * | 1.9  | EB019CS011 | Aurora Mb + G1 |
 * | 2.0  | EG020CS012 | Aurora_Mb + G1 |
 * | 2.6  | EN026CS011 | Aurora Mb + G1 |
 * | 2.7  | EM027CS011 | Aurora_Mb + G1 |
 * | 1.44 | E1144CS021 | Aurora Mb + G2 |
 * | 1.9  | E1190CS021 | Aurora Mb + G2 |
 * | 2.0  | E1200CS021 | Aurora Mb + G2 |
 * | 2.6  | E1260CS021 | Aurora Mb + G2 |
 * | 2.7  | E1271CS021 | Aurora Mb + G2 |
 *
 * http://www.pervasivedisplays.com/products/label_info
 */
