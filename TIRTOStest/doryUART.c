/*
 * doryUART.c
 *
 *  Created on: May 25, 2015
 *      Author: vagrant
 */


#include "doryUART.h"
#include <msp430.h>
//#include "Board.h"

char a[5][100];
char flag=0;
int col=0;
int line=0;
int last_char[5];



void doryUARTinit()
{
	//WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
	  P3SEL = BIT3+BIT4;                        // P3.4,5 = USCI_A0 TXD/RXD
	  UCA0CTL1 |= UCSWRST;                      // **Put state machine in reset**
	  UCA0CTL1 |= UCSSEL_2;                     // SMCLK
	  UCA0BR0 = 6;                              // 1MHz 9600 (see User's Guide)
	  UCA0BR1 = 0;                              // 1MHz 9600
	  UCA0MCTL = UCBRS_0 + UCBRF_13 + UCOS16;   // Modln UCBRSx=0, UCBRFx=0,
	                                            // over sampling
	  UCA0CTL1 &= ~UCSWRST;                     // **Initialize USCI state machine**
	  UCA0IE |= UCRXIE;                         // Enable USCI_A0 RX interrupt

	  //__bis_SR_register(LPM0_bits + GIE);       // Enter LPM0, interrupts enabled
	  __bis_SR_register(GIE);       // Enter LPM0, interrupts enabled
	  __no_operation();                         // For debugger
}



Void doryUARTfxn(UArg argument)
{
	switch(__even_in_range(UCA0IV,4))
	  {
	  case 0:break;                             // Vector 0 - no interrupt
	  case 2:                                   // Vector 2 - RXIFG
		 a[line][col] = UCA0RXBUF;                  // read RXed character
		 if (a[line][col] == LINE_FEED || col>98)
		 {
			 last_char[line]=col;
			 if(line<4)
			 {
				 line++;
			 }
			 else
			 {
				 line=0;
				 flag=1;
			 }
			 col=0;
		 }
		 else
		 {
			 col++;
		 }
	    break;
	  case 4:break;                             // Vector 4 - TXIFG
	  default: break;
	  }
}

char doryUARTtask()
{
	char returnvalue=flag;
	if(flag)
	{
		System_printf("UART flag set");
		flag=0;
	}
	UCA0IE |= UCRXIE;                         // Enable USCI_A0 RX interrupt
	return returnvalue;
}
