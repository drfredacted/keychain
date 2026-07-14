#include <inc/updatefuncs.h>
#include <msp430.h>

/*
 * variable declarations
 */
int state_r = 0;
int state_g = 25;
int state_b = 0;

int sel_led_r = 1;
int sel_led_b = 1;
int sel_led_g = 1;


int red1 = 0;
int red2 = 0;
int red3 = 0;

int blue1 = 0;
int blue2 = 0;
int blue3 = 0;

int green1 = 0;
int green2 = 0;
int green3 = 0;


int goal_red1 = 0;
int goal_red2 = 0;
int goal_red3 = 0;

int goal_blue1 = 0;
int goal_blue2 = 0;
int goal_blue3 = 0;

int goal_green1 = 0;
int goal_green2 = 0;
int goal_green3 = 0;

long long delay = 0;
int loops = 0;
//make all leds equal
void equalize()
{
    red2 = red3 = red1;
    blue2 = blue3 = blue1;
    green2 = green3 = green1;
}

void offset1()
{
    red2 = blue3 = green1;
    blue2 = green3 = red1;
    green2 = red3 = blue1;
}

void offset2()
{
    red2 = red3 = green1;
    blue2 = blue3 = red1;
    green2 = green3 = blue1;
}


/*
 * misc functions
 */


//function to make rgb value for led 1 random
void random_1()
{
    red1 = rand()%255;
    green1 = rand()%255;
    blue1 = rand()%255;

    // 1/4 chance to disable one of the rgb value's, this increases the average saturation of generated colors
    switch (rand()%4)
    {
    case 0:
        red1 = 0;
        break;
    case 1:
        green1 = 0;
        break;
    case 2:
        blue1 = 0;
        break;
    case 3:
        break;
    }
}

//code to make all leds have a random rgb value
void random_all()
{

    red1 = rand()%255;
    green1 = rand()%255;
    blue1 = rand()%255;

    switch (rand()%4)
    {
    case 0:
        red1 = 0;
        break;
    case 1:
        green1 = 0;
        break;
    case 2:
        blue1 = 0;
        break;
    case 3:
        break;
    }


    red2 = rand()%255;
    green2 = rand()%255;
    blue2 = rand()%255;

    switch (rand()%4)
    {
    case 0:
        red2 = 0;
        break;
    case 1:
        green2 = 0;
        break;
    case 2:
        blue2 = 0;
        break;
    case 3:
        break;
    }


    red3 = rand()%255;
    green3 = rand()%255;
    blue3 = rand()%255;

    switch (rand()%4)
    {
    case 0:
        red3 = 0;
        break;
    case 1:
        green3 = 0;
        break;
    case 2:
        blue3 = 0;
        break;
    case 3:
        break;
    }
}

//code to make rgb goal of led1 random
void random_1_goal()
{

    goal_red1 = rand()%255;
    goal_green1 = rand()%255;
    goal_blue1 = rand()%255;

    switch (rand()%4)
    {
    case 0:
        goal_red1 = 0;
        break;
    case 1:
        goal_green1 = 0;
        break;
    case 2:
        goal_blue1 = 0;
        break;
    case 3:
        break;
    }
}

//code to make all rgb goals random
void random_all_goal()
{

    goal_red1 = rand()%255;
    goal_green1 = rand()%255;
    goal_blue1 = rand()%255;

    switch (rand()%4)
    {
    case 0:
        goal_red1 = 0;
        break;
    case 1:
        goal_green1 = 0;
        break;
    case 2:
        goal_blue1 = 0;
        break;
    case 3:
        break;
    }

    goal_red2 = rand()%255;
    goal_green2 = rand()%255;
    goal_blue2 = rand()%255;

    switch (rand()%4)
    {
    case 0:
        goal_red2 = 0;
        break;
    case 1:
        goal_green2 = 0;
        break;
    case 2:
        goal_blue2 = 0;
        break;
    case 3:
        break;
    }

    goal_red3 = rand()%255;
    goal_green3 = rand()%255;
    goal_blue3 = rand()%255;

    switch (rand()%4)
    {
    case 0:
        goal_red3 = 0;
        break;
    case 1:
        goal_green3 = 0;
        break;
    case 2:
        goal_blue3 = 0;
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
    delay++;
    offset1();
    if (delay == 30000)
    {
        delay = 0;

        int bluetemp = blue1;
        int greentemp = green1;
        int redtemp = red1;

        red1 = greentemp;
        green1 = bluetemp;
        blue1 = redtemp;
    }
}

//random chase
void random_chase()
{
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

        int bluetemp = blue1;
        int greentemp = green1;
        int redtemp = red1;

        red1 = greentemp;
        green1 = bluetemp;
        blue1 = redtemp;
    }
}

//random chase
void color_chase()
{
    delay++;
    offset1();
    if (delay == 30000)
    {
        delay = 0;
        loops++;

        if (loops == 3)
        {
            loops = 0;
            red1 = rand()%255;
        }

        int bluetemp = blue1;
        int greentemp = green1;
        int redtemp = red1;

        red1 = greentemp;
        green1 = bluetemp;
        blue1 = redtemp;
    }
}

/*
 * random switching
 */

//sync random
void sync_random()
{
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
    delay++;
    if (delay == 1000)
    {
        delay = 0;
        interpolate();
        if ( goal_red1 == red1 & goal_green1 == green1 & goal_blue1 == blue1 & goal_red2 == red2 & goal_green2 == green2 & goal_blue2 == blue2 & goal_red3 == red3 & goal_green3 == green3 & goal_blue3 == blue3 )
        {
            random_all_goal();
        }
    }
}

