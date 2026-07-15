#include <msp430.h> 
#include <stdlib.h>
#include "inc/mainheader.h"
#include "inc/updatefuncs.h"

//current led mode variables
int mode = 1;
int status = 1;

#pragma vector = TIMER0_A1_VECTOR
__interrupt void update_timer_0(void)
{
   update_red();

   TA0CTL &= ~TAIFG;
   return;
}

#pragma vector = TIMER1_A1_VECTOR
__interrupt void update_timer_1(void)
{
   update_blue();
   update_green();

   TA1CTL &= ~TAIFG;
   return;
}

#pragma vector = PORT1_VECTOR
__interrupt void button()
{
    mode++;
    P1IFG = 0;
    if (mode == 5)
    {
        mode = 1;
    }

    switch (mode)
    {
    case 1:
        reset_led();
        status = (rand()%3)+1;
        break;
    case 2:
        led1.red = 255;
        led1.green = 0;
        led1.blue = 0;
        status = (rand()%3)+1;
        break;
    case 3:
        status = (rand()%4)+1;
        break;
    case 4:
        status = (rand()%3)+1;
        break;
    }
    return;
}

/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer

    //set clock speed to 1mhz
    BCSCTL1 = CALBC1_16MHZ; // Set range
    DCOCTL = CALDCO_16MHZ;  // Set DCO step + modulation

	/*
	 * timer A0/1 setup as pwm generators, using smclk as clock
	 */


	//timer 0
	TA0CTL = TASSEL_2 | MC_1 | TAIE;
	TA0CCTL1 = OUTMOD_7;
	TA0CCR0 = 255;
	red = 0;

	//timer 1
	TA1CTL = TASSEL_2 | MC_1 | TAIE;
	TA1CCTL1 = OUTMOD_7;
	TA1CCTL2 = OUTMOD_7;
	TA1CCR0 = 255;
	green = 0;
	blue = 0;


    /*
     *pin setups
     */

	//led enable
	P1DIR |= BIT0 | BIT1 | BIT2;
	P1OUT = 0;
	P1REN |= BIT3;
	P1IE |= BIT3;

	//pwm out
	P1SEL |= BIT6;
	P2SEL |= BIT6 | BIT1 | BIT2 | BIT4 | BIT5;
	P2SEL &= ~BIT7;
    P3SEL |= BIT5 | BIT2 |BIT3;

	__enable_interrupt();
	led1.red = 255;
	led1.goal_red = 255;
	while(1)
	{
	    switch (mode)
	    {
	    case 1:
            switch (status)
            {
            case 1:
                sync_rainbow();
                break;
            case 2:
                async_rainbow();
                break;
            case 3:
                rainbow_top_to_bottom();
                break;
            }
            break;
	    case 2:
            switch (status)
            {
            case 1:
                chase();
                break;
            case 2:
                random_chase();
                break;
            case 3:
                color_chase();
                break;
            }
            break;
	    case 3:
            switch (status)
            {
            case 1:
                random_breath();
                break;
            case 2:
                sync_random_breath();
                break;
            case 3:
                async_random_breath();
                break;
            case 4:
                color_random_breath();
                break;
            }
            break;
	    case 4:
            switch (status)
            {
            case 1:
                random();
                break;
            case 2:
                async_random();
                break;
            case 3:
                sync_random();
                break;
            }
            break;
	    }
	}
	return 0;
}
