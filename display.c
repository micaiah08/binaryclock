
#include <stdio.h>
#include "display.h"
#include "sense.h"
#define WHITE 0xFFFF
#define BLUE  0x001F
#define GREEN 0x07E0
#define RED   0xF800

pi_framebuffer_t *fb = NULL;

int open_display(void) {
  if (fb != NULL) {
	return 1;
}
  fb = getFrameBuffer();
  
  if (fb == NULL) {
	return 0;
}
	return 1;
}

void display_time(int hours, int minutes, int seconds) {
  clearFrameBuffer(fb, 0);

  display_colons();
  display_hours(hours);
  display_minutes(minutes);
  display_seconds(seconds);

}

void display_hours(int hours) {
 sense_fb_bitmap_t *bm = fb->bitmap;
 

 for (int i =0; i<6; i++) {
	if (hours & (1<<i)) {
	bm->pixel[7][7 - i] = BLUE;
}
}
}

void display_minutes(int minutes) {
 sense_fb_bitmap_t *bm = fb->bitmap;
 for (int i =0;i<6;i++) {
  if (minutes & (1<<i)){
    bm->pixel[4][7 - i] = GREEN;
}
}

}

void display_seconds(int seconds) {
	sense_fb_bitmap_t *bm = fb->bitmap;
        for(int i = 0; i<6; i++) {
	  if (seconds & (1<<i)) {
  	       bm->pixel[0][7 - i] = RED;
}
}

}

void display_colons(void) {
   sense_fb_bitmap_t *bm = fb->bitmap;
//first colonn
    bm->pixel[2][2] = WHITE;
    bm->pixel[3][2] = WHITE;
    bm->pixel[2][3] = WHITE;
    bm->pixel[3][3] = WHITE;

    bm->pixel[2][5] = WHITE;
    bm->pixel[3][5] = WHITE;
    bm->pixel[2][6] = WHITE;
    bm->pixel[3][6] = WHITE;

    // Second colon (between minutes and seconds)
    bm->pixel[5][2] = WHITE;
    bm->pixel[6][2] = WHITE;
    bm->pixel[5][3] = WHITE;
    bm->pixel[6][3] = WHITE;

    bm->pixel[5][5] = WHITE;
    bm->pixel[6][5] = WHITE;
    bm->pixel[5][6] = WHITE;
    bm->pixel[6][6] = WHITE;
}
void close_display(void) {
   if (fb !=NULL) {
	clearFrameBuffer(fb,0);
}


}
