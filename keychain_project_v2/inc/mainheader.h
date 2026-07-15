#ifndef _INC_MAINHEADER_H_
#define _INC_MAINHEADER_H_

/*
 * renames the TA count/compare registers to corresponding color
 */
#define red TA0CCR1
#define blue TA1CCR1
#define green TA1CCR2


//defines the variables that should be modifiable by main.c used in updatefuncs.c

typedef struct led {
    int red;
    int green;
    int blue;

    int goal_red;
    int goal_green;
    int goal_blue;
} led;

led led1;
led led2;
led led3;

//toggle function for every led (led: select led 1/2/3, state :0 = off, 1 = on)
void toggle_led(int led, int state);

void reset_led();

#endif /* _INC_MAINHEADER_H_ */
