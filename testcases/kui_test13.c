/**
 * @example kui_test13.c
 *
 * Example of using \ref kui_set_foreground_color function and \ref kui_remove_foreground_color function
 */

#include<kui_vt100.h>
#include<stdio.h>
int main()
{
    kui_clear();
    kui_set_foreground_color(KUI_COLOR_RED);
    printf("Foreground color of this text is color red\n");
    kui_remove_foreground_color();
    printf("There is no foreground color set in this text\n");
    kui_set_foreground_color(KUI_COLOR_MAGENTA);
    printf("Foreground  color of this text is color magenta\n");
    kui_remove_foreground_color();
    printf("There is no foreground color set in this text\n");

    kui_set_foreground_color(KUI_COLOR_YELLOW);
    printf("Foreground of this text is in yellow color");
    kui_remove_foreground_color();
    return 0;
}
