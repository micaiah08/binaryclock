#include "display.h"

int main(void) {
    open_display();
    fprintf(stderr,"Going to print a sigma!\n");
    display_sigma();
    sleep(5);
    fprintf(stderr,"Did it!\n");
    clear_sigma();
    sleep(1);
    /* Note that the below will not work because main.c doesn't know
     * anything about the 'fb' variable which is scoped in display.c
     */
    //freeFrameBuffer(fb);
    fprintf(stderr,"Exiting.\n");
    return 0;
}
