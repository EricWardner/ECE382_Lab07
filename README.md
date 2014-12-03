ECE382_Lab07
============
## Table of Contents ##
- [Introduction](#introduction)
- [Pre-lab](#pre-lab)
    - [Useful Information](#useful-information)
    - [Sensor Test](#sensor-test)
    - [Setup of ADC10](#setup-of-adc10)
    - [Hardware Setup](#hardwaressetup)
    - [Code Ideas](#code-ideas)

##Introduction
The purpose of this lab was to implement the analog to digital converters n the MSP430 so that it could read and interpret signals from the robot's 3 IR detectors/emitters

[Lab Link](http://ece382.com/labs/lab7/)

##Pre-Lab

###Useful Information
<ul>
<li>You must provide 5V and ground to the IR sensors!</li>
<li>Be mindful of loading!<ul>
<li>To combat it, sample as slowly as possible</li>
</ul>
</li>
<li>Be sure you write a quality header/implementation file so you can easily import this code for the maze competition.</li>
<li>You may want to use your moving average library to smooth the output from your sensors.</li>
</ul>

"With few exceptions the ADC10 control bits can only be modified when ENC = 0. ENC must be set to 1 before any conversion can take place." -tech docs

[lab7.c](http://ecse.bd.psu.edu/cmpen352/lecture/code/lec36.c)

###Sensor Test
Emmiter test: Viewing the IR emmitters with my cell phone camera showed that they all turned on and sent something out.

The test for the sensors was done by first wiring up the emitter to 5v and ground then attaching a multimeter to the sensor port and ground. I then put the robot in an open area to get the min value and up against the wall to get a max value. The threshold was taken from 2 inches away from the wall and far enough back so that readings were still sensitive. There seemed to be a certain lower threshold usually just below 1v where reading weren't very accurate and jumped around (could be noise). 

|Sensor |  Min  |  Max |Threshold|
|:-------:|:-------:|:-------:|:-------:|
|Left   |.200v|4.8v|0.95v-2.5v|
|Center|.300v|4.6v|0.8v-1.7v|
|Right|.317v|4.82v|0.6v-1.97v|


###Setup of ADC10
"The ADC10 module supports fast, 10-bit analog-to-digital conversions. The module implements a 10-bit SAR core, sample select control, reference generator, and data transfer controller (DTC)."

######what registers will be used?

ADC10CTL0

ADC10CTL1

ADC10AE0

ADC10MEM

ADC10BUSY

######which bits in registers are important

ADC10SHTx: Sample and hold time

SREF_0: Vcc & Vss as reference

ADC10ON: Turns it on

ENC: Enable conversion

ADC10SC: Start conversion


######What is the init sequence?
Dr. Coulston provided code in lab7.c

```C
ADC10CTL0 = 0;											// Turn off ADC subsystem
ADC10CTL1 = INCH_4 | ADC10DIV_3 ;						// Channel 4, ADC10CLK/4
ADC10AE0 = BIT4;		 								// Make P1.4 analog input
ADC10CTL0 = SREF_0 | ADC10SHT_3 | ADC10ON | ENC;		// Vcc & Vss as reference
```

###Hardware Setup
######which ADC10 channels will be used?

Most likely channels 4, 3, and 2 will be used.

######which pins correspond to those channels?

P1.4 - channel 4

P1.3 - channel 3

P1.2 - channel 2

###Code Ideas
######block or use interrupts?

I think it will be a good idea to use interrupts and just cycle through each reading really fast. The tech doc already provides guidance on the ADC10 interrupts.

######convert one sensor at a time or multiple?

One sensor at a time. The code will be simpler.
