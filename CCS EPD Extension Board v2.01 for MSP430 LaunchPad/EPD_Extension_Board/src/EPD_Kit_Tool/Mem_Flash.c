/**
* \file
*
* \brief The functions of working with flash memory
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

#include "Mem_Flash.h"


static uint8_t Mark_Random_Index=0;

/**
 * \brief Set Flash_CS pin to high and EPD_CS to low
 */
void Flash_cs_high(void) {
	EPD_flash_cs_high();
	EPD_cs_low ();
}

/**
 * \brief Set EPD_CS to high and Flash_CS to low
 */
void Flash_cs_low(void) {
	EPD_cs_high();
	EPD_flash_cs_low();
}

void Flash_init(void) {
	//Flash_CS_High();
}
 

/**
 * \brief Send one data byte to SPI
 *
 * \param data The data to be sent out
 */
static uint8_t send_byte(uint8_t byte_value) {
	epd_spi_write(byte_value);
	return 0;
	//return epd_spi_read(byte_value);
}

/**
 * \brief Get one data byte from SPI
 *
 * \return Get one data byte
 */
static uint8_t get_byte(void) {
	return epd_spi_read(0);
}

/**
 * \brief Send address to Flash
 *
 * \param flash_address The address
 */
static void send_flash_address(long flash_address) {
	/** A23-A0 */
	send_byte( (flash_address >> 16) );
	send_byte( (flash_address >> 8) );
	send_byte( (flash_address));
}

/**
 * \brief Read status register
 *
 * \return Register status
 */
static uint8_t CMD_RDSR(void) {
	uint8_t	gDataBuffer;

	// Chip select go low to start a flash command
	Flash_cs_low();

	// Send command
	gDataBuffer =send_byte( FLASH_CMD_RDSR );
	gDataBuffer = get_byte();

	// Chip select go high to end a flash command
	Flash_cs_high();

	return gDataBuffer;
}

/**
 * \brief Check if the flash is busy
 *
 * \return 1=busy, 0=not busy
 */
static uint8_t IsFlashBusy( void ) {
	uint8_t	 gDataBuffer;

	gDataBuffer= CMD_RDSR();
	if( (gDataBuffer & FLASH_WIP_MASK)  == FLASH_WIP_MASK )
		return 1;
	else
		return 0;
}

/**
 * \brief Read Flash data into buffer
 *
 * \param flash_address The start address of Flash
 * \param target_buffer The target address of buffer will be read
 * \param byte_length The data length will be read
 */
static void flash_cmd_read( long flash_address, uint8_t *target_buffer, long byte_length ) {
	long index;
	while( IsFlashBusy());
	/** Chip select go low to start a flash command */
	Flash_cs_low();


	/** Write READ command and address */
	send_byte( FLASH_CMD_FASTREAD );
	send_flash_address( flash_address );
	send_byte(0);

	/** Set a loop to read data into buffer */
	for( index=0; index < byte_length; index++ ) {
		// Read one data byte at a time
		*(target_buffer + index) = get_byte();
	}

	/** Chip select go high to end a flash command */
	Flash_cs_high();
}

/**
 * \brief Check the flash memory of EPD extension board is existed or not in order
 *         to determine the board is connected
 * \return The Flash is existed
 */
uint8_t is_flash_existed(void) {
	uint8_t	get_data_buffer=0;
	uint8_t check_times=3, flash_existed=0;
	epd_spi_attach();
	while(check_times--) {
		Flash_cs_high();
		delay_ms(1);
		/** Chip select go low to start a flash command */
		Flash_cs_low();
		delay_ms(1);
		/** Send command to check the Electronic ID of Flash */
		if(epd_spi_write_ex( FLASH_CMD_RES )==1) {
			epd_spi_write_ex(0);
			epd_spi_write_ex(0);
			epd_spi_write_ex(0);
			get_data_buffer = get_byte();
		}
		/** Chip select go high to end a flash command */
		Flash_cs_high();
		if(get_data_buffer==ElectronicID) {
			flash_existed=1;
			break;
		}
	};
	return flash_existed;
}

/**
 * \brief Check if the flash is write enable
 *
 * \return 1=write enable, 0=not write enable
 */
static uint8_t checkWREN( void ) {
	uint8_t	 gDataBuffer;

	gDataBuffer= CMD_RDSR();
	if( (gDataBuffer & 0x02)  == 0x02 )
		return 1;
	else
		return 0;
}
/**
 * \brief Set flash write enable
 */
static void CMD_WREN( void ) {
	do{
		// Chip select go low to start a flash command
		Flash_cs_low();
		// Write Enable command = 0x06, Setting Write Enable Latch Bit
		send_byte( FLASH_CMD_WREN );

		// Chip select go high to end a flash command
		Flash_cs_high();
	}while(!checkWREN());
}

