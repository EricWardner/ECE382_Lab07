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
###Sensor Test
Emmiter test: Viewing the IR emmitters with my cell phone camera showed that they all turned on and sent something out.

The test for the sensors was done by first wiring up the emitter to 5v and ground then attaching a multimeter to the sensor port and ground. I then put the robot in an open area to get the 

|Sensor |  Min  |  Max |Threshold|
|:-------:|:-------:|:-------:|:-------:|
|Left   |.300v|4.8v|1.0v-2.0v|
|Center|.300v|4.8v|1.0v-2.0v|
|Right|.300v|4.8v|1.0v-2.0v|

-What are good reference values??
    -test with multimeter and piece of paper, create chart, convert chart using the proportion

###Setup of ADC10
-what registers

-which bits in registers are important

-whats the init sequence
###Hardware Setup
-which ADC10 channels will be used?

-which pins correspond to those channels?

###Code Ideas
-block or use interrupts?

-convert one sensor at a time or multiple?
