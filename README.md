ECE382_Lab07
============
## Table of Contents ##
- [Introduction](#introduction)
- [Pre-lab](#Pre-lab)
    - [Useful Information](#Useful Information)
    - [Sensor Test](#Sensor Test)
    - [Setup of ADC10](#Setup of ADC10)
    - [Hardware setup](#Hardware setup)
    - [Code ideas](#Code ideas)

##Introduction
The purpose of this lab was to implement the analog to digital converters n the MSP430 so that it could read and interpret signals from the robot's 3 IR detectors/emitters

[Lab Link](http://ece382.com/labs/lab7/)

##Pre-Lab

###Useful Information
To-do
###Sensor Test
-Maybe add video ofsensor test. Will test using cell phone camera. Digital cameras pick up light in the infa red spectrum. It shows up as purple
-What are good reference values?? To-do/to-understand
###Setup of ADC10
-what registers
-which bits in registers are important
-whats the init sequence
###Hardware setup
-which ADC10 channels will be used?
-which pins correspond to those channels?
###Code ideas
-block or use interrupts?
-convert one sensor at a time or multiple?
