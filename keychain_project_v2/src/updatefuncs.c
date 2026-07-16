#include <msp430.h>
#include <stdlib.h>
#include "inc/mainheader.h"
#include "inc/updatefuncs.h"


//make all leds equal
void equalize()
{
    led2.red = led3.red = led1.red;
    led2.blue = led3.blue = led1.blue;
    led2.green = led3.green = led1.green;
}

void offset1()
{
    led2.red = led3.blue = led1.green;
    led2.blue = led3.green = led1.red;
    led2.green = led3.red = led1.blue;
}

void offset2()
{
    led2.red = led3.red = led1.green;
    led2.blue = led3.blue = led1.red;
    led2.green = led3.green = led1.blue;
}


/*
 * misc functions
 */


//function to make rgb value for led 1 random
void random_1()
{
    led1.red = rand()%255;
    led1.green = rand()%255;
    led1.blue = rand()%255;

    // 1/4 chance to disable one of the rgb value's, this increases the average saturation of generated colors
    switch (rand()%4)
    {
    case 0:
        led1.red = 0;
        break;
    case 1:
        led1.green = 0;
        break;
    case 2:
        led1.blue = 0;
        break;
    case 3:
        break;
    }
}

//code to make all leds have a random rgb value
void random_all()
{

    led1.red = rand()%255;
    led1.green = rand()%255;
    led1.blue = rand()%255;

    switch (rand()%4)
    {
    case 0:
        led1.red = 0;
        break;
    case 1:
        led1.green = 0;
        break;
    case 2:
        led1.blue = 0;
        break;
    case 3:
        break;
    }


    led2.red = rand()%255;
    led2.green = rand()%255;
    led2.blue = rand()%255;

    switch (rand()%4)
    {
    case 0:
        led2.red = 0;
        break;
    case 1:
        led2.green = 0;
        break;
    case 2:
        led2.blue = 0;
        break;
    case 3:
        break;
    }


    led3.red = rand()%255;
    led3.green = rand()%255;
    led3.blue = rand()%255;

    switch (rand()%4)
    {
    case 0:
        led3.red = 0;
        break;
    case 1:
        led3.green = 0;
        break;
    case 2:
        led3.blue = 0;
        break;
    case 3:
        break;
    }
}

//code to make rgb goal of led1 random
void random_1_goal()
{

    led1.goal_red = rand()%255;
    led1.goal_green = rand()%255;
    led1.goal_blue = rand()%255;

    switch (rand()%4)
    {
    case 0:
        led1.goal_red = 0;
        break;
    case 1:
        led1.goal_green = 0;
        break;
    case 2:
        led1.goal_blue = 0;
        break;
    case 3:
        break;
    }
}

//code to make all rgb goals random
void random_all_goal()
{

    led1.goal_red = rand()%255;
    led1.goal_green = rand()%255;
    led1.goal_blue = rand()%255;

    switch (rand()%4)
    {
    case 0:
        led1.goal_red = 0;
        break;
    case 1:
        led1.goal_green = 0;
        break;
    case 2:
        led1.goal_blue = 0;
        break;
    case 3:
        break;
    }

    led2.goal_red = rand()%255;
    led2.goal_green = rand()%255;
    led2.goal_blue = rand()%255;

    switch (rand()%4)
    {
    case 0:
        led2.goal_red = 0;
        break;
    case 1:
        led2.goal_green = 0;
        break;
    case 2:
        led2.goal_blue = 0;
        break;
    case 3:
        break;
    }

    led3.goal_red = rand()%255;
    led3.goal_green = rand()%255;
    led3.goal_blue = rand()%255;

    switch (rand()%4)
    {
    case 0:
        led3.goal_red = 0;
        break;
    case 1:
        led3.goal_green = 0;
        break;
    case 2:
        led3.goal_blue = 0;
        break;
    case 3:
        break;
    }
}

/* _          _                       _
| |        | |                     | |
| | ___  __| |  _ __ ___   ___   __| | ___  ___
| |/ _ \/ _` | | '_ ` _ \ / _ \ / _` |/ _ \/ __|
| |  __/ (_| | | | | | | | (_) | (_| |  __/\__ \
|_|\___|\__,_| |_| |_| |_|\___/ \__,_|\___||___/
*/

/*
 * chase
 */

