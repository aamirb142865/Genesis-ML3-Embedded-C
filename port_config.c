/* This file contains a function which
   configures all the ports required in TPMS*/
#include "tire_header.h"
void port_config()
{
    CLR_BIT(DDRD,PD2);  // Ignition Switch - Input
    SET_BIT(PORTD,PD2);  // Ignition Switch -  Active High
    SET_BIT(EIMSK,INT0);  // Enabling Interrupt for Ignition Switch
    SET_BIT(DDRD,PD4);  // Tire 1 Pressure Indicator - Output
    SET_BIT(DDRD,PD5);  // Tire 2 Pressure Indicator - Output
    SET_BIT(DDRD,PD6);  // Tire 3 Pressure Indicator - Output
    SET_BIT(DDRD,PD7);  // Tire 4 Pressure Indicator - Output
    SET_BIT(DDRB,PB0);  // Front Tires Temperature Indicator -  Output
    SET_BIT(DDRB,PB1);  // Rear Tires Temperature Indicator -  Output
    sei();  // Enable Global Interrupt
}

