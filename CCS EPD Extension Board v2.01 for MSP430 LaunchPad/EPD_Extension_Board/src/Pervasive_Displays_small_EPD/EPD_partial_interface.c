/**
* \file
*
* \brief The application interface for partial update
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

#include  "EPD_partial_interface.h"

/**
 * \brief For display power on stage, including power on and initialization of COG
 */
void display_PowerOn(uint8_t EPD_type_index)
{
	int8_t temperature=get_temperature();// Sense temperature
    /* Power on COG Driver */
	EPD_power_on(EPD_type_index,temperature);

	/* Initialize COG Driver */
	EPD_initialize_driver();
}


/**
 * \brief For display power off stage
 */
void display_PowerOff(void)
{
    /* Power off COG Driver */
	EPD_power_off ();
}


/**
 * \brief Compare with previous and new images and run Partial Update
 *
 * \param previous_image_ptr The pointer of memory that stores previous image
 * \param new_image_ptr The pointer of memory that stores new image
 */
void display_PartialUpdate(uint8_t *previous_image_ptr,uint8_t *new_image_ptr) {

	EPD_display_partialupdate_from_array_prt(previous_image_ptr,new_image_ptr);
}

/**
 * \brief Compare with previous and new images and run Global Update but determines if needs to Power on and off COG (Keep power)
 * \note This function is used when in partial update application but doesn't want to waste time for power on/off stages to perform global update
 *
 * \param EPD_type_index The defined EPD size
 * \param previous_image_ptr The pointer of memory that stores previous image
 * \param new_image_ptr The pointer of memory that stores new image
 * \param IsPowerControl Determine if need to Power On, Initialize and Power Off COG driver
 */
void display_GlobalUpdate(uint8_t EPD_type_index,uint8_t *previous_image_ptr,uint8_t *new_image_ptr,bool IsPowerControl)
{

    if(IsPowerControl)display_PowerOn(EPD_type_index);

	/* Display image data on EPD from image array */
	EPD_display_from_array_prt(previous_image_ptr,new_image_ptr);

	if(IsPowerControl)display_PowerOff();
}