//normal chase
void chase()
{
    static long long delay = 0;
    delay++;
    offset1();
    if (delay == 30000)
    {
        delay = 0;

        int bluetemp = led1.blue;
        int greentemp = led1.green;
        int redtemp = led1.red;

        led1.red = greentemp;
        led1.green = bluetemp;
        led1.blue = redtemp;
    }
}

//random chase
void random_chase()
{
    static long long delay = 0;
    static int loops = 0;
    delay++;
    offset1();
    if (delay == 30000)
    {
        delay = 0;
        loops++;

        if (loops == 6)
        {
            loops = 0;
            random_1();
        }

        int bluetemp = led1.blue;
        int greentemp = led1.green;
        int redtemp = led1.red;

        led1.red = greentemp;
        led1.green = bluetemp;
        led1.blue = redtemp;
    }
}

//random chase
void color_chase()
{
    static long long delay = 0;
    static int loops = 0;
    delay++;
    offset1();
    if (delay == 30000)
    {
        delay = 0;
        loops++;

        if (loops == 3)
        {
            loops = 0;
            led1.red = rand()%255;
        }

        int bluetemp = led1.blue;
        int greentemp = led1.green;
        int redtemp = led1.red;

        led1.red = greentemp;
        led1.green = bluetemp;
        led1.blue = redtemp;
    }
}

/*
 * random switching
 */

//sync random
void sync_random()
{
    static long long delay = 0;
    delay++;
    equalize();
    if(delay == 30000)
    {
        delay = 0;
        random_1();
    }
}

//async random
void async_random()
{
    static long long delay = 0;
    delay++;
    offset1();
    if(delay == 30000)
    {
        delay = 0;
        random_1();
    }
}

//all random
void random()
{
    static long long delay = 0;
    delay++;
    if (delay == 100000)
    {
        delay = 0;
        random_all();
    }
}


/*
 * random breathing
 */

//all random
void random_breath()
{
    static long long delay = 0;
    delay++;
    if (delay == 1000)
    {
        delay = 0;
        interpolate();
        if ( led1.goal_red == led1.red & led1.goal_green == led1.green & led1.goal_blue == led1.blue & led2.goal_red == led2.red & led2.goal_green == led2.green & led2.goal_blue == led2.blue & led3.goal_red == led3.red & led3.goal_green == led3.green & led3.goal_blue == led3.blue )
        {
            random_all_goal();
        }
    }
}

//sync random
void sync_random_breath()
{
    static long long delay = 0;
    delay++;
    equalize();
    if (delay == 1000)
    {
        delay = 0;
        interpolate1();

        if (led1.goal_red == led1.red & led1.goal_green == led1.green & led1.goal_blue == led1.blue)
        {
            random_1_goal();
        }
    }
}

//async random
void async_random_breath()
{
    static long long delay = 0;
    delay++;
    offset1();
    if (delay == 1000)
    {
        delay = 0;
        interpolate1();

        if (led1.goal_red == led1.red & led1.goal_green == led1.green & led1.goal_blue == led1.blue)
        {
            random_1_goal();
        }
    }
}

//random per color
void color_random_breath()
{
    static long long delay = 0;
    delay++;
    if (delay == 1000)
    {
        delay = 0;
        interpolate();

        if (led1.goal_red == led1.red)
        {
            led1.goal_red = rand()%255;
        }
        if (led1.goal_green == led1.green)
        {
            led1.goal_green = rand()%255;
        }
        if (led1.goal_blue == led1.blue)
        {
            led1.goal_blue = rand()%255;
        }


        if (led2.goal_red == led2.red)
        {
            led2.goal_red = rand()%255;
        }
        if (led2.goal_green == led2.green)
        {
            led2.goal_green = rand()%255;
        }
        if (led2.goal_blue == led2.blue)
        {
            led2.goal_blue = rand()%255;
        }


        if (led3.goal_red == led3.red)
        {
            led3.goal_red = rand()%255;
        }
        if (led3.goal_green == led3.green)
        {
            led3.goal_green = rand()%255;
        }
        if (led3.goal_blue == led3.blue)
        {
            led3.goal_blue = rand()%255;
        }
    }
}

/*
 * rainbow
 */

