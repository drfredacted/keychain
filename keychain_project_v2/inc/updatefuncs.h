#ifndef _INC_UPDATEFUNCS_H_
#define _INC_UPDATEFUNCS_H_


//updates the red led's
void update_red();

//toggle for individual leds
void red_1(int state);
void red_2(int state);
void red_3(int state);


//apply above comments
void update_blue();

void blue_1(int state);
void blue_2(int state);
void blue_3(int state);


void update_green();

void green_1(int state);
void green_2(int state);
void green_3(int state);

//misc
void interpolate();
void interpolate1();

//modes
void chase();
void random_chase();
void color_chase();

void random();
void sync_random();
void async_random();

void random_breath();
void sync_random_breath();
void async_random_breath();
void color_random_breath();

void sync_rainbow();
void async_rainbow();
void rainbow_top_to_bottom();

#endif /* _INC_UPDATEFUNCS_H_ */
