#include <msp430.h>
#include "Sensors.h"


unsigned short rightSensor(){
	unsigned short temp = 0;
	 // Configure P1.4 to be the ADC input
	ADC10CTL0 = 0;											// Turn off ADC subsystem
	ADC10CTL1 = 0;
	ADC10CTL1 = INCH_4 | ADC10DIV_3 ;						// Channel 4, ADC10CLK/4
	ADC10AE0 = BIT4;		 								// Make P1.4 analog input
	ADC10CTL0 = SREF_0 | ADC10SHT_3 | ADC10ON | ENC;		// Vcc & Vss as reference

	ADC10CTL0 |= ADC10SC;									// Start a conversion
	while(ADC10CTL1 & ADC10BUSY);							// Wait for conversion to complete
	temp = ADC10MEM;
	return (temp);

} // end infinite loop
unsigned short centerSensor(){
	unsigned short temp = 0;
	 // Configure P1.4 to be the ADC input
	ADC10CTL0 = 0;											// Turn off ADC subsystem
	ADC10CTL1 = 0;
	ADC10CTL1 = INCH_5 | ADC10DIV_3 ;						// Channel 4, ADC10CLK/4
	ADC10AE0 = BIT5;		 								// Make P1.4 analog input
	ADC10CTL0 = SREF_0 | ADC10SHT_3 | ADC10ON | ENC;		// Vcc & Vss as reference

	ADC10CTL0 |= ADC10SC;									// Start a conversion
	while(ADC10CTL1 & ADC10BUSY);							// Wait for conversion to complete
	temp = ADC10MEM;
	return (temp);

} // end infinite loop
unsigned short leftSensor(){
	unsigned short temp = 0;
	 // Configure P1.4 to be the ADC input
	ADC10CTL0 = 0;											// Turn off ADC subsystem
	ADC10CTL1 = 0;
	ADC10CTL1 = INCH_3 | ADC10DIV_3 ;						// Channel 4, ADC10CLK/4
	ADC10AE0 = BIT3;		 								// Make P1.4 analog input
	ADC10CTL0 = SREF_0 | ADC10SHT_3 | ADC10ON | ENC;		// Vcc & Vss as reference

	ADC10CTL0 |= ADC10SC;									// Start a conversion
	while(ADC10CTL1 & ADC10BUSY);							// Wait for conversion to complete
	temp = ADC10MEM;
	return (temp);

} // end infinite loop