//rainbow function
void rainbow()
{
    //r -> rg
    if ((led1.red == 255) & (led1.green == 0) & (led1.blue == 0))
    {
        led1.goal_green = 255;
    }

    //rg -> g
    if ((led1.red == 255) & (led1.green == 255) & (led1.blue == 0))
    {
        led1.goal_red = 0;
    }

    //g -> gb
    if ((led1.red == 0) & (led1.green == 255) & (led1.blue == 0))
    {
        led1.goal_blue = 255;
    }

    //gb -> b
    if ((led1.red == 0) & (led1.green == 255) & (led1.blue == 255))
    {
        led1.goal_green = 0;
    }

    //b -> rb
    if ((led1.red == 0) & (led1.green == 0) & (led1.blue == 255))
    {
        led1.goal_red = 255;
    }

    //rb -> r
    if ((led1.red == 255) & (led1.green == 0) & (led1.blue == 255))
    {
        led1.goal_blue = 0;
    }
}

//Synchronous
void sync_rainbow()
{
    static long long delay = 0;
    equalize();
     delay++;
    if (delay == 1000)
    {
        delay = 0;
        interpolate1();
        rainbow();
    }
}

//async
void async_rainbow()
{
    static long long delay = 0;
    delay++;
    offset1();
    if (delay == 300)
    {
        delay = 0;
        interpolate1();
        rainbow();
    }
}

//top to bottom
void rainbow_top_to_bottom()
{
    static long long delay = 0;
    delay++;
    offset2();
    if (delay == 300)
    {
        delay = 0;
        interpolate1();
        rainbow();
    }
}

/*
 * interpolating mode code
 */

//code to interpolate rgb value's for led 1 towards their goal
void interpolate1()
{
    //red

    //if goal_red is bigger then red, increment red
    if (led1.goal_red > led1.red)
    {
        led1.red++;
    }
    //if goal_red is smaller then red, decrement red
    else if (led1.goal_red < led1.red)
    {
        led1.red--;
    }

    //green

    //if goal_green is bigger then green, increment green
    if (led1.goal_green > led1.green)
    {
        led1.green++;
    }
    //if goal_green is smaller then green, decrement green
    else if (led1.goal_green < led1.green)
    {
        led1.green--;
    }

    //blue

    //if goal_blue is bigger then blue, increment blue
    if (led1.goal_blue > led1.blue)
    {
        led1.blue++;
    }
    //if goal_blue is smaller then blue, decrement blue
    else if (led1.goal_blue < led1.blue)
    {
        led1.blue--;
    }
}


//code to interpolate rgb value's for all leds towards their goal
void interpolate()
{
    /*
     * LED 1
     */

    //red
    if (led1.goal_red > led1.red)
    {
        led1.red++;
    }
    else if (led1.goal_red < led1.red)
    {
        led1.red--;
    }

    //green
    if (led1.goal_green > led1.green)
    {
        led1.green++;
    }
    else if (led1.goal_green < led1.green)
    {
        led1.green--;
    }

    //blue
    if (led1.goal_blue > led1.blue)
    {
        led1.blue++;
    }
    else if (led1.goal_blue < led1.blue)
    {
        led1.blue--;
    }


    /*
     * LED 2
     */

    //red
    if (led2.goal_red > led2.red)
    {
        led2.red++;
    }
    else if (led2.goal_red < led2.red)
    {
        led2.red--;
    }

    //green
    if (led2.goal_green > led2.green)
    {
        led2.green++;
    }
    else if (led2.goal_green < led2.green)
    {
        led2.green--;
    }

    //blue
    if (led2.goal_blue > led2.blue)
    {
        led2.blue++;
    }
    else if (led2.goal_blue < led2.blue)
    {
        led2.blue--;
    }


    /*
     * LED 3
     */

    //red
    if (led3.goal_red > led3.red)
    {
        led3.red++;
    }
    else if (led3.goal_red < led3.red)
    {
        led3.red--;
    }

    //green
    if (led3.goal_green > led3.green)
    {
        led3.green++;
    }
    else if (led3.goal_green < led3.green)
    {
        led3.green--;
    }

    //blue
    if (led3.goal_blue > led3.blue)
    {
        led3.blue++;
    }
    else if (led3.goal_blue < led3.blue)
    {
        led3.blue--;
    }
    return;
}


/*
_          _                   _ _   _       _           _                             _
| |        | |                 | | | (_)     | |         (_)                           | |
| | ___  __| |  _ __ ___  _   _| | |_ _ _ __ | | _____  ___ _ __   __ _    ___ ___   __| | ___
| |/ _ \/ _` | | '_ ` _ \| | | | | __| | '_ \| |/ _ \ \/ / | '_ \ / _` |  / __/ _ \ / _` |/ _ \
| |  __/ (_| | | | | | | | |_| | | |_| | |_) | |  __/>  <| | | | | (_| | | (_| (_) | (_| |  __/
|_|\___|\__,_| |_| |_| |_|\__,_|_|\__|_| .__/|_|\___/_/\_\_|_| |_|\__, |  \___\___/ \__,_|\___|
                                      | |                         __/ |
                                      |_|                        |___/
 */

