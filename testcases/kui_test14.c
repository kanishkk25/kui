/**
 * @example kui_test14.c
 *
 * Example of using \ref kui_set_color function and \ref kui_remove_color function
 */

#include<kui_vt100.h>
#include<stdio.h>
int main()
{
    kui_clear();
    kui_set_color(KUI_COLOR_RED,KUI_COLOR_BLUE);
    printf("Foreground color of this text is color blue and Background color of this text is color red\n");
    kui_remove_color();
    printf("There is no foreground color and background color set in this text\n");
    return 0;
}
