/*This file contains two functions:

  sample(): Finds out the sensor values with the help of
            the ADC module and takes appropriate action
            based on the values observed

  off():    It is used to represent ignition off. It clears
            all the output ports and disables the ADC module
*/
#include "tire_header.h"
void sample()
{
    ADMUX&=0x00;   //ADC Configuration for ADC0
    SET_BIT(ADMUX,REFS0);
    SET_BIT(ADCSRA,ADEN);
    SET_BIT(ADCSRA,ADSC);
    while(ADCSRA & (1 << ADSC));   // Sampling ADC0
    adc0 = ADC;
    CLR_BIT(ADCSRA,ADSC);
    SET_BIT(ADMUX,MUX0);   // ADC Configuration for ADC1
    SET_BIT(ADCSRA,ADSC);
    while(ADCSRA & (1 << ADSC));   // Sampling ADC1
    adc1 = ADC;
    CLR_BIT(ADCSRA,ADSC);
    CLR_BIT(ADMUX,MUX0);   // ADC Configuration for ADC2
    SET_BIT(ADMUX,MUX1);
    SET_BIT(ADCSRA,ADSC);
    while(ADCSRA & (1 << ADSC));   // Sampling ADC2
    adc2 = ADC;
    CLR_BIT(ADCSRA,ADSC);
    SET_BIT(ADMUX,MUX0);   // ADC Configuration for ADC3
    SET_BIT(ADCSRA,ADSC);
    while(ADCSRA & (1 << ADSC));   // Sampling ADC3
    adc3 = ADC;
    CLR_BIT(ADCSRA,ADSC);  // Stop ADC conversion
    CLR_BIT(ADCSRA,ADEN);  // Disable ADC Module
    if((adc0 < 447) || (adc0 > 461))    // 465 - 25psi, 480 - 35 psi
        SET_BIT(PORTD,PD4);
    else
        CLR_BIT(PORTD,PD4);
    if((adc1 < 447) || (adc1 > 461))
        SET_BIT(PORTD,PD5);
    else
        CLR_BIT(PORTD,PD5);
    if((adc2 < 446) || (adc2 > 458))    // 464 - 24psi, 475 - 33psi
        SET_BIT(PORTD,PD6);
    else
        CLR_BIT(PORTD,PD6);
    if((adc3 < 446) || (adc3 > 458))
        SET_BIT(PORTD,PD7);
    else
        CLR_BIT(PORTD,PD7);
    ADMUX&=0x00;   //ADC Reset
    SET_BIT(ADMUX,REFS0);
    SET_BIT(ADCSRA,ADEN);
    SET_BIT(ADMUX,MUX2);
    SET_BIT(ADCSRA,ADSC);
    while(ADCSRA & (1 << ADSC));   // Sampling ADC4
    adc4 = ADC;
    CLR_BIT(ADCSRA,ADSC);
    SET_BIT(ADMUX,MUX0);   // ADC Configuration for ADC3
    SET_BIT(ADCSRA,ADSC);
    while(ADCSRA & (1 << ADSC));   // Sampling ADC5
    adc5 = ADC;
    CLR_BIT(ADCSRA,ADSC);  // Stop ADC conversion
    CLR_BIT(ADCSRA,ADEN);  // Disable ADC Module
    if((adc4 < 573) || (adc4 > 628))    // For Front Tires (563 - 70 F, 620 - 100F)
        SET_BIT(PORTB,PB0);
    else
        CLR_BIT(PORTB,PB0);
    if((adc5 < 573) || (adc5 > 628))    // For Rear Tires
        SET_BIT(PORTB,PB1);
    else
        CLR_BIT(PORTB,PB1);
}
void off()
{
    ADMUX&=0x00;
    CLR_BIT(PORTD,PD4);  // Clear all outputs when ignition is off
    CLR_BIT(PORTD,PD5);
    CLR_BIT(PORTD,PD6);
    CLR_BIT(PORTD,PD7);
    CLR_BIT(PORTB,PB0);
    CLR_BIT(PORTB,PB1);
    CLR_BIT(ADCSRA,ADEN);  // Disable ADC
    CLR_BIT(ADCSRA,ADSC);
}

