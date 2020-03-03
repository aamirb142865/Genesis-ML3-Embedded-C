/* This file contains an ISR which is serviced when ignition is on*/
#include "tire_header.h"
ISR(INT0_vect)
{
    cli();
    flag.ignition = 1;
    sei();
}
