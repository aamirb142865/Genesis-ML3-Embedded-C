/*
Milestone 3
Topic: Tire Pressure Monitoring System
Name: AAMIR SUHAIL BURHAN
ID: 142865
Version: 1.0

Requirements:
        4 Pressure Sensors:     Input Voltage - (2.1 to 3.3V)
                                Input Pressure Range (100 to 1300kPa) -> (14 to 188psi)
                                Ideal Front Tire Pressure  (26 to 35psi) For Tire 1 & 2  (2.185V-2.25V)
                                Ideal Rear Tire Pressure  (25 to 33psi) For Tire 3 & 4   (2.18V-2.235V)

        Temperature Sensors:    Input Voltage -  (2.1 - 3.6V)
                                Input Temperature Range (-4 to 158 Fahrenheit)
                                Ideal Temperature Range (70 to 100 Fahrenheit)  (2.8-3.065V)

        Ignition Switch:        Used to switch on and off the system

        4 Pressure LEDs:        Used to indicate abnormal Pressure in the tires
        2 Temperature LEDs:     Used to indicate abnormal Temperature in the front tires
                                and rear tires
 */
#include "tire_header.h"
void port_config(void);  // Function for configuring all the ports used
void sample(void);  // Function for finding sensor values and displaying output
void off(void);  // Function which contains actions taken when ignition is switched off
int main(void)
{
    port_config();
    flag.ignition = 1;
    while(1)
    {
        if(flag.ignition == 1)
        {
            while(!(PIND & (1<<PD2)))
            {
                sample();
            }
            flag.ignition = 0;
        }
        else
        {
            off();
        }
    }
    return 0;
 }
