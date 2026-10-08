#include "display.h"

#define WHITE 0xFFFF

// The fb variable is global to this file: all functions here may access
// it. It is out of scope for main.c
pi_framebuffer_t *fb = NULL;

void open_display(void) {
    // Note: getFramBuffer may return NULL, which is a "zero pointer".
    // If it does, that's an error. This function isn't checking for
    // that, but it probably should.
    fb = getFrameBuffer();
}

void display_sigma() {
    sense_fb_bitmap_t *bm=fb->bitmap;

    // Top and bottom of sigma
    for(int i=3; i<8; i++) {
        bm->pixel[i][0]=WHITE;
        bm->pixel[i][6]=WHITE;
    }

    // Middle
    for(int i=4; i<7; i++) {
        bm->pixel[i][7-i]=WHITE;
        bm->pixel[i][i-1]=WHITE;
    }
}

void clear_sigma() {
    clearFrameBuffer(fb,0);
}