/*
 * red update functions
 */

void update_red()
{
    static int sel_led_r = 1;
    static int state_r = 0;
    state_r++;
       //if state reaches 1 before the led switch, turn the red pwm to 0 to avoid bleed over into next led
       if (state_r == 99)
       {
           red = 0;
       }

       //when 100 cycles are completed, switch to the next led
       if (state_r == 100)
       {
           state_r = 0;
           if(sel_led_r == 1)
           {
               red_3(0);
               red = led1.red;
               red_1(1);
           }

           if(sel_led_r == 2)
           {
               red_1(0);
               red = led2.red;
               red_2(1);
           }

           if(sel_led_r == 3)
           {
               red_2(0);
               red = led3.red;
               red_3(1);
           }

           //increment to next led for next loop
           sel_led_r++;
           if (sel_led_r == 4)
           {
               sel_led_r = 1;
           }

       }

       return;
}


//functions to turn on/off certain leds (state 0 is off, state 1 (or higher) is on)
void red_1(int state)
{
    if (state == 0)
    {
        P2DIR &= ~ BIT6;
    }
    else
    {
        P2DIR |= BIT6;
    }
}

void red_2(int state)
{
    if (state == 0)
    {
        P1DIR &= ~ BIT6;
    }
    else
    {
        P1DIR |= BIT6;
    }
}

void red_3(int state)
{
    if (state == 0)
    {
        P3DIR &= ~ BIT5;
    }
    else
    {
        P3DIR |= BIT5;
    }
}

/*
 * blue update functions
 */

void update_blue()
{
    static int sel_led_b = 1;
    static int state_b = 0;
    state_b++;
       if (state_b == 99)
       {
           blue = 0;
       }
       if (state_b == 100)
       {
           state_b = 0;
           if(sel_led_b == 1)
           {
               blue_3(0);
               blue = led1.blue;
               blue_1(1);
           }

           if(sel_led_b == 2)
           {
               blue_1(0);
               blue = led2.blue;
               blue_2(1);
           }

           if(sel_led_b == 3)
           {
               blue_2(0);
               blue = led3.blue;
               blue_3(1);
           }

           sel_led_b++;
           if (sel_led_b == 4)
           {
               sel_led_b = 1;
           }

       }

       return;
}

void blue_1(int state)
{
    if (state == 0)
    {
        P2DIR &= ~ BIT1;
    }
    else
    {
        P2DIR |= BIT1;
    }
}

void blue_2(int state)
{
    if (state == 0)
    {
        P2DIR &= ~ BIT2;
    }
    else
    {
        P2DIR |= BIT2;
    }
}

void blue_3(int state)
{
    if (state == 0)
    {
        P3DIR &= ~ BIT2;
    }
    else
    {
        P3DIR |= BIT2;
    }
}

/*
 * green update functions
 */

void update_green()
{
    static int sel_led_g = 1;
    static int state_g = 25;
    state_g++;
       if (state_g == 99)
       {
           green = 0;
       }
       if (state_g == 100)
       {
           state_g = 0;
           if(sel_led_g == 1)
           {
               green_3(0);
               green = led1.green;
               green_1(1);
           }

           if(sel_led_g == 2)
           {
               green_1(0);
               green = led2.green;
               green_2(1);
           }

           if(sel_led_g == 3)
           {
               green_2(0);
               green = led3.green;
               green_3(1);
           }

           sel_led_g++;
           if (sel_led_g == 4)
           {
               sel_led_g = 1;
           }

       }
       return;
}

void green_1(int state)
{
    if (state == 0)
    {
        P3DIR &= ~ BIT3;
    }
    else
    {
        P3DIR |= BIT3;
    }
}

void green_2(int state)
{
    if (state == 0)
    {
        P2DIR &= ~ BIT5;
    }
    else
    {
        P2DIR |= BIT5;
    }
}

void green_3(int state)
{
    if (state == 0)
    {
        P2DIR &= ~ BIT4;
    }
    else
    {
        P2DIR |= BIT4;
    }
}
