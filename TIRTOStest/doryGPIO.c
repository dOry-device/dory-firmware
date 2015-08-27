/*
 * doryGPIO.c
 *
 *  Created on: Aug 27, 2015
 *      Author: vagrant
 */

#include "doryGPIO.h"

void dory_GPIO_init()
{
    /* install Button callback */
 //   GPIO_setCallback(Board_BUTTON0, btn0_isr);

    /* Enable interrupts */
    GPIO_enableInt(Board_BUTTON0);

    /* install Button callback */
   // GPIO_setCallback(Board_BUTTON1, btn1_isr);

    /* Enable interrupts */
    GPIO_enableInt(Board_BUTTON1);


    /* install Button callback */
   // GPIO_setCallback(Board_BUTTON2, btn2_isr);

    /* Enable interrupts */
    GPIO_enableInt(Board_BUTTON2);

    /* install Button callback */
 //   GPIO_setCallback(Board_BUTTON3, btn3_isr);

    /* Enable interrupts */
    GPIO_enableInt(Board_BUTTON3);


}


void port1_isr()
{
	switch( P1IV ) {
	        case P1IV_NONE:   break;                               // None
	        case P1IV_P1IFG0:                                      // Pin 0 (btn0)
	        	System_printf("btn0\n");
	        	GPIO_clearInt(Board_BUTTON0);
	            break;
	        case P1IV_P1IFG1:                                       // Pin 1 (button 1)
	        	System_printf("btn1\n");
	        	GPIO_clearInt(Board_BUTTON1);
	             break;
	        case P1IV_P1IFG2:                                       // Pin 2
	        	System_printf("btn2\n");
	        	GPIO_clearInt(Board_BUTTON2);
	             break;
	        case P1IV_P1IFG3:                                       // Pin 3
	        	System_printf("btn3\n");
	        	GPIO_clearInt(Board_BUTTON3);
	             break;
	        case P1IV_P1IFG4:                                       // Pin 4
	        	__no_operation();
	             break;
	        case P1IV_P1IFG5:                                       // Pin 5
	             __no_operation();
	             break;
	        case P1IV_P1IFG6:                                       // Pin 6
	             __no_operation();
	             break;
	        case P1IV_P1IFG7:                                       // Pin 7
	             __no_operation();
	             break;
	        default:   break;
	    }


	System_printf("port1\n");
	System_flush();
}

void btn0_isr()
{
	System_printf("btn0\n");
	System_flush();
}


void btn1_isr()
{
	System_printf("btn1\n");
	System_flush();
}

void btn2_isr()
{
	System_printf("btn2\n");
	System_flush();
}

void btn3_isr()
{
	System_printf("btn3\n");
	System_flush();
}
