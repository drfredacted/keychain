#include <inc/mainheader.h>
#include <msp430.h>

void toggle_led (int led, int state)
{
    if (led == 1)
    {
        if (state == 0)
        {
            P1OUT |= BIT0;
        }
        else
        {
            P1OUT &= ~BIT0;
        }
    }
    else if (led == 2)
    {
        if (state == 0)
        {
            P1OUT |= BIT1;
        }
        else
        {
            P1OUT &= ~BIT1;
        }
    }
    else if (led == 3)
    {
        if (state == 0)
        {
            P1OUT |= BIT2;
        }
        else
        {
            P1OUT &= ~BIT2;
        }
    }
}