//sync random
void sync_random_breath()
{
    delay++;
    equalize();
    if (delay == 1000)
    {
        delay = 0;
        interpolate1();

        if (goal_red1 == red1 & goal_green1 == green1 & goal_blue1 == blue1)
        {
            random_1_goal();
        }
    }
}

//async random
void async_random_breath()
{
    delay++;
    offset1();
    if (delay == 1000)
    {
        delay = 0;
        interpolate1();

        if (goal_red1 == red1 & goal_green1 == green1 & goal_blue1 == blue1)
        {
            random_1_goal();
        }
    }
}

//random per color
void color_random_breath()
{
    delay++;
    if (delay == 1000)
    {
        delay = 0;
        interpolate();

        if (goal_red1 == red1)
        {
            goal_red1 = rand()%255;
        }
        if (goal_green1 == green1)
        {
            goal_green1 = rand()%255;
        }
        if (goal_blue1 == blue1)
        {
            goal_blue1 = rand()%255;
        }


        if (goal_red2 == red2)
        {
            goal_red2 = rand()%255;
        }
        if (goal_green2 == green2)
        {
            goal_green2 = rand()%255;
        }
        if (goal_blue2 == blue2)
        {
            goal_blue2 = rand()%255;
        }


        if (goal_red3 == red3)
        {
            goal_red3 = rand()%355;
        }
        if (goal_green3 == green3)
        {
            goal_green3 = rand()%255;
        }
        if (goal_blue3 == blue3)
        {
            goal_blue3 = rand()%355;
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
    if ((red1 == 255) & (green1 == 0) & (blue1 == 0))
    {
        goal_green1 = 255;
    }

    //rg -> g
    if ((red1 == 255) & (green1 == 255) & (blue1 == 0))
    {
        goal_red1 = 0;
    }

    //g -> gb
    if ((red1 == 0) & (green1 == 255) & (blue1 == 0))
    {
        goal_blue1 = 255;
    }

    //gb -> b
    if ((red1 == 0) & (green1 == 255) & (blue1 == 255))
    {
        goal_green1 = 0;
    }

    //b -> rb
    if ((red1 == 0) & (green1 == 0) & (blue1 == 255))
    {
        goal_red1 = 255;
    }

    //rb -> r
    if ((red1 == 255) & (green1 == 0) & (blue1 == 255))
    {
        goal_blue1 = 0;
    }
}

//Synchronous
void sync_rainbow()
{
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
    if (goal_red1 > red1)
    {
        red1++;
    }
    //if goal_red is smaller then red, decrement red
    else if (goal_red1 < red1)
    {
        red1--;
    }

    //green

    //if goal_green is bigger then green, increment green
    if (goal_green1 > green1)
    {
        green1++;
    }
    //if goal_green is smaller then green, decrement green
    else if (goal_green1 < green1)
    {
        green1--;
    }

    //blue

    //if goal_blue is bigger then blue, increment blue
    if (goal_blue1 > blue1)
    {
        blue1++;
    }
    //if goal_blue is smaller then blue, decrement blue
    else if (goal_blue1 < blue1)
    {
        blue1--;
    }
}


//code to interpolate rgb value's for all leds towards their goal
void interpolate()
{
    /*
     * LED 1
     */

    //red
    if (goal_red1 > red1)
    {
        red1++;
    }
    else if (goal_red1 < red1)
    {
        red1--;
    }

    //green
    if (goal_green1 > green1)
    {
        green1++;
    }
    else if (goal_green1 < green1)
    {
        green1--;
    }

    //blue
    if (goal_blue1 > blue1)
    {
        blue1++;
    }
    else if (goal_blue1 < blue1)
    {
        blue1--;
    }


    /*
     * LED 2
     */

    //red
    if (goal_red2 > red2)
    {
        red2++;
    }
    else if (goal_red2 < red2)
    {
        red2--;
    }

    //green
    if (goal_green2 > green2)
    {
        green2++;
    }
    else if (goal_green2 < green2)
    {
        green2--;
    }

    //blue
    if (goal_blue2 > blue2)
    {
        blue2++;
    }
    else if (goal_blue2 < blue2)
    {
        blue2--;
    }


    /*
     * LED 3
     */

    //red
    if (goal_red3 > red3)
    {
        red3++;
    }
    else if (goal_red3 < red3)
    {
        red3--;
    }

    //green
    if (goal_green3 > green3)
    {
        green3++;
    }
    else if (goal_green3 < green3)
    {
        green3--;
    }

    //blue
    if (goal_blue3 > blue3)
    {
        blue3++;
    }
    else if (goal_blue3 < blue3)
    {
        blue3--;
    }
    return 0;
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
/*
 *
 */
/*
 * red update functions
 */

void update_red()
{
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
               red = red1;
               red_1(1);
           }

           if(sel_led_r == 2)
           {
               red_1(0);
               red = red2;
               red_2(1);
           }

           if(sel_led_r == 3)
           {
               red_2(0);
               red = red3;
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
               blue = blue1;
               blue_1(1);
           }

           if(sel_led_b == 2)
           {
               blue_1(0);
               blue = blue2;
               blue_2(1);
           }

           if(sel_led_b == 3)
           {
               blue_2(0);
               blue = blue3;
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
               green = green1;
               green_1(1);
           }

           if(sel_led_g == 2)
           {
               green_1(0);
               green = green2;
               green_2(1);
           }

           if(sel_led_g == 3)
           {
               green_2(0);
               green = green3;
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
