#ifndef _INC_MAINHEADER_H_
#define _INC_MAINHEADER_H_

int state;

//defines the variables that should be modifiable by main.c used in updatefuncs.c
extern int red1;
extern int red2;
extern int red3;

extern int blue1;
extern int blue2;
extern int blue3;

extern int green1;
extern int green2;
extern int green3;


extern int goal_red1;
extern int goal_red2;
extern int goal_red3;

extern int goal_blue1;
extern int goal_blue2;
extern int goal_blue3;

extern int goal_green1;
extern int goal_green2;
extern int goal_green3;

//toggle function for every led (led: select led 1/2/3, state :0 = off, 1 = on)
void toggle_led(int led, int state);


#endif /* _INC_MAINHEADER_H_ */
