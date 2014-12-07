//-----------------------------------------------------------------
// Name:	Coulston
// File:	lab7.c
// Date:	Fall 2014
// Purp:	Collect analog samples from P1.3 and P1.4
//-----------------------------------------------------------------
#include "msp430g2553.h"
#include "Sensors.h"

void initMSP430();

//----------------------------------------------------------------------
//----------------------------------------------------------------------
int main(void) {

	unsigned short right = 0;
	unsigned short left = 0;
	unsigned short center = 0;

	IFG1=0; 													// clear interrupt flag1
	WDTCTL = WDTPW + WDTHOLD;									// disable WDT

	BCSCTL1 = CALBC1_8MHZ;										// 8MHz clock
	DCOCTL = CALDCO_8MHZ;

	P1DIR = BIT0|BIT6;												// Set the red LED as output
	P1OUT &= ~(BIT0|BIT6);

	while(1){
		// Configure P1.1 to be the ADC input (Left)
		left = leftSensor();
		if (left > 0x0200)	P1OUT |= BIT0;
		else					P1OUT &= ~BIT0;

		right = rightSensor();
		if (right > 0x0200)	P1OUT |= BIT6;
		else					P1OUT &= ~BIT6;

		center = centerSensor();
		if (center > 0x0200)	P1OUT |= (BIT0|BIT6);
		else					P1OUT &= ~(BIT0|BIT6);
	}

} // end main