/**
 * \brief Write the data to flash
 *
 * \param flash_address 32 bit flash memory address
 * \param source_address The source address of buffer will be written
 * \param byte_length The data length will be read
 */
static void CMD_PP( long flash_address, uint8_t *source_address, uint8_t byte_length ) {
	long index;
	while( IsFlashBusy()) _NOP();
	// Setting Write Enable Latch bit
	CMD_WREN();

	// Chip select go low to start a flash command
	Flash_cs_low();

	// Write Page Program command
	send_byte( FLASH_CMD_PP );
	send_flash_address( flash_address);

	// Set a loop to download whole page data into flash's buffer
	// Note: only last 256 byte will be programmed
	for( index=0; index < byte_length; index++ ) {
		send_byte( *(source_address + index) );
	}

	// Chip select go high to end a flash command
	Flash_cs_high();
	while( IsFlashBusy()) _NOP();
}

/**
 * \brief Erase the data of the chosen sector (4KB) to be "1"
 *
 * \param flash_address 32 bit flash memory address
 */
void CMD_SE( long flash_address ) {
	while( IsFlashBusy()) _NOP();
	// Setting Write Enable Latch bit
	CMD_WREN();
	while(IsFlashBusy());
	// Chip select go low to start a flash command
	Flash_cs_low();

	//Write Sector Erase command = 0x20;
	send_byte( FLASH_CMD_SE );

	send_flash_address( flash_address );

	// Chip select go high to end a flash command
	Flash_cs_high();
	while(IsFlashBusy());
}

/**
 * \brief Erase all of the flash memory
 */
void CMD_CE(void) {
	while(IsFlashBusy()) _NOP();
	// Setting Write Enable Latch bit
	CMD_WREN();
	// Chip select go low to start a flash command
	Flash_cs_low();
	//Write Chip Erase command = 0x60;
	send_byte( FLASH_CMD_CE);
	// Chip select go high to end a flash command
	Flash_cs_high();
	while( IsFlashBusy());

}


/**
 * \brief Read Flash data into buffer
 *
 * \param flash_address The start address of Flash
 * \param target_buffer The target address of buffer will be read
 * \param byte_length The data length will be read
 */
void read_flash(long flash_address,uint8_t *target_buffer, uint8_t byte_length) {

	flash_cmd_read(flash_address,target_buffer,byte_length);
}

/**
 * \brief Write Flash data from buffer
 *
 * \param flash_address 32 bit flash memory address
 * \param source_address The source address of buffer will be written
 * \param byte_length The data length will be read
 */
void write_flash(long flash_address,uint8_t *source_address, uint8_t byte_length) {

	CMD_PP(flash_address,source_address,byte_length);

}


/**
 * \brief To erase the image data
 *
 * \param address The start address to be erased
 * \param EPD_size The EPD size
 */
void erase_image(long address,uint8_t EPD_size) {
	uint8_t i,multiple_of_image_size=2;

	switch(EPD_size) {
	case EPD_144:	
    case EPD_190:
	case EPD_200:
    case EPD_260:
		multiple_of_image_size=2; // 8 kbytes
		break;
	case EPD_270:
		multiple_of_image_size=3; // 12kbytes
		break;
	}
	for(i=0; i<multiple_of_image_size; i++) {
		CMD_SE(address); //Erase data of the chosen sector
		address+=_flash_sector_size; //4K
		//delay_ms(300);
	}
}

/**
 * \brief Get the slideshow image address and clear the image or not
 *
 * \param EPD_size The EPD size
 * \param image_index The current image index to show
 * \param is_clear Whether to clear slideshow images
 */
long get_slideshow_image_address(uint8_t EPD_size,uint8_t image_index,uint8_t is_clear) {
	long addr=0;
	uint8_t IsExit=0xFF;

	/** number of maximum slideshow images = 4 */
	if(image_index>_image200_slideshow_page_max) image_index=0;

	switch( EPD_size) {
	case EPD_144:
		addr=_image144_slideshow_address(image_index);
		break;
	case EPD_190:
    case EPD_200:
    case EPD_260:
		addr=_image200_slideshow_address(image_index);
		break;
	case EPD_270:
		addr=_image270_slideshow_address(image_index);
		break;
	}
	/** To erase slideshow image */
	if(is_clear) {
		/** Read image mark offset byte to IsExit */
		flash_cmd_read(addr+_image_header_mark_offset,(uint8_t *)&IsExit,1);
		if(IsExit!=_image_state_is_empty) erase_image(addr,EPD_size);
	}

	return addr;
}

