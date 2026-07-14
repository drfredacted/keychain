#include <msp430.h> 
//#include <stdio.h>
#include <stdlib.h>
#include "inc/updatefuncs.h"
#include "inc/mainheader.h"


#pragma vector = TIMER0_A1_VECTOR
__interrupt void update_timer_0(void)
{
   update_red();

   TA0CTL &= ~TAIFG;
}

#pragma vector = TIMER1_A1_VECTOR
__interrupt void update_timer_1(void)
{
   update_blue();
   update_green();

   TA1CTL &= ~TAIFG;
}

#pragma vector = PORT1_VECTOR
__interrupt void button()
{
    state++;

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
	while(1)
	{
	    random_breath();
	}
	return 0;
}
