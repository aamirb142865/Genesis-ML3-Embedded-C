/* This file contains all the required header files,
   structures and global variables*/
#ifndef TIRE_HEADER_H_INCLUDED
#define TIRE_HEADER_H_INCLUDED
#include<avr/interrupt.h>
#include <avr/io.h>
struct {
        unsigned int ignition:1;}flag;  // Ignition Flag for interrupt control
#define SET_BIT(PORT,BIT) PORT|=(1<<BIT)
#define CLR_BIT(PORT,BIT) PORT&=~(1<<BIT)
unsigned volatile int adc0;    // Tire 1 Pressure ADC value
unsigned volatile int adc1;    // Tire 2 Pressure ADC value
unsigned volatile int adc2;    // Tire 3 Pressure ADC value
unsigned volatile int adc3;    // Tire 4 Pressure ADC value
unsigned volatile int adc4;    // Front Tires Temperature ADC value
unsigned volatile int adc5;    // Rear Tires Temperature ADC value
#endif //