/**
 * \brief Get the custom image address and clear the image or not
 *
 * \param EPD_size The EPD size
 * \param image_index The current image index to show
 * \param is_clear Whether to clear custom images
 */
long get_custom_image_address(uint8_t  EPD_size,uint8_t image_index,uint8_t is_clear) {
	long addr=0;
	uint8_t IsExit=0xFF;

	/** number of maximum custom images = 8 */
	if(image_index>_image200_custom_page_max) image_index=0;

	switch( EPD_size) {
	case EPD_144:
		addr=_image144_custom_address(image_index);
		break;
	case EPD_190:
    case EPD_200:
    case EPD_260:
		addr=_image200_custom_address(image_index);
		break;
	case EPD_270:
		addr=_image270_custom_address(image_index);
		break;
	}
	/** To erase custom image */
	if(is_clear) {
		flash_cmd_read(addr+_image_header_mark_offset,(uint8_t *)&IsExit,1);
		if(IsExit!=_image_state_is_empty) erase_image(addr,EPD_size);
	}

	return addr;
}

/**
 * \brief Get mark image information from flash
 *
 * \param EPD_size The EPD size
 */
long get_flash_mark_image_info(uint8_t EPD_size) {
	long mark_address=0;
	uint8_t IsExit=0xFF;

	switch(EPD_size) {
	case EPD_144:
		mark_address=_image144_mark_image_address(Mark_Random_Index);
		break;
	case EPD_190:
    case EPD_200:
    case EPD_260:
		mark_address=_image200_mark_image_address(Mark_Random_Index);
		break;
	case EPD_270:
		mark_address=_image270_mark_image_address(Mark_Random_Index);
		break;
	}
	Mark_Random_Index=(Mark_Random_Index+1) % (_image144_mark_image_page_max-1);
	flash_cmd_read(mark_address+_image_header_mark_offset,(uint8_t *)&IsExit,1);
	if(IsExit!=_image_state_is_empty) erase_image(mark_address,EPD_size);

	return mark_address;
}

/**
 * \brief Get image information from flash
 *
 * \param image_info The data structure of image information
 */
void get_flash_image_info(image_information_t * image_info) {
	uint8_t i;
	uint8_t previous_address_offset,new_address_offset,empty_address_offset;
	long next_new_empty_address=0;
	long previous_address=0;
	epd_spi_attach();
	delay_ms(2);
	for(i=0; i<_image_page_max; i++) {
		switch(image_info->EPD_size) {
		case EPD_144:
			previous_address=_image144_address(i);
			image_info->new_image_address=_image144_address(((i+1) & _image_page_mark));
			next_new_empty_address=_image144_address(((i+2) & _image_page_mark));
			break;
    	case EPD_190:
        case EPD_200:
        case EPD_260:
			previous_address=_image200_address(i);
			image_info->new_image_address=_image200_address(((i+1) & _image_page_mark));
			next_new_empty_address=_image200_address(((i+2) & _image_page_mark));
			break;
		case EPD_270:
			previous_address=_image270_address(i);
			image_info->new_image_address=_image270_address(((i+1) & _image_page_mark));
			next_new_empty_address=_image270_address(((i+2) & _image_page_mark));
			break;
		}
		flash_cmd_read(previous_address+_image_header_mark_offset,(uint8_t *)&previous_address_offset,1);
		flash_cmd_read(image_info->new_image_address+_image_header_mark_offset,(uint8_t *)&new_address_offset,1);
		flash_cmd_read(next_new_empty_address+_image_header_mark_offset,(uint8_t *)&empty_address_offset,1);
		//if(previous_address_offset!=_image_state_is_empty && new_address_offset==_image_state_is_empty)break;
		if(new_address_offset==_image_state_is_empty)break;
	}

	previous_address_offset=((i) & _image_page_mark);
	new_address_offset=((i+1) & _image_page_mark);
	empty_address_offset=((i+2) & _image_page_mark);

	switch(image_info->EPD_size) {
	case EPD_144:
		image_info->previous_image_address=_image144_address(previous_address_offset);
		image_info->new_image_address=_image144_address(new_address_offset);
		//erase next space
		if(empty_address_offset!=_image_state_is_empty)
			erase_image(_image144_address(empty_address_offset),image_info->EPD_size);
		break;
	case EPD_190:
    case EPD_200:
    case EPD_260:
		image_info->previous_image_address=_image200_address(previous_address_offset);
		image_info->new_image_address=_image200_address(new_address_offset);
		//erase next space
		if(empty_address_offset!=_image_state_is_empty)
			erase_image(_image200_address(empty_address_offset),image_info->EPD_size);
		break;
	case EPD_270:
		image_info->previous_image_address=_image270_address(previous_address_offset);
		image_info->new_image_address=_image270_address(new_address_offset);
		//erase next space
		if(empty_address_offset!=_image_state_is_empty)
			erase_image(_image270_address(empty_address_offset),image_info->EPD_size);
		break;
	}
	if(image_info->extend_address.last_address!=_NULL_address)
		image_info->previous_image_address=image_info->extend_address.last_address;
}

