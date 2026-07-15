#include <msp430.h>
#include <inc/mainheader.h>

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

void reset_led()
{
    led1.goal_red = 255;
    led1.goal_green =0;
    led1.goal_blue = 0;
    led2.goal_red = 0;
    led2.goal_green =0;
    led2.goal_blue = 0;
    led3.goal_red = 0;
    led3.goal_green = 0;
    led3.goal_blue = 0;
}
