
#include <stdio.h>
#include "display.h"

int main(void)
{
    int hours;
    int minutes;
    int seconds;

    if (open_display() == 0) {
        return 1;
    }

    while (scanf("%d:%d:%d", &hours, &minutes, &seconds) == 3) {
        display_time(hours, minutes, seconds);
    }

    close_display();

    return 0;
}