/**
 * \brief Write image header to flash
 *
 * \param address The image address
 */
void write_mark(long address) {
	uint8_t mark_byte=_image_state_in_use;
	epd_spi_attach();
	CMD_PP(address+_image_header_mark_offset,&mark_byte,1);
}

/**
 * \brief Write ASCII data to canvas image of flash
 *
 * \param imgInfo use image_information_t structure
 * \param coordinate_X The location of horizontal of inputted string
 * \param coordinate_Y The location of vertical of inputted string
 * \param Text The pointer of inputted string
 */
 
void write_ascii(image_information_t imgInfo,uint16_t coordinate_X,
                 uint16_t coordinate_Y,char *Text) {
	uint16_t x,y;
    uint16_t XPoint,Xrem;
    long address_offset=0;
    Uint16_Byte_t uint16_B;
    uint8_t tmp[COG_line_Max_Size];
    uint8_t Text_val,bkText_val;
    uint8_t text_y,tmp2,char_index;
	epd_spi_attach();
    XPoint=(coordinate_X)/7;
    Xrem=(coordinate_X)%7;
    text_y=0;
    tmp2=~(_BV(8-Xrem)-1);
    for(y=0;y<COG_parameters[imgInfo.EPD_size].vertical_size;y++)
    {
        read_flash((imgInfo.previous_image_address+address_offset),tmp,
                   COG_parameters[imgInfo.EPD_size].horizontal_size);
        if(coordinate_Y<=y && y<(coordinate_Y+__TEXT_High))
        {
            for(x=0;x<__TEXT_Length;x++)
            {
            	uint16_B.Uint16_Data=0;
            	char_index=*(Text+x);
            	if(char_index>=127 || char_index<__ASCII_OFFSET)char_index=__ASCII_OFFSET;
                Text_val=ASCII_character_bitmaps[char_index-__ASCII_OFFSET][text_y];
                uint16_B.Hi_Byte=Text_val;
                if(Xrem!=0)
                {
                    if(x==0) bkText_val= tmp[(XPoint+x)];
                    uint16_B.Uint16_Data>>=Xrem;
                    uint16_B.Hi_Byte|=(tmp2 & bkText_val);
                    bkText_val=uint16_B.Low_Byte;
                 }
                tmp[(XPoint+x)]=uint16_B.Hi_Byte;
            }
            text_y++;
            if(Xrem!=0)
            {
            	tmp[(XPoint+x)]&=(_BV(8-Xrem)-1);
            	tmp[(XPoint+x)]|=(tmp2 & bkText_val);
            }
        }
        write_flash((imgInfo.new_image_address+address_offset),tmp,
                        COG_parameters[imgInfo.EPD_size].horizontal_size);      
        address_offset+=_flash_line_size;
    }
    
	
}

/**
 * \brief Update slideshow parameters
 *
 * \param slideshow_info The pointer address of slideshow information
 */
void write_slideshow_parameters(slideshow_information_t * slideshow_info) {
	uint8_t Result;
	epd_spi_attach();
	long addr=_parameters_address;
	do {
		flash_cmd_read(addr,(uint8_t *)&Result,1);
		if(addr>=_parameters_address_max) {
			addr=_parameters_address;
			CMD_SE(addr);
		}
		addr+=sizeof(slideshow_information_t);
	} while(Result!=0xFF);
	addr-=sizeof(slideshow_information_t);
	write_flash(addr,(uint8_t *)slideshow_info,sizeof(slideshow_information_t));
}

/**
 * \brief Read slideshow parameters from defined Flash segment
 *
 * \param slideshow_info The structure of slideshow information
 */
void read_slideshow_parameters(slideshow_information_t * slideshow_info) {
	uint8_t Result;
	long addr=_parameters_address;
	epd_spi_attach();
	do {
		/** Read parameters from address */
		flash_cmd_read(addr,(uint8_t *)&Result,1);
		addr+=sizeof(slideshow_information_t);
		if(Result==0xFF && addr==_parameters_address+sizeof(slideshow_information_t)) break;
	} while(Result!=0xFF); /*!< Do while the data byte is empty */
	/*!< Forward two data length is the last saved position of parameter address */
	addr-=(sizeof(slideshow_information_t)*2);
	flash_cmd_read(addr,(uint8_t *)slideshow_info,sizeof(slideshow_information_t));
}
